#pragma once
#include"diag.h"
class databaseStudentX
{
	//����ά��ĳ��ѧ���Ŀγ̺�������Ϣ
	//ά����ѧ�����γ�-�ÿγ����̣���ϵ
	//�������� ��ɾ�Ĳ� + �ļ�
public:
	//�ļ�����
	int readFromFile(string path);
	bool writeToFile(string path);
	void setpath(string st);//����ѧ���ļ�·����ע��stҪ���ļ��ĺ�׺��������

	vector<stuCourseNode>& getStuCourseList();//��ȡѧ��������ѡ����Ϣ
	bool isCourseInStuCourseList(CourseNode);//��ѯѧ���Ƿ�ѡ��ĳ��� ���� CourseId
	/*bool isCourseAssistantFull(stuCourseNode tmp);*/
	stuCourseNode getStuCourse(stuCourseNode);//��ȡѧ����ĳ�ſε�������Ϣ ���� courseId

	void addStuCourse(stuCourseNode);//ѧ������һ�ſ�
	void delStuCourse(stuCourseNode);//ѧ������һ�ſ�
	void addAssistant(assistNode);//ѧ���޸����� ���� courseId Assistname
	
	vector<stuCourseNode> stuCourseList;
	string pathBase;
	
};

extern databaseStudentX dataStuX;;