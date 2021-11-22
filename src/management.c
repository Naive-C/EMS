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

// void search_option(ems* employee)
// {

//     RW_FILE(__func__);
//     print_header(">> Choose Search Option");

//     printf("             -------------------------------------------------------             \n");
//     printf("                               <1> Search By First Name	                         \n");
//     printf("                               <2> Search By Last Name                           \n");
//     printf("                               <3> Search By ID                                  \n");
//     printf("             -------------------------------------------------------             \n");
//     printf("                                                             <0> Exit            \n");
//     printf("             입력: ");

//     unknown_char_search_menu_retry:
// 	fflush(stdin);
//     switch(getchar()){
//         case '1':
// 			searchByFirstName(&employee);
// 			break;
// 		case '2':
// 			searchByLastName(&employee);
// 			break;
//         case '3':
// 			searchById(&employee);
// 			break;
//         case '4':
//             search('4', &employee);
//             break;
// 		case '0': 
//             getchar();
//             fclose(employee_fp);
//             break;
//         default:
// 			//TODO: 옵션을 제외한 케릭터에 대한 예외처리
//             goto unknown_char_search_menu_retry;
//     } 
// }

void search_option()
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
			search(1, &employee);
			break;
		case '2':
			search(2, &employee);
			break;
        case '3':
			search(3, &employee);
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

void search(int input, ems* employee)
{
     RW_FILE(__func__);

    typedef enum {
        FIRST_NAME = 1,
        LAST_NAME = 2,
        ID = 3
    }OPTION;

    char ask[100];
    char option_name[20];

    char search_first_name;
    char search_last_name;
    char search_id;

    OPTION option = input;
    
    if(option == 1) {
        strcpy(option_name, "First Name");
    }
    else if(option == 2) {
        strcpy(option_name, "Last Name");
    }
    else if(option == 3) {
        strcpy(option_name, "ID");
    }

    printf("             -------------------------------------------------------                  \n");
    printf("                    Write the %s you want to search                                   \n", option_name);
    printf("             -------------------------------------------------------                  \n");

    printf("             입력: ");
    scanf("%s", ask); 

    while((fscanf(employee_fp, "%s %s %s %zu",
		employee->id, employee->first_name, employee->last_name, &employee->salary)) != EOF) {
        search_first_name = strstr(employee->first_name, ask);
        search_last_name = strstr(employee->last_name, ask);
        search_id = strstr(employee->id, ask);
        if( (input == FIRST_NAME) && (search_first_name != NULL) || (input == LAST_NAME) && (search_last_name != NULL) || (input == ID) && (search_id != NULL) ) {
             printf("             |%-10s|%-15s|%-15s|%-10zu|\n", employee->id, employee->first_name, employee->last_name, employee->salary);
        }
    }
    printf("             -------------------------------------------------------             \n");
    printf("                    press any key return to the search option                    \n");
    getchar();
    getchar();

    fclose(employee_fp);
    search_option();
   
    
}