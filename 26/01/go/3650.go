package A

func minCost(n int, edges [][]int) int {
	edgeM := make([][]int, n)
	for i := 0; i < n; i++ {
		edgeM[i] = make([]int, n)
	}
	for _, e := range edges {
		edgeM[e[0]][e[1]] = e[2]
	}
}
