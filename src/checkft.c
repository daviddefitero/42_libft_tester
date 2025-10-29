/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:10:49 by dde-fite          #+#    #+#             */
/*   Updated: 2025/10/05 21:28:40 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_print_check(int match)
{
	if (match)
		printf("│ ✅ Result: match                          │\n");
	else
		printf("│ ❌ Result: unmatch                        │\n");
}

void	ft_check_int(t_test *test, int expted, int rslt)
{
	if (expted == rslt)
	{
		test->pass++;
		ft_print_check(1);
	}
	else
	{
		test->fail++;
		ft_print_check(0);
	}
}

void	ft_check_char(t_test *test, char expted, char rslt)
{
	if (expted == rslt)
	{
		test->pass++;
		ft_print_check(1);
	}
	else
	{
		test->fail++;
		ft_print_check(0);
	}
}

void	ft_check_str(t_test *test, char *expted, char *rslt, size_t len)
{
	if (expted == rslt || strncmp(expted, rslt, len) == 0)
	{
		test->pass++;
		ft_print_check(1);
	}
	else
	{
		test->fail++;
		ft_print_check(0);
	}
}

void	ft_check_boolean(t_test *test, int expted, int rslt)
{
	if ((expted && rslt) || (!expted && !rslt))
	{
		test->pass++;
		ft_print_check(1);
	}
	else
	{
		test->fail++;
		ft_print_check(0);
	}
}
