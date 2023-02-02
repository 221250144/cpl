#include <stdio.h>

int main ()
{
    typedef struct {
      char name[10000];
      int age;
      int grade;
    } Person ;
    Person a[6];
    int n = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%d",a[i].name,&a[i].age,&a[i].grade);
        a[i].grade *= 1.2;
        a[i].grade = a[i].grade > 600 ? 600 : a[i].grade;
        a[i].age++;
        printf("%s %d %d\n",a[i].name,a[i].age,a[i].grade);
    }

    return 0;
}