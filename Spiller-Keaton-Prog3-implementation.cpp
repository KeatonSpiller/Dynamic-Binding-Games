// CS 302 Winter 2024
// Keaton Spiller
// Prog 3 Implementation

# include "Spiller-Keaton-Prog3-helper.h"
/**
    Contains The Implementation for 
    Game
    Board_Game
    Video_Game
    Card_Game
    Node
    Tree
*/

// Game base class *****************************************************************
/** Protected Data Members:
    string name; string Genre; string rules; string mode; int difficulty;
*/


/** Constructor
    Input: New Game object
    Output: Empty Game Object
*/
Game::Game():
    name(""), genre(""), rules(""), mode(""), difficulty(0) {}


/** Parametric Constructor
    Input:  Game data members
    Output: Filled Game Object
*/
Game::Game(string src_name, 
           string src_genre, 
           string src_rules, 
           string src_mode,
           int src_difficulty):
    name(src_name), genre(src_genre), rules(src_rules), mode(src_mode) {}


/** Copy Constructor
    Input:  Game Object
    Output: Filled Game Object
*/
Game::Game(const Game & src):
    name(src.name), genre(src.genre), rules(src.rules), mode(src.mode), difficulty(src.difficulty) {}


/** Virtual Deconstructor
    Input: End of Game Object lifespan
    Output: Deallocation of Dynamic Memory
*/
Game::~Game() {}


/**
    input: obj1 = obj2
    output: obj1
        1. return obj1 if the same
        2. delete obj1 if contains memory
        3. Fill obj1 with obj2 and return obj1
*/
Game & Game::operator=(const Game & src)
{
    // If Equal
    if (this == &src) return *this;

    // If Dynamic Memory *Delete Here*
    
    name = src.name;
    genre = src.genre;
    rules = src.rules;
    mode = src.mode;
    difficulty = src.difficulty;
    
    return *this;
}


/** I/O (<<)
    Input: cout << op2
    Output: ostream && print to screen
*/
ostream & operator << (ostream & out, const Game & op2)
{
    if(!op2) return out;
    op2.display();
    return out;
}


/** I/O (>>)
    Input: cin >> op2
    Output: istream and op2 filled
*/
istream & operator >> (istream & in, Game & op2)
{
    op2.input();

    return in;
}

/** !=
    Input: obj != op2
    Output: true / false
*/
int operator ! (const Game & op1)
{
    int contents = op1.empty();
    return contents;
}


/** <
    Input: obj < op2
    Output: true / false
*/
int operator < (const Game & op1, const Game & op2)
{
    cout << "name1 : " << op1.name << " name2 : " << op2.name << endl;
    cout << "difficulty1 : " << op1.difficulty << " difficulty2 : " << op2.difficulty << endl;
    // first compare by name ascii ascending
    if(op1.difficulty < op2.difficulty) return 1;
    //else if(op1.name < op2.name) return 1;
    return 0;
}


/** <=
    Input: obj <= op2
    Output: true / false
*/
int operator <= (const Game & op1, const Game & op2)
{
    // first compare by name ascii ascending
    if(op1.name <= op2.name && op1.difficulty <= op2.difficulty) return 1;
    return 0;
}


/** >
    Input: obj > op2
    Output: true / false
*/
int operator > (const Game & op1, const Game & op2)
{
    // first compare by name ascii ascending
    if(op1.name > op2.name && op1.difficulty > op2.difficulty) return 1;
    return 0;
}


/** >=
    Input: obj >= op2
    Output: true / false
*/
int operator >= (const Game & op1, const Game & op2)
{
    // first compare by name ascii ascending
    if(op1.name >= op2.name && op1.difficulty >= op2.difficulty) return 1;
    return 0;
}


/** ==
    Input: obj == op2
    Output: true / false
*/
int operator == (const Game & op1, const Game & op2)
{
    // first compare by name ascii ascending
    if(op1.name == op2.name && op1.difficulty == op2.difficulty) return 1;
    return 0;
}


/** Virtual Display
*    Input:  obj & null arguments
    Output: cout to screen data members
*/
int Game::display() const
{
    cout << "Name: "       << name       << endl;
    cout << "Genre: "      << genre      << endl;
    cout << "Rules: "      << rules      << endl;
    cout << "Mode: "       << mode       << endl;
    cout << "Difficulty: " << difficulty << endl;
    return 1;
}


/** display ascii representation of data members (1 pure virtual function )
    Input:  obj & null argument
    Output: cout ascii values of data members
*/
void Game::display_ascii() const {}


/** input data from user
    Input:  obj & null argument
    Output: fill Game Object with user prompts
*/
int Game::input()
{
    string src_name;
    string src_genre;
    string src_rules;
    string src_mode;
    int src_difficulty;

    cout << "What Is The Name?" << endl;
    cin >> src_name; 
    cout << "What Is The Genre?" << endl;
    cin >> src_genre;
    cout << "What Are The Rules?" << endl;
    cin >> src_rules;
    cout << "What Is The Game Mode? (cooperative, singleplayer, ..., )?" << endl;
    cin >> src_mode;
    cout << "What Is The Difficulty? 1 Easy | 2 Medium | 3 Diffiult" << endl;
    cin >> src_difficulty;

    name = src_name;
    genre = src_genre;
    rules = src_rules;
    mode = src_mode;
    difficulty = src_difficulty;

    return 1;
}


