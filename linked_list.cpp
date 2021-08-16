#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;

class linkedList {

	private:
	
	struct node {
		int data=0;
		struct node *next=NULL;
	};
	node *head;
	
	public:
	
	void createLinkedList(int val) {
		node *newnode;
		newnode = new node;
		newnode->data = val;
		newnode->next = NULL;
		head = newnode;
	};
	
	void displayLinkedList() {
		node *temp;
		temp=head;
		while(temp!=NULL) {
			cout<<"[ DATA: "<<temp->data<<"| NEXT: "<<temp->next<<" ]-----";
			temp=temp->next;
		}
		delete temp;
	};
	void addNode(int val) {
		node *newnode;
		newnode = new node;
		newnode->next=NULL;
		newnode->data=val;
		node *temp = head;
		
		while(temp->next!=NULL) {
			temp = temp->next;
		}
		temp->next=newnode;
	};
	void deleteNode(int index) {
		node *temp;
		temp=head;
		node *curr;
		curr=head;
		while(temp->next!=NULL) {
			temp=temp->next;
		}
		while(curr->next!=temp) {
			curr=curr->next;
		}
		curr->next=NULL;
	};
	void editLinkedList(int val,int index) {
		if(head!=NULL) {
			node *temp;
			temp=head;
			int count = 0;
			while(temp->next!=NULL && count<=index) {
				temp=temp->next;
				count++;
			}
			temp->data=val;
		} else {
			cout<<"CANNOT DO IT"<<endl;
		}
	};
	void lengthLinkedList() {
		int length = 0;
		if(head!=NULL) {
			length = 1;
			node *temp;
			temp=head;
			while(temp->next!=NULL) {
				length++;
				temp=temp->next;
			}
			cout<<"LENGTH OF LINKED LIST: "<<length<<endl;
		} else {
			cout<<"LENGHT: 0"<<endl;
		}
	};
};

int main() {
	int menu=0,data=0,index=0;
	linkedList l1;
	do{
		cout<<"\n1] CREATE LINKED LIST "<<endl;
		cout<<"2] DISPLAY LINKED LIST"<<endl;
		cout<<"3] ADD NODE"<<endl;
		cout<<"4] EDIT NODE"<<endl;
		cout<<"5] DELETE NODE"<<endl;
		cout<<"6] LENGTH OF LINKED LIST"<<endl;
		cout<<"7] EXIT"<<endl;
		cout<<"ENTER YOUR CHOICE: ";
		cin>>menu;
		cout<<"\n";
		
		switch(menu) {
			case 1: {
				cout<<"LINKED LIST CREATED!!"<<endl;
				cout<<"ENTER DATA INTO HEAD NODE: ";
				cin>>data;
				l1.createLinkedList(data);
			}break;
			case 2: {
				cout<<"LINKED LIST: \n";
				l1.displayLinkedList();
			}break;
			case 3: {
				cout<<"ENTER DATA INTO NODE: ";
				cin>>data;
				l1.addNode(data);
			}break;
			case 4: {
				cout<<"ENTER WHICH NODE TO EDIT: ";
				cin>>index;
				cout<<"\nENTER DATA TO EDIT: ";
				cin>>data;
				l1.editLinkedList(data,index);
				l1.displayLinkedList();
			}break;
			case 5: {
				cout<<"WHICH NODE TO DELETE: ";
				cin>>index;
				l1.deleteNode(index);
				l1.displayLinkedList();
			}break;
			case 6: {
				l1.lengthLinkedList();
			}break;
		};
		
	}while(menu<7);
	return 0;	
}
