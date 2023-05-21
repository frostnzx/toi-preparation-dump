#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

const int N = 1e6+5 ;
const int MOD = 1e9+7 ;


int n , m , v[105] , dp[105][N] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1;i<=n;i++){
        cin >> v[i] ;
    }


    for(int i=1;i<=n;i++){
        dp[i][0] = 1 ;
        for(int j=1;j<=m;j++){
            if(j - v[i] >= 0)
                dp[i][j] += dp[i][j - v[i]] % MOD ;
            dp[i][j] += dp[i-1][j] % MOD ;
        }
    }

    cout << dp[n][m] % MOD ;
}