/** string empty non virtual
    Input:  obj and null argument
    Output: 0/1 if name is empty or not
*/
int Game::empty() const
{
    return name.empty();
}

// Board Game  *****************************************************************
/** Protected Data Members:
    int dice_size; int position;
*/


/** Constructor
    Input: New Game object
    Output: Empty Game Object
*/
Board_Game::Board_Game():
    dice_size(0), position(0) {}


/** Parametric Constructor
    Input: Board Game Objects
    Output: Empty Game Object
*/
Board_Game::Board_Game(string src_name, 
           string src_genre, 
           string src_rules, 
           string src_mode,
           int src_difficulty,
           int src_dice_size,
           int src_position):
    Game(src_name, src_genre, src_rules, src_mode, src_difficulty), // parent
    dice_size(src_dice_size), position(src_position) {}


/** Copy Constructor
    Input:  Game Object
    Output: Filled Game Object
*/
Board_Game::Board_Game(const Board_Game & src):
    Game(src), dice_size(src.dice_size), position(src.position) {}


/** Deconstructor
    Input: End of Game Object lifespan
    Output: Deallocation of Dynamic Memory
*/
Board_Game::~Board_Game() {}


/**
    input: obj1 = obj2
    output: obj1
        1. return obj1 if the same
        2. delete obj1 if contains memory
        3. Fill obj1 with obj2 and return obj1
*/
Board_Game & Board_Game::operator=(const Board_Game & src)
{
    // If Equal
    if (this == &src) return *this;
    
    // Pass Up
    Game::operator=(src);

    // If Dynamic Memory *Delete Here*
    
    dice_size = src.dice_size;
    position = src.position;
    
    return *this;
}


/** I/O (<<)
    Input: cout << op2
    Output: ostream && print to screen
*/
ostream & operator << (ostream & out, const Board_Game & op2)
{
    op2.display();
    return out;
}


/** I/O (>>)
    Input: cin >> op2
    Output: istream and op2 filled
*/
istream & operator >> (istream & in, Board_Game & op2)
{
    op2.input();
    return in;
}


/** Display
    Input:  obj & null arguments
    Output: cout to screen data members and inheriting display
*/
int Board_Game::display() const
{
    Game::display();
    cout << "Dice Size: " << dice_size << endl;
    cout << "Position: " << position << endl;
    return 1;
}


/** input data from user
    Input:  obj & null argument
    Output: fill Game Object with user prompts
*/
int Board_Game::input()
{
    Game::input();

    int src_dice_size;
    int src_position;

    cout << "What Is the Size of Dice?" << endl;
    cin >> src_dice_size; 
    cout << "What Is The Position?" << endl;
    cin >> src_position;

    dice_size = src_dice_size;
    position = src_position;

    return 1;
}


/** display ascii representation of data members (1 pure virtual)
    Input:  obj & null argument
    Output: cout ascii values of data members
*/
void Board_Game::display_ascii() const // pure virtual from base
{
    cout << "dice size: "<< dice_size << " ascii: "<< static_cast<char>(dice_size);
    cout << "position: "<< position << " ascii: "<< static_cast<char>(position);
    return;
}


// Card Game **********************************************************************
/** Protected Data Members:
    int deck_size; int hand_size; */

/** Constructor
    Input: New Game object
    Output: Empty Game Object
*/
Card_Game::Card_Game():
    deck_size(0), hand_size(0) {}


/** Parametric Constructor
    Input: Card Game Objects
    Output: Empty Game Object
*/
Card_Game::Card_Game(string src_name, 
                     string src_genre, 
                     string src_rules, 
                     string src_mode,
                     int src_difficulty,
                     int src_deck_size,
                     int src_hand_size):
    Game(src_name, src_genre, src_rules, src_mode, src_difficulty), // parent
    deck_size(src_deck_size), hand_size(src_hand_size) {}


/** Copy Constructor
    Input:  Game Object
    Output: Filled Game Object
*/
Card_Game::Card_Game(const Card_Game & src):
    Game(src), deck_size(src.deck_size), hand_size(src.hand_size) {}


/** Deconstructor
    Input: End of Game Object lifespan
    Output: Deallocation of Dynamic Memory
*/
Card_Game::~Card_Game(){}


/** Assignment
    Input:  obj1 = obj2
    Output: fill obj1 with data from obj2
*/
Card_Game & Card_Game::operator = (const Card_Game & src) // obj1 == obj2
{
    // If Equal
    if (this == &src) return *this;
    
    // Pass Up
    Game::operator=(src);

    // If Dynamic Memory *Delete Here*
    
    deck_size = src.deck_size;
    hand_size = src.hand_size;
    
    return *this;
}


