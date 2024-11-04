#include "get_next_line.h"

char *ft_strdup(char *s)
{
	int i = 0;
	char *res;

	while (s[i])
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char *get_next_line(int fd)
{
	int i = 0;
	static char buf[BUFFER_SIZE];
	static int buf_rd;
	static int buf_pos;
	char line[7000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buf_pos >= buf_rd)
		{
			buf_rd = read(fd, buf, BUFFER_SIZE);
			buf_pos = 0;
			if (buf_rd <= 0)
				break ;
		}
		if (line[i - 1] == '\n')
			break ;
		line[i] = buf[buf_pos++];
		i++;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

// #include <stdio.h>
// int main()
// {
//     int fd = open("./test.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return 1;
//     }
//     char *line = get_next_line(fd);
//     if (line)
//     {
//         printf("%s", line);
//         free(line);
//     }
//     close(fd);
//     return 0;
// }