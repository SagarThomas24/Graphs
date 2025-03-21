# Maximal Clique Enumeration Algorithm
# Tomita.cliques
## Research Paper Link
https://snap.stanford.edu/class/cs224w-readings/tomita06cliques.pdf
## **Introduction**  

The paper addresses the problem of **generating all maximal cliques** in an **undirected graph**. A **clique** is a **fully connected subgraph**, meaning every pair of vertices within it is adjacent. A **maximal clique** is a clique that **cannot be extended** by adding more vertices. Finding all maximal cliques has important applications in **clustering, bioinformatics, social network analysis, and combinatorial optimization**.  

The authors present a **depth-first search (DFS) algorithm** for **maximal clique enumeration**, which improves upon the **Bron–Kerbosch algorithm**. The problem of finding maximal cliques is a **fundamental challenge in graph theory**, with numerous real-world applications. Since a **clique** is a subset of vertices where **every pair of nodes is connected**, identifying all **maximal cliques** helps in understanding complex network structures and relationships.  

One of the major challenges in maximal clique enumeration is that the number of such cliques can grow **exponentially** with the number of vertices. The **worst-case number** of maximal cliques in a graph with **n vertices** is **O(3ⁿ/³)**, as established by **Moon and Moser (1965)**. This makes the problem **computationally expensive**, requiring efficient algorithms to handle large graphs effectively.  

To address this challenge, the authors propose an algorithm that **optimizes recursive expansion and pivot selection** to improve efficiency. Their approach achieves **optimal worst-case complexity** while reducing unnecessary recursive calls, making it significantly faster than previous methods.  



## **Difference Between the Proposed Algorithm and the Bron–Kerbosch Algorithm**  

The authors build upon the **Bron–Kerbosch algorithm (1973)** but introduce two key optimizations that significantly improve efficiency:  

- **Avoiding Redundant Recursive Calls**  
- **Optimized Pivot Selection to Minimize Expansions**  

### **1. Avoiding Redundant Recursive Calls**  

#### **Bron–Kerbosch: Recursive Expansion for All Candidates**  
In the **Bron–Kerbosch algorithm**, the recursive function is called for **every candidate vertex** in the current clique expansion. This can lead to **unnecessary computations** because some recursive branches may generate the **same maximal cliques multiple times**.  

#### **Proposed Algorithm: Pruning with FINI and CAND**  
The proposed algorithm introduces two sets:  

- **FINI (Finished Set)**: Nodes already processed and shouldn’t be expanded again.  
- **CAND (Candidate Set)**: Nodes that are still valid for expansion.  

Instead of recursively processing **every node in CAND**, the algorithm **filters the expansion** to **only include essential nodes** by using an **optimized pivot selection strategy**.  

---

### **2. Optimized Pivot Selection: Maximizing `|CAND ∩ N(u)|`**  

#### **Bron–Kerbosch: Arbitrary Pivot Selection**  
The **Bron–Kerbosch algorithm** sometimes chooses a pivot **arbitrarily**, leading to **suboptimal branching**, meaning **more recursive calls than necessary**.  

#### **Proposed Algorithm: Choosing the Pivot for Maximum Reduction**  
The proposed algorithm **chooses the pivot `u` such that `|CAND ∩ N(u)|` is maximized**, where `N(u)` is the **neighborhood of `u`**.  

- This means that `u` has the **maximum number of neighbors inside CAND**, reducing the number of new search branches.  
- Instead of making `|CAND|` recursive calls, the algorithm **only makes `k = |CAND - N(u)|` recursive calls**, where `N(u)` is the set of nodes adjacent to `u`.  

---

### **Why This Works**  

- The **larger** `|CAND ∩ N(u)|`, the **smaller** `|CAND - N(u)|`, which **reduces the number of recursive calls**.  
- This ensures that **each maximal clique is generated without duplication** while **minimizing unnecessary computations**.  
- By making the **smallest possible number of recursive calls**, the **search tree shrinks**, significantly improving performance.  

---

