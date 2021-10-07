#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int	main(int argc, char **argv)
{
	DIR				*dir_ptr;
	struct dirent	*file;

	dir_ptr = opendir("..");
	file = NULL;
	if (!dir_ptr)
	{
		fprintf(stderr, "%s directory 정보를 읽을 수 없습니다.\n", "..");
		return (-1);
	}
	file = readdir(dir_ptr);
	while (file)
	{
		printf("%s\n", file->d_name);
		file = readdir(dir_ptr);
	}
	closedir(dir_ptr);
	return (0);
}
