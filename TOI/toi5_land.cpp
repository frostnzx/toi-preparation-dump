#include<bits/stdc++.h>

using namespace std;
using i3 = tuple<double,int,int> ;
using pii = pair<int,int> ;

const int D[8][2] = {{-1,0} , {1 , 0} , {0 , -1} , {0 ,1} , {-1 , -1} , {1 , 1} , {-1 ,1} , {1 , -1}} ;

int n , m ;
double G[5][5] , A[5][5] , ans = 0 ;
vector<pii> idx ;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    for(int i=1;i<=n;i++){
        for(int j=1 ;j<=m;j++){
            cin >> G[i][j] ;
            idx.push_back({i , j});
        }
    }
    double rans = 1e9 ;
    do{
        memset(A , 0 , sizeof(A));
        ans = 0 ;
        for(auto now : idx){
            int y , x ; tie(y , x) = now ;
            ans += A[y][x] + G[y][x] ;
            for(int i=0;i<8;i++){
                int ny = y+D[i][0] , nx = x+D[i][1];
                if(ny < 1 || ny > n || nx < 1 || nx > m){
                    continue;
                }
                A[ny][nx] += 0.1 * (A[y][x] + G[y][x]) ;
            }
        }
        rans = min(rans , ans) ;
    }while(next_permutation(idx.begin() , idx.end()));


    cout << fixed << setprecision(2) << rans ;
}
