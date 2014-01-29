#include "Node.h"
#include "Result.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <list>
#include <queue>


#define SIZE 10000

using namespace std;

int Node::PATH;
int Node::DEPTH;
vector<int> Node::COMPARE;

void timestamp()
{
    time_t ltime;     /* calendar time */
    ltime=time(NULL); /* get current cal time */
    printf("%s",asctime( localtime(&ltime) ) );
}

int main()
{
    srand(13234321);
    Node* test=new Node(20); //must be even
    //test = test->add(new Item(1),0);
    //test = test->add(new Item(2),0);
    //test = test->add(new Item(3),0);
    //test = test->add(new Item(4),0);
    //test = test->add(new Item(5),0);
    //test = test->add(new Item(6),0);

    list<int> lst;

    timestamp();
    for (int i = 1; i <= SIZE; i++)
    {
        int val = rand() % SIZE;
        test = test->add(new Item(val),0);
        lst.push_back(val);
    }
    
    //test->remove(42, 0, false);
    //test->remove(42, 0, false);

    //Node::COMPARE.clear();
    //test->traversePrint();
    //lst.sort();
 
    timestamp();
    for (int i=0; i < SIZE; i++)
    {
        int val = lst.front();

        //vector<Result*> results;
        //results.clear();
    
        //timestamp();
        //test->find(val, results, false);
        //test->traversePrint();
        //printf("\n");
        test = test->removeValue(val, 0, false);
        test = test->removeValue(val, 0, false);
        if(i > SIZE - 1000) {
            test->traversePrint();
            printf("\n");
        }

        //test->traversePrint();
        //test->traversePrint();
        //printf("\n");
        //timestamp();

        //if(results.size() == 0)
        //{
        //    printf("%i,", val);
        //}
        //if(val != Node::COMPARE[i])
        lst.pop_front();
    }
    timestamp();
    
    
    //Node::traversePrint(test);

    //Node::PATH=0;
    //Node *find = Node::find(test, 1000001);

    //Node::DEPTH=0;
    //Node::traverse(test);


    return 0;
}