//1240 단순 2진 암호코드 
#include <stdio.h>
#pragma warning(disable:4996) 

char gacMap[52][102];
int ganCodeMap[10][7] = {
	{0,0,0,1,1,0,1}, //0
	{0,0,1,1,0,0,1}, //1	
	{0,0,1,0,0,1,1}, //2
	{0,1,1,1,1,0,1}, //3
	{0,1,0,0,0,1,1}, //4
	{0,1,1,0,0,0,1}, //5
	{0,1,0,1,1,1,1}, //6
	{0,1,1,1,0,1,1}, //7
	{0,1,1,0,1,1,1}, //8
	{0,0,0,1,0,1,1}, //9
};

int atoi(char c);
int getSecretCode(int* arr);
int checkSecretCode(int a[]);

int main() {

	freopen("input.txt","r", stdin);

	int T = 0;
	scanf("%d", &T);
	for (int i=0 ; i<T; i++){
		int M, N = 0;
		int result = -1;

		scanf("%d", &M);
		scanf("%d", &N);
		for (int j = 0; j<M; j++) {
			scanf("%s", gacMap[j]);
		}

		for (int j = 0; j < M; j++) {	
			for (int k = N - 1; k >= 0; k--) {
				if (gacMap[j][k]== '1') {
					int aSecretcode[8];
					int atemp[7];

					for (int l = 0; l < 8; l++) {
						for (int m = 0; m < 7; m++) {
							atemp[6 - m] = atoi(gacMap[j][k- 7*l - m]);
						}
						aSecretcode[7 - l] = getSecretCode(atemp);
					}
					result = checkSecretCode(aSecretcode);
					break;
				}
			}
			if (result!=-1) break;
		}
		printf("#%d %d\n",i+1, result);
	}

	return 0;
}

// askii to integer
int atoi(char c) {
	return c - '0';
}


// 코드에 맞는 숫자 추출
int getSecretCode(int * arr)
{
	for (int i =0 ; i<10; i++) 
	{
		for (int j = 0; j<7; j++)
		{
			if (arr[j] != ganCodeMap[i][j])
				break;
			if (j == 6)
				return i;
		}
	}
	return -1;
}

//올바른 암호코드 체크
int checkSecretCode(int a[])
{
	if (((a[0] + a[2] + a[4] + a[6]) * 3 + (a[1] + a[3] + a[5] + a[7])) % 10 == 0)
		return (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7]);
	else 
		return 0;
}

