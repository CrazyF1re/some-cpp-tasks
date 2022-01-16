#include <iostream>.
bool check(char ** t)
{
    if (t[2][3] == t[2][7] and t[2][3] == t[2][11] and (int(t[2][3])+ int(t[2][7])+ int(t[2][11]))!=96) return 1;
    if (t[4][3] == t[4][7] and t[4][3] == t[4][11] and(int(t[4][3]) + int(t[4][7]) + int(t[4][11])) != 96)return 1; 
    if (t[6][3] == t[6][7] and t[6][3] == t[6][11] and (int(t[6][3]) + int(t[6][7]) + int(t[6][11])) != 96) return 1;
    if (t[2][3] == t[4][3] and t[4][3] == t[6][3] and (int(t[2][3]) + int(t[4][3]) + int(t[6][3])) != 96) return 1;
    if (t[2][7] == t[4][7] and t[4][7] == t[6][7] and (int(t[2][7]) + int(t[4][7]) + int(t[6][7])) != 96) return 1;
    if (t[2][11] == t[4][11] and t[4][11] == t[6][11] and (int(t[2][11]) + int(t[4][11]) + int(t[6][11])) != 96)   return 1;
    if (t[2][3] == t[4][7] and t[4][7] == t[6][11] and (int(t[2][3]) + int(t[4][7]) + int(t[6][11])) != 96)   return 1;
    if (t[6][3] == t[4][7] and t[4][7] == t[2][11] and (int(t[6][3]) + int(t[4][7]) + int(t[2][11])) != 96)   return 1;
    return 0;
}
void draw(char** field) 
{
    system("cls");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 14; j++) 
        {
            std::cout << field[i][j];
        }
        std::cout << std::endl;
    }
}
void logic(char** field) 
{
    char move[1][2] = {};
    bool next = 1;// check if someone won
    bool who_is_next = 1; // 1 - next is [X] 0 - next is [O]
    int i = 0;//check number of moves
    while (next && i<9)
    {
        if (who_is_next) 
        {
            std::cout << "Turn of tic[X]: ";
            std::cin >> move[0][0];
            std::cin >> move[0][1];
            bool k = true;
            if (field[(int(move[0][1]) - 48) * 2][(int(move[0][0]) - 64) * 4 - 1] == ' ')
            {
                k = 0;
                field[(int(move[0][1]) - 48) * 2][(int(move[0][0]) - 64) * 4 - 1] = 'X';
            }
            else 
            {
                while (k)
                {
                    std::cout << "Wrong move, make another one: ";
                    std::cin >> move[0][0];
                    std::cin >> move[0][1];
                    if (field[(int(move[0][1]) - 48) * 2][(int(move[0][0]) - 64) * 4 - 1] == ' ')
                    {
                        k = 0;
                        field[(int(move[0][1]) - 48) * 2][(int(move[0][0]) - 64) * 4 - 1] = 'X';
                    }
                }
            }

        }
        else 
        {
            std::cout << "Turn of tac[O]: ";
            std::cin >> move[0][0];
            std::cin >> move[0][1];
            bool k = true;
            if (field[(int(move[0][1]) - 48) * 2][(int(move[0][0]) - 64) * 4 - 1] == ' ')
            {
                k = 0;
                field[(int(move[0][1]) - 48) * 2][(int(move[0][0]) - 64) * 4 - 1] = 'O';
            }
            else
            {
                while (k)
                {
                    std::cout << "Wrong move, make another one: ";
                    std::cin >> move[0][0];
                    std::cin >> move[0][1];
                    if (field[(int(move[0][1]) - 48) * 2][(int(move[0][0]) - 64) * 4 - 1] == ' ')
                    {
                        k = 0;
                        field[(int(move[0][1]) - 48) * 2][(int(move[0][0]) - 64) * 4 - 1] = 'O';
                    }
                }
            }
        }
        i++;
        draw(field);
        if (check(field))
        {
            if (who_is_next) std::cout << "Tic won [X]";
            else std::cout << "Tic won [O]";
            next = !next;
            break;
        }
        who_is_next = !who_is_next;
    }
    if (next) std::cout << "Draw";
}
int main()
{
    char row0[] = { ' ',' ',' ','A',' ',' ',' ','B',' ',' ',' ',' C',' ',' ' };
    char row1[] = { ' ',char(0xC9),char(0xCD),char(0xCD),char(0xCD),char(0xCB),char(0xCD),char(0xCD),char(0xCD),char(0xCB),char(0xCD),char(0xCD),char(0xCD),char(0xBB) };
    char row2[] = { '1' ,char(0xBA),' ',' ',' ',char(0xBA),' ',' ',' ',char(0xBA),' ',' ',' ',char(0xBA) };
    char row3[] = { ' ',char(0xCC),char(0xCD),char(0xCD),char(0xCD),char(0xCE),char(0xCD),char(0xCD),char(0xCD),char(0xCE),char(0xCD),char(0xCD),char(0xCD),char(0xB9) };
    char row4[] = { '2',char(0xBA),' ',' ',' ',char(0xBA),' ',' ',' ',char(0xBA),' ',' ',' ',char(0xBA) };
    char row5[] = { ' ',char(0xCC),char(0xCD),char(0xCD),char(0xCD),char(0xCE),char(0xCD),char(0xCD),char(0xCD),char(0xCE),char(0xCD),char(0xCD),char(0xCD),char(0xB9) };
    char row6[] = { '3',char(0xBA),' ',' ',' ',char(0xBA),' ',' ',' ',char(0xBA),' ',' ',' ',char(0xBA) };
    char row7[] = { ' ',char(0xC8),char(0xCD),char(0xCD),char(0xCD),char(0xCA),char(0xCD),char(0xCD),char(0xCD),char(0xCA),char(0xCD),char(0xCD),char(0xCD),char(0xBC) };
    char* arr1[] = { row0,row1,row2,row3,row4,row5,row6,row7 };
    char** field = arr1;
    draw(field);
    logic(field);

}