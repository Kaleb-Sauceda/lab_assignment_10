#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void insert(struct Trie **ppTrie, char *word)
{
    if (*ppTrie == NULL)
    {
        return;
    }
    Trie *temp = *ppTrie;
    int length = strlen(word);
    for (int i = 0; i < length; i++)
    {
        int index = word[i] - 'a';
        if (temp->children[index] == NULL)
        {
            temp->children[index] = calloc(1, sizeof(Trie));
        }
        temp = temp->children[index];
    }
    temp->flag++;
}

int numberOfOccurances(struct Trie *pTrie, char *word)
{
    for (int i = 0; i < strlen(word); i++)
    {
        int index = word[i] - 'a';
        if (pTrie->children[index] == NULL)
        {
            return 0;
        }
        pTrie = pTrie->children[index];
    }
    return pTrie->count;
}
struct Trie *deallocateTrie(struct Trie *pTrie);
int main(void)
{
      //read the number of the words in the dictionary
      // parse line  by line, and insert each word to the trie data structure
      char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
      for (int i=0;i<5;i++)
      {
          printf("\t%s : %d\n",pWords[i], numberOfOccurances(&trie, pWords[i]));
     }
    trie = deallocateTree(&trie);
    if (trie != NULL)
       printf("There is an error in this program\n");
    return 0;
}