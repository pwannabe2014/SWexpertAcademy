#include <stdio.h>
#pragma warning(disable:4996) 

int map[1000];
int dx[] = {-2,-1, 1, 2};
int main() {
	
	freopen("input.txt", "r", stdin);
	
	for (int i = 1; i < 11; i++) {

		int M = 0;
		int result = 0;

		scanf("%d", &M);

		for (int i = 0; i < M; i++)
		{
			scanf("%d", &map[i]);
		}

		for (int i = 2; i < M-2; i++)
		{
			int second_max = 0;

			if ((map[i] > map[i - 2]) && (map[i] > map[i - 1]) && (map[i] > map[i + 1]) && (map[i] > map[i + 2]))
			{
				for (int j = 0; j<4; j++) {
					if (second_max < map[i + dx[j]])
						second_max = map[i + dx[j]];
				}
				result += map[i] - second_max;
			}
		}
		printf("#%d %d", i, result);
		printf("\n");
	}

	return 0;
}

