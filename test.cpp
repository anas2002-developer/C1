#include<iostream>
using namespace std;
class Deque
{
    int front;
    int rear;
    int arr[5];
    public:
    int size; 
    Deque(){
            front = rear = -1;
            for(int i=0;i<5;i++){
			arr[i]=0;
			size++;
		}
    }
     bool isEmpty(){
        return (front==-1);
    }
    bool isFull(){
        return (rear+1)%size==front;
    }
     bool pushFront(int x)
     {
        if(isFull()){
             cout<<"Queue is Full";
             return false;
        }
        else if(isEmpty()){
            front = rear = 0;
        }
        else if(front == 0 && rear!=size-1){
            front = size - 1;
        }
        else{
            front--;
        }
        arr[front]= x;
        return true;
     }
     bool pushRear(int x){
        if(isFull()){
             cout<<"Queue is Full";
             return false;
        }
        else if(isEmpty()){
            front = rear = 0;
        }
        else if(rear == size-1 && front!=0 ){
            rear == 0;
        }
        else{
            rear++;
        }
        arr[rear] = x;
        return true;
     }
     int deque(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return 0; 
        }
        int ans = arr[front];
        arr[front]= -1;
        if(front == rear){
            front = rear = -1;
            }
            else if(front == size-1){
                front = 0;
            } 
            else{
                front++;
            }
            return ans;
        }
        int  popFront(){
            if(isEmpty()){
                cout<<"Queue is empty"<<endl;
                return 0; 
            }
            int ans = arr[front];
            arr[front] = -1;
           
            if(front == rear){
                front = rear =-1;
            }
            else if(front == size -1){
                front =0;
            }
            else{
                front++;
            }
            return ans;
        }
       int popRear(){
            if(isEmpty()){
                cout<<"Queue is empty"<<endl;
                return 0; 
            }
            int ans = arr[rear];
            arr[front] = -1;
            
            if(front == rear){
                front =rear =-1;
            }
            else if(rear == 0){
                rear = size - 1;
            }
            else{
                rear--;
            }
            return ans;
        }
    void show(){
        
		if (isEmpty()){
			cout<<"No elements";
            }
            else{
                cout<<endl<<"The circular queue is : ";
                for(int i=0;i<size;i++){
                    cout<<arr[i]<<" ";
                }
            }
        }
};
int main()
{
    Deque d;
   
    d.pushRear(5);
    d.pushRear(9);
    d.pushFront(2);
    d.pushFront(3);
    d.pushFront(4);
    d.show();
    cout<<"\nElement deleted "<<d.popFront();
    cout<<"\nElement deleted "<<d.popFront()<<endl;
    d.show();
    cout<<d.isEmpty()<<endl;
    
    return 0;
}
