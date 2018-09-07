cd QuickSort

# QuickSort with first element as pivot
echo "Running quicksort with pivot as first element"
rm -f readme.txt
echo -n "\nWhen the first element is considered as the pivot\n" >> "readme.txt"
gcc quicksort_first.c
for file in in_*
do
  ./a.out $file ${file[@]/in/out} # Run for all 12 input files

done

# QuickSort with a random element as pivot
echo "Running quicksort with pivot as a random element"
rm -f readme.txt
echo "\nWhen a random element is considered as the pivot\n" >> "readme.txt"
gcc quicksort_random.c
for file in in_*
do
  ./a.out $file ${file[@]/in/out}

done

# Counting sort
cd ../CountingSort
rm -f readme.txt
echo "Applying Counting Sort"
gcc countingSort.c
for file in in_*
do
  ./a.out $file ${file[@]/in/out} # Run for all 4 input files

done
# Return to the original directory
cd ..
