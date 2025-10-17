/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:30:59 by dde-fite          #+#    #+#             */
/*   Updated: 2025/10/05 23:27:21 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include "../tests.h"

t_test	test_ft_toupper(void)
{
	t_test	test;
	char	r_char;
	char	expted;
	char	rslt;

	ft_init_test(&test, "ft_toupper");
	while (test.n >= test.t_n)
	{
		r_char = ft_randnbr(255);
		expted = toupper(r_char);
		rslt = ft_toupper(r_char);
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
