echo 'make test exe'
cd ..
touch srcs/prompt.c
make test
cd tests
rm -f *.test
bash testcase.sh > answer.txt 2> a.txt
sed -e "s/testcase.sh: //g" a.txt | cut -d : -f 2- > answer_error.txt && rm a.txt
rm -f *.test
../minishell < testcase.sh 2> b.txt | sed 's/\[32mshell$> \[0m//g' | sed -e "/exit/d" > result.txt
cut -d : -f 2- b.txt > result_error.txt && rm b.txt

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