#include "LinkStack.h"
#include "stdio.h"

void Menu()
{
	printf("   **************  ϵͳ���ܲ˵�   **************        \n");
	printf("   *  1.��ջ��ʼ��      **      2.�ж�ջ�Ƿ�Ϊ��        \n");
	printf("   *  3.���ջ��Ԫ��    **      4.���ջ                \n");
	printf("   *  5.����ջ          **      6.���ջ����            \n");
	printf("   *  7.��ջ            **      8.��ջ                  \n");
	printf("                    9.�˳�ϵͳ                          \n");
};
int main()
{
	int sign;//ѡ��Ҫ���еĲ���
	int ret;//���Ƿ�����
	int status=0;//����Ƿ��ѳ�ʼ��
	LinkStack s;

	while (1)
	{
		system("cls");
		Menu();
		printf("\n��ѡ��Ҫ���еĲ���:");
		ret = scanf_s("%d", &sign);
		while (ret != 1)
		{
			while (getchar() != '\n');
			printf("�������,����������\n");
			Menu();
			ret = scanf_s("%d", &sign);
		}//���Ƿ����� 
		if (sign > 9 || sign <= 0)
		{
			printf("error!������һ��1-9������\n\n");
		}
		else
		{
			switch (sign)
			{
			case 1:
			{
				initLStack(&s);//��ʼ��
				if (initLStack(&s) == SUCCESS)
				{
					//printf("%d", s.count);
					printf("��ջ��ʼ���ɹ�\n");
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
					printf("��ջ��δ��ʼ��,���ȳ�ʼ��\n");
				}
				break;
			}
			case 3:
			{
				int e;
				if (status)
				{
					getTopLStack(&s, &e);
					printf("ջ����Ԫ����%d\n", e);
				}
				else
				{
					printf("��ջ��δ��ʼ��,���ȳ�ʼ��\n");
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
					printf("��ջ��δ��ʼ��,���ȳ�ʼ��\n");
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
					printf("��ջ��δ��ʼ��,���ȳ�ʼ��\n");
				}
				break;
			}

			case 6:
			{
				if (status)
				{
					int Length;
					LStackLength(&s, &Length);
					printf("ջ�ĳ���Ϊ%d", Length);
					break;
				}
				else
				{
					printf("��ջ��δ��ʼ��,���ȳ�ʼ��\n");
				}
				break;
			}
			case 7:
			{
				if (status)
				{
					int data;
					printf("Ҫ��ջ������:");
					scanf_s("%d", &data);
					pushLStack(&s, data);
				}

				else
				{
					printf("��ջ��δ��ʼ��,���ȳ�ʼ��\n");
				}
				break;
			}
			case 8:
			{
				if (status)
				{
					int data;
					popLStack(&s, &data);
					printf("��ջ������Ϊ%d", data);
				}

				else
				{
					printf("��ջ��δ��ʼ��,���ȳ�ʼ��\n");
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
		printf("�밴�س�����\n");
		while (getchar() != '\n');
		while (getchar() != '\n');
	}
	return 0;
}
