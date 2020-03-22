#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<vector>
#include<cstdlib>
#define DEBUG
#define testUi
//#define DEBUG

#define For(i, l, r) for(int i = l; i <= r; i++)
using namespace std;


struct CourseNode{
	CourseNode(){
		CourseId = 0;
		CourseName = "";
		CourseTeacher = "";
		CourseCap = -1;
		CourseSel = -1;
		CourseType = -1;
	}
	CourseNode(int id){
		CourseId = id;
		CourseName = "";
		CourseTeacher = "";
		CourseCap = -1;
		CourseSel = -1;
		CourseType = -1;
	}
	CourseNode(string name){
		CourseName = name;
		CourseId = 0;
		CourseTeacher = "";
		CourseCap = -1;
		CourseSel = -1;
		CourseType = -1;
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
	int CourseId, CourseCap, CourseSel, CourseType;//0专业课 1非专业课
	string CourseName, CourseTeacher; 
};
extern vector<CourseNode>CourseList;