# Maximal Clique Enumeration Algorithm
##Tomita.cliques
https://snap.stanford.edu/class/cs224w-readings/tomita06cliques.pdf
## Introduction
The paper addresses the problem of generating all maximal cliques in an undirected graph. A clique is a fully connected subgraph, and a maximal clique is a clique that cannot be extended by adding more vertices. Finding all maximal cliques has applications in clustering, bioinformatics, and combinatorial optimization.

The authors present a depth-first search (DFS) algorithm for maximal clique enumeration, which improves on the Bron–Kerbosch algorithm. The key contributions are:

Theoretical proof that the worst-case time complexity is O(3ⁿ/³).
Computational experiments that demonstrate the algorithm’s efficiency compared to existing methods.

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
