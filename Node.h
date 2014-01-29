#pragma once

#include "Item.h"
#include "Result.h"

#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

 /*  int itemFind(int val, int start, int end)
    {
        int half = (end - start) / 2;
        if (items[start + half]->value == val)
        {
            return start + half;
        }
        if (end - start < 2)
        {
            return start + half;
        }
        else if ( val < items[start + half]->value) 
        {
            return itemFind(val, start, start + half);
        }        
        else
        {
            return itemFind(val, start + half, end);
        }
    }

    Item* find(int val)
    { 
        int index = itemFind(val, 0, itemCount);
        if (items[index]->value == val)
            return this->items[index];
        else if(val < items[index]->value)
        {
            if (children[index] == 0)
                return 0;
            return children[index]->find(val);
        }
        else
        {
            if (children[index+1] == 0)
                return 0;
            return children[index+1]->find(val);
        }
      
    }*/

                     //if(
                        //   (!sibling->isLeaf() && sibling->childrenCount < sibling->itemCount) 
                        //|| (!node->isLeaf() && node->childrenCount < node->itemCount)
                        //|| (!parent->isLeaf() && parent->childrenCount < parent->itemCount)
                        //)
                        //{
                        //    int fs=32;
                        //}

                        //for(int j = 0; j < node->itemCount; j++)
                        //{
                        //    printf("%i",node->items[j]->value);
                        //}

                        //for(int j = 0; j < sibling->itemCount; j++)
                        //{
                        //    printf("%i",sibling->items[j]->value);
                        //}
                        //
                        //for(int j = 0; j < parent->itemCount; j++)
                        //{
                        //    printf("%i",parent->items[j]->value);
                        //}                 
/*                       if(
                        (!sibling->isLeaf() && sibling->childrenCount < sibling->itemCount) 
                        || (!node->isLeaf() && node->childrenCount < node->itemCount)
                        || (!parent->isLeaf() && parent->childrenCount < parent->itemCount)
                        )
                        {
                            int fs=32;
                        }

                        for(int j = 0; j < node->itemCount; j++)
                        {
                            printf("%i",node->items[j]->value);
                        }

                        for(int j = 0; j < sibling->itemCount; j++)
                        {
                            printf("%i",sibling->items[j]->value);
                        }

                        for(int j = 0; j < parent->itemCount; j++)
                        {
                            printf("%i",parent->items[j]->value);
                        }*/


            //if(
            //    (!node->isLeaf() && node->childrenCount < node->childrenCount)
            //    || (!parent->isLeaf() && parent->childrenCount < parent->itemCount)
            //)
            //{
            //    int fs=32;
            //}

             /*                if 
                 ((!this->isLeaf() && this->childrenCount < this->itemCount)
                        || (parent != 0 && !parent->isLeaf() && parent->childrenCount < parent->itemCount)
                        || (mnode->childrenCount < mnode->itemCount)
                        || (!rnode->isLeaf() && rnode->childrenCount < rnode->itemCount
                 ))
                 {
                    int kfds=32;
                 }*/

                         /*
        if ((!this->isLeaf() && this->childrenCount < this->itemCount)
        || (parent != 0 && !parent->isLeaf() && parent->childrenCount < parent->itemCount)
        || (!rnode->isLeaf() && rnode->childrenCount < rnode->itemCount))
        {
            int kfds=32;
        }*/


  /*                          sibling->childrenCount=0;
                            sibling->itemCount=0;
                            
                            if(
                            (!sibling->isLeaf() && sibling->childrenCount < sibling->itemCount) 
                            || (!node->isLeaf() && node->childrenCount < node->itemCount)
                            || (!parent->isLeaf() && parent->childrenCount < parent->itemCount)
                            )
                            {
                                int fs=32;
                            }

                            for(int j = 0; j < node->itemCount; j++)
                            {
                                printf("%i",node->items[j]->value);
                            }
                                                     
                            for(int j = 0; j < parent->itemCount; j++)
                            {
                                printf("%i",parent->items[j]->value);
                            }*/

 /*                           node->childrenCount = 0;
                            node->itemCount =0 ;
                            
                            if(
                            (!sibling->isLeaf() && sibling->childrenCount < sibling->itemCount) 
                            || (!node->isLeaf() && node->childrenCount < node->itemCount)
                            || (!parent->isLeaf() && parent->childrenCount < parent->itemCount)
                            )
                            {
                                int fs=32;
                            }

                            for(int j = 0; j < sibling->itemCount; j++)
                            {
                                printf("%i",sibling->items[j]->value);
                            }

                            for(int j = 0; j < parent->itemCount; j++)
                            {
                                printf("%i",parent->items[j]->value);
                            }*/
        //if(!this->isLeaf() && this->childrenCount < this->itemCount)
        //    int jk = 32;

