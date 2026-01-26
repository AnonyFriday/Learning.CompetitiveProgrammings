using System;
using System.Collections.Generic;
using System.Linq;

// ==================================
// === CHANGE HERE
// ==================================

void subArrayI(int[] arr, int i, int j)
{
    if (arr == null || arr.Length == 0) return;

    int N = arr.Length;
    if (i < 0) return;

    int a = i;
    int b = j > N ? N : j;

    for (; a < b; a++)
    {
        Console.Write(arr[a] + " ");
    }
}

int largetSubArraySumI(int[] arr)
{
    if (arr == null || arr.Length == 0) return 0;

    int N = arr.Length;

    int largestSum = int.MinValue;

    // 1. Calcualte the prefix sum
    // - sum[i] = sum[i - 1] + a[i]
    // 1 2 3 4 5 | 7 8 | 9 10
    //         i      j
    // [7,8] = sum to j - sum to i;

    // If the prefix is 1-base
    // sum[i, j] = pre[j + 1] - pre[i - 1 + 1];
    // if the prefix is 0-base
    // sum[i, j] = pre[j] - pre[i - 1];

    int[] prefixSum = new int[N + 1];
    prefixSum[0] = 0;

    for (int i = 1; i <= N; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            int sumItoJ;
            sumItoJ = prefixSum[j + 1] - prefixSum[i - 1 + 1];
            largestSum = int.Max(largestSum, sumItoJ);
        }
    }

    return largestSum;
}

int largetSubArraySumKadane(int[] arr)
{
    if (arr == null || arr.Length == 0)
    {
        return 0;
    }

    // Follow the trick
    // - If positive + positive, compare with the largest
    // - if posisitve + negastive, ofc it wont be largest, so just ignore the negative

    int largestSum = int.MinValue;
    int largestNegative = int.MinValue;
    int currentSum = 0;

    foreach (var el in arr)
    {
        if (el < 0)
        {
            largestNegative = Math.Max(largestNegative, el);  // tracking the highest negative anyway, for the case of all negatives
        }

        currentSum += el;
        if (currentSum < 0)
        {
            currentSum = 0;  // throw my bag
            continue;
        }

        largestSum = Math.Max(largestSum, currentSum);
    }

    if (largestSum == int.MinValue)
    {
        return largestNegative;
    }

    return largestSum;
}

// ==================================
// === MAIN EXECUTION
// ==================================

if (!int.TryParse(Console.ReadLine(), out int no1)) return;
if (!int.TryParse(Console.ReadLine(), out int no2)) return;
string input = Console.ReadLine() ?? " ";
int[] nums = input.Split(" ", StringSplitOptions.RemoveEmptyEntries)
                  .Select(e => int.TryParse(e, out int num) ? num : 0)
                  .ToArray();

subArrayI(nums, no1, no2);
Console.WriteLine("\n" + largetSubArraySumI(nums));
Console.WriteLine("\n" + largetSubArraySumKadane(nums));

