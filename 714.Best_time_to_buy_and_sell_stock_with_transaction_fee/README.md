# Solution:

Idea:
add `dp[i]` the maximum value of the amount if we have ever bought excise taxes on j day (j <=i) and added it on i day if
`dp[i] = max_amount(0 ... j) + prices[i] - prices[j] - fee`;

let's store the value of the expression `-prices[j] -fee + max_amount(0 ... j)` in the optimal_prev array.
let's store the maximum amount in the prev_max array
Then `optimal_prev[i]` is the max of `(-prices[j] + prev_max[j] - fee)` where j < i.

And finally `dp[i] = prices[i] + optimal_prev[i - 1]`

Optimization:

Note that to proceed to the next step i, we only need the previous values dp, prev_max and optimal_prev.
