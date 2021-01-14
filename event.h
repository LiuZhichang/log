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
	LogEvent(fl_level_t level, const fl_str_t& file, const fl_str_t& funcName
                   , fl_ui32_t line, fl_ui32_t elapse,fl_ui32_t threadId, fl_ui32_t coroutineId
                   , fl_ui64_t time, const fl_str_t& threadNmae, const fl_str_t& name);

    const fl_str_t& getFileName() const; 

    const fl_str_t& getFuncName() const; 

    const fl_str_t& getThName() const; 

    const fl_str_t& getLogName() const; 

    fl_ui32_t getLine() const; 

    fl_ui32_t getElapse() const; 

    fl_ui32_t getThid() const; 

    fl_ui32_t getCoid() const; 

    fl_ui64_t getTime() const; 

    fl_level_t getLevel() const; 

    const fl_str_t getLogText() const; 

    fl_sstrem_t& getStrIo(); 

  private:
	fl_ev_item  evi;
	fl_sstrem_t sstream;
};
