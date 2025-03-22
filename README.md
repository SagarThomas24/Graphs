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

```bash
 g++ -O3 -o maximal_clique main.cpp
```



### 3. Run the Program
Once compiled, execute the program using:

```bash
./maximal_clique
```
on running the program the code will ask to specify which dataset 
``` bash
Wiki-Vote.txt
Enron-Email.txt
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
