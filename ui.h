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
	string queBoxStr(string st, int opt = 0);//opt == 1允许输入空格
	vector<string> queBoxStrList(string st, char ch = ' ');//默认空格隔开
private:
	userAdmin admin;
	userStu stu;
};

class Password//用一个类实现，其实也可以不用这么麻烦，练习一下
{
public:
	Password()//构造函数，这里主要用于初始化密码，使之为空
	{
		psw = "";//初始化密码为空"";
		length = 0; //初始化密码长度
	}
	void inputPassword(string st)//用于输入并回显*为密码
	{
		char temp_c;
		cout << st;
		while (true)
		{
			temp_c = _getch();  //输入一个字符
			if (temp_c != char(13))  //判断该字符是不为回车，如果是则退出while
			{
				switch (temp_c)
				{
				case 8:
					if (length != 0)
					{
						cout << "/b /b";
						psw = psw.substr(0, length - 1);
						length--;
					}
					else;
					break;
				default:
					cout << "*"; //可用用你喜欢的任意字符，如改为cout<<"";则无回显
					psw += temp_c;//连成字符串；
					length++;
					break;
				}
			}
			else break;
		}
	}
	string getPassword()//返回一个密码字符串，其实可以把密码再次加密，存在数据库中。
	{
		return psw;
	}
private:
	string psw;//用于存密码的字符串；
	int length;//密码长度
};