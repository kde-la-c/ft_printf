#include "ft_printf.h"

void test(char *str, ...)
{
	va_list	ap;

	va_start(ap, str);
	printf("%i\n", va_arg(ap, int));
	printf("%i\n", va_arg(ap, int));
	printf("%i\n", va_arg(ap, int));
	va_end(ap);
}

int main()
{
	test("hey", 1, 2);
	return 0;
}

/* int	main()
{
	int		ft;
	int		nat;
	char	*base = "hola%u ";
	int		i = -55;
	// char	*str = "aaa";
	// char	s = 'a';

	printf("nat :\n");
	nat = printf(base, i);
	printf("\n%i\n", nat);
	printf("-----\n");
	printf("ft :\n");
	ft = ft_printf(base, i);
	printf("\n%i\n", ft);

	return 0;
} */

/* int	main()
{
	int uwu;
	char *str = NULL;

	uwu = ft_printf("hola %s %c %d %u %p %x %X-\n", str, 0, 0, -1, NULL, 0, 0);
	printf("tuyo: %d\n", uwu);
	sleep(1);
	uwu = printf("hola %s %c %d %u %p %x %X \n", str, 0, 0, -1, NULL, 0, 0);
	printf("original: %d\n", uwu);
	return (0);
} */