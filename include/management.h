/*
    EMS - management.h
    Employee Management System
	Copyright (C) 2021 Naive-C <naive.c.cell@gmail.com>
*/

#ifndef MANAGEMENT_H_
#define MANAGEMENT_H_

#include "employee_update.h"
#include "console.h"

void view(ems* employee);
void search_option(ems* employee);
void searchByFirstName(ems* employee);
void searchByLastName(ems* employee);
void searchById(ems* employee);
void add(ems* employee);

#endif