class Node
{

public:

    static int PATH;
    static int DEPTH;
    static vector<int> COMPARE;

    Node** children;
    Item** items; 
    int itemCount;
    int childrenCount;
    int m;

    void traversePrint()
    {
        for(int i =0; i < itemCount+1; i++)
        {
            if (children[i] != 0)
                children[i]->traversePrint();
            
            if(i < itemCount) 
            {
                Item* item = items[i];
                printf("%i,", items[i]->value);
                //COMPARE.push_back(items[i]->value);
            }
        }       
    }

    int itemFind(int val, int start, int end, vector<Result*>& results)
    {
        int half = (end - start) / 2;
        if (items[start + half]->value == val)
        {
 
            int i = start + half - 1;
            while(i >= 0 && items[i]->value == val)
            {
                i--;
            }           
            i++;
            while(i < itemCount && items[i]->value == val)
            {
                Result* result = new Result();
                result->index = i;
                result->item = items[i];
                results.push_back(result);
                i++;
            }
 
            return start + half;
        }

        if (end - start < 2)
        {
            return start + half;
        }
        else if ( val < items[start + half]->value) 
        {
            return itemFind(val, start, start + half, results);
        }        
        else
        {
            return itemFind(val, start + half, end, results);
        }
    }    

    void find(int val, vector<Result*>& results, bool found)
    { 
        int before = results.size();
        int index = itemFind(val, 0, itemCount, results);
        int after = results.size();

        for (int i = before; i < after; i++)
        {
            int index = results[i]->index;
            if (!this->isLeaf())
            {
                children[index]->find(val, results, true);
                if(i == (after - 1) && children[index+1] != 0)
                {
                    children[index+1]->find(val, results, true);
                }
            }
        }

        if (before-after == 0 && found == false)
        {
            if(val < items[index]->value)
            {
                if (children[index] != 0)
                    children[index]->find(val, results, found);
            }
            else
            {
                if (children[index+1] != 0)
                    children[index+1]->find(val, results, found);
            }
        }
    }

