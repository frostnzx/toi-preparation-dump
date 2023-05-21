#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

const int N = 1e6+5 ;

int n , dp[N] , v[5] = {1,2,5,15} , p[5] = {500,800,1500,3000};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    dp[0] = 0 ;
    for(int i=1;i<=n;i++){
        dp[i] = 1e9 ;
        for(int j=0;j<5;j++){
            dp[i] = min(dp[i] , dp[max(i-v[j],0)]+ p[j]) ;
        }
    }
    cout << dp[n] ;
}
