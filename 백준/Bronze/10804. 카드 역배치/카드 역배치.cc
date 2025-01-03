#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> v;
	
	for(int i=1; i<=20; i++){
		v.push_back(i);
	}
	
	//0, 1, 2, 3 ... 18, 19
	//1, 2, 3, 4 ... 19, 20
	//만약 구간이 [1, 4] -> idx 0 ~ 3
	
	for(int i=0; i<10; i++){
		int a, b;
		cin >> a >> b;
		
		reverse(v.begin() + (a-1), v.begin() + b);
	}
	
	for(int num : v){
		cout << num << " ";
	}
}