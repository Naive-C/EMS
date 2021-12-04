/*
	EMS - fileio->c
	Employee Management System
	Copyright (C) 2021 Naive-C <naive->c->cell@gmail->com>
*/

#include "fileio.h"

coordinate find_employee(const char* id, ems* employee) 
{
	size_t off_set, file_length;
	off_set = file_length = 0;

	RDWR_FILE();
	file_length = return_file_length(fileno(employee_fp));
	rewind(employee_fp);

	while(1){	
		off_set = ftell(employee_fp);

		//if(fgets(buf, BUFSIZ, employee_fp) == NULL) { break; }
		
		if(fscanf(employee_fp,"%s %s %s %s",
				  employee->id, 
				  employee->first_name, 
				  employee->last_name, 
				  employee->salary) == EOF) { break; }	

		if(strcmp(employee->id, id) == 0){  
			coord.x_coord = off_set;
			coord.y_coord = ftell(employee_fp) + 1;
		}
	}
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

void RDWR_FILE()
{
	if((employee_fp = fopen("Employee.dat", "r+t")) == NULL){
		fprintf(stderr, ">>> READ_FILE: no such file");
		exit(1);
	}
}

void APPEND_FILE()
{
	if((employee_fp = fopen("Employee.dat", "a+")) == NULL){
		fprintf(stderr, ">>> APPEND_FILE: no such file");
		exit(1);
	}
}
