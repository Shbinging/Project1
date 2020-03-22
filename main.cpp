#include"ui.h"
#include"diag.h"
#include"userAdmin.h"
#include"databaseCurrentCourse.h"
int main(){
	UI b;
	b.viewAllCourse();
	b.admin_addCourseFromFile();
	b.viewAllCourse();
	return 0;
}