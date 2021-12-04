/*
	EMS - delete.c
	Employee Management System
	Copyright (C) 2021 Naive-C <naive.c.cell@gmail.com>
*/

#include "management.h"

#ifndef DELETE 
 #define DELETE delete 
#endif

void delete(size_t ph_ptr, ems* employee)
{
	ems delete; 
	size_t n, counter;
	n = 1;
	counter = 0;

	if(ph_ptr == 0){
		print_header(">> Delete");
	}
	printf("             >> Delete ID: ");
	fflush(stdin);
	scanf("%10s", delete.id);
	if(strcmp(delete.id, "-1") == 0){main_menu();}

	RDWR_FILE();
	FILE* tmp_fp = fopen("tmp.dat", "wb");

    while((fscanf(employee_fp, "%s %s %s %s",
				  employee->id, employee->first_name, employee->last_name, employee->salary)) != EOF) {
		if(strcmp(employee->id, delete.id) == 0){
			printf("      ------ -------------------------------------------------------             \n");
			printf("      Status |ID        |First Name     |Last Name      |Salary    |\n"); 
			printf("      ------ -------------------------------------------------------             \n");
			printf("      Delete |%-10s|%-15s|%-15s|%-10s|\n", employee->id, employee->first_name, employee->last_name, employee->salary);
			printf("      ------ -------------------------------------------------------             \n");
			++counter;
		}
		else{
    		fprintf(tmp_fp, "%s %s %s %s\n", employee->id, employee->first_name, employee->last_name, employee->salary);
		}
	}
	if(counter != n){
		printf("             -------------------------------------------------------             \n");
		printf("                      일치하는 사원 정보가 존재하지않습니다\n");
		printf("             -------------------------------------------------------             \n");
		printf("             press any key return to the main menu");
		fflush(stdin);
		getchar();
    	fclose(employee_fp);
		main_menu();
	}
	else{
    	printf("                                  Delete Data\n");
    	printf("                              <Y>Yes        <N>No\n");
    	printf("             Choose Option: ");
	}

modify_employee_retry:
	fflush(stdin);
    switch(tolower(getchar())){
        case 'y':
			remove("Employee.dat");
			rename("tmp.dat", "Employee.dat");
            fclose(employee_fp);
            fclose(tmp_fp);
			main_menu("record delete successfully");
            break;
        case 'n':
			remove("tmp.dat");
            fclose(employee_fp);
            fclose(tmp_fp);
			main_menu();
            break;
        default:
    		printf("             Choose Option: ");
            goto modify_employee_retry;
    }
}
