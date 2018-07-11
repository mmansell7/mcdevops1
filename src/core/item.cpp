
#include <cstdlib>
#include <iostream>
#include "item.h"

Item::Item() {
   std::cout << "Item object has been created." << std::endl;
   position = 0.0;
}

Item::Item(const Item &item) {  // Copy constructor
   std::cout << "An Item object has been copied by its copy constructor." << std::endl;
}

Item::~Item() {   // Destructor
   std::cout << "Item object destroyed." << std::endl;
}

ItemPosition Item::getPosition() {
   std::cout << "Item object position is: " << "{xx,xx,xx}" << std::endl;
   return position;
}

void Item::move(ItemPosition&) {
   std::cout << "Item object is being moved." << std::endl;
}

