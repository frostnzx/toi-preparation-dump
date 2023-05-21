#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+5 , M = 2005   ;
const int D[4][2] = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}} ;

int n , m , cnt[N] , ans[4] , s = 1e9 , e = -1e9 ;
bitset<M> vis[N] , G[N] ;

void solve(int uy , int ux){
    vis[uy][ux] = true ;
    cnt[uy]++;

    s = min(uy , s) , e = max(uy , e) ;
    for(int i=0;i<4;i++){
        int vy = uy + D[i][0] , vx = ux + D[i][1] ;
        if(vis[vy][vx] || !G[vy][vx]){
            continue;
        }
        if(vy < 1 || vy > n || vx < 1 || vx > m){
            continue;
        }
        solve(vy , vx);
    }
}

int ty(){
    bool ty1 = true , ty2 = false ;

    for(int i=s;i<e;i++){
        if(cnt[i] != cnt[i+1]){
            ty1 = false ;
        }
        if(cnt[i] == cnt[i-1]+2 && cnt[i] == cnt[i+1]+2){
            ty2 = true ;
        }
    }
    for(int i=s;i<=e;i++){
        cnt[i] = 0 ;
    }
    s = 1e9 , e = -1e9 ;

    if(ty1) return 1 ;
    else if(ty2) return 2 ;
    else return 3 ;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> m >> n ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char x ; cin >> x ;
            if(x == '1'){
                G[i][j] = true ;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vis[i][j] && G[i][j]){
                solve(i , j);
                ans[ty()]++;
            }
        }
    }

    for(int i=1;i<=3;i++){
        cout << ans[i] << " " ;
    }
}

//keypoint : use bitset to reduce memory
