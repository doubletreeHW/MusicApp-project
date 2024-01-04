#include <stdio.h>
#include <string.h>

enum music_type { KPOP, JPOP, POP, CLASSIC, MOVIE_OST, ROCK, RnB };

typedef struct music {
	char title[100];
	char singer[100];
	char location[100];
	enum music_type genre;
}MUSIC;

MUSIC PlayList[100] = { {0}, };
int markList[100] = { 0, }; // ���ã�⸦ ���� �迭

void print_menu();                                        // �޴��� ����ϴ� �Լ�
void add_music(MUSIC PlayList[30], int musicCount);       // �뷡�� Ư¡���� �߰��ϴ� �Լ�
void find_music(MUSIC PlayList[30], int musicCount);      // ������ �Է��� �� ������ �θ� �뷡�� ����ϴ� �Լ�
void print_music(MUSIC PlayList[30], int musicCount);     // �߰��� ��� �뷡�� ����ϴ� �Լ�
void mark_music(MUSIC PlayList[30], int musicCount);      // �뷡�� ���ã�� �ϴ� �Լ�
void print_MarkMusic(MUSIC PlayList[30], int musicCount); // ���ã���� �뷡���� ����ϴ� �Լ�

int main()
{
	int num;
	int musicCount = 0; // �뷡�� ����

	while (1)
	{
		print_menu();
		printf("��ȣ�� �Է����ּ��� (1 ~ 6��) : ");
		scanf("%d", &num);
		printf("\n");

		switch (num)
		{
		case 1:
			add_music(PlayList, musicCount);
			musicCount++;
			continue;
		case 2:
			find_music(PlayList, musicCount);
			continue;
		case 3:
			print_music(PlayList, musicCount);
			continue;
		case 4:
			mark_music(PlayList, musicCount);
			continue;
		case 5:
			print_MarkMusic(PlayList, musicCount);
			continue;
		case 6:
			break;
		default:
			printf("1���� 6������ ���ڸ� �Է����ּ���!!\n");
			continue;
		}
		return 0;
	}
	return 0;
}

void print_menu()
{
	printf("=========================\n");
	printf("1.�뷡 �߰�\n2.������ �뷡 �˻�\n3.�뷡 ���\n4.�뷡 ���ã��\n5.���ã�� ���\n6.����\n");
	printf("=========================\n");
}

void add_music(MUSIC PlayList[30], int musicCount)
{
	printf("�뷡����: ");
	scanf("%s", PlayList[musicCount].title);

	printf("����: ");
	scanf("%s", PlayList[musicCount].singer);

	printf("��ġ: ");
	scanf("%s", PlayList[musicCount].location);

	printf("�帣 (0: KPOP, 1: JPOP, 2: POP, 3: Ŭ����, 4: ��ȭost, 5.��, 6.R&B): ");
	scanf("%d", &PlayList[musicCount].genre);

	printf("\n");
}

void find_music(MUSIC PlayList[30], int musicCount)
{
	char name[100];
	int song = 0;

	printf("���� �̸��� �Է��ϼ��� : ");
	scanf("%s", name);

	for (int i = 0; i < musicCount; i++) 
	{
		if (strcmp(name, PlayList[i].singer) == 0) // ���� �̸� ��
		{
			printf("\n------- %d�� �뷡 -------\n", i + 1);
			printf("�뷡����: %s\n", PlayList[i].title);
			printf("����: %s\n", PlayList[i].singer);
			printf("��ġ: %s\n", PlayList[i].location);

			if (PlayList[i].genre == 0)
				printf("�帣: KPOP\n");
			else if (PlayList[i].genre == 1)
				printf("�帣: JPOP\n");
			else if (PlayList[i].genre == 2)
				printf("�帣: POP\n");
			else if (PlayList[i].genre == 3)
				printf("�帣: Ŭ����\n");
			else if (PlayList[i].genre == 4)
				printf("�帣: ��ȭost\n");
			else if (PlayList[i].genre == 5)
				printf("�帣: ��\n");
			else if (PlayList[i].genre == 6)
				printf("�帣: R&B\n");
			printf("\n");

			song++; // �Է��� ������ �뷡 ��Ͽ� �ִ� ������ ���� �� +1
		}
	}

	if (musicCount == 0) // �߰� �� �뷡�� ���� ��� ���
		printf("���� �뷡 �߰��� ���ּ��� :)\n");

	if (musicCount != 0 && song == 0) // �߰� �� �뷡�� �ְ� ���� ������ ���� ��� ���
		printf("�ش� ������ �θ� ���� �����ϴ�.\n");

}

