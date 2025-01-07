#include <bits/stdc++.h>
using namespace std;

void second(deque<int> &DQ){
	int tmp2 = DQ.front();
	DQ.pop_front();
	DQ.push_back(tmp2);

}

void third(deque<int> &DQ){
	int tmp3 = DQ.back();
	DQ.pop_back();
	DQ.push_front(tmp3);

}

int getSecond(deque<int> DQ, int num) {
	int cnt = 0;
	
	while(DQ.front() != num){
		second(DQ);
		cnt++;
	}
	
	return cnt;
}

int getThird(deque<int> DQ, int num) {
	int cnt = 0;
	
	while(DQ.front() != num){
		third(DQ);
		cnt++;
	}
	
	return cnt;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	
	deque<int> DQ;
	
	for(int i=1; i<=N; i++){
		DQ.push_back(i);
	}
	
	int sum = 0;
	
	for(int i=0; i<M; i++){
		int num;
		cin >> num;
		
		if(DQ.front()==num) {
			DQ.pop_front();
		}else {
			int sec = getSecond(DQ, num);
			int thi = getThird(DQ, num);
			
			sum += min(sec, thi);
			
			if(sec < thi) {
				while(DQ.front() != num) second(DQ);
			}else {
				while(DQ.front() != num) third(DQ);
			}
			DQ.pop_front();
		}
	}
	
	cout << sum;
}