#include <iostream>
#include <deque>
#include <windows.h>                //���� ���ع��
#include <conio.h>                  //���� _getch() �� _kbhit()
#include <ctime>
#include <time.h>
#define N 30
#define Up 1                        //�������Ӧ�ĵ�ASCIIΪ 72
#define Down 2                      //��ASCIIΪ   80
#define Left 3                      //��ASCIIΪ   75
#define Right 4   
#include<stdlib.h>                  //��ASCIIΪ   77

using namespace std;

class Map {
private:
    class snake {                   //��������
    public:
        int x;
        int y;
    };
    class Food {                    //ʳ��������
    public:
        int x;
        int y;
    };
    Food food;
    snake head, tail;               //��ͷ ��β
    deque<int> direction;           //����ÿ��ǰ���ķ���,���һ��ǰ����ӵ���ǰ��
    int mod;                        //��Ϸģʽ ��ͨģʽ == 0, ð��ģʽ == 1;
    int score;
    int grade;
    int autoSpeed;                  //������Ϸ�Զ������ٶ�
    char map[N][N];                 //�������      //�� xx[Up] = 80 Down��ASCII��Ϊ80
    int opposite_direction[5] = {0, 80, 72, 77, 75};//���������ķ������ASCII��(������)
    int speed[9] = {0, 800, 600, 500, 420, 250, 100, 40, 5};//�����Զ�ǰ���ٶ�,��λms
public:
    Map() : head({N / 2, N / 2}), tail({N / 2, N / 2 - 2}),     //���캯��
        mod(0), score(0), grade(1), autoSpeed(speed[grade]) { }
    void Hello();                   //��ӭ����
    void Print_Hello(int);          //��ӡ��ӭ����
    void Start_Game();
    void Initialize_Map();
    int Update_Map();
    void Show_Map();
    void Rand_Food();
    void Reset();                   //��λ
};

void Map::Hello()
{
    while (true){
        system("cls");                  //����
        Print_Hello(mod);

        if (_getch() != 13){                //�ж��Ƿ�Ϊ�س���,ȷ��ѡ���ģʽ
            switch (_getch()){              //�ж������ƶ�
            case 80: mod = 1; break;
            case 72: mod = 0; break;
            }
            continue;
        }                           
                                                  //Enter ��ASCII��Ϊ 13, ���˻س�ȷ��ģʽ
        if (mod == 0){                              //��ͨģʽ
                do {
                    system("cls");
                    cout << "\n\n\n\n\t\t\t ����������Ҫ����Ϸ����: (1~8)   ";
                    cin >> grade;
                } while (grade > 8 || grade < 1);   //�жϵȼ������Ƿ���ȷ
                autoSpeed = speed[grade];           //�����Զ�����ٶ�
                break;
            }
            else                                    //ð��ģʽ
                break;
        }
    Start_Game();               //��ʼ��Ϸ
}

void Map::Print_Hello(int mod)
{
    srand((unsigned)time(NULL));       //��ʱ������������
    cout << "\n\n\n\t\t\t\t ̰���� \n\n\n\n";
    cout << "\t\t\t     ��ѡ�����ģʽ:";
    cout << "\n\n\t\t\t     ��ͨģʽ:";
    if (mod == 0) cout << "   *";       //�����֪��δ���س�ȷ��ǰѡ���ģʽ
    cout << "\n\n\t\t\t     ð��ģʽ:";
    if (mod == 1) cout << "   *";
    cout << "\n\n\n\n\n\n\n\n "  ;  
}

void Map::Start_Game()
{
    char choose;
    Initialize_Map();           //��ʼ����ͼ
    Rand_Food();                //������һ��ʳ��
    do {
        Show_Map();
    } while (Update_Map());

    cout << "\t\t Game Over!!!     ���ȼ�����? (Y/Others)";
    cin >> choose;
    if (choose == 'Y' || choose == 'y'){
        Reset();
        Hello();
    }
}

void Map::Initialize_Map()
{
    for (int i = 0; i < N; i++)                     //���ұ߿�
        map[0][i] = map[N - 1][i] = '*';
    for (int i = 1; i < N; i++)                     //���±߿�
        map[i][0] = map[i][N - 1] = '*';
    for (int i = 1; i < N - 1; i++)                 //�м�հ�
        for (int j = 1; j < N - 1; j++)
            map[i][j] = ' ';

    map[N / 2][N / 2] = '@';                                //��ʼ��ͷ
    map[N / 2][N / 2 - 1] = map[N / 2][N / 2 - 2] = 'O';    //��ʼ����
    direction.push_front(Right);        //��ʼ�� direction
    direction.push_front(Right);        //��Ϊ��ʼΪ OO@ β��Ҫ�����������Ҳ��ܵ���ͷλ��
}

