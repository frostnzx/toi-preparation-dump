#include<bits/stdc++.h>

using namespace std;

using pii = pair<int,int> ; 

const int N = 1005 , D[4][2] = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}} ; 

int n,m ; 
bool vis[N][N] ; 
char G[N][N] ; 

void solve(int y,int x){
    queue<pii> Q ; 
    Q.push({y , x});
    while(!Q.empty()){
        int uy,ux ; tie(uy,ux) = Q.front() ; 
        Q.pop();
        for(int i=0;i<4;i++){
            int vy = uy + D[i][0] , vx = ux + D[i][1] ;
            if(vy < 0 || vy > n || vx < 0 || vx > m)
                continue;
            if(!vis[vy][vx] && G[vy][vx] == '.')
                Q.push({vy ,vx}) , vis[vy][vx] = true ; 
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ; 
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> G[i][j] ; 

    int ans = 0 ;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!vis[i][j] && G[i][j] == '.')
                solve(i , j) , ans++ ; 

    cout << ans ; 
}