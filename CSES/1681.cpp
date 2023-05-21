#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 1e5+5 ;
const int MOD = 1e9+7 ;

ll n , m , dp[N] ;
bool vis[N] ;

vector<int> G[N] ;

ll solve(int u){
    vis[u] = true ;
    for(int bk : G[u]){
        if(!vis[bk]) {
            solve(bk) ;
        }
        if(dp[bk] != -1){
            if(dp[u] == -1) dp[u] = 0 ;
            dp[u] = (dp[u] + dp[bk]) % MOD;
        }
    }
    return dp[u] ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1;i<=m;i++){
        ll u , v ;
        cin >> u >> v ;
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        dp[i] = -1 ;
    }
    dp[1] = 1 ;
    solve(n);

    if(dp[n] == -1){ // no path between 1->n
        dp[n] = 0 ;
    }
    cout << dp[n] % MOD ;
}

