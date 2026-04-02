int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * temperaturesSize);
    for (int i = 0; i < temperaturesSize; i++) {
        result[i] = 0;
    }
    int stack[temperaturesSize]; 
    int top = -1;
    for (int i = 0; i < temperaturesSize; i++) {
        while (top != -1 && temperatures[i] > temperatures[stack[top]]) {
            int prevIndex = stack[top--];
            result[prevIndex] = i - prevIndex;
        }
        stack[++top] = i;
    }
    *returnSize = temperaturesSize;
    return result;
}