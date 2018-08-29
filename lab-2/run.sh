# QuickSort with first element as pivot
echo "Pivot as first"
echo "\nWhen the first element is considered as the pivot\n" >> "readme.txt"
gcc quickSort_first.c
./a.out in_ran100.txt out_ran100.txt
./a.out in_ran1000.txt out_ran1000.txt
./a.out in_ran10000.txt out_ran10000.txt
./a.out in_ran100000.txt out_ran100000.txt
./a.out in_asec100.txt out_asec100.txt
./a.out in_asec1000.txt out_asec1000.txt
./a.out in_asec10000.txt out_asec10000.txt
./a.out in_asec100000.txt out_asec100000.txt
./a.out in_desc100.txt out_desc100.txt
./a.out in_desc1000.txt out_desc1000.txt
./a.out in_desc10000.txt out_desc10000.txt
./a.out in_desc100000.txt out_desc100000.txt
# QuickSort with a random element as pivot
echo "Pivot as random"
echo "\nWhen a random element is considered as the pivot\n" >> "readme.txt"
gcc quickSort_random.c
./a.out in_ran100.txt out_ran100.txt
./a.out in_ran1000.txt out_ran1000.txt
./a.out in_ran10000.txt out_ran10000.txt
./a.out in_ran100000.txt out_ran100000.txt
./a.out in_asec100.txt out_asec100.txt
./a.out in_asec1000.txt out_asec1000.txt
./a.out in_asec10000.txt out_asec10000.txt
./a.out in_asec100000.txt out_asec100000.txt
./a.out in_desc100.txt out_desc100.txt
./a.out in_desc1000.txt out_desc1000.txt
./a.out in_desc10000.txt out_desc10000.txt
./a.out in_desc100000.txt out_desc100000.txt
# Generate input for counting sort
echo "Generating input files"
gcc gen_input_count.c
./a.out
# Counting sort
echo "Applying Counting Sort"
gcc countingSort.c
./a.out in_random50.txt out_random50.txt
./a.out in_random100.txt out_random100.txt
./a.out in_random500.txt out_random500.txt
./a.out in_random1000.txt out_random1000.txt
