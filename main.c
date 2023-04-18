#include "ft_printf.h"
// "hola%sque%%"
int	main()
{
	int		ft;
	int		nat;
	char	*base = "hola%s %i %c ";
	int		i = 55;
	char	*str = "aaa";
	char	s = 'a';

	printf("nat :\n");
	nat = printf(base, str, i, s);
	printf("\n%i\n", nat);
	printf("-----\n");
	printf("ft :\n");
	ft = ft_printf(base, str, i, s);
	printf("\n%i\n", ft);

	return 0;
}