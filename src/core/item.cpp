
#include <cstdlib>
#include <iostream>
#include "item.h"


ItemPosition::ItemPosition() {
   std::cout << "ItemPosition object has been created." << std::endl;
   for(int ii = 0; ii < len; ii++) {
      vals[ii] = 0.0;
   }
}

ItemPosition::~ItemPosition() {
   
}

int ItemPosition::getLen() {
   return len;
}

double * ItemPosition::getVals() {
   return vals;
}


int Item::itemCount = 0;

Item::Item() {
   itemCount++;
   //std::cout << "Item object has been created." << std::endl;
   std::cout << "Item object has been created. Now there are " << itemCount << "." << std::endl;
}

Item::Item(const Item &item) {  // Copy constructor
   std::cout << "An Item object has been copied by its copy constructor." << std::endl;
}

Item::~Item() {   // Destructor
   itemCount--;
   //std::cout << "Item object destroyed." << std::endl;
   std::cout << "Item object destroyed. Now there are " << itemCount << "." << std::endl;
}

ItemPosition Item::getPosition() {
   std::cout << "Item object position is: " << "{xx,xx,xx}" << std::endl;
   return *position;
}

void Item::setPosition(ItemPosition&) {
   std::cout << "Item object position is being set." << std::endl;
}

void Item::move(ItemPosition&) {
   std::cout << "Item object is being moved." << std::endl;
}



ItemFactory::ItemFactory() {
   std::cout << "ItemFactory object has been created." << std::endl;
}

ItemFactory::ItemFactory(const ItemFactory&) {
   std::cout << "ItemFactory object has been copied." << std::endl;
}

ItemFactory::ItemFactory(const ItemType&) {
   std::cout << "ItemFactory object has been copied." << std::endl;
}

ItemFactory::~ItemFactory() {
   std::cout << "ItemFactory object has been destroyed." << std::endl;
}

void ItemFactory::setType(ItemType *const it) {
   std::cout << "Setting ItemFactory object to produce items of certain type." << std::endl;
   itemType = it;
}

Item * ItemFactory::create() {
   std::cout << "Item being created by ItemFactory object." << std::endl;
   Item *pitem = new Item();
   return pitem;
}


