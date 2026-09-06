bool isValid(char* s) {
    int len = strlen(s);
    if (len % 2 != 0) {
        return false;
    }
    char stack[len];
    int top = -1;
    for (int i = 0; s[i] != '\0'; i++) {
        char current = s[i];
        if (current == '(' || current == '[' || current == '{') {
            stack[++top] = current;
        } 
        else {
            if (top == -1) {
                return false;
            }
            
            char open = stack[top--];
            if ((current == ')' && open != '(') ||
                (current == ']' && open != '[') ||
                (current == '}' && open != '{')) {
                    return false;
                }
        }
    }
    return top == -1;
}