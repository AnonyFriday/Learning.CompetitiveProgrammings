using System;
using System.Collections.Generic;
using System.Linq;

// ==================================
// === CHANGE HERE
// ==================================

/*
    Having a pointer as the right most barrier for the sorted part
    Next el = p + 1
    Iterate back the sorted back to insert at the correct position
*/
void InsertionSort(int[] arr, bool isAsc = true)
{
    if (arr == null || arr.Length == 0) return;

    int p = 0;
    int n = arr.Length;
    while (p < n - 1)
    {
        int i = p;
        while (i >= 0
            && ((isAsc && (arr[i] > arr[i + 1])) || (!isAsc && (arr[i] < arr[i + 1]))))
        {
            Swap(ref arr[i], ref arr[i + 1]);
            i--;
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

DurationTesting(() => InsertionSort(nums, isAsc == 1));
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