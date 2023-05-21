#include<bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5+5 ;  
bool incycle[N] ; 
int n , vis[N] , G[N] , ans[N] ; 
stack<int> path ; 

int c = 0 ;
void dfs(int u){
    vis[u] = true ; 
    path.push(u);

    if(vis[G[u]]==0)
        dfs(G[u]);
    else if(vis[G[u]]==1 && !incycle[G[u]] && G[u]!=u){ // found cycle first time
        while(!path.empty()){ // mark every node that in cycle
            int v = path.top();
            path.pop();
            c++;
            incycle[v] = true ; 
            if(v==G[u]){
                break;
            }
        }
    }
    if(!ans[u]){ // no assign value yet
        if(incycle[u])
            ans[u] = c ;
        else
            ans[u] = ans[G[u]]+1 ; 
        if(G[u]==u)ans[u] = 1 ; 
    }

    vis[u] = 2 ;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n ; 
    for(int i=1;i<=n;i++)
        cin >> G[i] ;
    
    for(int i=1;i<=n;i++){
        c = 0 ;
        if(!vis[i]) dfs(i);
        while(!path.empty())path.pop(); //clear path
    }
 
    for(int i=1;i<=n;i++)
        cout << ans[i] << " " ;
}