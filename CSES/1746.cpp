#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

const int N = 1e5+5 ;
const int MOD = 1e9+7 ;

ll n , m , v[N] , dp[N][105] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1;i<=n;i++){
        cin >> v[i] ;
    }

    for(int i=1;i<=n;i++){
        if(i == 1){
            if(v[i] == 0){
                for(int j=1;j<=m;j++){
                    dp[i][j] = 1 ;
                }
            }
            else {
                dp[i][v[i]] = 1 ;
            }
            continue;
        }

        if(v[i] != 0){
            for(int j=v[i]-1;j<=v[i]+1;j++){
                dp[i][v[i]] = (dp[i][v[i]] + dp[i-1][j]) % MOD ;
            }
            continue;
        }
        for(int j=1;j<=m;j++){
            if(v[i-1] != 0 && abs(j - v[i-1]) > 1){
                continue;
            }
            if(v[i+1] != 0 && abs(j - v[i+1]) > 1){
                continue;
            }
            dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1]) % MOD ;
        }
    }


    ll ans = 0 ;
    for(int i=1;i<=m;i++){
        ans = (ans + dp[n][i]) % MOD ;
    }

    cout << ans % MOD ;
}
