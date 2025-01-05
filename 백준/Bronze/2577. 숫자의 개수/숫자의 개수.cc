#include<bits/stdc++.h>
using namespace std;

int arr[10];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, c;
	cin >> a >> b >> c;
	
	int calc = a * b * c;
	string str = to_string(calc);
	
	for(char x : str){
		int idx = x - '0';
		arr[idx]++;
	}
	
	for(int num : arr){
		cout << num << '\n';
	}
}