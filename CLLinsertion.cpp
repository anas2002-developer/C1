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
    	Node* newNode=new Node(data);
	if (head==NULL){
		newNode->next=newNode;
		head=newNode;
	}     
    else{
    	Node* currNode=head;
    	while(currNode->next!=head){
    		currNode=currNode->next;
		}
		currNode->next=newNode;
		newNode->next=head;
		head=newNode;
	}
    }

    void anypend(Node* &head, int pos, int data){
        Node* newNode=new Node(data);
        if (head==NULL)
            prepend(head,data);
        }
        if (pos==1){
        	Node* currNode=head;
    	while(currNode->next!=head){
    		currNode=currNode->next;
		}
		currNode->next=newNode;
		newNode->next=head;
		head=newNode;	
		}
        else {
        	int count=1;
            Node *currNode=head;
            while(count!=pos-1){
            	currNode=currNode->next;
            	count++;
            	if (currNode==head){
            		cout<<"position out of bound"<<endl;
            		return;
				}
			}
			newNode->next = currNode->next;
            currNode->next= newNode;
        }
        }
    

    void append(Node* &head, int data){       
        Node *newNode=new Node(data);

        if (head==NULL){
        	newNode->next=newNode;
            head=newNode;
        }
        else {
            Node* currNode=head;
            while(currNode->next!=head){
                currNode=currNode->next;
            }
            currNode->next=newNode;
            newNode->next=head;
        }
    }

    int search(Node* &head, int data){
        Node* currNode=head;
        int pos=1;
        do{
        	if(currNode->data==data){
        		return (pos);
			}
        	currNode=currNode->next;
        	pos++;
		}
        while(currNode!=head);
        return 0;
    }
    
    void showLL(Node* &head){           
        if (head==NULL){
            cout<<"Empty List"<<endl;
        }
        Node *currNode=head;
        do{
        	cout<<currNode->data<<"->";
        	currNode=currNode->next;
		}
        while(currNode!=head);
        cout<<endl;
    }
    int main(){
    	Node* head=NULL;
        int a;
        prepend(head,5);
        prepend(head,6);
        prepend(head,7);
        prepend(head,8);
        append(head,10);
        append(head,11);
        anypend(head,7,12);
        a=search(head,5);
        if (a>0){
            cout<<"ELement found at pos - "<<a<<endl;
        }
        else{
            cout<<"Element not found"<<endl;
        }
        showLL(head);
        return 0;
    }


