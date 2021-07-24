ARG=`jot -r 100 0 2147483647 | tr "\n" " "`
#ARG=`jot -r 20 0 200 | tr "\n" " "`
echo $ARG
#echo -e "`./push_swap $ARG`"
#echo `./push_swap $ARG | wc -l`
#echo `./push_swap $ARG | ./checker_Mac $ARG`
echo `./push_swap $ARG | ./checker $ARG`
