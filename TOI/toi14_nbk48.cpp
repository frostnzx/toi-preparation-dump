#include<bits/stdc++.h>

using namespace std;

using ll = long long ;
using pii = pair<ll , ll> ;

const int N = 1e5+5 ;

ll n , q ;

vector<pii> vec ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q ;

    ll s = 0 ;
    for(int i=1 , x;i<=n;i++){
        cin >> x ;
        s += x ;
        vec.push_back({s , i});
    }
    sort(vec.begin() , vec.end());

    ll mx = -1e9 ;
    for(int i=0 ;i<vec.size();i++){
        mx = max(mx , vec[i].second) ;
        vec[i].second = mx ;
    }

    while(q--){
        ll p ; cin >> p ;
        int idx = upper_bound(vec.begin() , vec.end() , pii(p , 1e9)) - vec.begin() ;
        if(idx == 0){
            cout << "0\n" ;
        }
        else cout << vec[idx - 1].second  << "\n" ;
    }
}
// warning : quicksum ที่มีตัวติดลบจะไม่เรียงและ ใช้ binary search ไม่ได้

// keypoint : ใช้ quicksum ธรรมดาไม่ได้่เพราะมีตัวที่ติดลบ จะทำให้ค่าไม่เรียง แล้ว upperbound ไม่ได้
// ต้อง quicksum แล้วเก็บ idx แต่ละช่อง เพราะเราจะ sort อีกที โดยเก็บเป็น (qs[idx] , idx)
// หลัง sort แล้ว qs[idx] จะไม่ใช่ ผลบวกตั้งแต่ 1->idx อีกต่อไปแต่เป็น ผลบวกตั้งแต่ 1->qs[idx].second
// ไม่ต้องมองว่าเป็น prefix sum เพราะยังไงก็ไม่ต้องหักอะไรออกอยู่แล้ว เพราะเริ่มจาก 1->i เสมอ 
// ให้มองแยกๆ เป็น แต่ละแผนการซื้อไปเลย

// sort น้อยไปมาก
// จากนั้น ปรับต่า vec[idx].second เพราะถ้าเราสามารถมาถึง vec[idx] แล้วก็ต้องสามารถไป vec[idx-1] ได้หมด
// ทำให้ vec[idx].second = max(vec[idx].second , vec[{1 , ... , idx-1}])

// จากนั้น หลังจาก sort array ที่ได้มาตามราคาแล้ว ในแต่ละ query ก็ binary search หา แผนการซื้อที่แพงที่สุดที่สามารถซื้อได้ เป็น แผนที่ idx
// แผนที่ vec[idx].second จะเป็นคำตอบของ query ครั้งนี้เพราะว่า ไม่วายังไงถึง ถึงมีแผนการซื้อที่ถูกกว่า แต่ดูตอนได้มากกว่า แต่ในขั้นตอนก่อนหน้านี้
// เราได้ทำการปรับค่า vec[idx].second แล้ว ทำให้ vec[idx].second นี้จะเป็นตอนที่มากที่สุดที่สามารถดูได้ เมื่อซื้อ แผนการซื้อที 
// อยู่ในช่วงราคาตั้งแต่ 1 -> idx


