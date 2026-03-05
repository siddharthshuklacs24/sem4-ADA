int minimumTimeToInitialState(char* word, int k) {
    int n = strlen(word);
    int time = 1;

    // Check every possible shift until the word is entirely gone
    for (int i = k; i < n; i += k) {
        // 'i' represents the number of characters removed (t * k)
        // We compare the remaining suffix (word + i) 
        // with the start of the original word
        // The length to compare is the remaining length: n - i
        if (strncmp(word + i, word, n - i) == 0) {
            return time;
        }
        time++;
    }

    // If no prefix match was found, we must have shifted 
    // the entire original word out.
    return time;
}
