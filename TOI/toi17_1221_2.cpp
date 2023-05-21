#include<bits/stdc++.h>

#define f first
#define s second

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;

const int N = 550 ;

ll n , m , q , p[N] ;
pii G[N][N] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q ;
    for(int i=1;i<=n;i++){
        cin >> p[i] ;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j) {
                G[i][j] = {p[i] , 1} ;
            }
            else {
                G[i][j] = {p[i] + p[j] , 2} ;
            }
        }
    }
    for(int i=1;i<=m;i++){
        ll u , v , w ;
        cin >> u >> v >> w ;
        G[u][v] = {min(p[u] + p[v] , w) , 2} , G[v][u] = {min(p[u] + p[v] , w) , 2} ;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(G[i][k].f + G[k][j].f < G[i][j].f){
                    G[i][j] = {G[i][k].f + G[k][j].f , G[i][k].s + G[k][j].s} ;
                }
                else if(G[i][k].f + G[k][j].f == G[i][j].f){
                    G[i][j].s = max(G[i][j].s , G[i][k].s + G[k][j].s) ;
                }
            }
        }
    }

    while(q--){
        ll a , b ; cin >> a >> b ;
        cout << G[a][b].f << " " << G[a][b].s << "\n" ;
    }

}
