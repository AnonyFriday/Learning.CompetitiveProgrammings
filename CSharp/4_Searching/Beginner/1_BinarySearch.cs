using System;
using System.Collections.Generic;
using System.Linq;

// ==================================
// === CHANGE HERE
// ==================================

int BinarySearch(IList<int> list, int target)
{
    if (list == null || list.Count == 0) return -1;
    if (list.Count == 1) return target == list[0] ? 0 : -1;

    int left = 0;
    int right = list.Count;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        int el = list[mid];

        if (el == target)
        {
            return mid;
        }
        else if (el > target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
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
Console.WriteLine(BinarySearch(nums, no));