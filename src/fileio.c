/*
	EMS - fileio.c
	Employee Management System
	Copyright (C) 2021 Naive-C <naive.c.cell@gmail.com>
*/

#include "fileio.h"

coordinate* find_employee(const char* id, coordinate* coord) 
{
	RW_FILE(__func__);

	size_t off_set, file_length;
	off_set = file_length = 0;

	file_length = return_file_length(fileno(employee_fp));

	char buf[file_length + 1];

	while(1){	
		off_set = ftell(employee_fp);

		if(fgets(buf, 1024, employee_fp) == NULL) { break; }
			
		if(strstr(buf, id) != NULL){  
			coord->start_pos = off_set;
			coord->end_pos  = ftell(employee_fp);
			coord->after_the_end_position = file_length - ftell(employee_fp);
		}
	}

	fclose(employee_fp);	
	return coord;
}

size_t return_file_length(const int fd)
{
	struct stat buf;
	fstat(fd, &buf);

	//리턴 값: 
    //	   파일 기술자가 가리키고 있는 파일의 크기	
	size_t size = buf.st_size;

	return size;
}

void RW_FILE(const char* func_name)
{
	if((employee_fp = fopen("Employee.txt", "r+w")) == NULL){
		fprintf(stderr, "             %s >>> READ_FILE: no such file", func_name);
		exit(1);
	}
}

void APPEND_FILE(const char* func_name)
{
	if((employee_fp = fopen("Employee.txt", "a+")) == NULL){
		fprintf(stderr, "             %s >>> APPEND_FILE: no such file", func_name);
		exit(1);
	}
}
