# OOP Project - Classes: Date, Employee, Part_time, Full_time

This is my second OOP project. The project contains the definition of the 3 classes plus their functions and constructors, a vector of pointers
to the Employee class and an interactive menu with some possible commands. 

## Class Date

This class contains the day(int), month(string), year(int), overloaded relational operators to easily compare dates, get-ers, overloaded read and write operators.

## Class Employee

This is the base class from which the other 2 are derived. It contains the employee id(int), last name(string), first name(string), salary(double) and hire date(date) of an employee, get-ers,
overloaded read and write operators that call on virtual methods read_details and show_details, 3 static variables: id_generator that has base value of 100 and increases with each object constructed
and number_of_employees that is incremented with each object constructed and decremented with each object destructed and current_date that converts the local time date from ctime to Date format.

### Format

There is an input example in the file "data.in" that is used in the program.

1. string last_name and string first_name

Simple strings, no input verification is conducted.

2. double salary

Input verification is conducted to see if type conversion to double is possible.

3. Date hire_date

Input verification is conducted to see if type conversion to int, string and int is possible. Moreover, the day needs to actually exist in said month,
the month needs to be the name of an actual month, not necessarily lowercase, no restriction for the year but the date as a whole needs to be before the current date.

## Class Part_time

This is a derived class of Employee. It further adds the number of hours per day(int) an employee works and when the contract expires(date).
Overloading on read and write operators is made by calling the overloaded virtual methods read_details or show_details that call upon the same methods from the base class.

### Format

1. int hours_day

Input verification is conducted to see if type conversion to int is possible.

2. Date contract_expiration_date

Input verification is conducted as for hire_date plus an additional verifcation to see if it is after the hire_date chronologically.

## Class Full_time

This is a derived class of Employee. It further adds the number of part-timers this employee is coaching(int).
Overloading on read and write operators is made by calling the overloaded virtual methods read_details or show_details that call upon the same methods from the base class.

### Format

1. int number_coaching

Input verification is conducted to see if type conversion to int is possible.

## Interactive Menu

User friendly commands that utilise most of the classes and their functions.

### -1 to close the program 

>Closes the program by breaking the while loop.

### 0 to show all employees

>Iterates through the employees vector and writes in the console.

### 1 to add new employees

>Opens another menu with 3 choices for each type of possible employee that can be added.

### 2 to remove an employee

>Removes an employee from the employees vector by searching the id given from input.

### 3 to show all part-time employees

>Iterates through the employees vector and only writes the part-time employees in the console.

### 4 to show all full-time employees

>Iterates through the employees vector and only writes the full-time employees in the console.

### 5 to remove all employees

>Removes all employees from the vector.

### 6 to show the december salary of an employee for the current year

>Reads the id of an employee, searches for it in the employees vector and calculates the salary of said employee as follows: </br>
For base employees it simply writes his usual salary. </br> </br>
For part-time employees, if the contract is expired by then it writes an adequate message, if it expires that december, it will write 75% of the salary and if it expires later it will write the full salary. </br> </br>
For full-time employees, it will write the normal salary plus a percentage of said salary (years active in company multiplied by part-time employees coaching).

## Error handling

The program only throws integers that it then catches and passes to an error handling function that reads the remaining data as garbage
and then writes an adequate message to the console.

```C++
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

// And somewhere in main

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
```


