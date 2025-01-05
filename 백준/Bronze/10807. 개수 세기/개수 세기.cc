#include<bits/stdc++.h>
using namespace std;

int N, v, ans;
vector<int> vec;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	
	for(int i=0; i<N; i++){
		int num;
		cin >> num;
		vec.push_back(num);
	}
	
	cin >> v;
	
	for(int x : vec) {
		if(x == v) ans++;
	}
	
	cout << ans;
}