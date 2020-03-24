#include"ui.h"
#include"diag.h"
#include"agori.h"
#include<conio.h>
void UI::cmdUi(){
	while (1){
		printf("1.学生登录	2.学生注册	3.管理员登录		4.关闭\n");
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
		case 4:
			return;
		}
		wait();
	}
}

void UI::stuLogIn()
{
	string name = queBox<string>("输入学生ID:", 2);
	string password = queBox<string>("输入学生密码:", 2);
	if (stu.checkpassword(name, password)){
		printf("*******登陆成功!*******\n");
		wait();
		stuPanel(name);
	}
	else printf("用户名或密码错误！\n");
	wait();
	cmdUi();

}

void UI::stuReg()
{
	string name = queBox<string>("输入学生ID:", 2);
	if (stu.isStuWordInList(stuWordNode(name))){
		printf("此ID已经注册！\n");
		wait();
		cmdUi();
	}
	else{
		string password = queBox<string>("输入学生密码:", 2);
		stu.addStuWord(name, password);
		printf("*********注册成功,登录成功！*******\n");
		wait();
		stuPanel(name);
	}
}

void UI::adminLogIn()
{
	string st = queBox<string>("输入管理员ID:", 2);
	string password = queBox<string>("输入管理员密码:", 2);
	if (admin.checkPassword(st, password)){
			printf("*******登陆成功!*******\n");
			wait();
			adminPanel();
		}
	else{ printf("用户名或密码错误!\n"); wait(); cmdUi(); }
}

void UI::cls()
{
	system("cls");
}

void UI::wait(){
	char ch;
	while (_kbhit()){ ch = _getch(); }
	printf("\n*********任意键继续********\n");
	while (!_kbhit()){}
	ch = _getch();
	cls();
}

void UI::adminPanel()
{
	while (1){
		printf("1.注销登录 2.录入课程信息 3.查看全部课程信息 4.增加课程 5.删除课程 6.修改课程 7.查看具体课程\n");
		int tmp = queBox<int>("请选择所需的功能:", 1);
		switch (tmp){
		case 1:
			dataCourse.writeToFile();
			dataStuAll.writeToFile();
			dataAssi.writeToFile();
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
		if (tmp == 1) break;
	}
	wait();
	cmdUi();
}

void UI::stuPanel(string name)
{
	stu.setpath(name);
	while (1){
		stu_checkAssistError();
		printf("1.注销登录 2.查看课程信息 3.选课 4.查看个人课表 5.退课 6.举手报名助教7.选择个人助教\n");
		int tmp = queBox<int>("请选择所需的功能:", 1);
		switch (tmp){
		case 1:
			dataStuX.writeToFile();
			dataCourse.writeToFile();
			dataStuAll.writeToFile();
			dataAssi.writeToFile();
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
		if (tmp == 1) break;
	}
	wait();
	cmdUi();
}

void UI::viewAllCourse()
{
	printf("课程ID\t课程名称\t授课教师\t上限人数\t目前已选\t课程类型\n");
	vector<string>& CourseList = admin.getCourseList();
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
		printCourse(to_string(tmp.CourseId));
		printf("还希望进行以下哪项操作: 1.查看选课学生名单 2.查看课程报名助教名单");
		int opt = queBox<int>("输入操作编号:", 1);
		if (opt == 1){
			viewStu(curCourse.CourseId);
		}
		else if (opt == 2){
			printAssist(curCourse.CourseId);
		}
		else printf("无效操作！\n");
	}
}

void UI::viewStu(int courseId)
{
	courseStuNode a = admin.getCourseStuList(courseId);
	if (a.list.empty()) printf("此课程暂无学生选择!");
	else{
		printf("选择该课程的学生有:");
		cout << a.list[0];
		For(i, 1, int(a.list.size()) - 1){
			cout << "," << a.list[i];
		}
		cout << endl;
		CourseNode curCourse = admin.getCourse(CourseNode(courseId));
		printf("共计%d名学生，距离满课还差%d人\n", curCourse.CourseSel, curCourse.CourseCap - curCourse.CourseSel);
	}
}

void UI::printCourse(string CourseId){
	//cout << CourseId << endl;
	string id = str_toStringId(atoi(CourseId));
	cout << id << "\t" << pCourse.query(CourseId, 1)[0] << "\t" << pCourse.query(CourseId, 2)[0] << "\t" << pCourse.query(CourseId, 3)[0] << "\t" << pCourse.query(CourseId, 4)[0] << "\t";
	cout << pCourse.query(CourseId, 5)[0] << endl;
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
		printf("删除成功!\n");
		viewAllCourse();
	}
	else if (tmp1 == 1){
		printf("课程删除失败！无此课程!\n");
	}
	else if (tmp1 == 2){
		printf("课程删除失败，目前已有学生选此课!\n");
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

void UI::stu_checkAssistError()
{
	if (stu.isAssistError()){
		vector<string> a = stu.getAssistError();
		printf("注意！你选择的一下课程的助教退出了该课程，请重新选择助教!\n");
		printf("课程ID:");
		cout << a[0];
		For(i, 1, int(a.size()) - 1){
			cout << "," << a[i];
		}
		cout << endl;
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
	vector<string>& a = stu.getStuCourseList();
	printf("课程ID\t课程名称\t授课教师\t上限人数\t目前已选\t课程类型\n");
	For(i, 0, int(a.size()) - 1){
		printCourse(a[i]);
	}
	pair<int, int> sum = stu.getProAndNonePro();
	if (sum.first == 0 && sum.second == 0) printf("选课已经达到要求!\n");
	else{
		printf("根据学院要求，目前所选课程数不达标!");
		if (sum.first != 0) printf("差%d门专业课，", sum.first);
		if (sum.second != 0) printf("差%d门非业课，", sum.second);
		printf("请及时选课!\n");
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
	else printf("删除失败!该课程不在个人课表中!\n");
}

void UI::printAssist(vector<string>& list)
{
	printf("该课程助教有:");
	cout << list[0];
	For(i, 1, int(list.size()) - 1) cout << "," << list[i];
	cout << endl;
}

bool UI::printAssist(int id){
	int tmp = stu.isCourseAssistExsist(assistNode(id));
	if (!tmp){
		printf("该课程暂无助教!\n");
		return 1;
	}
	else{
		printAssist(stu.getAssistNode(assistNode(id)));
		return 0;
	}
}
void UI::stu_selAssistant()
{
	int id = queBox<int>("输入课程id:", 1);
	int tmp2 = stu.isCourseAssistHaveChosen(assistNode(id, stu.userName));
	if (tmp2 == 1) printf("该课程已经选过助教！");
	else{
		if (tmp2 == 2) printf("个人课表中无这门课！");
		else{
			if (printAssist(id));
			else{
				string st = queBox<string>("输入助教名称:", 2);
				int tmp2 = stu.addAssistant(assistNode(id), st);
				if (tmp2 == 0){
					printf("已选择该助教!\n");
				}
				if (tmp2 == 1) printf("无此助教!\n");
				if (tmp2 == 2) printf("不可以选择自己作助教!\n");
			}
		}
	}
}

void UI::stu_addAssistant()
{
	int id = queBox<int>("输入课程id:", 1);
	int tmp = stu.beAssistant(assistNode(id, stu.userName));
	if (tmp == 0) printf("报名成功!\n");
	if (tmp == 1) printf("报名失败，重复报名！\n");
	if (tmp == 2) printf("报名失败，已经有两门课程当助教!\n");
	if (tmp == 3) printf("报名失败，你没有选择此门课程!");
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