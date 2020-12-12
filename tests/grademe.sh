bash testcase.sh > answer.txt 2> answer_error.txt
../minishell < testcase.sh 2> result_error.txt | sed 's/\[32mshell$> \[0m//g' | sed -e "/exit/d" > result.txt
echo =================================
echo ====== Standard Output Test =====
echo =================================
diff answer.txt result.txt
echo =======================================
echo ====== Standard ERROR Output Test =====
echo =======================================
diff answer_error.txt result_error.txt
