#include "LinkStack.h"
#include "stdio.h"

void Menu()
{
	printf("   **************  系统功能菜单   **************        \n");
	printf("   *  1.链栈初始化      **      2.判断栈是否为空        \n");
	printf("   *  3.获得栈顶元素    **      4.清空栈                \n");
	printf("   *  5.销毁栈          **      6.检测栈长度            \n");
	printf("   *  7.入栈            **      8.出栈                  \n");
	printf("                    9.退出系统                          \n");
};
int main()
{
	int sign;//选择要进行的操作
	int ret;//检测非法输入
	int status=0;//检测是否已初始化
	LinkStack s;

	while (1)
	{
		system("cls");
		Menu();
		printf("\n请选择要进行的操作:");
		ret = scanf_s("%d", &sign);
		while (ret != 1)
		{
			while (getchar() != '\n');
			printf("输入错误,请重新输入\n");
			Menu();
			ret = scanf_s("%d", &sign);
		}//检测非法输入 
		if (sign > 9 || sign <= 0)
		{
			printf("error!请输入一个1-9的整数\n\n");
		}
		else
		{
			switch (sign)
			{
			case 1:
			{
				initLStack(&s);//初始化
				if (initLStack(&s) == SUCCESS)
				{
					//printf("%d", s.count);
					printf("链栈初始化成功\n");
					status = 1;
				}
				break;
			}
			case 2:
			{
				if (status)
					isEmptyLStack(&s);
				else
				{
					printf("链栈还未初始化,请先初始化\n");
				}
				break;
			}
			case 3:
			{
				int e;
				if (status)
				{
					getTopLStack(&s, &e);
					printf("栈顶的元素是%d\n", e);
				}
				else
				{
					printf("链栈还未初始化,请先初始化\n");
				}
				break;
			}
			case 4:
			{
				if (status)
				{
					clearLStack(&s);
					break;
				}
				else
				{
					printf("链栈还未初始化,请先初始化\n");
				}
				break;

			}
			case 5:
			{

				if (status)
				{
					destroyLStack(&s);
					break;
				}
				else
				{
					printf("链栈还未初始化,请先初始化\n");
				}
				break;
			}

			case 6:
			{
				if (status)
				{
					int Length;
					LStackLength(&s, &Length);
					printf("栈的长度为%d", Length);
					break;
				}
				else
				{
					printf("链栈还未初始化,请先初始化\n");
				}
				break;
			}
			case 7:
			{
				if (status)
				{
					int data;
					printf("要入栈的数据:");
					scanf_s("%d", &data);
					pushLStack(&s, data);
				}

				else
				{
					printf("链栈还未初始化,请先初始化\n");
				}
				break;
			}
			case 8:
			{
				if (status)
				{
					int data;
					popLStack(&s, &data);
					printf("出栈的数据为%d", data);
				}

				else
				{
					printf("链栈还未初始化,请先初始化\n");
				}
				break;
			}
			case 9:
			{
				break;
			}
			}
		
			if (sign==9)
			{
				break;
			}
		}
		printf("请按回车返回\n");
		while (getchar() != '\n');
		while (getchar() != '\n');
	}
	return 0;
}
