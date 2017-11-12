#include<iostream>
using namespace std;
struct student   //abstract data type created
{
	int rollno;
	char name[50];
	double marks;
	student*next;
};
student* AllocateNode();
void PerpendNode();
void InsertNode();
void SearchList();
void PrintNode();
void PrintList();
void AppendNode();
void DeleteANode(int n);
void DeleteFirstNode();
void DeleteLastNode();
void FindMthToLast();
void ListIntersection();
void ReverseList();
