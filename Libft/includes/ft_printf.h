/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtolochk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:27:42 by vtolochk          #+#    #+#             */
/*   Updated: 2018/01/31 15:36:22 by vtolochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# define MASK_1 49280
# define MASK_2 14712960
# define MASK_3 4034953344

typedef struct		s_prec
{
	int				prec;
	char			dot;
	char			star;
}					t_prec;

typedef struct		s_width
{
	int				wid;
	char			star;
}					t_width;

typedef struct		s_length
{
	char			hh_len;
	char			h_len;
	char			l_len;
	char			ll_len;
	char			j_len;
	char			z_len;
}					t_length;

typedef struct		s_flags
{
	char			minus;
	char			plus;
	char			space;
	char			hash;
	char			zero;
}					t_flags;

typedef struct		s_specif
{
	char			s_sp;
	char			big_s_sp;
	char			c_sp;
	char			big_c_sp;
	char			d_sp;
	char			i_sp;
	char			big_d_sp;
	char			o_sp;
	char			big_o_sp;
	char			u_sp;
	char			big_u_sp;
	char			x_sp;
	char			big_x_sp;
	char			p_sp;
	char			percent;
	char			fl_point_nb;
}					t_specif;

typedef struct		s_data
{
	t_flags			fl;
	t_width			wid;
	t_prec			prec;
	t_length		len;
	t_specif		spec;
	char			symb;
	unsigned int	u_symb;
	char			*str;
	unsigned int	*u_str;
	char			*prefix;
	char			negative_nb;
	char			flag;
	char			need_free;
}					t_data;

unsigned int		*ft_ustrsub(unsigned int *s, unsigned int st, size_t len);
size_t				ft_ustrlen(unsigned int *str);
int					ft_get_bytes(unsigned int ch);
unsigned int		ft_uputstr(unsigned int *str);
unsigned int		ft_get_act_bits(unsigned int c);
int					ft_putchar(unsigned int c);
int					ft_put(char sign, ssize_t len);
void				ft_len_init(t_length *len);
void				ft_format_init(t_data *data);
void				ft_specifier_init(t_specif *specifier);
void				ft_data_init(t_flags *flags, t_width *width, t_prec *prec);
void				ft_init_all(t_data *data);
void				ft_check_for_spec_oth(t_specif *spec, const char **format);
void				ft_check_for_spec_nb(t_specif *spec, const char **format);
void				ft_check_for_spec_symb(t_specif *spec, const char **format);
void				ft_check_prefix(t_data *data, int str_len);
void				ft_check_for_prec(t_prec *p, const char **f, va_list *ap);
void				ft_check_for_width(t_data *d, const char **f, va_list *ap);
void				ft_check_for_flags(t_flags *flags, const char **format);
void				ft_check_for_len(t_length *len, const char **format);
int					ft_check_all(va_list *ap, t_data *data, const char **form);
int					ft_snumbers(t_data *data, va_list *ap);
int					ft_unumbers(t_data *data, va_list *ap, size_t unsigned_num);
int					ft_str_spec(t_data *data, va_list *ap);
int					ft_print_format_str(t_data *data);
int					ft_found_spec_nb(t_data data);
int					ft_found_spec(t_data data);
int					ft_get_data(va_list *ap, const char **fmt, int i, int ret);
int					ft_print_string(va_list *ap, const char *format);
int					ft_format_str(t_data *data, va_list *ap);
int					ft_if_zero(t_data *data, const char **format);
int					ft_isvalid(const char *format);
int					no_spec(const char **format, int i);
int					ft_else_if_helper(t_data *data, va_list *ap);
int					ft_check_for_color(t_data data, const char **format);
int					ft_fl_point_nb(t_data *d, va_list *ap, int i, size_t tmp);
ssize_t				ft_bin_specif(const char **format, va_list *ap);
int					ft_pointer(t_data *data, va_list *ap);
void				ft_exit_printf(t_data *data);

#endif
