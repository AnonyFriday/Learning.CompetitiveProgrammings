using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;

// ==================================
// === CHANGE HERE
// ==================================

void RotateKArray(int[] arr, int k)
{
    if (arr == null || arr.Length == 0) return;

    int n = arr.Length;

    k %= n;
    if (k == 0) return;

    Array.Reverse<int>(arr, 0, n);
    Array.Reverse<int>(arr, 0, k);
    Array.Reverse<int>(arr, k, n - k); // number of items to flip
}

// ==================================
// === MAIN EXECUTION
// ==================================

if (!int.TryParse(Console.ReadLine(), out int no)) return;
string input = Console.ReadLine() ?? " ";
int[] nums = input.Split(" ", StringSplitOptions.RemoveEmptyEntries)
                  .Select(e => int.TryParse(e, out int num) ? num : 0)
                  .ToArray();

RotateKArray(nums, no);

// Add your execution call here, e.g., Console.WriteLine(YourFunction(nums, no));