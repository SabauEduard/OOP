#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "date.h"
#include "employee.h"

class Part_time : public Employee
{
public:
	Part_time(std::string, std::string, double, Date, int, Date);
	Part_time();
	Part_time(const Part_time&);
	virtual ~Part_time() {}
	Date get_expiration_date() const;
	int get_hours_day() const;
	Part_time& operator = (Part_time&);
	friend std::ifstream& operator >> (std::ifstream&, Part_time&);
	friend std::istream& operator >> (std::istream&, Part_time&);
	friend std::ofstream& operator << (std::ofstream&, Part_time&);
	friend std::ostream& operator << (std::ostream&, Part_time&);
	
protected:
	void show_details(std::ofstream&);
	void show_details(std::ostream&);
	void read_details(std::istream&);
	void read_details(std::ifstream&);

private:
	Date contract_expiration_date;
	int hours_day;
};