#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+5 ; 
const int INF = 1e9+7 ;

int n,m , p[N] ; 
map<int,int> mp ; 

int root(int u){
    if(p[u] == u){
        return u ; 
    }
    else return p[u] = root(p[u]) ; 
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ; 

    for(int i=1;i<=n;i++)
        p[i] = i  , mp[i] = 1;

    int cmp = n , ans = -INF ;
    while(m--){
        int u,v ; 
        cin >> u >> v ; 
        int pu = root(u) , pv = root(v) ;
        if(pu == pv){
            cout << cmp << " " << ans << "\n" ; 
            continue;
        }

        p[pu] = p[pv] ; 
        mp[pu] += mp[pv];
        mp[pv] = mp[pu] ;
        ans = max(ans , mp[pu]) ; 
        cmp--;
        cout << cmp << " " << ans << "\n" ; 
    }
}