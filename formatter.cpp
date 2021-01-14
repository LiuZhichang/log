#include "formatter.h"

LogFormatter::LogFormatter(const fl_str_t& pattern)
    : pattern(pattern) {
	
	parse();
}

fl_str_t LogFormatter::format(fl_event_t::ptr event) {
    fl_sstrem_t ss;
    for(auto& ptr : items) {
        ptr->format(ss, event);
    }
    return ss.str();
}

void LogFormatter::init() {
#define xx(symbol,type) \
	{#symbol}
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
	
}

