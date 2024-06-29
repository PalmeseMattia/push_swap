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
	ASSERT_EQUAL_INT(2, seek(stack));

	pop(stack);
	ASSERT_EQUAL_INT(1, seek(stack));
	
	pop(stack);
	ASSERT_EQUAL_INT(INT_MIN, seek(stack));
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
