#include "appender.h"
#include "type.h"

void LogAppender::setFormatter(fl_formater_t::ptr formatter) {
    fl_unique_mutex_t lock(mutex);
    this->formatter = formatter;
}

fl_formater_t::ptr LogAppender::getFromatter() {
	fl_guard_mutex_t lock(mutex);
//    fl_shared_mutex_t lock(mutex);
    return formatter;
}

void LogAppender::setLevel(fl_level_t level) {
    this->level = level;
}

fl_level_t LogAppender::getLevel() const {
    return level;
}

void ConsoleAppender::log(fl_level_t level, fl_event_t::ptr event) {
	if(level >= this->level) {
		fl_unique_mutex_t lock(mutex);
		formatter->format(std::cout,event);
	}	
}

FileAppender::FileAppender(const fl_str_t& filename)
    : filename(filename) {
    reopen();
}

void FileAppender::log(fl_level_t level, fl_event_t::ptr event) {
	if(level >= this->level) {
		fl_unique_mutex_t lock(mutex);
		formatter->format(filestream,event);
	}
}

bool FileAppender::reopen() {
    fl_unique_mutex_t lock(mutex);
    if(filestream)
        filestream.close();
    filestream.open(filename, std::ios::app);
    return !!filestream;
}
