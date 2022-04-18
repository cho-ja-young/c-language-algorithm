#include<stdio.h>
#include<stdlib.h> // rand() �Լ� ���� ���̺귯�� 
#include<time.h> // time() �Լ� ���� ���̺귯��


struct nodetype
{
    keytype key;
    nodetype* link;
}
typedef nodetype* node_pointer;


// ��� ���� 
//numdigits : ���� �ƴ� ���� n���� �� ���� ����Ʈ masterlist, 
//�� �������� �������� �ִ� ������ ��Ÿ���� ����
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
        list[j] = NULL; // ���̸� ����. 
    }
    p = masterlist;
    while (p != NULL) {
        j = value of ith digit (from the right) in p -> key;
        // j = p -> key���� (������) i��° ������ ��
        link p to the end of list[j];
        // p�� list[j]�� ���� ��ũ;
        p = p -> link;
    }
}

void coalesce (node_pointer& masterlist, node_pointer& list)
{
    index j;

    masterlist = NULL; // masterlist�� ����. 
    for (j=0; j <= 9; j++) {
        // list[j]�� �ִ� ������� masterlist�� ���� ��ũ;
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
        quick_sort(array, 0, n-1); // 100, 500, 1000, 5000, 10000

         // ���� ���� �ð� 
        end = (double)clock() / CLOCKS_PER_SEC;

        p_time = end-start;
        printf("���α׷� ���� �ð� : %.9lf\n", p_time);

        sum += p_time;
    }

    printf("�� test case�� ���� 5ȸ �ݺ� ������ ����� ��հ� : %.9lf\n", sum/5);
	
    
    return 0;
}
