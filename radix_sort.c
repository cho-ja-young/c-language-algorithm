#include<stdio.h>
#include<stdlib.h> // rand() 함수 포함 라이브러리 
#include<time.h> // time() 함수 포함 라이브러리


struct nodetype
{
    keytype key;
    nodetype* link;
}
typedef nodetype* node_pointer;


// 기수 정렬 
//numdigits : 음이 아닌 정수 n개로 된 연결 리스트 masterlist, 
//각 정수에서 십진수의 최대 개수를 나타내는 정수
void radix_sort (int array[], int length, int numdigits)
{
    int i, ex, max;
    int k = 0;
    // node_pointer list[0...9];

    for (i = 1; i <= numdigits; i++) {
        distribute(masterlist, list, i);
        coalesce(masterlist, list);
    }
}

void distribute (node_pointer& masterlist, node_pointer& list, index i) 
{
    int j;
    node_pointer p;

    for (j=0; j <= 9; j++) {
        list[j] = NULL; // 더미를 비운다. 
    }
    p = masterlist;
    while (p != NULL) {
        j = value of ith digit (from the right) in p -> key;
        // j = p -> key에서 (오른쪽) i번째 숫자의 값
        link p to the end of list[j];
        // p를 list[j]의 끝에 링크;
        p = p -> link;
    }
}

void coalesce (node_pointer& masterlist, node_pointer& list)
{
    index j;

    masterlist = NULL; // masterlist를 비운다. 
    for (j=0; j <= 9; j++) {
        // list[j]에 있는 마디들을 masterlist의 끝에 링크;
    }
}


int main(void)
{
	int i, j, n, k;
    int length;
    double start, end;
    double p_time = 0;
    double sum = 0; // 수행 결과 시간 저장

    // 5번씩 반복 수행 
    int count = 5;
    for (i=1; i<=count; i++) {
		printf("%d차 수행\n", i);
		
		printf("정렬할 숫자 개수를 입력하세요 : ");
    	scanf("%d", &n);

		int *array; 
	    array = malloc(sizeof(int)*n);
	    srand((unsigned int)time(NULL)); // 매번 다른 시드값 생성 
	    int random = 0;
	    
        length = sizeof(array) / sizeof(int);

        for (k=0; k<n; k++) {
            random = rand()%20000+1; // 난수 생성 
            array[k] = random;
        }
        
        // 정렬 시작 시간
        start = (double)clock() / CLOCKS_PER_SEC;
        
        // 정렬 함수 호출 
        quick_sort(array, 0, n-1); // 100, 500, 1000, 5000, 10000

         // 정렬 끝난 시간 
        end = (double)clock() / CLOCKS_PER_SEC;

        p_time = end-start;
        printf("프로그램 수행 시간 : %.9lf\n", p_time);

        sum += p_time;
    }

    printf("각 test case에 대해 5회 반복 실행한 결과의 평균값 : %.9lf\n", sum/5);
	
    
    return 0;
}
