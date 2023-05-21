#include<bits/stdc++.h>

using namespace std;

const int N = 305 ;
int n , m , G[N][N] , cnt ;
vector<int> ans ;

void solve(int y , int x , int py , int px){
    if(py >= 1 && py <= n && px >= 1 && px <= m){
        if(G[py][px] == 31){
            if(py == y){
                G[py][px] = 21 ;
            }
            else G[py][px] = 22 ;
        }
        else {
            G[py][px] = 0 ;
        }
    }
    if(y < 1 || y > n || x < 1 || x > m){
        ans.push_back(cnt);
        cnt = 0 ;
        return ;
    }
    cnt++;
    if(G[y][x] == 11){
        if(py == y-1){
            solve(y , x-1 , y , x);
        }
        else if(px == x-1){
            solve(y-1 , x , y , x);
        }
    }
    else if(G[y][x] == 12){
        if(py == y-1){
            solve(y , x+1 , y , x);
        }
        else if(px == x+1){
            solve(y-1 , x , y , x);
        }
    }
    else if(G[y][x] == 13){
        if(py == y+1){
            solve(y , x-1 , y , x);
        }
        else if(px == x-1){
            solve(y+1 , x , y , x);
        }
    }
    else if(G[y][x] == 14){
        if(py == y+1){
            solve(y , x+1 , y , x);
        }
        else if(px == x+1){
            solve(y+1 , x , y , x);
        }
    }
    else if(G[y][x] == 21){
        if(py == y-1){
            solve(y+1 , x , y , x);
        }
        else if(py == y+1){
            solve(y-1 , x , y , x);
        }
    }
    else if(G[y][x] == 22){
        if(px == x-1){
            solve(y , x+1 , y , x);
        }
        else if(px == x+1){
            solve(y , x-1 , y , x);
        }
    }
    else if(G[y][x] == 31){
        if(px == x-1){
            solve(y , x+1 , y , x);
        }
        else if(px == x+1){
            solve(y , x-1 , y , x);
        }
        else if(py == y-1){
            solve(y+1 , x , y , x);
        }
        else if(py == y+1){
            solve(y-1 , x , y , x);
        }
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
    for(int i=1;i<=m;i++){
        if(G[1][i] == 11 || G[1][i] == 12 || G[1][i] == 21 || G[1][i] == 31){
            solve(1 , i , 0 , i);
        }
        if(G[n][i] == 13 || G[n][i] == 14 || G[n][i] == 21 || G[n][i] == 31){
            solve(n , i , n+1 , i);
        }
    }
    for(int i=1;i<=n;i++){
        if(G[i][1] == 11 || G[i][1] == 13 || G[i][1] == 22 || G[i][1] == 31){
            solve(i , 1 , i , 0);
        }
        if(G[i][m] == 12 || G[i][m] == 14 || G[i][m] == 22 || G[i][m] == 31){
            solve(i , m , i , m+1);
        }
    }
    cout << ans.size() << "\n" ;
    for(int x : ans){
        cout << x << " " ;
    }
}
