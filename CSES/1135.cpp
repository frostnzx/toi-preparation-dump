#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+5 ;
const int mxD = ceil(log2(N)) + 20 ;

int n , q , p[N][mxD] , l , depth[N] ;

vector<int> G[N] ;

void dfs(int u , int par){
    for(int v : G[u]){
        if(v == par){
            continue ;
        }
        depth[v] = depth[u] + 1 ;
        p[v][0] = u ;
        for(int i=1;i<=l;i++){
            p[v][i] = p[p[v][i-1]][i - 1] ;
        }
        dfs(v , u);
    }
}

int lca(int a , int b){
    if(depth[a] < depth[b]){
        swap(a , b) ;
    }
    int dist = depth[a] - depth[b] ;
    for(int i=l-1;i>=0;i--){
        if(dist & (1 << i)){
            if(p[a][i] != 0)
                a = p[a][i] ;
        }
    }
    if(a == b){
        return dist ;
    }
    for(int i=l-1;i>=0;i--){
        if(p[a][i] != p[b][i]){
            a = p[a][i] , b = p[b][i] ;
            dist += (1 << i) * 2 ;
        }
    }
    return dist + 2 ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q ;
    for(int i=1, u , v;i<=n-1;i++){
        cin >> u >> v ;
        G[u].push_back(v) , G[v].push_back(u) ;
    }
    l = ceil(log2(n)) ;
    dfs(1 , 1) ;

    while(q--){
        int a , b ; cin >> a >> b ;
        cout << lca(a,b) << "\n" ;
    }
}
