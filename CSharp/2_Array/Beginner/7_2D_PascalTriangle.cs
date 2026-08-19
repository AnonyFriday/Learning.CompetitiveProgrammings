using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.VisualBasic;

// ==================================
// === CHANGE HERE
// ==================================

/*
    The Pascal triangle, notice that
    - The elenment above is equals to the 2 upper elements 
    - First and Last elements always equals to 1, append fisrt and last
    - always start at row index 1, each row loop n - 2

    arrr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];

*/
int[][] PascalTriangle(int n)
{
    if (n <= 0) return new int[n][];

    int[][] result = new int[n][];

    // n rows
    for (int i = 0; i < n; i++)
    {
        result[i] = new int[i + 1];

        // first
        result[i][0] = 1;

        // each element if rows
        for (int j = 1; j <= i - 1; j++)
        {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }

        // lasts
        if (i >= 1)
        {
            result[i][i] = 1;
        }
    }

    return result;
}

// ==================================
// === MAIN EXECUTION
// ==================================

/*
    Input / Output
*/
if (!int.TryParse(Console.ReadLine(), out int rows)) return;

DurationTesting(() =>
{
    var result = PascalTriangle(rows);
    Output2D(result);
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

void Output2D<T>(T[][] arr)
{
    foreach (T[] row in arr)
    {
        foreach (T el in row)
        {
            Console.Write($"{el} ");
        }
        Console.WriteLine();
    }
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