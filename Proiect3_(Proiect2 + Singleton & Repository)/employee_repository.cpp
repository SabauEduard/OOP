#include <vector>
#include <string>
#include "date.h"
#include "employee.h"
#include "repository.h"
#include "employee_repository.h"

Employee* employee_repository::search_by_id(int id)
{
	for (auto index = entities.begin(); index != entities.end(); index++)
		if ((*index)->get_id() == id)
			return *index;
}

std::vector<Employee*> employee_repository::search_by_last_name(std::string last_name)
{
	std::vector<Employee*> temp;
	for (auto index = entities.begin(); index != entities.end(); index++)
		if ((*index)->get_last_name() == last_name)
			temp.push_back(*index);
	return temp;
}

std::vector<Employee*> employee_repository::search_by_first_name(std::string first_name)
{
	std::vector<Employee*> temp;
	for (auto index = entities.begin(); index != entities.end(); index++)
		if ((*index)->get_first_name() == first_name)
			temp.push_back(*index);
	return temp;
}

std::vector<Employee*> employee_repository::search_by_salary(float salary)
{
	std::vector<Employee*> temp;
	for (auto index = entities.begin(); index != entities.end(); index++)
		if ((*index)->get_salary() == salary)
			temp.push_back(*index);
	return temp;
}

std::vector<Employee*> employee_repository::search_by_full_name(std::string last_name, std::string first_name)
{
	std::vector<Employee*> temp;
	for (auto index = entities.begin(); index != entities.end(); index++)
		if ((*index)->get_last_name() == last_name && (*index)->get_first_name() == first_name)
			temp.push_back(*index);
	return temp;
}

std::vector<Employee*> employee_repository::search_by_hire_date(Date hire_date)
{
	std::vector<Employee*> temp;
	for (auto index = entities.begin(); index != entities.end(); index++)
		if ((*index)->get_hire_date() == hire_date)
			temp.push_back(*index);
	return temp;
}