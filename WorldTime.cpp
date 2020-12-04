#include "WorldTime.h"
#pragma warning(disable : 4996)

unsigned short WorldTime::count = 0;
unsigned short WorldTime::numeration = 0;
WorldTime::WorldTime()
{
	srand(time(0));
	++count;
	++numeration;
	num = numeration;
	tZone = rand() % 27 - 12;
	country = search_in_f(tZone);
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	currentH = timeinfo->tm_hour;
	currentM = timeinfo->tm_min;
	currentS = timeinfo->tm_sec;
	tTrans = tZone - 2;
	if (currentH + tTrans < 0)countryH = currentH + tTrans + 24;
	else if (currentH + tTrans > 24)countryH = currentH + tTrans - 24;
	else countryH = currentH + tTrans;
	countryM = currentM;
	countryS = currentS;
}

WorldTime::WorldTime(short timeZone)
{
	++count;
	++numeration;
	num = numeration;
	tZone = timeZone;
	country = search_in_f(timeZone);
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	currentH = timeinfo->tm_hour;
	currentM = timeinfo->tm_min;
	currentS = timeinfo->tm_sec;
	tTrans = tZone - 2;
	if (currentH + tTrans < 0)countryH = currentH + tTrans + 24;
	else if (currentH + tTrans > 24)countryH = currentH + tTrans - 24;
	else countryH = currentH + tTrans;
	countryM = currentM;
	countryS = currentS;

}

void WorldTime::change_tz(short tz)
{
	tZone = tz;
	country = search_in_f(tz);
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	currentH = timeinfo->tm_hour;
	currentM = timeinfo->tm_min;
	currentS = timeinfo->tm_sec;
	tTrans = tZone - 2;
	if (currentH + tTrans < 0)countryH = currentH + tTrans + 24;
	else if (currentH + tTrans > 24)countryH = currentH + tTrans - 24;
	else countryH = currentH + tTrans;
	countryM = currentM;
	countryS = currentS;
}

short WorldTime::compare_country_time(WorldTime x)
{
	return this->tZone - x.tZone;
}



void WorldTime::print()
{
	std::string t;
	t = tzones[tZone];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	currentH = timeinfo->tm_hour;
	currentM = timeinfo->tm_min;
	currentS = timeinfo->tm_sec;
	tTrans = tZone - 2;
	if (currentH + tTrans < 0)countryH = currentH + tTrans + 24;
	else if(currentH+tTrans>24)countryH = currentH + tTrans - 24;
	else countryH = currentH + tTrans;
	
	countryM = currentM;
	countryS = currentS;
	std::cout << "Страна #"<<num<<":  " << country << "\n" << "Часовой пояс: UTC" << t << "\n" << "Время в стране: " << countryH << "часов " << countryM << "минут " << countryS << "секунд.\n"
		<< "Местное время: " << currentH << "часов " << countryM << "минут " << countryS << "секунд.\n";
}

void WorldTime::print_f()
{
	std::string t;
	t = tzones[tZone];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	currentH = timeinfo->tm_hour;
	currentM = timeinfo->tm_min;
	currentS = timeinfo->tm_sec;
	tTrans = tZone - 2;
	if (currentH + tTrans < 0)countryH = currentH + tTrans + 24;
	else if (currentH + tTrans > 24)countryH = currentH + tTrans - 24;
	else countryH = currentH + tTrans;
	countryM = currentM;
	countryS = currentS;
	std::ofstream file("Countries.txt", std::ios::app);
	file << "Страна#" << num << ":  " << country << "\n" << "Часовой пояс: UTC" << t << "\n" << "Время в стране: " << countryH << "часов " << countryM << "минут " << countryS << "секунд.\n"
		<< "Местное время: " << currentH << "часов " << countryM << "минут " << countryS << "секунд.\n";
	file.close();
}

std::string WorldTime::get_country()
{
	return country;
}

std::string WorldTime::search_in_f(short tz)
{
	char countr[20] = {};
	std::ifstream file("tzones.txt");
	do
	{
		
	} while (file >> countr&& countr[0] != tzones[tz][0] && countr[1] != tzones[tz][1] && countr[2] != tzones[tz][2]);
	file.close();
	if (countr != "error")
	{
		std::string s, a,res;
		std::ifstream r("tzones.txt");
		while (r >> a)
		{
			if (a != countr)
			{
				s += " " + a;
			}
			else res = a;
		}
		r.close();
		std::ofstream w("tzones.txt");
		w << s;
		w.close();
		this->tZone = tz;
		
		return res.substr(3);
	}
	else 
	{ 
		std::string tmp =search_in_f(rand() % 27 - 12); 
		return tmp;
	}
}

short WorldTime::get_zone()
{
	return tZone;
}

unsigned short WorldTime::get_num()
{
	return num;
}

WorldTime::~WorldTime()
{
	--count;
}
