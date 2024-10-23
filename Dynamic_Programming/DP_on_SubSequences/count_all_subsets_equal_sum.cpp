int solve(int index,vector<int>&arr, int target) {
  if (target == 0) {
    return 1;
  }
  if (index == 0) {
    return (arr[0] == target) ? 1 : 0;
  }

  int notTake = solve(index - 1,arr, target);
  int take = 0;
  if (arr[index] <= target) {
    take = solve(index - 1,arr, target - arr[index]);
  }
  return (take + notTake);
}

int findWays(vector<int> &arr, int k) {
  int n = arr.size();
  return solve(n - 1, arr, k);
}
