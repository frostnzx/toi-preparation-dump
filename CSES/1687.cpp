#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 2e5+5 ;

const int MXD = ceil(log2(N)) ;

int n , q , p[N][MXD] ;

int query(int u , int dist){
    for(int i=MXD;i>=0;i--){
        if(dist & (1 << i)){
            u = p[u][i];
        }
    }
    if(u == 0) u = -1 ;
    return u ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q ;
    for(int i=2;i<=n;i++){
        cin >> p[i][0] ;
    }

    for(int d=1;d<MXD;d++){
        for(int i=1;i<=n;i++){
            p[i][d] = p[p[i][d-1]][d - 1] ;
        }
    }

    while(q--){
        int u , dist ;
        cin >> u >> dist ;

        cout << query(u , dist) << "\n" ;
    }
}

