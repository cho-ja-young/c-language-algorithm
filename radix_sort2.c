#include<stdio.h>
#include<stdlib.h> // rand() 함수 포함 라이브러리 
#include<time.h> // time() 함수 포함 라이브러리
#include "ListBaseQueue.h"
using namespace std;

//struct nodetype
//{
//    keytype key;
//    nodetype* link;
//}
//typedef nodetype* node_pointer;


// 기수 정렬 
//numdigits : 음이 아닌 정수 n개로 된 연결 리스트 masterlist, 
//각 정수에서 십진수의 최대 개수를 나타내는 정수
void radix_sort (int array[], int length, int numdigits)
{
	int i;
    int numdigits = get_max_radix(array, size);
    
    queue<int> Q[10]; // 큐 10개 (1 ~ 9자리) 
    // node_pointer list[0...9];

    for (i = 1; i <= numdigits; i*=10) {
        distribute(masterlist, list, i);
        coalesce(masterlist, list);
    }
}

void distribute (node_pointer& masterlist, node_pointer& list, index i) 
{
    for(int j = 0 ; j < size ; j++){
	
			int k = 0; 
			// 자리수 
					
			if(array[j] >= i){ 
				k = (array[j] / i) % 10;
				// (1, 10, 100)보다 크면 계산하고 
				// 작으면 0으로 처리함 
				// (e.g. 10의자리에서 2 -> 02 -> 0) 
			}
			
			Q[k].push(array[j]);
		}
}

void coalesce (node_pointer& masterlist, node_pointer& list)
{
    int idx = 0;
		for(int j = 0 ; j < 10 ; j++){
			
			while(!Q[j].empty()){ 
				array[idx] = Q[j].front();
				Q[j].pop();
				idx++;
			}
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
        radix_sort(array, length, n); // 100, 500, 1000, 5000, 10000

         // 정렬 끝난 시간 
        end = (double)clock() / CLOCKS_PER_SEC;

        p_time = end-start;
        printf("프로그램 수행 시간 : %.9lf\n", p_time);

        sum += p_time;
    }

    printf("각 test case에 대해 5회 반복 실행한 결과의 평균값 : %.9lf\n", sum/5);
	
    
    return 0;
}
