#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int sum = 0;
    vector<int> odd;
    
    for(int i=0; i<7; i++){
        int num;
        cin >> num;
        
        if(num % 2 != 0) {
            sum += num;
            odd.push_back(num);
        }
    }
    
    if(odd.size()){
        cout << sum << '\n';
        cout << *min_element(odd.begin(), odd.end()) << '\n';
    }else {
        cout << -1;
    }
}