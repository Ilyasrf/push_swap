#include "push_swap.h"

// Helper function to add a node at the end of the stack
static void add_node_back(t_stack **stack, t_stack *new_node)
{
    t_stack *temp;

    if (!*stack)
        *stack = new_node;
    else
    {
        temp = *stack;
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
    }
}

// Create a stack from arguments
t_stack *create_stack(char **argv)
{
    t_stack *stack = NULL;
    t_stack *new_node;
    int i = 0;
    int num;

    while (argv[i])
    {
        if (!is_valid_number(argv[i]))
            return (free_stack(&stack), NULL); // Free memory if invalid input
        num = ft_atoi(argv[i]);
        new_node = (t_stack *)malloc(sizeof(t_stack));
        if (!new_node)
            return (free_stack(&stack), NULL); // Free memory if malloc fails
        new_node->value = num;
        new_node->next = NULL;
        add_node_back(&stack, new_node);
        i++;
    }
    if (has_duplicates(stack))
        return (free_stack(&stack), NULL); // Free if duplicates exist
    return (stack);
}

// Free a linked list (stack)
void free_stack(t_stack **stack)
{
    t_stack *temp;

    if (!stack || !*stack)
        return;
    while (*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

// Get stack size
int stack_size(t_stack *stack)
{
    int count = 0;
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return (count);
}

// Check if stack is sorted
int is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);  // Stack is not sorted
        stack = stack->next;
    }
    return (1);  // Stack is sorted
}
