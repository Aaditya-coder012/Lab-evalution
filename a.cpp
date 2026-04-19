// // 1. Matrix Chain Multiplication (DP)
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> arr(n + 1);
//     for (int i = 0; i <= n; i++)
//         cin >> arr[i];

//     vector<vector<int>> dp(n, vector<int>(n, 0));

//     for (int len = 2; len <= n; len++)
//     {
//         for (int i = 0; i <= n - len; i++)
//         {
//             int j = i + len - 1;
//             dp[i][j] = INT_MAX;

//             for (int k = i; k < j; k++)
//             {
//                 int cost = dp[i][k] + dp[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1];
//                 dp[i][j] = min(dp[i][j], cost);
//             }
//         }
//     }

//     cout << dp[0][n - 1];
// }

// /*
//     Input
//         4
//         10 20 30 40 30
//     Output
//         30000
// */

// // 2. Floyd–Warshall (DP)
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<vector<int>> dist(n, vector<int>(n));
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             cin >> dist[i][j];

//     for (int k = 0; k < n; k++)
//         for (int i = 0; i < n; i++)
//             for (int j = 0; j < n; j++)
//                 if (dist[i][k] < 1e9 && dist[k][j] < 1e9)
//                     dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//             cout << dist[i][j] << " ";
//         cout << endl;
//     }
// }

// /*
//     Input
//         4
//         0 5 1000000000 10
//         1000000000 0 3 1000000000
//         1000000000 1000000000 0 1
//         1000000000 1000000000 1000000000 0
//     Output
//         0 5 8 9
//         1000000000 0 3 4
//         1000000000 1000000000 0 1
//         1000000000 1000000000 1000000000 0
// */

// // 3. 0/1 Knapsack (DP version)
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, W;
//     cin >> n >> W;

//     vector<int> val(n), wt(n);
//     for (int i = 0; i < n; i++)
//         cin >> val[i] >> wt[i];

//     vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

//     for (int i = 1; i <= n; i++)
//     {
//         for (int w = 0; w <= W; w++)
//         {
//             if (wt[i - 1] <= w)
//                 dp[i][w] = max(dp[i - 1][w],
//                                val[i - 1] + dp[i - 1][w - wt[i - 1]]);
//             else
//                 dp[i][w] = dp[i - 1][w];
//         }
//     }

//     cout << dp[n][W];
// }

// /*
//     Input
//         3 50
//         60 10
//         100 20
//         120 30
//     Output
//         220
// */

// // 4. Weighted Interval Scheduling (DP)
// #include <bits/stdc++.h>
// using namespace std;

// struct Job {
//     int start, finish, profit;
// };

// bool cmp(Job a, Job b) {
//     return a.finish < b.finish;
// }

// int latestNonConflict(vector<Job>& jobs, int i) {
//     for (int j = i - 1; j >= 0; j--) {
//         if (jobs[j].finish <= jobs[i].start)
//             return j;
//     }
//     return -1;
// }

// int main() {
//     int n;
//     cin >> n;

//     vector<Job> jobs(n);
//     for (int i = 0; i < n; i++)
//         cin >> jobs[i].start >> jobs[i].finish >> jobs[i].profit;

//     sort(jobs.begin(), jobs.end(), cmp);

//     vector<int> dp(n);
//     dp[0] = jobs[0].profit;

//     for (int i = 1; i < n; i++) {
//         int incl = jobs[i].profit;
//         int l = latestNonConflict(jobs, i);
//         if (l != -1)
//             incl += dp[l];

//         dp[i] = max(incl, dp[i - 1]);
//     }

//     cout << dp[n - 1];
// }

// /*
//     Input
//         4
//         1 3 5
//         2 5 6
//         4 6 5
//         6 7 4
//     Output
//         14
// */