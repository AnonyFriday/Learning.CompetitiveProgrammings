using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;

// ==================================
// === CHANGE HERE
// ==================================

/*
    Applying 2 pointers
    - Read and Write

*/
string RemoveDuplicate(string input)
{
    if (string.IsNullOrEmpty(input)) return string.Empty;
    if (input.Count() == 1) return input;

    // Sort first
    char[] arr = input.ToArray();
    Array.Sort(arr, (a, b) => a - b);

    int n = input.Count();
    int write = 0;
    int read = 0;
    while (read < n)
    {
        // If equals, then just continue, else modify to the original
        while (read < n - 1 && arr[read] == arr[read + 1])
        {
            read++;
        }
        arr[write++] = arr[read];
        read++;
    }

    // Convert arr to string
    StringBuilder str = new StringBuilder();
    for (int i = 0; i < write; i++)
    {
        str.Append(arr[i]);
    }

    return str.ToString();
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
    string str = RemoveDuplicate(input);
    Console.WriteLine(str);
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