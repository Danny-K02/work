#pragma once
#include "Header.h"
#include <map>
class WorldTime
{
private:
	std::map<short, std::string> tzones =
	{
		{0,"000"},{1,"+01"},{2,"+02"},{3,"+03"},{4,"+04"},{5,"+05"},
		{6,"+06"},{7,"+07"},{8,"+08"},{9,"+09"},{10,"+10"},{11,"+11"},
		{12,"+12"},{13,"+13"},{14,"+14"},{-1,"-01"},{-2,"-02"},{-3,"-03"},{-4,"-04"},{-5,"-05"},
		{-6,"-06"},{-7,"-07"},{-8,"-08"},{-9,"-09"},{-10,"-10"},{-11,"-11"},{-12,"-12"} };
	unsigned short num;
	short tZone;
	std::string country;
	unsigned short currentH, currentM, currentS;
	unsigned short countryH, countryM, countryS;
	short tTrans;
	static unsigned short count;
	static unsigned short numeration;
public:
	WorldTime();
	WorldTime(short timeZone);
	void change_tz(short tz);
	short compare_country_time(WorldTime x);
	void print();
	void print_f();
	std::string get_country();
	std::string search_in_f(short tz);
	short get_zone();
	unsigned short get_num();
	~WorldTime();
};

