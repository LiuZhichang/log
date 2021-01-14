#include <iostream>
#include <ostream>
#include <string>
#include <sstream>

void pares(std::ostream& os,std::string& str) {
	enum statu {
		SYMBOL_START,
	};
	for(char& ch : str) {
		
	}
}

int main(int argc,char** argv) {
	std::stringstream ss;
	std::string pattern{"%d{%Y-%m-%d %H:%M:%S}%T%t%T%N%T%F%T[%p]%T[%c]%T%f:%l%T%m%n"};	
	pares(ss,pattern);
	return 0;
}

