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

    void anydelete(Node* &head, int data){

        if (head==NULL){
            cout<<"Empty Linked List"<<endl;
        }
        if (data==head->data){
        	head=head->next;
		}
        else {
        	Node *seclastNode=head;
            Node *lastNode=head->next;
            while(lastNode!=NULL){
            	if (lastNode->data==data){
            		seclastNode->next= lastNode->next;
            		break;
				}
                lastNode=lastNode->next;
                seclastNode=seclastNode->next;
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
    
    
    int main(){
    	Node* head=NULL;
        int a;
        prepend(head,5);
        prepend(head,6);
        prepend(head,7);
        prepend(head,8);
//		predelete(head);
//		sufdelete(head);
		anydelete(head,7);
        showLL(head);
        return 0;
    }


