#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	int ret;

	printf("-----------put first printf, second ft_printf-----------\n\n");

	printf("plain %%%%HELLO WORLD---: [");
	ret = printf("%%%%HELLO WORLD---");
	printf("](ret = %d)\n", ret);

	ft_printf("plain %%%%HELLO WORLD---: [");
	ret = ft_printf("%%%%HELLO WORLD---");
	ft_printf("](ret = %d)\n", ret);

	printf("\n\x1b[35m############## C A S E  %% #################\n\n");

	printf("\x1b[37mflag %%10%%: [");
	ret = printf("%10%");
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%10%%: [");
	ret = ft_printf("%10%");
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%-10%%: [");
	ret = printf("%-10%");
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%-10%%: [");
	ret = ft_printf("%-10%");
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%010%%: [");
	ret = printf("%010%");
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%010%%: [");
	ret = ft_printf("%010%");
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%-010%%: [");
	ret = printf("%-010%");
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%-010%%: [");
	ret = ft_printf("%-010%");
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%.10%%: [");
	ret = printf("%.10%");
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%.10%%: [");
	ret = ft_printf("%.10%");
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%20.10%%: [");
	ret = printf("%20.10%");
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%20.10%%: [");
	ret = ft_printf("%20.10%");
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%10.20%%: [");
	ret = printf("%10.20%");
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%10.20%%: [");
	ret = ft_printf("%10.20%");
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%020.10%%: [");
	ret = printf("%020.10%");
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%020.10%%: [");
	ret = ft_printf("%020.10%");
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%010.20%%: [");
	ret = printf("%010.20%");
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%010.20%%: [");
	ret = ft_printf("%010.20%");
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%0*%% (= -10): [");
	ret = printf("%0*%", -10);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%0*%% (= -10): [");
	ret = ft_printf("%0*%", -10);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%*%% (= -10): [");
	ret = printf("%*%", -10);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%*%% (= -10): [");
	ret = ft_printf("%*%", -10);
	ft_printf("](ret = %d)\n", ret);




	printf("\x1b[37mflag %%0*.*%% (-10, 6): [");
	ret = printf("%0*.*%", -10, 6);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%0*.*%% (-10, 6): [");
	ret = ft_printf("%0*.*%", -10, 6);
	ft_printf("](ret = %d)\n", ret);


	printf("\x1b[37mflag %%[05.]%%: [");
	ret = printf("%05.%");
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[05.]%%: [");
	ret = ft_printf("%05.%");
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[020.*]%% (= -15): [");
	ret = printf("%020.*%", -15);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[020.*]%% (= -15): [");
	ret = ft_printf("%020.*%", -15);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[020.0]%%: [");
	ret = printf("%020.0%");
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[020.0]%%: [");
	ret = ft_printf("%020.0%");
	ft_printf("](ret = %d)\n", ret);


	printf("\n\x1b[35m############## C A S E  %% C #################\n\n");

	printf("\x1b[37mplain %%c: [");
	ret = printf("%c", 'A');
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mplain %%c: [");
	ret = ft_printf("%c", 'A');
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mplain %%c (= 0): [");
	ret = printf("%c", 0);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mplain %%c (= 0): [");
	ret = ft_printf("%c", 0);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[10]c: [");
	ret = printf("%10c", 'A');
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[10]c: [");
	ret = ft_printf("%10c", 'A');
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[-10]c: [");
	ret = printf("%-10c", 'A');
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[-10]c: [");
	ret = ft_printf("%-10c", 'A');
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[INT_MAX]c: [");
	ret = printf("%2147483647c", 'A');
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[INT_MAX]c: [");
	ret = ft_printf("%2147483647c", 'A');
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[INT_MAX + 1]c: [");
	ret = printf("%2147483648c", 'A');
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[INT_MAX + 1]c: [");
	ret = ft_printf("%.2147483648c", 'A');
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[-* ( = -10)]c: [");
	ret = printf("%-*c", -10, 'A');
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[-* ( = -10)]c: [");
	ret = ft_printf("%-*c", -10, 'A');
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[010]c: [error: flag '0' results in undefined behavior with 'c' conversion specifier]\n");
	printf("              [");
	ret = printf("%010c", 'A');
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[010]c: [");
	ret = ft_printf("%010c", 'A');
	ft_printf("](ret = %d)\n", ret);
	
	printf("\x1b[37mflag %%[10.5]c: [error: precision used with 'c' conversion specifier, resulting in undefined behavior]\n");
	printf("               [");
	ret = printf("%10.5c", 'A');
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[10.5]c: [");
	ret = ft_printf("%10.5c", 'A');
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[10.-5]c: [");
	ret = printf("%10.-5c", 'A');
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[10.-5]c: [");
	ret = ft_printf("%10.-5c", 'A');
	ft_printf("](ret = %d)\n", ret);
	
	printf("\x1b[37mflag %%[-0]c: [error: flag '0' results in undefined behavior with 'c' conversion specifier]\n               [error: flag '0' is ignored when flag '-' is present]\n");
	printf("             [");
	ret = printf("%-0c", 'A');
	printf("](ret = %d)\n", ret);
	
	ft_printf("\x1b[35mflag %%[-0]c: [");
	ret = ft_printf("%-0c", 'A');
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%0*c (= -10): [");
	ret = printf("%0*c", -10, 'A');
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%0*c (= -10): [");
	ret = ft_printf("%0*c", -10, 'A');
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[05.]c: [");
	ret = printf("%05.c", 'A');
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[05.]c: [");
	ret = ft_printf("%05.c", 'A');
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[020.*]c (= -15): [");
	ret = printf("%020.*c", -15, 'A');
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[020.*]c (= -15): [");
	ret = ft_printf("%020.*c", -15, 'A');
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[020.0]c: [");
	ret = printf("%020.0c", 'A');
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[020.0]c: [");
	ret = ft_printf("%020.0c", 'A');
	ft_printf("](ret = %d)\n", ret);

	printf("\n\x1b[36m############## C A S E  %% S #################\n\n");
	
	char *s = "GYUDON";

	printf("\x1b[37mplain %%s: [");
	ret = printf("%s", s);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mplain %%s: [");
	ret = ft_printf("%s", s);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[10]s: [");
	ret = printf("%10s", s);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[10]s: [");
	ret = ft_printf("%10s", s);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[-10]s: [");
	ret = printf("%-10s", s);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[-10]s: [");
	ret = ft_printf("%-10s", s);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[3]s: [");
	ret = printf("%3s", s);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[3]s: [");
	ret = ft_printf("%3s", s);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[-3]s: [");
	ret = printf("%-3s", s);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[-3]s: [");
	ret = ft_printf("%-3s", s);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[010]s: [error: flag '0' results in undefined behavior with 's' conversion specifier]\n");
	printf("flag %%[010]s: [");
	ret = printf("%010s", s);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[010]s: [");
	ret = ft_printf("%010s", s);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[-010]s: [error: flag '0' is ignored when flag '-' is present]\n");
	printf("flag %%[-010]s: [");
	ret = printf("%-010s", s);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[-010]s: [");
	ret = ft_printf("%-010s", s);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[10.3]s: [");
	ret = printf("%10.3s", s);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[10.3]s: [");
	ret = ft_printf("%10.3s", s);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[10.10]s: [");
	ret = printf("%10.10s", s);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[10.10]s: [");
	ret = ft_printf("%10.10s", s);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[-10.3]s: [");
	ret = printf("%-10.3s", s);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[-10.3]s: [");
	ret = ft_printf("%-10.3s", s);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[10.* (= -3)]s: [");
	ret = printf("%10.*s", -3, s);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[10.* (= -3)]s: [");
	ret = ft_printf("%10.*s", -3, s);
	ft_printf("](ret = %d)\n", ret);
	printf("\x1b[37mflag %%[10.-10]s: [error: invalid conversion specifier '-']\n");
	printf("flag %%[10.-10]s: [");
	ret = printf("%10.-10s", s);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[10.-10]s: [");
	ret = ft_printf("%10.-10s", s);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[.3]s: [");
	ret = printf("%.3s", s);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[.3]s: [");
	ret = ft_printf("%.3s", s);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[.0]s: [");
	ret = printf("%.0s", s);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[.0]s: [");
	ret = ft_printf("%.0s", s);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[.*]s, %%[.*]s, %%[.*]s (= 0): [");
	ret = printf("%.*s, %.*s, %.*s", 0, s, 0, s, 0, s);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[.*]s, %%[.*]s, %%[.*]s (= 0): [");
	ret = ft_printf("%.*s, %.*s, %.*s", 0, s, 0, s, 0, s);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[10.0]s: [");
	ret = printf("%10.0s", s);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[10.0]s: [");
	ret = ft_printf("%10.0s", s);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[.-10]s: [error: invalid conversion specifier '-']\n");
	printf("flag %%[.-10]s: [");
	ret = printf("%.-10s", s);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[.-10]s: [");
	ret = ft_printf("%.-10s", s);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[.* (= -3)]s: [");
	ret = printf("%.*s", -3, s);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[.* (= -3)]s: [");
	ret = ft_printf("%.*s", -3, s);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%0*s (= -10): [");
	ret = printf("%0*s", -10, s);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%0*s (= -10): [");
	ret = ft_printf("%0*s", -10, s);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[010.]s: [");
	ret = printf("%010.s", s);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[010.]s: [");
	ret = ft_printf("%010.s", s);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[020.*]s (= -15): [");
	ret = printf("%020.*s", -15, s);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[020.*]s (= -15): [");
	ret = ft_printf("%020.*s", -15, s);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[020.0]s: [");
	ret = printf("%020.0s", s);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[020.0]s: [");
	ret = ft_printf("%020.0s", s);
	ft_printf("](ret = %d)\n", ret);

	printf("\n\x1b[33m############## C A S E  %% D & I #################\n\n");

	printf("\x1b[37mplain %%d(INT_MAX + 1): [");
	ret = printf("%d", INT_MAX + 1);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mplain %%d(INT_MAX + 1): [");
	ret = ft_printf("%d", INT_MAX + 1);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mplain %%d(INT_MIN - 1): [");
	ret = printf("%d", INT_MIN - 1);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mplain %%d(INT_MIN - 1): [");
	ret = ft_printf("%d", INT_MIN - 1);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mplain %%i: [");
	ret = printf("%i", INT_MAX);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mplain %%i: [");
	ret = ft_printf("%i", INT_MAX);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mplain %%i: [");
	ret = printf("%i", INT_MIN);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mplain %%i: [");
	ret = ft_printf("%i", INT_MIN);
	ft_printf("](ret = %d)\n", ret);

	int a = 12345;
	int b = -12345;

	printf("\x1b[37mflag %%[10]d: [");
	ret = printf("%10d", a);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[10]d: [");
	ret = ft_printf("%10d", a);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[10]d: [");
	ret = printf("%10d", b);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[10]d: [");
	ret = ft_printf("%10d", b);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[-10]d: [");
	ret = printf("%-10d", a);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[-10]d: [");
	ret = ft_printf("%-10d", a);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[-10]d: [");
	ret = printf("%-10d", b);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[-10]d: [");
	ret = ft_printf("%-10d", b);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[010]d: [");
	ret = printf("%010d", a);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[010]d: [");
	ret = ft_printf("%010d", a);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[010]d: [");
	ret = printf("%010d", b);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[010]d: [");
	ret = ft_printf("%010d", b);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37m*** error: flag '0' is ignored when flag '-' is present\n");
	printf("flag %%[-010]d: [");
	ret = printf("%-010d", a);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[-010]d: [");
	ret = ft_printf("%-010d", a);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37m*** error: flag '0' is ignored when flag '-' is present\n");
	printf("flag %%[-010]d: [");
	ret = printf("%-010d", b);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[-010]d: [");
	ret = ft_printf("%-010d", b);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[.10]d: [");
	ret = printf("%.10d", a);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[.10]d: [");
	ret = ft_printf("%.10d", a);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[.10]d: [");
	ret = printf("%.10d", b);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[.10]d: [");
	ret = ft_printf("%.10d", b);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%.[INT_MAX + 1]d: [");
	ret = printf("%.2147483647d", 12345);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%.[INT_MAX + 1]d: [");
	ret = ft_printf("%.2147483648d", 12345);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[10.10]d: [");
	ret = printf("%10.10d", a);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[10.10]d: [");
	ret = ft_printf("%10.10d", a);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[10.10]d: [");
	ret = printf("%10.10d", b);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[10.10]d: [");
	ret = ft_printf("%10.10d", b);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[20.10]d: [");
	ret = printf("%20.10d", a);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[20.10]d: [");
	ret = ft_printf("%20.10d", a);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[20.10]d: [");
	ret = printf("%20.10d", b);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[20.10]d: [");
	ret = ft_printf("%20.10d", b);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[-20.10]d: [");
	ret = printf("%-20.10d", a);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[-20.10]d: [");
	ret = ft_printf("%-20.10d", a);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[-20.10]d: [");
	ret = printf("%-20.10d", b);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[-20.10]d: [");
	ret = ft_printf("%-20.10d", b);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[10.20]d: [");
	ret = printf("%10.20d", a);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[10.20]d: [");
	ret = ft_printf("%10.20d", a);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[10.20]d: [");
	ret = printf("%10.20d", b);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[10.20]d: [");
	ret = ft_printf("%10.20d", b);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[-10.20]d: [");
	ret = printf("%-10.20d", a);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[-10.20]d: [");
	ret = ft_printf("%-10.20d", a);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[-10.20]d: [");
	ret = printf("%-10.20d", b);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[-10.20]d: [");
	ret = ft_printf("%-10.20d", b);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[0]d: [");
	ret = printf("%0d", a);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[0]d: [");
	ret = ft_printf("%0d", a);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[0]d: [");
	ret = printf("%0d", b);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[0]d: [");
	ret = ft_printf("%0d", b);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[.0]d: [");
	ret = printf("%.0d", a);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[.0]d: [");
	ret = ft_printf("%.0d", a);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[.0]d: [");
	ret = printf("%.0d", b);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[.0]d: [");
	ret = ft_printf("%.0d", b);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[010.]d: [");
	ret = printf("%010.d", b);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[010.]d: [");
	ret = ft_printf("%010.d", b);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[10.]d (d = 0): [");
	ret = printf("%10.d", 0);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[10.]d (d = 0): [");
	ret = ft_printf("%10.d", 0);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37m *** error: invalid conversion specifier '-'\n");
	printf("flag %%[.-10]d: [");
	ret = printf("%.-10d", a);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[.-10]d: [");
	ret = ft_printf("%.-10d", a);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37m *** error: invalid conversion specifier '-'\n");
	printf("flag %%[.-10]d: [");
	ret = printf("%.-10d", b);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[.-10]d: [");
	ret = ft_printf("%.-10d", b);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[.* (= -10)]d: [");
	ret = printf("%.*d", -10, a);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[.* (= -10)]d: [");
	ret = ft_printf("%.*d", -10, a);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[.* (= -10)]d: [");
	ret = printf("%.*d", -10, b);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[.* (= -10)]d: [");
	ret = ft_printf("%.*d", -10, b);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[0.0]d: [");
	ret = printf("%0.0d", a);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[0.0]d: [");
	ret = ft_printf("%0.0d", a);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[0.0]d: [");
	ret = printf("%0.0d", b);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[0.0]d: [");
	ret = ft_printf("%0.0d", b);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[010.0]d: [");
	ret = printf("%010.0d", a);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[010.0]d: [");
	ret = ft_printf("%010.0d", a);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[0.0]d (d = 0): [");
	ret = printf("%0.0d", 0);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[0.0]d (d = 0): [");
	ret = ft_printf("%0.0d", 0);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%0*d (= -10): [");
	ret = printf("%0*d", -10, a);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%0*d (= -10): [");
	ret = ft_printf("%0*d", -10, a);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[010.*]d (= -15): [");
	ret = printf("%010.*d", -15, b);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[33mflag %%[010.*]d (= -15): [");
	ret = ft_printf("%010.*d", -15, b);
	ft_printf("](ret = %d)\n", ret);

	printf("\n\x1b[35m############## C A S E  %% U #################\n\n");

	unsigned int u = 12345;

	printf("\x1b[37mplain %%u: [");
	ret = printf("%u", u);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mplain %%u: [");
	ret = ft_printf("%u", u);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[20]u: [");
	ret = printf("%20u", u);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[20]u: [");
	ret = ft_printf("%20u", u);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[-20]u: [");
	ret = printf("%-20u", u);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[-20]u: [");
	ret = ft_printf("%-20u", u);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[020]u: [");
	ret = printf("%020u", u);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[020]u: [");
	ret = ft_printf("%020u", u);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[-020]u: [");
	ret = printf("%-020u", u);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[-020]u: [");
	ret = ft_printf("%-020u", u);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[.20]u: [");
	ret = printf("%.20u", u);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[.20]u: [");
	ret = ft_printf("%.20u", u);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[25.20]u: [");
	ret = printf("%25.20u", u);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[25.20]u: [");
	ret = ft_printf("%25.20u", u);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[-30.20]u: [");
	ret = printf("%-30.20u", u);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[-30.20]u: [");
	ret = ft_printf("%-30.20u", u);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[.-20]u: [");
	ret = printf("%.-20u", u);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[.-20]u: [");
	ret = ft_printf("%.-20u", u);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[.*]u (= -10): [");
	ret = printf("%.*u", -10, u);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[.*]u (= -10): [");
	ret = ft_printf("%.*u", -10, u);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[0.0]u: [");
	ret = printf("%0.0u", u);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[0.0]u: [");
	ret = ft_printf("%0.0u", u);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[0.0]u (u = 0): [");
	ret = printf("%0.0u", 0);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[0.0]u (u = 0): [");
	ret = ft_printf("%0.0u", 0);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%0*u (= -10): [");
	ret = printf("%0*u", -10, u);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%0*u (= -10): [");
	ret = ft_printf("%0*u", -10, u);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[05.]u: [");
	ret = printf("%05.u", u);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[05.]u: [");
	ret = ft_printf("%05.u", u);
	ft_printf("](ret = %d)\n", ret);
	
	printf("\x1b[37mflag %%[010.]u: [");
	ret = printf("%010.u", u);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[010.]u: [");
	ret = ft_printf("%010.u", u);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[010.*]u (= -15): [");
	ret = printf("%010.*u", -15, u);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[010.*]u (= -15): [");
	ret = ft_printf("%010.*u", -15, u);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[010.0]u: [");
	ret = printf("%010.0u", u);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[010.0]u: [");
	ret = ft_printf("%010.0u", a);
	ft_printf("](ret = %d)\n", ret);


	printf("\n\x1b[36m############## C A S E  %% P #################\n\n");
	int *p;
	p = &a;

	printf("\x1b[37mplain %%p: [");
	ret = printf("%p", p);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mplain %%p: [");
	ret = ft_printf("%p", p);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[30]p: [");
	ret = printf("%30p", p);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[30]p: [");
	ret = ft_printf("%30p", p);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[5.]p, NULL: [");
	ret = printf("%5.p", NULL);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[5.]p, NULL: [");
	ret = ft_printf("%5.p", NULL);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%0*p (= -20): [");
	ret = printf("%0*p", -20, p);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%0*p (= -20): [");
	ret = ft_printf("%0*p", -20, p);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[020.]p: [");
	ret = printf("%020.p", p);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[020.]p: [");
	ret = ft_printf("%020.p", p);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[020.*]p (= -15): [");
	ret = printf("%020.*p", -15, p);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[020.*]p (= -15): [");
	ret = ft_printf("%020.*p", -15, p);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[020.0]p: [");
	ret = printf("%020.0p", p);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[36mflag %%[020.0]p: [");
	ret = ft_printf("%020.0p", p);
	ft_printf("](ret = %d)\n", ret);

	printf("\n\x1b[35m############## C A S E  %% x AND X #################\n\n");

	unsigned int ui = 123456;

	printf("\x1b[37mui = 123456\n");
	printf("\x1b[37mplain %%x: [");
	ret = printf("%x", ui);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mplain %%x: [");
	ret = ft_printf("%x", ui);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mplain %%X: [");
	ret = printf("%X", ui);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mplain %%X: [");
	ret = ft_printf("%X", ui);
	ft_printf("](ret = %d)\n", ret);

	ui = -123456;
	printf("\x1b[37mui = -123456\n");
	printf("plain %%x: [");
	ret = printf("%x", ui);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mplain %%x: [");
	ret = ft_printf("%x", ui);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mplain %%X: [");
	ret = printf("%X", ui);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mplain %%X: [");
	ret = ft_printf("%X", ui);
	ft_printf("](ret = %d)\n", ret);

	ui = 123456;
	printf("\x1b[37mui = 123456\n");
	printf("flag %%[20]x: [");
	ret = printf("%20x", ui);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[20]x: [");
	ret = ft_printf("%20x", ui);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[020]x: [");
	ret = printf("%020x", ui);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[020]x: [");
	ret = ft_printf("%020x", ui);
	ft_printf("](ret = %d)\n", ret);
	
	printf("\x1b[37mflag %%[-20]x: [");
	ret = printf("%-20x", ui);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[-20]x: [");
	ret = ft_printf("%-20x", ui);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[.20]x: [");
	ret = printf("%.20x", ui);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[.20]x: [");
	ret = ft_printf("%.20x", ui);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[30.20]x: [");
	ret = printf("%30.20x", ui);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[30.20]x: [");
	ret = ft_printf("%30.20x", ui);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[-30.20]x: [");
	ret = printf("%-30.20x", ui);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[-30.20]x: [");
	ret = ft_printf("%-30.20x", ui);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[030.20]x: [");
	ret = printf("%030.20x", ui);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[030.20]x: [");
	ret = ft_printf("%030.20x", ui);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[20.30]x: [");
	ret = printf("%20.30x", ui);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[20.30]x: [");
	ret = ft_printf("%20.30x", ui);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%0*x (= -10): [");
	ret = printf("%0*x", -10, ui);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%0*x (= -10): [");
	ret = ft_printf("%0*x", -10, ui);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[05.]x: [");
	ret = printf("%05.x", ui);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[05.]x: [");
	ret = ft_printf("%05.x", ui);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[020.]x: [");
	ret = printf("%020.x", ui);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[020.]x: [");
	ret = ft_printf("%020.x", ui);
	ft_printf("](ret = %d)\n", ret);
	
	printf("\x1b[37mflag %%[020.*]x (= -15): [");
	ret = printf("%020.*x", -15, ui);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[020.*]x (= -15): [");
	ret = ft_printf("%020.*x", -15, ui);
	ft_printf("](ret = %d)\n", ret);

	printf("\x1b[37mflag %%[020.0]x: [");
	ret = printf("%020.0x", ui);
	printf("](ret = %d)\n", ret);

	ft_printf("\x1b[35mflag %%[020.0]x: [");
	ret = ft_printf("%020.0x", ui);
	ft_printf("](ret = %d)\n", ret);


	printf("\x1b[37m---------------------\n");
	system("leaks a.out");
	return (0);
}
