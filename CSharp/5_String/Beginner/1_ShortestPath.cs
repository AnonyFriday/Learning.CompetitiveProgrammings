using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

// ==================================
// === CHANGE HERE
// ==================================

string ShortestPath(string input)
{
    if (input == null || string.IsNullOrEmpty(input)) return string.Empty;

    int x = 0;
    int y = 0;
    StringBuilder result = new StringBuilder();
    foreach (var el in input)
    {
        switch (el)
        {
            case 'N': y++; break;
            case 'S': y--; break;
            case 'W': x--; break;
            case 'E': x++; break;
        }
    }

    // 1st quardant
    if (x > 0) result.Append('E', x);
    if (x < 0) result.Append('W', -x);
    if (y > 0) result.Append('N', y);
    if (y < 0) result.Append('S', -y);

    return result.ToString();
}

// ==================================
// === MAIN EXECUTION
// ==================================

/*
    Input / Output
*/
string input = Console.ReadLine() ?? " ";

DurationTesting(() =>
{
    string path = ShortestPath(input);
    Console.WriteLine(path);
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