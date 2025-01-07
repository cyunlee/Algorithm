#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	queue<int> Q;
	
	for(int i=0; i<N; i++){
		string cmd;
		cin >> cmd;
		
		if(cmd == "push"){
			int val;
			cin >> val;
			Q.push(val);
		}else if(cmd == "pop"){
			if(Q.empty()){
				cout << "-1" << '\n';
			}else{
				cout << Q.front() << '\n';
				Q.pop();
			}
		}else if(cmd == "size"){
			cout << Q.size() << '\n';
		}else if(cmd == "empty"){
			if(Q.empty()) cout << "1" << '\n';
			else cout << "0" << '\n';
		}else if(cmd == "front"){
			if(Q.empty()) cout << "-1" << '\n';
			else cout << Q.front() << '\n';
		}else if(cmd == "back"){
			if(Q.empty()) cout << "-1" << '\n';
			else cout << Q.back() << '\n';
		}
	}
}