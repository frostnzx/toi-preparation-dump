#include<bits/stdc++.h>

using namespace std;

const int N = 2005 ;

using ll = long long ;

ll n , m , k , G[N][N] , qsR[N][N] , ans = -1e9 ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> G[i][j] ;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            qsR[i][j] = qsR[i][j-1] + G[i][j] ;
        }
    }

    for(int i=k;i<=n;i++){
        for(int j=k;j<=m;j++){
            ll c = 0 , s1 = 0 , s2 = 0 ;
            while(c < k){
                s1 += qsR[i-c][j-c] - qsR[i-c][j-k] ;
                s2 += qsR[i-c][j] - qsR[i-c][j-k+c] ;
                c++;
            }
            ans = max(ans , max(s1 , s2));
        }
    }

    cout << ans ;

}
