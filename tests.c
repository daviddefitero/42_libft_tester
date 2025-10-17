/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 21:31:46 by david             #+#    #+#             */
/*   Updated: 2025/10/16 19:37:52 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "tests.h"

int	ft_get_nbr_test(void)
{
	int	nbr;

	printf("➤ Enter the number of tests: ");
	scanf("%d", &nbr);
	return (nbr);
}

void	ft_init_test(t_test *test, char *fn_name)
{
	printf("\n➤ Selected Function: %s\n\n", fn_name);
	test->fn_name = fn_name;
	test->n = ft_get_nbr_test();
	test->t_n = 1;
	test->pass = 0;
	test->fail = 0;
	printf("\n╔═══════════════════════════════════════════╗\n"
		"║          Testing %s (x%d)          ║\n"
		"╚═══════════════════════════════════════════╝\n\n",
		test->fn_name, test->n);
}

static void	ft_print_header(void)
{
	printf("\n**************************************************************\n"
		"╔════════════════════════════════════════════════════════════╗\n"
		"║                    L I B F T   T E S T                     ║\n"
		"╚════════════════════════════════════════════════════════════╝\n"
		"                       d d e - f i t e\n"
		"**************************************************************\n\n\n"
		"For now, functions designed to directly modify the value of\n"
		"their arguments do not have return verification in the tests.\n\n"
		"» Select a function:\n"
		"\n╭───────────── LIBC FUNCTIONS ──────────────╮\n"
		"│ **  1. isalpha       **  2. isdigit       │\n"
		"│ **  3. isalnum       **  4. isascii       │\n"
		"│ **  5. isprint       **  6. strlen        │\n"
		"│ //  7. memset        //  8. bzero         │\n"
		"│ //  9. memcpy        // 10. memmove       │\n"
		"│ ** 11. strlcpy       ** 12. strlcat       │\n"
		"│ ** 13. toupper       ** 14. tolower       │\n"
		"│ ** 15. strchr        ** 16. strrchr       │\n"
		"│ ** 17. strncmp       // 18. memchr        │\n"
		"│ // 19. memcmp        // 20. strnstr       │\n"
		"│ // 21. atoi          // 22. calloc        │\n"
		"│ **  0. Exit                               │\n"
		"╰───────────────────────────────────────────╯\n"
		"\n***** --------> ");
}

// int	main(void)
// {
// 	int		usr_choice;
// 	t_test	test;

// 	srand(time(NULL));
// 	usr_choice = 1;
// 	while (usr_choice != 0)
// 	{
// 		ft_print_header();
// 		scanf("%d", &usr_choice);
// 		if (usr_choice == 1)
// 			test = test_ft_isalpha();
// 		else if (usr_choice == 2)
// 			test = test_ft_isdigit();
// 		else if (usr_choice == 3)
// 			test = test_ft_isalnum();
// 		else if (usr_choice == 4)
// 			test = test_ft_isascii();
// 		else if (usr_choice == 5)
// 			test = test_ft_isprint();
// 		else if (usr_choice == 6)
// 			test = test_ft_strlen();
// 		else if (usr_choice == 11)
// 			test = test_ft_strlcpy();
// 		else if (usr_choice == 12)
// 			test = test_ft_strlcat();
// 		else if (usr_choice == 13)
// 			test = test_ft_toupper();
// 		else if (usr_choice == 14)
// 			test = test_ft_tolower();
// 		else if (usr_choice == 15)
// 			test = test_ft_strchr();
// 		else if (usr_choice == 16)
// 			test = test_ft_strrchr();
// 		else if (usr_choice == 17)
// 			test = test_ft_strncmp();
// 		if (test.fn_name != NULL)
// 			printf("\n╔══════════════════════════════╗\n"
// 				"║ Summary (%s)         ║\n"
// 				"║ ✅ Passed: %d                 ║\n"
// 				"║ ❌ Failed: %d                 ║\n"
// 				"╚══════════════════════════════╝\n",
// 				test.fn_name, test.pass, test.fail);
// 	}
// }
