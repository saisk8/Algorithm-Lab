cd QuickSort

# QuickSort with first element as pivot
echo "Running quicksort with pivot as first element"
echo "\nWhen the first element is considered as the pivot\n" >> "readme.txt"
gcc quickSort_first.c
for file in in_*
do
  ./a.out $file ${file[@]/in/out} # Run for all 12 input files

done

# QuickSort with a random element as pivot
echo "Running quicksort with pivot as a random element"
echo "\nWhen a random element is considered as the pivot\n" >> "readme.txt"
gcc quickSort_random.c
for file in in_*
do
  ./a.out $file ${file[@]/in/out}

done

# Counting sort
cd ../CountingSort
echo "Applying Counting Sort"
gcc countingSort.c
for file in in_*
do
  ./a.out $file ${file[@]/in/out} # Run for all 4 input files

done
# Return to the original directory
cd ..
