/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:30:59 by dde-fite          #+#    #+#             */
/*   Updated: 2025/10/05 22:57:36 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include "../tests.h"

t_test	test_ft_isprint(void)
{
	t_test	test;
	char	r_char;
	int		expted;
	int		rslt;

	ft_init_test(&test, "ft_isprint");
	while (test.n >= test.t_n)
	{
		r_char = ft_randnbr(255);
		expted = isprint(r_char);
		rslt = ft_isprint(r_char);
		printf("╭─ TEST #%d ─────────────────────────────────╮\n"
			"│ Char: %c\n"
			"│ Expected: %d\n"
			"│ %s: %d\n", test.t_n, r_char, expted, test.fn_name, rslt);
		ft_check_boolean(&test, expted, rslt);
		printf("╰───────────────────────────────────────────╯\n");
		test.t_n++;
	}
	return (test);
}
