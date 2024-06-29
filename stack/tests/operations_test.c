#include "xtal.h"
#include "stack.h"

TEST(test_sa)
{
	t_twostack *twostack = create_twostack(3);
	push(twostack -> a, 1);
	push(twostack -> a, 2);
	push(twostack -> a, 3);

	printf("Stack Before SA: ");
	print_stack(twostack -> a);	
	ASSERT_EQUAL_INT(3, seek(twostack -> a));
	sa(twostack);
	
	printf("Stack After SA: ");
	print_stack(twostack -> a);	
	ASSERT_EQUAL_INT(2, seek(twostack -> a));
}

TEST(test_sa_no_elements)
{
	t_twostack *twostack = create_twostack(1);
	push(twostack -> a, 1);
	push(twostack -> a, 2);
	push(twostack -> a, 3);

	printf("Stack Before SA: ");
	print_stack(twostack -> a);	
	ASSERT_EQUAL_INT(1, seek(twostack -> a));
	sa(twostack);
	
	printf("Stack After SA: ");
	print_stack(twostack -> a);	
	ASSERT_EQUAL_INT(1, seek(twostack -> a));
}

TEST(test_sb)
{
	t_twostack *twostack = create_twostack(3);
	push(twostack -> b, 1);
	push(twostack -> b, 2);
	push(twostack -> b, 3);

	printf("Stack Before SB: ");
	print_stack(twostack -> b);	
	ASSERT_EQUAL_INT(3, seek(twostack -> b));
	sb(twostack);
	
	printf("Stack After SB: ");
	print_stack(twostack -> b);	
	ASSERT_EQUAL_INT(2, seek(twostack -> b));
}

TEST(test_sb_no_elements)
{
	t_twostack *twostack = create_twostack(1);
	push(twostack -> b, 1);
	push(twostack -> b, 2);
	push(twostack -> b, 3);

	printf("Stack Before SB: ");
	print_stack(twostack -> b);	
	ASSERT_EQUAL_INT(1, seek(twostack -> b));
	sb(twostack);
	
	printf("Stack After SB: ");
	print_stack(twostack -> b);	
	ASSERT_EQUAL_INT(1, seek(twostack -> b));
}

int main()
{
	run_tests();
}
