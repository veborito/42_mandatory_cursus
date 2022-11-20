#include "ft_printf.h"

int main()
{
	int my_result;
	int result;

	my_result = ft_printf("tamer en %c %c %c %c %c %c string\n", 't', 't', 't', 't', 't', 't');
	result = printf("tamer en %c %c %c %c %c %c string\n", 't', 't', 't', 't', 't', 't');
	printf("my fonction = %d , off fonction = %d\n", my_result, result);
	my_result = ft_printf("tamer en %10c string\n", 't');
	result = printf("tamer en %10c string\n", 't');
	printf("my fonction = %d , off fonction = %d\n", my_result, result);
	my_result = ft_printf("Je suis %7s string\n", "boris");
	result = printf("Je suis %7s string\n", "boris");
	printf("my fonction = %d , off fonction = %d\n", my_result, result);
	my_result = ft_printf("tamer en %d string\n", 10);
	result = printf("tamer en %d string\n", 10);
	printf("my fonction = %d , off fonction = %d\n", my_result, result);
	my_result = ft_printf("tamer en %4d string\n", 10);
	result = printf("tamer en %4d string\n", 10);
	printf("my fonction = %d , off fonction = %d\n", my_result, result);
	
	char s[] = "je suis amoureux";
	char *pointer = s;

	my_result = ft_printf("adresse de s: %p\n", s);
	result = printf("adresse de s: %p\n", pointer);
	printf("my fonction = %d , off fonction = %d\n", my_result, result);
	return 0;
}
