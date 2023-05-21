// write in short code style (short flood fill)

#include<bits/stdc++.h>

using namespace std;

const int N = 1005 , d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}} ; 
const char dir[4] = {'D','U','R','L'} ; 
using pii = pair<int,int> ; 

char G[N][N] ;
bool vis[N][N] ;  
int dist[N][N] ;
pii par[N][N] ;
int n,m ; 

int ay,ax,by,bx ; 

stack<char> ans ;

void bfs(int y,int x){
    queue<pii> q ; 
    q.push({y,x});
    vis[y][x] = true ; 

    while(!q.empty()){
        int uy,ux ; 
        tie(uy,ux) = q.front() ;
        q.pop();
        for(int i=0;i<4;i++){
            int vy = uy+d[i][0] , vx = ux+d[i][1] ; 
            if(vy<1 || vy>n || vx<1 || vx>m)
                continue;
            if(!vis[vy][vx] && G[vy][vx]!='#'){
                q.push({vy,vx}) ;
                vis[vy][vx] = true ;
                dist[vy][vx] = dist[uy][ux]+1 ; 
                par[vy][vx] = {uy,ux} ;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m ;
    for(int i=1;i<=n;i++)
        for(int k=1;k<=m;k++)
            cin >> G[i][k] ; 
    
    for(int i=1;i<=n;i++)
        for(int k=1;k<=m;k++)
            if(G[i][k] == 'A')
                ay = i , ax = k ;
            else if(G[i][k] == 'B')
                by = i , bx = k ;


    bfs(ay,ax);

    if(dist[by][bx] > 0){
        cout << "YES" << "\n" << dist[by][bx] << "\n" ; 
        int dy = by , dx = bx ; 
        while(G[dy][dx]!='A'){
            if(par[dy][dx].first == dy-1) 
                ans.push('D');
            else if(par[dy][dx].first == dy+1) 
                ans.push('U');
            else if(par[dy][dx].second == dx-1)
                ans.push('R');
            else if(par[dy][dx].second == dx+1)
                ans.push('L');
            tie(dy,dx) = par[dy][dx] ; 
        }

        while(!ans.empty())
            cout << ans.top() , ans.pop();
    }
    else cout << "NO" ; 
}