void Map::Show_Map()                            //�����Ϸ����
{
    system("cls");
    for (int i = 0; i < N; i++){
        cout << "\t";
        for (int j = 0; j < N; j++)
            cout << map[i][j] << ' ';
        if (i == N / 4)
            cout << "\t Score: " << score;
        if (i == N / 4 + 4)
            cout << "\t grade: " << grade;
        if (i == N / 4 + 8)
            cout << " ���ո����ͣ/����";
        cout << endl;
    }
}

int Map::Update_Map()                           //������Ϸ(����Ҫ��)
{
    int tmp_direction, tmp_others, sign = 0;    //sign == 1(�����˷����)         
    double start_time = (double)clock() / CLOCKS_PER_SEC;//����ִ����δ���ʱ��ʱ��

    do {
        if (_kbhit()){          //_kbhit()�ж��Ƿ��а�������,��������.
            tmp_others = _getch();              //����ǰ�н���
            if (tmp_others == 32)               //Ϊ�ո�� ��ͣ��Ϸ
                while (_getch() != 32);         //������ո���˳�ѭ��
            else if (tmp_others == 224){ //224Ϊ������ĵ�һ���ֽڵ�ASCII��
                    tmp_direction = _getch();
                if (opposite_direction[direction.front()] == tmp_direction) 
                //�Ƿ�Ϊ��һ�η���ķ���,������趨�³���<=4����Ե��Լ�(�½�)
                    continue;   //���赱ǰ��Ϊ: OO@ ���������ת�� �ж�Ϊ��Ч��ť,����ѭ��  
                switch (tmp_direction){                                 //�жϷ���
                case 72: direction.push_front(Up); sign = 1; break;
                case 80: direction.push_front(Down); sign = 1; break;
                case 75: direction.push_front(Left); sign = 1; break;
                case 77: direction.push_front(Right); sign = 1; break;
                }
                if (sign) break;                //�����˷����,�Ƴ�ѭ�� �ж����
            }
        }
        //δ���뷽�����ո�,�ж��Ƿ񳬹��Զ�ǰ��ʱ��
        if ((double)clock() / CLOCKS_PER_SEC - start_time > autoSpeed / 1000.0){//�÷�,����ǰ�н���
            direction.push_front(direction.front());    //�Զ�ǰ��,��ǰһ��ǰ������һ��
            break;
        }
    } while (true);

    map[head.x][head.y] = 'O';          //���µ�ͼ����ͷԭ��ͷλ����Ϊ����
    switch (direction.front()){         //������ͷ����
    case Up: head.x -= 1; break;
    case Down: head.x += 1; break;
    case Left: head.y -= 1; break;
    case Right: head.y += 1; break;
    }

    if (head.x == food.x && head.y == food.y){  //�Ƿ�Ե�ʳ��
        map[head.x][head.y] = '@';
        score += 10;
        if (mod == 1){          //����ð��ģʽ����Ϸ�ȼ����ٶ�,ÿ��6������һ��,���5��
            if (score / 60 >= grade){
                if (grade < 5)
                    grade++;
                autoSpeed = speed[grade];
            }
        }
        Rand_Food();                    //����ʳ��
    }
    else if (map[head.x][head.y] != ' ' && !(head.x == tail.x && head.y == tail.y)) 
        return 0;   //if(���µ�ͷλ���Ƿ�Ϊ��ͼ�еĿհ� && �Ƿ�Ϊ��β) (����)
        //ǰ���Ѿ��ж�û�Ե�ʳ��,������β��ǰ��,��Ϊֻ��������ͷû�и�����β,�����ų���β���
    else {                              //û�гԵ�ʳ��    
        map[tail.x][tail.y] = ' ';      //���µ�ͼ��β
        map[head.x][head.y] = '@';      //���µ�ͼ��ͷ
        switch (direction.back()){      //������β����
        case Up: tail.x -= 1; break;
        case Down: tail.x += 1; break;
        case Left: tail.y -= 1; break;
        case Right: tail.y += 1; break;
        }
        direction.pop_back();           //���� ǰ ��β����
    }
    return 1;                           //δײǽ��Ե��Լ�
}

void Map::Rand_Food()
{
    do {
        food.x = rand() % (N - 2) + 1;
        food.y = rand() % (N - 2) + 1;
    } while (map[food.x][food.y] != ' ');
    map[food.x][food.y] = '%';
}

void Map::Reset()
{
    Initialize_Map();
    head = {N / 2, N / 2};
    tail = {N / 2, N / 2 - 2};
    mod = 0;
    score = 0;
    grade = 1;
    autoSpeed = 800;
    direction.clear();
}

int main()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);                    //  �ٶ�
    CONSOLE_CURSOR_INFO CursorInfo;                                     //  �ѵ�
    GetConsoleCursorInfo(handle, &CursorInfo);      //��ȡ����̨�����Ϣ //  ����
    CursorInfo.bVisible = false;                    //���ؿ���̨���       //  ���
    SetConsoleCursorInfo(handle, &CursorInfo);      //���ÿ���̨���״̬ //  ����

    Map m;
    m.Hello();

    return 0;
}
