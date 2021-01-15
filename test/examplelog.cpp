#include "../log.h"

fl_logger_t::ptr logger = FL_LOGGER(system);

int main(int argc, char *argv[]) {
	logger->addAppender(fl_ConsoleLog());
	FL_LOG(logger,Level::DEBUG) << "some text: balabala";

	return 0;
}
