/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy- <mcauchy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:45:56 by mcauchy-          #+#    #+#             */
/*   Updated: 2025/01/16 16:39:39 by mcauchy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_stack
{
	int				nb;
	int				index;
	struct s_stack	*next;
}				t_stack;

// ---------------------------------------------------------------------------
//				FONCTIONS DE LIBFT
// ---------------------------------------------------------------------------

char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int nb);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
t_stack	*lst_before_last(t_stack *lst);
int		ft_only_sep(char *str, char charset);

// ---------------------------------------------------------------------------
// 						OPÉRATIONS SUR LES PILES
// ---------------------------------------------------------------------------

int		swap(t_stack **lst);
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b);

int		push(t_stack **src, t_stack **dest);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);

int		rotate(t_stack **lst);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);

int		reverse_rotate(t_stack **lst);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);

void	ft_putendl_fd(char *s, int fd);

// ---------------------------------------------------------------------------
//						VALIDATION DES ARGUMENTS
// ---------------------------------------------------------------------------

int		check_overflow(long nb);
int		ft_len(char **av);
int		check_doublon(char **av);
int		check_num(char *av);
long	ft_atol(const char *str);
void	check_arg(int ac, char **av);
void	validate_argument(char **check, int ac, int i);

// ---------------------------------------------------------------------------
//						ALGORITHMES DE TRI
// ---------------------------------------------------------------------------

t_stack	*initialize_stack(int ac, char **av);
int		is_sorted(t_stack **lst);
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	ft_putback_in_stack(t_stack **stack_a, t_stack **stack_b);

void	radix_sort(t_stack **stack_a, t_stack **stack_b);

// ---------------------------------------------------------------------------
//						TRI SIMPLE
// ---------------------------------------------------------------------------

void	sort_5(t_stack **stack_a, t_stack **stack_b);
void	push_to_b(t_stack **stack_a, t_stack **stack_b, int min);
int		find_max(t_stack *lst);
int		find_position(t_stack *stack_a, int min);
int		quick_find_min(t_stack *stack_a);
void	sort_3(t_stack **lst);

// ---------------------------------------------------------------------------
//					GESTION DE LA MÉMOIRE ET UTILITAIRES
// ---------------------------------------------------------------------------

void	free_stack(t_stack **lst);
void	ft_error(char *exit_msg);
char	**ft_free(char **to_free);

// ---------------------------------------------------------------------------
//					INDEX
// ---------------------------------------------------------------------------

void	sort_indice(t_stack *stack_a);
int		find_index_min(t_stack *stack_a);
int		find_index_max(t_stack *lst);
int		max_index_bits(t_stack **lst);

#endif