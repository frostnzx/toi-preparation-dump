#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 2e5+5 ;

ll n , m , in[N] , desc[N] , ans[N]; // re rooting technique

vector<int> G[N] ;

// calculate descendant (number of nodes in subtree rooting from u)
void dfs1(int u , int p){
    desc[u] = 1 ;
    for(int v : G[u]){
        if(v == p){
            continue ;
        }
        dfs1(v , u) ;
        desc[u] += desc[v] ;
    }
}

// calculate dp in u subtree
void dfs2(int u , int p){
    for(int v : G[u]){
        if(v == p){
            continue ;
        }
        dfs2(v , u);
        in[u] += desc[v] + in[v] ; // (1 * descendant of V) + (in of v)
    }
}

void dfs3(int u , int p){
    ll pv_ans = ans[p] - (in[u] + desc[u]) ; // PV_ANS is answer from p but excluding subtree rooting from u
    if(u == 1) pv_ans = 0 ;

    ans[u] = in[u] + pv_ans + (n - desc[u]);
    // (dis in subtree from u) + (dis from p to all nodes except those in u subtree) + (add edges u -> those nodes from pv_ans)

    for(int v : G[u]){
        if(v == p){
            continue ;
        }
        dfs3(v , u);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    for(int i=1;i<=n-1;i++){
        ll u , v , w ;
        cin >> u >> v ;
        G[u].push_back(v) , G[v].push_back(u) ;
    }

    dfs1(1 , 1);
    dfs2(1 , 1);
    dfs3(1 , 1);

    for(int i=1;i<=n;i++){
        cout << ans[i] << " " ;
    }
}
