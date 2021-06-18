// Portions you are to complete are marked with a TODO: comment.
// We've provided some incorrect return statements (so indicated) just
// to allow this skeleton program to compile and run, albeit incorrectly.
// The first thing you probably want to do is implement the trivial
// functions (marked TRIVIAL).  Then get City::display going.  That gives
// you more flexibility in the order you tackle the rest of the functionality.
// As you finish implementing each TODO: item, remove its TODO: comment.

#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
using namespace std;

// Manifest constants

const int MAXROWS = 20;      // max number of rows in a city
const int MAXCOLS = 40;      // max number of columns in a city
const int MAXWITCHES = 160;  // max number of witches allowed

const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;
const int NUMDIRS = 4;

///////////////////////////////////////////////////////////////////////////
// Type definitions
///////////////////////////////////////////////////////////////////////////

class City;  // This is needed to let the compiler know that City is a
             // type name, since it's mentioned in the Witch declaration.

class Witch
{
public:
    // Constructor
    Witch(City* cp, int r, int c);

    // Accessors
    int  row() const;
    int  col() const;

    // Mutators
    void move();

private:
    City* m_city;
    int   m_row;
    int   m_col;
};

class Player
{
public:
    // Constructor
    Player(City* cp, int r, int c);

    // Accessors
    int  row() const;
    int  col() const;
    int  age() const;
    bool isDead() const;

    // Mutators
    void stand();
    void move(int dir);
    bool tossBalloon(int dir);
    void setDead();

private:
    City* m_city;
    int   m_row;
    int   m_col;
    int   m_age;
    bool  m_dead;
};

class City
{
public:
    // Constructor/destructor
    City(int nRows, int nCols);
    ~City();

    // Accessors
    int     rows() const;
    int     cols() const;
    Player* player() const;
    int     witchCount() const;
    int     numWitchesAt(int r, int c) const;
    void    display(string msg) const;

    // Mutators
    bool    addWitch(int r, int c);
    bool    addPlayer(int r, int c);
    bool    meltWitch(int r, int c);
    bool    moveWitches();

private:
    int     m_rows;
    int     m_cols;
    Player* m_player;
    Witch* m_witches[MAXWITCHES];
    int     m_nWitches;
};

class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nWitches);
    ~Game();

    // Mutators
    void play();

private:
    City* m_city;
};

///////////////////////////////////////////////////////////////////////////
//  Auxiliary function declarations
///////////////////////////////////////////////////////////////////////////

int decodeDirection(char dir);
int randInt(int min, int max);
void clearScreen();

///////////////////////////////////////////////////////////////////////////
//  Witch implementation
///////////////////////////////////////////////////////////////////////////

Witch::Witch(City* cp, int r, int c)
{
    if (cp == nullptr)
    {
        cout << "***** A witch must be created in some City!" << endl;
        exit(1);
    }
    if (r < 1 || r > cp->rows() || c < 1 || c > cp->cols())
    {
        cout << "***** Witch created with invalid coordinates (" << r << ","
            << c << ")!" << endl;
        exit(1);
    }
    m_city = cp;
    m_row = r;
    m_col = c;
}

int Witch::row() const
{
    return m_row;
}

int Witch::col() const
{
    // TODO: TRIVIAL:  Return the number of the column the witch is at.
    return m_col;  // Replace this incorrect line with the correct code.
}

void Witch::move()
{
    int cr = m_row; //the current row 
    int cc = m_col; //the current col
    // Attempt to move in a random direction;  if we can't move, don't move.
    switch (randInt(0, NUMDIRS - 1))
    {
    case UP:
        if (cr == 1)
        {
            m_row =m_row;
            break;
        }
        else
        {
            m_row--;
            break;
        }
        // if statements with negation to see if game allows movemeent based on m_col and m_rows also if player is not there, use pointers
       // if(!(// TODO:  Move the witch up one row if possible.
    case DOWN:
        if (cr==m_city->rows())
        {
           m_row=m_row;
            break;
        }
        else
        {
            m_row++;
            break;
        }
    case LEFT:
        if (cc==1)
        {
            m_col=m_col;
            break;
        }
        else
        {
            m_col--;
        }
    case RIGHT:
        if (cc==m_city->cols())
        {
           m_col=m_col;
            break;
        }
        else
        {
            m_col++;
            break;
        }
    }
}

