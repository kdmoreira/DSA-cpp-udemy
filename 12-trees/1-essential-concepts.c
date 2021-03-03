#include <stdio.h>
#include <stdlib.h>

/* Trees Terminology: Root (topmost node); Parent; Child; Siblings; Descendants; Ancestors;
Degree of a Node (how many direct children it has, not descendants); Degree of a Tree (pre-decided
not possible to determine by looking, but we can determine the minimum, e.g. "at least 3");
Internal/External Nodes (Non-leaf Nodes/Leaf Nodes or Non-Terminal Nodes/Terminal Nodes):
External/Terminal/Leaf Nodes: degree 0, Internal/Non-leaf/Non-Terminal Nodes: degree other than 0;
Levels: counts nodes, starts from 1 (root), level 2 (root's children) and so on;
Height: counts edges, starts from 0 (root) and so on; Forest: collection of trees (remember that
a single node can also be considered a tree)

Binary Tree: nodes must have 0, 1 or 2 children.

Number of binary trees using N nodes:
1- Unlabelled nodes: Catalan formula: T(n)=(2n Cn)/n+1 i.e. T(5)=(2*5 C5)/5+1 -> T(5)=(10 C5)/6 ->
T(5)=((10*9*8*7*6)/5!)/6 -> T(5) = 42 (combination formula)
Other formula: T(n)=SUMMATION(upper limit: n, lower limit i=1) of T(i-1)*T(n-i), a recursive formula
Max. height: 2^(n-1)
2- Labelled nodes: T(n)=((2n Cn)/n+1)*n! -> Catalan formula for shapes * factorial for permutation/filling

Height vs Nodes: find height by n of nodes and vice-versa
1- Height is given:
Min. number of nodes: n = h + 1
Max. number of nodes: sum of the terms of a GP series: n = a+ar+ar^2+ar^3+...+ar^k
which is n = (a(r^(k+1)-1))/(r-1) or simply n = 2^(h+1)-1
2- Nodes are given:
Min. height: h = (log base2 (n+1)) - 1
Max. height: h = n - 1
In conclusion:
Height of binary tree: (log base2 (n+1)) - 1 <= h <= n - 1 that is: logarithmic to linear: O(log n) to O(n)
Number of nodes in a binary tree: h + 1 <= n <= 2^(h+1)-1 that is: linear to exponential: O(n) to O(2^n)

Internal Nodes vs External Nodes:
There's a relationship between nodes with degree 2 and degree 0, but not degree 1:
deg(0) = deg(2) + 1, this is always true for binary trees

Strict Binary Tree:
Definition: nodes can have either 0 or 2 children, not 1 children.
Height vs Nodes:
If height is given:
For the max. number of nodes is the same for a general binary tree formula: n = 2^(h+1) - 1
For the min. number of nodes we need a formula: n = 2h + 1
If nodes are given:
Max: h = (log base2 (n+1)) - 1
Min: h = (n - 1)/2
This means height is ranging from logarithmic to linear, similar to simple binary tree */

int main(void)
{

    return 0;
}