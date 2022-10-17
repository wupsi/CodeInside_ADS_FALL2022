#include <iostream>
#include <stack>
using namespace std;

bool isLetter(char c){
	return (c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z');
}

int main(){

	string exp; cin >> exp;
	stack<string> st;

	for(int i = 0; i < exp.size(); i++){
		if(isLetter(exp[i])) st.push(string(1, exp[i]));
		else{
			string op1 = st.top();
			st.pop();
			string op2 = st.top();
			st.pop();
			st.push("(" + op2 + exp[i] + op1 + ")");
		}
	}
	cout << st.top();
}
// char    string 
//  v        v
// 'a'  ->  "a"