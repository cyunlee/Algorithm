#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int sum = 0;
	vector<int> ret;
	
	for(int i=0; i<5; i++){
		int num;
		cin >> num;
		ret.push_back(num);
		
		sum += num;
	}
	
	int avg = sum / 5;
	
	sort(ret.begin(), ret.end());
	int mid = ret[2];
	
	cout << avg << '\n';
	cout << mid << '\n';
}