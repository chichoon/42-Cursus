int ft_isalpha(int c)
{
    if (c <= 'Z' && c >= 'A')
        return (1);
    else if (c <= 'z' && c >= 'a')
        return (2);
    return (0);
}