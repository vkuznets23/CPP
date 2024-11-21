#include <iostream>

int	main(int ac, char * av[])
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; av[i][j] != '\0'; j++)
		{	
			if (std::islower(av[i][j]))
				av[i][j] = std::toupper(av[i][j]);
		}	
	}
	// Print the transformed arguments
	for (int i = 1; i < ac; i++)
		std::cout << av[i] << " ";
	std::cout << std::endl;
	return 0;
}
