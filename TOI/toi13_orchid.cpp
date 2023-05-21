#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+5 ;

int n ;

vector<int> lis ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    for(int i=1 , x;i<=n;i++){
        cin >> x ;
        int it = upper_bound(lis.begin() , lis.end() , x) - lis.begin() ;
        if(it == lis.size()){
            lis.push_back(x) ;
        }
        else {
            lis[it] = x ;
        }
    }
    cout << n - lis.size() ;
}
