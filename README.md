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
1. **Initialization**:
   - Initialize a 5-dimensional dynamic programming (DP) table `dp` with dimensions:
     - `k + 1` (for enemy positions `ind` from 0 to `k`),
     - `initialPower + 1` (to track the remaining power at each step),
     - `skip + 1` (to track the remaining skips),
     - `recharge + 1` (to track the remaining recharges),
     - `2` (to track whether the previous enemy was skipped or not).
   - Each DP cell is initialized to `-1` (indicating uncalculated state).

2. **Base Cases**:
   - If Abhimanyu has reached the end (`ind >= k`), return `true` as he has successfully crossed the chakravyuha.
   - If Abhimanyu's power drops below zero at any point, return `false` as he cannot fight anymore.
   - If the current enemy's power exceeds Abhimanyu's remaining power, and he has no skips or recharges left, return `false`.
   - If Abhimanyu is at circle 3 or 7, and his power is less than the sum of the current enemy's power and half of the previous enemy's power, and he cannot skip or recharge, return `false`.

3. **Recursive Case**:
   - **Use skip**: If skips are available (`skip > 0`), call the recursive function with the next enemy (`ind + 1`), the same power, one less skip (`skip - 1`), and mark the current enemy as skipped (`lastSkipped = 1`).
   - **Use recharge**: If recharges are available (`recharge > 0`), recharge Abhimanyu back to his initial power (`power`) and call the function again with the same enemy (`ind`), recharged power, one less recharge (`recharge - 1`).
   - **Fight enemy**: If Abhimanyu's current power is greater than the enemy's power:
     - If the current enemy is at positions 3 or 7, subtract the sum of the current enemy's power and half of the previous enemy's power, and call the function with the next enemy (`ind + 1`).
     - For other positions, simply subtract the current enemy's power and call the function with the next enemy (`ind + 1`).

4. **Store the Result in DP**:
   - Store the result of the recursive computation in the DP table `dp[ind][initalPower][skip][recharge][lastSkipped]`.

5. **Final Answer**:
   - If the recursive function returns `true`, print "Abhimanyu can cross the chakravyuha"; otherwise, print "Abhimanyu cannot cross the chakravyuha".

---

### Time Complexity

The time complexity of this algorithm is approximately `O(k*initialPower*skip*recharge)`, where `k` is the number of circles, `initialPower` is Abhimanyu’s initial power, `skip` is the number of skips, and `recharge` is the number of recharges.

### Space Complexity

The space complexity is `O(k*initialPower*skip*recharge)` due to the use of the 5D DP table

