#include<bits/stdc++.h>

using namespace std;

const int N = 4e4+5 ;

int n , m , G[1005][1005] ;
bool vis[N] ;
int L[N] , R[N] , U[N] , D[N] ;

int sy = 1e9 , sx = 1e9 , ey = -1e9 , ex = -1e9 ;

void solve(int u , int y , int x){
    sy = min(sy , y); sx = min(sx , x);
    ey = max(ey , y); ex = max(ex , x);

    G[y][x] = u ;
    vis[u] = true ;

    int v ;
    v = L[u] ;
    if(!vis[v])
        solve(v , y , x-1);
    v = U[u] ;
    if(!vis[v])
        solve(v , y-1 , x);
    v = R[u] ;
    if(!vis[v])
        solve(v , y , x+1);
    v = D[u] ;
    if(!vis[v])
        solve(v , y+1 , x);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;

    for(int i=1;i<(n*m);i++){
        int a , b ; char x ;
        cin >> a >> x >> b ;
        if(x == 'U'){
            U[b] = a ;
            D[a] = b ;
        }
        else {
            L[b] = a ;
            R[a] = b ;
        }
    }

    solve(0 , 500 , 500) ;

    for(int i=sy;i<=ey;i++){
        for(int j=sx;j<=ex;j++){
            cout << G[i][j] << " " ;
        }
        cout << "\n" ;
    }
}


//keypoint : จะเริ่มที่ตัวไหนก็ได้เพราะยังไงก็เชื่อมเป็น connected graph อยู่แล้ว
//  และก็ไม่ต้องเก็บ vis ของ grid ก็ได้ แค่เก็บ vis ของเลขไม่ให้มันเดินทางเดิมซ็ำก็พอ
// เริ่มตัวแรกให้เป็นค่าเยอะๆ เพราะเราไม่รู้ว่ากราฟจะกระจายไปทางไหนกี่ทางบ้าง พอจะ printก็printจากค่าพิกัดมากสุดและน้อยสุด
