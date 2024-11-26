Four Sum


Given an array A and a target value, find all unique quadruples such that their sum is equal to the target value.

Note: The resultant set must not contain any duplicate quadruplets.

Example
A: [-1 , -3 , -2, -2, 5, 1]
Target: 2
Quadruples: [
 [-1, -3, 5, 1],
 [-2, -2, 5, 1]
]
Testing
Input Format
The first line contains an integer ‘T’ denoting the number of test cases.

For each test case, the input has three lines:

An integer ‘n’ denoting the length of the array A.
n space-separated integers denoting the elements of the array A.
The target value.
Output Format
For each test case, the output has the following lines

An integer ‘m’ denoting the number of unique quadruples.
Next m lines each contain four space-separated integers denoting elements whose sum is ‘target’.
Sample Input
4
5
1 2 3 4 5
11
6
1 2 3 4 5 2
10
1
5
10
10
-2 -7 1 -4 4 -5 6 8 -1 -2
-3
Expected Output
1
1 2 3 5
2
1 2 2 5
1 2 3 4
0
6
-7 -5 1 8
-7 -2 -2 8
-7 -1 1 4
-5 -4 -2 8
-5 -2 -2 6
-4 -2 -1 4