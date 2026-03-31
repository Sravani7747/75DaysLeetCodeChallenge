
#define MAX 1000
typedef struct {
    int stack[MAX];
    int minStack[MAX];
    int top;
} MinStack;
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->top = -1;
    return obj;
}
void minStackPush(MinStack* obj, int val) {
    if (obj->top == MAX - 1) {
        return;  
    }
    obj->top++;
    obj->stack[obj->top] = val;
    if (obj->top == 0) {
        obj->minStack[obj->top] = val;
    } else {
        if (val < obj->minStack[obj->top - 1])
            obj->minStack[obj->top] = val;
        else
            obj->minStack[obj->top] = obj->minStack[obj->top - 1];
    }
}
void minStackPop(MinStack* obj) {
    if (obj->top >= 0) {
        obj->top--;
    }
}
int minStackTop(MinStack* obj) {
    if (obj->top >= 0)
        return obj->stack[obj->top];
    return -1;
}
int minStackGetMin(MinStack* obj) {
    if (obj->top >= 0)
        return obj->minStack[obj->top];
    return -1;
}
void minStackFree(MinStack* obj) {
    free(obj);
}