#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include "date.h"
#include "employee.h"
#include "full_time.h"
#include "part_time.h"
class menu
{
public:
	void start_menu();
	static menu get_menu_instance();

private:
	void error_handler(int error);
	menu() { };
	static menu run_menu;
};
