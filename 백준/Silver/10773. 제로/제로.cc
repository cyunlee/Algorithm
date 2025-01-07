#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int K, sum = 0;
	cin >> K;
	
	stack<int> S;
	vector<int> ret;
	
	for(int i=0; i<K; i++){
		int number;
		cin >> number;
		
		if(number==0){
			S.pop();
		}else{
			S.push(number);
		}
	}
	
	while(!S.empty()){
		ret.push_back(S.top());
		S.pop();
	}
	
	cout << accumulate(ret.begin(), ret.end(), 0);
}