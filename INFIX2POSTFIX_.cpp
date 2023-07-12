#include<iostream>
#include<stack>
using namespace std;

int PRECEDENCE(char c){
	if (c=='^')
		return 3;
	else if (c=='*' || c=='/') 
		return 2;
	else if (c=='+' || c=='-')
		return 1;
	else
		return -1;
}

string INFIX2POSTFIX(string s){
	stack<char> STACK;
	string RESULT;
	
	for(int i=0;i<s.length();i++){
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
			RESULT+=s[i];
		}
		else if(s[i]=='('){
			STACK.push('(');
		}
		else if(s[i]==')'){
			while(!STACK.empty() && STACK.top()!='('){
				RESULT+=STACK.top();
				STACK.pop();
			}
			STACK.pop();
		}
		else{
			while(!STACK.empty() && PRECEDENCE(s[i])<=PRECEDENCE(STACK.top())){
				RESULT+=STACK.top();
				STACK.pop();
			}
			STACK.push(s[i]);
		}
	}
	while(!STACK.empty()){
		RESULT+=STACK.top();
		STACK.pop();
	}
	return RESULT;
}

int main(){
	cout<<INFIX2POSTFIX("A+((B+C)+(D+E)*F)/G")<<endl;
//	cout<<INFIX2POSTFIX("(A+B)*(C+D)")<<endl;
//	cout<<INFIX2POSTFIX("A+B*C+(D*E)")<<endl;
//	cout<<INFIX2POSTFIX("K+L-M*N+(O^P)*W/U/V*T+Q^J^A")<<endl;
//	cout<<INFIX2POSTFIX("A+B*(C^D-E)^(F+G*H)-I")<<endl;
//	cout<<INFIX2POSTFIX("A+(B*C(D/E^F)*G)*H)")<<endl;
	
	return 0;
}
