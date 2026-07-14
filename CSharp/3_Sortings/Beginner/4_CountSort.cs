using System;
using System.Collections.Generic;
using System.Linq;

// ==================================
// === CHANGE HERE
// ==================================

void CountSort(int[] arr)
{
    if (arr == null || arr.Length == 0) return;

    // largest
    int largest = arr.Max();

    // Dont do like this, only add Capacity, but the internal array is still 0
    int[] bucket = new int[largest + 1];

    for (int i = 0; i < arr.Length; i++)
    {
        var el = arr[i];
        bucket[el]++;
    }

    // Rearrange back from bucket
    int j = 0;
    for (int i = 0; i < bucket.Length; i++)
    {
        while (bucket[i] > 0)
        {
            arr[j] = i;
            j++;
            bucket[i]--;
        }
    }
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

DurationTesting(() => CountSort(nums));
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