/** I/O (<<)
    Input: cout << op2
    Output: ostream && print to screen
*/
ostream & operator << (ostream & out, const Card_Game & op2)
{
    op2.display();
    return out;
}


/** I/O (>>)
    Input: cin >> op2
    Output: istream and op2 filled
*/
istream & operator >> (istream & in, Card_Game & op2)
{
    op2.input();
    return in;
}


/** Display
    Input:  obj & null arguments
    Output: cout to screen data members and inheriting display
*/
int Card_Game::display() const
{
    Game::display();
    cout << "Deck Size: " << deck_size << endl;
    cout << "Hand Size: " << hand_size << endl;
    return 1;
}


/** input data from user
    Input:  obj & null argument
    Output: fill Game Object with user prompts
*/
int Card_Game::input()
{
    Game::input();

    int src_deck_size;
    int src_hand_size;

    cout << "What Is the Deck Size?" << endl;
    cin >> src_deck_size; 
    cout << "What Is The Hand Size?" << endl;
    cin >> src_hand_size;

    deck_size = src_deck_size;
    hand_size = src_hand_size;

    return 1;
}


/** display ascii representation of data members (1 pure virtual)
    Input:  obj & null argument
    Output: cout ascii values of data members
*/
void Card_Game::display_ascii() const // pure virtual from base
{
    cout << "deck size: "<< deck_size << " ascii: "<< static_cast<char>(deck_size);
    cout << "hand size: "<< hand_size << " ascii: "<< static_cast<char>(hand_size);
    return;
}


// Video Game *********************************************************************
/** Protected Data Members:
    string platform; string developers; */
    
/** Constructor
    Input: New Game object
    Output: Empty Game Object
*/
Video_Game::Video_Game():
    platform(""), developers("") {}


/** Parametric Constructor
    Input: Video Game Objects
    Output: Empty Game Object
*/
Video_Game::Video_Game(string src_name, 
                       string src_genre, 
                       string src_rules, 
                       string src_mode,
                       int src_difficulty,
                       string src_platform,
                       string src_developers):
    Game(src_name, src_genre, src_rules, src_mode, src_difficulty), // parent
    platform(src_platform), developers(src_developers) {}


/** Copy Constructor
    Input:  Game Object
    Output: Filled Game Object
*/
Video_Game::Video_Game(const Video_Game & src):
    Game(src), platform(src.platform), developers(src.developers) {}


/** Deconstructor
    Input: End of Game Object lifespan
    Output: Deallocation of Dynamic Memory
*/
Video_Game::~Video_Game(){}


/** Assignment
    Input:  obj1 = obj2
    Output: fill obj1 with data from obj2
*/
Video_Game & Video_Game::operator = (const Video_Game & src) // obj1 == obj2
{
    // If Equal
    if (this == &src) return *this;
    
    // Pass Up
    Game::operator=(src);

    // If Dynamic Memory *Delete Here*
    
    platform = src.platform;
    developers = src.developers;
    
    return *this;
}


/** I/O (<<)
    Input: cout << op2
    Output: ostream && print to screen
*/
ostream & operator << (ostream & out, const Video_Game & op2)
{
    op2.display();
    return out;
}


/** I/O (>>)
    Input: cin >> op2
    Output: istream and op2 filled
*/
istream & operator >> (istream & in, Video_Game & op2)
{
    op2.input();
    return in;
}


/** Display
    Input:  obj & null arguments
    Output: cout to screen data members and inheriting display
*/
int Video_Game::display() const
{
    Game::display();
    cout << "Platform: " << platform << endl;
    cout << "Developers: " << developers << endl;
    return 1;
}


/** input data from user
    Input:  obj & null argument
    Output: fill Game Object with user prompts
*/
int Video_Game::input()
{
    Game::input();

    string src_platform;
    string src_developers;

    cout << "What Is the Video Game Platform?" << endl;
    cin >> src_platform; 
    cout << "Who Are The Developers?" << endl;
    cin >> src_developers;

    platform = src_platform;
    developers = src_developers;

    return 1;
}


/** display ascii representation of data members (1 pure virtual)
    Input:  obj & null argument
    Output: cout ascii values of data members
*/
void Video_Game::display_ascii() const // pure virtual from base
{
    for (char p: platform)
    {
        cout << "platform: "<< p << " ascii: "<< static_cast<int>(p);
    }
    for (char d: developers)
    {
        cout << "developers: "<< d << " ascii: "<< static_cast<int>(d);
    }
    return;
}

// Node ***************************************************************************
/** Protected Data Members:
    Node * left;
    Node * right;
    unique_ptr<Game> ldata;
    unique_ptr<Game> rdata; */


/** Default Constructor
    Input:  obj & null argument
    Output: Create Game Object with empty values
*/
Node::Node():
    left(nullptr), 
    middle(nullptr),
    right(nullptr),
    ldata(nullptr),
    rdata(nullptr) {}


