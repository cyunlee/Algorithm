#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<int> S;
	
	int N;
	cin >> N;
	
	for(int i=0; i<N; i++){
		string cmd;
		cin >> cmd;
		
		if(cmd=="push"){
			int X;
			cin >> X;
			S.push(X);	
		}else if(cmd=="pop"){
			if(S.empty()){
				cout << "-1" << '\n';
			}else{
				cout << S.top() << '\n';
				S.pop();
			}
			
		}else if(cmd=="size"){
			cout << S.size() << '\n';
		}else if(cmd=="empty"){
			if(S.empty()) cout << "1" << '\n';
			else cout << "0" << '\n';
		}else if(cmd=="top"){
			if(S.empty()) cout << "-1" << '\n';
			else cout << S.top() << '\n';
		}
	}
}