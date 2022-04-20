// POO_Proiect2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include "date.h"
#include "employee.h"
#include "full_time.h"
#include "part_time.h"

std::ifstream fin("data.in");
std::ofstream fout("data.out");


void error_handler(int error)
{
    std::string garbage;
    getline(std::cin, garbage);

    std::cout << '\n';

    switch (error)
    {
    case 1:
        std::cout << "Incorrect date format. Please enter the correct information.\n\n";
        break;
    case 2:
        std::cout << "Incorrect salary format. Please enter the correct information.\n\n";
        break;
    case 3:
        std::cout << "Incorrect hours per day format. Please enter the correct information.\n\n";
        break;
    case 4:
        std::cout << "Incorrect number of part-timers coaching format. Please enter the correct information.\n\n";
        break;
    case 5:
        std::cout << "Contract can't expire before the hire date. Please enter the correct information.\n\n";
        break;
    case 6:
        std::cout << "Hire date can't be in the future.\n\n";
        break;
    }
}
int main()
{
    Date current_date = Employee::get_current_date();

    // creating the date after which part-timers will not receive their bonus in december
    Date exp_date(31, "december", current_date.get_year());

    // creating a vector with some employees 
    Employee* p_emp;
    std::vector<Employee*> employees;
    
    p_emp = new Full_time();
    fin >> *p_emp;
    employees.push_back(p_emp);
    
    p_emp = new Part_time();
    fin >> *p_emp;
    employees.push_back(p_emp);
    
    Date _date(5, "june", 2007);
    p_emp = new Full_time("Lata", "Stanescu", 2534.35, _date, 2);
    employees.push_back(p_emp);

    p_emp = new Full_time();
    fin >> *p_emp;
    employees.push_back(p_emp);

    p_emp = new Part_time();
    fin >> *p_emp;
    employees.push_back(p_emp);
    
   
    while (true)
    {
        std::cout << "Select -1 to close the program.\n";
        std::cout << "Select 0 to show all employees.\n";
        std::cout << "Select 1 to add new employees.\n";
        std::cout << "Select 2 to remove an employee.\n";
        std::cout << "Select 3 to show all part-time employees.\n";
        std::cout << "Select 4 to show all full-time employees.\n";
        std::cout << "Select 5 to remove all employees.\n";
        std::cout << "Select 6 to show the december salary of an employee for the current year.\n";
        std::cout << "Enter your request: ";

        std::string request1 = "";
        std::cin >> std::ws;
        getline(std::cin, request1);
        std::cout << '\n';

        if (request1 == "-1")
            break;
        else if (request1 == "0")
        {
            std::cout << "Number of employees is: " << Employee::get_number_of_employees() << "\n\n";
            for (auto index = employees.begin(); index != employees.end(); index++)
                std::cout << **index << '\n';
        }
        else if (request1 == "1")
        {
            while (true)
            {
                std::cout << "Select -1 to go back.\n";
                std::cout << "Select 0 to enter a base employee.\n";
                std::cout << "Select 1 to enter a full-time employee.\n";
                std::cout << "Select 2 to enter a part-time employee.\n";
                std::cout << "Enter your request: ";

                std::string request2 = "";
                std::cin >> std::ws;
                getline(std::cin, request2);
                std::cout << '\n';

                if (request2 == "-1")
                    break;
                else if (request2 == "0")
                {
                    std::cout << "Format of base employee is: first_name(string) last_name(string) salary(double) hire_date(int string int).\n";
                    std::cout << "Enter the information: ";

                    std::cin >> std::ws;
                    try
                    {
                        p_emp = new Employee();
                        std::cin >> *p_emp;
                        std::cout << '\n' << "Employee succesfully introduced." << "\n\n";
                        employees.push_back(p_emp);
                    }
                    catch (int error)
                    {
                        error_handler(error);
                    }
                }
                else if (request2 == "1")
                {
                    std::cout << "Format of full-time employee is: first_name(string) last_name(string) salary(double) hire_date(int string int) number_coaching(int).\n";
                    std::cout << "Enter the information: ";

                    std::cin >> std::ws;
                    try
                    {
                        p_emp = new Full_time();
                        std::cin >> *p_emp;
                        std::cout << '\n' << "Employee succesfully introduced." << "\n\n";
                        employees.push_back(p_emp);
                    }
                    catch (int error)
                    {
                        error_handler(error);
                    }
                }
                else if (request2 == "2")
                {
                    std::cout << "Format of part-time employee is: first_name(string) last_name(string) salary(double) hire_date(int string int) hours_day(int) contract_expiration_date(as hire_date).\n";
                    std::cout << "Enter the information: ";

                    std::cin >> std::ws;
                    try
                    {
                        p_emp = new Part_time();
                        std::cin >> *p_emp;
                        std::cout << '\n' << "Employee succesfully introduced." << "\n\n";
                        employees.push_back(p_emp);
                    }
                    catch (int error)
                    {
                        error_handler(error);
                    }
                }
                else
                {
                    std::cout << "Invalid request. Please try again.\n\n";
                }
            }
        }
        else if (request1 == "2")
        {
            std::string id_placeholder;
            std::cout << "Enter the id of the employee you wish to delete: ";
            std::cin >> std::ws;
            getline(std::cin, id_placeholder);
            if (Employee::is_int(id_placeholder))
            {
                bool found_one = false;
                int id_to_delete = stoi(id_placeholder);
                for (int index = 0; index < employees.size(); index++)
                    if (employees[index]->get_id() == id_to_delete)
                    {
                        delete employees[index];
                        employees.erase(employees.begin() + index);
                        found_one = true;
                        std::cout << "\nEmployee was successfully deleted.\n\n";

                        break;
                    }
                if(found_one == false)
                    std::cout << "\nEmployee with id " << id_to_delete << " does not exist.\n\n";
            }
            else
                std::cout << "\nIncorrect format of employee id.\n\n";
        }
        else if (request1 == "3")
        {
            Part_time* p_emp_pt;
            int number_pt = 0;
            for (int index = 0; index < employees.size(); index++)
            {
                p_emp_pt = dynamic_cast<Part_time*>(employees[index]);
                if (p_emp_pt != NULL)
                    std::cout << *p_emp_pt << '\n';
            }
           
        }
        else if (request1 == "4")
        {
            Full_time* p_emp_ft;
            int number_ft = 0;
            for (int index = 0; index < employees.size(); index++)
            {
                p_emp_ft = dynamic_cast<Full_time*>(employees[index]);
                if (p_emp_ft != NULL)
                    std::cout << *p_emp_ft << '\n';
            }
        }
        else if (request1 == "5")
        {
            for (int index = 0; index < employees.size(); index++)
                delete employees[index];
            employees.clear();
            std::cout << "All employees were successfully deleted.\n\n";
        }
        else if (request1 == "6")
        {
            std::string id_placeholder;
            std::cout << "Enter the id of the employee: ";
            std::cin >> std::ws;
            getline(std::cin, id_placeholder);
            if (Employee::is_int(id_placeholder))
            {
                bool found_one = false;
                int id_to_show = stoi(id_placeholder);
                for (int index = 0; index < employees.size(); index++)
                    if (employees[index]->get_id() == id_to_show)
                    {
                        found_one = true;
                        Full_time* p_emp_ft = dynamic_cast<Full_time*>(employees[index]);
                        float salary = employees[index]->get_salary();

                        if (p_emp_ft != NULL)
                        {
                            Date date = p_emp_ft->get_hire_date();
                           
                            float percentage = (current_date.get_year() - date.get_year()) * p_emp_ft->get_number_coaching() / 100.0;
                            std::cout << "\nDecember salary for employee with id " << id_to_show << " is: " << (salary + salary * percentage) << "\n\n";
                        }
                        else
                        {
                            Part_time* p_emp_pt = dynamic_cast<Part_time*>(employees[index]);
                            if (p_emp_pt != NULL)
                            {
                                Date date = p_emp_pt->get_expiration_date();
                                if (date <= exp_date)
                                    if (date.get_month() == "december")
                                        std::cout << "\nDecember salary for employee with id " << id_to_show << " is: " << 0.75 * salary << "\n\n";
                                    else std::cout << "\nContract will be expired by then.\n\n";
                                else std::cout << "\nDecember salary for employee with id " << id_to_show << " is: " << salary << "\n\n";
                            }
                            else std::cout << "\nDecember salary for employee with id " << id_to_show << " is: " << salary << "\n\n";
                        }
                        break;
                    }
                if(found_one == false)
                    std::cout << "\nEmployee with id " << id_to_show << " does not exist.\n\n";
            }
            else
                std::cout << "\nIncorrect format of employee id.\n\n";
        }
        else 
            std::cout << "Invalid request. Please try again.\n\n";
    }
   
    return 0;
}
