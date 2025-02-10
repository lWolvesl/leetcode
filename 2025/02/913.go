const (
	mouseTurn = 0
	catTurn   = 1

	draw     = 0
	mouseWin = 1
	catWin   = 2
)

func catMouseGame(graph [][]int) int {
	n := len(graph)
	degrees := make([][][2]int, n)
	results := make([][][2]int, n)
	for i := range degrees {
		degrees[i] = make([][2]int, n)
		results[i] = make([][2]int, n)
	}
	for i, to := range graph {
		for j := 1; j < n; j++ {
			degrees[i][j][mouseTurn] = len(to)
			degrees[i][j][catTurn] = len(graph[j])
		}
	}
	for _, y := range graph[0] {
		for i := range degrees {
			degrees[i][y][catTurn]--
		}
	}

	type state struct{ mouse, cat, turn int }
	q := []state{}
	for j := 1; j < n; j++ {
		results[0][j][mouseTurn] = mouseWin
		results[0][j][catTurn] = mouseWin
		q = append(q, state{0, j, mouseTurn}, state{0, j, catTurn})
	}
	for i := 1; i < n; i++ {
		results[i][i][mouseTurn] = catWin
		results[i][i][catTurn] = catWin
		q = append(q, state{i, i, mouseTurn}, state{i, i, catTurn})
	}

	getPrevStates := func(s state) (prevStates []state) {
		if s.turn == mouseTurn {
			for _, prev := range graph[s.cat] {
				if prev != 0 {
					prevStates = append(prevStates, state{s.mouse, prev, catTurn})
				}
			}
		} else {
			for _, prev := range graph[s.mouse] {
				prevStates = append(prevStates, state{prev, s.cat, mouseTurn})
			}
		}
		return
	}

	for len(q) > 0 {
		s := q[0]
		q = q[1:]
		result := results[s.mouse][s.cat][s.turn]
		for _, p := range getPrevStates(s) {
			prevMouse, prevCat, prevTurn := p.mouse, p.cat, p.turn
			if results[prevMouse][prevCat][prevTurn] == draw {
				canWin := result == mouseWin && prevTurn == mouseTurn || result == catWin && prevTurn == catTurn
				if canWin {
					results[prevMouse][prevCat][prevTurn] = result
					q = append(q, p)
				} else {
					degrees[prevMouse][prevCat][prevTurn]--
					if degrees[prevMouse][prevCat][prevTurn] == 0 {
						if prevTurn == mouseTurn {
							results[prevMouse][prevCat][prevTurn] = catWin
						} else {
							results[prevMouse][prevCat][prevTurn] = mouseWin
						}
						q = append(q, p)
					}
				}
			}
		}
	}
	return results[1][2][mouseTurn]
}