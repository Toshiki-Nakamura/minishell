echo '========== test start =============================='
echo '----- test: empty new line -----'

echo '----- test: pwd 1 -----'
pwd
echo '----- test: cd 1 -----'
cd ..
pwd
echo '----- test: export 1 -----'
export TEST_EXPORT=hoge
echo $TEST_EXPORT
echo '----- test: unset 1 -----'
unset TEST_EXPORT
echo $TEST_EXPORT
echo '----- test: execve 1 -----'
ls
ls -lt
echo '----- test: pipe 1 -----'
ls | cat -e | grep test
echo '----- test: gcc <a.out cat -e> -----'
gcc hello.c
./a.out | cat -e
rm ./a.out
echo '========== test finished =============================='
exit