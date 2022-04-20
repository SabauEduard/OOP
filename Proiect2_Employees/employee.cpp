#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include "date.h"
#include "employee.h"

int Employee::number_of_employees = 0;
int Employee::id_generator = 100;

std::string get_name_of_month(int month)
{
	switch (month)
	{
	case 1:
		return "january";
	case 2:
		return "february";
	case 3:
		return "march";
	case 4:
		return "april";
	case 5:
		return "may";
	case 6:
		return "june";
	case 7:
		return "july";
	case 8:
		return "august";
	case 9:
		return "september";
	case 10:
		return "october";
	case 11:
		return "november";
	case 12:
		return "december";
	}
}
Date generate_current_date()
{
	// transforming the local time date from ctime to my format of date
	time_t t = std::time(0);
	struct tm now;
	localtime_s(&now, &t);
	now.tm_year += 1900;
	now.tm_mon += 1;
	Date _current_date(now.tm_mday, get_name_of_month(now.tm_mon), now.tm_year);
	return _current_date;
}

Date Employee::current_date = generate_current_date();

bool Employee::is_float(std::string s)
{
	int dots = 0;
	for (int index = 0; index < s.length(); index++)
		if (strchr("0123456789.", s[index]) == NULL)
			return false;
		else if (s[index] == '.')
		{
			dots++;
			if (dots > 1)
				return false;
		}

	return true;
}
bool Employee::is_int(std::string s)
{
	for (int index = 0; index < s.length(); index++)
		if (strchr("0123456789", s[index]) == NULL)
			return false;
	return true;
}
Employee::Employee(std::string _first_name, std::string _last_name,double _salary, Date _date)
{
	id = id_generator;
	first_name = _first_name;
	last_name = _last_name;
	hire_date = _date;

	if (hire_date > current_date)
		throw 6;

	salary = _salary;
	Employee::number_of_employees++;
	Employee::id_generator++;
}
Employee::Employee()
{
	id = id_generator;
	first_name = "Unknown";
	last_name = "Unknown";
	salary = -1;
	hire_date = current_date;
	Employee::number_of_employees++;
	Employee::id_generator++;
}
Employee::Employee(const Employee& emp)
{
	id = id_generator;
	first_name = emp.first_name;
	last_name = emp.last_name;
	hire_date = emp.hire_date;   
	salary = emp.salary;
	Employee::number_of_employees++;
	Employee::id_generator++;
}
Employee& Employee::operator = (Employee& emp)
{
	id = emp.id;
	first_name = emp.first_name;
	last_name = emp.last_name;
	hire_date = emp.hire_date;
	salary = emp.salary;
	return *this;
}
void Employee::show_details(std::ofstream& stream)
{
	stream << "Employee ID: " << id << '\n';
	stream << "Full Name: " << first_name << " " << last_name << '\n';
	stream << "Salary: " << salary << '\n';
	stream << "Hire Date: " << hire_date;
}
void Employee::show_details(std::ostream& stream)
{
	stream << "Employee ID: " << id << '\n';
	stream << "Full Name: " << first_name << " " << last_name << '\n';
	stream << "Salary: " << salary << '\n';
	stream << "Hire Date: " << hire_date;
}
void Employee::read_details(std::istream& stream)
{
	std::string salary_placeholder;
	stream >> first_name >> last_name >> salary_placeholder;

	if (!is_float(salary_placeholder))
		throw 2;

	stream >> hire_date;

	if (hire_date > current_date)
		throw 6;

	salary = stod(salary_placeholder);

}
void Employee::read_details(std::ifstream& stream)
{
	std::string salary_placeholder;
	stream >> first_name >> last_name >> salary_placeholder;

	if (!is_float(salary_placeholder))
		throw 2;

	stream >> hire_date;

	if (hire_date > current_date)
		throw 6;

	salary = stod(salary_placeholder);
}
std::ifstream& operator >> (std::ifstream& stream, Employee& emp)
{
	emp.read_details(stream);
	return stream;
}
std::istream& operator >> (std::istream& stream, Employee& emp)
{
	emp.read_details(stream);
	return stream;
}
std::ofstream& operator << (std::ofstream& stream, Employee& emp)
{
	emp.show_details(stream);
	return stream;
}
std::ostream& operator << (std::ostream& stream, Employee& emp)
{
	emp.show_details(stream);
	return stream;
}

int Employee::get_number_of_employees() 
{
	return Employee::number_of_employees;
}
int Employee::get_id() const
{
	return id;
}
float Employee::get_salary() const
{
	return salary;
}
Date Employee::get_hire_date() 
{
	return hire_date;
}
std::string Employee::get_first_name() const
{
	return first_name;
}
std::string Employee::get_last_name() const
{
	return last_name;
}
Date Employee::get_current_date()
{
	return current_date;
}
Employee:: ~Employee()
{
	Employee::number_of_employees--;
}