void print_music(MUSIC PlayList[30], int musicCount)
{
	for (int i = 0; i < musicCount; i++) // ��ü �뷡 ���
	{
		printf("\n------- %d�� �뷡 -------\n", i + 1);
		printf("�뷡����: %s\n", PlayList[i].title);
		printf("����: %s\n", PlayList[i].singer);
		printf("��ġ: %s\n", PlayList[i].location);

		if (PlayList[i].genre == 0)
			printf("�帣: KPOP\n");
		else if (PlayList[i].genre == 1)
			printf("�帣: JPOP\n");
		else if (PlayList[i].genre == 2)
			printf("�帣: POP\n");
		else if (PlayList[i].genre == 3)
			printf("�帣: Ŭ����\n");
		else if (PlayList[i].genre == 4)
			printf("�帣: ��ȭost\n");
		else if (PlayList[i].genre == 5)
			printf("�帣: ��\n");
		else if (PlayList[i].genre == 6)
			printf("�帣: R&B\n");

		printf("\n");
	}
}

void mark_music(MUSIC PlayList[30], int musicCount)
{
	int num;

	printf("���ã�� �� �뷡�� ��ȣ�� �Է��ϼ��� : ");
	scanf("%d", &num);

	if (musicCount >= num && num > 0)  // ��ȣ�� ���ã�� ����
	{
		printf("%d�� �뷡��(%s�� %s) ���ã�� �Ǿ����ϴ�!\n", num, PlayList[num - 1].singer, PlayList[num - 1]);
		markList[num - 1] = 1; // markList[]�� 0���� 1�� ����
	}
	else 
		printf("%d�� �뷡�� �������� �ʰų� ���ڸ� �Է����ּ���.\n", num);
}

void print_MarkMusic(MUSIC PlayList[30], int musicCount)
{
	int mark = 0;

	for (int i = 0; i < musicCount; i++)
	{
		if (markList[i] == 1) // markList[i]�� 1�� �� �� �뷡�� ���ã�Ⱑ �� �뷡
		{
			printf("\n------- %d�� �뷡 -------\n", i + 1);
			printf("�뷡����: %s\n", PlayList[i].title);
			printf("����: %s\n", PlayList[i].singer);
			printf("��ġ: %s\n", PlayList[i].location);

			if (PlayList[i].genre == 0)
				printf("�帣: KPOP\n");
			else if (PlayList[i].genre == 1)
				printf("�帣: JPOP\n");
			else if (PlayList[i].genre == 2)
				printf("�帣: POP\n");
			else if (PlayList[i].genre == 3)
				printf("�帣: Ŭ����\n");
			else if (PlayList[i].genre == 4)
				printf("�帣: ��ȭost\n");
			else if (PlayList[i].genre == 5)
				printf("�帣: ��\n");
			else if (PlayList[i].genre == 6)
				printf("�帣: R&B\n");

			printf("\n");

			mark++; // ���ã�Ⱑ �� ���� ���� �� +1
		}
	}

	if (musicCount == 0) // �߰� �� �뷡�� ���� ��� ���
		printf("���� �뷡 �߰��� ���ּ��� :)\n");

	if (musicCount != 0 && mark == 0) // �߰� �� �뷡�� �ְ� ���ã��� �뷡�� ���� ��� ���
		printf("���ã��� ���� �����ϴ�.\n");
}