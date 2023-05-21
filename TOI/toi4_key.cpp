#include<bits/stdc++.h>

using namespace std;

int n , m ; // n = keymom , m = keyson
string a , x , b ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m ;
    cin >> a >> b >> x ;


    for(int l = 1-m ,r=0 ; l < n ; l++,r++){
        int nl = max(0 , l) , nr = min(n-1 , r) ;
        int sz = nr-nl+1 ,sx ;
        if(r > nr){
            sx = (m-1) - (r-nr) ;
        }
        else sx = m-1 ;

        for(int i=nr , c=0;i>=nl && c<sz;i-- , sx--,c++){
            int ss[3] ; ss[0] = x[sx] , ss[1] = a[i] , ss[2] = b[i] ;
            sort(ss , ss+3) ;
            x[sx] = ss[1] ;
        }
    }

    cout << x  ;

}

//keypoint : ที่จริงไม่ต้องทำแบบไล่ idx ก็ได้เพราะยังไง ลูกทุกช่อง ก็๋ต้องเทียบกับแม่ทุกช่อง อยู่แล้ว แค่ไล่เทียบลูกทุกตัวกับแม่ทุกตัวก็จบ