/** Default Deconstructor
    Input:  End of Game Object Lifespan
    Output: Deallocate Dynamic Memory
*/
Node::~Node() 
{
    if(ldata)
    {
        ldata = nullptr;
    }
    if(rdata)
    {
        rdata = nullptr;
    }
}


/** Node Getter left data
    Input:  Node to get
    Output: data of node
        unique_ptr<Game> ldata;
*/
Game *& Node::get_left_data()
{
    return ldata;
}


/** Node Getter right data
    Input:  Object of Game ptr to get
    Output: data of node
        unique_ptr<Game> rdata;
*/
Game *& Node::get_right_data()
{
    return rdata;
}


/** Node Setter left data
    Input:  Node to Set
    Output: true or false
        unique_ptr<Game> ldata;
*/
int Node::set_left(Node * to_set)
{
    if(!to_set)
    {
       left = nullptr; 
       return 0;
    }
    left = to_set;
    return 1;
}

/** Node Setter middle data
    Input:  Node to Set
    Output: true or false
        unique_ptr<Game> ldata;
*/
int Node::set_middle(Node * to_set)
{
    if(!to_set) 
    {
       middle = nullptr; 
       return 0;
    }
    middle = to_set;
    return 1;
}

/** Node Setter right data
    Input:  Node to Set
    Output: true or false
        unique_ptr<Game> rdata;
*/
int Node::set_right(Node * to_set)
{
    if(!to_set) 
    {
       right = nullptr; 
       return 0;
    }
    right = to_set;
    return 1;
}


/** Node getter left ptr to Node
    Input:  Node obj and null arguments
    Output: Node * pointer to left
*/
Node *& Node::get_left()
{
    return left;
}


/** Node getter middle ptr
    Input:  Node obj and null arguments
    Output: Node * pointer to right
*/
Node *& Node::get_middle()
{
    return middle;
}

/** Node getter right ptr to Node
    Input:  Node obj and null arguments
    Output: Node * pointer to right
*/
Node *& Node::get_right()
{
    return right;
}


int Node::set_left_data(Game * game)
{
    if(game == nullptr)
    {
        // reset the Data
        ldata = nullptr;
        return 1;
    }
    // downcasting
    Board_Game * board_game = dynamic_cast<Board_Game*>(game);
    Card_Game * card_game = dynamic_cast<Card_Game*>(game);
    Video_Game * video_game = dynamic_cast<Video_Game*>(game);
    if(board_game)
    {
        Board_Game * ptr = new Board_Game(* board_game);
        ldata = ptr;
    }
    else if(card_game)
    {
        Card_Game * ptr = new Card_Game(* card_game);
        ldata = ptr;
    }
    else if(video_game)
    {
        Video_Game * ptr = new Video_Game(* video_game);
        ldata = ptr;
    }
    return 1;
}


int Node::set_right_data(Game * game)
{
    if(game == nullptr)
    {
        // reset the Data
        rdata = nullptr;
        return 1;
    }
    // downcasting
    Board_Game * board_game = dynamic_cast<Board_Game*>(game);
    Card_Game * card_game = dynamic_cast<Card_Game*>(game);
    Video_Game * video_game = dynamic_cast<Video_Game*>(game);
    if(board_game)
    {
        Board_Game * ptr = new Board_Game(* board_game);
        rdata = ptr;
    }
    else if(card_game)
    {
        Card_Game * ptr = new Card_Game(* card_game);
        rdata = ptr;
    }
    else if(video_game)
    {
        Video_Game * ptr = new Video_Game(* video_game);
        rdata = ptr;
    }
    return 1;
}


// 2-3 Tree ************************************************************************
/** Protected Data Members:
    Node * root; */


/** Default Deconstructor
    Input:  End of Game Object Lifespan
    Output: Deallocate Dynamic Memory
*/
Tree::Tree():
    root(nullptr) {}


/** Default Deconstructor
    Input:  End of Game Object Lifespan
    Output: Deallocate Dynamic Memory
*/
Tree::~Tree() 
{
    if(root)
    {
        int remove_success = remove_all();
        if(!remove_success) cout << "Removal Failure\n";
    }
}


/** remove from 2-3 Tree Wrapper
    Input: Tree object and null argument
    Output: head recursively delete from the tree
*/
int Tree::remove_all()
{
    if(!root) 
    {
        cout << "Root Is Empty\n";
        return 1;
    }
    int remove_count = remove_all(root);
    root = nullptr;
    return remove_count;
}


/** remove from 2-3 Tree recursively
    Input: Tree object and null argument
    Output: head recursively delete from the tree
*/
int Tree::remove_all(Node * src)
{
    if(!src) return 0;
    int left_removed =   remove_all(src->get_left());
    int right_removed =  remove_all(src->get_middle());
    int middle_removed = remove_all(src->get_right());
    src->set_left_data(nullptr);
    src->set_right_data(nullptr);
    delete src;
    src = nullptr;

    return 1 + left_removed + right_removed + middle_removed; 
}


