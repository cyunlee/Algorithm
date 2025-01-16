#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[100004];
int n, m;

ll parametric_search(ll min_size, ll max_size) {
	ll st = min_size;
	ll en = max_size;
	
	while(st <= en) {
		ll mid = (st + en)/2;
		
		int sum = 0, cnt = 0;
		for(int i=0; i<n; i++){
			if (sum + arr[i] > mid) { //담은 강의 길이가 커지면 새 블루레이 시작
				sum = 0;
				cnt++;
			}
			sum += arr[i];
		}
		if(sum!=0) cnt++; //sum이 0이 아니면 마지막 블루레이에 강의가 남아있을 수 있음
		
		if(cnt > m) {
			st = mid + 1;
		}else {
			en = mid - 1;
		}
	}
	
	return st; //st와 en이 역전되면 이진 탐색이 끝난 시점이고, 이때 st는 최소값을 가리키게 됨
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	//강의 입력받기
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	ll min_size = *max_element(arr, arr+n);
	ll max_size = accumulate(arr, arr+n, 0LL);

	cout << parametric_search(min_size, max_size);
}