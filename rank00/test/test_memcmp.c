#include <string.h>
#include <stdio.h>

#include "../libft.h"

int main()
{
	char s[]="\0";
	char t[]="\200";
	char s1[10];
	char t1[20];
	char s2[0];
	char t2[0];
	char s3[]="salut bogoss";
	char t3[]="salut";
	char s4[]="";
	char t4[]="sat";
	char t5[]="";
	
	printf("%d, %d\n", memcmp(s, t, 10), ft_memcmp(s, t, 10));
	printf("%d, %d\n", memcmp(s1, t1, 20), ft_memcmp(s1, t1, 20));
	printf("%d, %d\n", memcmp(s2, t2, 20), ft_memcmp(s2, t2, 20));
	printf("%d, %d\n", memcmp(s3, t3, 100), ft_memcmp(s3, t3, 100));
	printf("%d, %d\n", memcmp(s3, t3, 0), ft_memcmp(s3, t3, 0));
	printf("%d, %d\n", memcmp(s3, t5, 100), ft_memcmp(s3, t5, 100));
	printf("%d, %d\n", memcmp(s4, t3, 100), ft_memcmp(s4, t3, 100));
	printf("%d, %d\n", memcmp(s3, t4, 15), ft_memcmp(s3, t4, 15));
	printf("%d, %d\n", memcmp(s4, t5, 2), ft_memcmp(s4, t5, 2));
	return 0;
}

