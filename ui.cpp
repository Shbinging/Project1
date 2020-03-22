#include"ui.h"
#include"diag.h"
#include"agori.h"
void UI::cmdUi(){
	//while (1){
		printf("1.ѧ����¼	2.ѧ��ע��	3.����Ա��¼\n");
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
		}
	//}
}

void UI::stuLogIn()
{
	string name = queBox<string>("����ѧ��ID:", 2);
	string password = queBox<string>("����ѧ������:", 2);
	if (stu.checkpassword(name, password)){
		printf("*******��½�ɹ�!*******\n");
		stuPanel(name);
	}
	else printf("�û������������");

}

void UI::stuReg()
{
	string name = queBox<string>("����ѧ��ID:", 2);
	if (stu.isStuWordInList(stuWordNode(name))){
		printf("��ID�Ѿ�ע�ᣡ\n");
	}
	else{
		string password = queBox<string>("����ѧ������:", 2);
		stu.addStuWord(name, password);
		printf("*********ע��ɹ�,��¼�ɹ���*******\n");
		stuPanel(name);
	}
}

void UI::adminLogIn()
{
	string st = queBox<string>("�������ԱID:", 2);
	string password = queBox<string>("�������Ա����:", 2);
	if (admin.checkPassword(st, password)){
			printf("*******��½�ɹ�!*******\n");
			adminPanel();
		}
	else printf("�û������������!\n");
}

void UI::cls()
{
}

void UI::adminPanel()
{
	printf("1.ע����¼ 2.¼��γ���Ϣ 3.�鿴ȫ���γ���Ϣ 4.���ӿγ� 5.ɾ���γ� 6.�޸Ŀγ� 7.�鿴����γ�\n");
	int tmp = queBox<int>("��ѡ������Ĺ���:", 1);
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
	printf("1.ע����¼ 2.�鿴�γ���Ϣ 3.ѡ�� 4.�鿴���˿α� 5.�˿� 6.���ֱ�������7.ѡ���������\n");
	int tmp = queBox<int>("��ѡ������Ĺ���:", 1);
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
	printf("�γ�ID\t�γ�����\t�ڿν�ʦ\t��������\tĿǰ��ѡ\t�γ�����\n");
	vector<CourseNode>& CourseList = admin.getCourseList();
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
		printCourse(tmp);
	}
}

void UI::printCourse(CourseNode tmp){
	string id = str_toStringId(tmp.CourseId);
	cout << id << "\t" << tmp.CourseName << "\t" << tmp.CourseTeacher << "\t" << tmp.CourseCap << "\t" << tmp.CourseSel << "\t";
	if (tmp.CourseType == 0) cout << "רҵ��" << endl;
	else cout << "��רҵ��" << endl;
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
		printf("ɾ���ɹ���");
		viewAllCourse();
	}
	else if (tmp1 == 1){
		printf("�γ�ɾ��ʧ�ܣ��޴˿γ̣�");
	}
	else if (tmp1 == 2){
		printf("�γ�ɾ��ʧ�ܣ�Ŀǰ����ѧ��ѡ�˿Σ�");
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
	vector<stuCourseNode>& a = stu.getStuCourseList();
	printf("�γ�ID\t�γ�����\t�ڿν�ʦ\t��������\tĿǰ��ѡ\t�γ�����\n");
	For(i, 0, int(a.size()) - 1){
		int tmp = a[i].courseId;
		CourseNode tmp1 = stu.getCourse(CourseNode(tmp));
		printCourse(tmp1);
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
	else printf("ɾ��ʧ��!�ÿγ̲��ڸ��˿α���!");
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
	string path = queBox<string>("��������Ҫ������ļ�����:", 2);
	int tmp = admin.addStuFromFile(path);
	if (tmp == 0) printf("����ɹ���\n");
	else if (tmp == 1) printf("����ʧ�ܣ��ļ��޷��򿪣�\n");
	else if (tmp == 2) printf("����ʧ�ܣ������ֳ��ļ�������\n");
}