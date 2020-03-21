#pragma once
#include"diag.h"
#include"userAdmin.h"
class UI
{
public:
	void cmdUi();
	void stuLogIn();
	void stuReg();
	void adminLogIn();
	void cls();
	void adminPanel();
	void viewAllCourse();
	void admin_addCourseFromFile();
	void viewCourse();
	void printCourse(CourseNode tmp);
	void admin_addCourse();
	void admin_delCourse();
	void admin_editCourse();
	template<class returnType>
	returnType queBox(string st, int opt);//1 int 2 string

private:
	userAdmin admin;
};
