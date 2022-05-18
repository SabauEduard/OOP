#pragma once
#include <vector>
#include <string>
#include "date.h"
#include "employee.h"
#include "repository.h"

class employee_repository : public repository<Employee>
{
public:
	Employee* search_by_id(int id);
	std::vector<Employee*> search_by_last_name(std::string last_name);
	std::vector<Employee*> search_by_first_name(std::string first_name);
	std::vector<Employee*> search_by_salary(float salary);
	std::vector<Employee*> search_by_full_name(std::string last_name, std::string first_name);
	std::vector<Employee*> search_by_hire_date(Date hire_date);
};