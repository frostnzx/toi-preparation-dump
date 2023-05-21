#include<bits/stdc++.h>

using namespace std;

const int N = 3e4+5 ;

int n , k , v[N] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k ;

    for(int i=1;i<=n;i++){
        cin >> v[i] ;
    }

    int ans = -1e9  ;
    for(int i=1;i<=n;i++){
        int ed = upper_bound(v+1 , v+n+1 , v[i] + k) - v -1 ;
        ans = max(ans , ed-i) ;
    }

    cout << ans ;
}
