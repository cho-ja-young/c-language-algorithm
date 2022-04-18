#include<stdio.h>
#include<stdlib.h> // rand() 함수 포함 라이브러리 
#include<time.h> // time() 함수 포함 라이브러리

// 퀵 정렬 정리  
void quick_sort(int array[], int low, int high) {
    int pivotpoint;

    if (low <= high) {
        int pivotpoint = partition(array, low, high); // 피벗포인트를 기준으로 왼쪽 오른쪽으로 나누기  
        quick_sort(array, low, pivotpoint-1); // 왼쪽 영역 정렬
        quick_sort(array, pivotpoint+1, high); // 오른쪽 영역 정렬 
    }
}

// 퀵 정렬 시간 측정 
int partition(int array[], int low, int high) {

    // 퀵 정렬 알고리즘 구현 

    int pivotitem;
    pivotitem = array[low]; // 첫번째 원소를 피벗으로 정한다.

    int i = low + 1;
    int j = high;

    // j = low-1; // 마지막 요소의 인덱스는 피벗보다 작다.

    for (i = low + 1; i<=high; i++) {
        while (i <= high && pivotitem >= array[i]) // 피벗보다 큰 값을 찾는 과정 
        {
            i++; // low를 오른쪽으로 이동 
        }
        while (j >= (low + 1)  && pivotitem <= array[high]) // 피벗보다 작은 값을 찾는 과정 
        {
            high--; // high를 왼쪽으로 이동
        }
        if (i <= j) {
            // j++;
            exchange(array, i, j);
        }
    }
    exchange(array, low, j);

    return j; // 바뀐 피멋의 위치 정보를 반환 

}

void exchange(int array[], int ap, int bp) 
{
    int temp;
    temp = array[ap];
    array[ap] = array[bp];
    array[bp] = temp;
}


int main(void)
{
	int i, j, n, k;
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

