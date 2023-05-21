#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+5 ; 

int n,m ; 
int color[N] ; 
vector<int> G[N] ; 
vector<int> path ; 

bool dfs(int u){
    path.push_back(u);
    if(color[u]==1){
        vector<int> ans ; 
        for(int i=path.size()-1;i>=0;i--){
            ans.push_back(path[i]);
            if(path[i] == u && i != path.size()-1)
                break;
        }
        cout << ans.size() << "\n" ; 
        for(int i=ans.size()-1;i>=0;i--)
            cout << ans[i] << " " ;
        return true ; 
    }
    if(color[u]==2){
        path.pop_back() ; return false ; 
    }
    color[u] = true ; 
    for(int v : G[u])
        if(dfs(v))
            return true ; 
    color[u] = 2 ; 
    path.pop_back();
    return false ; 
}

void solve(){
    bool isCycle = false ; 
    for(int i=1;i<=n;i++)
        if(color[i]==0 && dfs(i)){
            isCycle = true ; 
            break;
        }
        else path.clear();
    if(!isCycle)
        cout << "IMPOSSIBLE" ; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m ; 

    int u,v ; 
    for(int i=1;i<=m;i++)
        cin>>u>>v , G[u].push_back(v);
    
    solve();     
}