#include <iostream>
using namespace std;

#define Q 1000

int y(int a, int b, int c, int x){
    return a * x * x + b * x + c;
}


int main(){
    int a[Q], b[Q], c[Q], m[Q], l[Q], r[Q] ,ans[Q], n, k;

    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
        int m1 = - b[i] / a[i] / 2, m2 = m1 + 1, m3 = m1 - 1;
        int y1 = y(a[i], b[i], c[i], m1), y2 = y(a[i], b[i], c[i], m2), y3 = y(a[i], b[i], c[i], m3);
        if (y1 < y2)
            m[i] = m1;
        else
            m[i] = m2;
        if (y3 < y(a[i], b[i], c[i], m[i]))
            m[i] = m3;
        l[i] = 0; //左边从0开始
        r[i] = 1;
    }

    //cout << m[0]<< endl << m[1] << endl;

    for (int i = 0; i < k; i++){
        int tmp_min = INT_MAX;
        int last = -1;
        bool last_l = false;
        for (int j = 0; j < n; j++){
            int t1 = y(a[j], b[j], c[j], m[j] - l[j]), t2 = y(a[j], b[j], c[j], m[j] + r[j]);
            if (t1 < tmp_min){
                if(last != -1){
                    if (last_l)
                        l[last]--;
                    else
                        r[last]--;
                }
                tmp_min = t1;
                last = j;
                last_l = true;
                l[j]++;
            }
            if (t2 < tmp_min){
                if(last != -1){
                    if (last_l)
                        l[last]--;
                    else
                        r[last]--;
                }
                tmp_min = t2;
                last = j;
                last_l = false;
                r[j]++;
            }

        }
        ans[i] = tmp_min;
    }

    for (int i = 0; i < k; i++) {
        cout << ans[i];
        if (i != k - 1)
            cout << ' ';
    }

    return 0;
}

