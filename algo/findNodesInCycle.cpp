#include<bits/stdc++.h>
#define DEBUG 0

using namespace std;

using ll = long long ;
using pii = pair<ll , ll> ;
using i3 = tuple<ll , ll , ll> ;


const int N = 1e5+5 ;

ll n , m , U[N] , V[N] ;

bitset<N> vis , cycle ;
vector<int> G[N] ;

bool dfs1(int u , int p){
    if(vis[u]) {
        return cycle[u] = true ;
    }
    vis[u] = true ;
    for(int v : G[u]){
        if(v == p){
            continue ;
        }

        if(dfs1(v , u)){
            if(cycle[u]) return false ;
            else return cycle[u] = true ;
        }
    }
    return false ;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;

    for(int i=1;i<=m;i++){
        cin >> U[i] >> V[i]  ;
        G[U[i]].push_back(V[i]) , G[V[i]].push_back(U[i]) ;
    }

    dfs1(1 , -1);
}

