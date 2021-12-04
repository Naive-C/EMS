/*
    EMS - management.h
    Employee Management System
	Copyright (C) 2021 Naive-C <naive.c.cell@gmail.com>
*/

#ifndef MANAGEMENT_H_
#define MANAGEMENT_H_

#include "console.h"

extern void main_menu();
extern void view(ems* employee);
extern void search_option();
extern void search(size_t option, ems* employee);
extern void add(ems* employee);
extern void modify(size_t ph_ptr, ems* employee);
extern void delete(size_t ph_ptr, ems* employee);

#endif
