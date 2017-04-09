//HEADER FILE

using namespace std;

//Function declaration
int getPlayers();
void setCards(Cards *cards);
void setDeck(vector<int>& deck);
void printCards(Cards *cards);
void assignCards(Cards *cards, int playerNum, vector<int>& deck);
void takeTurns(Cards *cards, Players *player, int playerNum, vector<int>& deck);
void displayCards(Cards *cards, Players *player, int player2);
void setupPlayers(Cards *cards, Players *player, int playerAmount, vector<int>& deck);
int promptUser(Players *player, int playerAmount, int currentPlayer);
int promptCards(Cards *cards,Players *player, int playerAmount, int currentPlayer);
void checkPlayer(Cards *cards, Players *player, int cCard, int cPlayer, int tPlayer, vector<int>& deck);
void goFish(Players *player, int cPlayer, vector<int>& deck);
void winner(Cards *cards, Players *player, int cPlayer);
string translateSuit(int value);
string translateDenomination(int value);

