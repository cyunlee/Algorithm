#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, K;
	cin >> N >> K;
	
	list<int> L;
	vector<int> ret;
	
	for(int i=1; i<=N; i++){
		L.push_back(i);
	}
	
	auto cur = L.begin();
	
	while(!L.empty()){
		for(int i=0; i<K-1; i++){
			cur++;
			if(cur == L.end()) cur = L.begin();
		}
		ret.push_back(*cur);
		cur = L.erase(cur);
		if(cur == L.end()) cur = L.begin();
	}
	
	cout << '<';
	
	for(int i=0; i<N; i++){
		if(i == N-1) cout << ret[i];
		else cout << ret[i] << ", ";
	}
	
	cout << '>';
}