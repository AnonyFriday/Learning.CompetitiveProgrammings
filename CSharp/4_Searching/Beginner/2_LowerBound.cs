using System;
using System.Collections.Generic;
using System.Linq;

// ==================================
// === CHANGE HERE
// ==================================

int LowerBound(int[] arr, int val)
{
    if (arr == null || arr.Length == 0) return val;

    int left = 0;
    int right = arr.Length - 1;
    int answer = val;

    // Check the largest number under val in the array
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= val)
        {
            answer = arr[mid];
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return answer;
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
Console.WriteLine(LowerBound(nums, no));