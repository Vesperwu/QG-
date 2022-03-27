#include "LinkStack.h" 
#include <stdio.h>
#include <malloc.h>
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack* s)
{
	if (!s)
		return ERROR;
	//�ж��Ƿ��ʼ��
	s->top = NULL;//������ջ
	s->count = 0;//ջ�ĳ���

	return SUCCESS;

}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s)
{
	if (s->count==0)//���ջΪ��
	{
		printf("���ջΪ��\n");
		return ERROR;
	}
	else
	{
		printf("���ջ��Ϊ��\n");
		return SUCCESS;
	};
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e)
{	
	if (!s)
	{
		return ERROR;
	}
	*e = s->top->data;
	return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack *s)
{
	
	if (!s)
	{
		return ERROR;
	}
	else
	{
		while (s->count!=0)
		{	
			LinkStackPtr q = (LinkStackPtr)malloc(sizeof(StackNode));
			q = s->top;
			s->top = s->top->next;
			free(q);
			s->count--;
		}
	}
	 
}

//����ջ
Status destroyLStack(LinkStack *s)
{
	if (!s)
		return ERROR;//���ջΪ��
	else
	{
		while (s->count != 0)
		{
			LinkStackPtr q = (LinkStackPtr)malloc(sizeof(StackNode));
			q = s->top;
			s->top = s->top->next;
			free(q);
			s->count--;
		}
	}
	//free(s->top);
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack *s,int *length)
{
	if (!s)
		return ERROR;
	else
	{
		*length = s->count;
		return SUCCESS;
	}
}
//��ջ
Status pushLStack(LinkStack *s,ElemType data)
{
	LinkStackPtr S = (LinkStackPtr)malloc(sizeof(StackNode));//����һ�����
	if (!S)
	   return ERROR;
	S->data = data;
	S->next = s->top;//
	s->top = S;//ջ��ָ��ָ�������ɵ�S���
	s->count++;//�����������
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data)
{	
	if (!s)
	 return ERROR;
	LinkStackPtr q = (LinkStackPtr)malloc(sizeof(StackNode));//����һ�����������Ҫ��ջ������
	q = s->top;
	s->top=s->top->next;
	*data = q->data;
	free(q);
	s->count--;
	return SUCCESS;

}


