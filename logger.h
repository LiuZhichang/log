#pragma once

#include "type.h"
#include "event.h"
#include "appender.h"
#include <forward_list>

#define FL_LOG(logger,level) \
	if(logger->getLevel() <= level) \
		LogWrapper(logger,(fl_event_t::ptr(new fl_event_t( \
						level,__FILE__,__func__,__LINE__,0,0,0,time(0),"null",logger->getName() \
						)))).getStrIo()

#define FL_LOGGER(name) \
	fl_logger_t::ptr(new fl_logger_t(#name))

#define FL_LOG_DEBUG(logger) \
	FL_LOG(logger,fl_level_t::DEBUG)

#define FL_LOG_INFO(logger)	\
	FL_LOG(logger,fl_level_t::INFO)

#define FL_LOG_WARN(logger)	\
	FL_LOG(logger,fl_level_t::WARN)

#define FL_LOG_ERROR(logger)	\
	FL_LOG(logger,fl_level_t::ERROR)

#define FL_LOG_FATAL(logger)	\
	FL_LOG(logger,fl_level_t::FATAL)

inline	fl_appender_t::ptr fl_ConsoleLog() {
	return LogAppender::ptr(new ConsoleAppender());
}

inline fl_appender_t::ptr fl_FileLog(const std::string& name) {
	return LogAppender::ptr(new FileAppender(name));
}

class Logger {
	typedef std::forward_list<fl_appender_t::ptr> fl_flist_t;
	public:
		typedef std::shared_ptr<Logger> ptr;

		Logger(const fl_str_t& name = "root");

		void log(fl_level_t level,fl_event_t::ptr event);

		void debug(fl_event_t::ptr event);
		void info(fl_event_t::ptr event);
		void warn(fl_event_t::ptr event);
		void error(fl_event_t::ptr event);
		void fatal(fl_event_t::ptr event);

		void addAppender(fl_appender_t::ptr appender);
		void delAppender(fl_appender_t::ptr appender);
		void clearAppender();

		fl_level_t getLevel() const;
		void setLevel(fl_level_t level);
	
		void setFormatter(fl_formater_t::ptr formatter);
		fl_formater_t::ptr getFormatter();

		fl_str_t getName() const;
	private:
		fl_str_t			name;
		fl_level_t			level;
		fl_flist_t			appenders;
		fl_formater_t::ptr	formatter;
		fl_logger_t::ptr	root;
		fl_mutex_t			mutex; 
};

class LogWrapper{
	public:
		LogWrapper(fl_logger_t::ptr logger,fl_event_t::ptr event) 
			:logger(logger),event(event) {}
		~LogWrapper() {
			logger->log(event->getLevel(), event);
		}
		fl_sstrem_t& getStrIo() {
			return event->getStrIo();
		}
	private:
		fl_logger_t::ptr logger;
		fl_event_t::ptr event;
};