///////////////////////////////////////////////////////////////////////////
//  Player implementations
///////////////////////////////////////////////////////////////////////////

Player::Player(City* cp, int r, int c)
{
    if (cp == nullptr)
    {
        cout << "***** The player must be created in some City!" << endl;
        exit(1);
    }
    if (r < 1 || r > cp->rows() || c < 1 || c > cp->cols())
    {
        cout << "**** Player created with invalid coordinates (" << r
            << "," << c << ")!" << endl;
        exit(1);
    }
    m_city = cp;
    m_row = r;
    m_col = c;
    m_age = 0;
    m_dead = false;
}

int Player::row() const
{
    // TODO: TRIVIAL:  Return the number of the row player is at.
    return m_row;  // Replace this incorrect line with the correct code.
}

int Player::col() const
{
    // TODO: TRIVIAL:  Return the number of the column the player is at.
    return m_col;  // Replace this incorrect line with the correct code.
}

int Player::age() const
{
    // TODO: TRIVIAL:  Return the player's age.
    return m_age;  // Replace this incorrect line with the correct code.
}

void Player::stand()
{
    m_age++;
}

void Player::move(int dir)
{
    m_age++;
    int cr = m_row; //the current row 
    int cc = m_col; //the current col

    // Attempt to move in the indicated direction; if we can't move, don't move
    switch (dir)
    {
    case UP:
        if (cr == 1)
        {
            m_row= m_row;
            break;
        }
        else
        {
            m_row--;
            break;
        }
        // if statements with negation to see if game allows movemeent based on m_col and m_rows also if player is not there, use pointers
       // if(!(// TODO:  Move the witch up one row if possible.
    case DOWN:
        if (cr == m_city->rows())
        {
            m_row = m_row;
            break;
        }
        else
        {
            m_row++;
            break;
        }
    case LEFT:
        if (cc== 1)
        {
            m_col = m_col;
            break;
        }
        else
        {
            m_col--;
            break;
        }
    case RIGHT:
        if (cc == m_city->cols())
        {
            m_col = m_col;
            break;
        }
        else
        {
            m_col++;
            break;
        }
    }
}

bool Player::tossBalloon(int dir)
{
    m_age++;
    int r = row();
    int i = col();

    if (randInt(1, 3) > 1)  // replace with 1 // miss with 2/3 probability
        return false;
    else //did not miss
    {
        switch (dir)
        {
        case UP:
            if (i>=1 && i<=m_city->cols()&& (r-1)>=1 && (r-1)<=m_city->rows())
            //if (m_city->possibledir(m_row - 1, m_col))
            {
              
                for (int k = row() - 1; k > 0; k--)
                {
                    if (m_city->numWitchesAt(k, i) > 0)
                    {
                        m_city->meltWitch(k, i);
                        return true;
                        break;
                    }

                }
            }
            else break;
        case DOWN:
            if (i >= 1 && i <= m_city->cols() && (r + 1) >= 1 && (r + 1) <= m_city->rows())
            ///if (m_city->possibledir(m_row + 1, m_col))
            {
                //  int i = col();
                for (int k = 0; k < m_city->rows(); k++)
                {
                    if (m_city->numWitchesAt(k, i) > 0)
                    {
                        m_city->meltWitch(k, i);
                        return true;
                        break;
                    }

                }
            }
            else break;
        case LEFT:
            // int r = row();
            if ((i-1) >= 1 && (i-1 )<= m_city->cols() && r>= 1 &&  r <= m_city->rows())
             //if (m_city->possibledir(m_row, m_col - 1))
        {
            for (int k = col() - 1; k > 0; k--)
            {
                if (m_city->numWitchesAt(r, k) > 0)
                {
                    m_city->meltWitch(r, k);
                    return true;
                    break;
                }
            }
        }
        break;
        case RIGHT:
           
               //if (m_city->possibledir(m_row, m_col + 1)) //numWitchesAt(m_row, m_col + 1) == 0)
            if (i+1 >= 1 && (i+1) <= m_city->cols() && r >= 1 && r <= m_city->rows())
            for (int k = col(); k <= m_city->cols(); k++)
            {
                if (m_city->numWitchesAt(r, k) > 0)
                {
                    m_city->meltWitch(r, k);
                    return true;
                    break;
                }
            }

            break;
        }
    }

    // TODO:  Melt the nearest witch in direction dir
    return false;
}

