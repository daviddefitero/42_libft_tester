/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 21:51:29 by david             #+#    #+#             */
/*   Updated: 2025/10/07 22:02:06 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

static size_t	ft_get_values(char **r_str, char **expted, char **rslt)
{
	size_t	len_r_str;

	*r_str = ft_randstr(20);
	len_r_str = strlen(*r_str);
	*expted = malloc(len_r_str + 1);
	*rslt = malloc(len_r_str + 1);
	len_r_str = ft_randnbr_range(len_r_str - 5, len_r_str);
	strlcpy(*expted, *r_str, len_r_str);
	ft_strlcpy(*rslt, *r_str, len_r_str);
	return (len_r_str);
}

t_test	test_ft_strlcpy(void)
{
	t_test	test;
	char	*r_str;
	char	*expted;
	char	*rslt;
	size_t	len;

	ft_init_test(&test, "ft_strcpy");
	while (test.n >= test.t_n)
	{
		len = ft_get_values(&r_str, &expted, &rslt);
		printf("╭─ TEST #%d ─────────────────────────────────╮\n"
			"│ String:\n│ BEGIN STRING\n│ %s\n│ END STRING\n│\n"
			"│ Expected:\n│ BEGIN STRING\n│ %s\n│ END STRING\n│\n"
			"│ %s:\n│ BEGIN STRING\n│ %s\n│ END STRING\n│\n",
			test.t_n, r_str, expted, test.fn_name, rslt);
		ft_check_str(&test, expted, rslt, len);
		printf("╰───────────────────────────────────────────╯\n");
		test.t_n++;
		free(r_str);
		free(expted);
		free(rslt);
	}
	return (test);
}
