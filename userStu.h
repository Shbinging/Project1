#pragma once
#include"diag.h"
#include"databaseStudentAll.h"
#include"databaseStudentX.h"
#include"databaseCurrentCourse.h"
#include"databaseAssistant.h"
#include"databaseCourseAll.h"
#include"agori.h"
class userStu
{
public:
	bool checkpassword(string name, string password);
	void setpath(string path);//��ʼ��
	bool isStuWordInList(stuWordNode tmp);
	void addStuWord(string name, string password);
	
	vector<string>& getStuCourseList();
	int addCourse(CourseNode);
	int delCourse(CourseNode);
	int beAssistant(assistNode);//Ҫ���Լ�������
	int addAssistant(assistNode tmp, string st);//������˵��Լ�������
	
	bool isCourseAssistExsist(assistNode);
	int isCourseAssistHaveChosen(assistNode);
	vector<string>& getAssistNode(assistNode);
	CourseNode getCourse(CourseNode tmp);
	string userName;
	
	bool isAssistError();//�ж���û�и�ѧ���������˿� 1�� 0��
	vector<string> getAssistError();//��ȡ��ѧ���˿ε���������
	pair<int, int> getProAndNonePro();//��ȡʣ��רҵ�η�רҵ��Ҫ��

	void close();
private:
	int assistantSum, proSum, nonProSum, courseSum;
	//������������ רҵ������ ��רҵ������ �γ���
	//�ڳ�ʼ��ʱ���ͳ�ƣ�֮����ѧ������������ֱ�Ӽ���
};

