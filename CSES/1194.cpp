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

stack<char> ans ;

void bfs(){
    queue<pii> q ; 

    for(int i=1;i<=n;i++)
        for(int k=1;k<=m;k++)
            if(G[i][k] == 'M')
                q.push({i,k}) , vis[i][k] = true ; 
    for(int i=1;i<=n;i++)   
        for(int k=1;k<=m;k++)
            if(G[i][k] == 'A')
                q.push({i,k}) , vis[i][k] = true ; 
    

    while(!q.empty()){
        int uy,ux ; 
        tie(uy,ux) = q.front() ;
        
        q.pop();
        for(int i=0;i<4;i++){
            int vy = uy+d[i][0] , vx = ux+d[i][1] ; 
            if(vy<1 || vy>n || vx<1 || vx>m)
                continue;
            if(!vis[vy][vx] && G[vy][vx]!='#' && G[vy][vx]!='M'){
                q.push({vy,vx}) ;
                vis[vy][vx] = true ;
                dist[vy][vx] = dist[uy][ux]+1 ; 
                par[vy][vx] = {uy,ux} ;
                if(G[uy][ux] == 'M')
                    G[vy][vx] = 'M' ; 
            }
        }
    }
}

void printans(int y,int x){
    cout << "YES" << "\n" << dist[y][x] << "\n" ; 
    int dy = y , dx = x ; 
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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m ;
    for(int i=1;i<=n;i++)
        for(int k=1;k<=m;k++)
            cin >> G[i][k] ; 

    bfs();

    for(int i=1;i<=m;i++)
        if((G[1][i] == '.' || G[1][i] == 'A') && vis[1][i]) {
            printans(1,i) ;
            return 0 ; 
        }
    
    for(int i=1;i<=n;i++)
        if((G[i][1] == '.' || G[i][1] == 'A') && vis[i][1]) {
            printans(i,1) ;
            return 0 ; 
        }

    for(int i=1;i<=n;i++)
        if((G[i][m] == '.' || G[i][m] == 'A') && vis[i][m]) {
            printans(i,m) ;
            return 0 ; 
        }

    for(int i=1;i<=m;i++)
        if((G[n][i] == '.' || G[n][i] == 'A') && vis[n][i]) {
            printans(n,i) ;
            return 0 ; 
        }

    cout << "NO" ; 
}