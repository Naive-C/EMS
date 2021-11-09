/*
	EMS - main_menu.c
	Employee Management System
	Copyright (C) 2021 Naive-C <naive.c.cell@gmail.com>
*/

#include "main_menu.h"

void main_menu()
{
	print_header("");
    printf("                    ▄   ▄  ▄▄   ▄ ▄▄▄   ▄▄▄▄   ▄▄  ▄▄▄  ▄  ▄                     \n");
    printf("                    █▀▄▀█ █  █  ▄ █  █  █ █ █ █▄▄█ █  █ █  █                     \n");
    printf("                    █   █ ▀▄▄▀▄ █ █  █  █ █ █ ▀▄▄  █  █ ▀▄▄▀▄                    \n");
    printf("             -------------------------------------------------------             \n");
    printf("                               <1> View Employees	                             \n");
    printf("                               <2> Search Employee                               \n");
    printf("                               <3> Add Employee                                  \n");
    printf("             -------------------------------------------------------             \n");
    printf("                                                             <0> Exit            \n");
    printf("             입력: ");

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
		case '0': 
            exit(0);
        default:
			//TODO: 옵션을 제외한 케릭터에 대한 예외처리
            goto unknown_char_main_menu_retry;
    }   
}
