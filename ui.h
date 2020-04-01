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
	string queBoxStr(string st, int opt = 0);//opt == 1��������ո�
	vector<string> queBoxStrList(string st, char ch = ' ');//Ĭ�Ͽո����
private:
	userAdmin admin;
	userStu stu;
};

class Password//��һ����ʵ�֣���ʵҲ���Բ�����ô�鷳����ϰһ��
{
public:
	Password()//���캯����������Ҫ���ڳ�ʼ�����룬ʹ֮Ϊ��
	{
		psw = "";//��ʼ������Ϊ��"";
		length = 0; //��ʼ�����볤��
	}
	void inputPassword(string st)//�������벢����*Ϊ����
	{
		char temp_c;
		cout << st;
		while (true)
		{
			temp_c = _getch();  //����һ���ַ�
			if (temp_c != char(13))  //�жϸ��ַ��ǲ�Ϊ�س�����������˳�while
			{
				switch (temp_c)
				{
				case 8:
					if (length != 0)
					{
						cout << "/b /b";
						psw = psw.substr(0, length - 1);
						length--;
					}
					else;
					break;
				default:
					cout << "*"; //��������ϲ���������ַ������Ϊcout<<"";���޻���
					psw += temp_c;//�����ַ�����
					length++;
					break;
				}
			}
			else break;
		}
	}
	string getPassword()//����һ�������ַ�������ʵ���԰������ٴμ��ܣ��������ݿ��С�
	{
		return psw;
	}
private:
	string psw;//���ڴ�������ַ�����
	int length;//���볤��
};