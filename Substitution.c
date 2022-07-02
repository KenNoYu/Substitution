#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool only_26_char(string s);
bool only_alpha(string s);
bool no_same_char(string s);
char substitute(char c, string k);

int main(int argc, string argv[]) 
{
    string plaintext;
    
    // makes sure that argument count only has 2
    if (argc == 2)
    {
        // makes sure that argument is 26 characters
        bool c = only_26_char(argv[1]);
        if (c == true)
        {
            // makes sure that all characters in Key is alphabetical
            bool a = only_alpha(argv[1]);
            if (a == true)
            {
                // makes sure that all characters in ket do not repeat
                bool x = no_same_char(argv[1]);
                if (x == true)
                {
                    string key = argv[1]; 
                    plaintext = get_string("plaintext:  ");
                    printf("ciphertext:  ");
                    for (int i = 0; i < strlen(plaintext); i++)
                    {
                        char cipher = substitute(plaintext[i], key);
                        printf("%c", cipher);
                    }
                    printf("\n");
                }
                // If characters repeat print this
                else
                {
                    printf("Key must not contain repeated characters\n");
                    return 1;
                }
            }
            // If key does not have alphabetical characters print this
            else 
            {
                printf("Key must only contain alphabetical characters.\n");
                return 1;
            }
        }
        // If key is not 26 characters print this
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    // if argument count more or less than 2 print this
    else 
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
}

bool only_26_char(string s)
{
    bool value;
    int n = strlen(s);
    if (n == 26)
    {
        value = true;
    }
    else
    {
        value = false;
    }
    return value;
}

bool only_alpha(string s)
{
    bool value;
    
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isalpha(s[i]))
        {
            value = false;
        }
        else
        {
            value = true;
            continue;
        }
            
    }
    return value;
}

bool no_same_char(string s)
{
    bool value;
    
    for (int i = 0; i < strlen(s); i++)
    {
        int n = 25;
        while (n > 1)
        {
            if (s[i] == s[n] && i != n)
            {
                value = false;
                break;
            }
            else
            {
                value = true;
                n--;
                continue;
            }
        }
    }
    return value;
}

char substitute(char c, string k)
{
    int f = (int)c;
    
    if (isalpha(c))
    {
        if (isupper(c))
        {
            f = f - 'A';
            f = toupper(k[f]);
        }
        else if (islower(c))
        {
            f = f - 'a';
            f = tolower(k[f]);
        }
    }    
    else
    {
        f = c;
    }
    return (char)f;
}
