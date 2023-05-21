#include<bits/stdc++.h>

using namespace std;

const int N = 1005 ;
const int MOD = 1e9+7 ;

int n , dp[N][N] ;
char G[N][N] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> G[i][j] ;
        }
    }
    dp[1][1] = 1 ;


    if(G[1][1] == '*'){
        cout << "0" ;
        return 0 ;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(G[i][j] == '*'){
                continue;
            }
            if(i-1 >= 1 && G[i-1][j] != '*'){
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD ;
            }
            if(j-1 >= 1 && G[i][j-1] != '*'){
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD ;
            }
        }
    }

    cout << dp[n][n] % MOD ;
}
