#include "stdafx.h"

using namespace std;

seed_seq seed{ 2016 };
default_random_engine generator{ seed };
uniform_int_distribution<int> distribution(0, 51);


void InitDeck(vector<int>& deck)
{
    for (size_t i{}; i < deck.size(); ++i)
        deck.at(i) = i;
}

void DealCards(vector<int>& deck)
{
    for (auto& card : deck)
        swap(card,
             deck.at(distribution(generator)));
}

void DisplayCards(vector<int>& deck)
{
    const vector<string> suit{ "Clubs", "Diamonds",
                               "Hearts", "Spades" };

    const vector<string> rank{ "Deuce", "Three", "Four",
                               "Five", "Six", "Seven",
                               "Eight", "Nine", "Ten",
                               "Jack", "Queen", "King",
                               "Ace" };

    for (size_t i{}; i < deck.size(); ++i)
    {
        int card = deck.at(i);
        cout << "Card in position " << i
             << " is the " << rank.at(card % 13)
             << " of " << suit.at(card / 13) << endl;
    }
}

int main()
{
    vector<int> deck(52);

    const int maxDeal{ 10000 };

    auto startTime = chrono::steady_clock::now();

    for (int deal{}; deal < maxDeal; ++deal)
    {
        InitDeck(deck);
        DealCards(deck);
    }

    auto endTime = chrono::steady_clock::now();

    DisplayCards(deck);

    auto totalTime = chrono::duration_cast<chrono::milliseconds>
                     (endTime - startTime).count();

    cout.imbue(std::locale(""));
    cout << "Total deals: " << maxDeal << endl;
    cout << "Total run time (ms): " << totalTime << endl;

    return 0;
}