/** Utilize friend operators in base class to compare
    Input: Tree object and two object to compare
    Output:
        1 for less than
        2 for duplicate
        0 for >=
*/
int Tree::compare(const Game & obj1, const Game & obj2)
{
    if(!obj1 || !obj2) return 0;
    // perhaps compare if they are duplicates?
    if(obj1 == obj2)
    {
        return 2;
    }
    return obj1 < obj2;
}


/** Store Duplicates into a shared array
    Input: Tree object and Detected duplicate from comparison function
    Output: success or failure
vector<shared_ptr<game*>> duplicates;
*/
int Tree::store_duplicates(Game & obj)
{
    if(!obj) return 0;
    shared_ptr<Game*> duplicate = make_shared<Game*>(&obj);
    duplicates.push_back(duplicate);
    return 1;
}


/** display Duplicates into a shared array
    Input: Tree object null argument
    Output: success or failure display of duplicates
vector<shared_ptr<game*>> duplicates;
*/
int Tree::display_duplicates()
{
    if(duplicates.empty()) return 0;
    for(shared_ptr<Game*> p: duplicates)
    {
        Game* obj = *p.get();
        cout << "******************************************************" << endl;
        cout << *obj;
        cout << "******************************************************" << endl;
    }
    return 1;
}


/** insert into the 2-3 Tree Wrapper
    Input:  Tree obj and game* with derived object data to insert
    Output: insert from the root of the tree in sorted order
        1. If game is null return
        2. if root is null fill first node
        3. recursively call the tree
*/
int Tree::insert(Game * game)
{
    if(!game) return 0;
    // compare the games data
    // insert where best
    if(!root)
    {
        cout << "Root ?\n";
        root = new Node();
        root->set_left_data(game);
        return 1;
    }
    return insert(root, game);
}


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
int Tree::insert(Node *& src, Game * to_add)
{
    if(!to_add) return 0;
    
    // Empty Left Node
    if(!src)
    {
        cout << "Am I An Empty Left Data Node?";
        src = new Node();
        src->set_left_data(to_add);
        return 1;
    }

    int smaller;
    Game * ldata = src->get_left_data();
    Game * rdata = src->get_right_data();
    
    // Are Both Filled
    if(ldata && rdata)
    {
        // if rebalance The Tree
        if(!src->get_left() && !src->get_right())
        {
            cout << "Pushing up rebalancing The Tree\n";
            push_up(src, to_add);

            cout << "Pushing down root rebalancing The Tree\n";
            push_down(root);
            return 1;
        }

        cout << "ldata && rdata\n";
        // 1. less than left
        int smaller = compare(*to_add, *src->get_left_data());
        if(smaller == 2) return store_duplicates(*to_add); // handle duplicates

        cout << smaller << " Smaller\n";
        if(smaller)
        {
            cout << "Smaller Than data to add\n";
            insert(src->get_left(), to_add);
            push_up(src, to_add);
            return 1;
        }

        // 2. greater than equal to right
        int greater = !(compare(*to_add, *src->get_right_data()));
        if(greater == 2) return store_duplicates(*to_add); // handle duplicates

        cout << greater << " Larger?\n";
        if(greater)
        {
            cout << "Bigger Than data to add\n";
            insert(src->get_right(), to_add);
            push_up(src, to_add);
            return 1;
        }

        // 3. Middle 
        if(!smaller && !greater)
        {
            cout << "Smack Dab In The Middle\n";
            push_up(root, to_add);
            insert(src->get_middle(), to_add);
            return 1; 
        }
        cout << "Neither Cases Met\n";
    }

    // is there a left data value
    if(ldata && !rdata)
    {
        cout << "ldata && ! rdata\n";
        smaller = compare(*to_add, *src->get_left_data());
        if(smaller == 2) return store_duplicates(*to_add); // handle duplicates

        cout << smaller << " Smaller\n";
        Node * left = src->get_left();
        if(smaller)
        {
            if(!left)
            {
                int cmp_l = compare(*to_add, *ldata);
                if(cmp_l == 2) return store_duplicates(*to_add); // handle duplicates

                if(cmp_l)
                {
                    src->set_left_data(to_add);
                    src->set_right_data(ldata);
                }
                else
                {
                    src->set_left_data(ldata);
                    src->set_right_data(to_add);
                }
            }
            else // There Is a Left Subtree
            {
                if(!left->get_right_data())
                {
                    insert(left, to_add);
                }
                else // left subtree right data is present // push up and down
                {
                    cout << "two nodes in left subtree need to push up\n";
                    Game * lsubtree_rdata = left->get_right_data();
                    Game * lsubtree_ldata = left->get_left_data();

                    int greater_lsubtree_rdata = (!compare(*to_add, *lsubtree_rdata));
                    if(greater_lsubtree_rdata == 2) return store_duplicates(*to_add); // handle duplicates

                    if(greater_lsubtree_rdata)
                    {
                        if(left->get_left())
                        {
                            // if greater than left subtree right,
                            // then has to be greater than left subtree left
                            // push middle to_add and shift
                            Node * middle = src->get_middle();
                            if(!middle)
                            {
                                middle = new Node();
                                middle->set_left_data(to_add);
                                src->set_middle(middle);
                            }
                            src->set_right_data(src->get_left_data());
                            src->set_left_data(lsubtree_rdata);

                            left->set_left_data(lsubtree_ldata);
                            left->set_right_data(nullptr);
                        }
                    }
                    else
                    {
                        insert(left, to_add);
                    }
                }
            }
            return 1;
        }
        else // to_add greater than src->left_data
        {
            Node * right = src->get_right();
            // If There Is a Right Child Already?
            if(right)
            {
                cout << "to_add larger than src->left_data\n";
                int larger = (!compare(*to_add, *right->get_left_data()));
                if(larger == 2) return store_duplicates(*to_add); // handle duplicates

                if(larger)
                {
                    cout << "to_add larger than right subtree left\n";
                    if(right->get_right_data())
                    {
                        cout << "two nodes in right subtree need to push up\n";
                        Game * rsubtree_rdata = right->get_right_data();
                        Game * rsubtree_ldata = right->get_left_data();
                        
                        int greater_rsubtree_rdata = (!compare(*to_add, *rsubtree_ldata));
                        if(greater_rsubtree_rdata == 2) return store_duplicates(*to_add); // handle duplicates

                        if(greater_rsubtree_rdata)
                        {
                            cout << "Greater rsubtree_rdata\n";
                            // if greater than right subtree right,
                            // then has to be greater than right subtree left
                            // push middle right subtree left and shift
                            Node * middle = src->get_middle();
                            if(!middle)
                            {
                                middle = new Node();
                                middle->set_left_data(rsubtree_ldata);
                                src->set_middle(middle);
                            }
                            src->set_right_data(rsubtree_rdata);
                            right->set_left_data(to_add);
                            right->set_right_data(nullptr);
                            src->set_right(right);
                        }
                    }
                    else
                    {
                        return insert(right, to_add);
                    }
                }
                else
                {
                    int cmp_r = compare(*to_add, *src->get_left_data());
                    if(cmp_r == 2) return store_duplicates(*to_add); // handle duplicates

                    if(cmp_r)
                    {
                        src->set_right_data(src->get_left_data()); src->set_left_data(to_add); }
                    else
                    {
                        src->set_right_data(to_add);
                    }
                }
            }
            else
            {
                int cmp_r = compare(*to_add, *src->get_left_data());
                if(cmp_r == 2) return store_duplicates(*to_add); // handle duplicates

                if(cmp_r)
                {
                    src->set_right_data(src->get_left_data());
                    src->set_left_data(to_add);
                }
                else
                {
                    src->set_right_data(to_add);
                }
            }
            return 1;
        }
    }
    return 1;
}


