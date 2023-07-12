#include<iostream>
using namespace std;

class Node {
	public:
    int data;
    Node *next;      

    Node(int data) {
        this->data = data;
        this->next = NULL;       
        }
    };
    
    void prepend(Node* &head,int data){       
        Node *newNode=new Node(data);

        if (head==NULL){
            head=newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void anypend(Node* &head, int pos, int data){
        Node* newNode=new Node(data);

        if (head==NULL){
            head=newNode;
        }
        if (pos==1){
            newNode->next=head;
            head=newNode;
        }
        else {
            Node *currNode=head;
            for(int i=1;i<pos-1;i++){
                currNode=currNode->next;
            }
            if (currNode==NULL){
            	cout<<"position out of bound"<<endl;
			}
			else{
            newNode->next = currNode->next;
            currNode->next= newNode;
        	}
        }
    }

    void append(Node* &head, int data){       
        Node *newNode=new Node(data);

        if (head==NULL){
            head=newNode;
        }
        else {
            Node* currNode=head;
            while(currNode->next!=NULL){
                currNode=currNode->next;
            }
            currNode->next=newNode;
        }
    }

    int search(Node* &head, int data){
        Node* currNode=head;
        int pos=1;
        while(currNode!=NULL){
            if (currNode->data==data){
                return (pos);
            }
            currNode=currNode->next;
            pos++;
        }
        return 0;

    }
    void showLL(Node* &head){           
        if (head==NULL){
            cout<<"Empty List"<<endl;
        }
        Node *currNode=head;
        while(currNode!=NULL){
            cout<<currNode->data<<"->";
            currNode=currNode->next;
        }
        cout<<"NULL"<<endl;
    }
    int main(){
    	Node* head=NULL;
        int a;
        prepend(head,5);
        prepend(head,6);
//        prepend(head,7);
//        prepend(head,8);
//        append(head,10);
//        append(head,11);
//        anypend(head,8,12);
//        a=search(head,5);
//        if (a>0){
//            cout<<"ELement found at pos - "<<a<<endl;
//        }
//        else{
//            cout<<"Element not found"<<endl;
//        }

        showLL(head);
        return 0;
    }


