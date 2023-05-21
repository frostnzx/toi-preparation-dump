#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 21 ;
const int MOD = 1e9+7 ;

int n , m , dp[N][1 << N] ;
bool vis[N][1 << N] ;
// DP(i , j) = number of way to comes from i to n and passed every bit in J
vector<int> G[N] ;

// not DAG
// observation : N is very low maybe can do bit masking ?

void solve(int u , int bit){
    if(u == n && bit != (1 << (n-1))){
        return ; // optimize if reach n but missing any city just return
    }

    vis[u][bit] = true ;
    for(int v : G[u]){
        if(bit & (1 << (v-1))){
            continue;
        }
        if(!vis[v][bit | (1 << (v-1))]) {
            solve(v , bit | (1 << (v-1))) ;
        }
        dp[u][bit] = (dp[u][bit] + dp[v][bit | (1 << (v-1))]) % MOD ;
    }
    //cout << "u = " << u << " bit = " << bit << " dp[" << u << "][" << bit << "] = " << dp[u][bit] << "\n" ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1;i<=m;i++){
        ll u , v ;
        cin >> u >> v ;
        G[u].push_back(v);
    }
    dp[n][(1 << n) - 1] = 1 ;

    solve(1 , 1) ;

    cout << dp[1][1] % MOD;
}
