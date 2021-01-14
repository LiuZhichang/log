#include "formatter.h"

LogFormatter::LogFormatter(const fl_str_t& pattern)
    : pattern(pattern) {
    init();
    parse();
}

void LogFormatter::setPattern(const fl_str_t& pattern) {
    this->pattern = pattern;
}

fl_str_t LogFormatter::format(fl_event_t::ptr event) {
    fl_sstrem_t ss;
    for(auto& ptr : items) {
        ptr->format(ss, event);
    }
    return ss.str();
}

void LogFormatter::init() {
#define xx(des,type) \
	addItem(#des, FL_ITEM(type))
    xx(m, MessageFormatItem);
    xx(p, LevelFormatItem);
    xx(r, ElapseFormatItem);
    xx(c, NameFormatItem);
    xx(t, ThreadIdFormatItem);
    xx(n, NewLineFormatItem);
    xx(d, DateTimeFormatItem);
    xx(f, FileNameFormatItem);
    xx(l, LineFormatItem);
    xx(T, TabFormatItem);
    xx(F, CoroutineId);
    xx(N, ThreadNameFormatItem);
    xx(w, FuncNameFormatItem);
#undef xx
}

fl_ostream_t& LogFormatter::format(fl_ostream_t& os, fl_event_t::ptr event) {
    for(auto& ptr : items) {
        ptr->format(os, event);
    }
    return os;
}

bool LogFormatter::addItem(const fl_str_t& key, fl_item_wrapper item) {
    if(!item_dict.count(key)) {
        item_dict[key] = item;
        return true;
    }
    return false;
}

bool LogFormatter::replace(const fl_str_t& key, fl_item_wrapper item) {
    if(item_dict.count(key)) {
        item_dict[key] = item;
        return true;
    }
    return false;
}

// %d{%Y-%m-%d %H:%M:%S}%T%t%T%N%T%F%T[%p]%T[%c]%T%f:%l%T%m%n
void LogFormatter::parse() {
    if(pattern.empty()) {
        throw "pattern is empty";
    }
    enum class TYPE {
        FLAG,
        ITEM,
        REGEX,
        PENDING
    };
    TYPE type;
    char sym = '\0';
    int start = -1;
    for(int i = 0 ; i < pattern.size() ; ++i) {
        char ch = pattern[i];
        if(ch == '%' && type != TYPE::REGEX) {
            if(i + 1 < pattern.size()) {
                if(pattern[i + 1] == '%') {
                    type = TYPE::FLAG;
                    continue;
                } else {
                    type = TYPE::ITEM;
                    continue;
                }
            }
            if(type == TYPE::FLAG)
                items.push_back(FormatItem::ptr(new StringFormatItem("%")));
        } else if(std::isalpha(ch) && type == TYPE::ITEM) {
            if(i + 1 < pattern.size()) {
                if(pattern[i + 1] == '{') {
                    type = TYPE::PENDING;
                    sym = ch;
                    continue;
                }
            }
            std::string key(1, ch);
            auto it = item_dict.find(key);
            if(it != item_dict.end())
                items.push_back(it->second(""));
        } else {
            if(ch == '{')
                if(i + 1 < pattern.size()) {
                    if(pattern[i + 1] == '%') {
                        type = TYPE::REGEX;
                        start = i;
                        continue;
                    }
                }
            if(ch == '}' && type == TYPE::REGEX && sym != '\0') {
                std::string key(1, sym);
                auto it = item_dict.find(key);
                if(it != item_dict.end() && start)
                    items.push_back(it->second(pattern.substr(start + 1, i)));
                sym = '\0';
                start = -1;
                type = TYPE::PENDING;
                continue;
            }
        }
        if(type != TYPE::REGEX) {
            std::string tmp(1, ch);
            items.push_back(FormatItem::ptr(new StringFormatItem(tmp)));
        }
    }
}
