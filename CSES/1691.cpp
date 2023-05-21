#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 1e5+5 ;

// Euler circuit (undirected)
// use adjacency list as set if undirected
// Hierholzer's algorithm

int n , m ;
set<int> G[N] ;

vector<int> ans ;

void dfs(int u){
    while(!G[u].empty()){
        int now = *G[u].begin() ;

        G[now].erase(u) , G[u].erase(now) ;
        dfs(now) ;
    }
    ans.push_back(u);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1;i<=m;i++){
        ll u , v ;
        cin >> u >> v ;
        G[u].insert(v) , G[v].insert(u);
    }
    for(int i=1;i<=n;i++){
        if(G[i].size() % 2) {
            cout << "IMPOSSIBLE" ; return 0 ;
        }
    }
    dfs(1);

    //Check if the printed cycle has sufficient number of edges included or not.
    //If not then the original graph might be disconnected and Euler Path can't exist in this case.
    if(ans.size()-1 != m){
        cout << "IMPOSSIBLE" ; return 0 ;
    }

    reverse(ans.begin() , ans.end());
    for(int i : ans){
        cout << i << " " ;
    }
}

