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
int markList[100] = { 0, }; // 즐겨찾기를 위한 배열

void print_menu();                                        // 메뉴를 출력하는 함수
void add_music(MUSIC PlayList[30], int musicCount);       // 노래의 특징들을 추가하는 함수
void find_music(MUSIC PlayList[30], int musicCount);      // 가수를 입력해 그 가수가 부른 노래를 출력하는 함수
void print_music(MUSIC PlayList[30], int musicCount);     // 추가한 모든 노래를 출력하는 함수
void mark_music(MUSIC PlayList[30], int musicCount);      // 노래를 즐겨찾기 하는 함수
void print_MarkMusic(MUSIC PlayList[30], int musicCount); // 즐겨찾기한 노래들을 출력하는 함수

int main()
{
	int num;
	int musicCount = 0; // 노래의 개수

	while (1)
	{
		print_menu();
		printf("번호를 입력해주세요 (1 ~ 6번) : ");
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
			printf("1부터 6까지의 숫자만 입력해주세요!!\n");
			continue;
		}
		return 0;
	}
	return 0;
}

void print_menu()
{
	printf("=========================\n");
	printf("1.노래 추가\n2.가수의 노래 검색\n3.노래 출력\n4.노래 즐겨찾기\n5.즐겨찾기 목록\n6.종료\n");
	printf("=========================\n");
}

void add_music(MUSIC PlayList[30], int musicCount)
{
	printf("노래제목: ");
	scanf("%s", PlayList[musicCount].title);

	printf("가수: ");
	scanf("%s", PlayList[musicCount].singer);

	printf("위치: ");
	scanf("%s", PlayList[musicCount].location);

	printf("장르 (0: KPOP, 1: JPOP, 2: POP, 3: 클래식, 4: 영화ost, 5.락, 6.R&B): ");
	scanf("%d", &PlayList[musicCount].genre);

	printf("\n");
}

void find_music(MUSIC PlayList[30], int musicCount)
{
	char name[100];
	int song = 0;

	printf("가수 이름을 입력하세요 : ");
	scanf("%s", name);

	for (int i = 0; i < musicCount; i++) 
	{
		if (strcmp(name, PlayList[i].singer) == 0) // 가수 이름 비교
		{
			printf("\n------- %d번 노래 -------\n", i + 1);
			printf("노래제목: %s\n", PlayList[i].title);
			printf("가수: %s\n", PlayList[i].singer);
			printf("위치: %s\n", PlayList[i].location);

			if (PlayList[i].genre == 0)
				printf("장르: KPOP\n");
			else if (PlayList[i].genre == 1)
				printf("장르: JPOP\n");
			else if (PlayList[i].genre == 2)
				printf("장르: POP\n");
			else if (PlayList[i].genre == 3)
				printf("장르: 클래식\n");
			else if (PlayList[i].genre == 4)
				printf("장르: 영화ost\n");
			else if (PlayList[i].genre == 5)
				printf("장르: 락\n");
			else if (PlayList[i].genre == 6)
				printf("장르: R&B\n");
			printf("\n");

			song++; // 입력한 가수와 노래 목록에 있는 가수가 같을 시 +1
		}
	}

	if (musicCount == 0) // 추가 된 노래가 없을 경우 출력
		printf("먼저 노래 추가를 해주세요 :)\n");

	if (musicCount != 0 && song == 0) // 추가 된 노래가 있고 같은 가수가 없을 경우 출력
		printf("해당 가수가 부른 곡이 없습니다.\n");

}

void print_music(MUSIC PlayList[30], int musicCount)
{
	for (int i = 0; i < musicCount; i++) // 전체 노래 출력
	{
		printf("\n------- %d번 노래 -------\n", i + 1);
		printf("노래제목: %s\n", PlayList[i].title);
		printf("가수: %s\n", PlayList[i].singer);
		printf("위치: %s\n", PlayList[i].location);

		if (PlayList[i].genre == 0)
			printf("장르: KPOP\n");
		else if (PlayList[i].genre == 1)
			printf("장르: JPOP\n");
		else if (PlayList[i].genre == 2)
			printf("장르: POP\n");
		else if (PlayList[i].genre == 3)
			printf("장르: 클래식\n");
		else if (PlayList[i].genre == 4)
			printf("장르: 영화ost\n");
		else if (PlayList[i].genre == 5)
			printf("장르: 락\n");
		else if (PlayList[i].genre == 6)
			printf("장르: R&B\n");

		printf("\n");
	}
}

void mark_music(MUSIC PlayList[30], int musicCount)
{
	int num;

	printf("즐겨찾기 할 노래의 번호를 입력하세요 : ");
	scanf("%d", &num);

	if (musicCount >= num && num > 0)  // 번호로 즐겨찾기 저장
	{
		printf("%d번 노래가(%s의 %s) 즐겨찾기 되었습니다!\n", num, PlayList[num - 1].singer, PlayList[num - 1]);
		markList[num - 1] = 1; // markList[]를 0에서 1로 저장
	}
	else 
		printf("%d번 노래는 존재하지 않거나 숫자를 입력해주세요.\n", num);
}

void print_MarkMusic(MUSIC PlayList[30], int musicCount)
{
	int mark = 0;

	for (int i = 0; i < musicCount; i++)
	{
		if (markList[i] == 1) // markList[i]가 1일 시 그 노래는 즐겨찾기가 된 노래
		{
			printf("\n------- %d번 노래 -------\n", i + 1);
			printf("노래제목: %s\n", PlayList[i].title);
			printf("가수: %s\n", PlayList[i].singer);
			printf("위치: %s\n", PlayList[i].location);

			if (PlayList[i].genre == 0)
				printf("장르: KPOP\n");
			else if (PlayList[i].genre == 1)
				printf("장르: JPOP\n");
			else if (PlayList[i].genre == 2)
				printf("장르: POP\n");
			else if (PlayList[i].genre == 3)
				printf("장르: 클래식\n");
			else if (PlayList[i].genre == 4)
				printf("장르: 영화ost\n");
			else if (PlayList[i].genre == 5)
				printf("장르: 락\n");
			else if (PlayList[i].genre == 6)
				printf("장르: R&B\n");

			printf("\n");

			mark++; // 즐겨찾기가 된 곡이 있을 시 +1
		}
	}

	if (musicCount == 0) // 추가 된 노래가 없을 경우 출력
		printf("먼저 노래 추가를 해주세요 :)\n");

	if (musicCount != 0 && mark == 0) // 추가 된 노래가 있고 즐겨찾기된 노래가 없을 경우 출력
		printf("즐겨찾기된 곡이 없습니다.\n");
}