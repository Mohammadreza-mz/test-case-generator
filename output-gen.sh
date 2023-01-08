#!/bin/bash
g++ -std=c++11 validator.cpp -o validator.exe
g++ -std=c++11 solution.cpp -o solution.exe

cd testcases/in
for file in *; do
	test_number="${file%.*}";
	test_number="${test_number#input}";
	validation=$(../../validator.exe <$file);
	if [ "$validation" != "0" ]; then
		echo "validation failed on test $test_number";
	fi

	output_file="../out/output${test_number}.txt";
	ans=$(../../solution.exe <$file);
	echo $ans > $output_file;
done