/* 
   	EMS - view.c
	Employee Management System
	Copyright (C) 2021 Naive-C <naive.c.cell@gmail.com>
*/

#include "management.h"

#ifndef VIEW
 #define VIEW view 
#endif

void view(ems* employee)
{
	RDWR_FILE();
	print_header(">> View Employees");
	
	printf("             |ID        |First Name     |Last Name      |Salary    |\n"); 
   	printf("             -------------------------------------------------------             \n");
    while((fscanf(employee_fp, "%s %s %s %s",
		   employee->id, employee->first_name, employee->last_name, employee->salary)) != EOF)
	{
		printf("             |%-10s|%-15s|%-15s|%-10s|\n", employee->id, employee->first_name, employee->last_name, employee->salary); 
    }
    printf("             -------------------------------------------------------             \n");
	printf("             press any key return to the main menu");
	fflush(stdin);
	getchar();
    fclose(employee_fp);

	main_menu();
}
