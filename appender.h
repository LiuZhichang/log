#pragma once 

#include "type.h"
#include "event.h"
#include "formatter.h"
#include <mutex>

class LogAppender {
	public:
		typedef std::shared_ptr<LogAppender> ptr;
		
		virtual void log(fl_level_t level,fl_event_t::ptr event) = 0;
		void setFormatter(fl_formater_t::ptr formatter) {
			std::lock_guard<std::mutex> lock(mutex);	
			formatter = formatter;
		}
	protected:
		fl_formater_t::ptr  formatter;
		fl_level_t			level;
		fl_mutex_t			mutex;
};

