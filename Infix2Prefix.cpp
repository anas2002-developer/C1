#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int precedence(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

string infix2prefix(string s)
{
	reverse(s.begin(),s.end());
	stack<char> stac; 
	string result;

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			result += c;
		else if (c == '(')
			stac.push('(');

		else if (c == ')') {
			while (!stac.empty() && stac.top() != '(') {
				result += stac.top();
				stac.pop();
			}
			stac.pop();
		}
		else if (c=='^'){
			result += stac.top();
			stac.pop();
			stac.push(c);	
		}
		else{
			if (precedence(c) >= precedence(stac.top())){
				stac.push(c);
			}
			else {
				while (!stac.empty() && precedence(c) < precedence(stac.top())) {
					result += stac.top();
					stac.pop();
				}
				stac.push(c);
			}
		}
	}

	while (!stac.empty()) {
		result += stac.top();
		stac.pop();
	}
	reverse(result.begin(),result.end());
	return result;
}

int main()
{
//	cout<<infix2prefix("A+(B*C)")<<endl;
//	cout<<infix2prefix("(A*B)+(C*D)")<<endl;
//	cout<<infix2prefix("A+B*C^D")<<endl;
//	cout<<infix2prefix("K+L-M*N+(O^P)*W/U/V*T+Q^J^A")<<endl;
//	cout<<infix2prefix("(A+(B/C)*(D^E)-F)")<<endl;
//	cout<<infix2prefix("A+B+C")<<endl;
//	cout<<infix2prefix("A^B^C^D")<<endl;
	cout<<infix2prefix("A+B*(C-D)/(P-R)")<<endl;
	return 0;
}

