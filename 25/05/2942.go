package main

import "strings"

func findWordsContaining(words []string, x byte) []int {
	var result []int
	for i, word := range words {
		if strings.Index(word, string(x)) != -1 {
			result = append(result, i)
		}
	}
	return result
}
