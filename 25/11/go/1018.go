package L12

func prefixesDivBy5(nums []int) []bool {
	ans := make([]bool, len(nums))
	num := 0
	for i, v := range nums {
		num = ((num << 1) + v) % 5
		ans[i] = num == 0
	}
	return ans
}
