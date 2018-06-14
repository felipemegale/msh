#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc, char*argv[])
{
    mkdir(argv[1], 0);
}