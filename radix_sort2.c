#include<stdio.h>
#include<stdlib.h> // rand() �Լ� ���� ���̺귯�� 
#include<time.h> // time() �Լ� ���� ���̺귯��
#include "ListBaseQueue.h"
using namespace std;

//struct nodetype
//{
//    keytype key;
//    nodetype* link;
//}
//typedef nodetype* node_pointer;


// ��� ���� 
//numdigits : ���� �ƴ� ���� n���� �� ���� ����Ʈ masterlist, 
//�� �������� �������� �ִ� ������ ��Ÿ���� ����
void radix_sort (int array[], int length, int numdigits)
{
	int i;
    int numdigits = get_max_radix(array, size);
    
    queue<int> Q[10]; // ť 10�� (1 ~ 9�ڸ�) 
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
			// �ڸ��� 
					
			if(array[j] >= i){ 
				k = (array[j] / i) % 10;
				// (1, 10, 100)���� ũ�� ����ϰ� 
				// ������ 0���� ó���� 
				// (e.g. 10���ڸ����� 2 -> 02 -> 0) 
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
    double sum = 0; // ���� ��� �ð� ����

    // 5���� �ݺ� ���� 
    int count = 5;
    for (i=1; i<=count; i++) {
		printf("%d�� ����\n", i);
		
		printf("������ ���� ������ �Է��ϼ��� : ");
    	scanf("%d", &n);

		int *array; 
	    array = malloc(sizeof(int)*n);
	    srand((unsigned int)time(NULL)); // �Ź� �ٸ� �õ尪 ���� 
	    int random = 0;
	    
        length = sizeof(array) / sizeof(int);

        for (k=0; k<n; k++) {
            random = rand()%20000+1; // ���� ���� 
            array[k] = random;
        }
        
        // ���� ���� �ð�
        start = (double)clock() / CLOCKS_PER_SEC;
        
        // ���� �Լ� ȣ�� 
        radix_sort(array, length, n); // 100, 500, 1000, 5000, 10000

         // ���� ���� �ð� 
        end = (double)clock() / CLOCKS_PER_SEC;

        p_time = end-start;
        printf("���α׷� ���� �ð� : %.9lf\n", p_time);

        sum += p_time;
    }

    printf("�� test case�� ���� 5ȸ �ݺ� ������ ����� ��հ� : %.9lf\n", sum/5);
	
    
    return 0;
}
