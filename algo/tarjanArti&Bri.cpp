#include<bits/stdc++.h>

using namespace std;

using pii = pair<int,int> ;

const int N = 1e5+5 ;

int n , m , t , low[N] , disc[N] ;
bool vis[N] ;
vector<int> G[N] ;

set<int> ap ;
set<pii> bd ;

void dfs(int u , int p){
    low[u] = disc[u] = ++t ;

    vis[u] = true ;
    int child = 0 ;

    for(int v : G[u]){
        if(v == p)continue;
        if(!vis[v]){ // tree edge
            ++child ;
            dfs(v , u) ;
            low[u] = min(low[u] , low[v]);

            if((p != 0 && low[v] >= disc[u]) || (p == 0 && child > 1)){
                ap.insert(u) ;
            }
            if(low[v] > disc[u]){
                bd.insert({u , v});
            }
        }
        else { // back edge
            low[u] = min(low[u] , disc[v]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1 , u , v;i<=m;i++){
        cin >> u >> v ;
        G[u].push_back(v) ;
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i , 0);
        }
    }
}

