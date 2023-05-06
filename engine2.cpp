#include <iostream>  // used for input & output
#include <string>    // For working with Strings
#include <vector>    // For dynamic arrays
#include <algorithm> // For finding elements in container
#include <fstream>   // For file input/output
#include <sstream>   // For working with string streams

using namespace std; /* computer needs to know the code for the cout, cin functionalities and
                        it needs to know which namespace they are defined.*/

/*
Tokenization is the process of breaking down a larger string into smaller, more manageable pieces called
tokens.
 In the context of a search engine, tokenization is important because it allows us to break down the documents
 into individual words, which can be used to determine relevance in a search query.
*/
vector<string> tokenize(string str)
{
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, ' '))
    {
        tokens.push_back(token);
    }
    return tokens;
}

/*
load_documents: This function takes a filename as input and returns a vector of
strings, where each string represents a document that is read from the file.
 The function opens the file using an input file stream (ifstream), reads each
line of the file using the getline function, and appends each line to the vector of documents.
*/
vector<string> load_documents(string filename)
{
    ifstream file(filename);
    vector<string> documents;
    string line;
    while (getline(file, line))
    {
        documents.push_back(line);
    }
    file.close();
    return documents;
}
/*
This takes a vector of string and and a string as input, and returns a vector of integers, it represents
the index of the document that contains the query string.
Then it call tockenize and searches each document, and searches for the query string using find function
from algorithm library.
*/
vector<int> search_documents(vector<string> documents, string query)
{
    vector<int> results;
    for (int i = 0; i < documents.size(); i++)
    {
        string document = documents[i];
        vector<string> tokens = tokenize(document);
        if (find(tokens.begin(), tokens.end(), query) != tokens.end())
        {
            results.push_back(i);
        }
    }
    return results;
}

/*
'main' function, the code loads a set of documents from a file named "documents.txt" by
calling the 'load_documents' function. It then prompts the user to enter a query string
and reads the input using 'getline'.

Then 'search_documents' is called with the vector of documents and the query string as input,
resulting vector of indices is stored in the 'results' variable.
*/
int main()
{
    string filename = "documents.txt";
    vector<string> documents = load_documents(filename);

    string query;
    cout << "Enter a query: ";
    getline(cin, query);

    vector<int> results = search_documents(documents, query);
    if (results.empty())
    {
        cout << "No results found." << endl;
    }
    else
    {
        cout << "Results:" << endl;
        for (int i = 0; i < results.size(); i++) // This will print each document on a new line.
        {
            cout << "Document #" << results[i] << ": " << documents[results[i]] << endl;
        }
    }

    return 0;
}