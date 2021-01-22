echo '======================================'
echo '========== [BLACK BOX TEST] =========='
echo '======================================'
echo '----- test: Search and launch the right executable -----'
ls
ls -lt ..
ls fuga
echo '----- test: echo with option -n -----'
echo hoge
echo -n hoge
echo -x hoge
echo
echo '----- test: cd with only a relative or absolute path -----'
cd ..
pwd
cd $OLDPWD
pwd
cd hoge
echo '----- test: pwd without any options -----'
pwd
cd tests
pwd
pwd adlskfajsdlfajdfajlsdkfjasdlkfjasdlkfjalskdagkjsdfhkgjhsdfkjhdfkjahf
echo '----- test: export without any options -----'
echo '----- test: export 1 -----'
export TEST_EXPORT=hoge
echo $TEST_EXPORT
echo '----- test: export 2 -----'
export NO_VALUE=
echo $NO_VALUE
echo '----- test: export 3 -----'
export KEY
export | grep KEY
echo '----- test: export 4 -----'
export | sed /SHLVL/d
echo '----- test: unset without any options -----'
echo '----- test: unset 1 -----'
echo $TEST_EXPORT
unset TEST_EXPORT
echo $TEST_EXPORT
echo '----- test: unset 2 -----'
unset 0A
unset VAR?A
unset VAR=A
echo '----- test: env without any options and any arguments -----'
echo 'NOTE: 単体での env は表示順に差分が出るため実行していない'
echo '----- test: env & export & unset 1 -----'
env | grep KEY
export | grep KEY
echo '----- test: env & export & unset 2 -----'
export KEY=value
env | grep KEY
export | grep KEY
export KEY
env | grep KEY
export | grep KEY
echo '----- test: env & export & unset 3 -----'
unset KEY
env | grep KEY
export | grep KEY
echo '----- test: ; in the command should separate commands -----'
pwd; echo hoge; pwd
echo '----- test: ’ and " should work like in bash except for multiline commands -----'
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
echo '----- test: Redirections < > “>>” should work like in bash except for file descriptor aggregation -----'
echo '----- test: redirect output case -----'
rm -f a.test b.test c.test d.test
echo hoge>a.test
echo fuga>       b.test
echo foo      >c.test
echo bar   >    d.test
cat a.test b.test c.test d.test
echo hoge>>a.test
echo fuga>>      b.test
echo foo     >>c.test
echo bar   >>   d.test
cat a.test b.test c.test
echo '----- test: redirect input case -----'
cat <a.test
cat <        b.test
echo '----- test: multiple redirect case -----'
echo xxx>a.test<b.test>>c.test
cat a.test c.test
echo xxx >a.test<  b.test   >>   c.test
cat a.test c.test
echo '----- test: redirect unnormal filename case -----'
echo hoge>=d.test
cat =d.test
echo '----- test: redirect invalid filename case -----'
echo hoge > ..
echo 'redirect out to dir is' $?
echo hoge > fuga/fuga
echo 'redirect out to unexist name is' $?
cat < ..
echo 'redirect in from dir is' $?
cat < fuga/fuga
echo 'redirect in from unexist name is' $?
echo '----- test: Pipes | should work -----'
echo '----- test: pipe 1 -----'
ls | cat -e | cat -e | grep test
ls ../ | cat -e | cat -n | grep dia | awk '{print $2}'
echo '----- test: pipe 2 -----'
pwd | cat -e
echo '----- test: pipe 3 -----'
cd .. | ls
pwd
echo '----- test: pipe4 -----'
exit | echo hoge | ls
echo '----- test: Environment variables ($ followed by characters) should work -----'
echo $HOME
echo $USER
echo $TESTTESTTEST
echo '----- test: $? should work -----'
ls hoge
echo $?
echo $?
echo | cd hoge
echo $?
echo | cd
echo $?
CD hoge
echo $?
hoge
echo $?
ls | cat -e
echo $?
echo ''
echo ''
cat ..
echo $?
echo '======================================'
echo '========== [WHITE BOX TEST] =========='
echo '======================================'
echo '----- test: empty new line -----'



echo '----- test: utils_split and quote -----'
echo "lkanvl; ; ';s  ; kl ;ls| lsvk   " | cat -e
echo "  kasvjnsl " "|'a'a lacnln      ;lmav""aa "
echo" "'kkk'
echo 	hoge	 	 fuga
echo "	hoge	 	 fuga"
echo '----- test: tilde replace -----'
echo ~
echo ~$USER
echo foo > ~/home.test
cat < ~/home.test
echo xxx > ~home.test
echo yyy >>~/home.test
cat <~/home.test
rm -f ~home.test ~/home.test
echo '----- test: remove quotation -----'
echo hoge > "hoge.test"
ls hoge.test
echo '----- test: pipe and redirect case-----'
cat<../Makefile|grep minishell
cat < ../Makefile | grep minishell > b
cat b
cat < hello.c | cat -e > a ; cat < a | grep hello >> b
cat a b
ls | cat -e >> a | cat -n
rm a b
echo '----- test: pipe and redirect case 2-----'
echo hoge | >> a
rm a
echo '----- test: crazy case 1-----'
CD ..
PWd
cd tests
ECho minihsell
echo '----- test: crazy case 2-----'
UnsEt
EXPORT
EXit
echo '----- test: error case -----'
$HOME
echo $?
/bin/hoge
echo $?
hoge
echo $?
../a.out
echo $?
echo '----- test: <gcc a.out cat -e> -----'
gcc hello.c
./a.out | cat -e
rm ./a.out
echo '----- test: reset PATH -----'
unset "PATH"
PWD
pwd
Env
env
CD ..
ECHO "abc"
echo "abc "
cat hello.c
export "PATH=/usr/bin"
gcc -o 'testsA/tests' testsA/main.c
gcc -o 'testsB/tests' testsB/main.c
export "PATH=$PWD/testsA:$PWD/testsB:/bin"
tests
export "PATH=$PWD/testsB:$PWD/testsA:/bin"
tests
rm testsA/tests
rm testsB/tests
export "PATH=/usr/local/bin:/usr/bin:/bin"
env | grep "_="
export "PATH=:/usr/bin////:/bin"
env | grep "_="
export PATH="/usr/bin/:/bin"
env | grep "_="
echo '----- test: EXIT without any options -----'
exit