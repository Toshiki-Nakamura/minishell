cp testcase_syntax_error.sh tmp.txt
 > answer_syntax.txt
FILE_LINE=`wc -l tmp.txt | awk '{print $1}'`
for i in `seq 1 $FILE_LINE`
do
bash < tmp.txt 2> a.txt
sed -e '2d' a.txt | awk -F'[:]' '{ print $3 }' >> answer_syntax.txt
sed -i -e "1d" tmp.txt
done
echo "exit" >> answer_syntax.txt
rm *txt-e
rm a.txt
rm tmp.txt
