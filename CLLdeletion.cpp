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
            newNode->next=newNode;
			head=newNode;
        }
        else {
        	Node *currNode=head;
        	while(currNode->next!=head){
        		currNode=currNode->next;
			}
			currNode->next=newNode;
            newNode->next = head;
            head = newNode;
        }
    }
    
    void predelete(Node* &head){       
        if (head==NULL){
            cout<<"Empty Linked List"<<endl;;
        }
        else {
        	Node *currNode=head;
        	while(currNode->next!=head){
        		currNode=currNode->next;
			}
			currNode->next=head->next;
			head=head->next;
        }
    }

    void anydelete(Node* &head, int pos){

        if (head==NULL){
            cout<<"Empty Linked List"<<endl;
        }
        if (pos==1){
        	predelete(head);
		}
        else {
        	int count=1;
        	Node *currNode=head;
            while(count!=pos-1){
            	currNode=currNode->next;
            	count++;
            	if(currNode->next==head)
            	{
            		cout<<"position out of bound"<<endl;
            		return;
				}
            }
            currNode->next=currNode->next->next;
            
        }
    }

    void sufdelete(Node* &head){       

        if (head==NULL){
            cout<<"Empty Linked List"<<endl;
        }
        if (head->next==head){
        	head=NULL;
		}
        else {
        	Node *seclastNode=head;
            Node* lastNode=head->next;
            while(lastNode->next!=head){
                lastNode=lastNode->next;
                seclastNode=seclastNode->next;
            }
            seclastNode->next=lastNode->next;
            lastNode->next=NULL;
        }
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
		predelete(head);
		sufdelete(head);
//		anydelete(head,1);
        showLL(head);
        return 0;
    }


