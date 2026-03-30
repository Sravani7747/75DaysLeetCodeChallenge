int characterReplacement(char* s, int k) {
    int freq[26] = {0};
    int left = 0, right = 0;
    int maxFreq = 0;
    int maxLen = 0;
    while (s[right] != '\0') {
        freq[s[right] - 'A']++;
        if (freq[s[right] - 'A'] > maxFreq) {
            maxFreq = freq[s[right] - 'A'];
        }
        while ((right - left + 1) - maxFreq > k) {
            freq[s[left] - 'A']--;
            left++;
        }
        if ((right - left + 1) > maxLen) {
            maxLen = right - left + 1;
        }
        right++;
    }
    return maxLen;
}