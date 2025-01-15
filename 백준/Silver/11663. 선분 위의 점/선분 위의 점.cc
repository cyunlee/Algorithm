#include <bits/stdc++.h>
using namespace std;

long long A[100004];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		cin >> A[i];
	}
	
	sort(A, A+n);
	
	while(m--){
		long long begin, end;
		cin >> begin >> end;
		
		cout << upper_bound(A, A+n, end) - lower_bound(A, A+n, begin) << '\n';
	}
}