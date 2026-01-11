using System;
using System.Collections.Generic;
using System.Linq;

// ==================================
// === CHANGE HERE
// ==================================

/*
    Sorting first, so that pairing will be calculate on d = [[i] - [i + 1]]
    If d <= D, 1 pair
    if d > D, move a pointer to the new pair  d = [[i + 1] - [i + 2]], continue
*/
void PairSticks(int[] arr, int diff)
{
    if (arr == null || arr.Length <= 1) return;
    if (diff <= 0) return;

    int N = arr.Length;
    int count = 0;
    Array.Sort(arr, (a, b) => a - b);

    int i = 1;
    while (i < N)
    {
        int d = Math.Abs(arr[i] - arr[i - 1]);
        if (d <= diff)
        {
            count++;
            i += 2; // skit the first pair
        }
        else
        {
            i += 1; // skip the left element
        }
    }

    Console.WriteLine(count);
}

// ==================================
// === MAIN EXECUTION
// ==================================

/*
    Input / Output
*/
if (!int.TryParse(Console.ReadLine(), out int no)) return;
string input = Console.ReadLine() ?? " ";
int[] nums = input.Split(" ", StringSplitOptions.RemoveEmptyEntries)
                  .Select(e => int.TryParse(e, out int num) ? num : 0)
                  .ToArray();

DurationTesting(() => PairSticks(nums, no));
Output(nums);

// ==================================
// === Utilities
// ==================================

/*
    Swapping elements
*/
void Swap<T>(ref T a, ref T b)
{
    T temp = a;
    a = b;
    b = temp;
}

/*
    Output Arrays
*/
void Output<T>(T[] arr)
{
    foreach (T el in arr)
    {
        Console.Write($"{el} ");
    }
    Console.WriteLine();
}

/*
    Testing duration time to run the algorithm in milliseconds
*/
void DurationTesting(Action action)
{
    var startTime = DateTime.Now;

    action();

    var endTime = DateTime.Now;
    var duration = endTime - startTime;
    Console.WriteLine($"Duration: {duration.TotalMilliseconds} ms");
}