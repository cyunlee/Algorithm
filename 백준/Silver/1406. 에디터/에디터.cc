#include<bits/stdc++.h>
using namespace std;
list<char> L;
int N;
string str;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> str;
	cin >> N;
	
	string bufferflush;
	getline(cin, bufferflush);
	
	for(char x : str) L.push_back(x);
	
	auto cur = L.end();
	
	for(int i=0; i<N; i++){
		string cmd;
		getline(cin, cmd);
		
		if(cmd[0]=='L' && cur!=L.begin()) cur--;
		else if(cmd[0]=='D' && cur!=L.end()) cur++;
		else if(cmd[0]=='B'&& cur!=L.begin()) cur = L.erase(prev(cur));
		else if(cmd[0]=='P'){
			char alpha = cmd[2];
			L.insert(cur, alpha);
		}
	}
	
	for(auto i : L) cout << i;
}