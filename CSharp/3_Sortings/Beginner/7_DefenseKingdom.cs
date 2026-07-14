using System.Text.RegularExpressions;

// ==================================
// === CHANGE HERE
// ==================================

/*
    For example, the tower is at location:
    (2,3) (3,4) (1,1)

    For x and y, add the left and right barrier
    Find the max difference = max horizontal * max vertical

    Max horizontal =  left - right - 1, for barrier, left - right
    Max vertical = left - right - 1, for barrier left - right
    Since we have te outlier, I will initialize the array with 
        [1, w + 1], 
        [1, h + 1]

    Having the array to sort x coordination:
        1 | 1 2 3 | 3
    Having the array to sort y coordination:
        1 | 1 3 4 | 4
*/
void DefenseKindom(int w, int h, Tower[] positions)
{
    if (positions == null || positions.Length == 0)
    {
        Console.WriteLine(w * h);
    }

    if (w <= 0 || h <= 0) return;

    List<int> xs = new List<int>();
    List<int> ys = new List<int>();
    xs.Add(1);
    ys.Add(1);

    for (int i = 0; i < positions.Length; i++)
    {
        xs.Add(positions[i].W);
        ys.Add(positions[i].H);
    }

    xs.Add(w + 1);
    ys.Add(h + 1);

    // sort x and y
    xs.Sort((a, b) => a - b);
    ys.Sort((a, b) => a - b);

    // find the max diff
    int maxX = 1; int maxY = 1;
    for (int i = 1; i < xs.Count; i++)
    {
        maxX = Math.Max(maxX, xs[i] - xs[i - 1] - 1);
        maxY = Math.Max(maxY, ys[i] - ys[i - 1] - 1);
    }

    Console.WriteLine(maxX * maxY);
}

// ==================================
// === MAIN EXECUTION
// ==================================

/*
    Input / Output
*/
if (!int.TryParse(Console.ReadLine(), out int w)) return;
if (!int.TryParse(Console.ReadLine(), out int h)) return;

string input = Console.ReadLine() ?? " ";
Tower[] positions = input.Split(" ", StringSplitOptions.RemoveEmptyEntries)
                  .Select(e =>
                  {
                      var matches = Regex.Matches(e, "-?\\d+");
                      int a = int.Parse(matches[0].Value);
                      int b = int.Parse(matches[1].Value);
                      return new Tower(a, b);
                  })
                  .ToArray();

DurationTesting(() => DefenseKindom(w, h, positions));

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

record Tower(int W, int H);