#pragma once
#include <iostream>
#include <string>
#include <vector>

class Date 
{
public:
	Date(int = -1, std::string = "Unknown", int = -1);
	Date(const Date&);
	Date& operator = (Date&);
	Date& operator = (const Date&);
	virtual ~Date() {}
	int get_day() const;
	std::string get_month() const;
	int get_year() const;
	bool operator <= (Date);
	bool operator >= (Date);
	bool operator > (Date);
	bool operator < (Date);
	bool operator == (Date);
	friend std::ifstream& operator >> (std::ifstream&, Date&);
	friend std::istream& operator >> (std::istream&, Date&);
	friend std::ofstream& operator << (std::ofstream&, Date&);
	friend std::ostream& operator << (std::ostream&, Date&);

private:
	int day;
	std::string month;
	int year;
};
