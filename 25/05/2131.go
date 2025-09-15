package main

func Reverse(s string) string {
	bytes := []byte(s) // 直接转为字节切片
	for i, j := 0, len(bytes)-1; i < j; i, j = i+1, j-1 {
		bytes[i], bytes[j] = bytes[j], bytes[i] // 交换字节
	}
	return string(bytes)
}

func longestPalindrome(words []string) int {
	m := make(map[string]int)
	res, center := 0, 0
	for _, word := range words {
		m[word]++
	}
	for word := range m {
		if m[word] == 0 {
			continue
		}

		reversed := Reverse(word)

		if reversed == word {
			pairs := m[word] / 2
			res += pairs * 2 * 2
			if m[word]%2 == 1 {
				center = 2
			}
		} else {
			if m[reversed] >= 1 {
				pairs := min(m[word], m[reversed])
				res += pairs * 4
				m[word] -= pairs
				m[reversed] -= pairs
			}
		}
	}
	return res + center
}
