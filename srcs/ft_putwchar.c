#include <wchar.h>
#include <unistd.h>
#include "ft_printf.h"

int		utf8_convertion(wchar_t wch, char *wstr)
{
	int		len;

	len = 0;
	if (wch <= 0x7f)
		wstr[len++] = (char)wch;
	else if (wch <= 0x07FF)
	{
		wstr[len++] = (char)(wch >> 6) | 0xC0;
		wstr[len++] = ((char)wch & 0x3F) | 0x80;
	}
	else if (wch <= 0xFFFF)
	{
		wstr[len++] = (char)(wch >> 12) | 0xE0;
		wstr[len++] = ((char)(wch >> 6) & 0x3F) | 0x80;
		wstr[len++] = ((char)wch & 0x3F) | 0x80;
	}
	else if (wch <= 0x10FFFF)
	{
		wstr[len++] = (char)(wch >> 18) | 0xF0;
		wstr[len++] = ((char)(wch >> 12) & 0x3F) | 0x80;
		wstr[len++] = ((char)(wch >> 6) & 0x3F) | 0x80;
		wstr[len++] = ((char)wch & 0x3F) | 0X80;
	}
	return (len);
}

int		ft_wcharlen(wchar_t wch)
{
	if (wch <= 0x7f)
		return (1);
	else if (wch <= 0x07FF)
		return (2);
	else if (wch <= 0xFFFF)
		return (3);
	else if (wch <= 0x10FFFF)
		return (4);
	else
		return (-1);
}

int		ft_putwchar(wchar_t wc)
{
	char	conv[4];
	int		len;

	len = utf8_convertion(wc, conv);
	if (!len)
		return (-1);
	write(1, conv, len);
	return (len);
}
