#include"ui.h"
#include"diag.h"
#include"agori.h"
#include<conio.h>
void UI::begin(){
	system("mode con cols=150 lines=30");
	cls();
	printf("学生选课系统V1.1\npowered by Shbing\n");
	wait();
	printf("学生选课系统操作指南：\n");
	printf("1.请按照提示输入，按回车确认\n");
	printf("2.不输入任何东西直接按回车可直接退出选项\n");
	printf("3.建议不要直接关闭窗口\n");
	wait();
	cmdUi();
	cls();
	printf("再见!\n");
}
void UI::cmdUi(){

	while (1){
		printf("1.学生登录	2.学生注册	3.管理员登录		4.关闭\n");
		int opt = queBoxInt("输入操作:");
		
		switch (opt){
		case 1:
			stuLogIn();
			break;
		case 2:
			stuReg();
			break;
		case 3:
			adminLogIn();
			break;
		case 4:
			return;
		default:
			cls();
		}
		//wait();
	}
}

void UI::stuLogIn()
{
	cls();
	string name = queBoxStr("输入学生ID:");
	Password pass;
	pass.inputPassword("输入学生密码:");
	string password = pass.getPassword();
	cout << endl;
	if (stu.checkpassword(name, password)){
		printf("*******登陆成功!*******\n");
		wait();
		stuPanel(name);
	}
	else {
		printf("用户名或密码错误！\n");
		wait();
	}
}

void UI::stuReg()
{
	cls();
	string name = queBoxStr("输入学生ID:");
	if (stu.isStuWordInList(stuWordNode(name))){
		printf("此ID已经注册！\n");
		wait();
	}
	else{
		string password = queBoxStr("输入学生密码:");
		stu.addStuWord(name, password);
		printf("*********注册成功,登录成功！*******\n");
		wait();
		stuPanel(name);
	}
}

void UI::adminLogIn()
{
	cls();
	string st = queBoxStr("输入管理员ID:", 1);
	Password pass;
	pass.inputPassword("输入管理员密码:");
	string password = pass.getPassword();
	cout << endl;
	if (admin.checkPassword(st, password)){
			printf("*******登陆成功!*******\n");
			wait();
			adminPanel();
		}
	else{ printf("用户名或密码错误!\n"); wait();}
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
	cls();
	while (1){
		printf("1.注销登录 2.录入课程信息 3.查看全部课程信息 4.增加课程 5.删除课程 6.修改课程 7.查看具体课程\n");
		int tmp = queBoxInt("请选择所需的功能:");
		switch (tmp){
		case 1:
			admin.close();
			break;
		case 2:
			admin_addCourseFromFile();
			wait();
			break;
		case 3:
			viewAllCourse();
			wait();
			break;
		case 4:
			admin_addCourse();
			wait();
			break;
		case 5:
			admin_delCourse();
			wait();
			break;
		case 6:
			admin_editCourse();
			wait();
			break;
		case 7:
			viewCourse();
			wait();
			break;
		default:
			cls();
		}
		if (tmp == 1) break;
	}
	wait();
	//cmdUi();
}

void UI::stuPanel(string name)
{
	cls();
	stu.setpath(name);
	while (1){
		stu_checkAssistError();
		printf("1.注销登录 2.查看课程信息 3.选课 4.查看个人课表 5.退课 6.举手报名助教7.选择个人助教\n");
		int tmp = queBoxInt("请选择所需的功能:");
		switch (tmp){
		case 1:
			stu.close();
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
		default:
			cls();
		}
		if (tmp == 1) break;
		wait();
	}
	wait();
}

void UI::viewAllCourse()
{
	printf("全部课程如下:\n");
	printLine();
	print("课程ID", 10);
	print("课程名称");
	print("授课教师", 20);
	print("上限人数", 10);
	print("目前已选", 10);
	print("课程类型", 10);
	cout << endl;
	vector<string>& CourseList = admin.getCourseList();
	For(i, 0, int(CourseList.size()) - 1) printCourse(CourseList[i]);
	printLine();
}

