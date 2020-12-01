#include <bits/stdc++.h>

#define MAX 31
#define MAX1 1000001
using namespace std;
int n,b,res =0;
int dp[MAX][MAX1];
pair<int, int> x[MAX];
int knapsack(int h,int k){
    int cur;
    if(dp[h][k] != -1) return dp[h][k];
    if(h == 0 || k == 0) cur = 0;
    else if(x[h].first > k) cur = knapsack(h-1,k);
    else{
        int tmp1 = knapsack(h-1,k);
        int tmp2 = x[h].second + knapsack(h-1,k-x[h].first);
        cur = max(tmp1,tmp2);

    }
    return dp[h][k] = cur;


}
int main(){
    cin >> n >> b;
    for(int i =1;i <= n;i++){
        cin  >> x[i].first >> x[i].second;
    }

    for(int i =0; i <= n;i++){
        for(int j = 0;j <= b;j++){
            dp[i][j] = -1;
        }
    }
    cout << knapsack(n,b);
    return 0;
}
