#include<bits/stdc++.h>

using namespace std;

const int N = 1005 ;
const int X = 1e5+5 ;

int n , x  , w[N] , v[N] , dp[X] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> x ;
    for(int i=1;i<=n;i++){
        cin >> w[i] ;
    }
    for(int i=1;i<=n;i++){
        cin >> v[i] ;
    }

    for(int i=1;i<=n;i++){
        for(int j=x;j>=0;j--){
            if(j + w[i] <= x)
                dp[j + w[i]] = max(dp[j + w[i]] , dp[j] + v[i]);
        }
    }

    cout << dp[x] ;
}
