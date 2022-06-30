#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    vector<vector<int>> dp(n, vector<int>(n, 2147483647));

    for (int i = 0; i < n; i++) dp[i][i] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j+i < n; j++) {
            for (int k = j; k < j+i; k++) {
                int c = dp[j][k] + dp[k + 1][j + i] + a[j] * b[k] * a[k + 1] * b[j + i];
                dp[j][j + i] = min(dp[j][j + i], c);
            }
        }
    }

    cout << dp[0][n-1] << endl;
    return 0;
}