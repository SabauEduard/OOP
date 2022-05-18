// POO_Proiect3.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include "date.h"
#include "employee.h"
#include "full_time.h"
#include "part_time.h"
#include "menu.h"
#include "repository.h"
#include "employee_repository.h"

int main()
{
    menu run_menu = menu::get_menu_instance();
    // decomenteaza urmatoarea linie ca sa pornesti meniul
    //run_menu.start_menu(); 

    employee_repository emp_repo;
    Date *garb_date = new Date(21, "october", 2021);

    Employee* temp_emp = new Full_time("Eduard", "Sabau", 321.321, *garb_date, 3);
    emp_repo.add(temp_emp);

    garb_date = new Date(20, "january", 2019);
    Date* garb_date1 = new Date(10, "august", 2020);
    temp_emp = new Part_time("Lata", "Stanescu", 123.421, *garb_date, 5, *garb_date1);
    emp_repo.add(temp_emp);

    temp_emp = new Employee("Iosif", "Stelian", 321.321, *garb_date1);
    emp_repo.add(temp_emp);

    temp_emp = new Full_time("Marcel", "Aurelian", 3454.5, *garb_date1, 1);
    emp_repo.add(temp_emp);

    std::vector<Employee*> ans;

    ans = emp_repo.search_by_full_name("Sabau", "Eduard");

    std::cout << "Angajatii cu numele Sabau Eduard\n\n";

    for (auto index = ans.begin(); index != ans.end(); index++)
        std::cout << **index << '\n' << '\n';

    std::cout << '\n';

    ans = emp_repo.search_by_salary(321.321);

    std::cout << "Angajatii cu salariul 321.321\n" << '\n';

    for (auto index = ans.begin(); index != ans.end(); index++)
        std::cout << **index << '\n' << '\n';

    std::cout << '\n';

    ans = emp_repo.search_by_hire_date(*garb_date1);

    std::cout << "Angajatii cu data de angajare 10 august 2020\n\n";

    for (auto index = ans.begin(); index != ans.end(); index++)
        std::cout << **index << '\n' << '\n';

    return 0;
}
