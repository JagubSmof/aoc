// was initially creating a new c# project with every task
// This solution is stolen from Taeho Kang because he's smarter than me

//#define RUN_ALL

#if RUN_ALL
    Aoc22.Calories.Main();
    Aoc22.RPS.Main(); // includes solution 2
#endif

class Runner
{
    static void Main()
    {
        Aoc22.RPS.Main();
    }
}