import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maxFrequencyElements(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        int max = 0, ans = 0;
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
            int c = map.get(num);
            if (c > max) {
                max = c;
                ans = c;
            } else if (c == max) {
                ans += c;
            }
        }
        return ans;
    }
}