#include<bits/stdc++.h>

using namespace std;

using pii = pair<int,int> ; 
using ll = long long ; 
using iiii = tuple<ll , int , int ,int > ; 

const int N = 110 ; 
const ll INF = 1e18+7 ; 

int n,m,s,a,b,f ; 

vector<pii> G[N] ; 
ll dist[N][2][N] , p[N];
bool vis[N][2][N] ;  
priority_queue<iiii ,vector<iiii> , greater<iiii>> pq ; 

void solve(){
    for(int i=1;i<=n;i++)
        for(int k=0;k<2;k++)
            for(int j=0;j<=f;j++)
                dist[i][k][j] = INF ; 
    dist[a][0][0] = 0 ; 
    pq.push({dist[a][0][0] , a , 0 , 0});
    while(!pq.empty()){
        int wu , u , gift , fuel ; tie(wu,u,gift,fuel) = pq.top();

        //cout << "wu = " << wu << " u = " << u << " gift = " << gift << " fuel = " << fuel << "\n" ; 
        pq.pop();
        if(vis[u][gift][fuel])
            continue;
        vis[u][gift][fuel] = true ; 
        if(u == b){
            int w = (f-fuel)*p[u] ; 
            if(dist[u][gift][fuel] + w < dist[u][gift][f])
                dist[u][gift][f] = dist[u][gift][fuel] + w ; 
            if(!gift && dist[u][gift][fuel] < dist[u][1][f])
                dist[u][1][f] = dist[u][gift][fuel] ; 
        }
        for(auto vw : G[u]){
            int v,w ; tie(v,w) = vw ; 
            int nfuel ; 
            for(int i=0;i<=f-fuel;i++){
                nfuel = (fuel+i)-w ; 
                if(nfuel < 0) continue;
                if(!vis[v][gift][nfuel] && dist[u][gift][fuel] + (i*p[u]) < dist[v][gift][nfuel]){
                    dist[v][gift][nfuel] = dist[u][gift][fuel] + (i*p[u]) ; 
                    pq.push({dist[v][gift][nfuel] , v , gift , nfuel});
                }
            }
            nfuel = (f-w) ; 
            if(!gift && !vis[v][1][nfuel] && dist[u][gift][fuel] < dist[v][1][nfuel]){
                dist[v][1][nfuel] = dist[u][gift][fuel] ; 
                pq.push({dist[v][1][nfuel] , v , 1 , nfuel});
            }
        }
    }

    cout << min(dist[b][0][f] , dist[b][1][f]) ; 

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    for(int i=1;i<=n;i++)
        cin >> p[i];
    cin >> a >> b >> f >> m ; 
    for(int i=1;i<=m;i++){
        int u,v,w ; cin >> u >> v >> w ; 
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }

    solve();
}