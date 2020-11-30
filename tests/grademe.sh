./testcase.sh > answer.txt
../minishell < testcase.sh | sed 's/\[32mshell$> \[0m//g' | sed -e "/exit/d" > result.txt
diff answer.txt result.txt
