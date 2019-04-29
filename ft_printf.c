/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:54:22 by eleclet           #+#    #+#             */
/*   Updated: 2019/04/29 20:52:37 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	
	ft_printf("lallalaalal %s  %p  %d %d char == %c %% string == %s","TtripelPite",1, 2, 'Q', "SucePute");
	return (0);
}

int		ft_printf(const char *format, ...)
{

	char *str;
	va_list arg;
	

	str = ft_strdup(format);
	va_start(arg, format);
	while (*str != '\0')
	{
		if (*str == '%')
		{

			str++;
			if (*str == 'd')
			{
				ft_putnbr(va_arg(arg, int));
			}
			if (*str == 'c')
			{
				ft_putchar(va_arg(arg, unsigned int));
			}
			if (*str == 's')
			{
				ft_putstr(va_arg(arg, char *));
			}
			if (*str == '%')
			{
				ft_putchar('%');
			}
			if (*str == 'p')
			{
				//unsigned int p = va_arg(arg, unsigned int);
				//ft_putnbr(&p);
				ft_putstr("pointer");
			}
		}
		str++;
		ft_putchar(*str);
	}
	va_end(arg);
	




	//printf("%d ", va_arg(arg, mnt));
	//printf("%d ", va_arg(arg, int));
	//printf("%d ", va_arg(arg, int));
	//

	//printf("ALodaslkdas %d %d",1);
	return (0);
}
