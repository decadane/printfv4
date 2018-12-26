/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:22:49 by ffahey            #+#    #+#             */
/*   Updated: 2018/12/26 17:00:40 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define NUM_BUF_SIZE 32

# define OUT_MEMORY		-1
# define WRONG_SYMBOL	-2

# define ERROR_FLAG			0x10000000		//error symbol
# define HH_FLAG			0x00000001		//hh
# define H_FLAG				0x00000002		//h
# define L_FLAG				0x00000004		//l
# define LL_FLAG			0x00000008		//ll
# define LEFTFORMAT_FLAG	0x00000010		//-
# define SHOWSIGN_FLAG		0x00000020		//+
# define HASH_FLAG			0x00000040		//#
# define ZERO_FLAG			0x00000080		//0
# define SIGNED_FLAG		0x00000100		//d i
# define CAPS_FLAG			0x00000200		//X
# define SPACE_FLAG			0x00000400		//' '
# define POS_FLAG			0x00000800		//positive number
# define NEG_FLAG			0x00001000		//negative number



# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct		s_format
{
	char			spec;
	char			*str;
	char			sign;
	unsigned		flags;
	unsigned		width;
	unsigned		precision;
}					t_format;

void		ft_putchar(char);
void		ft_putstr(char*);

int			ft_printf(const char *fmt, ...);
size_t		ft_strlen(char *str);
char		*ft_strdup(const char *str);
char		*ft_strnew(size_t size);
int			ft_print_c(t_format, char);
int			ft_print_s(t_format, char*);
int			ft_print_num(t_format*, va_list);
int			ft_print_p(void *p);

char		*itoa(t_format *fmt, unsigned long long n);
t_format	*ft_create_format(void);
int			ft_read_format(const char*, t_format*);
int			ft_print_format(t_format *fmt, va_list args);


#endif
