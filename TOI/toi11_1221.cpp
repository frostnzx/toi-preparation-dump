#include<bits/stdc++.h>

using namespace std;

using pii = pair<int,int> ; 
const int N = 501 ; 
const int INF = 1e9+7 ; 

int n,m,q,a,b , price[N] ; 
pii dist[N][N] ; 

void solve(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k].first + dist[k][j].first < dist[i][j].first){
                    dist[i][j].first = dist[i][k].first + dist[k][j].first ; 
                    dist[i][j].second = dist[i][k].second + dist[k][j].second ; 
                }
                else if(dist[i][k].first + dist[k][j].first == dist[i][j].first && dist[i][k].second + dist[k][j].second > dist[i][j].second)
                    dist[i][j].second = dist[i][k].second + dist[k][j].second ; 
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q ; 
    for(int i=1;i<=n;i++)
        cin >> price[i] ; 
    
    for(int i=1;i<=n;i++)
        for(int k=1;k<=n;k++)
            if(i == k)
                dist[i][k] = {0 , 0} ;  
            else dist[i][k] = {price[i]+price[k] , 2} ;

    for(int i=1;i<=m;i++){
        int u,v,w ; 
        cin >> u >> v >> w ;
        dist[u][v] = {w,2} ; 
        dist[v][u] = {w,2} ; 
    }

    solve();

    while(q--){
        cin >> a >> b ; 
        cout << dist[a][b].first << " " << dist[a][b].second << "\n" ;
    }
}