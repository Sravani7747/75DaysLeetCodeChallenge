double findMaxAverage(int* nums, int numsSize, int k) {
    int sum = 0;

    for (int j = 0; j < k; j++) {
        sum += nums[j];
    }

    int maxSum = sum;

    for (int i = k; i < numsSize; i++) {
        sum += nums[i];
        sum -= nums[i - k];

        if (sum > maxSum) {
            maxSum = sum;
        }
    }

    return (double)maxSum / k;
}