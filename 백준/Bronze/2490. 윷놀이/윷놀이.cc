#include<bits/stdc++.h>
using namespace std;

//0 - 배, 1 - 등
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=0; i<3; i++){
		vector<int> v;
		int a, b, c, d;
		
		cin >> a >> b >> c >> d;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		v.push_back(d);
		
		int bae = 0, deung = 0;
		for(int x : v) {
			if(x==0) bae++;
			else deung++;
		}
		
		switch(bae) {
			case 1:
				cout << "A" << '\n';
				break;
			case 2:
				cout << "B" << '\n';
				break;
			case 3:
				cout << "C" << '\n';
				break;
			case 4:
				cout << "D" << '\n';
				break;
			case 0:
				cout << "E" << '\n';
				break;
		}
	}
}