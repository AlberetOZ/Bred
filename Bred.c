#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_STRINGS 4096
#define MAX_SYMBOLS 128
#define RUS_MOVE 100
#define RUS_POINT_CHANGE 48

int compar(const void* a, const void* b)
{
	if(a == b)
	{
		return 0;
	}
	int i = 0, j = 0, k = 0;
	i = strlen((char*)a);
	j = strlen((char*)b);
	for(; ((char*)a)[i] < 0; i++);
	for(; ((char*)b)[j] < 0; j++);
	
	for( k = 0; (((char*)a)[i - k] +  RUS_MOVE*(((char*)a)[i-1-k] + RUS_POINT_CHANGE) - ((char*)b)[j-k]  - RUS_MOVE*(((char*)b)[j-1-k] + RUS_POINT_CHANGE)) == 0; k += 2);
	i = 0;
	j = 0;
	return  (k/2);
	



}



int main() {

	srand(time(NULL));
 

	int i = 0, j = 0, p = 0,  n = 0, l = 0, temp3 = 0,  temp1 = 0, temp2 = 0,  m = 0;
	char str[MAX_STRINGS][MAX_SYMBOLS] = {{0}};
	char out[MAX_STRINGS][MAX_SYMBOLS] = {{0}};
	FILE *input, *output;
        input = fopen ("input","r");
        output = fopen ("output","w");
        
	assert(input);
	assert(output);
	assert(!ferror(input));
	assert(!ferror(output));

	printf("Сколько четверостишей?\n");
	scanf("%d", &m);
	m++;
	printf("Точность рифмы (кол-во совпадающих в конце букв)\n");
	scanf("%d", &p);
	p++;
	for(;fgets(str[i], MAX_SYMBOLS, input);i++)
	{
		if((strlen(str[i])+1 > 70) || (strlen(str[i])+1 < 36 ))
		i--;
		
	}

	n = i;
	printf("N = %d\n", n);

	for(i = 0; i < m; i++)
	{
		j = 0;
		temp1 = rand() % ((n-1) - 0);
		temp2 = rand() % ((n-1) - 0);
		strcpy(out[i*4+j] ,str[temp1]);
		j++;
		strcpy(out[i*4+j], str[temp2]);
		j++;
		for(l = 0; l < n*1337; l++)
		{
			temp3 = rand() % (n - 1);
			if(compar(str[temp3], str[temp1]) == p)
			{
				strcpy(out[i*4+j], str[temp3]);
				j++;
				break;
			}

		}
		printf("%d\n", temp3);
		for(l = 0; l < n*1337; l++)
                {
			temp3 = rand() % (n - 1) - 1;
			if(compar(str[temp3], str[temp2]) == p)
			{
				strcpy(out[i*4+j], str[temp3]);
				j++;
				break;
			}

		}
	}

	for( j = 0; j < m*4; j++)
	{
		fprintf(output, "%s", out[j]);

	}



	fclose (output);
	fclose (input);

	return 0;
}
