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
    Tree(string &s, int l, int r) //infix
    {
        string src_of_minp;
        int a, b, minp = -1, p = 1;
        for(int i = l; i <= r; i++)
        {
            ///do this..................
        }
        src = src_of_minp;
        if(isdigit(src[0]))
        {
            left = NULL;
            right = NULL;
        }
        else if(src.size() > 0)
        {
            left = new Tree(s, b+1, r);///remake this...... if u need.....
        }
        else
        {
            left = new Tree(s, l, a-1);///and here too
            right = new Tree(s, b+1, r);
        }


    }
    Tree(string &s, const string& type, int &id)
    {
        if(type == "postfix")
        {
            string c = "";
            bool notfinish = true;
            for(int i = id; i > 0 && notfinish; i--)
            {
                if(s[i] == ' ')
                {
                    src = c;
                    if(isdigit(c[0])) //number
                    {
                        //...
                        left = NULL;
                        right = NULL;
                        id--;

                    }
                    else if(c.size() > 1) //function
                    {
                        id--;
                        left = new Tree(s, type, id);
                        right = NULL;
                    }
                    else //operation
                    {
                        id--;
                        right = new Tree(s, type, id);
                        left = new Tree(s, type, id);;
                    }
                    notfinish = false;
                }
                else
                    c = s[i] + c;
            }
        }
        else if(type == "prefix")
        {
            string c = "";
            bool notfinish = true;
            for(int i = id; i < s.size() && notfinish; i++)
            {
                if(s[i] == ' ')
                {
                    src = c;
                    if(isdigit(c[0])) //number
                    {
                        //...
                        left = NULL;
                        right = NULL;
                        id++;

                    }
                    else if(c.size() > 1) //function
                    {
                        id++;
                        left = new Tree(s, type, id);
                        right = NULL;
                    }
                    else //operation
                    {
                        id++;
                        left = new Tree(s, type, id);
                        right = new Tree(s, type, id);;
                    }
                    notfinish = false;
                }
                else
                    c+= s[i];
            }
        }
    }
    void print_postfix();
    void print_prefix();
    void print_infix();
};

void Tree::print_postfix() {
    if(left) left->print_postfix();
    if(right) right->print_postfix();
    cout << src << " ";
}
void Tree::print_prefix() {
    cout << src << " ";
    if(left) left->print_prefix();
    if(right) right->print_prefix();
}

void Tree::print_infix() {
    if(left == NULL) cout << src;
    else if(right == NULL)
    {
        cout << src << "(";
        left->print_infix();
        cout << ")";
    }
    else
    {
        cout << "(";
        left->print_infix();
        cout << src;
        right->print_infix();
        cout << ")";
    }
}


int main() {
    string type, s;
    cin >> type;
    getline(cin, s);
    s += " ";
    if(type == "infix")
    {
        Tree *tree = new Tree(s, 0, s.size()-1);
        cout << "postfix:" << endl;
        tree->print_postfix();
        cout << "prefix:" << endl;
        tree->print_prefix();
    }
    else if(type == "postfix")
    {
        int id = (s.size()-1);
        Tree *tree = new Tree(s, type, id);
        cout << "infix:" << endl;
        tree->print_infix();
        cout << "prefix:" << endl;
        tree->print_prefix();
    }
    else if(type == "prefix")
    {
        int id = 0;
        Tree *tree = new Tree(s, type, id);
        cout << "infix:" << endl;
        tree->print_infix();
        cout << "postfix:" << endl;
        tree->print_postfix();
    }
    return 0;
}
