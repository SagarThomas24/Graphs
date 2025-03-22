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


## Modifications on the Input File  

1. **Removed Comments**  
   - The dataset initially contained comments, which were removed to ensure clean parsing.  

2. **Standardized Format**  
   - The first line of the file represents the number of vertices (`n`).  
   - The second line represents the number of edges (`m`).  
   - Each subsequent line contains two integers representing an edge between two vertices.  

3. **Ensured Proper Parsing**  
   - The program reads `n` and `m` first and then correctly processes the `m` edges.  

4. **User-Defined Input File**  
   - The filename is provided by the user instead of being hardcoded.  

These modifications make the input processing more structured and flexible.


##Contributions

Name                                   ID                            Contributions
Karingattil Sagar Thomas           2022A7PS0156H                  Read the Tomita.cliques paper and implemented the algorithm and helped in writing the report as well as helped in writing code for arboricity
                                                                  



## Notes
- `-O3` enables compiler optimizations for better performance.
- Ensure your input files (if any) are in the correct format before running.

For any issues, check error messages and ensure dependencies are installed.
