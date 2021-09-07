int main(int argc, char **argv, char **envm)
{
    pid_t pid;
    int p[2];

    if (argc != 5)
    {
        ft_putstr_fd("Usage : ./pipex infile cmd1 cmd2 outfile\n", 2);
		return (0);
    }
    if (pipe(p) == -1)
        return (0);
    
}