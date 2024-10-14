# Prismforce_ASDE_Assessment

## Problem statement
Imagine Abhimanyu in Chakravyuha. There are 11 circles in the Chakravyuha surrounded by different enemies.
Abhimanyu is located in the innermost circle and has to cross all the 11 circles to reach Pandavas army back.

### Given:
-  Each circle is guarded by different enemy where enemy is equipped with `k1, k2……k11` powers
Abhmanyu start from the innermost circle with p power Abhimanyu has a boon to skip fighting enemy
`skip` times 
- Abhmanyu can recharge himself with power `recharge` times 
- Battling in each circle will result in loss of the same power from Abhimanyu as the enemy. 
- If Abhmanyu enter the circle with energy less than the respective enemy, he will lose the battle
-  `k3` and `k7` enemies are endured with power to regenerate themselves once with half of their initial
power and can attack Abhimanyu from behind if he is battling in iteratively next circle

### Result:
Determine whether Abhimanyu can cross the Chakravyuha or not.

## Input Format
- An array of 11 integers representing the power of enemies in each circle.
- The second line contains three integers:
  - `initialPower` — the initial power Abhimanyu starts with.
  - `skip` — the number of times Abhimanyu can skip fighting enemies.
  - `recharge` — the number of times Abhimanyu can recharge his power.

## Output Format
- Output `"Abhimanyu can cross the chakravyuha"` if Abhimanyu can cross all 11 circles successfully. 
- Output `"Abhimanyu cannot cross the chakravyuha"` if it is impossible for him to escape the Chakravyuha.

## Test Case 1

### Input  
10 12 15 20 18 25 14 17 19 21 30

100 2 1

### Output  
  `Abhimanyu can cross the chakravyuha`


## Test Case 2

### Input  
30 25 40 35 50 45 55 50 60 70 80

80 1 2

### Output
`Abhimanyu cannot cross the chakravyuha`  

Algorithm
---------

1.  Use `dynamic programming` to store intermediate results and avoid recomputation. The DP table dimensions track the current circle, remaining power, remaining skips, remaining recharges, and whether the last circle was skipped.
    
2.  At each circle:
    
    *   Abhimanyu can skip the battle if skips are available.
        
    *   Abhimanyu can recharge if his power is insufficient for the current battle and recharges are available.
        
    *   Abhimanyu can battle if his power is greater than the enemy's.
        
3.  Handle special cases for circles 3 and 7 where enemies regenerate with half their power and can attack from behind if Abhimanyu fights in the next circle.
    

### Time Complexity

The time complexity of this algorithm is approximately `O(k \* initialPower \* skip \* recharge)`, where `k` is the number of circles, `initialPower` is Abhimanyu’s initial power, `skip` is the number of skips, and `recharge` is the number of recharges.

### Space Complexity

The space complexity is `O(k \* p \* a \* b)` due to the use of the 5D DP table

