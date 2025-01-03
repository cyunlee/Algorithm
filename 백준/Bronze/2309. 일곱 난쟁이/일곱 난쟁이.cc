#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> dwrf;
	
	for(int i=0; i<9; i++){
		int height;
		cin >> height;
		
		dwrf.push_back(height);
	}
	
	int sum = accumulate(dwrf.begin(), dwrf.end(), 0);
	int rest = sum - 100;
	
	for(int i=0; i<9; i++){
		for(int j=i+1; j<9; j++){
			if(dwrf[i] + dwrf[j] == rest) {
				dwrf.erase(dwrf.begin() + j);
				dwrf.erase(dwrf.begin() + i);
				goto found;
			}
		}
	}
	
	found:
		sort(dwrf.begin(), dwrf.end());
		for(int x : dwrf) {
			cout << x << '\n';
		}
}