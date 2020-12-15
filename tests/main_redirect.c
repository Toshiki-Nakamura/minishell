#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> // O_RDONLY, O_WRONLY, O_CREAT

int main(int argc, char *argv[])
{
    int in_fd,out_fd;

#if 1
    if ( argc != 3 ) {
        printf("Usage: %s input-file output-file\n", argv[0]);
        return 0;
    }

    // 入力用ファイル記述子
    if ( (in_fd = open(argv[1],O_RDONLY)) < 0 ) {
        perror("open");
        close(in_fd);
        return 0;
    }
    // 出力用ファイル記述子
    if ( (out_fd = open(argv[2],O_WRONLY|O_CREAT,0666)) < 0 ) {
        perror("open");
        close(out_fd);
        return 0;
    }

    // 入力をファイルへ
    close(0);
    dup2(in_fd,0);
    close(in_fd);

    // 出力をファイルへ
    close(1);
    dup2(out_fd,1);
    close(out_fd);
#else
    // 出力用ファイル記述子
    if ( (out_fd = open(argv[1],O_WRONLY|O_CREAT,0666)) < 0 ) {
        perror("open");
        close(out_fd);
        return 0;
    }
     // 出力をファイルへ
    close(1);
    dup2(out_fd,1);
    close(out_fd);

    set_redirect_input("./test.txt");
#endif
    execlp("wc", "wc", NULL);

    return 0;
}
