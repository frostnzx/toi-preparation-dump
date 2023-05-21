#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

const int N = 1e6+5 ;
const int MOD = 1e9+7 ;

ll n , m , dp[N] , v[105] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1;i<=n;i++){
        cin >> v[i] ;
    }

    dp[0] = 1 ;
    for(int i=0;i<=m;i++){
        for(int j=1;j<=n;j++){
            ll c = v[j] ;
            if(i + c <= m)
                dp[i + c] = (dp[i+c] + dp[i]) % MOD ;
        }
    }

    cout << dp[m] % MOD;
}
