# Notes
- Every face should have a left, right, down, and up variables that act as pointers to also affect other faces when one face is rotated. Still saving information as pointers
# For the future
So I want to have a very big cycling loop that will take a Rubiks cube and make a lot of valid movements. It will then take the sum of each position with the rubikchecker, and save that (maybe to a file).
It will then take simulate valid movements again but each time it will alter the Rubik's cube in an invalid way, and check those sums with valid ones.
Bottom line is, we want to compare if a sum number detail exists for both a valid and invalid cube. If so, we will prove that this method doesn't work.
