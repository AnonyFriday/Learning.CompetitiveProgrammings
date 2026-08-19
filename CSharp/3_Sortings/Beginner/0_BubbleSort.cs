using System;
using System.Collections.Generic;
using System.Linq;

// ==================================
// === CHANGE HERE
// ==================================

/*
    Bubbling up the smallest or largest depends on asc or desc
    to the end of the array
    Right-most position will be fixed for each iteration

    Big0 = 
*/
void BubbleSort(int[] arr, bool isAsc = true)
{
    if (arr == null || arr.Length == 0) return;

    int N = arr.Length;
    bool isSorted = false;
    for (int i = N - 1; i >= 0; i--)
    {
        isSorted = false;
        for (int j = 1; j <= i; j++)
        {
            // default asc
            if ((isAsc && (arr[j - 1] > arr[j]))
                || (!isAsc && (arr[j - 1] < arr[j])))
            {
                isSorted = true;
                Swap(ref arr[j], ref arr[j - 1]);
            }
        }

        if (!isSorted) break;
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

DurationTesting(() => BubbleSort(nums, true));
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
}

void DurationTesting(Action action)
{
    var startTime = DateTime.Now;

    action();

    var endTime = DateTime.Now;
    var duration = endTime - startTime;
    Console.WriteLine($"Duration: {duration.Microseconds} ms");
}

