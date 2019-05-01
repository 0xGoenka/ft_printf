/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:54:22 by eleclet           #+#    #+#             */
/*   Updated: 2019/05/01 18:34:29 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	
	ft_printf("%010d\n", -100);
	printf("%010d", -100);
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
			if (*str == '%')
			{
				ft_putchar('%');
			}
			if (*str == 'c')
			{
				ft_putchar(va_arg(arg, unsigned int));
			}
			if (*str == 's')
			{
				ft_putstr(va_arg(arg, char *));
			}
			if (*str == 'p')
			{
				//unsigned int p = va_arg(arg, unsigned int);
				//ft_putnbr(&p);
				ft_putstr("pointer");
			}
			if (*str == 'd' || *str == 'i')
			{
				ft_itos(va_arg(arg, int),10,0);
			}
			if (*str == 'o') // Print octal
			{
				ft_itos(va_arg(arg, int), 8, 1);
			}
			if (*str == 'u') // unsigned decimal
			{
				ft_itos(va_arg(arg, unsigned int),10,1); 
			}
			if (*str == 'x') // Hexa abcdef
			{
				ft_itos(va_arg(arg, unsigned int), 16, 1);
			}
			if (*str == 'X') // hexa ABCDF
			{
				ft_itos(va_arg(arg, unsigned int), 16, 1);
			}
			if (*str == '.') // precision
			{
				
			}
			if (*str == '0') // Width
			{
				char *tmp = str;
				char *str2;

				while (ft_isdigit(*str))
					str++;
				int zeron = ft_atoi(ft_strndup(tmp,str - tmp));
				int	ar = va_arg(arg, int);
				if (ar < 0)
				{
					str2 = ft_itos(ar, 10,0);
					zeron -= ft_strlen(str2) + 1;
					ft_putchar('-');
					ft_printnchar('0', zeron);
					ft_putstr(str2+1);
				}
				else
				{
					str2 = ft_itos(ar, 10,0);
					zeron -= ft_strlen(str2);
					ft_printnchar('0', zeron);
					ft_putstr(str2);
				}




			}
			//if (*str == '#') // precede octal by 0 or hex by 0x
			//if (*str == '0') // followed by number padding with 0 
			str++;
			
		}
		ft_putchar(*str);
		str++;
	}
	va_end(arg);
	




	//printf("%d ", va_arg(arg, mnt));
	//printf("%d ", va_arg(arg, int));
	//printf("%d ", va_arg(arg, int));
	//

	//printf("ALodaslkdas %d %d",1);
	return (0);
}

//int	parser(char *str)
//{
	
//}
