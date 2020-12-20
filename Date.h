#pragma once
#include <ctime>

class Date
{
public:
	Date();									//	constructor

	void setDate();							//	set time that is now

	int getYear();							//	getters for date
	int getMonth();							//
	int getDay();							//
	int getHour();							//
	int getMinute();						//
	int getSecond();						//

protected:
	int year;								//	year
	int month;								//	month
	int day;								//	day
	int hour;								//	hour
	int minute;								//	minute
	int second;								//	second
};