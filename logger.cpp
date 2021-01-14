#include "logger.h"

Logger::Logger(const fl_str_t& name)
    : name(name)
    , level(fl_level_t()) {
    formatter.reset(new fl_formater_t("[%d{%Y-%m-%d %H:%M:%S}]%T%t%T%N%T%F%T[%p]%T[%c]%T[%f:%l:%w]%T%m%n"));
}

void Logger::log(fl_level_t level, fl_event_t::ptr event) {
    if(level >= this->level) {
        if(!appenders.empty()) {
            fl_unique_mutex_t lock(mutex);
            for(auto appender : appenders) {
                appender->log(level, event);
            }
        } else if(root != nullptr) {
            fl_unique_mutex_t lock(mutex);
            root->log(level, event);
        }
    }
}

void Logger::debug(fl_event_t::ptr event) {
    log(fl_level_t::DEBUG, event);
}

void Logger::info(fl_event_t::ptr event) {
    log(fl_level_t::INFO, event);
}

void Logger::warn(fl_event_t::ptr event) {
    log(fl_level_t::WARN, event);
}

void Logger::error(fl_event_t::ptr event) {
    log(fl_level_t::ERROR, event);
}

void Logger::fatal(fl_event_t::ptr event) {
    log(fl_level_t::FATAL, event);
}

void Logger::addAppender(fl_appender_t::ptr appender) {
	fl_unique_mutex_t lock(mutex);
    if(!appender->getFromatter())
        appender->setFormatter(formatter);
    appenders.emplace_front(appender);
}

void Logger::delAppender(fl_appender_t::ptr appender) {
	fl_unique_mutex_t lock(mutex);
    appenders.remove(appender);
}

void Logger::clearAppender() {
    appenders.clear();
}

fl_level_t Logger::getLevel() const {
    return level;
}

void Logger::setLevel(fl_level_t level) {
    this->level = level;
}

void Logger::setFormatter(fl_formater_t::ptr formatter) {
	fl_unique_mutex_t lock(mutex);
    this->formatter = formatter;
    for(auto& appender : appenders) {
		if(!appender->getFromatter())
			appender->setFormatter(formatter);
    }
}

fl_formater_t::ptr Logger::getFormatter() {
	fl_guard_mutex_t lock(mutex);
    return formatter;
}

fl_str_t Logger::getName() const {
    return name;
}
