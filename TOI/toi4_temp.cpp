#include<bits/stdc++.h>

using namespace std;

const int N = 25 ;
const int D[4][2] = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1} } ;

int n , G[N][N] ;
bool vis[N][N] ;

int solve(int uy , int ux){
    vis[uy][ux] = true ;
    int ans = G[uy][ux] ;
    for(int i=0;i<4;i++){
        int vy = uy + D[i][0] , vx = ux + D[i][1] ;
        if(vy < 1 || vy > n || vx < 1 || vx > n)
            continue;
        if(!vis[vy][vx] && G[vy][vx] != 100 && G[vy][vx] > G[uy][ux]){
            ans = max(ans , solve(vy , vx)) ;
        }
    }
    return ans ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n ;
    int y,x ; cin >> x >> y ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> G[i][j] ;
        }
    }
    cout << solve(y , x);
}
