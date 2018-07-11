#include <vector>
#include <string>
#include <gsl/gsl_rng.h>

#ifndef MCDEVOPS1_ITEM_H
#define MCDEVOPS1_ITEM_H

class ItemPosition {
public:
   ItemPosition();
   ~ItemPosition();
   int getLen();
   double * getVals();

private:
   int len;
   double *vals;
};

class ItemMove {

};

class ItemType {
public:
   ItemType();
   ~ItemType();

protected:

private:
   
};

class Item {
public:
   static int itemCount;
   Item();                        // Default constructor
   Item(const Item&);             // Copy constructor
   ~Item();                       // Destructor
   virtual std::string getPosition();
   virtual void setPosition(ItemPosition*);
   virtual void setPositionRand(gsl_rng*);
   virtual void move(ItemMove*);

private:
   ItemPosition *position;
   ItemType *itemType;
};


typedef std::vector<Item*> ItemList;
enum ItemFactoryMode {rndm,lattice};

class ItemFactory {
public:
   ItemFactory();
   ItemFactory(const ItemFactory&);
   ItemFactory(ItemType *const);
   ~ItemFactory();
   void setType(ItemType *const);
   void setMode(const ItemFactoryMode);
   Item * create();
   ItemList * create(const int);

private:
   ItemType *itemType;
   ItemFactoryMode mode;
   gsl_rng *rng;
};

/*class ItemList {
public:
   ItemList();
   ~ItemList();
   std::vector<Item*> list;

private:
};*/

class PointParticle : public Item {
public:
   PointParticle();
   ~PointParticle();

private:
   
};

class PointParticleType : public ItemType {
public:
   PointParticleType();
   ~PointParticleType();

private:

};



class LJParticle3D : public PointParticle {
public:
   LJParticle3D();
   ~LJParticle3D();
   std::string getPosition();

private:

};

class LJParticle3DType : public PointParticleType {
public:
   LJParticle3DType();
   ~LJParticle3DType();

private:


};

#endif  // MCDEVOPS1_ITEM_H
