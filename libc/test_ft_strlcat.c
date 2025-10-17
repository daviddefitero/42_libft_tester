/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 21:51:29 by david             #+#    #+#             */
/*   Updated: 2025/10/05 23:27:28 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

static void	ft_get_values(char *r_str[2], char **expted, char **rslt)
{
	size_t	len_r_str[2];
	size_t	total_len;
	int		i;

	i = 0;
	while (i < 2)
	{
		r_str[i] = ft_randstr(20);
		len_r_str[i] = strlen(r_str[i]);
		i++;
	}
	total_len = len_r_str[0] + len_r_str[1] + 1;
	*expted = malloc(total_len);
	*rslt = malloc(total_len);
	strlcpy(*expted, r_str[0], len_r_str[0]);
	strlcpy(*rslt, r_str[0], len_r_str[0]);
	strlcat(*expted, r_str[1], total_len);
	ft_strlcat(*rslt, r_str[1], total_len);
}

t_test	test_ft_strlcat(void)
{
	t_test	test;
	char	*r_str[2];
	char	*expted;
	char	*rslt;

	ft_init_test(&test, "ft_strlcat");
	while (test.n >= test.t_n)
	{
		ft_get_values(r_str, &expted, &rslt);
		printf("╭─ TEST #%d ─────────────────────────────────╮\n"
			"│ String 1:\n│ BEGIN STRING\n│ %s\n│ END STRING\n│\n"
			"│ String 2:\n│ BEGIN STRING\n│ %s\n│ END STRING\n│\n"
			"│ Expected:\n│ BEGIN STRING\n│ %s\n│ END STRING\n│\n"
			"│ %s:\n│ BEGIN STRING\n│ %s\n│ END STRING\n│\n",
			test.t_n, r_str[0], r_str[1], expted, test.fn_name, rslt);
		ft_check_str(&test, expted, rslt, strlen(expted));
		printf("╰───────────────────────────────────────────╯\n");
		test.t_n++;
		free(r_str[0]);
		free(r_str[1]);
		free(expted);
		free(rslt);
	}
	return (test);
}
