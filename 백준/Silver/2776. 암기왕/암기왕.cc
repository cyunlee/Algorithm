#include <bits/stdc++.h>
using namespace std;
int A[1000002];
int n;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		cin >> n;
		
		for(int i=0; i<n; i++){
			cin >> A[i];
		}
		
		sort(A, A+n);
		
		int m;
		cin >> m;
		
		for(int i=0; i<m; i++){
			int num;
			cin >> num;
			
			cout << binary_search(A, A+n, num) << '\n';
		}
	}
}