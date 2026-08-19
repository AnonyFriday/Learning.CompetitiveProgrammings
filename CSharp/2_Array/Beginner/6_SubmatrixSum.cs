using System;
using System.Collections.Generic;
using System.Linq;

// ==================================
// === CHANGE HERE
// ==================================

int[][] CalculatePre(int[][] arr)
{
    int n = arr.Count();
    int m = arr[0].Count();

    int[][] pre = new int[n][];

    for (int i = 0; i < n; i++)
    {

        pre[i] = new int[m];

        for (int j = 0; j < m; j++)
        {
            int sum = arr[i][j];
            if (i > 0) sum += pre[i - 1][j];
            if (j > 0) sum += pre[i][j - 1];
            if (i > 0 && j > 0) sum -= pre[i - 1][j - 1];

            pre[i][j] = sum;
        }
    }

    return pre;
}

int SumRegion(int[][] pre, int rs, int cs, int re, int ce)
{
    var sum = pre[re][ce];

    if (rs > 0) sum -= pre[rs - 1][ce];
    if (cs > 0) sum -= pre[re][cs - 1];
    if (rs > 0 && cs > 0) sum += pre[rs - 1][cs - 1];

    return sum;
}

int CalculateSum(int[][] arr, int rs, int cs, int re, int ce)
{
    if (arr == null || arr.Count() == 0 || arr[0].Count() == 0) return 0;

    int[][] pre = CalculatePre(arr);
    int sum = SumRegion(pre, rs, cs, re, ce);

    return sum;
}

// ==================================
// === MAIN EXECUTION
// ==================================

/*
    Input / Output
*/

if (!int.TryParse(Console.ReadLine(), out int rs)) return;
if (!int.TryParse(Console.ReadLine(), out int cs)) return;
if (!int.TryParse(Console.ReadLine(), out int re)) return;
if (!int.TryParse(Console.ReadLine(), out int ce)) return;

int[][] arr = new int[4][];
int i = 0;

string input = Console.ReadLine() ?? " ";
while (input != string.Empty && i < 4)
{
    int[] row = input
                    .Split(" ")
                    .Select(int.Parse)
                    .ToArray();

    arr[i] = row;
    input = Console.ReadLine();
    i++;
}

DurationTesting(() =>
{
    int result = CalculateSum(arr, rs, cs, re, ce);
    Console.WriteLine(result);
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