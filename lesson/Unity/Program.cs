using System;

class Program
{
    static void Main(string[] args)
    {
        // 配列の書き方----------
        //int[] iAry1;    // １次元配列
        //int[,] iAry2;   // ２次元配列
        //int[, ,] iAry3; // ３次元配列

        //iAry1 = new int[2];     　// １次元配列の生成
        //iAry2 = new int[2, 3];  　// ２次元配列の生成
        //iAry3 = new int[2, 3, 4];// ３次元配列の生成


        // 1つ1つの要素に初期値を代入----------
        //var iAry = new int[2, 3];   // ２行３列の２次元配列
        //iAry[0, 0] = 10;
        //iAry[0, 1] = 20;
        //iAry[0, 2] = 30;
        //iAry[1, 0] = 100;
        //iAry[1, 1] = 200;
        //iAry[1, 2] = 300;

        //Console.WriteLine("iAry[0, 0] = " + iAry[0, 0]);
        //Console.WriteLine("iAry[0, 1] = " + iAry[0, 1]);
        //Console.WriteLine("iAry[0, 2] = " + iAry[0, 2]);
        //Console.WriteLine("iAry[1, 0] = " + iAry[1, 0]);
        //Console.WriteLine("iAry[1, 1] = " + iAry[1, 1]);
        //Console.WriteLine("iAry[1, 2] = " + iAry[1, 2]);

        
        // 宣言と同時に初期値を入力----------
        //var iAry = new int[2, 3]  // 要素数の省略が可能
        var iAry = new int[,]      // カンマで次元数の指定は必要
        {
            { 10, 20, 30 },
            { 100, 200, 300 }
        };

        Console.WriteLine("Length = " + iAry.Length);// 全体の長さ
        Console.WriteLine("Rank = " + iAry.Rank);    // 次元数
        for (var i = 0; i < iAry.Rank; ++i)
        {
            Console.WriteLine("Rank{0}.Length = {1}", i, iAry.GetLength(i));
        }
        
        for (var i = 0; i < iAry.GetLength(0); ++i )    // 行を処理
        {
            for (var k = 0; k < iAry.GetLength(1); ++k )// 列を処理
            {
                Console.WriteLine("iAry[{0}, {1}] = {2}", i, k, iAry[i, k]);
            }
        }

    }
}
