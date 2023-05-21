#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 2505 ;


ll n , m , dist[N] , par[N] ;
vector<i3> Edge ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1;i<=m;i++){
        ll u , v , w ;
        cin >> u >> v >> w ;
        Edge.push_back({u , v , w});
    }
    for(int i=1;i<=n;i++){
        par[i] = i ;
    }

    int start ;
    for(int i=1;i<=n-1;i++){
        start = -1 ;
        for(auto [u , v , w] : Edge){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w ;
                par[v] = u ;
                start = u ; // start at the last relaxed vertex
            }
        }
    }

    if(start == -1){
        cout << "NO" ;
    }
    else {
        for(int i=1;i<=n - 1;i++){ // trace back to negative cycle
            start = par[start] ;
        }
        vector<int> cycle ;
        for(int v = start ; ; v = par[v]){
            cycle.push_back(v);
            if(v == start && cycle.size() > 1){
                break;
            }
        }
        reverse(cycle.begin() , cycle.end());

        cout << "YES\n" ;
        for(int x : cycle){
            cout << x << " " ;
        }
    }
}
