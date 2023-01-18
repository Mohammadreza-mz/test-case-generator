# test-case-generator
## generate input
use test-gen.cpp to create test-case inputs.
## validator
a validator.cpp checks if the inputs of the problem are valid. you should write this file based on your problem. if inputs were valid you should print 0 to stdout, otherwise print 1.
## generate output
write your solution in solution.cpp. you may assume that input to your code is given via stdin. also, print the desired output to stdout.
## how to use
compile and run test-gen.cpp to create test-case inputs.
then use the output-gen.sh to run the validator and generate output for test-case.

```bash
g++ -std=c++11 test-gen.cpp -o test-gen.exe
./test-gen.exe
bash output-gen.sh
```
