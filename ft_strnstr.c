#include <string.h>

char *ft_strnstr(const char *s1, const char *s2, size_t len)
{

}



















char *strnstr(const char *s, const char *find, size_t slen)
{
	char c, sc;
	size_t len;

	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if (slen-- < 1 || (sc = *s++) == '\0')
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}
#include <stdio.h>


int main()
{
    char p[5] = "boris";
    char s[3] = "r";

    printf("%s \n", strnstr(p,s, 3));
}
