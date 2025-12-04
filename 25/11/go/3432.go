package L12

func countPartitions(nums []int) int {
	n := len(nums)
	count := 0
	prefix := make([]int, n)
	for i, v := range nums {
		count += v
		prefix[i] = count
	}

	ans := 0
	for i, v := range prefix {
		if i == n-1 {
			break
		}
		if (count-2*v)%2 == 0 {
			ans++
		}
	}
	return ans
}
