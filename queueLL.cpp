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
    
class queue{
	Node *front;
	Node *back;
	public:
	queue(){
		front=NULL;
		back=NULL;
	}
    
    //operations
    
    bool isEmpty(){
    	return front==NULL;
	}
    
	void enqueue(int data){   
        Node *newNode=new Node(data);

        if (isEmpty()){
            front=newNode;
            back=newNode;
        }
        else {
        	back->next=newNode;
        	back=newNode;
        }
    }
    
    int dequeue(){
		if (isEmpty()){
			cout<<"UNDERFLOW";
			return -1;
		}       
        else {
        	int dequeued=front->data;
            front=front->next;
            cout<<endl<<"Element poped is ";
            return dequeued;
        }
    }

	int peek(){
		if(isEmpty()){
			cout<<"UNDERFLOW";
			return -1;
		}
		cout<<endl<<"Element at front->";
		return front->data;
	}
    
	void traverse(){  
		cout<<endl<<endl<<"queue - ";         
        if (isEmpty()){
            cout<<"UNDERFLOW"<<endl;
        }
        Node *currNode=front;
        while(currNode!=NULL){
            cout<<currNode->data<<"->";
            currNode=currNode->next;
        }
        cout<<"NULL"<<endl;
    }
};
    
    
    int main(){
    	queue obj;
    	obj.enqueue(1);
        obj.enqueue(2);
        obj.enqueue(3);
        obj.enqueue(4);
        obj.enqueue(6);
        cout<<obj.dequeue();
        obj.enqueue(5);
        cout<<obj.peek();
        obj.traverse();
        return 0;
    }


