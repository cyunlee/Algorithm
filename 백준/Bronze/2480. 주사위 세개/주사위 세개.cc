#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, c;
	cin >> a >> b >> c;
	
	int prize = 0;
	
	if(a==b && b==c) {
		prize = 10000 + a * 1000;
	}else if(a==b && b!=c) {
		prize = 1000 + a * 100;
	}else if(b==c && c!=a){
		prize = 1000 + b * 100;
	}else if(c==a && a!=b){
		prize = 1000 + c * 100;
	}else {
		int max = a;
		if(b > max) {
			max = b;
		}
		if(c > max) {
			max = c;
		}
		prize = max * 100;
	}
	
	cout << prize << '\n';
}