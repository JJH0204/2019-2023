using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C샵_수업_1
{
    class Program
    {
        //정수 값을 입력 받아 3로 나눈 결과 출력
        static void ValMain()
        {
            int nScore = 0;
            float fAverage = 0.0f;
            string sScore, sAverage;
            Console.WriteLine("Score : " + nScore);
            Console.WriteLine("Average : " + fAverage);
            Console.Write("Please input integer\n: ");
            sScore = Console.ReadLine();
            
            nScore = Convert.ToInt32(sScore);
            fAverage = nScore / 3.0f;
            Console.WriteLine("score : " + nScore + "average : " + fAverage);
            sAverage = Convert.ToString(fAverage);
            Console.WriteLine("string average : " + sAverage);

        }
       
        //랜덤 클래스를 활용해 랜덤 값을 만들고 크리티컬 확률과 조건을 확인해 몬스터에게 데미지를 주는 예제 코드
        static void criticalAttackMain()
        {
            Random cRandom = new Random();
            int nRandom = cRandom.Next(1, 3); //랜덤으로 구한 값.
            Console.WriteLine("Random : " + nRandom); //1~3-1(2) 범위의 값들 중 하나를 랜덤으로 출력함

            int nPlayerPower = 10;
            int nMonsterHP = 100;

            if(nRandom == 1)
            {
                nPlayerPower = (int)(nPlayerPower * 1.5);
                Console.WriteLine("Critical Damage : " + nPlayerPower);
            }
            else
            {
                Console.WriteLine("Player Damage : " + nPlayerPower);
            }

            nMonsterHP -= nPlayerPower;

            Console.WriteLine("Monster HP : " + nMonsterHP);
        }
      
        //switch 문을 활용해 다 분기 조건문을 검사 할 수 있는 예제 코드
        static void MoveHome()
        {
            Console.Write("What do you want : (home, dungeon, store)\n: ");
            string sChoice = Console.ReadLine();

            switch(sChoice)
            {
                case "home":
                case "Home":
                case "HOME":
                    Console.WriteLine("We move \"Home\"");
                    break;
                case "dungeon":
                case "Dungeon":
                case "DUNGEON":
                    Console.WriteLine("We move \"Dungeon\"");
                    break;
                case "store":
                case "Store":
                case "STORE":
                    Console.WriteLine("We move \"Store\"");
                    break;

            }

        }

        static void Main(string[] args)
        {
            //ValMain();
            //criticalAttackMain();
            MoveHome();
        }
    }
}
