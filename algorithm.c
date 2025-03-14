#include "push_swap.h"

static int	find_largest_index(t_stack *stack)
{
	int max_index;
	t_stack *current;
	int i;
	int pos;
	current =stack;
	max_index = current -> index;
	pos = 0;
	i = 0;
	while (current)
	{
		if (current -> index > max_index)
		{
			max_index = current -> index;
		pos = i;
		}
		current = current -> next;
		i++;
	}
	return pos;
}
static void move_to_stack_b(t_stack **a, t_stack **b, int size)
(
	int i;
)