#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int		fd;
	int		ret;
	char	*line;

/* Prepare a "test.txt" file with any content */
	fd = open("test.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		printf("return (%d): line: %s\n", ret, line);
		free(line);
	}
	printf("return (%d): line: %s\n", ret, line);
	printf("FILE END\n");
	close(fd);
	free(line);
	system("leaks a.out");
	return (0);
}
