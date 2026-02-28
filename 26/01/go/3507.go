package A

import "math"

func isIncrease(nums []int) bool {
	for i := range nums {
		if i == len(nums)-1 {
			break
		}
		if nums[i] > nums[i+1] {
			return false
		}
	}
	return true
}

func minimumPairRemoval(nums []int) int {
	ans := 0
	index := 0
	temp := 0
	for !isIncrease(nums) {
		minX := math.MaxInt
		for i := range nums {
			if i == len(nums)-1 {
				break
			}
			temp = nums[i] + nums[i+1]
			if minX > temp {
				minX = temp
				index = i
			}
		}
		nums[index] = minX
		nums = append(nums[:index+1], nums[index+2:]...)
		ans++
	}
	return ans
}
