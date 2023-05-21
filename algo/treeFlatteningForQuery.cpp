#include<bits/stdc++.h>

using namespace std;

const int N = 1005 ;

int n ;
int timer , S[N] , E[N] , FT[2 * N] ;
vector<int> G[N] ;

void dfs(int u , int p){
    S[u] = timer ;
    FT[timer] = u ;
    timer++;

    for(int v : G[u]){
        if(v == p) {
            continue;
        }
        dfs(v , u);
    }

    E[u] = timer ;
    FT[timer] = u ;
    timer++;
}

int main(){
    cin >> n ;
    for(int i=1 , u , v;i<=n-1;i++){
        cin >> u >> v ;
        G[u].push_back(v) , G[v].push_back(u) ;
    }
}
