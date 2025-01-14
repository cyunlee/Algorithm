#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int k, n;
ll A[10002];

ll parametric_search(int mx_line, int n) {
  ll st = 1;
  ll en = mx_line;
  ll ans = 0;

  while(st <= en) {
    ll mid = (st + en)/2;
    ll sum = 0;

    for(int i=0; i<k; i++){
      sum += A[i]/mid;
    }

    if(sum >= n) {
      ans = mid;
      st = mid + 1;
    }else {
      en = mid - 1;
    }
  }

  return ans;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //k- 가지고 있는 랜선 수, n- 필요한 랜선 수
  cin >> k >> n;

  ll mx_line = 0;

  // 랜선 길이 입력
  for(int i=0; i<k; i++){
    cin >> A[i];
    mx_line = max(mx_line, A[i]);
  }

  sort(A, A+k);

  cout << parametric_search(mx_line, n);
}