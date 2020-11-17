#include <iostream>
#include <conio.h>

const int elements{ 6 };

char lockId[elements];

char password[elements]{ 'A','B', 'C', 'D', 'E', 'F' };
bool correctPassword{false};

static constexpr int KEY_UP = 72;
static constexpr int KEY_DOWN = 80;
static constexpr int KEY_LEFT = 75;
static constexpr int KEY_RIGHT = 77;

int arrowCorX{0};
char arrowSymbol{'V'};

void Draw() 
{
    std::cout << "\t\t\t\t";
    for (int i = 0; i < elements; i++) 
    {
        std::cout << "|";
        if (i == arrowCorX) {
            std::cout << arrowSymbol;
        }
        else {
            std::cout << " ";
        }
    }
    std::cout << "|\n\t\t\t\t";
    for (int i = 0; i < elements; i++)
    {
        std::cout << "|";
        std::cout << lockId[i];
    }
    std::cout << "|\n";
}

void ResetLock() 
{
    for (int i = 0; i < elements; i++)
    {
        lockId[i] = 'A';
    }
}

void GetInput() {
    char userInput;
    switch (userInput = _getch())
    {
    case KEY_UP: case 'w': case 'W':
        if (lockId[arrowCorX] < 65 + 25) {
            lockId[arrowCorX]++;
        }
        break;

    case KEY_DOWN: case 's': case 'S':
        if (lockId[arrowCorX] > 65)
        {
            lockId[arrowCorX]--;
        }
        break;

    case KEY_LEFT: case 'a': case 'A':
        if (arrowCorX > 0)
        {
            arrowCorX--;
        }
        break;

    case KEY_RIGHT: case 'd': case 'D':
        if (arrowCorX < elements - 1)
        {
            arrowCorX++;
        }
        break;

    default:
        break;
    }
}

void CheckPassword() 
{
    int correctLetters{0};
    for (int i = 0; i < elements; i++) {
        if (lockId[i] == password[i]) {
            correctLetters++;
        }
    }
    if (correctLetters == elements) {
        correctPassword = true;
    }
}

int main()
{
    ResetLock();
    do
    {
        Draw();
        GetInput();
        CheckPassword();
        system("cls");
    } while (!correctPassword);

    std::cout << "You entered the correct password!\n";
    return 0;
}