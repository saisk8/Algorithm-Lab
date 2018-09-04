# Generate input files
gcc adjancencyList_generator.c - o list_input_generator.o
./list_input_generator
gcc adjancencyMatrix_generator.c -o matrix_input_generator.o
./matrix_input_generator

# Run Dijkstra's algorithm
gcc dijkstra-adjacencyList.c -o dij_list.o
./dij_list.o

gcc dijkstra-adjacencyMatrix.c -o dij_matrix.c
./dij_matrix
