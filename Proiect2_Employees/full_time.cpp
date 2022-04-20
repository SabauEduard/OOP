#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "date.h"
#include "employee.h"
#include "full_time.h"

Full_time::Full_time(std::string _first_name, std::string _last_name, double _salary, Date _date, int _number_coaching)
	: Employee(_first_name, _last_name, _salary, _date), number_coaching(_number_coaching)
{

}
Full_time::Full_time()
	: Employee()
{
	number_coaching = -1;
}
Full_time::Full_time(const Full_time& emp_full_time)
	: Employee(emp_full_time)
{
	number_coaching = emp_full_time.number_coaching;
}
Full_time& Full_time:: operator = (Full_time& emp_full_time)
{
	Employee::operator =(emp_full_time);
	number_coaching = emp_full_time.number_coaching;
	return *this;
}
void Full_time::show_details(std::ostream& stream)
{
	Employee::show_details(stream);
	stream << "Number of part-timers under supervision: " << number_coaching << '\n';
}
void Full_time::show_details(std::ofstream& stream)
{
	Employee::show_details(stream);
	stream << "Number of part-timers under supervision: " << number_coaching << '\n';
}
void Full_time::read_details(std::istream& stream)
{
	std::string number_coaching_placeholder;

	Employee::read_details(stream);
	stream >> number_coaching_placeholder;

	if (!is_int(number_coaching_placeholder))
		throw 4;

	number_coaching = stoi(number_coaching_placeholder);

}
void Full_time::read_details(std::ifstream& stream)
{
	std::string number_coaching_placeholder;

	Employee::read_details(stream);
	stream >> number_coaching_placeholder;

	if (!is_int(number_coaching_placeholder))
		throw 4;

	number_coaching = stoi(number_coaching_placeholder);

}
std::istream& operator >> (std::istream& stream, Full_time& emp_full_time)
{
	emp_full_time.read_details(stream);
	return stream;
}
std::ifstream& operator >> (std::ifstream& stream, Full_time& emp_full_time)
{
	emp_full_time.read_details(stream);
	return stream;
}
std::ostream& operator << (std::ostream& stream, Full_time& emp_full_time)
{
	emp_full_time.show_details(stream);
	return stream;
}
std::ofstream& operator << (std::ofstream& stream, Full_time& emp_full_time)
{
	emp_full_time.show_details(stream);
	return stream;
}
int Full_time::get_number_coaching() const
{
	return number_coaching;
}