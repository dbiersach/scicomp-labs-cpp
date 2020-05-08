#include "stdafx.h"

using namespace std;

int main()
{
    seed_seq seed{ 2016 };
    default_random_engine generator{ seed };
    uniform_int_distribution<int> distribution(0, 364);

    for (int students = 2; students <= 80; students++)
    {
        vector<int> birthdays(students);

        int matchCount = 0;

        for (int classNum = 0; classNum < 10000; classNum++)
        {
            // Initialize the birthdays array with a random day between 0 and 364
            for (int i = 0; i < birthdays.size(); i++)
                birthdays.at(i) = distribution(generator);

            // Compare birthdays of each person to the remaining people
            // Note:  Only loop until the first match is found
            bool foundMatch = false;
            for (int j{}; !foundMatch && j < birthdays.size() - 1; j++)
                for (int k{ j + 1 }; !foundMatch && k < birthdays.size(); k++)
                    if (birthdays.at(j) == birthdays.at(k))
                        foundMatch = true;

            if (foundMatch)
                matchCount++;
        }

        cout << "Probability of matching birthdays among "
             << setw(2) << students << " people = "
             << fixed << setprecision(4) << (double)matchCount / 10000
             << endl;
    }

    return 0;
}

