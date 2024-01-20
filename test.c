#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void remove_whitespace(char s[101]) {
    int cnt = -1;
    int sz = (int)strlen(s);
    for (int i = 0; i < sz; ++i) {
        if (s[i] != ' ') {
            s[++cnt] = s[i];
        }
    }
    for (int i = cnt + 1; i < sz; ++i) {
        s[i] = '\0';
    }
}

int is_valid_char(char c) {
    return (c >= '0' && c <= '9') || c == 'x' || c == '^' || c == '+' || c == '-' || c == '(' || c == ')';
}

int is_operator(char c) {
    return c == '^' || c == '*' || c == '/' || c == '+' || c == '-';
}

int is_operator_priority(char c1, char c2) {
    if (c1 == '^') return 3;
    if (c1 == '*' || c1 == '/') return (c2 == '^') ? -1 : 2;
    if (c1 == '+' || c1 == '-') return (c2 == '^' || c2 == '*' || c2 == '/') ? -1 : 1;
    return -1;
}

double evaluate_polynomial(double x, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; ++i) {
        result *= x;
    }
    return result;
}

void process_expression(char expression[101]) {
    double result_stack[101] = {0};
    double operand_stack[101] = {0};
    int result_stack_index = -1;
    int operand_stack_index = -1;

    int length = strlen(expression);
    for (int i = 0; i < length; ++i) {
        if (!is_valid_char(expression[i])) {
            printf("Invalid character: %c\n", expression[i]);
            return;
        }

        if (expression[i] == '(') {
            result_stack[++result_stack_index] = expression[i];
        } else if (expression[i] == ')') {
            while (result_stack_index >= 0 && result_stack[result_stack_index] != '(') {
                double operand2 = operand_stack[operand_stack_index--];
                double operand1 = operand_stack[operand_stack_index--];
                char operator = result_stack[result_stack_index--];

                double temp_result = 0.0;
                switch (operator) {
                    case '^':
                        temp_result = evaluate_polynomial(operand1, (int)operand2);
                        break;
                    case '*':
                        temp_result = operand1 * operand2;
                        break;
                    case '/':
                        if (operand2 == 0) {
                            printf("Error: Division by zero\n");
                            return;
                        }
                        temp_result = operand1 / operand2;
                        break;
                    case '+':
                        temp_result = operand1 + operand2;
                        break;
                    case '-':
                        temp_result = operand1 - operand2;
                        break;
                }

                operand_stack[++operand_stack_index] = temp_result;
            }

            // Pop '('
            result_stack_index--;
        } else if (expression[i] == 'x') {
            operand_stack[++operand_stack_index] = 1.0;
        } else if (expression[i] >= '0' && expression[i] <= '9') {
            int value = 0;
            while (expression[i] >= '0' && expression[i] <= '9') {
                value = value * 10 + (expression[i] - '0');
                ++i;
            }
            --i; // To adjust for the extra increment in the loop
            operand_stack[++operand_stack_index] = (double)value;
        } else if (is_operator(expression[i])) {
            while (result_stack_index >= 0 && is_operator_priority(expression[i], result_stack[result_stack_index]) >= 0) {
                double operand2 = operand_stack[operand_stack_index--];
                double operand1 = operand_stack[operand_stack_index--];
                char operator = result_stack[result_stack_index--];

                double temp_result = 0.0;
                switch (operator) {
                    case '^':
                        temp_result = evaluate_polynomial(operand1, (int)operand2);
                        break;
                    case '*':
                        temp_result = operand1 * operand2;
                        break;
                    case '/':
                        if (operand2 == 0) {
                            printf("Error: Division by zero\n");
                            return;
                        }
                        temp_result = operand1 / operand2;
                        break;
                    case '+':
                        temp_result = operand1 + operand2;
                        break;
                    case '-':
                        temp_result = operand1 - operand2;
                        break;
                }

                operand_stack[++operand_stack_index] = temp_result;
            }

            result_stack[++result_stack_index] = expression[i];
        }
    }

    while (result_stack_index >= 0) {
        double operand2 = operand_stack[operand_stack_index--];
        double operand1 = operand_stack[operand_stack_index--];
        char operator = result_stack[result_stack_index--];

        double temp_result = 0.0;
        switch (operator) {
            case '^':
                temp_result = evaluate_polynomial(operand1, (int)operand2);
                break;
            case '*':
                temp_result = operand1 * operand2;
                break;
            case '/':
                if (operand2 == 0) {
                    printf("Error: Division by zero\n");
                    return;
                }
                temp_result = operand1 / operand2;
                break;
            case '+':
                temp_result = operand1 + operand2;
                break;
            case '-':
                temp_result = operand1 - operand2;
                break;
        }

        operand_stack[++operand_stack_index] = temp_result;
    }

    printf("Result: %.2fx^0 + %.2fx^1\n", operand_stack[operand_stack_index], operand_stack[operand_stack_index - 1]);
}

int main() {
    char expression[101];
    fgets(expression, sizeof(expression), stdin);
    remove_whitespace(expression);

    printf("Input: %s\n", expression);

    process_expression(expression);

    return 0;
}
