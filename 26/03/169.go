package main

func majorityElement(nums []int) int {
	a, s := nums[0], 1
	for i := 1; i < len(nums); i++ {
		if a == nums[i] {
			s++
			continue
		}
		s--
		if s == 0 {
			a = nums[i]
			s = 1
		}
	}
	return a
}
