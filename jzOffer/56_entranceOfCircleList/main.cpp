//
//  main.cpp
//  56_entranceOfCircleList
//
//  Created by kqy on 10/05/2017.
//  Copyright © 2017 kqy. All rights reserved.
//

#include <iostream>
using namespace std;
typedef struct  LNode {
    int value;
    struct LNode * next;
}LNode, ListNode;
void createCircleList(LNode **pHead, int length) {
    if (length < 1) {
        return;
    } else if (*pHead ==NULL) {
        LNode *headNode = new LNode();
        headNode -> value = 999;
        headNode ->next = NULL;
        *pHead = headNode;
    }
    LNode *p = new LNode();
    LNode *lastNode ;//最后一个结点，环的开始结点
    LNode * circleStartNode ;
    p = *pHead;
    for (int i = 0; i < length; ++ i ) {
        LNode *newNode = new LNode();
        newNode ->value =  (i+1) * 3;
        newNode -> next = NULL;
        p -> next  = newNode;
        p = newNode;
        lastNode = newNode;
        if (i == 2) {
            circleStartNode = newNode;
        }
    }
    lastNode -> next = circleStartNode;
}
void displayList(LNode *pHead, int length) {
    if (pHead == NULL ) {   
        cout<< "can't cout null" <<endl;
        return;
    }
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
LNode *meetNode (LNode *pHead) {
    if (!pHead) return nullptr;
    LNode *fastP = pHead -> next ;
    LNode *slowP = pHead ;
    while (fastP != slowP) {
        ++fastP; ++fastP;
        ++slowP;
    }
    return fastP;//返回相见的点
}
LNode *entranceP (LNode *meetP) {
    int count = 0;
    LNode *fastP = meetP;
    LNode *slowP = meetP;
    do {
        fastP = fastP -> next -> next;
        slowP = slowP -> next;
        ++count;
    } while (slowP != fastP); // count  = 圈数 。
    cout << "lengt:" << count << endl;
    fastP = meetP;
    slowP = meetP;
    for (int i = 0; i < count; ++i) fastP = fastP-> next;
    while (fastP != slowP) {
        fastP = fastP -> next;
        slowP = slowP -> next;
    }
    return fastP;
}
int main(int argc, const char * argv[]) {
    ListNode * p1 = new ListNode();
    p1 -> value = 3;
    createCircleList(&p1, 5);
    displayList(p1, 10);
    // 0517
   LNode *entrance = entranceP(p1);
    cout << entrance -> value << endl;
    //test 0510
//    cout << endl <<  lengOfCircleList(p1) << endl;
//    LNode *entrance = entranceList(p1);
//    cout << entrance -> value << endl;
    return 0;
}
int lengOfCircleList0510(LNode *pHead) {
    LNode *pFast = pHead -> next -> next;
    LNode *pSlow = pHead;
    int count = 1;
    while (pFast != pSlow) {
        pFast = pFast -> next -> next;
        pSlow = pSlow -> next;
    }
    pFast = pFast -> next -> next;
    pSlow = pSlow -> next;
    while (pFast != pSlow) {
        ++count;
        pFast = pFast -> next -> next;
        pSlow = pSlow -> next;
    }
    return count;
}
LNode * entranceList0510(LNode *pHead) {
    LNode *pFront = pHead;
    LNode *pBack = pHead;
    LNode *pEntranceCircle ;
    int count = lengOfCircleList0510(pHead);
    for (int i = 0; i < count; ++i) pFront = pFront -> next;
    while (pFront != pBack) {
        pFront = pFront -> next;
        pBack = pBack -> next;
    }
    pEntranceCircle = pFront;
    return pEntranceCircle;
}

