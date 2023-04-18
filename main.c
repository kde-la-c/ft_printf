#include "ft_printf.h"
// "hola%sque%%"
/* int	main()
{
	int		ft;
	// int		nat;
	char	*base = "hola%s %s";
	int		i = 55;
	char	*str = "aaa";
	char	s = 'a';

	// printf("nat :\n");
	// nat = printf(base, str, i, s);
	// printf("\n%i\n", nat);
	// printf("-----\n");
	// printf("ft :\n");
	ft = ft_printf(base, str, i, s);
	printf("\n%i\n", ft);

	return 0;
} */

int	main()
{
	int uwu;
	char *str = NULL;

	uwu = ft_printf("hola %s %c %d %u %p %x %X-\n", str, 0, 0, -1, NULL, 0, 0);
	printf("tuyo: %d\n", uwu);
	sleep(1);
	uwu = printf("hola %s %c %d %u %p %x %X \n", str, 0, 0, -1, NULL, 0, 0);
	printf("original: %d\n", uwu);
	return (0);
}