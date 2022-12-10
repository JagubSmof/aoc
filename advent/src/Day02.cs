// ADVENT OF CODE DAY 02 - ROCK PAPER SCISSORS //

/*
* Know the rules:
*   3 pts for draw, 6pts for win
*   1 pt for rock (a,x), 2 pts for paper(b,y), 3 pts for Scissors(c,z)
*   Rock(a,x) beats Scissors(c,z), Paper(b,y) beats Rock(a,x), Scissors(c,z) beats paper(b,y)
*   e.g. a * x = 3(draw) + 1(rock) pts
*   e.g. c * y = 0(loss) + 2(paper) pts
*   e.g. b * z = 6(win)  + 3(scissors) pts
* What to do:
*   Read data line by line from file RPSStrategy.txt //
*   Read lines char by char
*   First char is their play, second char is my play, space is redundant
*   Compare their play with my play to determine win/draw/loss
*   a * x, b * y, c * z draw
*   a * z, b * x, c * y loss
*   a * y, b * z, c * x win
*/
namespace Aoc22
{
    class RPS
    {
        static int PointsAccumulatedThisRound(string playerMoves)
        {
            int totalPoints = 0;

            // Determine points gained by choosing
            if (playerMoves.Contains("X"))
            {
                // Rock brings 1 point
                totalPoints += 1;
            }
            else if (playerMoves.Contains("Y"))
            {
                // Paper brings 2 points
                totalPoints += 2;
            }
            else if (playerMoves.Contains("Z"))
            {
                // Scissors bring 3 points
                totalPoints += 3;
            }
            
            // Determine points gained by result
            if (playerMoves == "AX" || playerMoves == "BY" || playerMoves == "CZ")
            {
                // Draw brings 3 points
                totalPoints += 3;
            }
            else if (playerMoves == "AY" || playerMoves == "BZ" || playerMoves == "CX")
            {
                // Win brings 6 points 
                totalPoints += 6;
            }

            return totalPoints;
        }

        static char MoveToPlay(char theirMove, char yourMove)
        {
            // X = Loss, Y = Draw, Z = Win

            if (theirMove == 'A')
            {
                switch (yourMove)
                {
                    case 'X':
                        return 'Z';
                    case 'Y':
                        return 'X';
                    case 'Z':
                        return 'Y';
                }
            }
            else if (theirMove == 'B')
            {
                switch (yourMove)
                {
                    case 'X':
                        return 'X';
                    case 'Y':
                        return 'Y';
                    case 'Z':
                        return 'Z';
                }
            }
            else
            {
                switch (yourMove)
                {
                    case 'X':
                        return 'Y';
                    case 'Y':
                        return 'Z';
                    case 'Z':
                        return 'X';
                }
            }
            return 'p';
        }

        public static void Main()
        {
            string[] lines = System.IO.File.ReadAllLines(@"../advent/input/RPSStrategy.txt");
            string playerMove = "";
            int pointsTotal = 0;

            foreach (string line in lines)
            {
                playerMove += line[0];
                playerMove += MoveToPlay(line[0], line[2]);
                // send this string to a function to review
                pointsTotal += PointsAccumulatedThisRound(playerMove);
                playerMove = "";
            }            

            Console.WriteLine(pointsTotal);
        }
    }
}