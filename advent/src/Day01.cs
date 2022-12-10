// ADVENT OF CODE DAY 01 - CALORIES //  

/*
* Read input from given data e.g. from text file //
* Read lines until a linebreak is read //
* Once linebreak is read, take all previous calories and add them up
* Put the result of this sum in an array/list/something
* Do this for all the data. Make sure it reads the end of the file (Perhaps append % to the end of the file for it to read)
* Compare all values in the "totals" array/list/whatever and return the highest value
* This value will be the answer
*/

namespace Aoc22
{
    class Calories
    {
        public static List<int> ListOfSumData(string[] lines)
        {
            List<int> dataToSum = new List<int>();
            List<int> summedData = new List<int>();

            foreach(string line in lines)
            {
                if (line != "")
                {
                    dataToSum.Add(Int32.Parse(line));
                }
                else
                {
                    summedData.Add(dataToSum.Sum());
                    dataToSum.Clear();
                }
            }

            return summedData;
        }

        public static void Main()
        {
            var lines = System.IO.File.ReadAllLines(@"../advent/input/CalorieData.txt");

            Console.WriteLine(ListOfSumData(lines).Max());
        }
    }
}