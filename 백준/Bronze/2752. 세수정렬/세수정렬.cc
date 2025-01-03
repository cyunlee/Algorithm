#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int a, b, c;
    vector<int> v;
    
    cin >> a >> b >> c;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    
    sort(v.begin(), v.end());
    
    for(int x : v) {
        cout << x << ' ';
    }
}