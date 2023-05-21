#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

const int N = 1e6+5 ;
const int MOD = 1e9+7 ;

ll n , dp[N] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    dp[0] = 1 ;
    for(int i=0;i<=n;i++){
        for(int c=1;c<=6;c++){
            if(i + c <= n)
                dp[i + c] = (dp[i+c] + dp[i]) % MOD ;
        }
    }

    cout << dp[n] % MOD;
}
