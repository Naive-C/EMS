/*
	EMS - main_menu.c
	Employee Management System
	Copyright (C) 2021 Naive-C <naive.c.cell@gmail.com>
*/

#include "main_menu.h"

void main_menu(const char *msg)
{
	system("clear");
	print_header_non_clear("       Developed by 성주용, 원성연");
    printf("                    ▄   ▄  ▄▄   ▄ ▄▄▄   ▄▄▄▄   ▄▄  ▄▄▄  ▄  ▄                     \n");
    printf("                    █▀▄▀█ █  █  ▄ █  █  █ █ █ █▄▄█ █  █ █  █                     \n");
    printf("                    █   █ ▀▄▄▀▄ █ █  █  █ █ █ ▀▄▄  █  █ ▀▄▄▀▄                    \n");
    printf("             -------------------------------------------------------             \n");
    printf("                               <1> View Employees	                             \n");
    printf("                               <2> Search Employee                               \n");
    printf("                               <3> Add Employee                                  \n");
    printf("                               <4> Modify Employee                               \n");
    printf("                               <5> Delete Employee                               \n");
    printf("             -------------------------------------------------------             \n");
    printf("                                                             <0> exit            \n");
    printf("             Choose Option: ");

unknown_char_main_menu_retry:
	fflush(stdin);
    switch(getchar()){
        case '1':
			view(&employee);
			break;
		case '2':
			search_option();
			break;
        case '3':
			add(&employee);
			break;
		case '4':
			modify(0, &employee);
			break;
		case '5':
			delete(0, &employee);
			break;
		case '0': 
			exit(0);
        default:
    		printf("             Choose Option: ");
			goto unknown_char_main_menu_retry;
    }   
}
