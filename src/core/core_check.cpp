
#include <cstdlib>
#include <iostream>
#include "item.h"


int main(int argc, char* argv[])
{
   
   Item *item1 = new Item();
   Item *item2 = new Item();
   
   delete item1;
   delete item2;

   ItemFactory *itFact1 = new ItemFactory();
   Item *item3 = itFact1->create();
   ItemList *l = itFact1->create(10);
   
   delete itFact1;

   delete item3;
   
   for (int ii = 0; ii < 10; ii++) {
      delete (*l)[ii];
   }
   
   delete l;
   
}

