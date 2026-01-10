using System;
using System.Collections.Generic;
using System.Linq;

// ==================================
// === CHANGE HERE
// ==================================

/*
    Iteration from 0 to N - 1 with p as a barrier for the sorted part.
    Iterate from i = p to N - 1 to find the smallest and largest depends on isAsc
    Swapping p with i
*/
void SelectionSort(int[] arr, bool isAsc = true)
{
    if (arr == null || arr.Length == 0) return;

    int N = arr.Length;
    int p = 0;
    while (p < N - 1)
    {
        int min = arr[p];
        int minPos = -1;

        for (int i = p + 1; i < N; i++)
        {
            if ((isAsc && (arr[i] < min))
                || (!isAsc && (arr[i] > min)))
            {
                min = arr[i];
                minPos = i;
            }
        }

        // sorted, then no swapping occurs
        if (minPos != -1)
        {
            Swap(ref arr[p], ref arr[minPos]);
        }
        p++;
    }
}


// ==================================
// === MAIN EXECUTION
// ==================================

/*
    Input / Output
*/
if (!int.TryParse(Console.ReadLine(), out int isAsc)) return;
string input = Console.ReadLine() ?? " ";
int[] nums = input.Split(" ", StringSplitOptions.RemoveEmptyEntries)
                  .Select(e => int.TryParse(e, out int num) ? num : 0)
                  .ToArray();

DurationTesting(() => SelectionSort(nums, isAsc == 1));
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