#pragma once
#include"diag.h"
class databaseStudentAll
{
	//ѧ��������������ά��
	//�ļ�Ϊstudent.txt
public:
	databaseStudentAll();
	//�ļ�����
	int readFromFile(string path);
	bool writeToFile(string path);

	void addStuWord(stuWordNode);//����һ��ѧ����������

	vector<stuWordNode>& getStuWordList();//��ѯȫ��ѧ������
	bool isStuInStuWordList(stuWordNode);//��ѯĳ��ѧ���Ƿ����
	stuWordNode getStuWord(stuWordNode);//��ѯĳ��ѧ��������
	
	
	
	vector<stuWordNode> stuWordList;//��
	string pathBase;
};

extern databaseStudentAll dataStuAll;
