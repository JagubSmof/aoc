namespace Utils
{
    class Files
    {
        public static string[] ReadFromFile(string path)
        {
            return System.IO.File.ReadAllLines(path);
        }
    }

}