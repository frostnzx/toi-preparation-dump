#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

// 1....n sum up to be n(n+1)/2
// so each half of subset should be n(n+1)/4
// just count ways to make n(n+1)/4 and the other number that
// we did not select should be other half

const int N = 250005 ;
const int MOD = 1e9+7 ;

ll n , val , dp[505][N] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    val = (n*(n+1))/4 ;

    for(int i=1;i<=n;i++){ // each number
        dp[i][0] = 1 ;
        for(int j=1;j<=val;j++){
            dp[i][j] = dp[i-1][j] % MOD ;
            if(j - i >= 0){
                dp[i][j] = (dp[i][j] + dp[i-1][j - i]) % MOD ;
            }
        }
    }
    if(n*(n+1) % 4){
        cout << "0" ;
    }
    else cout << dp[n][val] % MOD ;
}
