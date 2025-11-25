#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE NOISE *" << std::endl;
	else
	{
		std::string str;
		for (int i = 1; i < ac; i++)
		{
			for (int j = 0; av[i][j] != '\0'; j++)
				str += std::toupper(av[i][j]);
			if (i < ac - 1)
				str += ' ';
		}
			std::cout << str << std::endl;
	}
	return (0);
}
