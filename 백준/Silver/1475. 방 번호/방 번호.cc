#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, num[10]={}, ans = 0;
	
	cin >> N;
	
	while(N){
		num[N%10]++;
		N/=10;
	}
	
	for(int i=0; i<10; i++){
		if(i==6 || i==9) continue;
		ans = max(ans, num[i]);
	}
	
	ans = max(ans, (num[6]+num[9]+1)/2);
	
	cout << ans;
}