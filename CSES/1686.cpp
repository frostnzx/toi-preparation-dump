#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 1e5+5 ;

ll n , m , coins[N] , disc[N] , low[N] , d , scc[N] , scc_cnt , scc_coins[N];
ll dp[N] ;
bool vis[N] ;
vector<int> G[N] , G2[N] ;

stack<int> st ;

void tarjan(int u){
    low[u] = disc[u] = ++d ;

    st.push(u);
    vis[u] = true ;

    for(int v : G[u]){
        if(!disc[v]){
            tarjan(v);
            low[u] = min(low[u] , low[v]) ;
        }
        else { // back edge
            if(vis[v])
                low[u] = min(low[u] , disc[v]);
        }
    }

    if(low[u] == disc[u]){
        ++scc_cnt ;
        while(st.top() != u){
            int now = st.top() ; st.pop();
            scc[now] = scc_cnt ;
            vis[now] = false ;
        }
        st.pop();
        scc[u] = scc_cnt ;
        vis[u] = false ;
    }
}

ll solve(int u){
    if(G2[u].empty()){
        return dp[u] = scc_coins[u] ;
    }
    if(dp[u] != -1){
        return dp[u] ;
    }
    dp[u] = scc_coins[u] ;
    for(int back_edge : G2[u]){
        dp[u] = max(dp[u] , solve(back_edge) + scc_coins[u]) ;
    }
    return dp[u] ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1;i<=n;i++){
        cin >> coins[i] ;
    }
    for(int i=1;i<=m;i++){
        ll u , v , w ;
        cin >> u >> v ;
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(disc[i] == 0){
            tarjan(i);
        }
    }
    // build SCC graph
    for(int u=1;u<=n;u++){
        for(int v : G[u]){
            if(scc[u] != scc[v]){
                G2[scc[v]].push_back(scc[u]) ;
            }
        }
    }
    for(int i=1;i<=n;i++){
        scc_coins[scc[i]] += coins[i] ;
    }
    memset(dp , -1 , sizeof(dp));

    ll ans = -1e18 ;
    for(int i=1;i<=scc_cnt;i++){
        ans = max(ans , solve(i));
    }

    cout << ans ;
}



// observation :
// we can't just use DFS or BFS and try travel around because we can travel
// to the same node multiple time to maximize the coin
// (but every coin can be collected once so its not infinite cycle)
// but we know that once we entered any SCC we can collect every coin in that SCC
// so we simplify the graph by making each SCC component a node
// and then we want to maximize coin since SCC graph is DAG we can use DP on DAG tech
