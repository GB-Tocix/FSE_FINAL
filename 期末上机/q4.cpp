#include <iostream>
using namespace std;


int main(){
    int n, m;
    int dis[300][300];
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] =INT_MAX / 2 - 1;

    for (int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        dis[u][v] = c;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if(dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j];

    cout << dis[1][n];

    return 0;
}
