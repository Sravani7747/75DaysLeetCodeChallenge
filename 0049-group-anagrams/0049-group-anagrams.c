
int cmpChar(const void *a, const void *b)
{
    return (*(char*)a - *(char*)b);
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) 
{
    char ***result = (char ***)malloc(strsSize * sizeof(char **));
    *returnColumnSizes = (int *)malloc(strsSize * sizeof(int));

    char **sorted = (char **)malloc(strsSize * sizeof(char *));
    int *visited = (int *)calloc(strsSize, sizeof(int));

    int groupCount = 0;

    // Create sorted version of each string
    for(int i = 0; i < strsSize; i++)
    {
        sorted[i] = strdup(strs[i]);
        qsort(sorted[i], strlen(sorted[i]), sizeof(char), cmpChar);
    }

    for(int i = 0; i < strsSize; i++)
    {
        if(visited[i]) continue;

        result[groupCount] = (char **)malloc(strsSize * sizeof(char *));
        int count = 0;

        for(int j = i; j < strsSize; j++)
        {
            if(!visited[j] && strcmp(sorted[i], sorted[j]) == 0)
            {
                result[groupCount][count++] = strs[j];
                visited[j] = 1;
            }
        }

        (*returnColumnSizes)[groupCount] = count;
        groupCount++;
    }

    *returnSize = groupCount;
    return result;
}