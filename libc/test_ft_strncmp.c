/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:48:31 by dde-fite          #+#    #+#             */
/*   Updated: 2025/10/13 19:29:57 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

static void	ft_get_values(char *r_str[2], int *expted, int *rslt)
{
	size_t	len_r_str[2];
	size_t	max_len;
	int		i;

	i = 0;
	while (i < 2)
	{
		r_str[i] = ft_randstr(20);
		len_r_str[i] = strlen(r_str[i]);
		i++;
	}
	max_len = ft_maxnbr(len_r_str[0], len_r_str[1]);
	*expted = strncmp(r_str[0], r_str[1], max_len);
	*rslt = ft_strncmp(r_str[0], r_str[1], max_len);
}

t_test	test_ft_strncmp(void)
{
	t_test	test;
	char	*r_str[2];
	int		expted;
	int		rslt;

	ft_init_test(&test, "ft_strncmp");
	while (test.n >= test.t_n)
	{
		ft_get_values(r_str, &expted, &rslt);
		printf("╭─ TEST #%d ─────────────────────────────────╮\n"
			"│ String 1:\n│ BEGIN STRING\n│ %s\n│ END STRING\n│\n"
			"│ String 2:\n│ BEGIN STRING\n│ %s\n│ END STRING\n│\n"
			"│ Expected: %d\n"
			"│ %s: %d\n", test.t_n, r_str[0], r_str[1], expted,
			test.fn_name, rslt);
		ft_check_int(&test, expted, rslt);
		printf("╰───────────────────────────────────────────╯\n");
		test.t_n++;
		free(r_str[0]);
		free(r_str[1]);
	}
	return (test);
}
