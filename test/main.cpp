#include "../formatter.h"
#include <iostream>
class FLItem : public FormatItem{
  public:
	  FLItem(fl_str_t str){}
    void format(fl_ostream_t& os, fl_event_t::ptr event) override {
		os << "fl";
    }
};


int main(int argc, char *argv[]) {

    fl_formater_t format("123123");
	fl_formater_t::fl_item_wrapper item = [](const std::string& fmt) {return FormatItem::ptr(new FLItem(fmt));};
	int res = format.addItem("p",item); 
	std::cout << res << std::endl;
	res = format.addItem("p", FL_ITEM(FLItem));
	std::cout << res << std::endl;
    return 0;
}
