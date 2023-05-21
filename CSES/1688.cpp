#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 2e5+5 ;
const int mxD = ceil(log2(N)) ;

int n , q , p[N][mxD + 20] , depth[N] , l ;

vector<int> G[N] ;

void pre_process(int u){
    for(int v : G[u]){
        depth[v] = depth[u] + 1 ;
        p[v][0] = u ;
        for(int i=1;i<=l;i++){
            p[v][i] = p[p[v][i - 1]][i - 1] ;
        }
        pre_process(v);
    }
}

int lca(int a , int b){
    if(depth[a] < depth[b]){
        swap(a , b);
    }
    int dif = depth[a] - depth[b] ;
    for(int i=l;i>=0;i--){
        if(dif & (1 << i)){
            a = p[a][i] ;
        }
    }
    if(a == b) return a ;
    for(int i=l;i>=0;i--){
        if(p[a][i] != p[b][i]){
            a = p[a][i] ;
            b = p[b][i] ;
        }
    }
    return p[a][0] ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q ;
    for(int i=2;i<=n;i++){
        ll x ;
        cin >> x ; G[x].push_back(i) ;
    }
    l = ceil(log2(n)) ;
    pre_process(1);

    while(q--){
        int a , b ;
        cin >> a >> b ;
        cout << lca(a , b) << "\n" ;
    }

}

