/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   training.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artberna <artberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:38:15 by artberna          #+#    #+#             */
/*   Updated: 2024/10/01 09:39:04 by artberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	int	count = 0;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[count])
		count += ft_putchar(s[count]);
	return (count);
}

int ft_putnbr(int nb)
{
	int		count = 0;
	long	lnb = nb;

	if (lnb < 0)
	{
		lnb = -lnb;
		count += ft_putchar('-');
	}
	if (lnb >= 10)
		count += ft_putnbr(lnb / 10);
	lnb = lnb % 10;
	count += ft_putchar(lnb + 48);
	return (count);
}

int	ft_puthexa(unsigned int nb)
{
	int	count = 0;
	char *base = "0123456789abcdef";

	if (nb >= 16)
		count += ft_puthexa(nb / 16);
	count += ft_putchar(base[nb % 16]);
	return (count);
}

int	print_s(const char *s, va_list ap)
{
	int count = 0;

	if (*s == '%')
		count += ft_putchar('%');
	else if (*s == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (*s == 'd')
		count += ft_putnbr(va_arg(ap, int));
	else if (*s == 'x')
		count += ft_puthexa(va_arg(ap, unsigned int));
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int	count = 0;
	va_list	ap;

	va_start(ap, s);
	if (!s)
		return (-1);
	if (*s == '\0')
		return (0);
	while (*s)
	{
		if (*s == '%' && *s + 1 == '\0')
			return (-1);
		if (*s == '%' && *(++s))
			count += print_s(s, ap);
		else
			count += ft_putchar(*s);
		s++;
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	int				a = -111415414;
	unsigned int	b = 8564496;
	char			*s = "arrete de repeter";
	int				a_e = 000;
	int				b_e = 000;
	char			*s_e = NULL;

	int total = printf("OFFICIAL\na = [%d]  ||  b = [%x] || s = [%s]\n", a, b, s);
	int mtotal = ft_printf("PERSOooo\na = [%d]  ||  b = [%x] || s = [%s]\n", a, b, s);
	printf("OFFICIAL : TOTAL = [%d]\na_e = [%d]  ||  b_e = [%x] || s_e = [%s]\n", total, a_e, b_e, s_e);
	ft_printf("PERSOooo : TOTAL = [%d]\na_e = [%d]  ||  b_e = [%x] || s_e = [%s] \n", mtotal, a_e, b_e, s_e);
	return (0);
}
