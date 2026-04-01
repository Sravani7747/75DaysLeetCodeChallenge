int evalRPN(char** tokens, int tokensSize) {
    int stack[10000];
    int top = -1;
    for (int i = 0; i < tokensSize; i++) {
        if (strcmp(tokens[i], "+") == 0 ||
            strcmp(tokens[i], "-") == 0 ||
            strcmp(tokens[i], "*") == 0 ||
            strcmp(tokens[i], "/") == 0) {
            int a = stack[top--];
            int b = stack[top--];
            int result;
            if (strcmp(tokens[i], "+") == 0)
                result = b + a;
            else if (strcmp(tokens[i], "-") == 0)
                result = b - a;
            else if (strcmp(tokens[i], "*") == 0)
                result = b * a;
            else
                result = b / a; 
            stack[++top] = result;
        }
        else {
            stack[++top] = atoi(tokens[i]);
        }
    }
    return stack[top];
}