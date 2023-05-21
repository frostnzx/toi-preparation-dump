#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 5005 ;

ll n , m , dist[N] ;
bool cycle[N] , vis[N] ;

vector<i3> G ;
vector<int> BE[N] ;

bool dfs(int u , bool reach_1 , bool reach_cycle){
    vis[u] = true ;
    if(u == 1) {
        reach_1 = true ;
    }
    if(cycle[u]){
        reach_cycle = true ;
    }
    if(reach_1 && reach_cycle){
        return true ;
    }
    for(auto v : BE[u]){
        if(vis[v]) continue ;
        if(dfs(v , reach_1 , reach_cycle)) {
            return true ;
        }
    }
    return false ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1;i<=m;i++){
        ll u , v , w ;
        cin >> u >> v >> w ;
        G.push_back({u , v , -w}); // -1 * w
        BE[v].push_back(u); // store back edge
    }
    if(m == 1){
        cout << -1 * get<2>(G[0]) ;
        return 0 ;
    }

    for(int i=1;i<=n;i++){
        dist[i] = 1e18 ;
    }
    dist[1] = 0 ;

    // cal max dist 1 -> n

    for(int i=1;i<=n-1;i++){
        for(auto [u , v , w] : G){
            if(dist[u] + w < dist[v]){
                if(i == n-1){
                    cycle[v] = cycle[u] = true ; // marked relaxed
                }
                dist[v] = dist[u] + w ;
            }
        }
    }

    // check if n can reach cycle and then go to 1 (if can reach then min dist is from cycle)
    if(dfs(n , 0 , 0)){
        cout << -1 ;
    }
    else{
        cout << -dist[n] ;
    }
}
