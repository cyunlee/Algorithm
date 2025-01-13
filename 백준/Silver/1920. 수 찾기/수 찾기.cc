#include <bits/stdc++.h>
using namespace std;
int n, m;
int A[100005];
int M[100005];

int binary_search(int target){
  int st = 0;
  int en = n-1;

  while(st <= en){
    int mid = (st+en)/2;

    if(target<A[mid]) en = mid - 1;
    else if(target>A[mid]) st = mid + 1;
    else return 1;
  }

  return 0;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for(int i=0; i<n; i++){
    cin >> A[i];
  }

  sort(A, A+n);

  cin >> m;

  for(int i=0; i<m; i++){
    cin >> M[i];
    cout << binary_search(M[i]) << '\n';
  }
}