#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>  // For INT_MAX and INT_MIN

// Stack Structure (Linked List)
typedef struct s_stack
{
    int value;
	int				index;
    struct s_stack *next;
} t_stack;

// 📌 Parsing Functions
int is_valid_number(char *str);
int has_duplicates(t_stack *stack);  // Changed to accept linked list
int count_numbers(char **argv);
t_stack *parse_input(char **argv);  // Now returns a linked list
void free_array(char **arr);

// 📌 Stack Utility Functions
t_stack *create_stack(t_stack **stack, char **argv);
void free_stack(t_stack **stack);
int stack_size(t_stack *stack);
int is_sorted(t_stack *stack);

// 📌 Stack Operations
void sa(t_stack **stack);  // Swap a
void sb(t_stack **stack);  // Swap b
void ss(t_stack **stack_a, t_stack **stack_b);  // Swap both
void pa(t_stack **stack_a, t_stack **stack_b);  // Push a
void pb(t_stack **stack_b, t_stack **stack_a);  // Push b
void ra(t_stack **stack);  // Rotate a
void rb(t_stack **stack);  // Rotate b
void rr(t_stack **stack_a, t_stack **stack_b);  // Rotate both
void rra(t_stack **stack);  // Reverse rotate a
void rrb(t_stack **stack);  // Reverse rotate b
void rrr(t_stack **stack_a, t_stack **stack_b);  // Reverse rotate both

// 📌 Sorting Algorithms
// void sort_three(t_stack **stack);
// void sort_five(t_stack **stack);
// void push_swap(t_stack **stack_a, t_stack **stack_b);

#endif
