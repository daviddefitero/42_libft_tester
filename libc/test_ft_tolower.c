/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:30:59 by dde-fite          #+#    #+#             */
/*   Updated: 2025/10/05 23:27:19 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include "../tests.h"

t_test	test_ft_tolower(void)
{
	t_test	test;
	char	r_char;
	char	expted;
	char	rslt;

	ft_init_test(&test, "ft_tolower");
	while (test.n >= test.t_n)
	{
		r_char = ft_randnbr(255);
		expted = tolower(r_char);
		rslt = ft_tolower(r_char);
		printf("╭─ TEST #%d ─────────────────────────────────╮\n"
			"│ Char: %c\n"
			"│ Expected: %c\n"
			"│ %s: %c\n", test.t_n, r_char, expted, test.fn_name, rslt);
		ft_check_char(&test, expted, rslt);
		printf("╰───────────────────────────────────────────╯\n");
		test.t_n++;
	}
	return (test);
}
