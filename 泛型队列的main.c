#include "LQueue.h"
#include <stdio.h>

void Menu()
{
	printf("   **************  系统功能菜单   **************        \n");
	printf("   *  1.队列初始化      **      2.判断队列是否为空      \n");
	printf("   *  3.获得列头元素    **      4.清空队列              \n");
	printf("   *  5.销毁队列        **      6.检测队列长度          \n");
	printf("   *  7.入队            **      8.出队                  \n");
	printf("   *  9.输出队列        **      10.退出系统             \n");

}
int main()
{
	
	int sign;//选择要进行的操作
	int ret;//检测非法输入
	int status = 0;//检测是否已初始化
	LQueue Q;

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
			ret = scanf_s("%d", &sign);
		}
		while (getchar() != '\n');

	
		//检测非法输入 
		if (sign > 10 || sign <= 0)
		{
			printf("error!请输入一个1-10的整数\n");
		}
		else
		{
			switch (sign)
			{
			case 1:
			{
				InitLQueue(&Q);//初始化
			   //printf("%d", s.count);
				printf("队列初始化成功\n");
				status = 1;
				break;
			}
			case 2:
			{
				if (status)
					IsEmptyLQueue(&Q);
				else
				{
					printf("队列还未初始化,请先初始化\n");
				}
				break;
			}
			case 3:
			{
				void* a = (void*)malloc(10);
				if (status)
				{
					if (datatype[0] == 'i')
					{
                      GetHeadLQueue(&Q, a);
					
					}
					else if (datatype[0] == 'd')
					{
						GetHeadLQueue(&Q, a);
						
					}
					else if (datatype[0] == 'c')
					{
						GetHeadLQueue(&Q, a);
		
					}
				}
				else
				{
					printf("队列还未初始化,请先初始化\n");
				}
				break;
			}
			case 4:
			{
				if (status)
				{
					ClearLQueue(&Q);
					printf("清空队列成功!\n");
					break;
				}
				else
				{
					printf("队列还未初始化,请先初始化\n");
				}
				break;
			}
			case 5:
			{

				if (status)
				{
					DestoryLQueue(&Q);
				}
				else
				{
					printf("队列未初始化,请先初始化\n");
				}
				break;
			}
			case 6:
			{
				if (status)
				{
					LengthLQueue(&Q);
					break;
				}
				else
				{
					printf("队列还未初始化,请先初始化\n");
				}
				break;
			}
			case 7:
			{
				if (status)
				{
					//type = 'i';
					int data;
					printf("请选择你要输入的数据的类型\n");
					printf("i表示整型数据,d表示浮点型数据,c表示字符型数据\n");
					printf("输入你要入队的数据类型:");
					scanf_s("%c", &type);
					while (ret != 1)
					{
						while (getchar() != '\n');
						printf("输入错误,请重新输入\n");
						ret = scanf_s("%c", &type);
					}
					while (getchar() != '\n');
					
					datatype[num] = type;

					if (datatype[num] == 'i')
					{
						int data;
						printf("请输入要入队的整型数据:");
						scanf_s("%d", &data);
						while (ret != 1)
						{
							while (getchar() != '\n');
							printf("输入错误,请重新输入\n");
							ret = scanf_s("%d", &data);
						}
						while (getchar() != '\n');
						
						EnLQueue(&Q, &data);
						num++;
						printf("入队成功\n");
					}
					else if (datatype[num] == 'd')
					{
						double data;
						printf("请输入要入队的浮点型数据:");
						scanf_s("%lf", &data);
						while (ret != 1)
						{
							while (getchar() != '\n');
							printf("输入错误,请重新输入\n");
							ret = scanf_s("%lf", &data);
						}
						while (getchar() != '\n');
						EnLQueue(&Q, &data);
						num++;
						printf("入队成功\n");
					}
					else if (datatype[num] == 'c')
					{
						char data;
						printf("请输入要入队的浮点型数据:");
						scanf_s("%c", &data);
						while (getchar() != '\n');
						EnLQueue(&Q , &data);
						num++;
						printf("入队成功\n");
					}
					
				}
				else
				{
					printf("队列还未初始化,请先初始化\n");
				}
				break;
			}
			case 8:
			{
				if (status)
				{
					
					DeLQueue(&Q);
					printf("出队成功!\n");
				}

				else
				{
					printf("队列还未初始化,请先初始化\n");
				}
				break;
			}
			case 9:
			{
				if (status)
				{
					TraverseLQueue(&Q, LPrint);
				}
				else
				{
					printf("队列还未初始化,请先初始化\n");
				}
				break;
			}
			case 10:
			{
				break;
			}
			}
			if (sign == 10)
			{
				break;
			}
		}
		printf("按回车返回\n");
		while (getchar() != '\n');
	}
	return 0;
}

		


