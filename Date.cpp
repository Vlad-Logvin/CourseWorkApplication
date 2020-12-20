#include "Date.h"

Date::Date()		//default constructor
{
	struct tm new_time;
	time_t now = time(NULL);
	localtime_s(&new_time, &now);

	this->year = new_time.tm_year % 100 + 2000;
	this->month = new_time.tm_mon + 1;
	this->day = new_time.tm_mday;
	this->hour = new_time.tm_hour;
	this->minute = new_time.tm_min;
	this->second = new_time.tm_sec;
}

void Date::setDate()		//set date which is now
{
	struct tm new_time;
	time_t now = time(NULL);
	localtime_s(&new_time, &now);

	this->year = new_time.tm_year % 100 + 2000;
	this->month = new_time.tm_mon + 1;
	this->day = new_time.tm_mday;
	this->hour = new_time.tm_hour;
	this->minute = new_time.tm_min;
	this->second = new_time.tm_sec;
}

int Date::getYear()		//year getter
{
	return this->year;
}

int Date::getMonth()		//month getter
{
	return this->month;
}

int Date::getDay()		//day getter
{
	return this->day;
}

int Date::getHour()		//hour getter
{
	return this->hour;		
}

int Date::getMinute()		//minute getter
{
	return this->minute;
}

int Date::getSecond()		//second getter
{
	return this->second;
}