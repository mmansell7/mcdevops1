
#include <cstdlib>
#include <iostream>
#include "item.h"
#include <vector>
#include <gsl/gsl_rng.h>
#include <string>

unsigned long int seed = 12345;

// --------------------------------------- ItemPosition ---------------------------------------- //

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

// ------------------------------------------ Item --------------------------------------------- //

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

std::string Item::getPosition() {
   std::string posstr =  "{xx,xx,xx}";
   return posstr;
}

void Item::setPosition(ItemPosition *pos) {
   std::cout << "Item object position is being set." << std::endl;
}

void Item::setPositionRand(gsl_rng *rng) {
  
} 

void Item::move(ItemMove *m) {
   std::cout << "Item object is being moved." << std::endl;
}

// --------------------------------------- ItemFactory ----------------------------------------- //

ItemFactory::ItemFactory() {
   std::cout << "ItemFactory object has been created." << std::endl;
   rng = gsl_rng_alloc(gsl_rng_taus2);
   gsl_rng_set(rng,seed);
}

ItemFactory::ItemFactory(const ItemFactory&) {
   std::cout << "ItemFactory object has been copied." << std::endl;
}

ItemFactory::ItemFactory(ItemType *const it) {
   std::cout << "ItemFactory object has been created with a specified item type." << std::endl;
   this->setType(it);
   rng = gsl_rng_alloc(gsl_rng_taus2);
   gsl_rng_set(rng,seed);
}

ItemFactory::~ItemFactory() {
   std::cout << "ItemFactory object has been destroyed." << std::endl;
}

void ItemFactory::setType(ItemType *const it) {
   std::cout << "Setting ItemFactory object to produce items of certain type." << std::endl;
   itemType = it;
}

Item * ItemFactory::create() {
   Item *pitem = new Item();
   switch (mode)
   {
      case rndm:
         std::cout << "Item being created by ItemFactory object in random mode." << std::endl;
         pitem->setPositionRand(rng);
         break;
      default:
         std::cout << "ItemFactory object has invalid create mode. Exiting application." << std::endl;
         exit(EXIT_FAILURE);
   }
   return pitem;
}

ItemList * ItemFactory::create(const int n) {
   ItemList *l = new ItemList(n,NULL);
   for (int ii = 0; ii < n; ii++) {
      std::cout << "Creating item # " << ii << " in ItemList object." << std::endl;
      (*l)[ii] = this->create();
   }
   std::cout << "l within create func is " << l << std::endl;
   return l;
}

void ItemFactory::setMode(const ItemFactoryMode m) {
   mode = m;
}


// ------------------------------------------ ItemType ----------------------------------------- //

ItemType::ItemType() {
}

ItemType::~ItemType() {
}



// ------------------------------------- PointParticleType ------------------------------------- //

PointParticleType::PointParticleType() {
}

PointParticleType::~PointParticleType() {
}


// ------------------------------------- PointParticle ---- ------------------------------------- //

PointParticle::PointParticle() {
}

PointParticle::~PointParticle() {
}


// -------------------------------------- LJParticle3DType -------------------------------------- //

LJParticle3DType::LJParticle3DType() {
}

LJParticle3DType::~LJParticle3DType() {
}


// -------------------------------------- LJParticle3D ------------------------------------------ //

LJParticle3D::LJParticle3D() {
}

LJParticle3D::~LJParticle3D() {
}

std::string LJParticle3D::getPosition() {
   std::string posstr = "{xx,xx,xx}";
   return posstr;
}



// --------------------------------------------------------------------------------------------- //
