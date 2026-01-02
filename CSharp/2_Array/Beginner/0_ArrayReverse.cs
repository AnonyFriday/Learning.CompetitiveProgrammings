using System;
using System.Collections.Generic;
using System.Linq;

// ==================================
// === CHANGE HERE
// ==================================

void ReverseArray<T>(T[] arr)
{
    if (arr == null || arr.Length == 0) return;

    int l = 0;
    int r = arr.Length - 1;
    while (l < r)
    {
        T temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;

        l++;
        r--;
    }
}

// ==================================
// === MAIN EXECUTION
// ==================================

string input = Console.ReadLine() ?? " ";
int[] nums = input.Split(" ", StringSplitOptions.RemoveEmptyEntries)
                  .Select(e => int.TryParse(e, out int num) ? num : 0)
                  .ToArray();

ReverseArray(nums);

foreach (var el in nums)
{
    Console.Write($"{el} ");
}

// Add your execution call here, e.g., Console.WriteLine(YourFunction(nums, no));