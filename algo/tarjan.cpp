#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+5 ;

int n , m , t , low[N] , disc[N] , scc[N] , scc_cnt ;
bool vis[N] ;
vector<int> G[N] ;

stack<int> st ;

void dfs(int u){
    low[u] = disc[u] = ++t ;

    st.push(u);
    vis[u] = true ;

    for(int v : G[u]){
        if(!disc[v]){ // tree edge
            dfs(v) ;
            low[u] = min(low[u] , low[v]);
        }
        else { // back edge
            if(vis[v]){ // if in stack
                low[u] = min(low[u] , disc[v]);
            }
        }
    }

    if(low[u] == disc[u]){
        scc_cnt++ ;
        while(st.top() != u){
            int now = st.top() ;

            vis[now] = false ;
            st.pop() ;

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
    for(int i=1 , u , v;i<=m;i++){
        cin >> u >> v ;
        G[u].push_back(v) ;
    }

    for(int i=1;i<=n;i++){
        if(!disc[i]){
            dfs(i);
        }
    }

    cout << scc_cnt << "\n" ;
    for(int i=1;i<=n;i++){
        cout << scc[i] ;
        if(i != n){
            cout << " " ;
        }
    }
}


// CSES : 1683

//Note that application of tarjan for bridges and articulation point doesn't require stack
//https://www.cnblogs.com/dgsvygd/p/16579676.html
