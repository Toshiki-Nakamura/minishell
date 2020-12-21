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
echo '----- test: export 2 -----'
export NO_VALUE=
echo $NO_VALUE_
echo '----- test: export 3 -----'
export KEY
export | sed /SHLVL/d
echo '----- test: export 4 -----'
env | grep KEY
export | grep KEY
echo '----- test: export 4 -----'
export KEY=value
env | grep KEY
export | grep KEY
export KEY
env | grep KEY
export | grep KEY
echo '----- test: export 5 -----'
unset KEY
env | grep KEY
export | grep KEY
echo '----- test: unset 1 -----'
unset TEST_EXPORT
echo $TEST_EXPORT
echo '----- test: execve 1 -----'
ls
ls -lt
echo '----- test: pipe 1 -----'
ls | cat -e | grep test
echo '----- test: pipe 2 -----'
pwd | cat -e
echo '----- test: pipe 3 -----'
cd .. | ls
pwd
echo '----- test: pipe4 -----'
exit | echo hoge | ls
echo '----- test: quote 1 -----'
echo "ddd' ss 'DD"
echo "aaa"'bb"c'" 'aaa'"
echo 'aaa"CCC"'"eee"'ggggg'''
echo 'bb"cccddd"ee"ff''ii"jj"k'
echo "''''"'"""'
echo "hoge   'fuga'   DD"
echo '----- test: quote 2 -----'
echo "'$HOME' $HOME"
echo '----- test: quote 3 -----'
echo '"$HOME" '$HOME''
echo '----- test: quote 4 -----'
echo '"$HOME"' '''$HOME'''
echo '----- test: quote 5 -----'
echo '"$HOME ''$HOME''"'
echo '----- test: quote 6 -----'
echo "'$HOME ""$HOME""'"
echo '----- test: quote 7 -----'
echo '"''$HOME'' "'
echo '----- test: quote 8 -----'
echo '"$HOME ''$HOME''"'
echo '----- test: $? status -----'
ls hoge
echo $?
echo $?
echo | cd hoge
echo $?
echo | cd
echo $?
hoge


echo $?
ls | cat -e
echo $?
echo '----- test: crazy case 1-----'
CD ..
PWd
cd tests
ECho minihsell
echo '----- test: crazy case 2-----'
UnsEt
EXPORT
EXit
echo '----- test: gcc <a.out cat -e> -----'
gcc hello.c
./a.out | cat -e
rm ./a.out
echo '========== test finished =============================='
exit