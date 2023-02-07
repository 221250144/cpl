#include <stdio.h>

typedef struct {
    char name_of_person[25];
    int gong;
    int shou;
    int jishu;
} Person ;

typedef struct {
    char name_of_team[25];
    Person person[11];
    int sum_of_gong;
    int sum_of_shou;
    int sum_of_jishu;
} Team ;
Team teams[1000];

int main()
{
    int n = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", teams[i].name_of_team);
        for (int j = 0; j < 11; ++j) {
            scanf("%s%d%d%d", teams[i].person[j].name_of_person, &teams[i].person[j].gong, &teams[i].person[j].shou,
                  &teams[i].person[j].jishu);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 11; ++j) {
            teams[i].sum_of_gong += teams[i].person[j].gong;
            teams[i].sum_of_shou += teams[i].person[j].shou;
            teams[i].sum_of_jishu += teams[i].person[j].jishu;
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (teams[j].sum_of_gong < teams[j + 1].sum_of_gong) {
                Team temp;
                temp = teams[j];
                teams[j] = teams[j + 1];
                teams[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%s ",teams[i].name_of_team);
    }
    printf("\n");

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (teams[j].sum_of_shou < teams[j + 1].sum_of_shou) {
                Team temp;
                temp = teams[j];
                teams[j] = teams[j + 1];
                teams[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%s ",teams[i].name_of_team);
    }
    printf("\n");

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (teams[j].sum_of_jishu < teams[j + 1].sum_of_jishu) {
                Team temp;
                temp = teams[j];
                teams[j] = teams[j + 1];
                teams[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%s ",teams[i].name_of_team);
    }

    return 0;
}