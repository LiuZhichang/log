#pragma once

#include "type.h"
#include "event.h"
#include "formatter.h"
#include <mutex>

class LogAppender {
  public:
    typedef std::shared_ptr<LogAppender> ptr;

    virtual void log(fl_level_t level, fl_event_t::ptr event) = 0;

    void setFormatter(fl_formater_t::ptr formatter);

    fl_formater_t::ptr getFromatter();

    void setLevel(fl_level_t level);

    fl_level_t getLevel() const;

  protected:
    fl_formater_t::ptr  formatter;
    fl_level_t			level;
    fl_mutex_t			mutex;
};

class ConsoleAppender : implement LogAppender {
  public:
    typedef std::shared_ptr<ConsoleAppender> ptr;

    void log(fl_level_t level, fl_event_t::ptr event) override;
};

class FileAppender : implement LogAppender {
  public:
	  typedef std::shared_ptr<FileAppender> ptr;

	  FileAppender(const fl_str_t& filename);

	  void log(fl_level_t level,fl_event_t::ptr event) override;
	
	  bool reopen();

  private:
	  fl_str_t			filename;
	  fl_ofstream_t		filestream;
};
