#pragma once
#include"diag.h"


class databaseAssistant
{
public:
	databaseAssistant();//��ʼ�������ļ�
	//�ļ����ֵĶ�д �ļ�Ϊassistant.txt
	int readFromFile(string path);
	bool writeToFile(string path);

	int countAssistant(assistNode tmp);//ͳ��ĳ��ѧ���������̵Ĵ��� ������� stuId
	bool isStuInAssistList(assistNode tmp);//��ѯĳ��ѧ���Ƿ���ĳ���γ��е����� �������courseId stuId

	void addStuInAssistList(assistNode tmp);//��ĳ���γ�����һ��ѧ�� ������� courseId stuId
	assistNode& getAssistNode(assistNode tmp);//��ѯĳ���γ̵�ѧ������ ���ز��� assistNode
	
	bool isCourseInAssistList(assistNode tmp);//��ѯĳ���γ��Ƿ������� ������� courseId
	void delCourseInAssistList(assistNode tmp);//ɾ��ĳ���γ��Լ��ÿγ�ȫ������ �������courseId

	vector<assistNode> assistList;//��(����assistNode��ɵ�һ��)
	assistNode assist;//assistNode
private:
	string pathBase;//�ļ�·��
};

extern databaseAssistant dataAssi;
