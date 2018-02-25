// header

#include "ft_ls.h"

int ft_check_for_perm(char *file)
{
	struct stat st;
	lstat(file, &st);
	if (!(st.st_mode & S_IXUSR) && !(st.st_mode & S_IXGRP) && !(st.st_mode & S_IXOTH) &&
	    (!(st.st_mode & S_IWUSR) && !(st.st_mode & S_IWGRP) && !(st.st_mode & S_IWOTH)) &&
	    (!(st.st_mode & S_IRUSR) && !(st.st_mode & S_IRGRP) && !(st.st_mode & S_IROTH)))
		return (1);
	return (0);
}

void ft_print_no_perm(int len, char **arg_files, int i)
{
	if (len > 1)
	{
		write(2, arg_files[i], ft_strlen(arg_files[i]));
		write(2, ":\n", 2);
	}
	write(2, "ls: ", 4);
	write(2, arg_files[i], ft_strlen(arg_files[i]));
	write(2, ": Permission denied", 19);
	if (arg_files[i+1])
		write(2, "\n\n", 2);
	else
		write(2, "\n", 1);
}
