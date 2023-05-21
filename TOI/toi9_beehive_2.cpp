#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll , ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 1005 ;
const int MOD = 1e9+7 ;

int n , m , G[N][N] , dp[N][N] , dp2[N][N] ;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> G[i][j] ;
        }
    }

    for(int i=1;i<=m;i++){
        dp[n][i] = G[n][i] ;
        dp2[n][i] = 1 ;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=m;j++){
            if(i%2){ // odd
                if(dp[i+1][j] + G[i][j] > dp[i][j]){
                    dp[i][j] = dp[i+1][j] + G[i][j] ;
                    dp2[i][j] = dp2[i+1][j] ;
                }
                else if(dp[i+1][j] + G[i][j] == dp[i][j]){
                    dp2[i][j] += dp2[i+1][j] ;
                }
                if(j != 1) {
                    if(dp[i+1][j-1] + G[i][j] > dp[i][j]){
                        dp[i][j] = dp[i+1][j-1] + G[i][j] ;
                        dp2[i][j] = dp2[i+1][j-1] ;
                    }
                    else if(dp[i+1][j-1] + G[i][j] == dp[i][j]){
                        dp2[i][j] += dp2[i+1][j-1] ;
                    }
                }
            }
            else {
                if(dp[i+1][j] + G[i][j] > dp[i][j]){
                    dp[i][j] = dp[i+1][j] + G[i][j] ;
                    dp2[i][j] = dp2[i+1][j] ;
                }
                else if(dp[i+1][j] + G[i][j] == dp[i][j]){
                    dp2[i][j] += dp2[i+1][j] ;
                }
                if(j != m){
                    if(dp[i+1][j+1] + G[i][j] > dp[i][j]){
                        dp[i][j] = dp[i+1][j+1] + G[i][j] ;
                        dp2[i][j] = dp2[i+1][j+1] ;
                    }
                    else if(dp[i+1][j+1] + G[i][j] == dp[i][j]){
                        dp2[i][j] += dp2[i+1][j+1] ;
                    }
                }
            }
        }
    }

    int ans , cnt ;
    for(int i=1;i<=m;i++){
        if(dp[1][ans] < dp[1][i]){
            ans = i ;
        }
    }
    for(int i=1;i<=m;i++){
        if(dp[1][ans] == dp[1][i]){
            cnt += dp2[1][i] ;
        }
    }

    cout << dp[1][ans] << " " << cnt ;
}

