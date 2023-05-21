#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 1e5+5 ;

int n , m , dp[N] , p[N] ;
bool vis[N] ;
vector<int> G[N] ;

//DP on DAG

void solve(int u){
    vis[u] = true ;
    for(int v : G[u]){
        if(!vis[v]){
            solve(v);
        }
        if(dp[v] != -1 && dp[v] + 1 > dp[u]){
            dp[u] = dp[v] + 1 ;
            p[u] = v ;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1;i<=m;i++){
        int u , v , w ;
        cin >> u >> v ;
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        p[i] = i ;
        dp[i] = -1 ;
    }
    dp[n] = 1 ;
    solve(1);

    if(dp[1] == -1){
        cout << "IMPOSSIBLE" ;
    }
    else {
        cout << dp[1] << "\n" ;
        for(int i=1;;i = p[i]){
            cout << i << " " ;
            if(i == n) break;
        }
    }
}

//alter sol : dijkstra all weight * -1
