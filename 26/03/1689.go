package A

func minPartitions(n string) int {
	res := 0
	for _, v := range n {
		t := int(v - '0')
		if res < t {
			res = t
		}
	}
	return res
}
