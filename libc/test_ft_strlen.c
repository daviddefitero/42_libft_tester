/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:29:38 by david             #+#    #+#             */
/*   Updated: 2025/10/05 22:17:46 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

t_test	test_ft_strlen(void)
{
	t_test	test;
	char	*r_str;
	size_t	expted;
	size_t	rslt;

	ft_init_test(&test, "ft_strlen");
	while (test.n >= test.t_n)
	{
		r_str = ft_randstr(20);
		expted = strlen(r_str);
		rslt = ft_strlen(r_str);
		printf("╭─ TEST #%d ─────────────────────────────────╮\n"
			"│ String:\n│ BEGIN STRING\n│ %s\n│ END STRING\n│\n"
			"│ Expected: %ld\n"
			"│ %s: %ld\n", test.t_n, r_str, expted, test.fn_name, rslt);
		ft_check_int(&test, expted, rslt);
		printf("╰───────────────────────────────────────────╯\n");
		test.t_n++;
		free(r_str);
	}
	return (test);
}
