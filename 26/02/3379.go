package A

func constructTransformedArray(nums []int) []int {
	n := len(nums)
	res := make([]int, n)
	for i, v := range nums {
		if v > 0 {
			res[i] = nums[(i+v)%n]
		}
		if v == 0 {
			res[i] = v
		}
		if v < 0 {
			res[i] = nums[((i+v)%n+n)%n]
		}
	}
	return res
}
