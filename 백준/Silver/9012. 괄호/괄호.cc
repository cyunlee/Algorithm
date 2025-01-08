#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	for(int i=0; i<T; i++){
		bool isValid = true;
		
		string str;
		cin >> str;
		
		stack<char> st;
		
		for(char x : str){
			if(x=='(') st.push(x);
			else{
				if(st.empty() || st.top()!='('){
					isValid = false;
					break;
				}else if(!st.empty() && st.top()=='('){
					st.pop();
				}
			}
		}
		
		if(!st.empty()) isValid = false;
		
		if(isValid) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}