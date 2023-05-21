#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 1e5+5 ;

vector<pii> G[N] ;

vector<ll> ans ;
ll n , m , k , dist[N][15] , par[N] ;

priority_queue<pii , vector<pii> , greater<pii> > pq ;

// store k-th best path from 1->N

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k ;
    for(int i=1;i<=m;i++){
        ll u , v , w ;
        cin >> u >> v >> w ;
        G[u].push_back({v , w});
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=10;j++){
            dist[i][j] = 1e18 ;
        }
    }

    //dist[N][0]  = the best path , dist[N][1] = second best path

    dist[1][0] = 0 ;
    pq.push({dist[1][0] , 1});

    while(!pq.empty()){
        auto[d , u] = pq.top(); pq.pop();
        if(d > dist[u][k-1]) { // dist[u][k-1] is worse path to u
            // if d is even worse why bother consider?
            continue ;
        }

        for(auto [v , w] : G[u]){
            if(d + w < dist[v][k-1]){
                dist[v][k-1] = d + w ;
                pq.push({dist[v][k-1] , v});
                sort(dist[v] , dist[v] + k) ; // to maintain dist[v][k-1] to be the worst path to v
            }
        }
    }

    for(int i=0;i<k;i++){
        cout << dist[n][i] << " "  ;
    }
}
