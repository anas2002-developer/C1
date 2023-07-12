#include<iostream>
using namespace std;

class STACKKKK{
	public:
	int array[5];
	int top;
	int size;
	STACKKKK(){
		top=-1;
		size=0;
		for(int i=0;i<5;i++){
			array[i]=0;
			size++;
		}
	}

bool isEmpty(){
	return top==-1;
}

bool isFull(){
	return top==size-1;
}

void push(int x){
	if(isFull()){
		cout<<"OVERFLOW/n";
	}
	else{
		top++;
		array[top]=x;
	}
}

int pop(){
	if(isEmpty()){
		cout<<"UNDERFLOW\n";
	}
	else{
		int rmv=array[top];
		array[top]=0;
		top--;
		return rmv;
	}
}

int peek(){
	cout<<"Peek ";
	return array[top];
}

void update(int x,int pos){
	if(pos>top+1 || pos<1){
		cout<<"Position Out of Bound\n";
	}
	else{
		array[pos-1]=x;
	}
}
void traverse(){
	if(isEmpty()){
		cout<<"UNDERFLOW\n";
	}
	else{
		cout<<"STACKKKK-";
		for(int i=0;i<=top;i++){
			cout<<array[i]<<" ";
		}
	}
}

int length(){
	return top+1;
}

};

int main(){
	STACKKKK obj;
	obj.push(2);
	obj.push(4);
	obj.push(6);
	obj.push(8);
	obj.push(10);
	
	obj.pop();
	cout<<obj.peek()<<endl;
	obj.update(18,4);
	
	obj.length();
	obj.traverse();
	return 0;
}
