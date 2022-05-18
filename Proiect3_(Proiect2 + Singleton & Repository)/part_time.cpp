#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "date.h"
#include "employee.h"
#include "part_time.h"

Part_time::Part_time(std::string _first_name, std::string _last_name, double _salary, Date _date, int _hours_day, Date _contract_expiration_date)
	: Employee(_first_name, _last_name, _salary, _date), hours_day(_hours_day), contract_expiration_date(_contract_expiration_date)
{
	if (contract_expiration_date < get_hire_date())
		throw 5;
}
Part_time::Part_time()
	: Employee()
{
	hours_day = -1;
	contract_expiration_date = Employee::get_current_date();
}
Part_time::Part_time(const Part_time& emp_part_time)
	: Employee(emp_part_time)
{
	hours_day = emp_part_time.hours_day;
	contract_expiration_date = emp_part_time.contract_expiration_date;
}
Part_time& Part_time::operator = (Part_time& emp_part_time)
{
	Employee::operator=(emp_part_time);
	hours_day = emp_part_time.hours_day;
	contract_expiration_date = emp_part_time.contract_expiration_date;
	return *this;
}
void Part_time::show_details(std::ostream& stream)
{
	Employee::show_details(stream);
	stream << "Hours per day: " << hours_day << '\n';
	stream << "Contract expiration date: " << contract_expiration_date;
}
void Part_time::show_details(std::ofstream& stream)
{
	Employee::show_details(stream);
	stream << "Hours per day: " << hours_day << '\n';
	stream << "Contract expiration date: " << contract_expiration_date;
}
void Part_time::read_details(std::istream& stream)
{
	std::string hours_day_placeholder;

	Employee::read_details(stream);
	stream >> hours_day_placeholder; 

	if (!is_int(hours_day_placeholder))
		throw 3;

	stream >> contract_expiration_date;

	if (contract_expiration_date < get_hire_date())
		throw 5;

	hours_day = stoi(hours_day_placeholder);
}
void Part_time::read_details(std::ifstream& stream)
{
	std::string hours_day_placeholder;

	Employee::read_details(stream);
	stream >> hours_day_placeholder;

	if (!is_int(hours_day_placeholder))
		throw 3;

	stream >> contract_expiration_date;

	if (contract_expiration_date < get_hire_date())
		throw 5;

	hours_day = stoi(hours_day_placeholder);
}
std::istream& operator >> (std::istream& stream, Part_time& emp_part_time)
{
	emp_part_time.read_details(stream);
	return stream;
}
std::ifstream& operator >> (std::ifstream& stream, Part_time& emp_part_time)
{
	emp_part_time.read_details(stream);
	return stream;
}
std::ostream& operator << (std::ostream& stream, Part_time& emp_part_time)
{
	emp_part_time.show_details(stream);
	return stream;
}
std::ofstream& operator << (std::ofstream& stream, Part_time& emp_part_time)
{
	emp_part_time.show_details(stream);
	return stream;
}
Date Part_time::get_expiration_date() const
{
	return contract_expiration_date;
}
int Part_time::get_hours_day() const
{
	return hours_day;
}