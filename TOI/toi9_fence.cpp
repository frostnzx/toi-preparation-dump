#include<bits/stdc++.h>

using namespace std;

const int N = 505 ;

int q = 2 , n , m , t , G[N][N] , qsR[N][N] , qsC[N][N] ;

void solve(){
    memset(G , 0 , sizeof(G)) ;
    memset(qsR , 0 , sizeof(qsR));
    memset(qsC , 0 , sizeof(qsC));
    int ans = -1e9 ;

    cin >> n >> m >> t ;
    for(int i=1 , y , x;i<=t;i++){
        cin >> y >> x ;
        G[y+1][x+1] = 1 ;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            qsR[i][j] += qsR[i][j-1] + G[i][j] ;
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            qsC[i][j] += qsC[i-1][j] + G[i][j] ;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int sz = 1 ; // start from size 2x2
            while(i+sz <= n && j+sz <= m){
                int sum = 0 ;
                sum += qsR[i][j+sz] - qsR[i][j-1] ;
                sum += qsR[i+sz][j+sz] - qsR[i+sz][j-1] ;
                sum += qsC[i+sz][j] - qsC[i-1][j] ;
                sum += qsC[i+sz][j+sz] - qsC[i-1][j+sz] ;

                if(sum == 0){
                    ans = max(ans , sz+1) ;
                }
                sz++;
            }
        }
    }
    cout << ans << "\n" ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(q--){
        solve();
    }
}

