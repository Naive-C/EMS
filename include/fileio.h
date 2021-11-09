/*
    EMS - fileio.h
    Employee Management System
	Copyright (C) 2021 Naive-C <naive.c.cell@gmail.com>
*/

#ifndef FILEIO_H_
#define FILEIO_H_

#include <sys/stat.h>
#include "ems.h"

coordinate* find_employee(const char* id, coordinate* coord); 
size_t return_file_length(const int fd);
void RW_FILE(const char* func_name);
void APPEND_FILE(const char* func_name);

#endif
