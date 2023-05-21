#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 1e5+5 ;

// Euler path ( directed )
// condition not the same as undirected

// Hierholzer's algorithm

int n , m , in[N] , out[N];
vector<int> G[N] ;

vector<int> ans ;

void dfs(int u){
    while(!G[u].empty()){
        int now = G[u].back();
        G[u].pop_back(); // if directed only pop u
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
        G[u].push_back(v) ;

        in[v]++ , out[u]++ ;
    }
    // start node need to have extra 1 outgoing edge
    // end node need to have 1 extra incoming edge
    // if not have no Eulerian path that start from start and
    // end at end
    if(out[1] - in[1] != 1 || in[n] - out[n] != 1){
        cout << "IMPOSSIBLE" ; return 0 ;
    }
    // if any other node have extra edge then no path
    for(int i=2;i<n;i++){
        if(in[i] != out[i]) {
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


// https://www.topcoder.com/thrive/articles/eulerian-path-and-circuit-in-graphs

//https://usaco.guide/problem-solutions/
