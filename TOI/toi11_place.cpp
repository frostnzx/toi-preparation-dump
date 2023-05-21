#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

const int N = 2e5+5 ;

struct Edge {
    int u ,v , w ;

    bool operator<(const Edge &other) const {
        return w > other.w ;
    }
};

int n , m , p[N] ;
ll ans ;

vector<Edge> G ;

int root(int u){
    if(p[u] == u){
        return u ;
    }
    else return p[u] = root(p[u]);
}

int main(){
    ios_base::sync_with_stdio(0);

    cin >> n >> m ;
    for(int i=1 , u , v , w;i<=m;i++){
        cin >> u >> v >> w ;
        G.push_back({u , v , w-1});
    }

    for(int i=1;i<=n;i++){
        p[i] = i ;
    }
    sort(G.begin()  , G.end());

    for(auto [u , v , w] : G){
        int pu = root(p[u]) , pv = root(p[v]) ;
        if(pu == pv){
            continue;
        }
        ans += w ;
        p[pu] = p[pv] ;
    }

    cout << ans ;
}
