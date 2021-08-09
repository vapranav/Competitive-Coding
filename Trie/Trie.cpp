// A CPP implementation of the trie data structure includes inserting, searching and prefix based search.

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class TrieNode
{
public:
    vector<TrieNode *> children = vector<TrieNode *>(26);
    string item = "";
    TrieNode()
    {
        // cout << "hello world";
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (auto c : word)
        {
            if (node->children[c - 'a'] == NULL)
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->item = word;
        cout << "Word inserted successfully!"
             << "\n";
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (auto c : word)
        {
            if (node->children[c - 'a'] == NULL)
                return false;
            node = node->children[c - 'a'];
        }
        return node->item == word ? true : false;
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (auto c : prefix)
        {
            if (node->children[c - 'a'] == NULL)
                return false;
            node = node->children[c - 'a'];
        }
        return true;
    }
};

int main()
{
    Trie *trie = new Trie();
    trie->insert("hello");
    trie->insert("world");
    bool found = trie->startsWith("wod");
    found == true ? cout << "word found" : cout << "not found";
}
