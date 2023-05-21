#include<bits/stdc++.h>

using namespace std;

const int N = 1005 ;

int dp[N][N] , n ;
char v[N] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    for(int i=1;i<=n;i++){
        cin >> v[i] ;
    }

    for(int z=1;z<=n;z++){
        for(int l=1;l<=n-z+1;l++){
            int r = l+z-1 ;
            if(z == 1){
                dp[l][r] = 0 ;
                continue ;
            }
            dp[l][r] = dp[l][r-1] ; // if v[r] not matching any card in V(l ... r)
            for(int x=l;x<r;x++){
                if(v[x] == v[r]){
                    dp[l][r] = max(dp[l][r] , dp[l][x-1] + dp[x+1][r-1] + 1) ;
                }
            }
        }
    }
    cout << dp[1][n] ;
}
