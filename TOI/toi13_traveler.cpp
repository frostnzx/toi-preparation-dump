#include<bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 1e5+5 ; 
const ll INF = 1e18+7 ; 

ll n,m , x,y,z ; 

using pii = pair<ll,ll> ;

vector<pii> G[N] ; 
ll distx[N] , disty[N] ; 
priority_queue<pii,vector<pii>,greater<pii>> pq ; 

void solve(ll st , ll dist[N]){
    for(int i=0;i<=n;i++)
        dist[i] = INF ; 
    bool vis[N] = {false} ; 

    dist[st] = 0 ; 
    pq.push({dist[st] , st});
    while(!pq.empty()){
        ll u = pq.top().second ; 
        pq.pop();

        if(vis[u])
            continue;
        vis[u] = true ; 

        for(auto vw : G[u]){
            ll v = vw.first , w = vw.second ; 
            if(!vis[v] && dist[u] + w < dist[v]){
                dist[v] = dist[u]+w ; 
                pq.push({dist[v] , v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> x >> y >> z ; 
     
    for(int i=0;i<m;i++){
        ll u,v,w ; cin >> u >> v >> w ; 
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }

    solve(x,distx);
    if(distx[y] <= z){
        cout << y <<  " " << distx[y] << " " << "0" ;
    }
    else {
        solve(y,disty);

        ll ans , wans ; 
        for(int i=0;i<n;i++){
            if(i == y)
                continue;
            if(distx[i] <= z && disty[i] < wans)
                ans = i , wans = disty[i] ; 
        }
        cout << ans << " " << distx[ans] << " " << disty[ans] ; 
    }
}