bool Player::isDead() const
{
    if (m_dead == true)
    {
        return true;
    }
    else //if else statement with bools// TODO: TRIVIAL:  Return whether the player is dead.
        return false;  // Replace this incorrect line with the correct code.
}

void Player::setDead()
{
    m_dead = true;
}

///////////////////////////////////////////////////////////////////////////
//  City implementations
///////////////////////////////////////////////////////////////////////////

City::City(int nRows, int nCols)
{
    if (nRows <= 0 || nCols <= 0 || nRows > MAXROWS || nCols > MAXCOLS)
    {
        cout << "***** City created with invalid size " << nRows << " by "
            << nCols << "!" << endl;
        exit(1);
    }
    m_rows = nRows;
    m_cols = nCols;
    m_player = nullptr;
    m_nWitches = 0;
}

City::~City()
{
    delete m_player;
    // delete any witches that had not been deleted
    // (if player loses the game or quits early)
    for (int i = 0; i < m_nWitches; i++)
    {
        delete m_witches[i];
    }
}

int City::rows() const
{
    // TODO: TRIVIAL: Return the number of rows in the city.
    return m_rows;  // Replace this incorrect line with the correct code.
}

int City::cols() const
{
    // TODO: TRIVIAL: Return the number of columns in the city.
    return m_cols;  // Replace this incorrect line with the correct code.
}


//bool City::possibledir(int r, int c)const
//{
//    if (c >= 1 && c <= m_cols && r >= 1 && r <= m_rows)
//    {
//        return true;
//
//    }
//    return false;
//}

Player* City::player() const
{
    return m_player;
}


int City::witchCount() const
{
    return m_nWitches;
}

int City::numWitchesAt(int r, int c) const
{
    int witches_here = 0;
    for (int k = 0; k < m_nWitches; k++)
    {
        if (m_witches[k]->row() == r && m_witches[k]->col() == c) // checks if theres a witch at (r,c) if so adds 1
        {
            witches_here++;
        }
    }
    // TODO:  Return the number of witches at row r, column c.
    return  witches_here;  // Replace this incorrect line with the correct code.
}

void City::display(string msg) const
{
    // Position (row,col) in the city coordinate system is represented in
    // the array element grid[row-1][col-1]
    char grid[MAXROWS][MAXCOLS];
    int r, c;

    // Fill the grid with dots
    for (r = 0; r < rows(); r++)
        for (c = 0; c < cols(); c++)
            grid[r][c] = '.';

    for (int k = 0; k < rows(); k++)
        for (int i = 0; i < cols(); i++) {
            if (numWitchesAt(k +1, i + 1) == 1)
            {
                grid[k][i] = 'W';
            }
            else if (numWitchesAt(k + 1, i + 1) >= 2 && numWitchesAt(k + 1, i + 1) <= 8)
                grid[k][i] = numWitchesAt(k + 1, i + 1) + '0';
            else if (numWitchesAt(k + 1, i + 1) >= 9)
                grid[k][i] = '9';

        }

    // Indicate each witch's position
// if number of witches is exactly 1 at (r,c) chnage it to 'W'  if more change it to num of witches if greater than 9 select 9 call function how many witches here.
// TODO:  If one witch is at some position, set the char to 'W'.
//        If it's 2 through 8, set it to '2' through '8'.
//        For 9 or more, set it to '9'.

    // Indicate player's position
    if (m_player != nullptr)
    {
        // Set the char to '@', unless there's also a witch there,
        // in which case set it to '*'.
        char& gridChar = grid[m_player->row() - 1][m_player->col() - 1];
        if (gridChar == '.')
            gridChar = '@';
        else
            gridChar = '*';
    }

    // Draw the grid
    clearScreen();
    for (r = 0; r < rows(); r++)
    {
        for (c = 0; c < cols(); c++)
            cout << grid[r][c];
        cout << endl;
    }
    cout << endl;

    // Write message, witch, and player info
    cout << endl;
    if (msg != "")
        cout << msg << endl;
    cout << "There are " << witchCount() << " witches remaining." << endl;
    if (m_player == nullptr)
        cout << "There is no player." << endl;
    else
    {
        if (m_player->age() > 0)
            cout << "The player has lasted " << m_player->age() << " steps." << endl;
        if (m_player->isDead())
            cout << "The player is dead." << endl;
    }
}

