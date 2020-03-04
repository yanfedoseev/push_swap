int		ft_sqrt_plus(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
		i++;
	return (i);
}