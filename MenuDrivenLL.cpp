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
    
    void predelete(Node* &head){       
        if (head==NULL){
            cout<<"Empty Linked List"<<endl;;
        }
        else {
            head=head->next;
        }
    }

    void anydelete(Node* &head, int pos){

        if (head==NULL){
            cout<<"Empty Linked List"<<endl;
        }
        if (pos==1){
        	head=head->next;
		}
        else {
            Node *currNode=head;
            for(int i=1;i<pos-1;i++){
                currNode=currNode->next;
            }
            if (currNode->next==NULL){
            	cout<<"position out of bound"<<endl;
			}
			else{
            currNode->next= currNode->next->next;
        	}
        }
    }

    void sufdelete(Node* &head){       

        if (head==NULL){
            cout<<"Empty Linked List"<<endl;
        }
        if (head->next==NULL){
        	head=NULL;
		}
        else {
        	Node *seclastNode=head;
            Node* lastNode=head->next;
            while(lastNode->next!=NULL){
                lastNode=lastNode->next;
                seclastNode=seclastNode->next;
            }
            seclastNode->next=NULL;
        }
    }

    void showLL(Node* head){           
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
            newNode->next = currNode->next;
            currNode->next= newNode;
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
    
    int main(){
    	Node* head=NULL;
        int a;
        prepend(head,2);
        prepend(head,4);
        prepend(head,6);
        prepend(head,8);
        prepend(head,10);
        prepend(head,12);
        cout<<"Name : MOHD ANAS"<<endl<<"UID : 21BCS8965"<<endl<<endl;
        
        int choice,pos,element,torf=1;
        while(torf){
        	cout<<endl<<endl;
        	cout<<"*******************************"<<endl;
        cout<<"Operations (Singly Linked List):"<<endl;
        cout<<"1. Insertion"<<endl;
        cout<<"2. Deletion"<<endl;
        cout<<"3. Searching"<<endl;
        cout<<"4. Traversing"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter choice(1-5):";
        cin>>choice;
        switch(choice){
        	case 1:
        		showLL(head);
        		cout<<"Enter position of element to be inserted=";
        		cin>>pos;
        		cout<<endl<<"Enter element to be inserted=";
        		cin>>element;
        		anypend(head,pos,element);
        		break;
        	case 2:
        		showLL(head);
        		cout<<"Enter position of element to be deleted=";
        		cin>>pos;
        		anydelete(head,pos);
        		break;
        	case 3:
        		cout<<endl<<"Enter element to be searched=";
        		cin>>element;
        		a=search(head,element);
        		if (a>0){
        			cout<<endl<<"Element found at position="<<a;
				}
				else{
					cout<<endl<<"Element not found";
				}
				break;
			case 4:
				showLL(head);
				break;
			case 5:
				cout<<"Exited.";
				torf=0;
				break;
			default:
				cout<<"Wrong choice";
				cout<<endl<<"Program Terminated";
				torf=0;
				break;
		}
	}
        return 0;
    }


