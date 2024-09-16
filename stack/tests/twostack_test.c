#include "xtal.h"
#include "../stack.h"

TEST(test_create_stacks)
{
	t_stacks *stacks = create_stacks(2);
	
	ASSERT_NOT_NULL(stacks);
	ASSERT_NOT_NULL(stacks -> a);
	ASSERT_NOT_NULL(stacks -> b);

	push(stacks -> a, 1);
	push(stacks -> a, 2);
	push(stacks -> a, 3);
	push(stacks -> a, 4);
	
	push(stacks -> b, 5);
	push(stacks -> b, 6);
	push(stacks -> b, 7);
	push(stacks -> b, 8);

	ASSERT_EQUAL_INT(2, peek(stacks -> a));
	ASSERT_EQUAL_INT(6, peek(stacks -> b));

	pop(stacks -> a);
	pop(stacks -> b);
	ASSERT_EQUAL_INT(1, peek(stacks -> a));
	ASSERT_EQUAL_INT(5, peek(stacks -> b));

	pop(stacks -> a);
	pop(stacks -> a);
	ASSERT_EQUAL_INT(INT_MIN, peek(stacks -> a));
	print_stack(stacks -> a);
	free_stacks(stacks);
}

TEST(test_equals)
{
	t_stacks *stacks = create_stacks(3);
	push(stacks -> a, 1);
	push(stacks -> a, 2);
	push(stacks -> a, 3);
	push(stacks -> b, 1);
	push(stacks -> b, 2);
	push(stacks -> b, 3);
	
	t_stacks *stacks1 = create_stacks(3);
	push(stacks1 -> a, 1);
	push(stacks1 -> a, 2);
	push(stacks1 -> a, 3);
	push(stacks1 -> b, 1);
	push(stacks1 -> b, 2);
	push(stacks1 -> b, 3);

	ASSERT_TRUE(equal(stacks, stacks1));
	free_stacks(stacks);
	free_stacks(stacks1);
}


TEST(test_not_equals)
{
	t_stacks *stacks = create_stacks(3);
	push(stacks -> a, 1);
	push(stacks -> a, 2);
	push(stacks -> a, 3);
	push(stacks -> b, 1);
	push(stacks -> b, 2);
	push(stacks -> b, 3);
	
	t_stacks *stacks1 = create_stacks(3);
	push(stacks1 -> a, 1);
	push(stacks1 -> a, 1);
	push(stacks1 -> a, 3);
	push(stacks1 -> b, 1);
	push(stacks1 -> b, 2);
	push(stacks1 -> b, 3);

	ASSERT_FALSE(equal(stacks, stacks1));
	free_stacks(stacks);
	free_stacks(stacks1);
}
int main()
{
	run_tests();
}
