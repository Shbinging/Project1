#include"ui.h"
#include"diag.h"
#include"agori.h"
#include<conio.h>
void UI::cmdUi(){
	while (1){
		printf("1.ѧ����¼	2.ѧ��ע��	3.����Ա��¼		4.�ر�\n");
		printf("�������:");

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
	string name = queBox<string>("����ѧ��ID:", 2);
	string password = queBox<string>("����ѧ������:", 2);
	if (stu.checkpassword(name, password)){
		printf("*******��½�ɹ�!*******\n");
		wait();
		stuPanel(name);
	}
	else printf("�û������������\n");
	wait();
	cmdUi();

}

void UI::stuReg()
{
	string name = queBox<string>("����ѧ��ID:", 2);
	if (stu.isStuWordInList(stuWordNode(name))){
		printf("��ID�Ѿ�ע�ᣡ\n");
		wait();
		cmdUi();
	}
	else{
		string password = queBox<string>("����ѧ������:", 2);
		stu.addStuWord(name, password);
		printf("*********ע��ɹ�,��¼�ɹ���*******\n");
		wait();
		stuPanel(name);
	}
}

void UI::adminLogIn()
{
	string st = queBox<string>("�������ԱID:", 2);
	string password = queBox<string>("�������Ա����:", 2);
	if (admin.checkPassword(st, password)){
			printf("*******��½�ɹ�!*******\n");
			wait();
			adminPanel();
		}
	else{ printf("�û������������!\n"); wait(); cmdUi(); }
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
	while (1){
		printf("1.ע����¼ 2.¼��γ���Ϣ 3.�鿴ȫ���γ���Ϣ 4.���ӿγ� 5.ɾ���γ� 6.�޸Ŀγ� 7.�鿴����γ�\n");
		int tmp = queBox<int>("��ѡ������Ĺ���:", 1);
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
		printf("1.ע����¼ 2.�鿴�γ���Ϣ 3.ѡ�� 4.�鿴���˿α� 5.�˿� 6.���ֱ�������7.ѡ���������\n");
		int tmp = queBox<int>("��ѡ������Ĺ���:", 1);
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
	printf("�γ�ID\t�γ�����\t�ڿν�ʦ\t��������\tĿǰ��ѡ\t�γ�����\n");
	vector<string>& CourseList = admin.getCourseList();
	For(i, 0, int(CourseList.size()) - 1) printCourse(CourseList[i]);
}

void UI::viewCourse()
{
	string st = queBox<string>("������Ҫ�鿴�Ŀγ�ID������:", 2);
	CourseNode curCourse;
	if (str_isNum(st)) curCourse.CourseId = stoi(st);
	else curCourse.CourseName = st;
	if (!admin.isCourseInList(curCourse)){
		printf("�޴˿γ̣�");
	}
	else{
		CourseNode tmp = admin.getCourse(curCourse);
		printf("�γ�ID\t�γ�����\t�ڿν�ʦ\t��������\tĿǰ��ѡ\t�γ�����\n");
		printCourse(to_string(tmp.CourseId));
		printf("��ϣ�����������������: 1.�鿴ѡ��ѧ������ 2.�鿴�γ̱�����������");
		int opt = queBox<int>("����������:", 1);
		if (opt == 1){
			viewStu(curCourse.CourseId);
		}
		else if (opt == 2){
			printAssist(curCourse.CourseId);
		}
		else printf("��Ч������\n");
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

void UI::printCourse(string CourseId){
	//cout << CourseId << endl;
	string id = str_toStringId(atoi(CourseId));
	cout << id << "\t" << pCourse.query(CourseId, 1)[0] << "\t" << pCourse.query(CourseId, 2)[0] << "\t" << pCourse.query(CourseId, 3)[0] << "\t" << pCourse.query(CourseId, 4)[0] << "\t";
	cout << pCourse.query(CourseId, 5)[0] << endl;
}
void UI::admin_addCourse()
{
	string st = queBox<string>("����γ̾�����Ϣ:", 2);
	vector<string> a = str_Split(st, ',');
	CourseNode tmp = CourseNode(a[0], a[1], stoi(a[2]), stoi(a[3]), a[4]);
	int state = admin.addCourse(tmp);//��ӿγ�
	if (state == 1){
		printf("���ʧ�ܣ��γ��Ѿ����б���!\n");
	}
	else{
		printf("��ӳɹ���\n");
		viewAllCourse();
	}
}

void UI::admin_delCourse()
{
	int tmp = queBox<int>("����γ̱��:", 2);
	int tmp1 = admin.delCourse(tmp);
	if (tmp1 == 0){
		printf("ɾ���ɹ�!\n");
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
	int id = queBox<int>("������Ҫ�޸ĵ�id:", 1);
	if (!admin.isCourseInList(CourseNode(id))){
		printf("�޸�ʧ�ܣ��޴˿γ̣�");
	}
	else{
		int tmp = queBox<int>("������Ҫ�޸ĵ��ֶ�(1.�ον�ʦ  2.��������): ", 1);
		if (tmp == 1){
			string st = queBox<string>("�޸Ľ�ʦ����Ϊ:", 2);


			CourseNode tmpCourse;
			tmpCourse.CourseName = st;
			tmpCourse.CourseId = id;
			int tmp1 = admin.editCourse(tmpCourse);
			if (!tmp1) printf("�޸ĳɹ���\n");
			else printf("�޸�ʧ�ܣ�\n");
		}
		else{
			if (tmp == 2){
				int cap= queBox<int>("�޸���������Ϊ:", 1);
				CourseNode tmpCourse;
				tmpCourse.CourseCap = cap;
				tmpCourse.CourseId = id;
				int tmp1 = admin.editCourse(tmpCourse);
				if (!tmp1) printf("�޸ĳɹ���\n");
				else printf("�޸�ʧ�ܣ���Ϊ�޸ĺ������С��Ŀǰ��ѡ����\n");
			}
		}
	}
}

void UI::stu_checkAssistError()
{
	if (stu.isAssistError()){
		vector<string> a = stu.getAssistError();
		printf("ע�⣡��ѡ���һ�¿γ̵������˳��˸ÿγ̣�������ѡ������!\n");
		printf("�γ�ID:");
		cout << a[0];
		For(i, 1, int(a.size()) - 1){
			cout << "," << a[i];
		}
		cout << endl;
	}
}

void UI::stu_addCourse()
{
	int id = queBox<int>("����γ�id:", 1);
	int tmp = stu.addCourse(CourseNode(id));
	if (tmp == 0) printf("�Ѿ���ӵ����˿α���!\n");
	else if (tmp == 1)printf("���ʧ�ܣ��ÿγ��Ѿ��ڸ��˿α���!\n");
	else if (tmp == 2) printf("���ʧ�ܣ��ÿγ�����!\n");
}

void UI::stu_viewAllCourse()
{
	vector<string>& a = stu.getStuCourseList();
	printf("�γ�ID\t�γ�����\t�ڿν�ʦ\t��������\tĿǰ��ѡ\t�γ�����\n");
	For(i, 0, int(a.size()) - 1){
		printCourse(a[i]);
	}
	pair<int, int> sum = stu.getProAndNonePro();
	if (sum.first == 0 && sum.second == 0) printf("ѡ���Ѿ��ﵽҪ��!\n");
	else{
		printf("����ѧԺҪ��Ŀǰ��ѡ�γ��������!");
		if (sum.first != 0) printf("��%d��רҵ�Σ�", sum.first);
		if (sum.second != 0) printf("��%d�ŷ�ҵ�Σ�", sum.second);
		printf("�뼰ʱѡ��!\n");
	}
}

void UI::stu_delCourse()
{
	int id = queBox<int>("����γ�id:", 1);
	int tmp = stu.delCourse(CourseNode(id));
	if (tmp == 0){
		printf("ɾ���ɹ�!\n");
		viewAllCourse();
	}
	else printf("ɾ��ʧ��!�ÿγ̲��ڸ��˿α���!\n");
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
	int id = queBox<int>("����γ�id:", 1);
	int tmp2 = stu.isCourseAssistHaveChosen(assistNode(id, stu.userName));
	if (tmp2 == 1) printf("�ÿγ��Ѿ�ѡ�����̣�");
	else{
		if (tmp2 == 2) printf("���˿α��������ſΣ�");
		else{
			if (printAssist(id));
			else{
				string st = queBox<string>("������������:", 2);
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
	int id = queBox<int>("����γ�id:", 1);
	int tmp = stu.beAssistant(assistNode(id, stu.userName));
	if (tmp == 0) printf("�����ɹ�!\n");
	if (tmp == 1) printf("����ʧ�ܣ��ظ�������\n");
	if (tmp == 2) printf("����ʧ�ܣ��Ѿ������ſγ̵�����!\n");
	if (tmp == 3) printf("����ʧ�ܣ���û��ѡ����ſγ�!");
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
	string path = queBox<string>("��������Ҫ������ļ�����:", 2);
	int tmp = admin.addStuFromFile(path);
	if (tmp == 0) printf("����ɹ���\n");
	else if (tmp == 1) printf("����ʧ�ܣ��ļ��޷��򿪣�\n");
	else if (tmp == 2) printf("����ʧ�ܣ������ֳ��ļ�������\n");
}