
#When should we think about DP
    1.  Mostly problem will of optimisation or reducible to optimisation
    2.  Overlapping subproblem

#Greedy vs Divide and Conquer vs DP

    Greedy
        1.  Greedy algorithms are which find optimal solution at every stage and hope for finding global optimum at the end.
        2.  It never reconsider its chocies.  

    Divide and Conquer
        1.  Subproblems are independent
        2.  Not optimisation

    DP
        1.  DP made decision based on all its previous decisoin
        2.  Overlapping subproblems

#When to use Memoization and when to use Tabulation

    Memoization Top-Down
        1.  Recursion with memoization is better whenever the state is sparse space (number of different subproblems are less).
        2.  If we, don't actually need to solve all smaller subproblems but only some of them.
        3.  Whenever the state space is irregular.

    Tabulation Bottom-Up
        1.  Whenever the state space is dense and irregular.
        2.  No additional functional overhead
        3.  We can save space in some problems

