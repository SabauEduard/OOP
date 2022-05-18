#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "date.h"
#include "employee.h"

class Full_time : public Employee
{
public:
	Full_time(std::string, std::string, double, Date, int);
	Full_time();
	Full_time(const Full_time&);
	int get_number_coaching() const;
	Full_time& operator = (Full_time&);
	virtual ~Full_time() {}
	friend std::ifstream& operator >> (std::ifstream& stream, Full_time&);
	friend std::istream& operator >> (std::istream& stream, Full_time&);
	friend std::ostream& operator << (std::ostream& stream, Full_time&);
	friend std::ofstream& operator << (std::ofstream& stream, Full_time&);

protected:
	void show_details(std::ofstream&);
	void show_details(std::ostream&);
	void read_details(std::istream&);
	void read_details(std::ifstream&);

private:
	int number_coaching;
};