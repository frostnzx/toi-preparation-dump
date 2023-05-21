#include<bits/stdc++.h>

using namespace std;

using i3 = tuple<int,int,int> ;

const int N = 1e6+5 ;

int n , t , ans , fw[N] , height ;

void add(int k , int x){
    while(k <= N){
        fw[k] += x ;
        k += k&-k ;
    }
}
int sum(int k){
    int s = 0 ;
    while(k >= 1){
        s += fw[k] ;
        k -= k&-k ;
    }
    return s ;
}

int st(){
    int l = 1 , r = 1e6 , ans = 1 ;
    while(l <= r){
        int mid = (l+r)/2 ;
        int now = sum(mid) ;
        if(now == t){
            r = mid-1 ;
            ans = mid ;
        }
        else if(now < t){
            r = mid-1 ;
        }
        else {
            l = mid+1 ;
        }
    }
    return ans ;
}
int ed(){
    int l = 1 , r = 1e6 , ans = 1 ;
    while(l <= r){
        int mid = (l+r)/2 ;

        int now = sum(mid) ;
        if(now == t){
            l = mid+1 ;
            ans = mid ;
        }
        else if(now < t){
            r = mid-1 ;
        }
        else {
            l = mid+1 ;
        }
    }
    return ans ;
}

vector<i3> eventP ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> t ;

    for(int i=1 ,s , h , w, o;i<=n;i++){
        cin >> s >> h >> w >> o ;

        eventP.push_back({s , h , o});
        eventP.push_back({s + w , h , -o});
    }

    sort(eventP.begin() , eventP.end());

    int lst = 0 ;
    for(auto [idx , h , val] : eventP){
        int start = st() , endd = ed() ;
        if(sum(start) == t && sum(endd) == t){
            ans += (endd - start + 1) * (idx - lst) ;
        }
        add(1 , val) , add(h+1 , -val) ;

        lst = idx ;
    }

    cout << ans ;
}

//keypoint : fenwick + bnsearch + sweepline

//note : bnsearch เริ่มจากการหาช่องที่มีค่าเป็น t แล้วค่อยหาตัวเริ่ม / ตัวท้าย
