#pragma once
#include "type.h"
#include "event.h"
#include "util.h"
#include <functional>

#define FL_ITEM(type) \
	[](const std::string& fmt) {return FormatItem::ptr(new type(fmt));}

class FormatItem {
  public:
    typedef std::shared_ptr<FormatItem> ptr;
    virtual void format(fl_ostream_t& os, fl_event_t::ptr event) = 0;
};

class LogFormatter {
  public:
    typedef std::shared_ptr<LogFormatter> ptr;
	typedef std::function<FormatItem::ptr(const std::string& str)> fl_item_wrapper;
    typedef std::unordered_map<std::string,std::function<FormatItem::ptr(const std::string& str)>> fl_map_t;
    typedef std::list<FormatItem::ptr> fl_list_t;
  public:
    LogFormatter(const fl_str_t& pattern);
    fl_str_t format(fl_event_t::ptr event);
    fl_ostream_t& format(fl_ostream_t& os, fl_event_t::ptr event);
    fl_str_t getPattern() const {
        return pattern;
    }
    bool addItem(const fl_str_t& key, fl_item_wrapper item);
    bool replace(const fl_str_t& key, fl_item_wrapper item);
  private:
    void init();
    void parse();

  private:
    fl_str_t	pattern;
    fl_list_t	items;
    fl_map_t	item_dict;
};

class MessageFormatItem : implement FormatItem {
  public:
    MessageFormatItem(const std::string&) {}
    void format(std::ostream& os
                ,  LogEvent::ptr event) override {
        os << event->getLogText();
    }
};
class LineFormatItem : implement FormatItem {
  public:
    LineFormatItem(const std::string&) {}
    void format(std::ostream& os
                ,  LogEvent::ptr event) override {
        os << event->getLine();
    }
};
class LevelFormatItem : implement FormatItem {
  public:
    LevelFormatItem(const std::string&) {}
    void format(std::ostream& os
                ,  LogEvent::ptr event) override {
        os << UT::toString(event->getLevel());
    }
};
class ElapseFormatItem : implement FormatItem {
  public:
    ElapseFormatItem(const std::string&) {}
    void format(std::ostream& os
                ,  LogEvent::ptr event) override {
        os << event->getElapse();
    }
};
class NameFormatItem : implement FormatItem {
  public:
    NameFormatItem(const std::string&) {}
    void format(std::ostream& os
                ,  LogEvent::ptr event) override {
        os << event->getLogName();
    }
};
class ThreadIdFormatItem : implement FormatItem {
  public:
    ThreadIdFormatItem(const std::string&) {}
    void format(std::ostream& os
                ,  LogEvent::ptr event) override {
        os << event->getThid();
    }
};
class FiberIdFormatItem : implement FormatItem {
  public:
    FiberIdFormatItem(const std::string& str = "") {}
    ~FiberIdFormatItem() {}
    void format(std::ostream& os
                , LogEvent::ptr event) override {
        os << event->getCoid();
    }
};
class DateTimeFormatItem : implement FormatItem {
  public:
    DateTimeFormatItem(const std::string& format = "%Y:%m:%d %H:%M:%s"): m_format(format) {
        if(m_format.empty())
            m_format = "%Y:%m:%d %H:%M:%s";
    }
    ~DateTimeFormatItem() {}
    void format(std::ostream& os,
                LogEvent::ptr event) override {
        struct tm tm;
        time_t time = event->getTime();
        localtime_r(&time, &tm);
        char buf[64];
        strftime(buf, sizeof(buf), m_format.c_str(), &tm);
        os << buf;
    }
  private:
    std::string m_format;
};
class FileNameFormatItem : implement FormatItem {
  public:
    FileNameFormatItem(const std::string& str = "") {}
    ~FileNameFormatItem() {}
    void format(std::ostream& os
                , LogEvent::ptr event) override {
        os << event->getFileName();
    }
};
class ThreadNameFormatItem : implement FormatItem {
  public:
    ThreadNameFormatItem(const std::string& str = "") {}
    ~ThreadNameFormatItem() {}
    void format(std::ostream& os
                , LogEvent::ptr event) override {
        os << event->getThName();
    }
};
class NewLineFormatItem : implement FormatItem {
  public:
    NewLineFormatItem(const std::string& str = "") {}
    ~NewLineFormatItem() {}
    void format(std::ostream& os
                , LogEvent::ptr event) override {
        os << "\n";
    }
};
class TabFormatItem : implement FormatItem {
  public:
    TabFormatItem(const std::string& str = "") {}
    ~TabFormatItem() {}
    void format(std::ostream& os
                , LogEvent::ptr event) override {
        os << "\t";
    }
};
class StringFormatItem : implement FormatItem {
  public:
    StringFormatItem(const std::string& str)
        : m_str(str) {}
    void format(std::ostream& os
                , LogEvent::ptr event)override {
        os << m_str;
    }
  private:
    std::string m_str;
};
class FuncNameFormatItem : implement FormatItem {
  public:
    FuncNameFormatItem(const std::string& str) {}
    void format(std::ostream& os
                , LogEvent::ptr event) override {
        os << event->getFuncName();
    }
};
