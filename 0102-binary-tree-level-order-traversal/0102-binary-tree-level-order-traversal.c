
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    int capacity = 100;
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    int qCap = 1000;
    struct TreeNode** queue = malloc(qCap * sizeof(struct TreeNode*));
    int front = 0, rear = 0;
    queue[rear++] = root;
    int level = 0;
    while (front < rear) {
        if (level >= capacity) {
            capacity *= 2;
            result = realloc(result, capacity * sizeof(int*));
            *returnColumnSizes = realloc(*returnColumnSizes, capacity * sizeof(int));
        }
        int size = rear - front;
        result[level] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[level] = size;
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            result[level][i] = node->val;
            if (rear >= qCap) {
                qCap *= 2;
                queue = realloc(queue, qCap * sizeof(struct TreeNode*));
            }
            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }
        level++;
    }
    *returnSize = level;
    free(queue);
    return result;
}