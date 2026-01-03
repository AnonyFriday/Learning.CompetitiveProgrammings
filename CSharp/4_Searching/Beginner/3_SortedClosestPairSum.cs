using System;
using System.Collections.Generic;
using System.Linq;

// ==================================
// === CHANGE HERE
// ==================================

(int, int) SortedClosestPairSum(int[] arr, int val)
{
    if (arr == null || arr.Length == 0) return (int.MinValue, int.MinValue);

    (int lVal, int rVal) pair = (int.MinValue, int.MinValue);

    int left = 0;
    int right = arr.Length - 1;
    int minDiff = int.MaxValue;

    // No <= due to left != right in the pair
    while (left < right)
    {
        int currSum = arr[left] + arr[right];

        // If the difference is smallest, take that pair
        int diff = Math.Abs(currSum - val);
        if (minDiff > diff)
        {
            minDiff = diff;
            pair.lVal = arr[left];
            pair.rVal = arr[right];
        }

        if (currSum > val)
        {
            right = right - 1;
        }
        else
        {
            left = left + 1;
        }
    }

    return pair;
}

// ==================================
// === MAIN EXECUTION
// ==================================

if (!int.TryParse(Console.ReadLine(), out int no)) return;
string input = Console.ReadLine() ?? " ";
int[] nums = input.Split(" ", StringSplitOptions.RemoveEmptyEntries)
                  .Select(e => int.TryParse(e, out int num) ? num : 0)
                  .ToArray();

// Add your execution call here, e.g., Console.WriteLine(YourFunction(nums, no));
var pair = SortedClosestPairSum(nums, no);

Console.WriteLine(pair.Item1 + " and " + pair.Item2);