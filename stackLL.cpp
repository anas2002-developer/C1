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
    
    //operations
    
    bool isEmpty(Node* &top){
    	return top==NULL;
	}
    
	void push(Node* &top,int data){   
        Node *newNode=new Node(data);

        if (top==NULL){
            top=newNode;
        }
        else {
            newNode->next = top;
            top = newNode;
        }
    }
    
    int pop(Node* &top){
		if (isEmpty(top)){
			cout<<"UNDERFLOW";
			return -1;
		}       
        else {
        	int poped=top->data;
            top=top->next;
            cout<<endl<<"Element poped is ";
            return poped;
        }
    }

	int peek(Node* &top){
		if(isEmpty(top)){
			cout<<"UNDERFLOW";
			return -1;
		}
		else{
		cout<<endl<<"Element at top->";
		return top->data;
	}
	}
    
	void traverse(Node* &top){  
		cout<<endl<<endl<<"stack - ";         
        if (isEmpty(top)){
            cout<<"UNDERFLOW"<<endl;
        }
        Node *currNode=top;
        while(currNode!=NULL){
            cout<<currNode->data<<"->";
            currNode=currNode->next;
        }
        cout<<"NULL"<<endl;
    }
    
    
    int main(){
    	Node* top=NULL;
        push(top,1);
        push(top,2);
//        push(top,3);
//        push(top,4);
//        push(top,6);
//        cout<<pop(top);
//        push(top,5);
//        cout<<peek(top);
        traverse(top);
        return 0;
    }


