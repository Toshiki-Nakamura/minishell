echo '----- make test exe -----'
cd ..
touch srcs/prompt.c
make test
cd tests
rm -f *.test
echo '----- execute bash std test -----'
bash testcase.sh > answer.txt 2> std.test
sed -e "s/testcase.sh: //g" std.test | cut -d : -f 2- > answer_error.txt
rm -f *.test
echo '----- execute minishell std test -----'
../minishell < testcase.sh 2> std.test | sed 's/\[32mshell$> \[0m//g' | sed -e "/exit/d" > result_tmp.txt
tail -n 20 result_tmp.txt > result_leaks.txt
tail -r result_tmp.txt | sed '1,20d' | tail -r > result.txt
cut -d : -f 2- std.test | sed -e "/exit/d" > result_error.txt
echo '----- execute minishell error test -----'
../minishell < testcase_minishell_error.sh >dummy.test 2> result_ms_error.txt
rm -f *.test
../minishell < syntax_error.sh 2> res.test | sed 's/\[32mshell$> \[0m//g' |sed -e "/exit/d"  >/dev/null
cut -d : -f 2- res.test > result_syntax_error.txt
rm -f *.test

ESC=$(printf '\033')
echo =================================
echo ====== Standard Output Test =====
echo =================================
diff answer.txt result.txt
if [ $? = 0 ]; then echo "$ESC[32m SUCCESS $ESC[0m"
else echo "$ESC[31m FAILED $ESC[0m"
fi

echo =======================================
echo ====== Standard ERROR Output Test =====
echo =======================================
diff answer_error.txt result_error.txt
if [ $? = 0 ]; then echo "$ESC[32m SUCCESS $ESC[0m"
else echo "$ESC[31m FAILED $ESC[0m"
fi

echo ========================================
echo ====== Minishell ERROR Output Test =====
echo ========================================
diff answer_ms_error.txt result_ms_error.txt
if [ $? = 0 ]; then echo "$ESC[32m SUCCESS $ESC[0m"
else echo "$ESC[31m FAILED $ESC[0m"
fi

echo =============================
echo ====== Memory Leak Test =====
echo =============================
tail -n +16 result_leaks.txt
