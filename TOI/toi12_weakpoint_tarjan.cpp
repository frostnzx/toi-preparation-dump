#include<bits/stdc++.h>

using namespace std;

using pii = pair<int,int> ;

const int N = 5e5+5 ;

int n, m , low[N] , disc[N] , t , ans[N];

bool vis[N] ;

vector<int> G[N] ;

set<pii> ap ;

void dfs(int u , int p){
    low[u] = disc[u] = ++t ;

    vis[u] = true ;

    int ap_child = 0 ;
    bool isap = false ;

    for(int v : G[u]){
        if(v == p)continue;
        if(!vis[v]){ // tree edge
            dfs(v , u) ;
            ans[u] += ans[v] + 1 ;

            low[u] = min(low[u] , low[v]);

            if(p != 0 && low[v] >= disc[u]){
                isap = true ;
                ap_child += ans[v] + 1 ; // only count if u is ap for v
            }
        }
        else { // back edge
            low[u] = min(low[u] , disc[v]);
        }
    }

    if(isap){
        ap.insert({u , ap_child});
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1 , u , v;i<=n;i++){
        cin >> u >> v ;
        G[u].push_back(v) , G[v].push_back(u) ;
    }

    dfs(m , 0);

    if(ap.empty()){
        int ans ;
        for(int i=1;i<=n;i++){
            if(i != m){
                ans = i ;
                break;
            }
        }

        cout << ans << "\n0" ;
        return 0 ;
    }

    int idx , mx = -1e9 ;
    for(auto [x , y] : ap){
        if(x == m) continue;
        if(y > mx){
            mx = y , idx = x ;
        }
    }

    cout << idx << "\n" << mx ;
}