/** Pull Down to balance tree
    Input: Node To pull down
    Output: rebalance Tree
*/
int Tree::push_down(Node * src)
{
    Node * left = src->get_left();
    Node * right = src->get_right();
    Node * middle = src->get_middle();

    // if there exists children below node to pull up
    // left pull up
    if(left && right && middle)
    {
        if(src->get_left_data() && src->get_right_data())
        {
            Node * temp = new Node();
            temp->set_left(src);
            temp->set_right(right);
            temp->set_left_data(src->get_right_data());

            src->set_right_data(nullptr);
            src->set_right(middle);
            src->set_middle(nullptr);
            root = temp;

            delete temp;
           /*
            int larger = !(src->get_left_data() < right->get_left_data() );
            if(larger)
            {
                Game * ld = right->get_left_data();
                right->set_left_data(src->get_left_data());
                src->set_left_data(ld);
                
            }
            */
        }
    }
    return 1;

}



/** Push up tree that is inbalanced
    Input: Tree object to push up and node to add
    Output: rebalanced tree
*/
int Tree::push_up(Node * src, Game * to_add)
{
    //*****************************************************************************
    Node * left = src->get_left();
    Node * right = src->get_right();

    // push Up with empty children
    if(!left && !right)
    {
        //*************************************************************************
        // Left Subtree Comparisons
        int ldata_smaller = compare(*to_add, *src->get_right_data());
        if(ldata_smaller == 2) return store_duplicates(*to_add); // handle duplicates

        if(!left)
        {
            cout << "Creating Left SubTree of Push Up New Node\n";
            left = new Node();
        }
        // Move Left down and swap with to_add
        if(ldata_smaller)
        {
            cout << "Left Subtree smaller\n";
            int cmp_flip = compare(*to_add, *src->get_left_data());
            if(cmp_flip == 2) return store_duplicates(*to_add); // handle duplicates

            if(!cmp_flip)
            {
                left->set_left_data(src->get_left_data());
                src->set_left_data(to_add);
                src->set_left(left);
            }
            else
            {
                left->set_left_data(to_add);
                src->set_left(left);
            }
        }
        else
        {
            cout << "Left Subtree larger\n";
            left->set_left_data(src->get_left_data());
            src->set_left_data(to_add);
            src->set_left(left);
        }
        //*************************************************************************
        // Right Subtree Comparisons
        int cmp_greater = (!compare(*src->get_left_data(), *src->get_right_data()));
        if(cmp_greater == 2) return store_duplicates(*to_add); // handle duplicates

        if(!right)
        {
            cout << "Creating Right SubTree of Push Up New Node\n";
            right = new Node();
        }
        if(cmp_greater)
        {
            cout << "Comparing to_add and right data\n";
            cout << cmp_greater << " Compare Greater\n";
            
            right->set_left_data(src->get_left_data());
            src->set_left_data(src->get_right_data());
            src->set_right(right);
            src->set_right_data(nullptr);
        }
        else
        {
            cout << "Comparing src->left_data is less than right data\n";
            right->set_left_data(src->get_right_data());
            src->set_right_data(nullptr);
            src->set_right(right);
        }
    }
    return 1;
}


