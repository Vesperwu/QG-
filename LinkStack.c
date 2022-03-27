#include "LinkStack.h" 
#include <stdio.h>
#include <malloc.h>
//链栈

//初始化栈
Status initLStack(LinkStack* s)
{
	if (!s)
		return ERROR;
	//判断是否初始化
	s->top = NULL;//建立空栈
	s->count = 0;//栈的长度

	return SUCCESS;

}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s)
{
	if (s->count==0)//如果栈为空
	{
		printf("这个栈为空\n");
		return ERROR;
	}
	else
	{
		printf("这个栈不为空\n");
		return SUCCESS;
	};
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e)
{	
	if (!s)
	{
		return ERROR;
	}
	*e = s->top->data;
	return SUCCESS;
}

//清空栈
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

//销毁栈
Status destroyLStack(LinkStack *s)
{
	if (!s)
		return ERROR;//如果栈为空
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

//检测栈长度
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
//入栈
Status pushLStack(LinkStack *s,ElemType data)
{
	LinkStackPtr S = (LinkStackPtr)malloc(sizeof(StackNode));//生成一个结点
	if (!S)
	   return ERROR;
	S->data = data;
	S->next = s->top;//
	s->top = S;//栈顶指针指向新生成的S结点
	s->count++;//结点数量增加
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack *s,ElemType *data)
{	
	if (!s)
	 return ERROR;
	LinkStackPtr q = (LinkStackPtr)malloc(sizeof(StackNode));//生成一个结点来接收要出栈的数据
	q = s->top;
	s->top=s->top->next;
	*data = q->data;
	free(q);
	s->count--;
	return SUCCESS;

}


