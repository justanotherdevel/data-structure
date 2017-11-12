#include<iostream>
#include<stdio.h>
#include "student.h"

using namespace std;

student *head;				//declared global

student *AllocateNode()			//creates a pointer pointing to a node
{
	student *ptr;
	ptr = new student;
	cout << "Enter Roll no" << endl;
	cin >> ptr->rollno;
	cout << "Enter Name" << endl;
	cin >> ptr->name;
	cout << "Enter Marks" << endl;
	cin >> ptr->marks;
	ptr->next = NULL;
	return ptr;
}

//Rewrote PrependNode
void PrependNode()
{
	student *tmp = AllocateNode();
	tmp->next = head;
	head = tmp;
}

//What if n-2 > the number of nodes? Run time error?
void InsertNode()			//inserting node at nth location
{
	int n;
	student *temp;
	temp = head;
	cout << "Position at which you want to insert the Linked List" << endl;
	cin >> n;
	for (int i =0; i < n-2; i++)
	{
		temp = temp->next;
	}	
	student *store  = temp->next;
	student *ext = AllocateNode();
	temp->next = ext;
	ext->next = store;
}

// Search is not by position. Try implementing it with roll number
// you might also need to add a condition when the roll number is not in the list
void SearchList()
{
	int n;
	cout << "Enter the node which you want to print";
	cin >> n;
	student *temp;
	temp = head;
	for (int i = 0; i < n; i++)
	{
		temp = temp->next;	// traversal of list
	}	
	cout << "Search completed";
}

// Condition where n is greater than the list size?
void PrintNode()
{
	int n;
	cout<<"enter the node which u want to print";
	cin>>n;
	student*temp6;
	temp6=head;
	for(int i=1;i<n;i++)
	{
		temp6 = temp6->next;
	}
	cout<<temp6->rollno;      //at end of loop the value of i is also useful
	cout<<endl<<temp6->name;
	cout<<endl<<temp6->marks;
}

// Rewrote the entire function
void PrintList()
{
	student *temp = head;
	while(temp){
		cout << temp->rollno << " " << temp->name << " " << temp->marks;
		temp = temp->next;
	}
	
}

// Append only one node at a time
void AppendNode()    //attaching node in the end
{
	student *tmp = AllocateNode();
	student *iter = head;
	if (iter) {
		while (iter->next) {
			iter = iter->next;
		}
		iter->next = tmp;
	} else {
		head = tmp;
	}
}

// Maybe implement delete function with roll number and not position
// Also, there is a memory leak situation
void DeleteANode(int n)    //deleting a node at Nth position
{
	student*temp;
	temp = head;
	int i=1;
	if(n!=1)
	{
	while ((i<n-1)&&(temp->next!=NULL))
	{
		temp=temp->next;
		i++;
	}
		temp->next = temp->next->next;   // not pointing a node...means it is deleted
}
	else
	{
			head = temp->next;
	}
}

// Rewrote the entire function
void DeleteFirstNode()
{
	if (head) {
		student *tmp = head;
		head = head->next;
		delete tmp;
	}
}

// Rewrote the entire function
void DeleteLastNode()
{
	student *prev = head;
	if (head) {
		student *tmp = head;
		while (tmp->next) {
			prev = tmp;
			tmp = tmp->next;	
		}
		delete tmp;
		prev->next = 0;
	}
}
void FindMthToLast()
{
	student*temp = head;
	int x, m, i=1 ;
	cout<<"enter the value of M you want to find ! "<<endl;//mth to last means  n-l+1 th from beginning
	cin>>m;
	while(temp->next!=NULL) //calculating current size of linked list
	{
		temp = temp->next;
		i++;
	}
	x = i-m+1;
	student*temp6;
	temp6=head;
	for(int j=1;j<x;j++)
	{
		temp6 = temp6->next;
	}
	cout<<temp6->rollno;
	cout<<endl<<temp6->name;
	cout<<endl<<temp6->marks;
		
}

