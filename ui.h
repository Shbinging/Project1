#pragma once
#include"diag.h"
#include"userAdmin.h"
#include"userStu.h"
class UI
{
public:
	void cmdUi();
	void stuLogIn();
	void stuReg();
	void adminLogIn();
	void cls();
	void adminPanel();
	void stuPanel(string name);
	void viewAllCourse();
	void admin_addCourseFromFile();
	void viewCourse();
	void printCourse(CourseNode tmp);
	void admin_addCourse();
	void admin_delCourse();
	void admin_editCourse();
	void stu_addCourse();
	void stu_viewAllCourse();
	void stu_delCourse();
	void printAssist(assistNode& tmp);
	void stu_addAssistant();
	void stu_selAssistant();
	template<class returnType>
	returnType queBox(string st, int opt);//1 int 2 string

private:
	userAdmin admin;
	userStu stu;
};