    static void balance(Node* node, Node* parent)
    {
        int half = (node->m-1) /2;

        if(node->itemCount < half && parent != 0)
        {
            bool found = false;
            for(int i =0; i < parent->childrenCount && found == false; i++)
            {
                if(parent->children[i] == node)
                {
                    found = true;
                    if( i+1 < parent->childrenCount && parent->children[i+1] != 0 && parent->children[i+1]->itemCount > half)
                    {
                        Node* sibling = parent->children[i+1];

                        node->items[node->itemCount] = parent->items[i];
                        node->itemCount++;
                        
                        parent->items[i] = sibling->items[0];
                        for(int j = 0; j < sibling->itemCount-1; j++)
                        {
                            sibling->items[j] = sibling->items[j+1];
                        }
                        sibling->itemCount--;
                        sibling->items[sibling->itemCount] = 0;
                            
                        if (!sibling->isLeaf())
                        {
                            node->children[node->childrenCount] = sibling->children[0];
                            node->childrenCount++;

                            for(int j = 0; j < sibling->childrenCount-1; j++)
                            {
                                sibling->children[j] = sibling->children[j+1];
                            }
                            sibling->childrenCount--;
                            sibling->children[sibling->childrenCount] = 0;
                        }
                    }
                    else if(i>0 && parent->children[i-1] !=0 && parent->children[i-1]->itemCount > half)
                    {
                        Node* sibling = parent->children[i-1];

                        for(int j=node->itemCount; j > 0; j--)
                        {
                            node->items[j] = node->items[j-1];
                        }
                        node->items[0] = parent->items[i-1];  //set parent item to first item
                        node->itemCount++; // increment item count
                        parent->items[i-1] = sibling->items[sibling->itemCount-1]; //set parent item to left, right most item
                        sibling->items[sibling->itemCount-1] = 0; //set parent's left node, right most node to null
                        sibling->itemCount--; //decrement item count of parent's left node of items
                        
                            
                        if (!sibling->isLeaf())
                        {    
                            for(int j=node->childrenCount; j > 0; j--)
                            {
                                node->children[j] = node->children[j-1];
                            }

                            node->children[0] = sibling->children[sibling->childrenCount-1];
                            node->childrenCount++;
                            sibling->children[sibling->childrenCount-1] = 0;
                            sibling->childrenCount--;
                        }
                    }
                    else
                    {
                        if(i+1 < parent->childrenCount && parent->children[i+1] !=0)
                        {
                            Node* sibling = parent->children[i+1];
   
                            node->items[node->itemCount] = parent->items[i];
                            node->itemCount++;
                            parent->items[i] = 0;
                            for (int j = i; j < parent->itemCount-1; j++)
                            {
                                parent->items[j] = parent->items[j+1];
                            }
                            parent->itemCount--;
                            parent->items[parent->itemCount] = 0;

                            parent->children[i+1] = 0;
                            for (int j = i + 1; j < parent->childrenCount-1; j++)
                            {
                                parent->children[j] = parent->children[j+1];
                            }                            
                            parent->childrenCount--;
                            parent->children[parent->childrenCount] = 0;

                            for (int j = 0; j < sibling->itemCount; j++)
                            {
                                node->items[node->itemCount] = sibling->items[j];
                                node->itemCount++;
                                sibling->items[j] = 0;
                            }

                            for (int j = 0; j < sibling->childrenCount; j++)
                            {
                                node->children[node->childrenCount] = sibling->children[j];
                                node->childrenCount++;
                                sibling->children[j] = 0;
                            }
                            delete sibling;
                        }
                        else if(i>0 && parent->children[i-1] !=0)
                        {
                            Node* sibling = parent->children[i-1];
                       
                            sibling->items[sibling->itemCount] = parent->items[i-1];
                            sibling->itemCount++;
                            parent->items[i-1] = 0;                                
                            for (int j = i-1; j < parent->itemCount-1; j++)
                            {
                                parent->items[j] = parent->items[j+1];
                            }
                            parent->itemCount--;
                            parent->items[parent->itemCount] = 0;

                            parent->children[i]=0;
                            for (int j = i; j < parent->childrenCount-1; j++)
                            {
                                parent->children[j] = parent->children[j+1];
                            }
                            parent->childrenCount--;
                            parent->children[parent->childrenCount] = 0;                                

                            for (int j = 0; j < node->itemCount; j++)
                            {
                                sibling->items[sibling->itemCount] = node->items[j];
                                sibling->itemCount++;
                                node->items[j] = 0;
                            }
                            
                            for (int j = 0; j < node->childrenCount; j++)
                            {
                                sibling->children[sibling->childrenCount] = node->children[j];
                                sibling->childrenCount++;
                                node->children[j] = 0;
                            }

                            delete node;
                        }
                    }
                }
            }
        }
    }

    static void moveMax(Node* node, Node* parent, Item *&itemPtr)
    {
        Item *item;
        if(node->isLeaf())
        {
 
            item = node->items[node->itemCount-1];
            node->items[node->itemCount-1] = 0;
            node->itemCount--;
            itemPtr = item;

            balance(node, parent);
        }
        else
        {
            moveMax(node->children[node->childrenCount-1], node, itemPtr);
            balance(node, parent);
        }
    }

    static void moveMin(Node* node, Node* parent, Item *&itemPtr)
    {
        Item *item;
        if(node->isLeaf())
        {

            item = node->items[0];
            node->items[0] = 0;
            for(int i=0; i < node->itemCount-1; i++)
            {
                node->items[i] = node->items[i+1];
            }            
            node->itemCount--;
            node->items[node->itemCount] = 0;

            itemPtr = item;
            balance(node, parent);
        }
        else
        {
            moveMin(node->children[0], node, itemPtr);
            balance(node, parent);
        }
    }

    Node* removeValue(int val, Node* parent, bool found)
    {
        if(this->isLeaf() && this->itemCount == 0)
        {
            return this;
        }    
        if (remove(val, parent, found))
        {
            if(this == 0)
            {
                int j= 4;
            }
            if(this->itemCount==0 && this->childrenCount > 0)
            {
                if (children[0]==0)
                    int fsd=0;
                return children[0];
            }
        }
        return this;
    }

