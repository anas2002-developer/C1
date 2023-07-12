#include<iostream>
using namespace std;
int main(){
	int a=10;
	int *p=&a;
	int **r=&p;
	cout<<"  a = "<<a<<endl;
	cout<<"  p = "<<p<<endl;
	cout<<" *p = "<<*p<<endl;
	cout<<" &a = "<<&a<<endl;
	cout<<"  r = "<<r<<endl;
	cout<<" &p = "<<&p<<endl;
	cout<<" *r = "<<*r<<endl;
	cout<<"**r = "<<**r<<endl;
	
	return 0;
}

