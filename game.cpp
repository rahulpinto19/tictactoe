#include <stdio.h>
#include <iostream>
#include <utility>
#include <conio.h>
#include <unistd.h>
using namespace std;
class tic
{
    char arr[3][3];
    pair<int, int> u1, u2;
    string name;
public:
    tic()
    {
        cout<<"Enter your Name:"<<endl;
        cin>>name;
        int user1, user2;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                arr[i][j] = ' ';
    }
    void print()
    {
        cout << "   ___ ___ ___ " << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "  |";
            for (int j = 0; j < 3; j++)
            {
                cout << arr[i][j] << "  |";
            }
            cout << endl;
            cout << "  |___|___|___|" << endl;
        }
    }
    int check(pair<int, int> a, char use)
    {
        int count = 0, set = a.second;
        // checks for the column level
        for (int i = 0; i < 3; i++)
            if (arr[i][set] == use)
                count++;
        if (count == 3)
            return 1;
        count = 0;
        set = a.first;
        // checks for the row level
        for (int i = 0; i < 3; i++)
            if (arr[set][i] == use)
                count++;
        if (count == 3)
            return 1;
        count = 0;
        int i = a.first;
        int j = a.second;
        while (i++ >= 0 and i < 3 and j++ < 3 and j >= 0 and arr[i][j] == use)
        {

            count++;
        }
        i = a.first;
        j = a.second;
        while (i-- >= 0 and i < 3 and j-- < 3 and j >= 0 and arr[i][j] == use)
            count++;
        if (count == 3)
            return 1;
        count = 0;
        i = a.first;
        j = a.second;
        // two while for top right to bottom left;
        while (i-- >= 0 and i < 3 and j++ < 3 and j >= 0 and arr[i][j] == use)
        {

            count++;
        }
        i = a.first;
        j = a.second;
        while (i++ >= 0 and i < 3 and j-- < 3 and j >= 0 and arr[i][j] == use)
            count++;

        if (count == 3)
            return 1;
        return 0;
    }

    int start()
    {
        int endgame = 0, pos;
        char a, b;
        int count = 0;
        while (count < 9)
        {
            system("cls");
            print();
            cout << name<<"'s turn " << endl;
            cout << "from position 1 to 9" << endl;
            for (int i = 0; i < 3; i++)
            {
                cout << "enter the number which is not occupied" << endl;
                cin >> pos;
                pos--;
                if (pos>=0 and pos<9 and arr[pos / 3][pos % 3] == ' ')
                    break;
                if (i == 2)
                {
                    cout << name<<"you have crossed the limit user 2 won the game ";
                    return 0;
                }
            }
            u1.first = pos / 3;
            u1.second = pos % 3;
            arr[pos / 3][pos % 3] = 'X';
            if (check(u1, 'X') == 1)
            {
                print();
                cout << name<<"  won the game"<<endl;
                return 0;
            }
            system("cls");
            print();
            cout << "computer" << endl;
            cout<<"Thinking!.."<<endl;
            sleep(4);
            int ct=0;
            while(ct<20)
            {
                pos=rand()%9;
                if (arr[pos / 3][pos % 3] == ' ')
                    break;
                ct++;
            }
            u1.first = pos / 3;
            u1.second = pos % 3;
            arr[pos / 3][pos % 3] = 'O';
            if (check(u1, 'O') == 1)
            {
                print();
                cout << "computer won the game" << endl;
                return 0;
            }
            count++;
        }
        cout << "TIE!!" << endl;
    }
};
class instruction
{
    public:
    instruction()
    {
        cout<<"-> Welcome to the game of the XOXO"<<endl;
        cout<<"-> Here you will be playing with the compute"<<endl;
        cout<<"-> You are onloy allowed to select numbers from the 1-9"<<endl;
        sleep(5);
    }
    ~instruction()
    {}
};
int main()
{
    char a;
    while (1)
    {
        instruction i;
        tic t;
        t.start();
        cout << "want to repeat the game Y/N" << endl;
        cin >> a;
        if (a == 'n' or a == 'N')
            {
                cout<<"Thank you for playing the game"<<endl;
                break;}
    }
}
