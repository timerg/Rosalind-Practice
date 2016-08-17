#ifndef _longcsfind_
#define _longcsfind_
#include "sufixTree.h"
#include "parseFASTA.h"



Node* longestCommon(SNode* tree, Node* labelList, Node* nowResult, Node* bestResult);
Node* longestCommonInChildrens(ListOfSNode* childrens, Node* labelList, Node* nowResult, Node* bestResult);
SNode* constructTree(SNode* tree, FastaList* list);
Node* constructLabel(FastaList* list);
Node* findCommon(SNode* tree, Node* labelList);

#endif