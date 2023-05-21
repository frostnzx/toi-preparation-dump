#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll,ll> ;
using i3 = tuple<ll , ll , ll> ;

const int N = 1e5+5 ;

ll n , m , t , low[N] , disc[N] , scc[N] , scc_cnt ;
bool vis[N] ;

vector<int> G[N] ;
stack<int> st ;

void dfs(int u){
    low[u] = disc[u] = ++t ;

    st.push(u);
    vis[u] = true ;
    for(int v : G[u]){
        if(!disc[v]){
            dfs(v);
            low[u] = min(low[u] , low[v]) ;
        }
        else {
            if(vis[v]){
                low[u] = min(low[u] , disc[v]) ;
            }
        }
    }
    if(low[u] == disc[u]){
        scc_cnt++;
        while(st.top() != u){
            int now = st.top(); st.pop();
            vis[now] = false ;
            scc[now] = scc_cnt ;
        }
        vis[u] = false ;
        st.pop();
        scc[u] = scc_cnt ;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1;i<=m;i++){
        ll u , v , w ;
        cin >> u >> v ;
        G[u].push_back(v);
    }

    for(int i=1;i<=n;i++){
        if(!disc[i]){
            dfs(i);
        }
    }

    if(scc_cnt == 1){
        cout << "YES" ;
    }
    else {
        cout << "NO\n" ;
        for(int i=1;i<=n;i++){
            for(int v : G[i]){
                if(scc[i] != scc[v]){ // i can go v but v can't go i
                    cout << v << " " << i ;
                    return 0 ;
                }
                // not including the case where i can't go v and v can't go i
            }
        }
        // if there's a pair which u can't go v and v can't go u either
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(scc[i] != scc[j]){
                    cout << i << " " << j ;
                    return 0 ;
                }
            }
        }
    }
}
