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

typedef struct ems{
	char         id[10];
	char first_name[15];
	char  last_name[15];
	size_t 		 salary;
}ems;
ems employee;

typedef struct coordinate{
	int   start_pos;
	int   end_pos;
	int	  after_the_end_position;
}coordinate;
coordinate coord;
