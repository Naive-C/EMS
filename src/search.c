/*
	EMS - search.c
	Employee Management System
	Copyright (C) 2021 Naive-C <naive.c.cell@gmail.com>
*/

#include "management.h"

#ifndef SEARCH
 #define SEARCH search 
#endif

void search_option()
{
    RDWR_FILE();
    print_header(">> Choose Search Option");

    printf("                       <1> ID <2> First Name <3> Last Name                      \n");
    printf("             -------------------------------------------------------             \n");
    printf("                                                             <0> Exit            \n");
    printf("             Choose Option: ");

unknown_char_search_menu_retry:
	fflush(stdin);
    switch(getchar()){
        case '1':
			search(ID, &employee);
			break;
		case '2':
			search(FIRST_NAME, &employee);
			break;
        case '3':
			search(LAST_NAME, &employee);
			break;
		case '0': 
			main_menu();
            fclose(employee_fp);
            break;
        default:
    		printf("             Choose Option: ");
            goto unknown_char_search_menu_retry;
    } 
}

void search(size_t option, ems* employee)
{
    char ask[15];
	char* option_name = NULL,
    	* search_first_name,
		* search_last_name,
		* search_id;
	size_t n, counter = 0;
	n = counter = 0;

    RDWR_FILE();
    print_header(">> Search");

    if(option == ID)
		option_name = "ID";
    else if(option == FIRST_NAME)
		option_name = "First Name";	
    else if(option == LAST_NAME)
		option_name = "Last Name";	
    
    printf("             입력: ");
    scanf("%s", ask); 
    printf("             -------------------------------------------------------             \n");
	while((fscanf(employee_fp, "%s %s %s %s",
				  employee->id, employee->first_name, employee->last_name, employee->salary)) != EOF) 
	{
        search_id = strstr(employee->id, ask);
        search_first_name = strstr(employee->first_name, ask);
        search_last_name = strstr(employee->last_name, ask);

        if((option == ID && search_id != NULL                 )
		|| (option == LAST_NAME && search_last_name != NULL   )
	   	|| (option == FIRST_NAME && search_first_name != NULL)) 
		{
             printf("             |%-10s|%-15s|%-15s|%-10s|\n", 
					employee->id, employee->first_name, employee->last_name, employee->salary);
			 ++counter;
        }
    }
	if(n == counter){
		printf("                     일치하는 사원 정보를 찾을 수 없습니다\n");
		printf("             -------------------------------------------------------             \n");
    	printf("                            <1> Main menu <2> Search                         \n");
    	printf("             -------------------------------------------------------             \n");
    	printf("             Choose Option: ");
    	fclose(employee_fp);
	}
	else{

    	printf("             -------------------------------------------------------             \n");
    	printf("                 <1> Main menu <2> Search <3> Modify <4> Delete                        \n");
    	printf("             -------------------------------------------------------             \n");
    	printf("             Choose Option: ");
    	fclose(employee_fp);
	}

unknown_char_search_menu_retry:
	fflush(stdin);
    switch(getchar()){
        case '1':
			main_menu();
			break;
		case '2':
			search_option();
			break;
        case '3':
			delete(1, employee);
			break;
        case '4':
			delete(1, employee);
			break;
        default:
    		printf("             Choose Option: ");
            goto unknown_char_search_menu_retry;
    } 
}
