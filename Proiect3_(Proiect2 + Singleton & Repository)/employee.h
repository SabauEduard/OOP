#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "date.h"

class Employee
{
public:
	Employee(std::string, std::string, double, Date);
	Employee();
	Employee(const Employee&);
	virtual ~Employee();
	Employee& operator = (Employee&);
	static int get_number_of_employees();
	static Date get_current_date();
	int get_id() const;
	float get_salary() const;
	Date get_hire_date();
	std::string get_last_name() const;
	std::string get_first_name() const;
	friend std::ifstream& operator >> (std::ifstream&, Employee&);
	friend std::istream& operator >> (std::istream&, Employee&);
	friend std::ofstream& operator << (std::ofstream&, Employee&);
	friend std::ostream& operator << (std::ostream&, Employee&);
	static bool is_float(std::string);
	static bool is_int(std::string);

protected:
	virtual void show_details(std::ostream&);
	virtual void show_details(std::ofstream&);
	virtual void read_details(std::istream&);
	virtual void read_details(std::ifstream&);
	static Date current_date;

private:
	static int number_of_employees;
	static int id_generator; 
	int id;
	std::string last_name;
	std::string first_name;
	Date hire_date;
	double salary;
};