/** Find the Max Height from node given
    Input: Node To traverse
    Output: Max height from Node
*/
int Tree::height(Node * src) const
{
    if(!src) return 0;
    int left = 1 + height(src->get_left());
    int middle = 1 + height(src->get_middle());
    int right = 1 + height(src->get_right());
    if(left > middle && left > right)
    {
        return left;
    }
    else if(middle > right && middle > left)
    {
        return middle;
    }
    else
    {
        return right;
    }
}


/** Display All Nodes in Tree including levels and max height recursive
    Input: Tree object to display
    Output: Display Nodes of Tree
        uses inorder_traverse and height
*/
int Tree::display() const
{
    if(!root) return 0;
    int traversal = inorder_traverse(root);
    cout << "*******************************************************\n";
    cout << "Max Height of Tree: " << height(root) << endl;
    cout << "*******************************************************\n";
    return traversal;
}


/** Traverse the Tree in order ascending to descending
    Input: Tree object and src
    Output: Display Nodes of Tree
// 1. tranferse left
// 2. print
//   - print(right)
//   - traverse middle
//   - print(left)
// 4. traverse right
*/
int Tree::inorder_traverse(Node * src) const
{
    if(!src) return 0;
    inorder_traverse(src->get_left());
    display_node(src);
    inorder_traverse(src->get_right());
    return 1;
}


/** Display All Nodes in Tree including levels and max height recursive
    Input: Tree object and src
    Output: Display Nodes of Tree
        uses inorder_traverse and height
// Print singular Node
*/
int Tree::display_node(Node * src) const
{
    if(!src) return 0;

        Game * ldata = src->get_left_data();
        int node_depth = 0;
        int max_depth = 0;
        if(ldata)
        {
            max_depth = height(root);
            node_depth = (max_depth - height(src) + 1);
            cout << "*******************************************************\n";
            cout << "Left Node\n";
            cout << *ldata;
            cout << "Height of Node: "<< node_depth << endl;
            cout << "*******************************************************\n";
        }
        // In order traversal Requires 
        // Printing The Middle in between left and right
        inorder_traverse(src->get_middle());
        Game * rdata = src->get_right_data();
        if(rdata)
        {
            max_depth = height(root);
            node_depth = (max_depth - height(src) + 1);
            cout << "*******************************************************\n";
            cout << "Right Node\n";
            cout << *rdata;
            cout << "Height of Node: "<< node_depth << endl;
            cout << "*******************************************************\n";
        }

    return 1;
}


// Menu ***************************************************************************


/**
Default Constructor
input:  new Object to initialize
output: Object for use of calling functions
*/
Menu::Menu(){}


/**
Default Deconstructor
input:  End of Menu obj lifespan
output: Dealloction of any dynamic memory
*/
Menu::~Menu(){}


/**
Menu greeting
input:  Menu obj
output: greet the user
*/
int Menu::greetings()
{
    cout << "Welcome To the Game!!!" << endl;
    return 1;
}


/**
Menu run program
input:  Menu obj
output: Run the Different Cases Prompted for the user
*/
int Menu::run_program()
{
    string activity = "1";
    string input;
    string list_options;
    srand(time(nullptr));

    Tree t;
    Game * game;

    while(activity != "0")
    {
        // Ask User Activity
        cin_game_type(activity);
        switch(stoi(activity))
        {
            case 1: //
            {
                Board_Game board_game;
                game = & board_game;
                game_cases(t, game);
                break;
            }//End Case 1

            case 2: // 
            {
                Card_Game card_game;
                game = & card_game;
                game_cases(t, game);
                break;
            }//End Case 2

            case 3: // 
            {
                Video_Game video_game;
                game = & video_game;
                game_cases(t, game);
                break;
            }//End Case 3 
        }//End Switch
    }//End While
    
    return 1;
}


