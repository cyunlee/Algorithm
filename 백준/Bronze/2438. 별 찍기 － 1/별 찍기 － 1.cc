#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	for(int i=1; i<=n; i++){
		for(int j=0; j<i; j++){
			cout << "*";
		}
		cout << '\n';
	}
}