# Maximal Clique Algorithm - Instructions

## Prerequisites
Ensure you have the following installed:

- A C++ compiler (**g++** recommended)
- A terminal or command prompt

## Steps to Run the Program

### 1. Extract the Files
Unzip the provided zip file and open the extracted folder in **VS Code** or your preferred editor.

### 2. Compile the Program
Open a terminal in the extracted folder and run the following command to compile the C++ files with optimization:

For The Research Paper:  The worst-case time complexity for generating all maximal cliques and computational experiments.
```bash
 g++ -O3 -o maximal_clique tomiata.cpp
```

For The Research Paper :  Listing All Maximal Cliques in Sparse Graphs in Near-Optimal TIme
```bash
 g++ -O3 -o maximal_clique Bkl.cpp
```
For The Research Paper :Arboricity and Subgraph Listing Algorithms
```bash
 g++ -O3 -o maximal_clique Arboricity.cpp
```





### 3. Run the Program
Once compiled, execute the program using:

```bash
./maximal_clique
```
on running the program the code will ask to specify which dataset 

For Wiki-Vote.txt
``` bash
Wiki-Vote.txt
```
For Enron-Email.txt
```bash
Enron-Email.txt
```
For Skitter.txt
``` bash
Skitter.txt
```

If additional arguments are needed, provide them after the command, e.g.,

```bash
./maximal_clique input.txt
```


## Notes
- `-O3` enables compiler optimizations for better performance.
- Ensure your input files (if any) are in the correct format before running.

For any issues, check error messages and ensure dependencies are installed.
