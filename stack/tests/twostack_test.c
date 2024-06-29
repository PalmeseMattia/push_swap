#include "xtal.h"
#include "../stack.h"

TEST(test_create_twostack)
{
	t_twostack *twostack = create_twostack(2);
	
	ASSERT_NOT_NULL(twostack);
	ASSERT_NOT_NULL(twostack -> a);
	ASSERT_NOT_NULL(twostack -> b);

	push(twostack -> a, 1);
	push(twostack -> a, 2);
	push(twostack -> a, 3);
	push(twostack -> a, 4);
	
	push(twostack -> b, 5);
	push(twostack -> b, 6);
	push(twostack -> b, 7);
	push(twostack -> b, 8);

	ASSERT_EQUAL_INT(2, seek(twostack -> a));
	ASSERT_EQUAL_INT(6, seek(twostack -> b));

	pop(twostack -> a);
	pop(twostack -> b);
	ASSERT_EQUAL_INT(1, seek(twostack -> a));
	ASSERT_EQUAL_INT(5, seek(twostack -> b));

	pop(twostack -> a);
	pop(twostack -> a);
	ASSERT_EQUAL_INT(INT_MIN, seek(twostack -> a));
	print_stack(twostack -> a);
	free_twostack(twostack);
}

int main()
{
	run_tests();
}
