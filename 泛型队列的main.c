#include "LQueue.h"
#include <stdio.h>

void Menu()
{
	printf("   **************  ϵͳ���ܲ˵�   **************        \n");
	printf("   *  1.���г�ʼ��      **      2.�ж϶����Ƿ�Ϊ��      \n");
	printf("   *  3.�����ͷԪ��    **      4.��ն���              \n");
	printf("   *  5.���ٶ���        **      6.�����г���          \n");
	printf("   *  7.���            **      8.����                  \n");
	printf("   *  9.�������        **      10.�˳�ϵͳ             \n");

}
int main()
{
	
	int sign;//ѡ��Ҫ���еĲ���
	int ret;//���Ƿ�����
	int status = 0;//����Ƿ��ѳ�ʼ��
	LQueue Q;

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
			ret = scanf_s("%d", &sign);
		}
		while (getchar() != '\n');

	
		//���Ƿ����� 
		if (sign > 10 || sign <= 0)
		{
			printf("error!������һ��1-10������\n");
		}
		else
		{
			switch (sign)
			{
			case 1:
			{
				InitLQueue(&Q);//��ʼ��
			   //printf("%d", s.count);
				printf("���г�ʼ���ɹ�\n");
				status = 1;
				break;
			}
			case 2:
			{
				if (status)
					IsEmptyLQueue(&Q);
				else
				{
					printf("���л�δ��ʼ��,���ȳ�ʼ��\n");
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
					printf("���л�δ��ʼ��,���ȳ�ʼ��\n");
				}
				break;
			}
			case 4:
			{
				if (status)
				{
					ClearLQueue(&Q);
					printf("��ն��гɹ�!\n");
					break;
				}
				else
				{
					printf("���л�δ��ʼ��,���ȳ�ʼ��\n");
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
					printf("����δ��ʼ��,���ȳ�ʼ��\n");
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
					printf("���л�δ��ʼ��,���ȳ�ʼ��\n");
				}
				break;
			}
			case 7:
			{
				if (status)
				{
					//type = 'i';
					int data;
					printf("��ѡ����Ҫ��������ݵ�����\n");
					printf("i��ʾ��������,d��ʾ����������,c��ʾ�ַ�������\n");
					printf("������Ҫ��ӵ���������:");
					scanf_s("%c", &type);
					while (ret != 1)
					{
						while (getchar() != '\n');
						printf("�������,����������\n");
						ret = scanf_s("%c", &type);
					}
					while (getchar() != '\n');
					
					datatype[num] = type;

					if (datatype[num] == 'i')
					{
						int data;
						printf("������Ҫ��ӵ���������:");
						scanf_s("%d", &data);
						while (ret != 1)
						{
							while (getchar() != '\n');
							printf("�������,����������\n");
							ret = scanf_s("%d", &data);
						}
						while (getchar() != '\n');
						
						EnLQueue(&Q, &data);
						num++;
						printf("��ӳɹ�\n");
					}
					else if (datatype[num] == 'd')
					{
						double data;
						printf("������Ҫ��ӵĸ���������:");
						scanf_s("%lf", &data);
						while (ret != 1)
						{
							while (getchar() != '\n');
							printf("�������,����������\n");
							ret = scanf_s("%lf", &data);
						}
						while (getchar() != '\n');
						EnLQueue(&Q, &data);
						num++;
						printf("��ӳɹ�\n");
					}
					else if (datatype[num] == 'c')
					{
						char data;
						printf("������Ҫ��ӵĸ���������:");
						scanf_s("%c", &data);
						while (getchar() != '\n');
						EnLQueue(&Q , &data);
						num++;
						printf("��ӳɹ�\n");
					}
					
				}
				else
				{
					printf("���л�δ��ʼ��,���ȳ�ʼ��\n");
				}
				break;
			}
			case 8:
			{
				if (status)
				{
					
					DeLQueue(&Q);
					printf("���ӳɹ�!\n");
				}

				else
				{
					printf("���л�δ��ʼ��,���ȳ�ʼ��\n");
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
					printf("���л�δ��ʼ��,���ȳ�ʼ��\n");
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
		printf("���س�����\n");
		while (getchar() != '\n');
	}
	return 0;
}

		


