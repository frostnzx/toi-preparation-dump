#include<bits/stdc++.h>

using namespace std;

using ll = unsigned long long int ;

const int N = 550 ;
const ll INF = 1e18 ; 

int n,m,q ; 

ll dist[N][N] ; 

void solve(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]) ; 
            }
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0); 

    cin >> n >> m >> q ; 

    for(int i=1;i<=n;i++)
        for(int k=1;k<=n;k++)
            if(i == k)
                dist[i][k] = 0 ;
            else dist[i][k] = INF ;  

    for(int i=1;i<=m;i++){
        int u,v ; 
        ll w ; 
        cin >> u >> v >> w ; 
        dist[u][v] = min(dist[u][v] , w) ; 
        dist[v][u] = min(dist[u][v] , w) ; 
    }

    solve();

    while(q--){
        int a,b ; cin >> a >> b ; 
        if(dist[a][b] == INF)
            cout << "-1\n" ; 
        else cout << dist[a][b] << "\n" ; 
    }
}