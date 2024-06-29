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

TEST(test_ss)
{
	t_twostack *twostack = create_twostack(3);
	push(twostack -> b, 1);
	push(twostack -> b, 2);
	push(twostack -> b, 3);

	push(twostack -> a, 1);
	push(twostack -> a, 2);
	push(twostack -> a, 3);

	printf("Stacks:\n");
	print_stack(twostack -> a);	
	print_stack(twostack -> b);	
	ASSERT_EQUAL_INT(3, seek(twostack -> b));

	ss(twostack);	
	printf("Stacks After SS:\n");
	print_stack(twostack -> b);	
	print_stack(twostack -> a);
	ASSERT_EQUAL_INT(2, seek(twostack -> b));

	ss(twostack);	
	printf("Stacks After SS:\n");
	print_stack(twostack -> b);	
	print_stack(twostack -> a);
	ASSERT_EQUAL_INT(3, seek(twostack -> b));
}

TEST(test_pa)
{
	t_twostack *twostack = create_twostack(6);
	push(twostack -> a, 1);
	push(twostack -> a, 2);
	push(twostack -> a, 3);

	push(twostack -> b, 4);
	push(twostack -> b, 5);
	push(twostack -> b, 6);


	print_twostack(twostack);

	pa(twostack);
	printf("\nStacks After PA:\n");
	print_twostack(twostack);
	ASSERT_EQUAL_INT(6, seek(twostack -> a));

	pa(twostack);
	pa(twostack);
	pa(twostack);
	pa(twostack);
	printf("Stacks After Spamming PA:\n");
	print_twostack(twostack);
	ASSERT_EQUAL_INT(4, seek(twostack -> a));
	ASSERT_EQUAL_INT(INT_MIN, seek(twostack -> b));
}

TEST(test_pb)
{
	t_twostack *twostack = create_twostack(6);
	push(twostack -> a, 1);
	push(twostack -> a, 2);
	push(twostack -> a, 3);
	ASSERT_EQUAL_INT(2, twostack -> a -> top)

	push(twostack -> b, 4);
	push(twostack -> b, 5);
	push(twostack -> b, 6);


	print_twostack(twostack);

	pb(twostack);
	printf("\nStacks After PB:\n");
	print_twostack(twostack);
	ASSERT_EQUAL_INT(3, seek(twostack -> b));

	pb(twostack);
	pb(twostack);
	pb(twostack);
	pb(twostack);
	printf("Stacks After Spamming PB:\n");
	print_twostack(twostack);
	ASSERT_EQUAL_INT(1, seek(twostack -> b));
	ASSERT_EQUAL_INT(INT_MIN, seek(twostack -> a));
}

TEST(test_ra)
{
	t_twostack *twostack = create_twostack(3);
	push(twostack -> a, 1);
	push(twostack -> a, 2);
	push(twostack -> a, 3);
	ASSERT_EQUAL_INT(2, twostack -> a -> top);
	
	print_twostack(twostack);
	ra(twostack);
	ASSERT_EQUAL_INT(2, twostack -> a -> top);
	printf("\nStacks After RA:\n");
	print_twostack(twostack);
	ASSERT_EQUAL_INT(2, seek(twostack -> a));

	ra(twostack);
	ra(twostack);
	ASSERT_EQUAL_INT(2, twostack -> a -> top);
	printf("Stacks After Spamming RA:\n");
	print_twostack(twostack);
}

TEST(test_ra_no_space)
{
	t_twostack *twostack = create_twostack(1);
	push(twostack -> a, 1);
	push(twostack -> a, 2);
	push(twostack -> a, 3);
	ASSERT_EQUAL_INT(0, twostack -> a -> top);
	
	print_twostack(twostack);
	ra(twostack);
	ASSERT_EQUAL_INT(0, twostack -> a -> top);
	printf("\nStacks After RA:\n");
	print_twostack(twostack);
	ASSERT_EQUAL_INT(1, seek(twostack -> a));
}

int main()
{
	run_tests();
}
