
#include <cstdlib>
#include <iostream>
#include "item.h"
#include <gsl/gsl_rng.h>

int main(int argc, char* argv[])
{
   
   Item *item1 = new Item();
   Item *item2 = new Item();
   
   delete item1;
   delete item2;

   ItemType *it = new LJParticle3DType;
   ItemFactory *itFact1 = new ItemFactory(it);
   itFact1->setMode(rndm);
   Item *item3 = itFact1->create();
   ItemList *l = itFact1->create(10);
   
   delete itFact1;

   delete item3;
   
   for (int ii = 0; ii < 10; ii++) {
      std::cout << "Item is at position " << (*l)[ii]->getPosition() << std::endl;
      delete (*l)[ii];
   }
   
   delete l;
   
}

