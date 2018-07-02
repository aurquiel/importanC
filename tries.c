#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
#define TRUE 1
#define FALSE 0

typedef struct tNodo{
    struct tNodo *letters[ALPHABET_SIZE];
    unsigned isEndOfWord;
}Nodo;

Nodo *getNewTrie(){
    Nodo *trie = (Nodo*)malloc(sizeof(Nodo));
    trie->isEndOfWord = FALSE;
    for (int i =0; i<ALPHABET_SIZE; i++)
        trie->letters[i] = NULL;
    return trie;
}

void insert(Nodo *root, const char *word){
    Nodo *trieExplorer = root;
    unsigned int i, index;
    for(i = 0; i<strlen(word); i++){
        index = tolower(word[i]) - 'a';
        if(trieExplorer->letters[index]==NULL){
            trieExplorer->letters[index] = getNewTrie();
        }
        trieExplorer = trieExplorer->letters[index];
    }
    trieExplorer->isEndOfWord = TRUE;
}

unsigned search(Nodo *root, const char *word){
    Nodo *trieExplorer = root;
    unsigned int i, index;
    for(i = 0; i<strlen(word); i++){
        index = tolower(word[i]) - 'a';
        if(trieExplorer->letters[index]==NULL){
            return FALSE;
        }
        trieExplorer = trieExplorer->letters[index];
    }
    return trieExplorer->isEndOfWord;
}

unsigned search2(Nodo *root, const char *word){
    Nodo *trieExplorer = root;
    unsigned int i, index;
    for(i = 0; i<strlen(word); i++){
        index = tolower(word[i]) - 'a';
        if(trieExplorer->letters[index]==NULL){
            return FALSE;
        }
        trieExplorer = trieExplorer->letters[index];
    }
    return (trieExplorer == NULL) ? 0:1;
}

int main()
{
    Nodo *myTrie = getNewTrie();
    insert(myTrie,"algoritmos");
    insert(myTrie,"udemy");
    insert(myTrie,"christopher");
    insert(myTrie,"programacion");
    printf("%d\n",search2(myTrie,"algor2"));
    free(myTrie);
    return 0;
}
