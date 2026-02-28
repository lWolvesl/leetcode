package A

func minBitwiseArray(nums []int) []int {
	ans := make([]int, 0, len(nums))
	for _, num := range nums {
		if num == 2 {
			ans = append(ans, -1)
			continue
		}
		temp := num
		t := 0
		for temp&1 == 1 {
			t++
			temp >>= 1
		}
		ans = append(ans, num^(1<<(t-1)))
	}
	return ans
}
