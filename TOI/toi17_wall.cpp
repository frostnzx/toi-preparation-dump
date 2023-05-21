#include<bits/stdc++.h>

using namespace std;

const int N = 1005 ;
const int D[4][2] = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}} ;

int n , m , ans = -1e9 , cnt ;
char G[N][N] ;

bool vis[N][N] , flood[N][N] ;

void dfs(int uy , int ux){
    vis[uy][ux] = true ;
    for(int i=0;i<4;i++){
        int vy = uy+D[i][0] , vx = ux+D[i][1] ;
        if(vy < 1 || vy > n || vx < 1 || vx > m){
            continue ;
        }
        if(G[vy][vx] == '.'){
            if(flood[vy][vx]){
                cnt++;
            }
            continue;
        }
        if(vis[vy][vx]){
            continue ;
        }
        dfs(vy , vx) ;
    }
}

void waterflood(int uy , int ux){
    flood[uy][ux] = true ;
    for(int i=0;i<4;i++){
        int vy = uy+D[i][0] , vx = ux+D[i][1] ;
        if(vy < 1 || vy > n || vx < 1 || vx > m){
            continue ;
        }
        if(G[vy][vx] == 'X'){
            continue;
        }
        if(flood[vy][vx]){
            continue ;
        }
        waterflood(vy , vx) ;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> G[i][j] ;
        }
    }

    waterflood(1 , 1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vis[i][j] && G[i][j] == 'X'){
                cnt = 0 ;
                dfs(i , j);
                ans = max(ans ,cnt) ;
            }
        }
    }

    cout << ans ;
}
