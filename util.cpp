#include "util.h"

namespace UT {

const fl_str_t toString(fl_level_t level) {
    switch(level) {
#define xx(lv) \
		case Level::lv: \
			return #lv; \
			break
        xx(DEBUG);
        xx(INFO);
        xx(WARN);
        xx(ERROR);
        xx(FATAL);
    default:
        return "UNKONW";
        break;
#undef xx
    }

}

const Level fromString(const fl_str_t& level) {
#define xx(lv,str) \
	if(level == #str) \
		return Level::lv;

    xx(DEBUG, DEBUG);
    xx(INFO, INFO);
    xx(WARN, WARN);
    xx(ERROR, ERROR);
    xx(FATAL, FATAL);

    xx(DEBUG, debug);
    xx(INFO, info);
    xx(WARN, warn);
    xx(ERROR, error);
    xx(FATAL, fatal);
#undef xx
    return Level();
}

}


