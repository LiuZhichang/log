#include "../log.h"	

int main(int argc, char *argv[]) {
	
	fl_logger_t::ptr logger(new Logger("system"));
	fl_appender_t::ptr console(new ConsoleAppender());
	logger->addAppender(console);

	FL_LOG(logger, fl_level_t::DEBUG) << "sdfsdf";
	return 0;
}

