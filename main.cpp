#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class Tree
{
public:
    string src;
    Tree *left;
    Tree *right;
    Tree(string s, string type, int &id)
    {
        if(type == "infix")
        {

        }
        else if(type == "postfix")
        {

        }
        else if(type == "prefix")
        {
            string c = "";
            for(int i = id; i < s.size(); i++)
            {
                if(s[i] == ' ')
                {
                    src = c;
                    if(isdigit(c[i]))
                    {
                        //...
                    }
                    else
                    {
                        left = NULL;
                        right = NULL;
                    }
                }
                else
                    c+= s[i];
            }
        }
    }
};

int main() {

    return 0;
}
