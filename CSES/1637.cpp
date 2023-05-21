#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+5 ;

int n , dp[N] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;

    dp[0] = 0 ;
    for(int i=1;i<=n;i++){
        int sz = 0 , x  = i ; while(x != 0){sz++ , x/=10;}

        dp[i] = 1e9 ;
        for(int j = 0 , p = 10 ; j < sz ; j++ , p*=10){
            int now = (i - ((i%p)/(p/10))) ;
            if(now >= 0){
                dp[i] = min(dp[i] , dp[now] + 1) ;
            }
        }
    }

    cout << dp[n] ;
}
