#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+5 ; 

int n , m , indeg[N] ; 
vector<int> G[N] ; 
vector<int> sorted ; 
queue<int> q ; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0) ; 

    cin >> n >> m ; 

    for(int i=1;i<=m;i++){
        int u,v ; cin >> u >> v ; 
        G[u].push_back(v);
        indeg[v]++;
    }

    for(int i=1;i<=n;i++){
        if(indeg[i] == 0){
            q.push(i) ;
        }
    }

    while(!q.empty()){
        int u = q.front() ; 
        q.pop();

        sorted.push_back(u) ; 
        for(int v : G[u]){
            indeg[v]--;
            if(indeg[v] == 0){
                q.push(v);
            }
        }
    }
    if(sorted.size() != n){
        cout << "IMPOSSIBLE" ; 
        return 0 ;
    }
    for(int i : sorted)
        cout << i << " " ;

}