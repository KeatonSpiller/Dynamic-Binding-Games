// CS 302 Winter 2024
// Keaton Spiller
// Prog 3 Header file

/** What Is In This Assignment?
    Dynamic Binding
    three derived classes
    exception handling
    smart pointers
*/

/**      {} Hierarchy Visual {}
    
              Abstract Game
                  (base)
            /       |       \
    Video_Game  Card_Game  Board_Game
                    ^
                    : 
                    :
   Node ("has-an" (*base)
                    ^
                    : 
                    :
  2-3 Balanced Tree("has-a" root of Node)    */


# pragma once // Run Header Once

# include <iostream>
# include <vector>
# include <string>
# include <list>
# include <cstring>
# include <cstdlib>
# include <stdexcept>
# include <memory>

using std::string, std::vector;                                    // Containers
using std::cin, std::cout, std::ostream, std::istream, std::endl;  // IO Stream
using std::stoi, std::stof;                                        // Type Cast
using std::rand, std::srand;                                       // Randomization
using std::shared_ptr, std::make_shared;                           // Smart Ptr
using std::exception;                                              // Exceptions

//**********************************************************************************
class Game
{
    public:

        /** Constructor
            Input: New Game object
            Output: Empty Game Object
        */
        Game();


        /** Parametric Constructor
            Input:  Game data members
            Output: Filled Game Object
        */
        Game(string src_name, 
             string src_genre, 
             string src_rules, 
             string src_mode,
             int src_difficulty);


        /** Copy Constructor
            Input:  Game Object
            Output: Filled Game Object
        */
        Game(const Game & src);


        /** Deconstructor
            Input: End of Game Object lifespan
            Output: Deallocation of Dynamic Memory
        */
        virtual ~Game();


        /** Assignment
            Input:  obj1 = obj2
            Output: fill obj1 with data from obj2
        */
        Game & operator = (const Game & src); // obj1 == obj2


        /** !=
            Input: obj != op2
            Output: true / false
        */
        friend int operator ! (const Game & op1);


        /** I/O (<<)
            Input: cout << op2
            Output: ostream && print to screen
        */
        friend ostream & operator << (ostream & out, const Game & op2);


        /** I/O (>>)
            Input: cin >> op2
            Output: istream and op2 filled
        */
        friend istream & operator >> (istream & in, Game & op2);


        /** greater than
            Input: op1 > op2
            Output: bool true/false
                op1.name > op2.name && op1.difficulty > op2.difficulty
        */
        friend int operator > (const Game & op1, const Game & op2);


        /** greater than equal to
            Input: op1 >= op2
            Output: bool true/false
                op1.name >= op2.name && op1.difficulty >= op2.difficulty
        */
        friend int operator >= (const Game & op1, const Game & op2);


        /** less than
            Input: op1 < op2
            Output: bool true/false
                //op1.name < op2.name && op1.difficulty < op2.difficulty
                op1.difficulty < op2.difficulty
        */
        friend int operator < (const Game & op1, const Game & op2);


        /** less than equal to
            Input: op1 <= op2
            Output: bool true/false
                op1.name <= op2.name && op1.difficulty <= op2.difficulty
        */
        friend int operator <= (const Game & op1, const Game & op2);


        /** equivalent
            Input: obj == op2
            Output: true / false
                op1.name == op2.name && op1.difficulty == op2.difficulty
        */
        friend int operator == (const Game & op1, const Game & op2);


        /** Display // 1 pure virtual
            Input:  obj & null arguments
            Output: cout to screen data members
        */
        virtual int display() const;


        /** input data from user
            Input:  obj & null argument
            Output: fill Game Object with user prompts
        */
        virtual int input();


        /** string empty non virtual
            Input:  obj and null argument
            Output: 0/1 if name is empty or not
        */
        int empty() const;


        /** string empty non virtual
            Input:  obj and null argument
            Output: 0/1 if name is empty or not
        */
        int compare() const;


        /** display ascii representation of data members (1 pure virtual)
            Input:  obj & null argument
            Output: cout ascii values of data members
        */
        virtual void display_ascii() const = 0;

    protected:
        string name;
        string genre;
        string rules;
        string mode;
        int difficulty;
};


//**********************************************************************************
class Board_Game: public Game
{
    public:

        /** Constructor
            Input: New Game object
            Output: Empty Game Object
        */
        Board_Game();


        /** Parametric Constructor
            Input: Board Game Objects
            Output: Empty Game Object
        */
        Board_Game(string src_name, 
                   string src_genre, 
                   string src_rules, 
                   string src_mode,
                   int src_difficulty,
                   int src_dice_size,
                   int src_position);


        /** Copy Constructor
            Input:  Game Object
            Output: Filled Game Object
        */
        Board_Game(const Board_Game & src);


        /** Deconstructor
            Input: End of Game Object lifespan
            Output: Deallocation of Dynamic Memory
        */
        ~Board_Game();


        /** Assignment
            Input:  obj1 = obj2
            Output: fill obj1 with data from obj2
        */
        Board_Game & operator = (const Board_Game & src); // obj1 == obj2


