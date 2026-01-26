using System;
using System.Collections.Generic;
using System.IO.Pipelines;
using System.Linq;

// ==================================
// === CHANGE HERE
// ==================================

int[] WavePrint(int[][] arr)
{
    if (arr == null) return Array.Empty<int>();

    int rows = arr.Length;
    int cols = arr[0].Length;
    bool isDown = true;
    List<int> result = new List<int>();

    for (int c = cols - 1; c >= 0; c--)
    {
        if (isDown)
        {
            for (int r = 0; r <= rows - 1; r++)
            {
                result.Add(arr[r][c]);
            }
        }
        else
        {
            for (int r = rows - 1; r >= 0; r--)
            {
                result.Add(arr[r][c]);
            }
        }
        isDown = !isDown;
    }

    return result.ToArray();
}

// ==================================
// === MAIN EXECUTION
// ==================================

/*
    Input / Output
*/
int[][] arr = new int[5][];

for (int i = 0; i < 5; i++)
{
    int[] nums = Console.ReadLine()
                    .Split(" ")
                    .Select(int.Parse)
                    .ToArray();

    arr[i] = nums;
}

DurationTesting(() =>
{
    var result = WavePrint(arr);
    Output(result);
});

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

void Output<T>(T[,] arr)
{
    for (int i = 0; i < arr.GetLength(0); i++)
    {
        for (int j = 0; j < arr.GetLength(1); j++)
        {
            Console.Write(arr[i, j] + " ");
        }
        Console.WriteLine();
    }
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