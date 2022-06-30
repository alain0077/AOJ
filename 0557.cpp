#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
    }

    unsigned long long dp[100][21] = {};
    dp[0][a[0]] = 1;
    
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (j - a[i] >= 0) {
                dp[i][j] += dp[i - 1][j - a[i]];
            }
            if (j + a[i] <= 20) {
                dp[i][j] += dp[i - 1][j + a[i]];
            }
        }
    }

    int q;
    cin >> q;
    cout << dp[n - 2][q] << endl;
    return 0;
}