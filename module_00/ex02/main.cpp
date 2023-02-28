#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <sstream>

int main(void){
	time_t	timer;
	tm		*timeinfo;
	int		year, month, day;
	std::string	month_str;
	std::ostringstream	stream;

	time(&timer);
	timeinfo = localtime(&timer);
	year = timeinfo->tm_year + 1900;
	month = timeinfo->tm_mon + 1;
	stream << month;
	month_str = stream.str();
	day = timeinfo->tm_mday;

	month_str.resize(2, '0');
	std::cout << "[";
	std::cout << year ;
	std::cout << month_str << std::setfill('0') << std::setw(2);
	std::cout << day;
	std::cout << "_";
	std::cout << timeinfo->tm_hour << timeinfo->tm_min << timeinfo->tm_sec << "]" << std::endl;
	return (0);
}