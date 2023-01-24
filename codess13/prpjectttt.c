#include <stdio.h>
#include <string.h>
#include <stdbool.h>
typedef struct val {
    enum {I, F, E} type;
    union {
        int ival;
        double fval;
    } val;
} Val;
typedef struct token {
    enum {V, IN, FL, O} type;
    int le;
    char name[1010];
} Token;
typedef struct var {
    Val val;
    int le;
    char name[1010];
} Var;
int varn;
char s[1030], tmp[1030];
Var v[130];
Token tokens[1030];
bool isalph (char x) {
    if (x >= 'a' && x <= 'z') return 1;
    if (x >= 'A' && x <= 'Z') return 1;
    if (x == '_') return 1;
    return 0;
}
bool isoperator (char *x, int len) {
    if (len != 1) return 0;
    if (x[0] == '=' || x[0] == '+' || x[0] == '-' || x[0] == '*' || x[0] == '/' || x[0] == '(' || x[0] == ')') return 1;
    return 0;
}
void varcheck(int x, int *flag, int len) {
    if (!*flag) return;
    char c;
    if (isoperator(tokens[x].name, len)) {
        tokens[x].type = O;
        return;
    }
    int dot = 0, alpha = 0;
    for (int i = 0; i < len; i++) {
        c = tokens[x].name[i];
        if (c == '.') dot++;
        if (isalph(c)) alpha++;
    }
    if (alpha) {
        c = tokens[x].name[0];
        if (c >= '0' && c <= '9') {
            *flag = 0;
            return;
        }
        for (int i = 0; i < len; i++) {
            c = tokens[x].name[i];
            if (!isalph(c) && (c < '0' || c > '9')) {
                *flag = 0;
                return;
            }
        }
        tokens[x].type = V;
        return;
    }
    if (dot) {
        if (dot != 1) {
            *flag = 0;
            return;
        }
        c = tokens[x].name[0];
        if (c == '.' || (c == '0' && tokens[x].name[1] != '.')) {
            *flag = 0;
            return;
        }
        c = tokens[x].name[len - 1];
        if (c == '.') {
            *flag = 0;
            return;
        }
        for (int i = 0; i < len; i++) {
            if ((tokens[x].name[i] >= '0' && tokens[x].name[i] <= '9') || tokens[x].name[i] == '.') {
                continue;
            }
            *flag = 0;
            return;
        }
        tokens[x].type = FL;
        return;
    }
    c = tokens[x].name[0];
    if (len != 1 && (c <= '0' || c > '9')) {
        *flag = 0;
        return;
    }
    for (int i = 0; i < len; i++) {
        if (tokens[x].name[i] < '0' || tokens[x].name[i] > '9') {
            *flag = 0;
            return;
        }
    }
    tokens[x].type = IN;
}
bool change (char *x, int *t) {
    int i = 0, len = strlen(x);
    while (i < len) {
        int tmpn = 0;
        while (i < len && x[i] != ' ') {
            tmp[tmpn++] = x[i];
            i++;
        }
        *t = *t + 1;
        tokens[*t].le = tmpn;
        for (int j = 0; j < tmpn; j++) tokens[*t].name[j] = tmp[j];
        i++;
    }
    int wordflag = 1;
    for (int i = 1; i <= *t; i++) varcheck(i, &wordflag, tokens[i].le);
    if (wordflag) return 1;
    return 0;
}
bool cmp(char *x, char *y, int lenx, int leny) {
    if (lenx != leny) return 0;
    for (int i = 0; i < lenx; i++) {
        if (x[i] != y[i]) return 0;
    }
    return 1;
}
Val getnum(Token x) {
    Val res;
    if (x.type == IN) {
        res.type = I;
        res.val.ival = 0;
        for (int i = 0; i < x.le; i++) res.val.ival = res.val.ival * 10 + (x.name[i] - '0');
    } else {
        res.type = F;
        res.val.fval = 0;
        int p = 0;
        for (int i = 0; i < x.le; i++) {
            if (x.name[i] == '.') {
                p = i;
                break;
            }
        }
        for (int i = 0; i < p; i++) res.val.fval = res.val.fval * 10.0 + (x.name[i] - '0');
        double pp = 0.1;
        for (int i = p + 1; i < x.le; i++) {
            res.val.fval += pp * (x.name[i] - '0');
            pp *= 0.1;
        }
    }
    return res;
}
int find(char *x, int len) {
    for (int i = 1; i <= varn; i++) {
        if (cmp(v[i].name, x, v[i].le, len)) {
            return i;
        }
    }
    return 0;
}
int checkp(int l, int r) {
    int top = 0;
    for (int i = l; i <= r; i++) {
        if (tokens[i].name[0] == '(') {
            top++;
        } else if (tokens[i].name[0] == ')') {
            if (top) {
                top--;
            } else {
                return -1;
            }
        }
    }
    if (top != 0) {
        return -1;
    }
    if (tokens[l].name[0] != '(' || tokens[r].name[0] != ')') return 0;
    for (int i = l + 1; i <= r - 1; i++) {
        if (tokens[i].name[0] == '(') {
            top++;
        } else if (tokens[i].name[0] == ')') {
            if (top) {
                top--;
            } else {
                return 0;
            }
        }
    }
    if (top != 0) {
        return 0;
    }
    return 1;
}
Val work(Val x, Val y, char op) {
    Val res;
    if (x.type == E || y.type == E) {
        res.type = E;
        return res;
    }
    if (x.type == I && y.type == I) {
        res.type = I;
        switch (op) {
            case '+': res.val.ival = x.val.ival + y.val.ival; break;
            case '-': res.val.ival = x.val.ival - y.val.ival; break;
            case '*': res.val.ival = x.val.ival * y.val.ival; break;
            case '/': res.val.ival = x.val.ival / y.val.ival; break;
        }
    } else if (x.type == I && y.type == F) {
        res.type = F;
        switch (op) {
            case '+': res.val.fval = x.val.ival + y.val.fval; break;
            case '-': res.val.fval = x.val.ival - y.val.fval; break;
            case '*': res.val.fval = x.val.ival * y.val.fval; break;
            case '/': res.val.fval = x.val.ival / y.val.fval; break;
        }
    } else if (x.type == F && y.type == I) {
        res.type = F;
        switch (op) {
            case '+': res.val.fval = x.val.fval + y.val.ival; break;
            case '-': res.val.fval = x.val.fval - y.val.ival; break;
            case '*': res.val.fval = x.val.fval * y.val.ival; break;
            case '/': res.val.fval = x.val.fval / y.val.ival; break;
        }
    } else {
        res.type = F;
        switch (op) {
            case '+': res.val.fval = x.val.fval + y.val.fval; break;
            case '-': res.val.fval = x.val.fval - y.val.fval; break;
            case '*': res.val.fval = x.val.fval * y.val.fval; break;
            case '/': res.val.fval = x.val.fval / y.val.fval; break;
        }
    }
    return res;
}
Val eval(int l, int r) {
    Val res;
    if (l > r) {
        res.type = E;
        return res;
    }
    if (l == r) {
        if (tokens[l].type == IN) {
            res = getnum(tokens[l]);
            return res;
        } else if (tokens[l].type == FL) {
            res = getnum(tokens[l]);
            return res;
        } else if (tokens[l].type == V){
            int p = find(tokens[l].name, tokens[l].le);
            if (p) {
                return v[p].val;
            } else {
                res.type = E;
                return res;
            }
        }
        res.type = E;
        return res;
    }
    int ch = checkp(l, r);
    if (ch == 1) {
        return eval(l + 1, r - 1);
    }
    if (ch == -1) {
        res.type = E;
        return res;
    }
    int top = 0, p = 0;
    for (int i = l; i <= r; i++) {
        char c = tokens[i].name[0];
        if (c == '(') {
            top++;
            continue;
        }
        if (c == ')') {
            top--;
            continue;
        }
        if (tokens[i].type == O && top == 0) {
            char ccc = tokens[i - 1].name[0];
            if (i != l && (ccc == '+' || ccc == '-' || ccc == '*' || ccc == '/')) continue;
            if (p == 0) {
                p = i;
            } else {
                if (c == '+' || c == '-') {
                    p = i;
                } else {
                    if (tokens[p].name[0] == '*' || tokens[p].name[0] == '/') {
                        p = i;
                    }
                }
            }
        }
    }
    if (p == 0) {
        res.type = E;
        return res;
    }
    if (p == l) {
        if (tokens[p].name[0] == '-') {
            res.type = I;
            res.val.ival = -1;
            Val a = work(res, eval(p + 1, r), '*');;
            return a;
        } else {
            res.type = E;
            return res;
        }
    } else {
        Val a = work(eval(l, p - 1), eval(p + 1, r), tokens[p].name[0]);
        return a;
    }
}
void print(Val x) {
    if (x.type == I) {
        printf("%d\n", x.val.ival);
    } else {
        printf("%f\n", x.val.fval);
    }
}
int main() {
    while (gets(s)) {
        int tokenn = 0;
        if (!change(s, &tokenn)) {
            printf("Error\n");
            continue;
        }
        bool fuzhi = 0;
        for (int i = 1; i <= tokenn; i++) {
            if (tokens[i].name[0] == '=') {
                fuzhi = 1;
                break;
            }
        }
        if (fuzhi) {
            bool yufa = 1;
            int po;
            for (int i = tokenn; i >= 1; i--) {
                if (tokens[i].name[0] == '=') {
                    po = i;
                    break;
                }
            }
            for (int i = 1; i < po; i++) {
                if (i % 2 && tokens[i].type != V) {
                    yufa = 0;
                    break;
                }
                if (i % 2 == 0 && tokens[i].name[0] != '=') {
                    yufa = 0;
                    break;
                }
            }
            if (yufa == 0) {
                printf("Error\n");
                continue;
            }
            Val tmp = eval(po + 1, tokenn);
            if (tmp.type == E) {
                printf("Error\n");
                continue;
            }
            for (int i = 1; i < po; i++) {
                if (tokens[i].type != V) continue;
                int p = find(tokens[i].name, tokens[i].le);
                if (p) {
                    v[p].val = tmp;
                } else {
                    varn++;
                    v[varn].le = tokens[i].le;
                    for (int j = 0; j < tokens[i].le; j++) v[varn].name[j] = tokens[i].name[j];
                    v[varn].val = tmp;
                }
            }
            print(tmp);
        } else {
            Val tmp = eval(1, tokenn);
            if (tmp.type == E) {
                printf("Error\n");
                continue;
            }
            print(tmp);
        }
    }
    return 0;
}