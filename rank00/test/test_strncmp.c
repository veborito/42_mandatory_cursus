#include <string.h>
#include <stdio.h>

#include "../libft/libft.h"

int main()
{
	// char s[]="\0";
	// char t[]="\200";
	// char s1[10];
	// char t1[20];
	// char s2[0];
	// char t2[0];
	// char s3[]="salut bogoss";
	// char t3[]="salut";
	// char s4[]="";
	// char t4[]="sat";
	// char t5[]="";
	
	// printf("%d, %d\n", strncmp(s, t, 10), ft_strncmp(s, t, 10));
	// printf("%d, %d\n", strncmp(s1, t1, 20), ft_strncmp(s1, t1, 20));
	// printf("%d, %d\n", strncmp(s2, t2, 20), ft_strncmp(s2, t2, 20));
	// printf("%d, %d\n", strncmp(s3, t3, 100), ft_strncmp(s3, t3, 100));
	// printf("%d, %d\n", strncmp(s3, t3, 0), ft_strncmp(s3, t3, 0));
	// printf("%d, %d\n", strncmp(s3, t5, 100), ft_strncmp(s3, t5, 100));
	// printf("%d, %d\n", strncmp(s4, t3, 100), ft_strncmp(s4, t3, 100));
	// printf("%d, %d\n", strncmp(s3, t4, 15), ft_strncmp(s3, t4, 15));
	// printf("%d, %d\n", strncmp(s4, t5, 2), ft_strncmp(s4, t5, 2));
	// printf("------------------------------------------------------\n");
	// printf("%d, %d\n", strncmp("t", "", 0), ft_strncmp("t", "", 0));
	// printf("%d, %d\n", strncmp("1234", "1235", 3), ft_strncmp("1234", "1235", 3));
	// printf("%d, %d\n", strncmp("", "1", 0), ft_strncmp("", "1", 0));
	// printf("%d, %d\n", strncmp("1", "", 0), ft_strncmp("1", "", 0));
	// printf("%d, %d\n", strncmp("abcdefgh", "abcdwxyz", 4), ft_strncmp("abcdefgh", "abcdwxyz", 4));
	// printf("%d, %d\n", strncmp("zyxbcdefgh", "abcdwxyz", 0), ft_strncmp("zyxbcdefgh", "abcdwxyz", 0));
	// printf("%d, %d\n", strncmp("abcdefgh", "", 0), ft_strncmp("abcdefgh", "", 0));
	// 	printf("------------------------------------------------------\n");
	printf("%d\n", strncmp("164bedb0d17902004d3b7add9270b820e3934e42", "164bedb0d17902004d3b7add9270b820e3934e42", strlen("164bedb0d17902004d3b7add9270b820e3934e42")));
	return 0;
}


