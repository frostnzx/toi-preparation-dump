#include<bits/stdc++.h>

using namespace std;

using i3 = tuple<int,int,int> ;

const int N = 105 ;

int n , m , dis[N][N] ;

char G[N][N] ;

void solve(){
    memset(dis , -1 , sizeof(dis));
    queue<i3> q ;

    q.push({1 , 1 , 1}) ;
    while(!q.empty()){
        int uy , ux , t ; tie(uy , ux , t) = q.front() ;
        q.pop() ;

        if(dis[uy][ux] != -1){
            if(dis[uy][ux] == t){
                cout << t << "\n" ;
                cout << uy << " " << ux ;
                return ;
            }
            continue;
        }
        dis[uy][ux] = t ;

        if(G[uy][ux] == 'R' || G[uy][ux] == 'B'){
            if(ux+1 <= m){
                q.push({uy , ux+1 , t+1});
            }
        }
        if(G[uy][ux] == 'D' || G[uy][ux] == 'B'){
            if(uy+1 <= n){
                q.push({uy+1 , ux , t+1});
            }
        }
        if(G[uy][ux-1] == 'R' || G[uy][ux-1] == 'B'){
            if(ux-1 >= 1){
                q.push({uy , ux-1 , t+1});
            }
        }
        if(G[uy-1][ux] == 'D' || G[uy-1][ux] == 'B'){
            if(uy-1 >= 1){
                q.push({uy-1 , ux , t+1});
            }
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

    solve();
}