bool City::addWitch(int r, int c)
{
    // If MAXWITCHES have already been added, return false.  Otherwise,
    // dynamically allocate a new witch at coordinates (r,c).  Save the
    // pointer to the newly allocated witch and return true.
    
    if (witchCount() == MAXWITCHES)
        return false;

    else
    {// adds a witch at the next available index of n_witches through dynamic memory allocation
        m_witches[m_nWitches] = new Witch(this, r, c);
        m_nWitches++; // m_nWitches also increases by 1
        return true;
    }
    // TODO:  Implement this
        // Replace this incorrect line with the correct code.
}

bool City::addPlayer(int r, int c)
{
    // Don't add a player if one already exists
    if (m_player != nullptr)
        return false;

    // Dynamically allocate a new Player and add it to the city
    m_player = new Player(this, r, c);
    return true;
}

bool City::meltWitch(int r, int c)
{
    if (numWitchesAt(r, c) == 0)
        return false;
    for (int k = 0; k < m_nWitches; k++)
    {
        if (m_witches[k]->row() == r && m_witches[k]->col() == c)
        {
            delete m_witches[k];
            m_witches[k] = m_witches[witchCount() - 1];
            m_nWitches--;
            return true;
        }
    }
    return true;
}

// TODO:  Melt one witch at row r, column c, and return true.
//        Return false is there is no witch there to destroy.

bool City::moveWitches()
{
    for (int k = 0; k < m_nWitches; k++)
    {
        // TODO:  Have the k-th witch in the city make one move.  If that
        m_witches[k]->move(); //        move results in the witch being at the same  position
        //        as the player, the player dies.
       // if (m_witches[k]->row() == this->m_player->row() && m_witches[k]->col() == this->m_player->col())
          if (m_witches[k]->row() == m_player->row() && m_witches[k]->col() == m_player->col())
            m_player->setDead();
        //return m_player->isDead();
    }

    //    if( m_witchhes[k]->// return true if the player is still alive, false otherwise
    return !m_player->isDead();
}

///////////////////////////////////////////////////////////////////////////
//  Game implementations
///////////////////////////////////////////////////////////////////////////

Game::Game(int rows, int cols, int nWitches)
{
    if (nWitches < 0)
    {
        cout << "***** Cannot create Game with negative number of witches!" << endl;
        exit(1);
    }
    if (nWitches > MAXWITCHES)
    {
        cout << "***** Trying to create Game with " << nWitches
            << " witches; only " << MAXWITCHES << " are allowed!" << endl;
        exit(1);
    }
    if (rows == 1 && cols == 1 && nWitches > 0)
    {
        cout << "***** Cannot create Game with nowhere to place the witches!" << endl;
        exit(1);
    }

    // Create city
    m_city = new City(rows, cols);

    // Add player
    int rPlayer = randInt(1, rows);
    int cPlayer = randInt(1, cols);
    m_city->addPlayer(rPlayer, cPlayer);

    // Populate with witches
    while (nWitches > 0)
    {
        int r = randInt(1, rows);
        int c = randInt(1, cols);
        // Don't put a witch where the player is
        if (r == rPlayer && c == cPlayer)
            continue;
        m_city->addWitch(r, c);
        nWitches--;
    }
}

