#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

const int N = 1e6+5 ;
const int MOD = 1e9+7 ;

ll q , dp[N][2] ;
//dp(i , ty) , ty-1 -> brick on i is connect
//             ty-2 -> brick on i isn't connect

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    dp[1][0] = 1 , dp[1][1] = 1 ;

    for(int i=2;i<N;i++){
        dp[i][0] = ((2 * dp[i-1][0])%MOD + dp[i-1][1])%MOD ;
        dp[i][1] = ((4 * dp[i-1][1])%MOD + dp[i-1][0])%MOD ;

        dp[i][0] %= MOD ;
        dp[i][1] %= MOD ;
    }

    cin >> q ;
    while(q--){
        int x ; cin >> x ;
        ll ans = (dp[x][0] + dp[x][1]) % MOD ;

        cout << ans << "\n" ;
    }
}
