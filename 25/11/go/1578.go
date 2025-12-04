package L12

func minCost(colors string, neededTime []int) int {
	count := 0
	ans := 0
	m := 0
	for i := 0; i < len(colors); i++ {
		count += neededTime[i]
		m = max(m, neededTime[i])
		if i != len(colors)-1 && colors[i] == colors[i+1] {
			continue
		}
		ans += count - m
		m = 0
		count = 0
	}
	return ans
}
