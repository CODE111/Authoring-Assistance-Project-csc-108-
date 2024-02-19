#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

void PrintMenu()
{
    std::cout << "MENU" << std::endl;
    std::cout << "c - Number of non-whitespace characters" << std::endl;
    std::cout << "w - Number of words" << std::endl;
    std::cout << "f - Find text" << std::endl;
    std::cout << "r - Replace all !'s" << std::endl;
    std::cout << "s - Shorten spaces" << std::endl;
    std::cout << "q - Quit" << std::endl;
}
int GetNumOfNonWSCharacters(const std::string &sampleText)
{
    int numberOfChar;
    std::string withoutspace;

    // Need to remove all the space and get the length of the sample text
    for (int i = 0; i < sampleText.size(); i++)
    {
        if (!(isspace(sampleText.at(i))))
        {
            withoutspace = withoutspace + sampleText.at(i);
        }
    }
    numberOfChar = withoutspace.length();
    return numberOfChar;
}

int GetNumOfWords(const std::string &sampleText)
{
    int numberOfWords = 0;
    for (size_t i = 0; i < sampleText.size(); i++)
    {
        if (isspace(sampleText.at(i)))
        {
            numberOfWords++;
        }
    }
    numberOfWords -= 1;
    return numberOfWords;
}

int FindText(std::string &TextFound, std::string &sampleText)
{
    size_t numberOfTextFound = 0;
    size_t pos = sampleText.find(TextFound);
    // Need to find word match
    // Need to fix
    while (pos != std::string::npos)
    {
        numberOfTextFound++;
        pos = sampleText.find(TextFound, pos + TextFound.size());
    }
    return numberOfTextFound;
}
std::string ReplaceExclamation(std::string &sampleText)
{
    std::string updateString = "";

    for (size_t i = 0; i < sampleText.size(); i++)
    {
        if (sampleText.at(i) == '!')
        {
            sampleText.at(i) = '.';
            updateString = sampleText;
        }
    }
    return updateString;
}

std::string ShortenSpace(std::string &sampleText)
{
    // update the string by replacing all sequences of 2 or more spaces with a single space.
    std::string newUpdatedString = sampleText;
    size_t count = 0;

    for (size_t i = 0; i < newUpdatedString.size(); i++)
    {
        // need to fix this
        if (newUpdatedString.at(i) == ' ')
        {
            count++;
            if (count > 2)
            {
                newUpdatedString.erase(newUpdatedString.begin() + i);
                i--;
            }
        }
    }
    return newUpdatedString;
}

char ExecuteMenu(std::string &sampleText, char &userChoice)
{
    std::string TextFound;

    userChoice = tolower(userChoice);
    while (userChoice != 'q')
    {
        switch (userChoice)
        {
        case 'c':
            std::cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(sampleText) << std::endl;
            break;
        case 'w':
            std::cout << "Number of words:" << GetNumOfWords(sampleText) << std::endl;
            break;
        case 'f':
            std::cout << "Enter a word or phrase to be found:" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, TextFound);
            std::cout << "\"" << TextFound << "\""
                      << " instances: " << FindText(TextFound, sampleText) << std::endl;
            break;
        case 'r':

            std::cout << "Edited text: " << ReplaceExclamation(sampleText) << std::endl;
            break;
        case 's':
            std::cout << "Edited text: " << ShortenSpace(sampleText) << std::endl;
            break;
        default:
            PrintMenu();
            std::cout << std::endl;
            std::cout << "Choose an option:" << std::endl;
            std::cin >> userChoice;
        }
        std::cout << std::endl;
        PrintMenu();
        std::cout << std::endl;
        std::cout << "Choose an option:" << std::endl;
        std::cin >> userChoice;
    }
    return userChoice;
}

int main()
{
    char userChoice;
    std::string sampleText = "";

    std::cout << "Enter a sample text:" << std::endl;
    std::getline(std::cin, sampleText);
    std::cout << std::endl;
    std::cout << "You entered: " << sampleText << std::endl;
    std::cout << std::endl;

    PrintMenu();
    std::cout << std::endl;
    std::cout << "Choose an option:" << std::endl;
    std::cin >> userChoice;
    ExecuteMenu(sampleText, userChoice);

    return 0;
}
