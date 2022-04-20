#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "date.h"


bool day_exists(std::string day, std::string month)
{
	int num_day = std::stoi(day);

	if (month == "january" && 0 <= num_day && num_day <= 31)
		return true;
	if (month == "february" && 0 <= num_day && num_day <= 29)
		return true;
	if (month == "march" && 0 <= num_day && num_day <= 31)
		return true;
	if (month == "april" && 0 <= num_day && num_day <= 30)
		return true;
	if (month == "may" && 0 <= num_day && num_day <= 31)
		return true;
	if (month == "june" && 0 <= num_day && num_day <= 30)
		return true;
	if (month == "july" && 0 <= num_day && num_day <= 31)
		return true;
	if (month == "august" && 0 <= num_day && num_day <= 31)
		return true;
	if (month == "september" && 0 <= num_day && num_day <= 30)
		return true;
	if (month == "october" && 0 <= num_day && num_day <= 31)
		return true;
	if (month == "november" && 0 <= num_day && num_day <= 30)
		return true;
	if (month == "december" && 0 <= num_day && num_day <= 31)
		return true;

	return false;
}
bool month_exists(std::string& month)
{
	// making month lower case
	for (auto index = month.begin(); index != month.end(); index++)
		*index = tolower(*index);

	if (month == "january")
		return true;
	if (month == "february")
		return true;
	if (month == "march")
		return true;
	if (month == "april")
		return true;
	if (month == "may")
		return true;
	if (month == "june")
		return true;
	if (month == "july")
		return true;
	if (month == "august")
		return true;
	if (month == "september")
		return true;
	if (month == "october")
		return true;
	if (month == "november")
		return true;
	if (month == "december")
		return true;
	return false;
}
int get_number_of_month(std::string month)
{
	if (month == "january")
		return 1;
	else if (month == "february")
		return 2;
	else if (month == "march")
		return 3;
	else if (month == "april")
		return 4;
	else if (month == "may")
		return 5;
	else if (month == "june")
		return 6;
	else if (month == "july")
		return 7;
	else if (month == "august")
		return 8;
	else if (month == "september")
		return 9;
	else if (month == "october")
		return 10;
	else if (month == "november")
		return 11;
	else return 12;
}
bool check_input(std::string day_placeholder, std::string month_placeholder, std::string year_placeholder)
{
	// checking if the day is in the correct format
	for (int index = 0; index < day_placeholder.size(); index++)
		if (!isdigit(day_placeholder[index]))
			return false;

	// checking if the month is valid
	if (!month_exists(month_placeholder))
		return false;

	// checking if the day exists withing the month
	if (!day_exists(day_placeholder, month_placeholder))
		return false;

	// checking if the year is in the correct format
	for (int index = 0; index < year_placeholder.size(); index++)
		if (!isdigit(year_placeholder[index]))
			return false;

	return true;

}
Date::Date(int _day, std::string _month, int _year)
{	
	day = _day;
	month = _month;
	year = _year;
}
Date::Date(const Date& _date)
{
	day = _date.day;
	month = _date.month;
	year = _date.year;
}
Date& Date:: operator = (const Date& _date)
{
	day = _date.day;
	month = _date.month;
	year = _date.year;
	return *this;
}
Date& Date:: operator = (Date& _date)
{
	day = _date.day;
	month = _date.month;
	year = _date.year;
	return *this;
}
std::ifstream& operator >> (std::ifstream& stream, Date& _date)
{
	std::string day_placeholder, month_placeholder, year_placeholder;
	stream >> day_placeholder >> month_placeholder >> year_placeholder;

	if (!check_input(day_placeholder, month_placeholder, year_placeholder))
		throw 1;

	_date.day = stoi(day_placeholder);
	_date.month = month_placeholder;
	_date.year = stoi(year_placeholder);

	return stream;
	
}
std::istream& operator >> (std::istream& stream, Date& _date)
{
	std::string day_placeholder, month_placeholder, year_placeholder;
	stream >> day_placeholder >> month_placeholder >> year_placeholder;

	if (!check_input(day_placeholder, month_placeholder, year_placeholder))
		throw 1;

	_date.day = stoi(day_placeholder);
	_date.month = month_placeholder;
	_date.year = stoi(year_placeholder);

	return stream;
}
std::ofstream& operator << (std::ofstream& stream, Date& _date)
{
	stream << _date.day << " " << _date.month << " " << _date.year << '\n';
	return stream;
}
std::ostream& operator << (std::ostream& stream, Date& _date)
{
	stream << _date.day << " " << _date.month << " " << _date.year << '\n';
	return stream;
}
bool Date::operator <= (Date _date)
{
	int month1 = get_number_of_month(month);
	int month2 = get_number_of_month(_date.month);
	if (year < _date.year)
		return true;
	else if (year == _date.year)
			if (month1 < month2)
				return true;
			else if (month1 == month2)
				if (day <= _date.day)
					return true;
	return false;
}
bool Date::operator >= (Date _date)
{
	int month1 = get_number_of_month(month);
	int month2 = get_number_of_month(_date.month);
	if (year > _date.year)
		return true;
	else if (year == _date.year)
		if (month1 > month2)
			return true;
		else if (month1 == month2)
			if (day >= _date.day)
				return true;
	return false;
}
bool Date::operator < (Date _date)
{
	return !operator >= (_date);
}
bool Date::operator > (Date _date)
{
	return !operator <= (_date);
}
bool Date::operator == (Date _date)
{
	return (operator >= (_date) && operator <= (_date));
}
int Date::get_day() const
{
	return day;
}
std::string Date::get_month() const
{
	return month;
}
int Date::get_year() const
{
	return year;
}
