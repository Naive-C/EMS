/*
    EMS - fileio.h
    Employee Management System
	Copyright (C) 2021 Naive-C <naive.c.cell@gmail.com>
*/

#ifndef FILEIO_H_
#define FILEIO_H_

#include <sys/stat.h>
#include "ems.h"

coordinate find_employee(const char* id, ems* employee); 
size_t return_file_length(const int fd);
void RDWR_FILE();
void APPEND_FILE();

#endif
