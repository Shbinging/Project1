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
	void wait();
	void adminPanel();
	void stuPanel(string name);
	void viewAllCourse();
	void admin_addCourseFromFile();
	void viewCourse();
	void viewStu(int Courseid);
	void printCourse(string);
	void admin_addCourse();
	void admin_delCourse();
	void admin_editCourse();
	void stu_checkAssistError();
	void stu_addCourse();
	void stu_viewAllCourse();
	void stu_delCourse();
	void printAssist(vector<string>&);
	void stu_addAssistant();
	bool printAssist(int id);
	void stu_selAssistant();
	template<class returnType>
	returnType queBox(string st, int opt);//1 int 2 string

private:
	userAdmin admin;
	userStu stu;
};
