/*
 	EMS - ems.h
 	Employee Management System
 	Copyright (C) 2021 Naive-C <naive.c.cell@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

FILE* employee_fp;

enum{
	ID = 1,
    FIRST_NAME,
    LAST_NAME 
};

typedef enum{
	false,
	true
}boolean;

typedef struct ems{
	char         id[11];
	char first_name[16];
	char  last_name[16];
	char     salary[11];
}ems;
ems employee;

typedef struct coordinate{
	size_t   x_coord;
	size_t   y_coord;
}coordinate;
coordinate coord;
