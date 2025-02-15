# Maximal Clique Enumeration Algorithm

## Overview
This repository implements a **Depth-First Search (DFS)-based algorithm** for generating all **maximal cliques** of an undirected graph. The algorithm incorporates **pruning methods** similar to the **Bron-Kerbosch algorithm** and optimizes space by outputting the cliques in a **tree-like structure**.

## Key Features

- **Efficient DFS-Based Approach**:  
  Utilizes depth-first search with pruning to efficiently enumerate maximal cliques.

- **Optimal Worst-Case Complexity**:  
  The algorithm achieves the best-known bound of **O(3ⁿ/³)**, matching the worst-case bound proven by **Moon and Moser**.

- **Tree-Structured Output**:  
  Outputs maximal cliques in a tree-like format, reducing space requirements compared to straightforward enumeration methods.

- **Comparative Analysis**:  
  Benchmarked against well-known algorithms, including:
  - **Bron-Kerbosch Algorithm** (Recursive backtracking for clique enumeration)
  - **Tsukiyama et al. Algorithm** (O(α(G)m)-time algorithm based on arboricity)
  - **Tarjan & Trojanowski Algorithm** (O(2ⁿ/³) for finding one maximum independent set)
  - **Robson's Algorithm** (O(2⁰.²⁷⁶ⁿ) for the maximum independent set problem)

## Complexity

- **Worst-case time complexity**: O(3ⁿ/³) for a graph with *n* vertices.
- **Space complexity**:  
  Optimized using a **tree-based output format**, requiring significantly **less memory** than direct clique listing algorithms.
