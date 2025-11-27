#include <stdio.h>
#include <string.h>

struct Student {
    char name[20];
    int kor, eng, math, total;
};

struct Student s[100];
int cnt = 0;

void add() {
    if (cnt >= 100) { printf("가득 찼습니다.\n"); return; }

    printf("이름: "); scanf("%s", s[cnt].name);
    printf("국어 영어 수학: ");
    scanf("%d %d %d", &s[cnt].kor, &s[cnt].eng, &s[cnt].math);

    s[cnt].total = s[cnt].kor + s[cnt].eng + s[cnt].math;
    cnt++;
}

void search() {
    char name[20];
    printf("검색 이름: "); scanf("%s", name);

    for (int i = 0; i < cnt; i++) {
        if (!strcmp(s[i].name, name)) {
            printf("%s / 국:%d 영:%d 수:%d 총:%d\n",
                s[i].name, s[i].kor, s[i].eng, s[i].math, s[i].total);
            return;
        }
    }
    printf("없음\n");
}

int main() {
    int m;
    while (1) {
        printf("1.등록 2.검색 0.종료: ");
        scanf("%d", &m);
        if (m == 1) add();
        else if (m == 2) search();
        else if (m == 0) break;
    }
}
