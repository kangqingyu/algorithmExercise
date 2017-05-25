//
//  main.cpp
//  57_deleteDuplicationList
//
//  Created by kqy on 10/05/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
typedef struct  LNode {
    int value;
    struct LNode * next;
}LNode;
void createListAuto(LNode **pHead, int length) {
    if (length < 1) {
        return;
    } else if (*pHead ==NULL) {
        LNode *headNode = new LNode();
        headNode -> value = 999;
        headNode ->next = NULL;
        *pHead = headNode;
    }
    LNode *p = new LNode();
    p = *pHead;
    for (int i = 0; i < length; ++ i ) {
        LNode *newNode = new LNode();
        if (i % 3 == 0) {
            newNode ->value =  i * 3 ;
        }else   newNode ->value =  (i+1) * 3  ;
        newNode -> next = NULL;
        p -> next  = newNode;
        p = newNode;
    }
}
void displayList(LNode *pHead, int length) {
    LNode *p = pHead;
    for (int i = 0; i < length; ++i) {
        if (!p) {
            break;
        }
        std::cout << p -> value << "  ";
        p = p->next;
    }
    std::cout<< std::endl;
}
void deleteDuplication(LNode **pHead) {
    LNode *pMove = *pHead;
    LNode *pPre = 0;
    while (pMove) {
        LNode *pNext = pMove -> next;
        LNode *pDelete = 0;
        bool sameDelete = false;
        if (!pNext) return;
        if (pMove -> value == pNext -> value) sameDelete = true;
        if (!sameDelete) {
            pPre = pMove;// 先把前一个记录。
            pMove = pNext;
//            pNext = pNext -> next;
        } else {
            while (pMove -> value == pNext -> value) {
                pDelete = pNext;
                pNext = pNext -> next;
                delete pDelete;
                pDelete = NULL;
            }
            pDelete = pMove;
            pMove = pNext;
            delete pDelete;
            pDelete = NULL;
            //接前边的
            pPre -> next = pMove;
        }// else
    }
}
int main(int argc, const char * argv[]) {
    LNode *p1 = new LNode();
    createListAuto(&p1, 9);
    displayList(p1, 9);
    deleteDuplication(&p1);
    displayList(p1, 9);
    return 0;
}

void deleteDuplication0519(LNode **pHead) {
    LNode *preN = nullptr;
    LNode *curN = *pHead;
    while (curN ) {
        LNode *nextN = curN -> next;
        if (!nextN) {
            return;
        }
        while (nextN -> value == curN -> value) {
            LNode *deleteP = nextN;
            nextN  = nextN -> next;
            delete deleteP;
            deleteP = nullptr;
        }
        preN = curN;
        curN = nextN;
    }
}

void deleteDuplication0517(LNode **pHead) {
    LNode *frontP = *pHead;
    frontP = frontP -> next;
    LNode *backP = *pHead;
    while (frontP) {
        while (frontP -> value == backP -> value) {
            frontP = frontP -> next;
        }
    }
}

void deleteDuplication0510(LNode **pHead) {
    LNode *preP = *pHead;
    LNode *currentP = *pHead ;
    LNode *nextP;
    currentP = currentP -> next;
    while (currentP) {
        nextP = currentP -> next;
        if (!nextP) {
            break;
        }
        if (nextP -> value != currentP -> value) {
            preP = currentP;
            currentP = nextP;
            continue;
        }
         //else 是current = next的情况.
        while (currentP -> value == nextP -> value) {
            nextP = nextP -> next;
        }
        preP -> next = nextP;
        currentP = nextP;
    }
}

