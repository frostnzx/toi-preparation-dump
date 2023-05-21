#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 2e5+5 ;

int n , m , dp[N][2] , qs[N];
bool vis[N] ;
vector<int> G[N] ;

void solve(int u , int p){

    vis[u] = true ;

    int child_cnt = 0 ;

    for(int v : G[u]){
        if(v == p) continue ;
        if(vis[v]) continue ;
        solve(v , u);

        child_cnt ++ ;
    }
    if(child_cnt == 0) return ;

    int idx = 1 ;
    for(int v : G[u]){
        if(v == p) continue ;
        qs[idx] = max(dp[v][0] , dp[v][1]) + qs[idx - 1] ;
        idx++;
    }
    dp[u][0] = qs[child_cnt] ;

    idx = 1 ;
    for(int v : G[u]){
        if(v == p) continue ;
        int l = qs[idx-1] , r = qs[child_cnt] - qs[idx] ;
        dp[u][1] = max(dp[u][1] , l + (dp[v][0] + 1) + r) ;
        idx++;
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

    solve(1 , 1);
    cout << max(dp[1][0] , dp[1][1]) ;
}

// if you selected edges that have u , v as an endpoint
// you can no longer select any edge that have u or v as their endpoint anymore
