/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:22:49 by ffahey            #+#    #+#             */
/*   Updated: 2019/01/10 15:19:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define NUM_BUF_SIZE 32

# define OUT_MEMORY		-1
# define WRONG_SYMBOL	-2

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
# define J_FLAG				0x00002000		//j
# define Z_FLAG				0x00004000		//z
# define WIDTH				0x00100000
# define PRECISION			0x00200000

# define SPECIFICATOR		"cCsSpdDiuUoOxXfF%"

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
	int				width;
	int				precision;
}					t_format;

typedef union		u_float
{
	long double		x;
	char			spec_value; // 1 - NAN, 2 - INF
	struct {
		long int	mantis: 64;
		int			base: 15;
		char		sign: 1;
	};
}					t_float;

int			ft_putchar(char);
int			ft_putnchar(char, size_t);
int			ft_putstr(char*);
int			ft_putwchar(wchar_t);
int			ft_wcharlen(wchar_t);
int			ft_putwstr(wchar_t*);
int			ft_wstrlen(wchar_t*);

int			ft_printf(const char *fmt, ...);
size_t		ft_strlen(char *str);
char		*ft_strdup(const char *str);
char		*ft_strnew(size_t size);
char		*ft_itoa(long n);
char		*ft_strjoin(char *s1, char *s2);

int			ft_print_c(t_format, va_list);
int			ft_print_s(t_format*, va_list);
int			ft_print_p(t_format*, va_list);

int			ft_print_num(t_format*, va_list);
int			ft_print_dec(unsigned long long, t_format*);
int			ft_print_oct(unsigned long long, t_format*);
int			ft_print_hex(unsigned long long, t_format*);
int			ft_print_f(t_format *lst, va_list va);

char		*itoa(t_format *fmt, unsigned long long n);
t_format	*ft_create_format(void);
int			ft_read_format(const char*, t_format*);
int			ft_print_format(t_format *fmt, va_list args);

void		ft_printbit(void*, size_t);
#endif
