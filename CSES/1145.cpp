#include<bits/stdc++.h>

using namespace std;

vector<int> lis ;

int n ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    for(int i=1 , x;i<=n;i++){
        cin >> x ;
        int idx = lower_bound(lis.begin() , lis.end() , x) - lis.begin() ;
        if(idx == lis.size()){
            lis.push_back(x);
        }
        else lis[idx] = x ;
    }

    cout << lis.size() ;
}

// increasing only use lower_bound
// equal or increasing use upper_bound
