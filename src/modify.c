/*
	EMS - modify.c
	Employee Management System
	Copyright (C) 2021 Naive-C <naive.c.cell@gmail.com>
*/

#include "management.h"

#ifndef MODIFY
 #define MODIFY modify
#endif

void modify(size_t ph_ptr, ems* employee)
{
	ems modify, tmp;
	size_t n, counter;
	n       = 1; 
	counter = 0;
	RDWR_FILE();
	FILE* tmp_fp = fopen("tmp.dat", "wb");

	if(ph_ptr == 0){
		print_header(">> Modify");
	}
	else{
		printf("             -------------------------------------------------------             \n");
	}

	printf("             >> Modify ID: ");
	fflush(stdin);
	scanf("%10s", modify.id);
	if(strcmp(modify.id, "-1") == 0){main_menu();}
	
    while((fscanf(employee_fp, "%s %s %s %s",
				  employee->id, employee->first_name, employee->last_name, employee->salary)) != EOF) {
		if(strcmp(employee->id, modify.id) == 0){
			++counter;
		}
	}
	if(n != counter){
		printf("             -------------------------------------------------------             \n");

		printf("                     일치하는 사원 정보를 찾을 수 없습니다\n");
		printf("             -------------------------------------------------------             \n");
		printf("             press any key return to the main menu");
		fflush(stdin);
		getchar();
    	fclose(employee_fp);

		main_menu();
	}

	printf("             >> First Name: ");
	fflush(stdin);
	scanf("%15s", modify.first_name);
	if(strcmp(modify.first_name, "-1") == 0){main_menu();}

	printf("             >> Last Name: ");
	fflush(stdin);
	scanf("%15s", modify.last_name);
	if(strcmp(modify.last_name, "-1") == 0){main_menu();}

	printf("             >> Salary: ");
	fflush(stdin);
	scanf("%10s", modify.salary);
	if(strcmp(modify.salary, "-1") == 0){main_menu();}

	rewind(employee_fp);
    while((fscanf(employee_fp, "%s %s %s %s",
				  employee->id, employee->first_name, employee->last_name, employee->salary)) != EOF) {
		if(strcmp(employee->id, modify.id) == 0){
			fprintf(tmp_fp, "%s %s %s %s\n", modify.id, modify.first_name, modify.last_name, modify.salary);
			strcpy(tmp.id, employee->id);
			strcpy(tmp.first_name, employee->first_name);
			strcpy(tmp.last_name, employee->last_name);
			strcpy(tmp.salary, employee->salary);
		}
		else{
			fprintf(tmp_fp, "%s %s %s %s\n",employee->id, employee->first_name, employee->last_name, employee->salary);
		}
	}
   	printf("      ------ -------------------------------------------------------             \n");
	printf("      Status |ID        |First Name     |Last Name      |Salary    |\n"); 
   	printf("      ------ -------------------------------------------------------             \n");
   	printf("      Origin |%-10s|%-15s|%-15s|%-10s|\n", tmp.id, tmp.first_name, tmp.last_name, tmp.salary);
   	printf("      Modify |%-10s|%-15s|%-15s|%-10s|\n", modify.id, modify.first_name, modify.last_name, modify.salary);
   	printf("      ------ -------------------------------------------------------             \n");
   	printf("                                  Delete Data\n");
   	printf("                              <Y>Yes        <N>No\n");
    printf("             Choose Option: ");

modify_employee_retry:
	fflush(stdin);
    switch(tolower(getchar())){
        case 'y':
			remove("Employee.dat");
			rename("tmp.dat", "Employee.dat");
            fclose(employee_fp);
            fclose(tmp_fp);
			main_menu("record modified successfully");
            break;
        case 'n':
			remove("tmp.dat");
            fclose(employee_fp);
            fclose(tmp_fp);
			main_menu();
            break;
		case 's':
			search_option();
			break;
        default:
    		printf("             Choose Option: ");
            goto modify_employee_retry;
    }
}
