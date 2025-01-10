#include<bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;

  vector<int> times;

  for(int i=0; i<n; i++){
    int time;
    cin >> time;
    times.push_back(time);
  }

  int ysum = 0;
  int msum = 0;

  for(int x : times) {
    int y = 10 + (x/30) * 10;
    int m = 15 + (x/60) * 15;

    ysum += y;
    msum += m;
  }

  if(ysum < msum) {
    cout << "Y" << " " << ysum;
  }else if(msum < ysum) {
    cout << "M" << " " << msum;
  }else if(ysum == msum) {
    cout << "Y M" << " " << ysum;
  }
}