// Didn't check this function
void ListIntersection()
{
	int a,w;
	student*temp1, *temp2, *temp3;
	head = AllocateNode();
	cout<<"for the first linked list"<<endl;
	cout<<"one node allocated for you"<<endl;
	cout<<"Press 0 to exit and enter the second.....1 to perpendNode,......2 to AppendNode,.......3 to PrintList"<<endl;
	
	int j=1;
	while(j==1)
	{
		cin>>a;
		switch(a)
	{
		case 0: j=0;
				break;
		case 1: PrependNode();
				break;
		case 2: AppendNode();
				break;
		case 3: PrintList();
				break;
	}	
	}
	temp1=head;
	cout<<"for the second link list"<<endl;
	head =  AllocateNode();
	cout<<"one node is allocate for you"<<endl;
	cout<<"Press 1 to perpendNode,......2 to AppendNode,.......3 to PrintList"<<endl;

	int i =1;
	while(i==1)
	{
		cin>>w;
		switch(w)
	{
		case 0: i=0;
				break;
		case 1: PrependNode();
				break;
		case 2: AppendNode();
				break;
		case 3: PrintList();
				break;
	}	
	}
	temp2 = head;
	cout<<"the intersection of these two linked lists is ....."<<endl<<endl;
	while(temp1->next!=NULL)
	{
		temp3=temp2;
		while(temp3->next!=NULL)
		{
		if( (temp1->rollno==temp3->rollno) &&(temp1->name==temp3->name)&&(temp1->marks==temp3->marks))
		{
			cout<<temp1->rollno<<endl;
			cout<<temp1->name<<endl;          //comparing the all elements of linked list Naive method
			cout<<temp1->marks<<endl;
			temp3 = temp3->next;
			break;
		}
		else 
		{
			temp3 = temp3->next;
			
		}
			
		}
		if(temp3->next==NULL)
		{
		if( (temp1->rollno==temp3->rollno) &&(temp1->name==temp3->name)&&(temp1->marks==temp3->marks))
		{
			cout<<temp1->rollno<<endl;
			cout<<temp1->name<<endl;          //comparing the all elements of linked list Naive method
			cout<<temp1->marks<<endl;
		}	
		}
		temp1 = temp1->next;
		if(temp1->next==NULL){
			temp3=temp2;
		while(temp3->next!=NULL)
		{
		if( (temp1->rollno==temp3->rollno) &&(temp1->name==temp3->name)&&(temp1->marks==temp3->marks))
		{
			cout<<temp1->rollno<<endl;
			cout<<temp1->name<<endl;          //comparing the all elements of linked list Naive method
			cout<<temp1->marks<<endl;
			temp3 = temp3->next;
			break;
		}
		else 
		{
			temp3 = temp3->next;
			
		}
			
		}
		if(temp3->next==NULL)
		{
		if( (temp1->rollno==temp3->rollno) &&(temp1->name==temp3->name)&&(temp1->marks==temp3->marks))
		{
			cout<<temp1->rollno<<endl;
			cout<<temp1->name<<endl;          //comparing the all elements of linked list Naive method
			cout<<temp1->marks<<endl;
		}	
		}
		}
	}
}

void ReverseList()
{
	student *p1, *p2, *p3; 						// three continuous nodes, previous, current and next
        if (head == NULL)						// Linked List is empty
        {
            cout<<"List is empty"<<endl;
            return;
        }
        if (head->next == NULL)					// Only one node
        {
            return;
        }  
        p1 = head;								//start node
        p2 = p1->next;							//second node
        p3 = p2->next;							//third node
        p1->next = NULL;						//pointing to NULL as it is last node
        p2->next = p1;							//second last node.
        while (p3 != NULL)						//traverse
        {
            p1 = p2;							//second node
            p2 = p3;							//third node
            p3 = p3->next;						//next node
            p2->next = p1;         				//p2 does the work of adjusting the poiters.
		}
        head = p2;
        student *temp;
        temp=head;
        while(temp->next!=NULL){
        	cout<<temp->rollno;
			cout<<temp->name;
			cout<<temp->marks;
        	temp=temp->next;
		}
		cout<<temp->rollno;
		cout<<temp->name;
		cout<<temp->marks;
}
int main()
{
	head = AllocateNode();
	int a,n;
	
	while(1)
	{
		cout<<"\nWelcome....Enter your choice to perform action"<<endl;
		cout<<"0: exit the loop"<<endl;
		cout<<"1: A node has been allocated for you"<<endl;
		cout<<"2: PerpendNode"<<endl;
		cout<<"3: AppendNode"<<endl;
		cout<<"4: InsertNode"<<endl;
		cout<<"5: SearchListcout"<<endl;
		cout<<"6: PrintNode"<<endl;
		cout<<"7: PrintList"<<endl;
		cout<<"8: DeleteFirstNode"<<endl;
		cout<<"9: DeleteLastNode"<<endl;
		cout<<"10: DeleteANode"<<endl;
		cout<<"11: ReverseList"<<endl;
		cout<<"12: ListUnion"<<endl;
		cout<<"13: ListIntersection"<<endl;
		cout<<"14: FindMthToLast"<<endl;
		cin>>a;
		switch(a)
		{
			case 0: 
				        return 0;
			case 1: cout<<"A node has been allocated for you";
					break;
			case 2: PrependNode();
			        	break;
			case 3: AppendNode();
					break;
			case 4: InsertNode();
					break;
			case 5: SearchList();
					break;
			case 6: PrintNode();
					break;
			case 7: PrintList();
					break;
			case 8: DeleteFirstNode();
					break;
			case 9: DeleteLastNode();
					break;
			case 10: cout<<"enter the number of node you want to delete";
				  	cin>>n;
				  	DeleteANode(n);
					break;
			case 11: ReverseList();
					break;
		/*case 12: ListUnion();*/
			case 13: ListIntersection();
					break;
			case 14: FindMthToLast();
			  		break;
	}
}

	return 0;
}
