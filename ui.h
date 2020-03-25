#pragma once
#include"diag.h"
#include"userAdmin.h"
#include"userStu.h"
class UI
{
public:
	void cls();
	void wait();
	//面板类
	void cmdUi();//开始界面
	void stuLogIn();//学生登录界面
	void stuReg();//学生注册界面
	void adminLogIn();//管理员登录界面
	void adminPanel();//管理员主面板
	void stuPanel(string name);//学生主面板
	//组件：管理员
	void viewAllCourse();//查看全部课程
	void admin_addCourseFromFile();//2从文件导入课程
	void viewCourse();//7查看单个课程
	void viewStu(int Courseid);//7查看单个课程学生
	void admin_addCourse();//4增加课程
	void admin_delCourse();//5删除课程
	void admin_editCourse();//6编辑课程
	//组件：学生
	void stu_checkAssistError();//判断个人助教是否异常
	void stu_addCourse();//3选课
	void stu_viewAllCourse();//4查看个人课表
	void stu_delCourse();//5退课
	void stu_addAssistant();//6举手报名助教
	

	void stu_selAssistant();//7选择助教

	//部件：公共
	bool printAssist(int id);
	void printAssist(vector<string>&);//打印助教
	void printCourse(string);//完整版课表打印
	void printCoursePart(string);//部分课表打印
	int queBoxInt(string st);
	string queBoxStr(string st);
private:
	userAdmin admin;
	userStu stu;
};
