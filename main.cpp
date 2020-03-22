#include"ui.h"
#include"diag.h"
#include"userAdmin.h"
#include"databaseCurrentCourse.h"
int main(){
	UI b;
	b.admin_addCourse();
	b.admin_addCourse();
	//b.admin_editCourse();
	b.viewCourse();
	return 0;
}