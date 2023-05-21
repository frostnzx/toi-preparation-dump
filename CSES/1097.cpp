#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

const int N = 5005 ;

ll n , val[N] , dp[N][N] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    for(int i=1;i<=n;i++){
        cin >> val[i] ;
    }

    // max score for both player

    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++){
            ll round = (i - 1) + (n - j) + 1 ;
            if(j < i){
                continue;
            }
            if(i == j){
                if(round % 2){
                    dp[i][j] = val[i] ;
                }
                continue ;
            }
            if(round % 2){ // round of first player
                dp[i][j] = max(dp[i+1][j] + val[i] , dp[i][j-1] + val[j]) ;
            }
            else { // round of second player
                dp[i][j] = min(dp[i+1][j] , dp[i][j-1]) ;
                // when in second player round
                // choose worst way for first player
                // in order to get himself best possible value
            }
        }
    }

    cout << dp[1][n] ;
}
