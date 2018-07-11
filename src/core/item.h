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


class Item {
public:
   static int itemCount;
   Item();                        // Default constructor
   Item(const Item&);             // Copy constructor
   ~Item();                       // Destructor
   ItemPosition getPosition();
   void setPosition(ItemPosition&);
   void move(ItemPosition&);

private:
   ItemPosition *position;

};

class ItemType {
public:
   ItemType();
   ~ItemType();

protected:

private:
   
};

class ItemFactory {
public:
   ItemFactory();
   ItemFactory(const ItemFactory&);
   ItemFactory(const ItemType&);
   ~ItemFactory();
   void setType(ItemType *const);
   Item * create();

private:
   ItemType *itemType;

};



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

private:

};

class LJParticle3DType : public PointParticleType {
public:
   LJParticle3DType();
   ~LJParticle3DType();

private:


};

#endif  // MCDEVOPS1_ITEM_H
