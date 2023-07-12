#include<iostream>
using namespace std;

class Node {
	public:
    int data;
    Node *next; 
	Node *prev;     

    Node(int data) {
        this->data = data;
        this->next = NULL;
		this->prev = NULL;       
        }
    };
    void prepend(Node* &head,int data){       
        Node *newNode=new Node(data);

        if (head==NULL){
            head=newNode;
        }
        else {
            newNode->next = head;
			head->prev = newNode;
            head = newNode;
        }
    }
    
    void predelete(Node* &head){       
        if (head==NULL){
            cout<<"Empty Linked List"<<endl;;
        }
        else {
            head=head->next;
            head->prev=NULL;
        }
    }

//    void anydelete(Node* &head, int data){		//using data as parameter
//
//        if (head==NULL){
//            cout<<"Empty Linked List"<<endl;
//        }
//        if (data==head->data){
//        	head=head->next;
//		}
//        else {
//        	Node *seclastNode=head;
//            Node *lastNode=head->next;
//            while(lastNode!=NULL){
//            	if (lastNode->data==data){
//            		seclastNode->next= lastNode->next;
//            		lastNode->next->prev=seclastNode;
//            		break;
//				}
//                lastNode=lastNode->next;
//                seclastNode=seclastNode->next;
//            }
//            
//        }
//    }
    
    void anydelete(Node* &head, int pos){
        if (head==NULL){
            cout<<"Empty Linked List"<<endl;
        }
        if (pos==1){
        	head=head->next;
		}
        else {
        	int count=1;
            Node *currNode=head;
            while(currNode!=NULL && count!=pos){
            	currNode=currNode->next;
            	count++;
        	}
        	if (currNode==NULL){
        		cout<<"position out of bound"<<endl;
			}
			else{
        	currNode->prev->next= currNode->next;
            if (currNode->next!=NULL){	
            	currNode->next->prev= currNode->prev;
            }
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
            lastNode->prev=NULL;
            seclastNode->next=NULL;
        }
    }

    void showLL(Node* head){     
		cout<<"NULL"<<"->";      
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
        prepend(head,7);
        prepend(head,8);
//		predelete(head);
//		sufdelete(head);
		anydelete(head,4);
        showLL(head);
        return 0;
    }


