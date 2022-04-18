#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__
 
#define TRUE 1
#define FALSE 0
 
typedef int Data; 
 
typedef struct _node
{
    Data data;
    struct _node *next; // �̷��� struct�����ͷ� �����ϴ� ������ ���� 
                        //int a = 8; int *b; b = &a; ��� �ϵ��� ���� �ڷ����� ���߾��ִ°��̴�
}Node;
 
typedef struct _lQueue
{
    Node *front;
    Node *rear;
} LQueue;
 
typedef LQueue Queue;
 
void QueueInit(Queue *pq); // ť �ʱ�ȭ
int QIsEmpty(Queue *pq); // ť�� ����ִ��� Ȯ���ϴ� �Լ�
 
void Enqueue(Queue *pq, Data data); // ť�� �� ������
Data Dequeue(Queue *pq); // ť���� �� ����
Data QPeek(Queue *pq); 
 
#endif


// ��ó: https://www.crocus.co.kr/280 [Crocus]
