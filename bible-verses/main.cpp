#include "stdafx.h"

using namespace std;

// King James Version (without the Apocrypha)
const int numBooks = 66;
const int maxChapters = 150; // Psalms
const int maxVerses = 176; // Psalm 119
vector<string> books(numBooks);
vector<vector<int>> verses(numBooks);

seed_seq seed{ time(0) };
default_random_engine generator{ seed };
uniform_int_distribution<int> distributionBook(0, numBooks - 1);
uniform_int_distribution<int> distributionChapter(0, maxChapters - 1);
uniform_int_distribution<int> distributionVerse(1, maxVerses);

void LoadChapters(string fileName)
{
    ifstream bible(fileName, ios::binary);
    if (!bible)
    {
        cout << "Cannot open " << fileName << endl;
        exit(-1);
    }
    string line{};
    const regex comma(",");
    for (int book{}; book < numBooks; book++)
    {
        getline(bible, line);
        vector<string> row{
            sregex_token_iterator(line.begin(), line.end(), comma, -1),
            sregex_token_iterator() };
        books.at(book) = row.at(0);
        verses.at(book).resize(0);
        for (int chapter{}; chapter < maxChapters; chapter++)
            verses.at(book).push_back(stoi(row.at(chapter + 1)));
    }
}

void SelectRandomVerse()
{
    int randomBook = distributionBook(generator);
    cout << books.at(randomBook) << " ";

    int randomChapter = distributionChapter(generator);
    while (verses.at(randomBook).at(randomChapter) == 0)
        randomChapter = distributionChapter(generator);

    cout << randomChapter + 1 << ":";

    int maxVerse = verses.at(randomBook).at(randomChapter);

    int randomVerse = distributionVerse(generator);
    while (randomVerse > maxVerse)
        randomVerse = distributionVerse(generator);

    cout << randomVerse << endl;
}


int main()
{
    LoadChapters("BibleVersesPerChapterPerBook.csv");
    for (int n{}; n < 20; n++)
        SelectRandomVerse();
}
