#include "xtal.h"
#include "../stack.h"

TEST(test_create_stack)
{
	t_stack *stack = create_stack(2);
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	push(stack, 4);
	print_stack(stack);

	ASSERT_NOT_NULL(stack);
	ASSERT_NOT_NULL(stack -> elements);

	ASSERT_EQUAL_INT(1, stack -> elements[0]);
	ASSERT_EQUAL_INT(2, stack -> elements[1]);
	ASSERT_EQUAL_INT(2, peek(stack));

	pop(stack);
	ASSERT_EQUAL_INT(1, peek(stack));
	
	pop(stack);
	ASSERT_EQUAL_INT(INT_MIN, peek(stack));
	
	free_stack(stack);
}

TEST(test_push_back)
{
	t_stack *stack = create_stack(5);
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	push(stack, 4);
	print_stack(stack);

	push_back(stack, 0);
	printf("Push back 0:\n");
	print_stack(stack);
	ASSERT_EQUAL_INT(0, stack -> elements[0]);
	ASSERT_EQUAL_INT(4, stack -> top);
	free_stack(stack);
}

TEST(test_push_back_full_stack)
{
	t_stack *stack = create_stack(2);
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	push(stack, 4);
	print_stack(stack);

	push_back(stack, 0);
	printf("Push back 0:\n");
	print_stack(stack);
	ASSERT_EQUAL_INT(1, stack -> elements[0]);
	ASSERT_EQUAL_INT(1, stack -> top);
	free_stack(stack);
}


TEST(test_create_empty_stack)
{
	t_stack *stack = create_stack(0);
	ASSERT_NULL(stack -> elements);
	free(stack);
}

int main()
{
	run_tests();
}
