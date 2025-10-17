/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:29:38 by david             #+#    #+#             */
/*   Updated: 2025/10/13 19:29:55 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

static size_t	ft_get_len(char *a, char *b)
{
	if (a == NULL || b == NULL)
		return (0);
	return (ft_maxnbr(strlen(a), strlen(b)));
}

t_test	test_ft_strrchr(void)
{
	t_test	test;
	char	r_char;
	char	*r_str;
	char	*expted;
	char	*rslt;

	ft_init_test(&test, "ft_strrchr");
	while (test.n >= test.t_n)
	{
		r_str = ft_randstr(20);
		r_char = ft_randchar();
		expted = strrchr(r_str, r_char);
		rslt = ft_strrchr(r_str, r_char);
		printf("╭─ TEST #%d ─────────────────────────────────╮\n"
			"│ String:\n│ BEGIN STRING\n│ %s\n│ END STRING\n"
			"│ Char to find: %c\n"
			"│ Expected: %s\n"
			"│ %s: %s\n", test.t_n, r_str, r_char, expted, test.fn_name, rslt);
		ft_check_str(&test, expted, rslt, ft_get_len(expted, rslt));
		printf("╰───────────────────────────────────────────╯\n");
		test.t_n++;
		free(r_str);
	}
	return (test);
}
