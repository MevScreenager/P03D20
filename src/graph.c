#include<stdio.h>
#include<string.h>

void drawfield(int *field);
int input();
int function(int symbol, int last, int count, int i, int *y);
void number();
void operation();
int parentheses = 0;

int main() {
    int field[25][80], i = 0;
    int y[1000];
    char ychar[1000];
    for (int i= 0; i < 25; i++)
        for (int j = 0; j < 80; j++)
            field[i][j] = 0;
    // drawfield((int*) field);
    fgets(ychar, 1000, stdin);
    for (int i = 0; i < 1000; i++)
        y[i] = (int) ychar[i];
    for (int i = 0; y[i]; i++) {
        i = function(y[i], 1, 0, i, y);
        operation(y[i]);
    }
}

void drawfield(int *field) {
    for (int i = 0; i < 25; i++)
        for (int j = 0; j < 80; j++) {
            if (i == 24 && j == 79) {
                if (field[i + j] == 0) printf(".");
                else printf("*");
                break;
            }
            if (j == 79) {
                if (field[i + j] == 0) printf(".\n");
                else printf("*\n");
                break;
            }
            if (field[i + j] == 0) printf(".");
            else printf("*");
        }

}

int input() {
    int parentheses = 0;
    while (!feof(stdin)) {
        int c = getchar();
        switch (c) {
            case '(':
                parentheses++;
                break;
            case ')':
                parentheses--;
                break;
        }
    }
    if (parentheses != 0) return 0;
    return 1;
}

int function(int symbol, int last, int count, int i, int *y) {
    // char c;
    // scanf("%c", &c);
    // symbol = (int) c;
    i++;
    switch (symbol) {
        case 's':
            if (count == 2) { printf("cos"); break; }
            function(y[i], symbol, ++count, i, y);
            break;
        case 'c':
            function(y[i], symbol, ++count, i, y);
            break;
        case 't':
            if (count == 3) { printf("sqrt"); break; }
            function(y[i], symbol, ++count, i, y);
            break;
        case 'l':
            function(y[i], symbol, ++count, i, y);
            break;
        case 'i':
            function(y[i], symbol, ++count, i, y);
            break;
        case 'o':
            function(y[i], symbol, ++count, i, y);
            break;
        case 'a':
            function(y[i], symbol, ++count, i, y);
            break;
        case 'q':
            function(y[i], symbol, ++count, i, y);
            break;
        case 'n':
            if (count == 2 && last == 'i') { printf("sin"); break; }
            if (count == 2 && last == 'a') { printf("tan"); break; }
            if (count == 1 && last == 'l') { printf("ln"); break; }
            function(y[i], symbol, ++count, i, y);
            break;
        case 'g':
            if (count == 2) { printf("ctg"); break; }
            function(y[i], symbol, ++count, i, y);
            break;
        case 'r':
            function(y[i], symbol, ++count, i, y);
            break;
        //default: operation(symbol); break;
    } return i;
}

// void parenthese() {
//     switch (c) {
//         case '(':
//             parentheses++;
//             break;
//         case ')':
//             parentheses--;
//             break;
//     }
// }

void number() {
    int n;
    scanf("%d", &n);
    switch (n) {
        case 0: break;
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: break;
        case 5: break;
        case 6: break;
        case 7: break;
        case 8: break;
        case 9: break;
    }
}

void operation(int symbol) {
    // if (symbol == 0) {
    //     char c;
    //     scanf("%c", &c);
    //     switch (c) {
    //         case '+': break;
    //         case '-': break;
    //         case '*': break;
    //         case '/': break;
    //     }
    // } else {
        switch (symbol) {
            case '+': printf("+"); break;
            case '-': printf("+"); break;
            case '*': printf("+"); break;
            case '/': printf("+"); break;
        }
    // }

}
