#include "ft_printf.h"

int	main()
{
	int		ft;
	int		nat;
	char	*base = "hola%p %p %p\n";
	int		i = 55;
	char	*str = "HOLLA";
	char	s = 'a';

	printf("nat :\n");
	nat = printf(base, str, i, s);
	printf("%i\n", nat);
	printf("-----\n");
	printf("ft :\n");
	ft = ft_printf(base, str, i, s);
	printf("%i\n", ft);

	// i = nbargs(str);
	// printf("ret :%i\n", i);
	return 0;
}