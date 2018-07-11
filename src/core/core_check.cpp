
#include <cstdlib>
#include <iostream>
#include "item.h"

//Item::itemCount = 7;

int main(int argc, char* argv[])
{
   
   Item *item1 = new Item();
   Item *item2 = new Item();
   
   delete item1;
   delete item2;

   ItemFactory *itFact1 = new ItemFactory();
   Item *item3 = itFact1->create();

   delete itFact1;

   delete item3;
  
}

