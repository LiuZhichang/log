#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <mutex>
#include <memory>
#include <unordered_map>
#include <functional>
#include <list>
#include <mutex>
#include <shared_mutex>

#define implement public

typedef std::string						fl_str_t;
typedef uint32_t						fl_ui32_t;
typedef uint64_t						fl_ui64_t;
typedef std::ostream					fl_ostream_t;
typedef std::ofstream					fl_ofstream_t;
typedef std::stringstream				fl_sstrem_t;
typedef std::mutex          		    fl_mutex_t;
typedef std::lock_guard<std::mutex>		fl_guard_mutex_t;
typedef std::shared_lock<std::mutex>	fl_shared_mutex_t; 
typedef std::unique_lock<std::mutex>	fl_unique_mutex_t;

enum class Level {
    DEBUG = 0x01,
    INFO  = 0x02,
    WARN  = 0x03,
    ERROR = 0x04,
    FATAL = 0x05
};

typedef Level							fl_level_t;

class LogEvent;
class LogFormatter;
class FormatItem;
class LogAppender;
class Logger;

typedef LogEvent						fl_event_t;
typedef LogFormatter					fl_formater_t;
typedef FormatItem						fl_item_t;
typedef LogAppender						fl_appender_t;
typedef Logger							fl_logger_t;
