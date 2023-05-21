#include<bits/stdc++.h>

using namespace std;

using ll = unsigned long long int ;
using pii = pair<ll,ll> ; 


int n,m ; 
const int N = 1e5+5 ; 
const ll INF = 1e18 ; 

vector<pii> G[N] ; 
ll dist[N] ; 
priority_queue<pii,vector<pii>,greater<pii>> pq ; 
bool vis[N] ; 

void solve(){
    fill(dist,dist+n+1,INF) ; 

    dist[1] = 0 ; 
    pq.push({dist[1] , 1}) ; 
    while(!pq.empty()){
        int u = pq.top().second ; 
        pq.pop() ; 
        if(vis[u])
            continue;
        vis[u] = true ; 
        for(auto vw : G[u]){
            int v = vw.first ; 
            ll w = vw.second ; 
            if(!vis[v] && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w ; 
                pq.push({dist[v] , v});
            }
        }
    }

    for(int i=1;i<=n;i++)
        cout << dist[i] << " " ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ; 

    int u,v ; 
    ll w ;  
    for(int i=1;i<=m;i++){
        cin >> u >> v >> w ; 
        G[u].push_back({v,w});
    }

    solve();
}