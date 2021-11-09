/*
    EMS - console.c
    Employee Management System
    Copyright (C) 2021 Naive-C <naive.c.cell@gmail.com>
*/

#include "console.h"

void print_header(const char* current_page)
{
	size_t center = (40 - (strlen(current_page) / 2));
	system("clear");
    printf("             -------------------------------------------------------             \n");
	for(size_t i = 0; i < center; ++i){
		printf(" ");
	}
	printf("%s\n", current_page);
    printf("             -------------------------------------------------------             \n");
}
