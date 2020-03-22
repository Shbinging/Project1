#include"ui.h"
#include"diag.h"
#include"agori.h"
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
	string name = queBox<string>("输入学生ID:", 2);
	string password = queBox<string>("输入学生密码:", 2);
	if (stu.checkpassword(name, password)){
		printf("*******登陆成功!*******\n");
		stuPanel(name);
	}
	else printf("用户名或密码错误！");

}

void UI::stuReg()
{
	string name = queBox<string>("输入学生ID:", 2);
	if (stu.isStuWordInList(stuWordNode(name))){
		printf("此ID已经注册！\n");
	}
	else{
		string password = queBox<string>("输入学生密码:", 2);
		stu.addStuWord(name, password);
		printf("*********注册成功,登录成功！*******\n");
		stuPanel(name);
	}
}

void UI::adminLogIn()
{
	string st = queBox<string>("输入管理员ID:", 2);
	string password = queBox<string>("输入管理员密码:", 2);
	if (admin.checkPassword(st, password)){
			printf("*******登陆成功!*******\n");
			adminPanel();
		}
	else printf("用户名或密码错误!\n");
}

void UI::cls()
{
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

void UI::stuPanel(string name)
{
	stu.setpath(name);
	printf("1.注销登录 2.查看课程信息 3.选课 4.查看个人课表 5.退课 6.举手报名助教7.选择个人助教\n");
	int tmp = queBox<int>("请选择所需的功能:", 1);
	switch (tmp){
	case 1:
		return;
		break;
	case 2:
		viewAllCourse();
		break;
	case 3:
		stu_addCourse();
		break;
	case 4:
		stu_viewAllCourse();
		break;
	case 5:
		stu_delCourse();
		break;
	case 6:
		stu_addAssistant();
		break;
	case 7:
		stu_selAssistant();
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
	string st = queBox<string>("输入需要查看的课程ID或名称:", 2);
	CourseNode curCourse;
	if (str_isNum(st)) curCourse.CourseId = stoi(st);
	else curCourse.CourseName = st;
	if (!admin.isCourseInList(curCourse)){
		printf("无此课程！");
	}
	else{
		CourseNode tmp = admin.getCourse(curCourse);
		printf("课程ID\t课程名称\t授课教师\t上限人数\t目前已选\t课程类型\n");
		printCourse(tmp);
	}
}

void UI::printCourse(CourseNode tmp){
	string id = str_toStringId(tmp.CourseId);
	cout << id << "\t" << tmp.CourseName << "\t" << tmp.CourseTeacher << "\t" << tmp.CourseCap << "\t" << tmp.CourseSel << "\t";
	if (tmp.CourseType == 0) cout << "专业课" << endl;
	else cout << "非专业课" << endl;
}
void UI::admin_addCourse()
{
	string st = queBox<string>("输入课程具体信息:", 2);
	vector<string> a = str_Split(st, ',');
	CourseNode tmp = CourseNode(a[0], a[1], stoi(a[2]), stoi(a[3]), a[4]);
	int state = admin.addCourse(tmp);//添加课程
	if (state == 1){
		printf("添加失败！课程已经在列表中!\n");
	}
	else{
		printf("添加成功！\n");
		viewAllCourse();
	}
}

void UI::admin_delCourse()
{
	int tmp = queBox<int>("输入课程编号:", 2);
	int tmp1 = admin.delCourse(tmp);
	if (tmp1 == 0){
		printf("删除成功！");
		viewAllCourse();
	}
	else if (tmp1 == 1){
		printf("课程删除失败！无此课程！");
	}
	else if (tmp1 == 2){
		printf("课程删除失败，目前已有学生选此课！");
	}
}

void UI::admin_editCourse()
{
	int id = queBox<int>("输入需要修改的id:", 1);
	if (!admin.isCourseInList(CourseNode(id))){
		printf("修改失败！无此课程！");
	}
	else{
		int tmp = queBox<int>("输入需要修改的字段(1.任课教师  2.容纳人数): ", 1);
		if (tmp == 1){
			string st = queBox<string>("修改教师名称为:", 2);


			CourseNode tmpCourse;
			tmpCourse.CourseName = st;
			tmpCourse.CourseId = id;
			int tmp1 = admin.editCourse(tmpCourse);
			if (!tmp1) printf("修改成功！\n");
			else printf("修改失败！\n");
		}
		else{
			if (tmp == 2){
				int cap= queBox<int>("修改容纳人数为:", 1);
				CourseNode tmpCourse;
				tmpCourse.CourseCap = cap;
				tmpCourse.CourseId = id;
				int tmp1 = admin.editCourse(tmpCourse);
				if (!tmp1) printf("修改成功！\n");
				else printf("修改失败！因为修改后的人数小于目前已选人数\n");
			}
		}
	}
}

void UI::stu_addCourse()
{
	int id = queBox<int>("输入课程id:", 1);
	int tmp = stu.addCourse(CourseNode(id));
	if (tmp == 0) printf("已经添加到个人课表中!\n");
	else if (tmp == 1)printf("添加失败！该课程已经在个人课表中!\n");
	else if (tmp == 2) printf("添加失败！该课程已满!\n");
}

void UI::stu_viewAllCourse()
{
	vector<stuCourseNode>& a = stu.getStuCourseList();
	printf("课程ID\t课程名称\t授课教师\t上限人数\t目前已选\t课程类型\n");
	For(i, 0, int(a.size()) - 1){
		int tmp = a[i].courseId;
		CourseNode tmp1 = stu.getCourse(CourseNode(tmp));
		printCourse(tmp1);
	}
}

void UI::stu_delCourse()
{
	int id = queBox<int>("输入课程id:", 1);
	int tmp = stu.delCourse(CourseNode(id));
	if (tmp == 0){
		printf("删除成功!\n");
		viewAllCourse();
	}
	else printf("删除失败!该课程不在个人课表中!");
}

void UI::stu_addAssistant()
{

}

void UI::stu_selAssistant()
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
	if (tmp == 0) printf("导入成功！\n");
	else if (tmp == 1) printf("导入失败！文件无法打开！\n");
	else if (tmp == 2) printf("导入失败！已有现成文件名单！\n");
}