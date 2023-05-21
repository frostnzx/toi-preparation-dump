#include<bits/stdc++.h>

using namespace std;

const int N = 1e3+5 ;

int n , m , k , G[N][N] , qs[N][N] , ans = -1e9 ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k ;
    k--;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> G[i][j] ;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            qs[i][j] = qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1] + G[i][j] ;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int a = qs[i][j] - qs[max(1 , i-k)-1][j] - qs[i][max(1 , j-k)-1] + qs[max(1,i-k)-1][max(1,j-k)-1] ;
            ans = max(ans , a) ;
        }
    }

    cout << ans ;
}

