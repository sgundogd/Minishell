#include <stdio.h>
void ft(char **str)
{
	*str = "cemal";
}






int main()
{
	char *str = "fatih";
	ft(&str);
	printf("%s",str);
}
