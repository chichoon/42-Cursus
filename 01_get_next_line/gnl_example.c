static ssize_t  is_newline(const char *s)
{
    size_t  index;
    index = 0;
    while (s[index])
    {
        if (s[index] == '\n')
            return (index);
        index++;
    }
    return (-1);
}
static int      found_nl(char **carrier, char **line, ssize_t nl_index)
{
    char    *temp;
    (*carrier)[nl_index] = '\0';
    *line = ft_strdup(*carrier);
    temp = ft_strdup(*carrier + nl_index + 1);
    free(*carrier);
    *carrier = temp;
    return (1);
}
static int      not_found_nl(char **carrier, char **line)
{
    *line = ft_strdup(*carrier);
    free(*carrier);
    *carrier = 0;
    return (0);
}
int             get_next_line(int fd, char **line)
{
    static char *carrier = 0;
    char        buf[BUFFER_SIZE + 1];
    char        *temp;
    ssize_t     r_bytes;
    ssize_t     nl_index;
    if (fd < 0 || BUFFER_SIZE < 1 || line == 0)
        return (-1);
    if (!carrier)
        carrier = ft_strdup("");
    while ((r_bytes = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[r_bytes] = '\0';
        temp = ft_strjoin(carrier, buf);
        free(carrier);
        carrier = temp;
        if ((nl_index = is_newline(carrier)) >= 0)
            return (found_nl(&carrier, line, nl_index));
    }
    if (r_bytes == -1)
        return (-1);
    if ((nl_index = is_newline(carrier)) >= 0)
        return (found_nl(&carrier, line, nl_index));
    return (not_found_nl(&carrier, line));
}
