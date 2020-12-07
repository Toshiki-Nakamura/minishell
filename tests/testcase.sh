echo '========== test start =============================='
echo '----- test: echo 1 -----'
echo '----- test: pwd 1 -----'
pwd
cd ..
pwd
echo '----- test: export 1 -----'
export TEST_EXPORT=hoge
echo $TEST_EXPORT
echo '----- test: unset 1 -----'
unset TEST_EXPORT
echo $TEST_EXPORT
echo '========== test finished =============================='
exit