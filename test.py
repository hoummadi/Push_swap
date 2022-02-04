import random
arg = int(input())
stack_a = []
stack_a = random.sample(range(arg), arg)
print(' '.join([str(i) for i in stack_a]))
#ARG=$(python3 ./test.py); ./push_swap $ARG | ./checker $ARG 
#ARG=$(python3 ./test.py); echo $ARG; ./push_swap $ARG | wc -l; ./push_swap $ARG | ./checker $ARG
#ARG=$(python3 ./test.py); echo $ARG;time ./push_swap $ARG | ./checker $ARG
