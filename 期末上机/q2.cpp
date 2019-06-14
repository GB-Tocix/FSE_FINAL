#include <iostream>
using namespace std;


int main(){
    int n, a[501], b[501], c[501], d[501], count = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];


    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                for (int l = 0; l < n; l++)
                    if (a[i]+b[j]+c[k]+d[l] == 0)
                        count++;
    cout << count;

    return 0;
}
