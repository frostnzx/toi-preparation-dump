#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll , ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 1e5+5 , M = 1e6+5;
const int MOD = 1e9+7 ;

int n , dp[1005][1005] ;

int solve(int n , int k){
    if(k == 0 || k == n) {
        return 1 ;
    }
    if(dp[n][k] > 0 ) return dp[n][k] ;
    dp[n][k] = (solve(n-1, k-1) % MOD + solve(n-1 , k) % MOD) % MOD ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    while(n--){
        int a , b ;
        cin >> a >> b ;
        cout << solve(a , b) % MOD << "\n" ;
    }
}

