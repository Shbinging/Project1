#include"ui.h"
#include"diag.h"
#include"userAdmin.h"
#include"databaseCurrentCourse.h"
#include"databaseStudentAll.h"
#include"databaseStudentX.h"
#include"databaseAssistant.h"
#include"databaseCourseAll.h"
#include"userStu.h"
int main(){
	UI b;
	//dataCourseStu.init();
	dataCourse.readFromFile();
	dataStuAll.readFromFile();
	dataAssi.readFromFile();
	dataCourseStu.init();
	b.cmdUi();
	return 0;
}