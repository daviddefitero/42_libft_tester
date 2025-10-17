/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 00:07:42 by david             #+#    #+#             */
/*   Updated: 2025/10/13 19:29:06 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>

typedef struct s_test
{
	char	*fn_name;
	int		n;
	int		t_n;
	int		pass;
	int		fail;
}	t_test;

void	ft_init_test(t_test *test, char *fn_name);
int		ft_get_nbr_test(void);
void	ft_check_int(t_test *test, int expted, int rslt);
void	ft_check_char(t_test *test, char expted, char rslt);
void	ft_check_str(t_test *test, char *expted, char *rslt, size_t len);
void	ft_check_boolean(t_test *test, int expted, int rslt);

int		ft_randnbr(int max);
int		ft_randnbr_range(int min, int max);
char	ft_randchar(void);
char	*ft_randstr(int max);

t_test	test_ft_isalpha(void);
t_test	test_ft_isdigit(void);
t_test	test_ft_isalnum(void);
t_test	test_ft_isascii(void);
t_test	test_ft_isprint(void);
t_test	test_ft_strlen(void);
t_test	test_ft_strlcpy(void);
t_test	test_ft_strlcat(void);
t_test	test_ft_toupper(void);
t_test	test_ft_tolower(void);
t_test	test_ft_strncmp(void);
t_test	test_ft_strchr(void);
t_test	test_ft_strrchr(void);
