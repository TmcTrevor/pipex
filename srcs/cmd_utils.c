#include "../includes/pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}
void    error(void)
{
   printf("error");
   exit(0);
}

void	cmd_call(char *argv, char **envm)
{
    char **cmd;
    char *file_path;

    
    cmd = ft_split(argv, ' ');
    file_path =  find_path(cmd[0],envm);
    if (execve(file_path,cmd, envm) == -1)
        return (error());
    
}