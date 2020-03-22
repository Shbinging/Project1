#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<vector>
#include<cstdlib>

#define testUi
//#define DEBUG

#define For(i, l, r) for(int i = l; i <= r; i++)
using namespace std;


struct CourseNode{
	CourseNode(int id){
		CourseId = id;
		CourseName = "";
	}
	CourseNode(string name){
		CourseName = name;
		CourseId = 0;
	}
	// id name teacher cap sel type
	CourseNode(string name, string teacher, int cap, int sel, string type){
		CourseId = 0;
		CourseName = name;
		CourseTeacher = teacher;
		CourseCap = cap;
		CourseSel = sel;
		if (type == "专业课") CourseType = 0;
		else CourseType = 1;
	}
	int CourseId, CourseCap, CourseSel;
	string CourseName, CourseTeacher;
	bool CourseType;//0专业课 1非专业课
};
extern vector<CourseNode>CourseList;