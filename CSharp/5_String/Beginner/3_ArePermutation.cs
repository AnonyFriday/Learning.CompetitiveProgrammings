using System;
using System.Collections.Generic;
using System.Linq;

// ==================================
// === CHANGE HERE
// ==================================

/*
    Using Dictionary to calculate freq
*/
bool IsPermutation(string org, string src)
{
    if (string.IsNullOrEmpty(org) || string.IsNullOrEmpty(src)) return true;
    if (org.Length != src.Length) return false;

    int n = src.Length;

    Dictionary<char, int> dict = new Dictionary<char, int>();
    for (int i = 0; i < n; i++)
    {
        if (dict.ContainsKey(org[i]))
        {
            dict[org[i]]++;
        }
        else
        {
            dict[org[i]] = 1;
        }

        if (dict.ContainsKey(src[i]))
        {
            dict[src[i]]--;
        }
        else
        {
            dict[src[i]] = -1;
        }
    }

    foreach (var el in dict)
    {
        if (el.Value > 0 || el.Value < 0) return false;
    }

    return true;
}

// ==================================
// === MAIN EXECUTION
// ==================================

/*
    Input / Output
*/
string org = Console.ReadLine() ?? " ";
string src = Console.ReadLine() ?? " ";

DurationTesting(() =>
{
    var isPer = IsPermutation(org, src);
    Console.WriteLine(isPer);
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