/**
game case statements
input:  Menu obj
output: Run the options for virtual base game
*/
int Menu::game_cases(Tree & t, Game * game)
{
    string activity = "1";
    string input;
    string list_options;

    list_options = "1";
    while(stoi(list_options) != 0)
    {
        // Ask User Options
        cin_list_options(list_options);
        switch(stoi(list_options))
        {
            case 1:// Insert
            {
                input = "y";
                while(input != "N" && input != "n")
                {
                    cin >> *game;
                    t.insert(game);
                    prompt_insert_entry();
                    cin >> input;
                }
                break;
            }

            case 2: // Display All
            {
                int display_success = t.display();
                if(display_success) cout << "Display Success\n";
                if(!display_success) cout << "Display Failure\n";
                break;
            }

            case 3: // Remove All
            {
                int remove_success = t.remove_all();
                if(remove_success) cout << "Remove All Success\n";
                if(!remove_success) cout << "Remove All Failure\n";
                break;
            }

            case 4: // Display Duplicates
            {
                int duplicate_display = t.display_duplicates();
                if(duplicate_display) cout << "Duplicate Display Success\n";
                if(!duplicate_display) cout << "Duplicate Display Failure\n";
                break;
            }

        }
    }//End Options

    return 1;
}


/**
Menu prompt type
input:  Menu obj
output: cout list of options for the user
*/
int Menu::prompt_game_type()
{
    cout << "******************************************************" << endl;
    cout << "Which Video Game Would You Like To Build?" << endl;
    cout << "1 Board Game | 2 Card Game | 3 Video Game" << endl;
    cout << "0 to Quit Program" << endl;
    cout << "******************************************************" << endl;
    return 1;
}


/**
Menu prompt animal type
input:  Menu obj
output: integar 
        Repeating prompt until valid animal type entered
*/
int Menu::cin_game_type(string & activity)
{
    Exception_Handling e;
    prompt_game_type();
    cin >> activity; 
    int stoi_valid = e.validate_stoi(activity);
    while(!stoi_valid)
    {
        cout << "Please Enter a Valid Integer\n";
        prompt_game_type();
        cin >> activity; 
        stoi_valid = e.validate_stoi(activity);
    }
    return 1;
}

/**
Menu input list options
input:  Menu obj
output: integar 
        Repeating prompt until valid prompt given
*/
int Menu::cin_list_options(string & list_options)
{
    Exception_Handling e;

    prompt_list_options();
    cin >> list_options;
    int stoi_valid = e.validate_stoi(list_options);
    while(!stoi_valid)
    {
        cout << "Please Enter a Valid Integer\n";
        cin >> list_options;
        stoi_valid = e.validate_stoi(list_options);
    }
    return 1;
}

/**
Menu prompt insert
input:  Menu obj
output: cout to screen asking to insert an animal
*/
int Menu::prompt_insert_entry()
{
    cout << "Add Another Entry?" << endl;
    cout << "'y' to Continue | 'n' to Quit" << endl;
    return 1;
}


/**
Menu prompt options
input:  Menu obj
output: cout to screen list of prompt options
*/
int Menu::prompt_list_options()
{
    cout << "******************************************************" << endl;
    cout << "What Would You Like To Do For The List?" << endl;
    cout << "1 Insert | 2 Display All | 3 Remove All\n";
    cout << "4 Display duplicates\n";
    cout << "0 to Exit List" << endl;
    cout << "******************************************************" << endl;
    return 1;
}


/**
Menu prompt outro
input:  Menu obj
output: cout to screen outro sequence
*/
int Menu::outro()
{
    cout << "Thank You For Running The Program!\n";
    cout << "Have A Wondeful Day!!!\n";
    return 1;
}


// Exception Handling *************************************************************


/**
Default Constructor
input:  Exception_Handling object
output: Empty object to call exception functions
*/
Exception_Handling::Exception_Handling() {}


/**
Default Deconstructor
input:  End of Exception_Handling lifespan
output: Deallocate any dynamic Memory
*/
Exception_Handling::~Exception_Handling() {}


/**
Validate If the string is an integar
input:  string
output: 1 or 0 if string is an integar
*/
int Exception_Handling::validate_stoi(string src)
{
   try{
        stoi(src);
        return 1;
   }
   catch(const exception & stoi_Error)
   {
        cout << "Invalid Integar: " << stoi_Error.what() << endl;
        return 0;
   }
}


/**
Validate If the string is a float
input:  string
output: 1 or 0 if string is an float
*/
int Exception_Handling::validate_stof(string src)
{
   try{
       try{
            stof(src);
            return 1;
       }
       catch(const exception & stof_Error)
       {
            cout << "Invalid float: " << stof_Error.what() << endl;
            return 0;
       }
    }
    catch(const std::invalid_argument & invalid_arg_Error)
    {
        cout << "Invalid float: " << invalid_arg_Error.what() << endl;
        return 0;
    }
}


/**
Validate If the integar is negative
input:  integar
output: 1 if positive
        0 if negative
*/
int Exception_Handling::validate_negative(int a)
{
    if(a < 0){
        cout << "Negative Value Detected\n";
        return 0;
    }
    return 1;
}

