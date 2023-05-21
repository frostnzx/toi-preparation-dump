#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 1e5+5 ;

vector<pii> G[N] ;

ll n , m ;
ll dist[2][N] ;

priority_queue<i3 , vector<i3> , greater<i3>> pq ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1;i<=m;i++){
        ll u , v , w ;
        cin >> u >> v >> w ;
        G[u].push_back({v , w}) ;
    }
    for(int i=1;i<=n;i++){
        dist[0][i] = 1e18 ;
        dist[1][i] = 1e18 ;
    }

    dist[0][1] = 0 ;
    pq.push({dist[0][1] , 1 , 0});

    while(!pq.empty()){
        auto [d , u , used] = pq.top(); pq.pop();
        if(d > dist[used][u]){
            continue;
        }
        for(auto [v , w] : G[u]){
            if(dist[used][u] + w < dist[used][v]){
                dist[used][v] = dist[used][u] + w ;
                pq.push({dist[used][v] , v , used});
            }
            if(used == 0){
                if(dist[used][u] + w/2 < dist[1][v]){
                    dist[1][v] = dist[used][u] + w/2 ;
                    pq.push({dist[1][v] , v , 1});
                }
            }
        }
    }

    cout << min(dist[1][n] , dist[0][n]) ;
}
