package C

func kLengthApart(nums []int, k int) bool {
	last := -k - 1
	for i := 0; i < len(nums); i++ {
		if nums[i] != 1 {
			continue
		}
		if i-last <= k {
			return false
		}
		last = i
	}
	return true
}
