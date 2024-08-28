#include "xtal.h"
#include "../stack.h"

TEST(test_sa)
{
	t_stacks *stacks = create_stacks(3);
	push(stacks -> a, 1);
	push(stacks -> a, 2);
	push(stacks -> a, 3);

	printf("Stack Before SA: ");
	print_stack(stacks -> a);	
	ASSERT_EQUAL_INT(3, peek(stacks -> a));
	sa(stacks);
	
	printf("Stack After SA: ");
	print_stack(stacks -> a);	
	ASSERT_EQUAL_INT(2, peek(stacks -> a));
}

TEST(test_sa_no_elements)
{
	t_stacks *stacks = create_stacks(1);
	push(stacks -> a, 1);
	push(stacks -> a, 2);
	push(stacks -> a, 3);

	printf("Stack Before SA: ");
	print_stack(stacks -> a);	
	ASSERT_EQUAL_INT(1, peek(stacks -> a));
	sa(stacks);
	
	printf("Stack After SA: ");
	print_stack(stacks -> a);	
	ASSERT_EQUAL_INT(1, peek(stacks -> a));
}

TEST(test_sa_two_elements)
{
	t_stacks *stacks = create_stacks(2);
	push(stacks -> a, 1);
	push(stacks -> a, 2);

	printf("Stack Before SA: ");
	print_stack(stacks -> a);	
	ASSERT_EQUAL_INT(2, peek(stacks -> a));
	sa(stacks);
	
	printf("Stack After SA: ");
	print_stack(stacks -> a);	
	ASSERT_EQUAL_INT(1, peek(stacks -> a));
}

TEST(test_sb)
{
	t_stacks *stacks = create_stacks(3);
	push(stacks -> b, 1);
	push(stacks -> b, 2);
	push(stacks -> b, 3);

	printf("Stack Before SB: ");
	print_stack(stacks -> b);	
	ASSERT_EQUAL_INT(3, peek(stacks -> b));
	sb(stacks);
	
	printf("Stack After SB: ");
	print_stack(stacks -> b);	
	ASSERT_EQUAL_INT(2, peek(stacks -> b));
}

TEST(test_sb_no_elements)
{
	t_stacks *stacks = create_stacks(1);
	push(stacks -> b, 1);
	push(stacks -> b, 2);
	push(stacks -> b, 3);

	printf("Stack Before SB: ");
	print_stack(stacks -> b);	
	ASSERT_EQUAL_INT(1, peek(stacks -> b));
	sb(stacks);
	
	printf("Stack After SB: ");
	print_stack(stacks -> b);	
	ASSERT_EQUAL_INT(1, peek(stacks -> b));
}

TEST(test_ss)
{
	t_stacks *stacks = create_stacks(3);
	push(stacks -> b, 1);
	push(stacks -> b, 2);
	push(stacks -> b, 3);

	push(stacks -> a, 1);
	push(stacks -> a, 2);
	push(stacks -> a, 3);

	printf("Stacks:\n");
	print_stack(stacks -> a);	
	print_stack(stacks -> b);	
	ASSERT_EQUAL_INT(3, peek(stacks -> b));

	ss(stacks);	
	printf("Stacks After SS:\n");
	print_stack(stacks -> b);	
	print_stack(stacks -> a);
	ASSERT_EQUAL_INT(2, peek(stacks -> b));

	ss(stacks);	
	printf("Stacks After SS:\n");
	print_stack(stacks -> b);	
	print_stack(stacks -> a);
	ASSERT_EQUAL_INT(3, peek(stacks -> b));
}

TEST(test_pa)
{
	t_stacks *stacks = create_stacks(6);
	push(stacks -> a, 1);
	push(stacks -> a, 2);
	push(stacks -> a, 3);

	push(stacks -> b, 4);
	push(stacks -> b, 5);
	push(stacks -> b, 6);


	print_stacks(stacks);

	pa(stacks);
	printf("\nStacks After PA:\n");
	print_stacks(stacks);
	ASSERT_EQUAL_INT(6, peek(stacks -> a));

	pa(stacks);
	pa(stacks);
	pa(stacks);
	pa(stacks);
	printf("Stacks After Spamming PA:\n");
	print_stacks(stacks);
	ASSERT_EQUAL_INT(4, peek(stacks -> a));
	ASSERT_EQUAL_INT(INT_MIN, peek(stacks -> b));
}

TEST(test_pb)
{
	t_stacks *stacks = create_stacks(6);
	push(stacks -> a, 1);
	push(stacks -> a, 2);
	push(stacks -> a, 3);
	ASSERT_EQUAL_INT(2, stacks -> a -> top)

	push(stacks -> b, 4);
	push(stacks -> b, 5);
	push(stacks -> b, 6);


	print_stacks(stacks);

	pb(stacks);
	printf("\nStacks After PB:\n");
	print_stacks(stacks);
	ASSERT_EQUAL_INT(3, peek(stacks -> b));

	pb(stacks);
	pb(stacks);
	pb(stacks);
	pb(stacks);
	printf("Stacks After Spamming PB:\n");
	print_stacks(stacks);
	ASSERT_EQUAL_INT(1, peek(stacks -> b));
	ASSERT_EQUAL_INT(INT_MIN, peek(stacks -> a));
}

TEST(test_ra)
{
	t_stacks *stacks = create_stacks(3);
	push(stacks -> a, 1);
	push(stacks -> a, 2);
	push(stacks -> a, 3);
	ASSERT_EQUAL_INT(2, stacks -> a -> top);
	
	print_stacks(stacks);
	ra(stacks);
	ASSERT_EQUAL_INT(2, stacks -> a -> top);
	printf("\nStacks After RA:\n");
	print_stacks(stacks);
	ASSERT_EQUAL_INT(2, peek(stacks -> a));

	ra(stacks);
	ra(stacks);
	ASSERT_EQUAL_INT(2, stacks -> a -> top);
	printf("Stacks After Spamming RA:\n");
	print_stacks(stacks);
}

TEST(test_ra_no_space)
{
	t_stacks *stacks = create_stacks(1);
	push(stacks -> a, 1);
	push(stacks -> a, 2);
	push(stacks -> a, 3);
	ASSERT_EQUAL_INT(0, stacks -> a -> top);
	
	print_stacks(stacks);
	ra(stacks);
	ASSERT_EQUAL_INT(0, stacks -> a -> top);
	printf("\nStacks After RA:\n");
	print_stacks(stacks);
	ASSERT_EQUAL_INT(1, peek(stacks -> a));
}

int main()
{
	run_tests();
}
