#include <iostream>
#include <cstring>

int main(int ac, char *av[])
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; ++i)
	{
		for (int j = 0; j < (int)strlen(av[i]); ++j)
			av[i][j] = toupper(av[i][j]);
		std::cout << av[i];
	}
	std::cout << std::endl;
	return (0);
}