Game::~Game()
{
    delete m_city;
}

void Game::play()
{
    string msg = "";
    m_city->display(msg);
    Player* player = m_city->player();
    if (player == nullptr)
        return;

    while (!player->isDead() && m_city->witchCount() > 0)
    {
        cout << "Move (u/d/l/r/tu/td/tl/tr/q or nothing): ";
        string action;
        getline(cin, action);
        if (action.size() == 0)
            player->stand();
        else
        {
            switch (action[0])
            {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'q':
                return;
            case 'u':
            case 'd':
            case 'l':
            case 'r':
                player->move(decodeDirection(action[0]));
                break;
            case 't':
                if (action.size() < 2)  // if no direction, nobody moves
                {
                    cout << '\a' << endl;  // beep
                    continue;
                }
                switch (action[1])
                {
                default:   // if bad direction, nobody moves
                    cout << '\a' << endl;  // beep
                    continue;
                case 'u':
                case 'd':
                case 'l':
                case 'r':
                    if (player->tossBalloon(decodeDirection(action[1])))
                        msg = "Hit!";
                    else
                        msg = "Missed!";
                    break;
                }
                break;
            }
        }
        if (!player->isDead())
            m_city->moveWitches();
        m_city->display(msg);
        msg = "";
    }
    if (player->isDead())
        cout << "You lose." << endl;
    else
        cout << "You win." << endl;
}

///////////////////////////////////////////////////////////////////////////
//  Auxiliary function implementations
///////////////////////////////////////////////////////////////////////////

int decodeDirection(char dir)
{
    switch (dir)
    {
    case 'u':  return UP;
    case 'd':  return DOWN;
    case 'l':  return LEFT;
    case 'r':  return RIGHT;

    }
    return -1;  // bad argument passed in!
}

// Return a uniformly distributed random int from min to max, inclusive
int randInt(int min, int max)
{
    if (max < min)
        swap(max, min);
    static random_device rd;
    static default_random_engine generator(rd());
    uniform_int_distribution<> distro(min, max);
    return distro(generator);
}
void doBasicTests();
void thisFunctionWillNeverBeCalled();
///////////////////////////////////////////////////////////////////////////
//  main()
///////////////////////////////////////////////////////////////////////////

int main()
{
    // Create a game
    // Use this instead to create a mini-game:   Game g(3, 3, 2);
    //Game g(15, 10, 6);

    // Play the game
    //g.play();
   doBasicTests(); // Remove this line after completing test.
    return 0;       // Remove this line after completing test.
}

