#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

const int N = 1e5+5 ;

ll n , q , arr[N] , qs[N] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q ;
    for(int i=1;i<=n;i++){
        cin >> arr[i] ;
        qs[i] = qs[i-1] + arr[i] ;
    }

    while(q--){
        ll s , m , e ,res = 0 ;
        cin >> s >> m >> e ;
        if(m == 1){
            res = qs[e] - qs[s - 1] ;
        }
        else {
            for(int i=s ; i<=e ; i+=m){
                res += arr[i] ;
            }
        }
        cout << res << " " ;
    }
}

//keypoint : ข้อนี้คิดตรงๆ แต่แยกเคสไว้ ถ้า m = 1 ให้ใช้ qs ธรรมดาเป็นการลดเวลาถ้ามีเคสไหน m = 1 เยอะๆลงไปมาก
// เอาจริงๆ ข้อนี้ actualsol คือ sqrt decomposition แต่โจทย์ข้อนี้น่าจะเจนเทสเคสมาไม่ดี ฉะนั้นถ้าคิดวิธีที่อาจทำได้แค่บางกรณี แต่จะเร็วกว่ามากๆ
// ก็ลองเขียนโดย แยกเป็นเคสนั้นดู ถ้าโจทย์เจนเทสเคสมาไม่ดี อาจจะฟลุคถูกก็ได้ เวลาคิด sol บางอันที่คิดว่าไม่น่าทันก็ลองเขียนส่งดูก่อนก็ได้

//reminder : อย่าลืมดักเคส ถ้าคิดเคสดักออก แต่ดักแล้วต้อง else ให้มันทำ case อื่นได้ด้วย
