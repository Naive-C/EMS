/*
	EMS - add.c
	Employee Management System
	Copyright (C) 2021 Naive-C <naive.c.cell@gmail.com>
*/

#include "management.h"

#ifndef ADD 
 #define ADD add 
#endif

void add(ems* employee)
{
	APPEND_FILE();
	print_header(">> Add Employee");

    printf("             >> ID: ");
    fflush(stdin);
    scanf("%10s", employee->id);
	if(strcmp(employee->id, "-1") == 0){main_menu();}

    printf("             >> First Name: ");
    fflush(stdin);
    scanf("%15s", employee->first_name);
	if(strcmp(employee->first_name, "-1") == 0){main_menu();}

    printf("             >> Last Name: ");
    fflush(stdin);
    scanf("%15s", employee->last_name);
	if(strcmp(employee->last_name, "-1") == 0){main_menu();}

    printf("             >> Salary: ");
    fflush(stdin);
    scanf("%10s", employee->salary);
	if(strcmp(employee->salary, "-1") == 0){main_menu();}

    //TODO: 사원에 대한 속성 추가 

	print_header(">> New Employee Information");
    printf("             ID        : %s\n", employee->id);
    printf("             First Name: %s\n", employee->first_name);
    printf("             Last Name : %s\n", employee->last_name);
    printf("             Salary    : %s\n", employee->salary);
    printf("             -------------------------------------------------------             \n");
    printf("                                  Record Data\n");
    printf("                              <Y>Yes        <N>No\n");
    printf("             Choose Option: ");

add_employee_retry:
	fflush(stdin);
    switch(tolower(getchar())){
        case 'y':
            fprintf(employee_fp, "%s %s %s %s\n",
				   	employee->id, employee->first_name, employee->last_name, employee->salary);
            fclose(employee_fp);
			main_menu("record added successfully");
            break;
        case 'n':
            fclose(employee_fp);
			main_menu();
            break;
        default:
    		printf("             Choose Option: ");
            goto add_employee_retry;
    }
}
