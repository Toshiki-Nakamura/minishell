./testcase.sh > answer.txt
../minishell < testcase.sh > result.txt
diff result.txt answer.txt
