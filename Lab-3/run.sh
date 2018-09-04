
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
