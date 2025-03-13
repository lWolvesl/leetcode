#include <stdbool.h>

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

long long count(char* word, int k) {
    int n = strlen(word);
    long long res = 0;
    int consonants = 0;
    int occur[26] = {0};
    int vowelCount = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && (consonants < k || vowelCount < 5)) {
            if (isVowel(word[j])) {
                occur[word[j] - 'a']++;
                vowelCount += occur[word[j] - 'a'] == 1;
            } else {
                consonants++;
            }
            j++;
        }
        if (consonants >= k && vowelCount == 5) {
            res += n - j + 1;
        }
        if (isVowel(word[i])) {
            occur[word[i] - 'a']--;
            if (occur[word[i] - 'a'] == 0) {
                vowelCount--;
            }
        } else {
            consonants--;
        }
    }
    return res;
}

long long countOfSubstrings(char* word, int k) {
    return count(word, k) - count(word, k + 1);
}