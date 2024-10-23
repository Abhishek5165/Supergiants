// Time Complexity : O(2^N);
// Space Complexity : O(N);

// Recursion ..

#include <bits/stdc++.h> 
bool solve(int index,int target,vector<int>&arr){
if(target == 0){
    return true;
}
if(index == 0){
    return (arr[0] == target);
}
bool notTake = solve(index-1,target,arr);
bool take = false;
if(target >= arr[index]){
    take = solve(index-1,target-arr[index],arr);
}
return (take || notTake);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
bool ans = solve(n-1,k,arr);
return ans;
}

// Memoization...

// Time Complexity : O(N*target);
// Space Complexity : O(N) + O(N*target);

#include <bits/stdc++.h> 
int dp[1001][1001];
bool solve(int index,int target,vector<int>&arr){
if(target == 0){
    return true;
}
if(index == 0){
    return (arr[0] == target);
}
if(dp[index][target] != -1){
    return dp[index][target];
}

bool notTake = solve(index-1,target,arr);
bool take = false;
if(target >= arr[index]){
    take = solve(index-1,target-arr[index],arr);
}
return dp[index][target] = (take || notTake);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
memset(dp,-1,sizeof(dp));
bool ans = solve(n-1,k,arr);
return ans;
}

// Bottom up ......

// Time Complexity : O(N*target);
// Space Complexity : O(N*target);


#include <bits/stdc++.h>

bool subsetSumToK(int n, int k, vector<int> &arr) {
  vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, 0));

  for (int i = 0; i < n; i++) {
    dp[i][0] = true;
  }
  dp[0][arr[0]] = true;

  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      bool notTake = dp[i-1][j];
      bool take = false;
      if (j >= arr[i]) {
        take = dp[i-1][j-arr[i]];
      }
    dp[i][j] = take || notTake;
    }
  }
  return dp[n-1][k];
}


// Space Optimised...

// Time Complexity : O(N*target);
// Space Complexity : O(target);


#include <bits/stdc++.h>

bool subsetSumToK(int n, int k, vector<int> &arr) {
  vector<bool> prev(k + 1,0);
  vector<bool> curr(k + 1,0);

  prev[0] = curr[0] = true;
  prev[arr[0]] = true;

  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      bool notTake = prev[j];
      bool take = false;
      if (j >= arr[i]) {
        take = prev[j-arr[i]];
      }
    curr[j] = take || notTake;
    }
    prev = curr;
  }
  return prev[k];
}