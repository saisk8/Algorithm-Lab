
# Clean directory
echo "Cleaning directory..."
rm -f *.o *.txt

# Generate input files
echo "Generating inputs"
gcc adjacencyList-generator.c -o list.o
./list.o

gcc adjacencyMatrix-generator.c -o matrix.o
./matrix.o
echo "Inputs generated"

# Run Dijkstra's algorithm
echo "Running Dijkstra with Adjacency List..."
gcc dijkstra-adjacencyList.c -o dij_list.o
./dij_list.o

echo "Running Dijkstra with Adjacency Matrix..."
gcc dijkstra-adjacencyMatrix.c -o dij_matrix.o
./dij_matrix.o

echo "Done. The results are populated in respective output files and the analysis is shown in readme.txt\nThank you"
echo "It therefore, can be concluded that the Dijkstra program using the Adjacency List and \nMin-Heap, run faster on average than the one using the Adjacency Matrix and Min-Heap.\n\n" >> readme.txt
echo "\nNote: Kindly note that an input size of 10,000 could not be given to the Adjacency Matrix probelm due to" >> readme.txt
echo "the stack overflow problem that may occur in many systems...\n The size of the matrix is too large to be allocated on the stack memory" >> readme.txt

