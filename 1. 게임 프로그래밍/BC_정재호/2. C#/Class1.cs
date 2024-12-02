using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C샵_수업_1
{
    class Monster
    {
        //private string SponPoint;
        private string MonName;
        private int MonHP;
        private int MonPower;
        public Monster(string Point, string name, int hp, int power)
        {
            MonName = name;
            MonHP = hp;
            MonPower = power;
        }
        public Monster() { }
        public Monster(Monster temp)
        {
            MonName = temp.GetName();
            MonHP = temp.GetHP();
            MonPower = temp.GetPower();
        }
        public string GetName()
        {
            return MonName;
        }
        public int GetHP()
        {
            return MonHP;
        }
        public int GetPower()
        {
            return MonPower;
        }
        public void SetHp(int _HP)
        {
            MonHP = _HP;
        }
        public void Show()
        {
            Console.WriteLine("#################################");
            Console.WriteLine("{0}\n{1}\n{2}", MonName, MonHP, MonPower);
            Console.WriteLine("#################################");
        }
        public void AddMon(Monster mon)
        {
            MonName = mon.GetName();
            MonHP = mon.GetHP();
            MonPower = mon.GetPower();
        }
    }
    //반복문 문제
    class monsterList
    {
        public List<Monster> GrassMon;
        public List<Monster> MountMon;
        public List<Monster> RiverMon;
        public monsterList()
        {
            AddMonGrass(ref GrassMon);
            AddMonMount(ref MountMon);
            AddMonRiver(ref RiverMon);
        }
        static void AddMonGrass(ref List<Monster> MONLIST)
        {
            MONLIST = new List<Monster>();
            MONLIST.Add(new Monster("grass", "피카츄", 100, 20));
            MONLIST.Add(new Monster("grass", "이상해씨", 100, 20));
            MONLIST.Add(new Monster("grass", "캐터피", 100, 10));
        }
        static void AddMonMount(ref List<Monster> MONLIST)
        {
            MONLIST = new List<Monster>();
            MONLIST.Add(new Monster("Mount", "파이리", 100, 20));
            MONLIST.Add(new Monster("Mount", "구구", 100, 10));
            MONLIST.Add(new Monster("Mount", "깨비참", 100, 10));
        }
        static void AddMonRiver(ref List<Monster> MONLIST)
        {
            MONLIST = new List<Monster>();
            MONLIST.Add(new Monster("River", "꼬부기", 100, 20));
            MONLIST.Add(new Monster("River", "모래두지", 100, 10));
            MONLIST.Add(new Monster("River", "꼬렛", 100, 10));
        }
    }
    
    class user
    {
        public List<Monster> HaveMonster;
        private int MonsterBall=0;

        
        public user()
        {
            HaveMonster = new List<Monster>();
            MonsterBall = 10;
        }
        public void Set_MonsterBall(int nBall)
        {
            MonsterBall = nBall;
        }
        public int Get_MonsterBall()
        {
            return MonsterBall;
        }

        public void MonsterAtk(ref Monster MyMonster, ref Monster OtherMonster)
        {
            OtherMonster.SetHp(OtherMonster.GetHP()-MyMonster.GetPower());
        }
        public void GetOtherMon(Monster OtherMonster)
        {
            HaveMonster.Add(OtherMonster);
        }


        public void DelMyMon(int index)
        {
            HaveMonster.Remove(HaveMonster[index]);
        }
        public string Get_HaveMonName(int index)
        {
            string returnName = HaveMonster[index].GetName();
            return returnName;
        }

        
    }
    class PoketMon
    {
        private static monsterList MonsterList = new monsterList();
        public void PoketMonGame()
        {
            user Player = new user();
            char keyinput = (char)0;
            Console.WriteLine("GAME_START~~");
            Console.WriteLine();
            Console.Write("[안녕하십니까. 포켓몬 세계에 오신 것을 환영합니다.]\n[파트너로 삼을 포켓몬을 선택해주세요.]\n");
            Console.Write("[1. 이상해씨 2. 파이리 3. 꼬북이]\n유저 : ");
            ReadKey(ref keyinput);

            if (keyinput == '1')
            {
                Player.HaveMonster.Add(new Monster(MonsterList.GrassMon[1]));
            }
            else if(keyinput == '2')
            {
                Player.HaveMonster.Add(new Monster(MonsterList.MountMon[0]));
            }
            else
            {
                Player.HaveMonster.Add(new Monster(MonsterList.RiverMon[0]));
            }
            
            Console.Write(string.Format($"[\"{Player.Get_HaveMonName(0)}\"을(를) 가졌습니다.]\n[게임을 시작합니다.]\n\n\n"));
            
            while(true)
            {
                Console.Write("[마을에 입장했습니다.]\n" +
                    "['상점'에서 몬스터볼을 구매하실 수 있습니다.]\n" +
                    "['여관'에서 소지하고 있는 몬스터의 체력을 회복할 수 있습니다.]\n" +
                    "['던전'에서 몬스터와 대결하고 몬스터를 잡을 수 있습니다.]\n"+
                    "['병원'에서 당신이 소지한 몬스터의 상태를 확인할 수 있습니다.]\n"+
                    "[1. 상점 2. 여관 3. 던전 4. 병원]\n유저 : ");
                ReadKey(ref keyinput);
                if(keyinput == '1')
                {

                }
                else if(keyinput == '2')
                {

                }
                else if(keyinput == '3')
                {
                    ChoiceDon(ref keyinput, ref Player);
                }
                else if(keyinput == '4')
                {
                    Hospital(ref keyinput, ref Player);
                }
                else
                {
                    //버그 확인
                    for (int i = 0; i < 3; i++)
                        MonsterList.GrassMon[i].Show();
                    for (int i = 0; i < 3; i++)
                        MonsterList.MountMon[i].Show();
                    for (int i = 0; i < 3; i++)
                        MonsterList.RiverMon[i].Show();
                }
            }
        }
        
        //몬스터 랜덤 생성 //생성 = produce
        static void ProdMon(string area, ref Monster Mon)
        {
            Random Rand = new Random();
            int RandMon;
            RandMon = Rand.Next(0, 3);

            if (area == "Grass") Mon.AddMon(MonsterList.GrassMon[RandMon]);
            else if (area == "Mount") Mon.AddMon(MonsterList.MountMon[RandMon]); 
            else Mon.AddMon(MonsterList.RiverMon[RandMon]); 
        }
        static void ChoiceDon(ref char key, ref user Player)
        {
            Console.Write("[던전에 입장했습니다.]\n[어디로 이동하시겠습니까?]\n[1. 초원 2. 산 3. 강]\n유저 : ");
            ReadKey(ref key);
            switch (key)
            {
                case '1':
                    Console.WriteLine("[초원으로 이동했습니다.]");
                    MoveDon(ref key, "Grass", ref Player);
                    break;
                case '2':
                    Console.WriteLine("[산으로 이동했습니다.]");
                    MoveDon(ref key, "Mount", ref Player);
                    break;
                case '3':
                    Console.WriteLine("[강으로 이동했습니다.]");
                    MoveDon(ref key, "River", ref Player);
                    break;
            }
        }
        static void MoveDon(ref char key, string area, ref user Player)
        {
            Random Rand = new Random();
            int RandEvent;

            while(true)
            {
                Console.Write("[행동을 선택해주세요.]\n[1. 이동 2. 돌아가기]\n유저 : ");
                ReadKey(ref key);

                if(key == '1')
                {
                    Console.WriteLine("[앞으로 한걸음 이동했습니다.]");
                    RandEvent = Rand.Next(0, 3);
                    if(RandEvent>0)//몬스터와 조우
                    {
                        Monster Mon = new Monster();
                        ProdMon(area, ref Mon);
                        Console.WriteLine(string.Format($"[\"{Mon.GetName()}\"이(가) 등장했습니다.]"));
                        Console.Write(string.Format($"[\"{Mon.GetName()}\"와 전투배틀을 진행하시 겠습니까?]\n[1. 예 2. 아니오]\n유저 : "));
                        ReadKey(ref key);
                        if(key == '1')
                        {
                            //몬스터와 전투
                            BattleMon(ref Mon, ref Player, ref key);
                        }
                        else
                        {
                            Console.WriteLine("[전투를 진행하지 않습니다.]");
                            Console.WriteLine();
                        }
                    }
                    else
                    {
                        Console.WriteLine("[아무일도 일어나지 않았습니다.]");
                        Console.WriteLine();
                    }
                }
                else
                {
                    Console.WriteLine("[마을로 돌아 갑니다.]");
                    Console.WriteLine();
                    break;
                }
            }
        }
        static void BattleMon(ref Monster Mon, ref user Player, ref char key)
        {
            bool shilde = true;
            int MonIndex = 0;
            Console.WriteLine("[전투가 시작되었습니다.]");
            Console.WriteLine("[전투의 시작은 기본적으로 첫번째 몬스터를 소환해 진행됩니다.]");
            Monster UseMon = Player.HaveMonster[MonIndex];
            Console.WriteLine("['{0}' 이(가) 필드에 소환되었습니다.]\n", UseMon.GetName());
            UseMon.Show();
            while (true)
            {
                Console.Write("[행동을 선택해주세요.]\n[1. 공격 2. 막기 3. 몬스터 변경 4. 도망]\n유저 : ");
                ReadKey(ref key);

                if(key == '1')
                {
                    Random Rand = new Random();
                    int RandMon;
                    RandMon = Rand.Next(1, 3);
                    Console.WriteLine("[나의 '{0}'이(가) 공격했습니다.]", UseMon.GetName());
                    if(RandMon == 1)
                    {
                        Console.WriteLine("[공격이 생각보다 효과가 컸습니다.]");
                        AtkMon(ref UseMon, ref Mon, 2);
                    }
                    else
                    {
                        AtkMon(ref UseMon, ref Mon, 1);
                    }
                    
                }
                else if(key == '2')
                {
                    Console.WriteLine("[나의 '{0}'이(가 막기를 시전했습니다.)]", UseMon.GetName());
                    shilde = false;
                }
                else if(key == '3')
                {
                    Console.WriteLine("[몬스터를 변경합니다.]");
                    //몬스터 변경 함수 ( HP를 확인하고 0과 같은 경우 변경이 불가능 하도록 )
                }
                else
                {
                    Console.WriteLine("[도망치는데 성공했습니다.]");
                    break;
                }

                if (Mon.GetHP() <= 0)
                {
                    Console.WriteLine("[상대몬스터를 처치하는데 성공했습니다.]\n");
                    GetOtherMon(Mon, ref Player, ref key);
                    break;
                }

                if (shilde)
                {
                    Console.WriteLine("[상대 '{0}'이(가) 공격했습니다.]", Mon.GetName());
                    AtkMon(ref Mon, ref UseMon, 1);
                }
                else
                {
                    Console.WriteLine("[막기에 성공했습니다.]");
                    shilde = true;
                }

                if(UseMon.GetHP() <= 0)
                {
                    Console.WriteLine("[나의 '{0}'이(가) 공격 받아 HP가 0이 되었습니다.]", UseMon.GetName());
                    Console.Write("[몬스터를 변경하시겠습니까?]\n[1. 예 2. 아니오 도망갈래요]\n 유저 : ");
                    ReadKey(ref key);
                    if(key == '2')
                    {
                        Console.WriteLine("[전투를 종료합니다.]");
                        break;
                    }
                    else
                    {
                        Console.Write("[사용할 몬스터를 선택해주세요.]\n유저 : ");
                        //몬스터 변경 함수
                    }
                }
                BattleResult(ref UseMon, ref Mon);
            }
        }
        static void AtkMon (ref Monster MyMon, ref Monster OtherMon, int damage)
        {
            OtherMon.SetHp(OtherMon.GetHP() - (MyMon.GetPower()*damage));
        }
        static void BattleResult (ref Monster MyMon, ref Monster OtherMon)
        {
            //공격 결과 출력
            Console.WriteLine("<전투결과>\n[나의 몬스터]");
            MyMon.Show();
            Console.WriteLine("[상대 몬스터]");
            OtherMon.Show();
        }
        //병원에서 사망한 몬스터를 치유 할 수 있도록 만들 예정
        static void MonShow(ref user Player)
        {
            for (int count = 1; count - 1 < Player.HaveMonster.Count(); count++)
            {
                Console.WriteLine();
                Console.Write(string.Format($"<{count}번>\n" +
                    $"이름 : {Player.HaveMonster[count - 1].GetName()}\n체력 : {Player.HaveMonster[count - 1].GetHP()}\n힘 : {Player.HaveMonster[count - 1].GetPower()}"));

            }
        }
        
        static void Hospital(ref char key, ref user Player)
        {
            Console.Write("[병원에 입장하셨습니다.]\n[소지하고 계신 몬스터는 다음과 같습니다.]");
            do
            {
                MonShow(ref Player);
                Console.WriteLine();
                Console.WriteLine();

                Console.Write("[다시 확인하시겠습니까?]\n[1. 예 2. 아니오]\n유저 : ");
                ReadKey(ref key);
            } while (key == '1');
            Console.WriteLine("[마을로 이동합니다.]");
            Console.WriteLine();
        }
        static void ReadKey(ref char key)
        {
            key = (char)Console.Read();
            Console.ReadLine();
        }
        static void GetOtherMon(Monster OtherMon, ref user Player, ref char key)
        {
            Console.Write("[처치한 몬스터를 잡으시겠습니까?]\n[소지하고 있는 몬스터 볼 : {0}]\n[1. 예 2. 아니오]", Player.Get_MonsterBall());
            ReadKey(ref key);
            if (key == '1')
            {
                Player.Set_MonsterBall(Player.Get_MonsterBall() - 1);
                Player.HaveMonster.Add(OtherMon);
                Console.WriteLine("[몬스터를 잡는데 성공했습니다.]");
            }
        }
    }
}
