/*
	EMS - employee_update.c
	Employee Management System
	Copyright (C) 2021 Naive-C <naive.c.cell@gmail.com>
*/

#include "employee_update.h"

void modify(const char* id, const char* origin_data, const char* modify_data)
{
	char buf[BUFSIZ];
	const char* id_addr;
	const char* modify_addr;
	size_t modify_ptr;

	while(fgets(buf, BUFSIZ, employee_fp) != NULL){
		id_addr = strstr(buf, id);
		modify_addr = strstr(buf, modify_data);

		if(id_addr != NULL && modify_addr != NULL){
			modify_ptr = modify_addr - buf;
			fseek(employee_fp, modify_ptr, SEEK_SET);
			fwrite(modify_data, strlen(modify_data), 1, employee_fp);
		}
	}
}

void delete(coordinate* coord)
{
}
