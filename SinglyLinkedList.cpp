#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int data){
			this->data=data;
			this->next=NULL;
		}
};

void InsertionF( Node* &head , int data ){
	Node* newNode=new Node(data);
	
	if(head==NULL){
		head=newNode;
	}
	
	else{
		newNode->next=head;
		head=newNode;
	}
}

void InsertionE( Node* &head , int data ){
	Node* newNode=new Node(data);
	
	if(head==NULL){
		head=newNode;
	}
	
	else{
		Node* currNode=head;
		while(currNode->next!=NULL){
			currNode=currNode->next;
	}
	currNode->next=newNode;
}
}

void InsertionA( Node* &head , int data , int pos ){
	Node* newNode=new Node(data);
	
	if(head==NULL){
		head=newNode;
	}
	
	if(pos==1){
		newNode->next=head;
		head=newNode;
	}
	
	else{
		Node* currNode=head;
		for(int i=1;i<pos-1;i++){
			currNode=currNode->next;
		}
		if(currNode==NULL){
			cout<<"Position Out of Bound"<<endl;
		}
		else{
			newNode->next=currNode->next;
			currNode->next=newNode;
		}
	}
}

void DeletionF( Node* &head ){
	if(head==NULL){
		cout<<"No Node to delete\n";
	}
	
	else{
		head=head->next;
	}
}
void DeletionE( Node* &head ){
	
	if(head==NULL){
		cout<<"No Node to delete\n";
	}
	
	if(head->next==NULL){
		head=NULL;
	}
	
	else{
		Node* currNode=head;
		while(currNode->next->next!=NULL){
			currNode=currNode->next;
		}
		currNode->next=NULL;
	}
}

void DeletionA( Node* &head , int pos ){
	
	if(head==NULL){
		cout<<"No Node to delete\n";
	}
	
	if(head->next==NULL){
		head=NULL;
	}
	
	else{
		Node* currNode=head;
		for(int i=1;i<pos-1;i++){
			currNode=currNode->next;
		}
		if(currNode->next==NULL){
			cout<<"Position Out of Bound\n";
		}
		else{
			currNode->next=currNode->next->next;
		}
	}
}

int Search( Node* &head , int data ){
	Node* currNode=head;
	int pos=1;
	
	if(head==NULL){
		cout<<"No Nodes\n";
	}
	
	while(currNode!=NULL){
		if(currNode->data==data){
			cout<<"Element present at pos ";
			return pos;
		}
		currNode=currNode->next;
		pos++;
	}
	cout<<"Not Present in LL ";
	return -1;
}

void Traverse( Node* &head ){
	if (head==NULL){
		cout<<"NO NODE"<<endl;
	}
	
	Node* currNode=head;
	while(currNode!=NULL){
		cout<<currNode->data<<"->";
		currNode=currNode->next;
	}
	cout<<"NULL"<<endl;
}

int main(){				//4,12,2,10,6,8
	Node* head=NULL;
	
	InsertionF(head,2);
	InsertionF(head,4);
	InsertionE(head,6);
	InsertionE(head,8);
	InsertionA(head,10,3);
	InsertionA(head,12,2);
	
	DeletionF(head);		//12,2,6
	DeletionE(head);
	DeletionA(head,3);
	
	cout<<Search(head,6)<<endl;			//3
	
	Traverse(head);
	
	return 0;
}
