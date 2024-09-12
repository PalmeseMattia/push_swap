// I want to create a Tree of depth M and with N children for each node
typedef struct s_node
{
	t_stacks	*stacks;
	int			orderliness;
} t_node;

t_node	*create_tree(unsigned int nodes)
{
	t_node	*tree;
	int		i;
	
	tree = (t_node *)malloc(nodes * sizeof(t_node));
	i = 0;
	if (!tree)
			return (NULL);
	while (i < nodes)
	{
		tree[i].orderliness = 0;
		tree[i].stacks = NULL;
	}
	return (tree);
}
