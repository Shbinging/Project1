#include"ui.h"
#include"diag.h"

void UI::cmdUi(){
	//while (1){
		printf("1.学生登录	2.学生注册	3.管理员登录\n");
		printf("输入操作:");

		int opt;
		scanf_s("%d", &opt);
		switch (opt){
		case 1:
			stuLogIn();
			break;
		case 2:
			stuReg();
			break;
		case 3:
			adminLogIn();
		}
	//}
}

void UI::stuLogIn()
{
}

void UI::stuReg()
{
}

void UI::adminLogIn()
{
	string st = queBox<string>("输入管理员ID:", 2);
	if (st == "Admin"){
		string password = queBox<string>("输入管理员密码:", 2);
		if (password == "admin"){
			printf("*******登陆成功!*******\n");
			adminPanel();
		}
	}
}

void UI::adminPanel()
{
	printf("1.注销登录 2.录入课程信息 3.查看全部课程信息 4.增加课程 5.删除课程 6.修改课程 7.查看具体课程\n");
	int tmp = queBox<int>("请选择所需的功能:", 1);
	switch (tmp){
	case 1: 
		return;
		break;
	case 2:
		admin_addCourseFromFile();
		break;
	case 3:
		viewAllCourse();
		break;
	case 4:
		admin_addCourse();
		break;
	case 5:
		admin_delCourse();
		break;
	case 6:
		admin_editCourse();
		break;
	case 7:
		viewCourse();
		break;
	}
}

void UI::viewAllCourse()
{
	printf("课程ID\t课程名称\t授课教师\t上限人数\t目前已选\t课程类型\n");
	vector<CourseNode>& CourseList = admin.getCourseList();
	For(i, 0, int(CourseList.size()) - 1) printCourse(CourseList[i]);
}

void UI::viewCourse()
{
}

void UI::printCourse(CourseNode tmp){
	string id = to_string(tmp.CourseId);
	if (id.length() == 1) id = "00" + id;
	else if (id.length() == 2) id = "0" + id;
	cout << id << "\t" << tmp.CourseName << "\t" << tmp.CourseTeacher << "\t" << tmp.CourseCap << "\t" << tmp.CourseSel << "\t";
	if (tmp.CourseType == 0) cout << "专业课" << endl;
	else cout << "非专业课" << endl;
}
void UI::admin_addCourse()
{
}

void UI::admin_delCourse()
{
}

void UI::admin_editCourse()
{
}

template<class returnType>
returnType UI::queBox(string st, int opt)
{
	cout << st;
	returnType tmp;
	cin >> tmp;
	return tmp;
}

void UI::admin_addCourseFromFile()
{
	string path = queBox<string>("请输入需要导入的文件名称:", 2);
	int tmp = admin.addStuFromFile(path);
	if (tmp == 0) cout << "导入成功！";
}