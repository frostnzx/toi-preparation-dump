#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+5 ;

struct DATA {
    int h , y , x ;
    bool status ;

    bool operator<(const DATA &other) const {
        return h > other.h ;
    }
};

int n , t , f , s , q , G[N][N] ;
vector<DATA> vec ;

int main(){
    cin >> n >> t >> f >> s >> q ;
    for(int i=1 , x , y , h , v;i<=n;i++){
        cin >> x >> y >> h >> v ;
        vec.push_back({h , y , x , v});
        G[y][x] = h ;
    }


    for(auto &[h , y , x , v] : vec){
        if(v){

        }
        else {

        }
    }
}
