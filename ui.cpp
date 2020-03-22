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
}

void UI::stuReg()
{
}

void UI::adminLogIn()
{
	string st = queBox<string>("�������ԱID:", 2);
	if (st == "Admin"){
		string password = queBox<string>("�������Ա����:", 2);
		if (password == "admin"){
			printf("*******��½�ɹ�!*******\n");
			adminPanel();
		}
	}
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

void UI::viewAllCourse()
{
	printf("�γ�ID\t�γ�����\t�ڿν�ʦ\t��������\tĿǰ��ѡ\t�γ�����\n");
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
	int tmp = queBox("��������Ҫ�޸ĵ�id:", 1);

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
	if (tmp == 0) cout << "����ɹ���";
}