using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;

// ==================================
// === CHANGE HERE
// ==================================

bool ArePermutation(string s1, string s2)
{
    if (string.IsNullOrEmpty(s1) || string.IsNullOrEmpty(s2)) return false;

    int s1Len = s1.Count();
    int s2Len = s2.Count();

    if (s1Len > s2Len) return false;

    // build a target mask
    const int ASCII_SIDE = 256;
    char[] target = new char[ASCII_SIDE];
    char[] window = new char[ASCII_SIDE];

    for (int i = 0; i < s1Len; i++)
    {
        target[s1[i]]++;
        window[s2[i]]++; // build a window
    }

    // using SequenceEqual if both contain the same item
    if (Enumerable.SequenceEqual(target, window)) return true;

    // start from right
    for (int right = s1Len; right < s2Len; right++)
    {
        window[s2[right]]++; // added new frequency to the array
        window[s2[right - s1Len]]--; // reduce left el from the array
        if (Enumerable.SequenceEqual(target, window)) return true;
    }

    return false;
}

// ==================================
// === MAIN EXECUTION
// ==================================

/*
    Input / Output
*/
string s1 = Console.ReadLine() ?? " ";
string s2 = Console.ReadLine() ?? " ";

DurationTesting(() =>
{
    var isPermutated = ArePermutation(s1, s2);
    Console.WriteLine(isPermutated);
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