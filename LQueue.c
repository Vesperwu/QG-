#include "LQueue.h" 
#include <stdio.h>
#include <string.h>
#include <malloc.h>

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
	
	Node *p = malloc(sizeof(Node));
	Q->front = p;
	Q->rear = p;
	Q->front->next = NULL;
	Q->length = 0;
	
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	Node* p = malloc(sizeof(Node));
	while (Q->front->next)
	{
		p = Q->front->next;
		Q->front->next = Q->front->next->next;
		free(p);
		Q->length--;
	}
	Q->rear = Q->front;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if (Q->length==0)
	{
		printf("�˶���Ϊ��\n");
		return TRUE;
	}
	else
	{
		printf("�˶��в�Ϊ��\n");
		return FALSE;
	}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue* Q, void* e)
{
	if (!Q) 
	{
		return FALSE;
	}
	unsigned int typeSize;
	if (datatype[0] == 'i') 
	{
		typeSize = sizeof(int);
		printf("��ͷ��������: % d\n", *(int*)Q->front->next->data);
	}
	else if (datatype[0] == 'd')
	{
		typeSize = sizeof(double);
		printf("��ͷ��������: %lf\n", *(double*)Q->front->next->data);
	}
	else if (datatype[0] == 'c') 
	{
		typeSize = sizeof(char);
		printf("��ͷ��������: %c\n", *(char*)Q->front->next->data);
	}
	else {
		typeSize = sizeof(Q->front->next->data);

	}

	return TRUE;
}


/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
	if (!Q)
	{
		return FALSE;
	}
	else
	{
		printf("�����еĳ���Ϊ%d\n", Q->length);
		return TRUE;
	}

}
/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue * Q, void* data)
{
		Node* p = (Node*)malloc(sizeof(Node));
		if (!p) {

			return FALSE;
		}
		p->data = (void*)malloc(21);
		memcpy(p->data, data, 20);
		p->next = NULL;
		Q->rear->next = p;
		Q->rear = p;
		Q->length++;
		return TRUE;
}



/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
	if (!Q)
	{
		return FALSE;
	}
	else
	{
		Node* p = malloc(sizeof(Node));
		p = Q->front->next;
		Q->front->next = p->next;
		free(p);
		Q->length--;
		return  TRUE;
	}
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
		Node* p = malloc(sizeof(Node));
		while (Q->front->next)
		{
			p = Q->front->next;
			Q->front->next = Q->front->next->next;
			free(p);
			Q->length--;
		}
	    Q->rear = Q->front;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue * Q, void (*foo)(void* q))
{
	    num = 0;
		Node* p;
		if (Q->length==0)
		{

			return FALSE;
		}
		int i = 0;
		p = Q->front->next;
		
		while (p)
		{
			foo(p->data);
			p = p->next;
		}
		printf("\n");
		return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void* q)
	{
		if (datatype[num] == 'i') 
		{
			printf("%d  ", *(int*)q);
			num++;
		}
		else if (datatype[num] == 'd')
		{
			printf("%.2f  ", *(double*)q);
			num++;
		}
		else if (datatype[num] == 'c') 
		{
			printf("%c  ", *(char*)q);
			num++;
		}
	}



/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/



