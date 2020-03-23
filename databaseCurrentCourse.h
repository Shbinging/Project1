#pragma once
#include"diag.h"
class databaseCurrentCourse
{
	//����ά���γ̵ľ�����Ϣ
	//�ļ�+��ɾ�Ĳ� �ļ�Ϊcurrent_course.txt
public:
	databaseCurrentCourse();
	//�ļ�����
	bool isFileExsist(string path);
	int readFromFile(string path);
	bool writeToFile(string path);

	void addCourse(CourseNode);//����һ�ſγ���Ϣ
	void delCourse(CourseNode);//ɾ��һ�ſγ���Ϣ
	void editCourse(CourseNode);//�ı�ĳ�ſγ̵�ĳ����Ϣ ��courseId/CourseName��Ϊ�ؼ��֣��ı�����

	bool isCourseInlist(CourseNode);//��ѯĳ�ſγ��Ƿ����
	vector<CourseNode>& getCourseList();//��ȡ���пγ��б�
	CourseNode getCourse(CourseNode);//��ȡĳ��γ���Ϣ

	vector<CourseNode>CourseList;
	string pathBase;
private:
	int courseSum;
};

extern databaseCurrentCourse dataCourse;