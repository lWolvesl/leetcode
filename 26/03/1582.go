package A

func numSpecial(mat [][]int) int {
	res := 0
	x := make(map[int]int)
	y := make(map[int]int)
	for i, row := range mat {
		for j, v := range row {
			if v == 0 {
				continue
			}
			x[i]++
			y[j]++
		}
	}
	for i, row := range mat {
		for j, v := range row {
			if v == 0 {
				continue
			}
			if x[i] == 1 && y[j] == 1 {
				res++
			}

		}
	}
	return res
}
