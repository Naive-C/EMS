/*
	EMS - management.c
	Employee Management System
	Copyright (C) 2021 Naive-C <naive.c.cell@gmail.com>
*/

#include "management.h"

void view(ems* employee)
{
	RW_FILE(__func__);
	print_header(">> View Employees");
             
	printf("             |ID        |First Name     |Last Name      |Salary    |\n"); 
    printf("             -------------------------------------------------------             \n");
    while((fscanf(employee_fp, "%s %s %s %zu",
		   employee->id, employee->first_name, employee->last_name, &employee->salary)) != EOF){
		printf("             |%-10s|%-15s|%-15s|%-10zu|\n", employee->id, employee->first_name, employee->last_name, employee->salary); 
    }
    printf("             -------------------------------------------------------             \n");
	
	printf("             press any key return to the main menu");
	//fflush(stdin);
    getchar();
	getchar();

    fclose(employee_fp);
}

void add(ems* employee)
{

	APPEND_FILE(__func__);
	print_header(">> Add Employee");

    printf("             >> ID: ");
    fflush(stdin);
    scanf("%10s", employee->id);

    printf("             >> First Name: ");
    fflush(stdin);
    scanf("%15s", employee->first_name);

    printf("             >> Last Name: ");
    fflush(stdin);
    scanf("%15s", employee->last_name);

    printf("             >> Salary: ");
    fflush(stdin);
    scanf("%10zu", &employee->salary);

    //TODO: hire_flag는 true, fire_flag는 false로 변경

	print_header(">> New Employee Information");
    printf("             ID        : %s\n", employee->id);
    printf("             First Name: %s\n", employee->first_name);
    printf("             Last Name : %s\n", employee->last_name);
    printf("             Salary    : %zu\n", employee->salary);
    printf("             --------------------------------------------------------          \n");
    printf("                                  Record Data\n");
    printf("                              <Y>Yes        <N>No\n");
    printf("             Choose Option: ");

add_employee_retry:
    switch(tolower(getchar())){
        case 'y':
            fprintf(employee_fp, "%s %s %s %zu\n", employee->id, employee->first_name, employee->last_name, employee->salary);
            fclose(employee_fp);
            break;
        case 'n':
            break;
        default:
            goto add_employee_retry;
    }
}

void search_option(ems* employee)
{
    RW_FILE(__func__);
    print_header(">> Choose Search Option");

    printf("             -------------------------------------------------------             \n");
    printf("                               <1> Search By First Name	                         \n");
    printf("                               <2> Search By Last Name                           \n");
    printf("                               <3> Search By ID                                  \n");
    printf("             -------------------------------------------------------             \n");
    printf("                                                             <0> Exit            \n");
    printf("             입력: ");

    unknown_char_search_menu_retry:
	fflush(stdin);
    switch(getchar()){
        case '1':
			searchByFirstName(&employee);
			break;
		case '2':
			searchByLastName(&employee);
			break;
        case '3':
			searchById(&employee);
			break;
		case '0': 
            getchar();
            fclose(employee_fp);
            break;
        default:
			//TODO: 옵션을 제외한 케릭터에 대한 예외처리
            goto unknown_char_search_menu_retry;
    } 
}

void searchByFirstName(ems* employee)
{
    char input[100];
    RW_FILE(__func__);
    printf("             -------------------------------------------------------             \n");
    printf("                    Write the First Name you want to search                      \n");
    printf("             -------------------------------------------------------             \n");

    printf("             입력: ");
    scanf("%s", input); 

    print_header(">> Search By First Name");
     
    printf("             |ID        |First Name     |Last Name      |Salary    |\n"); 
    printf("             -------------------------------------------------------             \n");
    while((fscanf(employee_fp, "%s %s %s %zu",
		employee->id, employee->first_name, employee->last_name, &employee->salary)) != EOF) {
        if(strcmp(employee->first_name, input) == 0) {
            printf("             |%-10s|%-15s|%-15s|%-10zu|\n", employee->id, employee->first_name, employee->last_name, employee->salary);
        }
    }
    printf("             -------------------------------------------------------             \n");
    getchar();
    getchar();

    fclose(employee_fp);
}

void searchByLastName(ems* employee)
{
    char input[100];
    RW_FILE(__func__);
    printf("             -------------------------------------------------------             \n");
    printf("                    Write the Last Name you want to search                       \n");
    printf("             -------------------------------------------------------             \n");

    printf("             입력: ");
    scanf("%s", input); 

    print_header(">> Search By Last Name");
     
    printf("             |ID        |First Name     |Last Name      |Salary    |\n"); 
    printf("             -------------------------------------------------------             \n");
    while((fscanf(employee_fp, "%s %s %s %zu",
		employee->id, employee->first_name, employee->last_name, &employee->salary)) != EOF) {
        if(strcmp(employee->last_name, input) == 0) {
            printf("             |%-10s|%-15s|%-15s|%-10zu|\n", employee->id, employee->first_name, employee->last_name, employee->salary);
        }
    }
    printf("             -------------------------------------------------------             \n");
    getchar();
    getchar();

    fclose(employee_fp);
}

void searchById(ems* employee)
{
    char input[100];
    RW_FILE(__func__);
    printf("             -------------------------------------------------------             \n");
    printf("                    Write the ID you want to search                              \n");
    printf("             -------------------------------------------------------             \n");

    printf("             입력: ");
    scanf("%s", input); 

    print_header(">> Search By Last Name");
     
    printf("             |ID        |First Name     |Last Name      |Salary    |\n"); 
    printf("             -------------------------------------------------------             \n");
    while((fscanf(employee_fp, "%s %s %s %zu",
		employee->id, employee->first_name, employee->last_name, &employee->salary)) != EOF) {
        if(strcmp(employee->id, input) == 0) {
            printf("             |%-10s|%-15s|%-15s|%-10zu|\n", employee->id, employee->first_name, employee->last_name, employee->salary);
        }
    }
    printf("             -------------------------------------------------------             \n");
    getchar();
    getchar();

    fclose(employee_fp);
}
