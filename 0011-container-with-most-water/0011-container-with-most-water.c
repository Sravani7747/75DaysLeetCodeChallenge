
int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int maxArea = 0;
    while (left < right) {
        int width = right - left;
        int minHeight;
        if (height[left] < height[right])
            minHeight = height[left];
        else
            minHeight = height[right];
        int area = width * minHeight;
        if (area > maxArea)
            maxArea = area;
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return maxArea;
}