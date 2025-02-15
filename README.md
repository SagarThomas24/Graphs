# Maximal Clique Enumeration Algorithm

## Overview
This repository implements a **Depth-First Search (DFS)-based algorithm** for generating all **maximal cliques** in an undirected graph. The algorithm optimizes space using **tree-structured output** and improves efficiency with **pruning methods** inspired by Bron-Kerbosch.

## Key Features
- **Efficient DFS-Based Approach**: Uses depth-first search with pruning.
- **Optimal Complexity**: Achieves worst-case **O(3ⁿ/³)** complexity.
- **Tree-Structured Output**: Saves memory space.
- **Comparison with Existing Algorithms**:
  - Bron-Kerbosch Algorithm (Backtracking)
  - Tsukiyama et al. (O(α(G)m)-time)
  - Tarjan & Trojanowski (O(2ⁿ/³) for max independent set)
  - Robson's Algorithm (O(2⁰·²⁷⁶ⁿ))
