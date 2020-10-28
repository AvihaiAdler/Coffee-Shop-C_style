#include "Date.h"

Date::Date(int day, int month, int year)
{
	this->day = day % 7;
	this->month = month % 12;

	if (year > 2020 || year < 1950)
		this->year = 2020;
	else
		this->year = year;
}

Date::Date(const Date& other)
{
	day = other.day;
	month = other.month;
	year = other.year;
}

const Date& Date::operator=(const Date& other)
{
	if (this != &other)
	{
		day = other.day;
		month = other.month;
		year = other.year;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	os << date.day << "/" << date.month << "/" << date.year << std::endl;
	return os;
}

const int Date::CURRENT_YEAR = 2020;