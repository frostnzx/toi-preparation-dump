#include<bits/stdc++.h>

using namespace std;

using pii = pair<int,int> ;

const int N = 2005 ;

const int D[8][2] = {{1 , 0} , {-1 , 0} , {0 , 1} , {0 , -1} , {-1 , -1} , {-1 , 1} , {1 , -1} , {1 , 1}} ;

int n , m , ans = 0 ;
char G[N][N] ; bool vis[N][N] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> G[i][j] ;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(G[i][j] == '1' && !vis[i][j]){
                ans++;
                queue<pii> q ;
                q.push({i , j});

                while(!q.empty()){
                    auto [uy , ux] = q.front(); q.pop();
                    for(int i=0;i<8;i++){
                        int vy = uy + D[i][0] , vx = ux + D[i][1] ;
                        if(vy < 1 || vy > n || vx < 1 || vx > m){
                            continue;
                        }
                        if(vis[vy][vx] || G[vy][vx] == '0'){
                            continue;
                        }
                        q.push({vy , vx});
                        vis[vy][vx] = true ;
                    }
                }
            }
        }
    }

    cout << ans ;
}
