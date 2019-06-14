#include <iostream>
using namespace std;


bool cmp(string a, string b){
    return a>b;
}


int main(){
    char c;
    string s[31], tmp;
    int n = 0;
    cin >> c;
    cin >> tmp;
    while (tmp!="@"){
        s[n] = tmp;
        n++;
        cin >> tmp;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < s[i].length();) {
            if (s[i][j] == c)
                s[i] = s[i].substr(0, j) + s[i].substr(j + 1);
            else
                j++;
        }

    for (int i = 0 ; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (cmp(s[j + 1], s[j])){
                string tmp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = tmp;
            }


    for (int i = 0; i < n; i++) {
        cout << s[i];
        if (i != n - 1)
            cout << endl;
    }
    return 0;
} 