    bool remove(int val, Node* parent, bool found)
    {
        vector<Result*> results;
        int before = results.size();
        int index = itemFind(val, 0, itemCount, results);
        int after = results.size();


        int half = (m-1) /2;

        if(after - before > 0)
        {
            int index = results[0]->index;
            delete(items[index]);
            items[index] = 0;
            Item* item;
            if(this->isLeaf())
            {
                for(int i=index; i < itemCount; i++)
                {
                    items[i] = items[i+1];   
                }
                itemCount--;
            }
            else if (children[index] != 0)
            {
                moveMax(children[index], this, items[index]);
            }
            else if (children[index+1] != 0)
            {
                moveMin(children[index+1], this, items[index]);

            }  

            balance(this, parent);
            return true;
        }
        else
        {
            bool childFound = false;
            if(val < items[index]->value)
            {
                if (children[index] != 0)
                    childFound = children[index]->remove(val, this, found);
            }
            else
            {
                if (children[index+1] != 0)
                    childFound = children[index+1]->remove(val, this, found);
            }

            if (childFound) 
            {
                balance(this, parent);
            }
            return childFound;
        }
    }

    bool isLeaf()
    {      
        if (childrenCount == 0)
            return true;  
        return false;
    }

    bool isFull()
    {
        if (itemCount != (m-1))
            return false;
        return true;
    }

    Node(int m)
    {
        this->m = m;

        items = new Item*[m-1]();
        for (int i=0; i < m-1; i ++)
        {
            items[i] = 0;
        }
        itemCount = 0;

        children = new Node*[m]();
        for (int i=0; i < m; i ++)
        {
            children[i] = 0;
        }
        childrenCount = 0;
        
    }  

    static void addToNode(Node* node, Item* item, int start, int end)
    {

        if (end == 0 && start == 0)
        {
            node->items[start] = item;
            node->itemCount++;
        }
        else if (end - start < 2)
        {            
            for(int i=node->itemCount; i>start+1; i--)
            {
               node->items[i] = node->items[i-1];
            }
            
            if (item->value < node->items[start]->value)
            {
                node->items[start+1] = node->items[start];
                node->items[start] = item;
            }            
            else
            {
                node->items[start+1] = item;
            }
            node->itemCount++;
        }
        else
        {
            int half = (end - start) / 2;
            if(item->value < node->items[start+half]->value)
                addToNode(node,item,start,start + half);
            else
                addToNode(node,item, start + half,end);
        }
        
    }

    Node* add(Item* item, Node* parent) 
    {          
        if(isLeaf())
        {
            addToNode(this, item, 0, this->itemCount);        
        }
        else
        {
            bool branched = false;
            for(int i=0; i< this->itemCount && branched == false; i++)
            {
                if(item->value <= items[i]->value)
                {
                    children[i]->add(item, this);
                    branched = true;
                }
            }
            if (!branched && children[itemCount] != 0)
            {
                children[itemCount]->add(item, this);
            }            
        }

        if(isFull())
        {            
            int half = (m-1) /2;

            Node* rnode = new Node(m);

            
            for(int i=half+1; i < m ; i++)
            {
                if (i < (m-1))
                {
                    addToNode(rnode, items[i], 0, rnode->itemCount);
                    items[i] = 0;
                    itemCount--;
                }
                if (children[i] != 0)
                {
                    rnode->children[i - half - 1] = children[i];
                    rnode->childrenCount++;

                    children[i] = 0;
                    childrenCount--;                
                }
            }

            if (parent == 0)
            {
                 Node* mnode = new Node(m);
                 addToNode(mnode, items[half], 0, mnode->itemCount);
                 items[half] = 0;
                 itemCount--;

                 mnode->children[0] = this;
                 mnode->children[1] = rnode;
                 
                 mnode->childrenCount += 2;
                 

                 return mnode;
            }
            else
            {
                addToNode(parent, items[half], 0, parent->itemCount);
                items[half] = 0;
                itemCount--;
                bool found = false;
                for(int i=parent->childrenCount-1; i >= 0 && found == false ; i--)
                {
                    if (parent->children[i] == this)
                    {
                        parent->children[i+1] = rnode;
                        parent->childrenCount++;
                        found = true;   
                    }
                    else
                    {
                        parent->children[i+1] = parent->children[i];
                    }
                }
            }   
        }
        return this; 
    }
};