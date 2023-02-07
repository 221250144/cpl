#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Process(char *a,int len) ;

int *ans;
int cnt = 0;

int main()
{
    ans = malloc(5000 * sizeof (*ans));
    char *a = malloc(5000 * sizeof (*a));
    while (scanf("%s", a) != EOF) {
        size_t lens = strlen(a);
        char *position = strchr(a, ';');
        if (position == NULL) {
            Process(a, lens);
        } else {
            char *before = malloc(5000 * sizeof(*before));
            strncpy(before, a, position - a);
            *(before + (position - a)) = '\0';
            Process(before, strlen(before));
            *(ans + cnt) = 6;
            cnt++;
            Process((position + 1), strlen(position + 1));

            free(before);
        }
    }

    for (int i = 0; i < cnt; ++i) {
        switch (*(ans + i)) {
            case 1 : printf("reserved ");
                break;
            case 2 : printf("operator ");
                break;
            case 3 : printf("variable ");
                break;
            case 4 : printf("float ");
                break;
            case 5 : printf("integer ");
                break;
            case 6 : printf("\n");
                break;
        }
    }

    free(a);
    free(ans);
    return 0;
}

int Process(char *a,int len) {
    int ture = 1;
    if (len == 0) {
        return 0;
    } else {
        char *t1 = strchr(a, '.');
        if (strcmp(a, "const") == 0 || strcmp(a, "int") == 0 || strcmp(a, "float") == 0 || strcmp(a, "double") == 0 ||
            strcmp(a, "long") == 0 || strcmp(a, "long") == 0 || strcmp(a, "static") == 0 || strcmp(a, "void") == 0 ||
            strcmp(a, "char") == 0 || strcmp(a, "extern") == 0 || strcmp(a, "return") == 0 || strcmp(a, "break") == 0 ||
            strcmp(a, "enum") == 0 || strcmp(a, "struct") == 0 || strcmp(a, "typedef") == 0 ||
            strcmp(a, "union") == 0 || strcmp(a, "goto") == 0) {
            *(ans + cnt) = 1;
            ture = 0;
        } else if (*a == '+' || *a == '-' || *a == '*' || *a == '/' || *a == '=' || *a == '>' || *a == '<' ||
                   strcmp(a, "!=") == 0 || strcmp(a, ">=") == 0 || strcmp(a, "<=") == 0) {
            *(ans + cnt) = 2;
            ture = 0;
        } else if (*a == '_' || (*a >= 'A' && *a <= 'Z') || (*a >= 'a' && *a <= 'z')) {
            if (len == 1) {
                *(ans + cnt) = 3;
                ture = 0;
            } else {
                for (int i = 1; i < len; ++i) {
                    if (!(*(a + i) == '_' || (*(a + i) >= 'A' && *(a + i) <= 'Z') ||
                        (*(a + i) >= 'a' && *(a + i) <= 'z') ||
                        (*(a + i) >= '0' && *(a + i) <= '9'))) {
                        break;
                    }
                    if (i == len - 1) {
                        *(ans + cnt) = 3;
                        ture = 0;
                    }
                }
            }
        } else if (t1 != NULL) {
            char *t3 = strchr(t1 + 1, '.');
            if (t3 == NULL) {
                for (int i = 0; i < len; ++i) {
                    if (!((*(a + i) >= '0' && *(a + i) <= '9') || *(a + i) == '.')) {
                        break;
                    }
                    if (i == len - 1) {
                        *(ans + cnt) = 4;
                        ture = 0;
                    }
                }
            }
        } else if (t1 == NULL) {
            for (int i = 0; i < len; ++i) {
                if (!((*(a + i) >= '0' && *(a + i) <= '9') || *(a + i) == '.')) {
                    break;
                }
                if (i == len - 1) {
                    *(ans + cnt) = 5;
                    ture = 0;
                }
            }
        }
        if (ture == 1) {
            printf("Compile Error");
            exit(0);
        }
        cnt++;
    }

    return 0;
}