#include<iostream>
using namespace std;

class stackArray{
	public:
	int arr[5];
	int top;
	int size;					//if not defined default value is 1
	stackArray(){
		for(int i=0;i<5;i++){
			arr[i]=0;
			size++;
		}
	}
	
	//operations:
	
	bool isEmpty(){
		return top==-1;
	}
	bool isFull(){
		return top==size-1;
	}	
	void push(int x){
		if (isFull()){
			cout<<"OVERFLOW"<<endl;
		}
		else{
			top++;
			arr[top]=x;
		}
	}
	int pop(){
		if (isEmpty()){
			cout<<"UNDERFLOW";
			return -1;
		}
		else{
			int poped=arr[top];
			arr[top]=0;
			top--;
			cout<<endl<<"Element poped is ";
			return poped;
		}
	}
	int peek(){
		cout<<endl;
		if (isEmpty()){
			cout<<"UNDERFLOW";
			return -1;
		}
		else{
			cout<<"element at top->";
			return arr[top];
		}
	}
	void update(int x, int pos){
		cout<<endl;
		if (pos-1>top || pos<1){
			cout<<"position out of bound"<<endl;
		}
		else{
			arr[pos-1]=x;
		}
	}
	void traverse(){
		cout<<endl<<endl<<"stack = ";
		if (isEmpty()){
			cout<<"UNDERFLOW";}
		for(int i=0;i<=top;i++){
			cout<<arr[i]<<" ";
		}
	}
	int length(){
		return top+1;
	}
};

int main(){
	stackArray obj;
	cout<<obj.isEmpty();
	cout<<obj.pop();
	obj.push(1);
	obj.push(2);
	obj.push(3);
	obj.push(4);
	obj.push(6);
	cout<<obj.pop();
	obj.push(5);
	obj.update(20,5);
	cout<<obj.peek();
	obj.traverse();
	cout<<endl<<"Length="<<obj.length()<<endl;
}