void UI::viewCourse()
{
	while (1){
		viewAllCourse();
		string st = queBoxStr("输入需要查看的课程ID或名称:");
		if (st.length() == 0) return;
		CourseNode curCourse;
		if (str_isNum(st)) curCourse.CourseId = stoi(st);
		else curCourse.CourseName = st;
		if (!admin.isCourseInList(curCourse)){
			printf("无此课程！");
			wait();
		}
		else{
			CourseNode tmp = admin.getCourse(curCourse);
			print("课程ID", 10);
			print("课程名称");
			print("授课教师", 20);
			print("上限人数", 10);
			print("目前已选", 10);
			print("课程类型", 10);
			cout << endl;
			printCourse(to_string(tmp.CourseId));
			printf("\n还希望进行以下哪项操作: 1.查看选课学生名单 2.查看课程报名助教名单\n");
			int opt = queBoxInt("输入操作编号:");
			if (opt == -1) return;
			if (opt == 1){
				viewStu(curCourse.CourseId);
				break;
			}
			else if (opt == 2){
				printAssist(curCourse.CourseId);
				break;
			}
			else { printf("无效操作！\n"); wait(); }
		}
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

void UI::print(string st, int n1){
	if (str_isNum(st)) n1 = 10;
	int n = st.length();
	cout << st;
	For(i, 1, n1 - n) cout << " ";
}
void UI::printCourse(string CourseId){
	//cout << CourseId << endl;
	string id = str_toStringId(atoi(CourseId));
	//cout << id << "\t" << pCourse.query(CourseId, 1)[0] << "\t" <<"\t\t"<< pCourse.query(CourseId, 2)[0] << "\t" << pCourse.query(CourseId, 3)[0] << "\t" << pCourse.query(CourseId, 4)[0] << "\t";
	print(id);
	print(pCourse.query(CourseId, 1)[0]);
	print(pCourse.query(CourseId, 2)[0], 20);
	print(pCourse.query(CourseId, 3)[0]);
	print(pCourse.query(CourseId, 4)[0]);
	print(pCourse.query(CourseId, 5)[0]);
	cout << endl;
	//cout << pCourse.query(CourseId, 5)[0] << endl;
}

void UI::printCoursePart(string CourseId)
{
	string id = str_toStringId(atoi(CourseId));
	print(id);
	print(pCourse.query(CourseId, 1)[0]);
	print(pCourse.query(CourseId, 2)[0], 20);
	print(pCourse.query(CourseId, 5)[0], 20);
	//cout << id << "\t" << pCourse.query(CourseId, 1)[0] << "\t\t" << pCourse.query(CourseId, 2)[0] << "\t" << pCourse.query(CourseId, 5)[0]<<"\t";
	string assist = pStuCourse.query(CourseId, 1)[0];
	if (assist == "Null") printf("无\t\t");
	else if (assist == "Wait")
		printf("待重选\t\t");
	else cout << assist << "\t\t";
	if (pAssistMem.queryHasKey(CourseId + stu.userName)){
		vector<string> memlist = pAssistMem.query(CourseId + stu.userName, 1);
		if (memlist.empty()) printf("无\n");
		else{
			cout << memlist[0];
			For(i, 1, int(memlist.size()) - 1) cout << "," << memlist[i];
			cout << endl;
		}
	}
	else printf("不担任助教\n");

}

void UI::admin_addCourse()
{
	while (1){
		string st = queBoxStr("输入课程具体信息:(课程名称,授课教授,容纳人数,已选人数,课程类型):");
		vector<string> a = str_Split(st, ',');
		if (a.empty()) return;
		if (a.size() != 5){
			printf("非法输入!\n");
			wait();
			continue;
		}
		CourseNode tmp = CourseNode(a[0], a[1], stoi(a[2]), stoi(a[3]), a[4]);
		int state = admin.addCourse(tmp);//添加课程
		if (state == 1){
			printf("添加失败！课程已经在列表中!\n");
			wait();
		}
		else{
			printf("添加成功！\n");
			wait();
			viewAllCourse();
			break;
		}
	}
}

void UI::admin_delCourse()
{
	viewAllCourse();
	int tmp = queBoxInt("\n输入课程编号:");
	if (tmp == -1) return;
	int tmp1 = admin.delCourse(tmp);
	if (tmp1 == 0){
		printf("删除成功!\n");
		wait();
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
	while (1){
		viewAllCourse();
		int id = queBoxInt("\n输入需要修改的id:");
		if (id == -1) return;
		if (!admin.isCourseInList(CourseNode(id))){
			{printf("修改失败！无此课程！"); wait(); }
		}
		else{
			int tmp = queBoxInt("输入需要修改的字段(1.任课教师  2.容纳人数): ");
			if (tmp == -1) return;
			if (tmp == 1){
				string st = queBoxStr("修改教师名称为:");
				if (st.length() == 0) return;

				CourseNode tmpCourse;
				tmpCourse.CourseTeacher = st;
				tmpCourse.CourseId = id;
				int tmp1 = admin.editCourse(tmpCourse);
				if (!tmp1){
					printf("修改成功！\n");
					wait();
					viewAllCourse();
					break;
				}
				else { printf("修改失败！\n"); wait(); }
			}
			else{
				if (tmp == 2){
					int cap = queBoxInt("修改容纳人数为:");
					if (cap == -1) return;
					CourseNode tmpCourse;
					tmpCourse.CourseCap = cap;
					tmpCourse.CourseId = id;
					int tmp1 = admin.editCourse(tmpCourse);
					if (!tmp1){
						printf("修改成功！\n");
						wait();
						viewAllCourse();
						break;
					}
					else {
						printf("修改失败！因为修改后的人数小于目前已选人数\n"); wait();
					}
				}
			}
		}
	}
}

void UI::stu_checkAssistError()
{
	if (stu.isAssistError()){
		vector<string> a = stu.getAssistError();
		printf("注意！你选择的以下课程的助教退出了该课程，请重新选择助教!\n");
		printf("课程ID:");
		cout << str_toStringId(atoi(a[0]));
		For(i, 1, int(a.size()) - 1){
			cout << "," << str_toStringId(atoi(a[i]));
		}
		cout << endl;
	}
}

void UI::stu_addCourse()
{
	stu_viewNotChooseCourse();
	vector<string> id = queBoxStrList("输入选择课程的id（可以多选，空格隔开）:");
	if (id.empty()) return;
	For(i, 0, int(id.size()) - 1){
		cout << "课程" << str_toStringId(atoi(id[i]))<<" ";
		int tmp = stu.addCourse(CourseNode(atoi(id[i])));
		if (tmp == 0) printf("已经添加到个人课表中!\n");
		else if (tmp == 1)printf("添加失败！该课程已经在个人课表中!\n");
		else if (tmp == 2) printf("添加失败！该课程已满!\n");
		else if (tmp == 3) printf("添加失败！无此课程!\n");
		else if (tmp == 4) printf("添加失败！选课已经达到最大值10门\n");
	}
	wait();
	stu_viewAllCourse();
}

void UI::printLine(){
	For(i, 1, 100) printf("*");
	cout << endl;
}
void UI::stu_viewAllCourse()
{
	printf("个人课表如下:\n");
	printLine();
	vector<string>& a = stu.getStuCourseList();
	print("课程ID", 10);
	print("课程名称");
	print("授课教师", 20);
	print("课程类型", 20);
	printf("个人助教\t自己担任助教的小组成员\n");
	For(i, 0, int(a.size()) - 1){
		printCoursePart(a[i]);
	}
	pair<int, int> sum = stu.getProAndNonePro();
	printLine();
	if (sum.first == 0 && sum.second == 0) printf("选课已经达到要求!\n");
	else{
		printf("根据学院要求，目前所选课程数不达标!");
		if (sum.first != 0) printf("差%d门专业课，", sum.first);
		if (sum.second != 0) printf("差%d门非业课，", sum.second);
		printf("请及时选课!\n");
	}
}

void UI::stu_viewNotChooseCourse()
{
	printf("当前未选的课程有:\n");
	printLine();
	print("课程ID", 10);
	print("课程名称");
	print("授课教师", 20);
	print("上限人数", 10);
	print("目前已选", 10);
	print("课程类型", 10);
	cout << endl;
	vector<string>& CourseList = admin.getCourseList();
	For(i, 0, int(CourseList.size()) - 1){
		if (!pStuCourse.queryHasKey(CourseList[i])) printCourse(CourseList[i]);
	}
	printLine();
}

void UI::stu_viewAssistantCourse()
{
	printf("可以选择助教的课程如下:\n");
	printLine();
	vector<string>& a = stu.getStuCourseList();
	print("课程ID", 10);
	print("课程名称");
	print("可选助教名单");
	cout << endl;
	For(i, 0, int(a.size()) - 1){
		if (pStuCourse.queryHas(a[i], 1, "Null") || pStuCourse.queryHas(a[i], 1, "Wait")){
			vector<string>& b = pCourse.query(a[i], 7);
			if (!b.empty()){
				print(str_toStringId(atoi(a[i])), 10);
				print(pCourse.query(a[i], 1)[0]);
				For(j, 0, int(b.size()) - 1){
					cout << b[j] << " ";
				}
				cout << endl;
			}
		}
	}
	printLine();
}

void UI::stu_delCourse()
{
	printf("当前已选的课有:\n\n");
	stu_viewAllCourse();
	printf("\n删除课程:\n");
	vector<string> id = queBoxStrList("输入课程id（可以多选，空格隔开）:");
	if (id.empty()) return;
	For(i, 0, int(id.size()) - 1){
		cout << "课程" << str_toStringId(atoi(id[i])) << " ";
		int tmp = stu.delCourse(CourseNode(atoi(id[i])));
		if (tmp == 0){
			printf("删除成功!\n");
		}
		else printf("删除失败!该课程不在个人课表中!\n");
	}
	wait();
	stu_viewAllCourse();
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
	stu_viewAssistantCourse();
	int id = queBoxInt("输入课程id:");
	if (id == -1) return;
	int tmp2 = stu.isCourseAssistHaveChosen(assistNode(id, stu.userName));
	if (tmp2 == 1) printf("该课程已经选过助教！");
	else{
		if (tmp2 == 2) printf("个人课表中无这门课！");
		else{
			if (printAssist(id));
			else{
				string st = queBoxStr("输入助教名称:");
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
	stu_viewAllCourse();
	int id = queBoxInt("输入课程id:");
	if (id == -1) return;
	int tmp = stu.beAssistant(assistNode(id, stu.userName));
	if (tmp == 0) printf("报名成功!\n");
	if (tmp == 1) printf("报名失败，重复报名！\n");
	if (tmp == 2) printf("报名失败，已经有两门课程当助教!\n");
	if (tmp == 3) printf("报名失败，你没有选择此门课程!");
}

string UI::queBoxStr(string st, int opt)
{
	cout << st;
	string tmp;
	getline(cin, tmp);
	while (tmp.find(' ', 0) != -1 && (!opt)){
		printf("输入非法!\n");
		cout << st;
		getline(cin, tmp);
	}
	return tmp;
}

vector<string> UI::queBoxStrList(string st, char ch)
{
	bool f = 0;
	while (!f){
		cout << st;
		string tmp;
		getline(cin, tmp);
		vector<string> a = str_Split(tmp, ch);
		For(i, 0, int(a.size()) - 1){
			if (!str_isNum(a[i])){
				f = 1; 
				break;
			}
		}
		if (f) cout << "输入非法！" << endl;
		else return a;
		f = !f;
	}
}

int UI::queBoxInt(string st)
{
	cout << st;
	string tmp;
	getline(cin, tmp);
	while(atoi(tmp) == -1){
		printf("输入非法!\n");
		cout << st;
		getline(cin, tmp);
	}
	if (tmp.length() == 0) return -1;
	else return atoi(tmp);
}

void UI::admin_addCourseFromFile()
{
	string path = queBoxStr("请输入需要导入的文件名称:");
	if (path.length() == 0) return;
	int tmp = admin.addStuFromFile(path);
	if (tmp == 0) printf("导入成功！\n");
	else if (tmp == 1) printf("导入失败！文件无法打开！\n");
	else if (tmp == 2) printf("导入失败！已有现成文件名单！\n");
}