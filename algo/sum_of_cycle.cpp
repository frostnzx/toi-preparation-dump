#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;

const int N = 5e4+5 ;

ll n , m , ans , cycle_w ;
bitset<N> vis , incy ;

vector<pii> G[N] ;
stack<pii> path ; // node , w

void dfs(int u , int p){
    vis[u] = true ;
    for(auto [v , w] : G[u]){
        if(v == p){
            continue ;
        }
        if(vis[v]){
            if(incy[v]){
                continue ;
            }
            cycle_w += w ;
            incy[u] = true ;
            while(!path.empty()){
                auto[f , s] = path.top();
                cycle_w += s ;
                incy[f] = true ;

                path.pop();
                if(f == v)break;
            }
        }
        else {
            path.push({u , w}) ;
            dfs(v , u);
            if(!path.empty()){
                path.pop();
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n ;

    for(int i=1 , u , v , w;i<=m;i++){
        cin >> u >> v >> w ;
        G[u].push_back({v , w}) , G[v].push_back({u , w});
        ans += w ;
    }
    dfs(0 , 0);

    cout << ans * 2 - cycle_w ;
}


//toi16_watertruck
