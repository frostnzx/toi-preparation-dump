#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 1e5+5 ;
const int MOD = 1e9+7 ;

ll n , m , dist[N] , mn[N] , mx[N] , cnt[N];
vector<pii> G[N] ;
priority_queue<pii , vector<pii> , greater<pii>> pq ;

// not multi state sssp

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1;i<=m;i++){
        ll u , v , w ;
        cin >> u >> v >> w ;
        G[u].push_back({v , w});
    }
    for(int i=1;i<=n;i++){
        dist[i] = 1e18 ;
        mn[i] = 0 ;
        mx[i] = 0 ;
        cnt[i] = 0 ;
    }

    dist[1] = 0 ;
    cnt[1] = 1 ;
    pq.push({dist[1] , 1});
    while(!pq.empty()){
        auto[d , u] = pq.top(); pq.pop();
        if(d > dist[u]){
            continue ;
        }
        for(auto [v , w] : G[u]){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w ;
                mn[v] = mn[u] + 1 ;
                mx[v] = mx[u] + 1 ;
                cnt[v] = cnt[u] % MOD ;

                pq.push({dist[v] , v});
            }
            else if(dist[u] + w == dist[v]){
                mn[v] = min(mn[v] , mn[u] + 1) ;
                mx[v] = max(mx[v] , mx[u] + 1) ;
                cnt[v] = (cnt[u]%MOD + cnt[v]%MOD) % MOD ;
            }
        }
    }

    cout << dist[n] << " " << cnt[n]%MOD << " " << mn[n] << " " << mx[n] ;
}

