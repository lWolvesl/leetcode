class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        int last = -k - 1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 1) {
                continue;
            }
            if (i - last <= k) {
                return false;
            }
            last = i;
        }
        return true;
    }
}