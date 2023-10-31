#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0;
    int *p = NULL;
    int sum = 0;
    int i, data;
    char newline; // 개행 문자를 임시로 저장할 변수

    while (1) {
        printf("%d번째 숫자 : ", n + 1);
        if (scanf("%d%c", &data, &newline) != 2 || newline != '\n') {
            break; // 숫자가 아닌 입력 또는 Enter 키 입력 시 루프를 종료
        }

        n++;

        // 메모리를 새로 할당하고 이전 데이터를 복사
        int *new_p = (int *)realloc(p, sizeof(int) * n);
        if (new_p == NULL) {
            free(p);
            printf("메모리 할당 실패.\n");
            return 1;
        }
        p = new_p;
        p[n - 1] = data;

        // 짝수의 합 계산
        if (data % 2 == 0) {
            sum += data;
        }
    }

    for (i = 0; i < n; i++) {
        if (p[i] % 2 == 0) {
            sum += p[i];
        }
    }

    printf("짝수의 합 ==> %d\n", sum);

    free(p);

    return 0;
}
