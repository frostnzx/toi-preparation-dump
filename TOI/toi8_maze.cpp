#include<bits/stdc++.h>
#define DEBUG 0

using namespace std;

using pii = pair<int,int> ;

const int N = 155 ;
const int D[4][2] = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}} ;

int n , m , G[N][N] , dis[2][N][N] , y[2] , x[2] ;
bool vis[2][N][N] ;

void solve(int ty){
    queue<pii> q ;

    q.push({y[ty] , x[ty]});
    vis[ty][y[ty]][x[ty]] = true ;
    dis[ty][y[ty]][x[ty]] = 1 ;
    while(!q.empty()){
        int uy , ux ; tie(uy , ux) = q.front() ;
        q.pop();
        for(int i=0;i<4;i++){
            int vy = uy + D[i][0] , vx = ux + D[i][1] ;
            if(vy < 1 || vy > n || vx < 1 || vx > m){
                continue;
            }
            if(vis[ty][vy][vx]){
                continue;
            }
            if(G[vy][vx]){
                q.push({vy , vx}) ;
            }
            dis[ty][vy][vx] = dis[ty][uy][ux] + 1 ;
            vis[ty][vy][vx] = true ;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=0;i<2;i++){
        cin >> y[i] >> x[i] ;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> G[i][j] ;
        }
    }

    for(int i=0;i<2;i++){
        solve(i);
    }

    int cnt = 0 , ans = 1e9 ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!G[i][j]){
                if(dis[0][i][j] != 0 &&  dis[1][i][j] != 0){
                    cnt++;
                    if(dis[0][i][j] + dis[1][i][j] - 1 < ans){
                        ans = dis[0][i][j] + dis[1][i][j] - 1 ;
                    }
                }
            }
        }
    }

    cout << cnt << "\n" << ans ;

}


//keypoint : why the fuck can't use G as a boolean wtf?????
