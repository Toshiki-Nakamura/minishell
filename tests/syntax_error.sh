#"- pipe and semicolon -"
ls ;     |  ls | hoge
ls |  cat |
pwd |       |echo
| ls |cat -e  
; ls |cat -e  
|
;
;    |     |
|    ;      | 
hoge | ; | ; |
hoge ; | ; |
ls | cat -ne | ; echo
ls ;   ;  cat -e
#"- redirect -"
echo "hoge" >> > a.test
echo "hoge" > >> a.test
echo "hoge" > > >a.test
echo "hoge" >>> a.test
echo "hoge" >>>>> a.test
echo "hoge" << < hello.c
echo "hoge" < < hello.case
echo "hoge" << < hello.case
echo "hoge" ><> a.test
echo "hoge" ><><><>< ><>< > a.test

#"- all mix -"
>> >  a |   | hoge ;
ls |>>| cat 
ls |  <  | cat 
ls |  >  | cat 
echo | ls >> | cat -e
ls |>>|cat -e
ls|>a|hoge ; rm a
echo "--" | cat >>  ;pwd;echo "hoge"| cat -ne

#"- crazy case -"
ls >     
         >>     
ls >            | 
ls <;
exit