        /** I/O (<<)
            Input: cout << op2
            Output: ostream && print to screen
        */
        friend ostream & operator << (ostream & out, const Board_Game & op2);


        /** I/O (>>)
            Input: cin >> op2
            Output: istream and op2 filled
        */
        friend istream & operator >> (istream & in, Board_Game & op2);

        /** input data from user
            Input:  obj & null argument
            Output: fill Game Object with user prompts
        */
        int input();

        /** Display
            Input:  obj & null arguments
            Output: cout to screen data members and inheriting display
        */
        int display() const;


        /** display ascii representation of data members (1 pure virtual)
            Input:  obj & null argument
            Output: cout ascii values of data members
        */
        void display_ascii() const;


    protected:
        int dice_size;
        int position;
};


//**********************************************************************************
class Card_Game: public Game
{
    public:

        /** Constructor
            Input: New Game object
            Output: Empty Game Object
        */
        Card_Game();


        /** Parametric Constructor
            Input: Card Game Objects
            Output: Empty Game Object
        */
        Card_Game(string src_name, 
                   string src_genre, 
                   string src_rules, 
                   string src_mode,
                   int src_difficulty,
                   int src_deck_size,
                   int src_hand_size);


        /** Copy Constructor
            Input:  Game Object
            Output: Filled Game Object
        */
        Card_Game(const Card_Game & src);


        /** Deconstructor
            Input: End of Game Object lifespan
            Output: Deallocation of Dynamic Memory
        */
        ~Card_Game();


        /** Assignment
            Input:  obj1 = obj2
            Output: fill obj1 with data from obj2
        */
        Card_Game & operator = (const Card_Game & src); // obj1 == obj2


        /** I/O (<<)
            Input: cout << op2
            Output: ostream && print to screen
        */
        friend ostream & operator << (ostream & out, const Card_Game & op2);


        /** I/O (>>)
            Input: cin >> op2
            Output: istream and op2 filled
        */
        friend istream & operator >> (istream & in, Card_Game & op2);


        /** input data from user
            Input:  obj & null argument
            Output: fill Game Object with user prompts
        */
        int input();


        /** Display
            Input:  obj & null arguments
            Output: cout to screen data members and inheriting display
        */
        int display() const;


        /** display ascii representation of data members (1 pure virtual)
            Input:  obj & null argument
            Output: cout ascii values of data members
        */
        void display_ascii() const; // pure virtual

    protected:
        int deck_size;
        int hand_size;
};


class Video_Game: public Game
{
    public:

        /** Constructor
            Input: New Game object
            Output: Empty Game Object
        */
        Video_Game();


        /** Parametric Constructor
            Input: Video Game Objects
            Output: Empty Game Object
        */
        Video_Game(string src_name, 
                   string src_genre, 
                   string src_rules, 
                   string src_mode,
                   int src_difficulty,
                   string src_platform,
                   string src_developers);


        /** Copy Constructor
            Input:  Game Object
            Output: Filled Game Object
        */
        Video_Game(const Video_Game & src);


        /** Deconstructor
            Input: End of Game Object lifespan
            Output: Deallocation of Dynamic Memory
        */
        ~Video_Game();


        /** Assignment
            Input:  obj1 = obj2
            Output: fill obj1 with data from obj2
        */
        Video_Game & operator = (const Video_Game & src); // obj1 == obj2


        /** I/O (<<)
            Input: cout << op2
            Output: ostream && print to screen
        */
        friend ostream & operator << (ostream & out, const Video_Game & op2);


        /** I/O (>>)
            Input: cin >> op2
            Output: istream and op2 filled
        */
        friend istream & operator >> (istream & in, Video_Game & op2);

        /** input data from user
            Input:  obj & null argument
            Output: fill Game Object with user prompts
        */
        int input();

        /** Display
            Input:  obj & null arguments
            Output: cout to screen data members and inheriting display
        */
        int display() const;


        /** display ascii representation of data members (1 pure virtual)
            Input:  obj & null argument
            Output: cout ascii values of data members
        */
        void display_ascii() const; // pure virtual

    protected:
        string platform;
        string developers;
};

//**********************************************************************************

/**
2-3 Tree Node
           [<, >=]
less     in-between  greater-than  
[<, >=]    [<, >=]     [<, >=]
*/
class Node
{
    public:
        
        /** Constructor
            Input: New Game object
            Output: Empty Game Object
        */
        Node();

        /** Deconstructor
            Input: End of Node lifespan
            Output: Deallocate Dynamic Memory
        */
        ~Node();
        
        /** data getter
            Input: Get the data to manipulate in the Tree class
            Output: Game object to manipulate
        */
        Game *& get_left_data();

        /** data getter
            Input: Get the data to manipulate in the Tree class
            Output: Game object to manipulate
        */
        Game *& get_right_data();
        
        /** downcasting to set the derived object within the base pointer
            Input: Node object and base ptr
            Output: Set Data members of derived class base pointer is pointing
        */
        int set_left_data(Game * game);

        /** downcasting to set the derived object within the base pointer
            Input: Node object and base ptr
            Output: Set Data members of derived class base pointer is pointing
        */
        int set_right_data(Game * game);

