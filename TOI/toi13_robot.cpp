#include<bits/stdc++.h>

using namespace std;

using i3 = tuple<int,int,int> ;

const int N = 2005 ;
const int D[4][2] = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}} ;

int n , m , acnt , ans ;
char G[N][N] ;
bool vis[N][N] ;

queue<i3> q ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> G[i][j] ;
            if(G[i][j] == 'X'){
                q.push({i , j , 0});
                vis[i][j] = true ;
            }
        }
    }
    while(!q.empty()){
        auto [uy , ux , d] = q.front() ;
        q.pop();

        if(G[uy][ux] == 'A'){
            acnt++ , ans += d*2 ;
        }

        for(int i=0;i<4;i++){
            int vy = uy + D[i][0] , vx = ux + D[i][1] ;
            if(vy < 1 || vy > n || vx < 1 || vx > m){
                continue;
            }
            if(vis[vy][vx] || G[vy][vx] == 'W'){
                continue ;
            }
            q.push({vy , vx , d+1});
            vis[vy][vx] = true ;
        }
    }

    cout << acnt << " " << ans ;
}
