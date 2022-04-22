#include <stdio.h>

int main(void)
{
    int x,y,black_first =0,white_first =0,arr[52][52] = {0,};
    char color;
    scanf("%d %d\n",&x,&y);
    
    for(int i = 1; i <= x; i++)
    {
    	for(int j = 1; j <= y+1; j++)
    	{
    		scanf("%c",&color);
    		if (color == '\n')
    			;
    		else
    			arr[i][j] = color;
		}
	}
	
	int w_best = -1;
	for(int X = 1; X <= x-8+1; X++ )
	{
		for(int Y = 1; Y <= y-8+1; Y++)
		{
			white_first= 0;
			for(int count = 1, i = X; i <= X+7; i++)
			{
				count = 0;
				for(int j = Y; j <= Y+7; j++)
				{
					if (i%2 > 0)
					{
						if (count%2 == 0)
						{
							if (arr[i][j] != 'B')
								white_first += 1;
						}
						else
						{
							if (arr[i][j] != 'W')
								white_first += 1;
						}
					}
					else
					{
						if (count%2 == 0)
						{
							if (arr[i][j] != 'W')
								white_first += 1;
						}
						else
						{
							if (arr[i][j] != 'B')
								white_first += 1;
						}
					}
					count += 1;
				}
			}
			if (w_best < 0)
				w_best = white_first;
			else
			{
				if(w_best > white_first)
					w_best = white_first;
			}
		}
	}
	
	int b_best = -1;
	for(int X = 1; X <= x-8+1; X++ )
	{
		for(int Y = 1; Y <= y-8+1; Y++)
		{
			black_first = 0;
			for(int count = 1, i = X; i <= X+7; i++)
			{
				count = 0;
				for(int j = Y; j <= Y+7; j++)
				{
					if (i%2 > 0)
					{
						if (count%2 == 0)
						{
							if (arr[i][j] != 'W')
								black_first += 1;
						}
						else
						{
							if (arr[i][j] != 'B')
								black_first += 1;
						}
					}
					else
					{
						if (count%2 == 0)
						{
							if (arr[i][j] != 'B')
								black_first += 1;
						}
						else
						{
							if (arr[i][j] != 'W')
								black_first += 1;
						}
					}
					count += 1;
				}
			}
			if (b_best < 0)
				b_best = black_first;
			else
			{
				if(b_best > black_first)
					b_best = black_first;
			}
		}
	}
	
	
	if (w_best > b_best)
		printf("%d",b_best);
	else
		printf("%d",w_best);
	
	
    return 0;
}