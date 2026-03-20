using System.Text.RegularExpressions;

// ==================================
// === CHANGE HERE
// ==================================

List<(int, int)> SortCabs(List<(int, int)> pairs)
{
    if (pairs == null || pairs.Count == 0) return new List<(int, int)>();

    var result = new List<(int, int)>(pairs);

    // Can also use the lambda, since it matchhes the delegate
    Comparison<(int a, int b)> comDelegate = (pair1, pair2) =>
    {
        double sum1 = Math.Pow(pair1.a, 2) + Math.Pow(pair1.b, 2);
        double sum2 = Math.Pow(pair2.a, 2) + Math.Pow(pair2.b, 2);

        return Math.Sqrt(sum1).CompareTo(Math.Sqrt(sum2));
    };

    result.Sort(comDelegate);
    return result;
}

// ==================================
// === MAIN EXECUTION
// ==================================

/*
    Input / Output
*/
List<(int, int)> cabs = new();

string line;
while (!string.IsNullOrEmpty(line = Console.ReadLine()))
{
    var matches = Regex.Matches(line, "\\d");

    if (matches.Count() <= 0) continue;

    cabs.Add(new(
        int.Parse(matches[0].Value),
        int.Parse(matches[1].Value)
    ));
}

// Logic
DurationTesting(() =>
{
    var result = SortCabs(cabs);

    foreach (var pair in result)
    {
        Console.WriteLine($"({pair.Item1},{pair.Item2})");

    }
});


// DurationTesting(() => AlgorithmName(nums, true));
// Output(nums);

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