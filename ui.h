#pragma once
#include"diag.h"
#include"userAdmin.h"
#include"userStu.h"
class UI
{
public:
	void cls();
	void wait();
	//�����
	void cmdUi();//��ʼ����
	void stuLogIn();//ѧ����¼����
	void stuReg();//ѧ��ע�����
	void adminLogIn();//����Ա��¼����
	void adminPanel();//����Ա�����
	void stuPanel(string name);//ѧ�������
	//���������Ա
	void viewAllCourse();//�鿴ȫ���γ�
	void admin_addCourseFromFile();//2���ļ�����γ�
	void viewCourse();//7�鿴�����γ�
	void viewStu(int Courseid);//7�鿴�����γ�ѧ��
	void admin_addCourse();//4���ӿγ�
	void admin_delCourse();//5ɾ���γ�
	void admin_editCourse();//6�༭�γ�
	//�����ѧ��
	void stu_checkAssistError();//�жϸ��������Ƿ��쳣
	void stu_addCourse();//3ѡ��
	void stu_viewAllCourse();//4�鿴���˿α�
	void stu_delCourse();//5�˿�
	void stu_addAssistant();//6���ֱ�������
	

	void stu_selAssistant();//7ѡ������

	//����������
	bool printAssist(int id);
	void printAssist(vector<string>&);//��ӡ����
	void printCourse(string);//������α��ӡ
	void printCoursePart(string);//���ֿα��ӡ
	int queBoxInt(string st);
	string queBoxStr(string st);
private:
	userAdmin admin;
	userStu stu;
};