        /** set the pointer to a Node
            Input: Node
            Output: success / failure
        */
        int set_left(Node * to_set);

        /** set the pointer to a Node
            Input: Node
            Output: success / failure
        */
        int set_middle(Node * to_set);

        /** set the pointer to a Node
            Input: Node
            Output: success / failure
        */
        int set_right(Node * to_set);


        /** Node getter
            Input: Get the Node to manipulate in the Tree class
            Output: Node to manipulate
        */
        Node *& get_left();

        /** Node getter
            Input: Get the Node to manipulate in the Tree class
            Output: Node to manipulate
        */
        Node *& get_middle();

        /** Node getter
            Input: Get the Node to manipulate in the Tree class
            Output: Node to manipulate
        */
        Node *& get_right();


    protected:
        Node * left;
        Node * middle;
        Node * right;
        Game * ldata;
        Game * rdata;
};


/**
1. push up
2. data in node
3. children  (<, inbetween, > {current root})
[ 2-3 Tree ]
*/
class Tree
{
    public:
        Tree();
        ~Tree();

        /** insert into the 2-3 Tree Wrapper
            Input:  Tree obj and game* with derived object data to insert
            Output: insert from the root of the tree in sorted order
                1. If game is null return
                2. if root is null fill first node
                3. recursively call the tree
        */
        int insert(Game * game);
    
        /** remove from 2-3 Tree Wrapper
            Input: Tree object and null argument
            Output: head recursively delete from the tree
        */
        int remove_all();


        /** Display All Nodes in Tree including levels and max height Wrapper
            Input: Tree object to display
            Output: Display Nodes of Tree
        */
        int display() const;


        /** Utilize friend operators in base class to compare
            Input: Tree object and two object to compare
            Output:
                1 for less than
                2 for duplicate
                0 for >=
        */
        int compare(const Game & obj1, const Game & obj2);


        /** display Duplicates into a shared array
            Input: Tree object null argument
            Output: success or failure display of duplicates
        */
        int display_duplicates();


    protected:
        Node * root;
        vector<shared_ptr<Game*>> duplicates;
       

        /** Store Duplicates into a shared array
            Input: Tree object and Detected duplicate from comparison function
            Output: success or failure
        */
        int store_duplicates(Game & game);


        /** insert into the 2-3 Tree recursive traversal
            Input:  Tree obj, current Node to check, game* derived to insert
            Output: insert from the root of the tree in sorted order
                1. If game is null return
                2. if Node is null then fill 
                3. two data filled case
                    a. no children
                        i.  push up if can
                        ii. push down if can
                    b. smaller than left  recursive call left
                       i. push up if can
                    c. smaller than right recusive call right
                    d. in between
                        i.  push up if can
                        ii. recursive call middle
                4. one data filled case
                    a. smaller than ldata
                        i. left subtree
                            a. either insert and swap which is larger
                            b. recursively call insert left subtree
                            c. add middle node
                    b. larger than ldata
                        i. right subtree
                            a. either insert and swap which is larger
                            b. recursively call insert right subtree
                            c. add middle node
        */
        int insert(Node *& src, Game * to_add);

        /** Display All Nodes in Tree including levels and max height recursive
            Input: Tree object and src
            Output: Display Nodes of Tree
                uses inorder_traverse and height
        */
        int display_node(Node * src) const;


        /** Traverse the Tree in order ascending to descending
            Input: Tree object and src
            Output: Display Nodes of Tree
         1. tranferse left
         2. print
           - print(right)
           - traverse middle
           - print(left)
         4. traverse right
        */
        int inorder_traverse(Node * src) const;

        /** Push up tree that is inbalanced
            Input: Tree object to push up and node to add
            Output: rebalanced tree
        */
        int push_up(Node * src, Game * to_add);

        /** Pull Down to balance tree
            Input: Node To pull down
            Output: rebalance Tree
        */
        int push_down(Node * src);

        /** Find the Max Height from node given
            Input: Node To traverse
            Output: Max height from Node
        */
        int height(Node * src) const;

        /** remove from 2-3 Tree recursively
            Input: Tree object and null argument
            Output: head recursively delete from the tree
        */
        int remove_all(Node * src);
};


/**
User Interface Handling 
Creating Game Objects, 
Tree objects,
Options and prompts
*/
class Menu
{
    public:
        Menu();
        ~Menu();
        // Simplifying the functionality of the main User system into multiple
        // menu options
        int greetings();
        int run_program();
        int game_cases(Tree & t, Game * game);
        int prompt_game_type();
        int cin_game_type(string & activity);
        int prompt_list_options();
        int cin_list_options(string & option);
        int prompt_insert_entry();
        int outro();
};


class Exception_Handling
{
    public:
        Exception_Handling();
        ~Exception_Handling();
        // functions to try and catch any bugs that could be found in the
        // operator overloaders as we receive input and perform arithmetic
        // (overloaders don't always catch where there is a bug on their own)
        int validate_stoi(string src);
        int validate_stof(string src);
        int validate_negative(int a);
};


