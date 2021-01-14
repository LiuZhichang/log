#include "event.h"

LogEvent::LogEvent(const fl_ev_item& ei)
    : evi(ei) {
}

LogEvent::LogEvent(fl_level_t level, const fl_str_t& file, const fl_str_t& funcName
                   , fl_ui32_t line, fl_ui32_t elapse,fl_ui32_t threadId, fl_ui32_t coroutineId
                   , fl_ui64_t time, const fl_str_t& threadNmae, const fl_str_t& name)
{
	evi.ev_level	= level;
	evi.ev_file		= file;
	evi.ev_func		= funcName;
	evi.ev_line		= line;
	evi.ev_elapse	= elapse;
	evi.ev_thid		= threadId;
	evi.ev_coid		= coroutineId;
	evi.ev_time		= time;
	evi.ev_thname	= threadNmae;
	evi.ev_logname	= name;
}

 const fl_str_t& LogEvent::getFileName() const {
    return evi.ev_file;
}

 const fl_str_t& LogEvent::getFuncName() const {
    return evi.ev_func;
}

 const fl_str_t& LogEvent::getThName() const {
    return evi.ev_thname;
}

 const fl_str_t& LogEvent::getLogName() const {
    return evi.ev_logname;
}

 fl_ui32_t LogEvent::getLine() const {
    return evi.ev_line;
}

 fl_ui32_t LogEvent::getElapse() const {
    return evi.ev_elapse;
}

 fl_ui32_t LogEvent::getThid() const {
    return evi.ev_thid;
}

 fl_ui32_t LogEvent::getCoid() const {
    return evi.ev_coid;
}

 fl_ui64_t LogEvent::getTime() const {
    return evi.ev_time;
}

 fl_level_t LogEvent::getLevel() const {
    return evi.ev_level;
}

const fl_str_t LogEvent::getLogText() const {
    return sstream.str();
}

fl_sstrem_t& LogEvent::getStrIo() {
    return sstream;
}

fl_ev_item::fl_ev_item() {

}
