#include<bits/stdc++.h>

using namespace std;

using pii = pair<int,int> ;

const int N = 405 ;

int q , k , v[N] , n ;
pii dp[N][N] ;

int main(){
    cin >> q >> k ;
    while(q--){
        cin >> n ;
        for(int i=1;i<=n;i++){
            cin >> v[i] ;
        }

        for(int z=1;z<=n;z++){
            for(int l=1;l<n-z+1;l++){
                int r = l+z-1 ;
                if(z == 1){
                    dp[l][r] = {1 , 1} ;
                    continue ;
                }
                dp[l][r] = {dp[l+1][r].first + 1 , 1} ; // if we don't match v[l] with any v[x]
                // just remove v[l] alone and then remove v[l+1 , r] after
                // and second will be 1 because we remove v[l] independently then it will be 1st time we remove it
                for(int x=l+1;x<=r;x++){
                    if(v[l] == v[x] && dp[x][r].second < k){
                        pii tmp = {dp[l+1][x-1].first + dp[x][r].first , dp[l][x].second + 1} ;
                        dp[l][r] = min(dp[l][r] , tmp) ;
                    }
                }
            }
        }
        cout << "f = " << dp[1][n].first << " s = " << dp[1][n].second << "\n" ;
    }
}
