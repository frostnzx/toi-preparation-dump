#include<bits/stdc++.h>

using namespace std;

using i6 = tuple<int,int,int,int,int,int> ;

const int N = 15 ;

int n , m , x , y , z , ans = 1e9 ;
bool vis[N] ;

vector<i6> st ;

void solve(int dist , int x , int y , int z ,int a ,int b ,int c){
    if(a >= n && b >= n && c >= n){
        ans = min(ans , dist) ;
        return ;
    }
    if(dist > ans){
        return ;
    }

    for(int i=0;i<m;i++){
        if(vis[i]){
            continue;
        }
        int nx , ny , nz , nm , nk , nc ;
        tie(nx , ny , nz , nm , nk , nc) = st[i] ;
        int nd = (nx - x)*(nx - x) + (ny - y)*(ny - y) + (nz - z)*(nz - z) ;

        vis[i] = true ;
        solve(dist + nd , nx , ny , nz , a + nm , b + nk , c + nc) ;
        vis[i] = false ;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> x >> y >> z >> m ;
    for(int i=0;i<m;i++){
        int a,b,c,d,e,f ;
        cin >> a >> b >> c >> d >> e >> f ;
        st.push_back({a , b , c , d ,e , f});
    }
    solve(0 , x , y , z , 0 , 0 , 0) ;
    cout << ans ;
}

//keypoint : complete search และ ถ้าไม่จำเป็นก็อย่าใช้ next permutation เขียน recursive เองเร็วกว่า
