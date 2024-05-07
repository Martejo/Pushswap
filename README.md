### Push_swap

The “push_swap” project is an exercise in sorting data on a stack with a limited set of operations, while minimizing the number of actions. The project uses two stacks, called A and B. The aim is to receive a series of disordered numbers on stack A and sort them using only the following operations:

- **sa**: `swap a` - Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
- **sb**: `swap b` - Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
- **ss**: `sa` and `sb` at the same time.
- **pa**: `push a` - Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
- **pb**: `push b` - Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
- **ra**: `rotate a` - Shift up all elements of stack A by 1. The first element becomes the last one.
- **rb**: `rotate b` - Shift up all elements of stack B by 1. The first element becomes the last one.
- **rr**: `ra` and `rb` at the same time.
- **rra**: `reverse rotate a` - Shift down all elements of stack A by 1. The last element becomes the first one.
- **rrb**: `reverse rotate b` - Shift down all elements of stack B by 1. The last element becomes the first one.
- **rrr**: `rra` and `rrb` at the same time.
