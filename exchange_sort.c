#include<stdio.h>
#include<stdlib.h> // rand() 함수 포함 라이브러리 
#include<time.h> // time() 함수 포함 라이브러리

//교환 정렬 시간 측정 
double exchange_sort() {
    double start, end;
    double p_time = 0;

    
    // 교환 정렬 알고리즘 구현 
    int i, j, temp, n;
    printf("정렬할 숫자 개수를 입력하세요 : ");
    scanf("%d", &n);
    int *array; 
    array = malloc(sizeof(int)*n);
    srand((unsigned int)time(NULL)); // 매번 다른 시드값 생성 
    int random = 0;
	
	// 정렬 시작 시간
    start = (double)clock() / CLOCKS_PER_SEC;

    for (i=0; i<n; i++) {
        random = rand()%20000+1; // 난수 생성 
        array[i] = random;
    }

    for (i=0; i<(n-1); i++) {
        for (j=(i+1); j<n; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
	

    // 정렬 끝난 시간 
    end = (double)clock() / CLOCKS_PER_SEC;

    p_time = end-start;
    printf("프로그램 수행 시간 : %.9lf\n", p_time);

    return p_time;
}

int main(void)
{
    int i, j = 0; 
    double sum = 0; // 수행 결과 시간 저장

    // 5번씩 반복 수행 
    int count = 5;
    for (i=1; i<=count; i++) {
        printf("%d차 수행\n", i);
        // 정렬 함수 호출 
        sum += exchange_sort(); // 100, 500, 1000, 5000, 10000
    }

    printf("각 test case에 대해 5회 반복 실행한 결과의 평균값 : %.9lf\n", sum/5);
	
    
    return 0;
}
