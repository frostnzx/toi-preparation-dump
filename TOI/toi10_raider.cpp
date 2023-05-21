#include<bits/stdc++.h>

using namespace std;

using i3 = tuple<int,int,int> ;

const int N = 105 ;
const int D1[6][2] = {{-1 , 0} , {-1 , 1} , {0 , -1} , {0 , 1} , {1 , 0} , {1 , 1}} ;
const int D2[6][2] = {{-1 , -1} , {-1 , 0} , {0 , -1} , {0 , 1} , {1 , -1} , {1 , 0}} ;

int n , m , G[N][N] ;
bool vis[N][N][1005] ;

void solve(){
    int st = ((n - 1)/2)+1 ;

    queue<i3> q ;

    for(int i=st-1;i<=st+1;i++){
        if(G[i][1] == 0) continue;
        vis[i][1][1] = true ;
        q.push({i , 1 , 1});
    }
    while(!q.empty()){
        int uy , ux , cnt ; tie(uy , ux , cnt) = q.front();
        q.pop();

        //cout << "uy = " << uy << " ux = " << ux << " cnt = " << cnt << " dis[uy][ux] = " << dis[uy][ux][cnt] << "\n" ;

        if(uy == ((n - 1)/2)+1 && ux == m){
            cout << cnt ;
            return ;
        }

        int n_cnt = cnt+1;

        for(int i=0;i<6;i++){
            int vy , vx ;
            if(uy % 2 == 1){
                vy = uy + D1[i][0] , vx = ux + D1[i][1] ;
            }
            else {
                vy = uy + D2[i][0] , vx = ux + D2[i][1] ;
            }

            if(vy < 1 || vy > n || vx < 1 || vx > m){
                continue;
            }
            if(vis[vy][vx][n_cnt] || G[vy][vx] == 0){
                continue;
            }
            if(n_cnt % G[vy][vx] != 0){
                continue;
            }
            q.push({vy , vx , n_cnt});
            vis[vy][vx][n_cnt] = true ;
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


//keypoint : 1. มันเริ่มได้จากจุดสามจุด เพื่อให้ประหยัดเวลาก็ push จุดเริ่มต้นทั้งหมดไปพร้อมกันเลยก็ได้
// 2. ค่า dist ไม่ต้องเก็บใน array state ก็ได้ แต่เก็บเอาไว้ใน queue ส่วน array แยก state ใช้เป็น bool เพื่อเก็บ vis เฉยๆแทน เพื่อประหยัด mem
// ที่ทำแบบนี้ได้เพราะการ bfs เพื่อหา shortest path ไม่จำเป็นต้องแก้ค่าเหมือน dijkstra ทำให้โยน dist ใส่ queue แล้ว dist ของ state นั้นก็จะ
// ไม่มีวันเปลี่ยน

//ps. ข้อนี้โจทย์ testcase ผิด

