#pragma  once

#include "type.h"

struct fl_ev_item {
    fl_ev_item();
    fl_str_t	ev_file;
    fl_str_t	ev_func;
    fl_str_t	ev_thname;
    fl_str_t	ev_logname;
    fl_ui32_t	ev_line;
    fl_ui32_t	ev_elapse;
    fl_ui32_t	ev_thid;
    fl_ui32_t	ev_coid;
    fl_ui64_t	ev_time;
    fl_level_t	ev_level;
};
class LogEvent {
  public:
    typedef std::shared_ptr<LogEvent> ptr;

    LogEvent(const fl_ev_item& ei);

    const fl_str_t& getFileName() const {
        return evi.ev_file;
    }

    const fl_str_t& getFuncName() const {
        return evi.ev_func;
    }

    const fl_str_t& getThName() const {
        return evi.ev_thname;
    }

    const fl_str_t& getLogName() const {
        return evi.ev_logname;
    }

    fl_ui32_t getLine() const {
        return evi.ev_line;
    }

    fl_ui32_t getElapse() const {
        return evi.ev_elapse;
    }

    fl_ui32_t getThid() const {
        return evi.ev_thid;
    }

    fl_ui32_t getCoid() const {
        return evi.ev_coid;
    }

    fl_ui64_t getTime() const {
        return evi.ev_time;
    }

    fl_level_t getLevel() const {
        return evi.ev_level;
    }

    const fl_str_t getLogText() const {
        return sstream.str();
    }

    fl_sstrem_t& getStrIo() {
        return sstream;
    }

  private:
	fl_ev_item  evi;
	fl_sstrem_t sstream;
};
