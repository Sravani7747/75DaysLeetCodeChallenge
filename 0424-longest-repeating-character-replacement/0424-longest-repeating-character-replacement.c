int characterReplacement(char* s, int k) {
    int freq[26] = {0};
    int l = 0, r = 0;
    int maxFreq = 0;
    int maxLen = 0;
    while (s[r] != '\0') {
        freq[s[r] - 'A']++;
        if (freq[s[r] - 'A'] > maxFreq) {
            maxFreq = freq[s[r] - 'A'];
        }
        while ((r - l + 1) - maxFreq > k) {
            freq[s[l] - 'A']--;
            l++;
        }
        if ((r - l + 1) > maxLen) {
            maxLen = r - l + 1;
        }
        r++;
    }
    return maxLen;
}