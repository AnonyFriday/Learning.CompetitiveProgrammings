// ==================================
// === CHANGE HERE
// ==================================

/*
    A point is (x,y), if x equals, then compare with the y
    Using the insertion sorting, reduce the swapping
*/
using System.Text.RegularExpressions;

void CartesianPointsSort(
    Point[] arr,
    Func<Point, Point, int> comparer)
{
    if (arr == null || arr.Length == 0) return;

    int p = 0;
    int N = arr.Length;

    while (p < N - 1)
    {
        for (int i = p + 1; i > 0; i--)
        {
            // a < b -->true, then a - b < 0
            if (comparer(arr[i], arr[i - 1]) < 0)
            {
                Swap(ref arr[i], ref arr[i - 1]);
            }
        }

        p++;
    }
}

/*
    Ascending
*/
Func<Point, Point, int> PointLexigraphicalComparision = (a, b) =>
{
    if (a.X == b.X)
    {
        if (a.Y == b.Y) return 0;
        return a.Y - b.Y;
    }
    return a.X - b.X;
};

// ==================================
// === MAIN EXECUTION
// ==================================

/*
    Input / Output
*/
if (!int.TryParse(Console.ReadLine(), out int no)) return;
string input = Console.ReadLine() ?? " ";
Point[] points = input.Split(" ", StringSplitOptions.RemoveEmptyEntries)
                  .Select(e =>
                  {
                      // matches negative and positive numbers
                      var matches = Regex.Matches(e, @"-?\d+");
                      int first = int.Parse(matches[0].Value);
                      int second = int.Parse(matches[1].Value);
                      return new Point(first, second);
                  })
                  .ToArray();

DurationTesting(() => CartesianPointsSort(points, PointLexigraphicalComparision));

foreach (var point in points)
{
    Console.WriteLine($"({point.X},{point.Y})");
}

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

public record Point(int X, int Y);