///////////////////////////////////////////////////////////////////////////
//  clearScreen implementation
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++/g31 UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.  (The Xcode output window doesn't have the capability
// of being cleared.)

#ifdef _WIN32

#pragma warning(disable : 4005)
#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
        &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not _WIN32

#include <iostream>
#include <cstring>
#include <cstdlib>

void clearScreen()  // will just write a newline in an Xcode output window
{
    static const char* term = getenv("TERM");
    if (term == nullptr || strcmp(term, "dumb") == 0)
        cout << endl;
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif
#include <type_traits>
#include <cassert>

#define CHECKTYPE(c, f, r, a)  \
    static_assert(std::is_same<decltype(&c::f), r (c::*)a>::value, \
       "FAILED: You changed the type of " #c "::" #f);  \
    [[gnu::unused]] auto xxx##c##_##f = static_cast<r(c::*)a>(&c::f)

void thisFunctionWillNeverBeCalled()
{
    // If the student deleted or changed the interfaces to the public
    // functions, this won't compile.  (This uses magic beyond the scope
    // of CS 31.)

    Witch(static_cast<City*>(0), 1, 1);
    CHECKTYPE(Witch, row, int, () const);
    CHECKTYPE(Witch, col, int, () const);
    CHECKTYPE(Witch, move, void, ());

    Player(static_cast<City*>(0), 1, 1);
    CHECKTYPE(Player, row, int, () const);
    CHECKTYPE(Player, col, int, () const);
    CHECKTYPE(Player, age, int, () const);
    CHECKTYPE(Player, isDead, bool, () const);
    CHECKTYPE(Player, stand, void, ());
    CHECKTYPE(Player, move, void, (int));
    CHECKTYPE(Player, tossBalloon, bool, (int));
    CHECKTYPE(Player, setDead, void, ());

    City(1, 1);
    CHECKTYPE(City, rows, int, () const);
    CHECKTYPE(City, cols, int, () const);
    CHECKTYPE(City, player, Player*, () const);
    CHECKTYPE(City, witchCount, int, () const);
    CHECKTYPE(City, numWitchesAt, int, (int, int) const);
    CHECKTYPE(City, display, void, (string) const);
    CHECKTYPE(City, addWitch, bool, (int, int));
    CHECKTYPE(City, addPlayer, bool, (int, int));
    CHECKTYPE(City, meltWitch, bool, (int, int));
    CHECKTYPE(City, moveWitches, bool, ());

    Game(1, 1, 1);
    CHECKTYPE(Game, play, void, ());
}

void doBasicTests()
{
    {
        City walk(10, 20);
        assert(walk.addPlayer(2, 6));
        Player* pp = walk.player();
        assert(pp->row() == 2 && pp->col() == 6 && !pp->isDead());
        pp->move(UP);
        assert(pp->row() == 1 && pp->col() == 6 && !pp->isDead());
        pp->move(UP);
        assert(pp->row() == 1 && pp->col() == 6 && !pp->isDead());
        pp->setDead();
        assert(pp->row() == 1 && pp->col() == 6 && pp->isDead());
    }
    {
        City ofAngels(2, 2);
        assert(ofAngels.addPlayer(1, 1));
        assert(ofAngels.addWitch(2, 2));
        Player* pp = ofAngels.player();
        assert(ofAngels.moveWitches());
        assert(!pp->isDead());
        for (int k = 0; k < 1000 && ofAngels.moveWitches(); k++)
            assert(ofAngels.numWitchesAt(1, 1) == 0);
       assert(pp->isDead() && ofAngels.numWitchesAt(1, 1) == 1);
    }
    {
        City ousDarth(1, 40);
        assert(ousDarth.addPlayer(1, 1));
        assert(ousDarth.addWitch(1, 37));
        assert(ousDarth.addWitch(1, 40));
        assert(ousDarth.addWitch(1, 39));
        assert(ousDarth.addWitch(1, 36));
        assert(ousDarth.addWitch(1, 40));
        assert(ousDarth.addWitch(1, 38));
        assert(ousDarth.witchCount() == 6 && ousDarth.numWitchesAt(1, 40) == 2);
        Player* pp = ousDarth.player();
        for (int k = 0; k < 1000 && ousDarth.witchCount() != 0; k++)
            pp->tossBalloon(RIGHT);
        assert(ousDarth.witchCount() == 0);
        assert(ousDarth.addWitch(1, 40));
        for (int k = 0; k < 38; k++)
        {
            ousDarth.moveWitches();
            pp->stand();
        }
        assert(ousDarth.witchCount() == 1);
        // If the program crashes after leaving this compound statement, you
        // are probably messing something up when you delete a melted Witch
        // (or you have mis-coded the destructor).
        //
        // Draw a picture of your m_witches array before tossing any balloons
        // and also note the values of m_nWitches or any other variables you
        // might have that are involved with the number of Witches.  Trace
        // through your code step by step as the Witches are melted and
        // removed, updating the picture according to what the code says, not
        // what you want it to do.  If you don't see a problem then, try
        // tracing through the destruction of the city.
        //
        // If you execute the code, use the debugger to check on the values
        // of key variables at various points.  If you didn't try to learn
        // to use the debugger, insert statements that write the values of
        // key variables to cerr so you can trace the execution of your code
        // and see the first place where something has gone amiss.  (Comment
        // out the call to clearScreen in City::display so that your output
        // doesn't disappear.)
    }
    cout << "Passed all basic tests" << endl;
}