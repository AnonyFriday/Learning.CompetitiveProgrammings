using System;

// ==================================
// === CHANGE HERE
// ==================================

char[] StringCompression(char[] chars)
{
    if (chars == null || chars.Length == 0) return chars;

    int n = chars.Length;
    int readStart = 0;
    int readEnd = 0;
    int write = 0;

    while (readStart < n)
    {
        // Iterate over the 
        while ((readEnd < n) && chars[readEnd] == chars[readStart])
        {
            readEnd++;
        }

        int count = readEnd - readStart;
        chars[write++] = chars[readStart];

        // numeric patching is at only if count > 1
        if (count > 1)
        {
            string countStr = count.ToString();
            foreach (var el in countStr)
            {
                chars[write++] = el;
            }
        }

        readStart = readEnd;
    }

    Array.Resize(ref chars, write);

    return chars;
}

// ==================================
// === MAIN EXECUTION
// ==================================

/*
    Input / Output
*/
if (!int.TryParse(Console.ReadLine(), out int no)) return;
string input = Console.ReadLine() ?? " ";
char[] chars = input.ToArray();

DurationTesting(() =>
{
    char[] arr = StringCompression(chars);
    Output<char>(arr);
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