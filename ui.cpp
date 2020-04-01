#include"ui.h"
#include"diag.h"
#include"agori.h"
#include<conio.h>
void UI::begin(){
	system("mode con cols=150 lines=30");
	cls();
	printf("ѧ��ѡ��ϵͳV1.1\npowered by Shbing\n");
	wait();
	printf("ѧ��ѡ��ϵͳ����ָ�ϣ�\n");
	printf("1.�밴����ʾ���룬���س�ȷ��\n");
	printf("2.�������κζ���ֱ�Ӱ��س���ֱ���˳�ѡ��\n");
	printf("3.���鲻Ҫֱ�ӹرմ���\n");
	wait();
	cmdUi();
	cls();
	printf("�ټ�!\n");
}
void UI::cmdUi(){

	while (1){
		printf("1.ѧ����¼	2.ѧ��ע��	3.����Ա��¼		4.�ر�\n");
		int opt = queBoxInt("�������:");
		
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
	string name = queBoxStr("����ѧ��ID:");
	Password pass;
	pass.inputPassword("����ѧ������:");
	string password = pass.getPassword();
	cout << endl;
	if (stu.checkpassword(name, password)){
		printf("*******��½�ɹ�!*******\n");
		wait();
		stuPanel(name);
	}
	else {
		printf("�û������������\n");
		wait();
	}
}

void UI::stuReg()
{
	cls();
	string name = queBoxStr("����ѧ��ID:");
	if (stu.isStuWordInList(stuWordNode(name))){
		printf("��ID�Ѿ�ע�ᣡ\n");
		wait();
	}
	else{
		string password = queBoxStr("����ѧ������:");
		stu.addStuWord(name, password);
		printf("*********ע��ɹ�,��¼�ɹ���*******\n");
		wait();
		stuPanel(name);
	}
}

void UI::adminLogIn()
{
	cls();
	string st = queBoxStr("�������ԱID:", 1);
	Password pass;
	pass.inputPassword("�������Ա����:");
	string password = pass.getPassword();
	cout << endl;
	if (admin.checkPassword(st, password)){
			printf("*******��½�ɹ�!*******\n");
			wait();
			adminPanel();
		}
	else{ printf("�û������������!\n"); wait();}
}

void UI::cls()
{
	system("cls");
}

void UI::wait(){
	char ch;
	while (_kbhit()){ ch = _getch(); }
	printf("\n*********���������********\n");
	while (!_kbhit()){}
	ch = _getch();
	cls();
}

void UI::adminPanel()
{
	cls();
	while (1){
		printf("1.ע����¼ 2.¼��γ���Ϣ 3.�鿴ȫ���γ���Ϣ 4.���ӿγ� 5.ɾ���γ� 6.�޸Ŀγ� 7.�鿴����γ�\n");
		int tmp = queBoxInt("��ѡ������Ĺ���:");
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
		printf("1.ע����¼ 2.�鿴�γ���Ϣ 3.ѡ�� 4.�鿴���˿α� 5.�˿� 6.���ֱ�������7.ѡ���������\n");
		int tmp = queBoxInt("��ѡ������Ĺ���:");
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
	printf("ȫ���γ�����:\n");
	printLine();
	print("�γ�ID", 10);
	print("�γ�����");
	print("�ڿν�ʦ", 20);
	print("��������", 10);
	print("Ŀǰ��ѡ", 10);
	print("�γ�����", 10);
	cout << endl;
	vector<string>& CourseList = admin.getCourseList();
	For(i, 0, int(CourseList.size()) - 1) printCourse(CourseList[i]);
	printLine();
}

void UI::viewCourse()
{
	while (1){
		viewAllCourse();
		string st = queBoxStr("������Ҫ�鿴�Ŀγ�ID������:");
		if (st.length() == 0) return;
		CourseNode curCourse;
		if (str_isNum(st)) curCourse.CourseId = stoi(st);
		else curCourse.CourseName = st;
		if (!admin.isCourseInList(curCourse)){
			printf("�޴˿γ̣�");
			wait();
		}
		else{
			CourseNode tmp = admin.getCourse(curCourse);
			print("�γ�ID", 10);
			print("�γ�����");
			print("�ڿν�ʦ", 20);
			print("��������", 10);
			print("Ŀǰ��ѡ", 10);
			print("�γ�����", 10);
			cout << endl;
			printCourse(to_string(tmp.CourseId));
			printf("\n��ϣ�����������������: 1.�鿴ѡ��ѧ������ 2.�鿴�γ̱�����������\n");
			int opt = queBoxInt("����������:");
			if (opt == -1) return;
			if (opt == 1){
				viewStu(curCourse.CourseId);
				break;
			}
			else if (opt == 2){
				printAssist(curCourse.CourseId);
				break;
			}
			else { printf("��Ч������\n"); wait(); }
		}
	}
}

void UI::viewStu(int courseId)
{
	courseStuNode a = admin.getCourseStuList(courseId);
	if (a.list.empty()) printf("�˿γ�����ѧ��ѡ��!");
	else{
		printf("ѡ��ÿγ̵�ѧ����:");
		cout << a.list[0];
		For(i, 1, int(a.list.size()) - 1){
			cout << "," << a.list[i];
		}
		cout << endl;
		CourseNode curCourse = admin.getCourse(CourseNode(courseId));
		printf("����%d��ѧ�����������λ���%d��\n", curCourse.CourseSel, curCourse.CourseCap - curCourse.CourseSel);
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
	if (assist == "Null") printf("��\t\t");
	else if (assist == "Wait")
		printf("����ѡ\t\t");
	else cout << assist << "\t\t";
	if (pAssistMem.queryHasKey(CourseId + stu.userName)){
		vector<string> memlist = pAssistMem.query(CourseId + stu.userName, 1);
		if (memlist.empty()) printf("��\n");
		else{
			cout << memlist[0];
			For(i, 1, int(memlist.size()) - 1) cout << "," << memlist[i];
			cout << endl;
		}
	}
	else printf("����������\n");

}

void UI::admin_addCourse()
{
	while (1){
		string st = queBoxStr("����γ̾�����Ϣ:(�γ�����,�ڿν���,��������,��ѡ����,�γ�����):");
		vector<string> a = str_Split(st, ',');
		if (a.empty()) return;
		if (a.size() != 5){
			printf("�Ƿ�����!\n");
			wait();
			continue;
		}
		CourseNode tmp = CourseNode(a[0], a[1], stoi(a[2]), stoi(a[3]), a[4]);
		int state = admin.addCourse(tmp);//��ӿγ�
		if (state == 1){
			printf("���ʧ�ܣ��γ��Ѿ����б���!\n");
			wait();
		}
		else{
			printf("��ӳɹ���\n");
			wait();
			viewAllCourse();
			break;
		}
	}
}

void UI::admin_delCourse()
{
	viewAllCourse();
	int tmp = queBoxInt("\n����γ̱��:");
	if (tmp == -1) return;
	int tmp1 = admin.delCourse(tmp);
	if (tmp1 == 0){
		printf("ɾ���ɹ�!\n");
		wait();
		viewAllCourse();
	}
	else if (tmp1 == 1){
		printf("�γ�ɾ��ʧ�ܣ��޴˿γ�!\n");
	}
	else if (tmp1 == 2){
		printf("�γ�ɾ��ʧ�ܣ�Ŀǰ����ѧ��ѡ�˿�!\n");
	}
}

void UI::admin_editCourse()
{
	while (1){
		viewAllCourse();
		int id = queBoxInt("\n������Ҫ�޸ĵ�id:");
		if (id == -1) return;
		if (!admin.isCourseInList(CourseNode(id))){
			{printf("�޸�ʧ�ܣ��޴˿γ̣�"); wait(); }
		}
		else{
			int tmp = queBoxInt("������Ҫ�޸ĵ��ֶ�(1.�ον�ʦ  2.��������): ");
			if (tmp == -1) return;
			if (tmp == 1){
				string st = queBoxStr("�޸Ľ�ʦ����Ϊ:");
				if (st.length() == 0) return;

				CourseNode tmpCourse;
				tmpCourse.CourseTeacher = st;
				tmpCourse.CourseId = id;
				int tmp1 = admin.editCourse(tmpCourse);
				if (!tmp1){
					printf("�޸ĳɹ���\n");
					wait();
					viewAllCourse();
					break;
				}
				else { printf("�޸�ʧ�ܣ�\n"); wait(); }
			}
			else{
				if (tmp == 2){
					int cap = queBoxInt("�޸���������Ϊ:");
					if (cap == -1) return;
					CourseNode tmpCourse;
					tmpCourse.CourseCap = cap;
					tmpCourse.CourseId = id;
					int tmp1 = admin.editCourse(tmpCourse);
					if (!tmp1){
						printf("�޸ĳɹ���\n");
						wait();
						viewAllCourse();
						break;
					}
					else {
						printf("�޸�ʧ�ܣ���Ϊ�޸ĺ������С��Ŀǰ��ѡ����\n"); wait();
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
		printf("ע�⣡��ѡ������¿γ̵������˳��˸ÿγ̣�������ѡ������!\n");
		printf("�γ�ID:");
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
	vector<string> id = queBoxStrList("����ѡ��γ̵�id�����Զ�ѡ���ո������:");
	if (id.empty()) return;
	For(i, 0, int(id.size()) - 1){
		cout << "�γ�" << str_toStringId(atoi(id[i]))<<" ";
		int tmp = stu.addCourse(CourseNode(atoi(id[i])));
		if (tmp == 0) printf("�Ѿ���ӵ����˿α���!\n");
		else if (tmp == 1)printf("���ʧ�ܣ��ÿγ��Ѿ��ڸ��˿α���!\n");
		else if (tmp == 2) printf("���ʧ�ܣ��ÿγ�����!\n");
		else if (tmp == 3) printf("���ʧ�ܣ��޴˿γ�!\n");
		else if (tmp == 4) printf("���ʧ�ܣ�ѡ���Ѿ��ﵽ���ֵ10��\n");
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
	printf("���˿α�����:\n");
	printLine();
	vector<string>& a = stu.getStuCourseList();
	print("�γ�ID", 10);
	print("�γ�����");
	print("�ڿν�ʦ", 20);
	print("�γ�����", 20);
	printf("��������\t�Լ��������̵�С���Ա\n");
	For(i, 0, int(a.size()) - 1){
		printCoursePart(a[i]);
	}
	pair<int, int> sum = stu.getProAndNonePro();
	printLine();
	if (sum.first == 0 && sum.second == 0) printf("ѡ���Ѿ��ﵽҪ��!\n");
	else{
		printf("����ѧԺҪ��Ŀǰ��ѡ�γ��������!");
		if (sum.first != 0) printf("��%d��רҵ�Σ�", sum.first);
		if (sum.second != 0) printf("��%d�ŷ�ҵ�Σ�", sum.second);
		printf("�뼰ʱѡ��!\n");
	}
}

void UI::stu_viewNotChooseCourse()
{
	printf("��ǰδѡ�Ŀγ���:\n");
	printLine();
	print("�γ�ID", 10);
	print("�γ�����");
	print("�ڿν�ʦ", 20);
	print("��������", 10);
	print("Ŀǰ��ѡ", 10);
	print("�γ�����", 10);
	cout << endl;
	vector<string>& CourseList = admin.getCourseList();
	For(i, 0, int(CourseList.size()) - 1){
		if (!pStuCourse.queryHasKey(CourseList[i])) printCourse(CourseList[i]);
	}
	printLine();
}

void UI::stu_viewAssistantCourse()
{
	printf("����ѡ�����̵Ŀγ�����:\n");
	printLine();
	vector<string>& a = stu.getStuCourseList();
	print("�γ�ID", 10);
	print("�γ�����");
	print("��ѡ��������");
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
	printf("��ǰ��ѡ�Ŀ���:\n\n");
	stu_viewAllCourse();
	printf("\nɾ���γ�:\n");
	vector<string> id = queBoxStrList("����γ�id�����Զ�ѡ���ո������:");
	if (id.empty()) return;
	For(i, 0, int(id.size()) - 1){
		cout << "�γ�" << str_toStringId(atoi(id[i])) << " ";
		int tmp = stu.delCourse(CourseNode(atoi(id[i])));
		if (tmp == 0){
			printf("ɾ���ɹ�!\n");
		}
		else printf("ɾ��ʧ��!�ÿγ̲��ڸ��˿α���!\n");
	}
	wait();
	stu_viewAllCourse();
}

void UI::printAssist(vector<string>& list)
{
	printf("�ÿγ�������:");
	cout << list[0];
	For(i, 1, int(list.size()) - 1) cout << "," << list[i];
	cout << endl;
}

bool UI::printAssist(int id){
	int tmp = stu.isCourseAssistExsist(assistNode(id));
	if (!tmp){
		printf("�ÿγ���������!\n");
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
	int id = queBoxInt("����γ�id:");
	if (id == -1) return;
	int tmp2 = stu.isCourseAssistHaveChosen(assistNode(id, stu.userName));
	if (tmp2 == 1) printf("�ÿγ��Ѿ�ѡ�����̣�");
	else{
		if (tmp2 == 2) printf("���˿α��������ſΣ�");
		else{
			if (printAssist(id));
			else{
				string st = queBoxStr("������������:");
				int tmp2 = stu.addAssistant(assistNode(id), st);
				if (tmp2 == 0){
					printf("��ѡ�������!\n");
				}
				if (tmp2 == 1) printf("�޴�����!\n");
				if (tmp2 == 2) printf("������ѡ���Լ�������!\n");
			}
		}
	}
}

void UI::stu_addAssistant()
{
	stu_viewAllCourse();
	int id = queBoxInt("����γ�id:");
	if (id == -1) return;
	int tmp = stu.beAssistant(assistNode(id, stu.userName));
	if (tmp == 0) printf("�����ɹ�!\n");
	if (tmp == 1) printf("����ʧ�ܣ��ظ�������\n");
	if (tmp == 2) printf("����ʧ�ܣ��Ѿ������ſγ̵�����!\n");
	if (tmp == 3) printf("����ʧ�ܣ���û��ѡ����ſγ�!");
}

string UI::queBoxStr(string st, int opt)
{
	cout << st;
	string tmp;
	getline(cin, tmp);
	while (tmp.find(' ', 0) != -1 && (!opt)){
		printf("����Ƿ�!\n");
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
		if (f) cout << "����Ƿ���" << endl;
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
		printf("����Ƿ�!\n");
		cout << st;
		getline(cin, tmp);
	}
	if (tmp.length() == 0) return -1;
	else return atoi(tmp);
}

void UI::admin_addCourseFromFile()
{
	string path = queBoxStr("��������Ҫ������ļ�����:");
	if (path.length() == 0) return;
	int tmp = admin.addStuFromFile(path);
	if (tmp == 0) printf("����ɹ���\n");
	else if (tmp == 1) printf("����ʧ�ܣ��ļ��޷��򿪣�\n");
	else if (tmp == 2) printf("����ʧ�ܣ������ֳ��ļ�������\n");
}