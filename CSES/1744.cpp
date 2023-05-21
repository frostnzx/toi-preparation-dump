#include<bits/stdc++.h>

using namespace std;

const int N = 505 ;

int a , b , dp[N][N] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> a >> b ;

    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i == j){
                continue ;
            }
            if(i == 1){
                dp[i][j] = j - 1 ;
                continue ;
            }
            if(j == 1){
                dp[i][j] = i - 1 ;
                continue ;
            }

            dp[i][j] = 1e9 ;
            for(int x = 1 ; x < i ; x++){
                dp[i][j] = min(dp[i][j] , dp[x][j] + dp[i - x][j] + 1);
            }
            for(int x = 1 ; x < j ; x++){
                dp[i][j] = min(dp[i][j] , dp[i][x] + dp[i][j - x] + 1);
            }
        }
    }

    cout << dp[a][b] ;
}