### **Why These Optimizations Matter**  

 **Fewer Recursive Calls** → Less redundant computation, leading to an **optimal worst-case time of O(3ⁿ/³)**.  
 **Less Memory Usage** → Since fewer calls are made, it **reduces the space complexity**.  
 **Better Practical Performance** → The **experimental results show** that this algorithm **outperforms other methods**, especially in **dense graphs**.  


## **The Algorithm**  

The algorithm improves upon the **Bron–Kerbosch algorithm** by making two key optimizations:  

- **Avoiding redundant recursive calls**  
- **Using an optimized pivot selection strategy**  

---

### **Step-by-Step Explanation of the Psuedo-Code**  

#### **1. Start with an empty clique (`Q`)**  
- The algorithm begins with an **empty set** `Q` that will grow into a **maximal clique**.
  

 ![image](https://github.com/user-attachments/assets/406bf411-beb3-4e44-8c31-a112399f2500)


#### **2. Define two sets:**  
- **CAND (Candidate Set)** → Nodes that **can be added** to `Q` to expand the clique.
  ![image](https://github.com/user-attachments/assets/3730ac31-7c7c-498f-b84c-3554c70bb528)
 
- **FINI (Finished Set)** → Nodes that **have already been processed** and should not be considered again.

 ![image](https://github.com/user-attachments/assets/be82ef1d-1149-4e1f-9520-a6cd0dccc28b)


#### **3. Expand `Q` recursively**  
- The algorithm **picks a node** from `CAND` and **adds it to `Q`**.  
- It then finds the **subset of `CAND` that is still connected** to the new clique (so that the clique remains valid).  
- This process continues until **no more vertices can be added**, forming a **maximal clique**.  

#### **4. Prune unnecessary branches**  
- Instead of **blindly expanding** every node in `CAND`, the algorithm **chooses a special pivot node (`u`)** that helps **reduce the number of recursive calls**.  
- The pivot is chosen to **maximize the number of nodes in `CAND` that are also connected** to it.  
- This means **fewer calls** are needed because **most candidates are already considered through `u`**.  

#### **5. Backtrack and explore other possibilities**  
- Once a **maximal clique** is found, the algorithm **removes the last added node** and **backtracks** to explore other possible cliques.  
- This ensures that **all maximal cliques are found without duplication**.  

#### **6. Repeat until all possibilities are explored**  
- The process continues until **all nodes in the graph** have been considered and **no more new maximal cliques** can be generated.  



## Psuedocode
![image](https://github.com/user-attachments/assets/2e832a42-a935-4ea8-a195-3bcd02cf57dc)



## Example dataset 
  Using the data given in the paper as an example 

  Nodes : 9        
  
  Edges : 15



![image](https://github.com/user-attachments/assets/4b701f5a-bb1a-41fa-b141-d2e66186c5db)



## **OBSERVATIONS**
- ### Enron Email dataset
  - **Largest Clique Size** : 20
  - **Number of Cliques**   : 226859
  - **Execution time**      : 11135 ms

  ![image](https://github.com/user-attachments/assets/3a26a959-2f8d-49ee-b72d-2a3c4b18849b)



- ### Wiki-Vote Dataset
    - **Largest Clique Dataset** : 20
    - **Number of Cliques**      : 459002
    - **Execution time**         : 13135 ms
 
   ![image](https://github.com/user-attachments/assets/bfc17a09-2cd4-4ba4-b307-c66a258e5969)


- ### Skitter Dataset
    - **Largest Clique Dataset** : 67
    - **Number of Cliques**      : 37322355
    - **Execution time**         : 23352000 ms
      
     ![image](https://github.com/user-attachments/assets/9c674de8-f326-4569-a136-cdf852058edb)
     ![image](https://github.com/user-attachments/assets/b0278b3a-73f0-4b10-b765-1f292adf5683)





  



    



## Complexity

- **Worst-case time complexity**: O(3ⁿ/³) for a graph with *n* vertices.
- **Space complexity**:  
  Optimized using a **tree-based output format**, requiring significantly **less memory** than direct clique listing algorithms.
