#include "LQueue.h" 
#include <stdio.h>
#include <string.h>
#include <malloc.h>

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
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
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
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
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if (Q->length==0)
	{
		printf("此队列为空\n");
		return TRUE;
	}
	else
	{
		printf("此队列不为空\n");
		return FALSE;
	}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
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
		printf("队头的数据是: % d\n", *(int*)Q->front->next->data);
	}
	else if (datatype[0] == 'd')
	{
		typeSize = sizeof(double);
		printf("队头的数据是: %lf\n", *(double*)Q->front->next->data);
	}
	else if (datatype[0] == 'c') 
	{
		typeSize = sizeof(char);
		printf("队头的数据是: %c\n", *(char*)Q->front->next->data);
	}
	else {
		typeSize = sizeof(Q->front->next->data);

	}

	return TRUE;
}


/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
		printf("此数列的长度为%d\n", Q->length);
		return TRUE;
	}

}
/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
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
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
 *    @description : 清空队列
 *    @param         Q 队列指针Q
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
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
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
 *    @description : 操作函数
 *    @param         q 指针q
 
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



