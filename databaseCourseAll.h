#pragma once
#include"diag.h"
#include"databaseStudentAll.h"
#include"databaseCurrentCourse.h"
#include"databaseStudentX.h"
class databaseCourseAll
{
	//����ά��ÿ���γ�����ѡѧ��������
	//ά�����γ̣� ѧ������ϵ
public:
	//databaseCourseAll();
	//int len();
	void init();//��ʼ��ͳ��
	/*
	void addStuInCourseX(int id, string name);//��ĳ���γ�������ѧ��
	void addCourseXInGraph(int id);//����һ��γ�

	void delCourseXInGraph(int id);//ɾ��һ��γ�
	void delStuInCourseX(int id, string name);//ɾ��ĳ���γ��е�ĳ��ѧ��
	
	pair<int, int> findStuInCourseX(int id, string name);//��ѯ��ĳ���γ���ѧ��λ�� -1û�ҵ�������λ��
	bool isStuInCourseX(int id, string name);//��ѯĳ��ѧ���Ƿ�ѡ��ĳ��γ�
	courseStuNode& getListInCourseX(int id);//��ȡĳ���γ̵�ѧ������
	int findCourseXInGraph(int id);
	bool isCourseXInGraph(int id);//��ѯ�ÿγ��Ƿ��ڱ���
	
	vector<courseStuNode> courseStuList;
	courseStuNode courseStuListNode;
	*/
};

extern databaseCourseAll dataCourseStu;