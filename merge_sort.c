#include<stdio.h>
#include<stdlib.h> // rand() 함수 포함 라이브러리 
#include<time.h> // time() 함수 포함 라이브러리

// 병합 정렬 정리  
void merge_sort(int array[], int left, int right) {
    int middle;

    if (left < right) {
        middle = (left+right)/2; // 중간 위치 계산
        merge_sort(array, left, middle); // 앞쪽 리스트 정렬 
        merge_sort(array, middle+1, right); // 뒤쪽 리스트 정렬 
        merge(array, left, middle, right); // 두개의 부분 배열을 병합
    }
}

// 합병 정렬 시간 측정 
void merge(int array[], int left, int middle, int right) {

    // 병합 정렬 알고리즘 구현 
    int i = left;
	int j = middle+1;
	int k = left;
	int n = right+1;
	int l = 0;

    int *tmp; 
    tmp = malloc(sizeof(int)*n); // 새로운 배열  

    // 분할 정렬된 array 병합 
    while (i<=middle && j<=right) {
        if (array[i]<=array[j]) {
            tmp[k++] = array[i++];
        }
        else {
            tmp[k++] = array[j++];
        }
    }

	// 남아 있는 값들을 일괄 복사
    while(i<=middle) {
    	tmp[k++] = array[i++];
	}
	
	// 남아 있는 값들을 일괄 복사
    while(j<=right) {
    	tmp[k++] = array[j++];
	}

    // 배열 tmp[](임시 배열)의 리스트를 배열 array[]로 재복사
    for(l = left; l <= right; l++) {
        array[l] = tmp[l];
    }

}

int main(void)
{
	int i, j, temp, n, k;
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
        merge_sort(array, 0, n-1); // 100, 500, 1000, 5000, 10000

         // 정렬 끝난 시간 
        end = (double)clock() / CLOCKS_PER_SEC;

        p_time = end-start;
        printf("프로그램 수행 시간 : %.9lf\n", p_time);

        sum += p_time;
    }

    printf("각 test case에 대해 5회 반복 실행한 결과의 평균값 : %.9lf\n", sum/5);
	
    
    return 0;
}
