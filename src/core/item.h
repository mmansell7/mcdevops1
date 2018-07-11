#ifndef MCDEVOPS1_ITEM_H
#define MCDEVOPS1_ITEM_H

typedef double ItemPosition;

class Item {
public:
  Item();                        // Default constructor
  Item(const Item&);             // Copy constructor
  ~Item();                       // Destructor
  ItemPosition getPosition();
  void move(ItemPosition&);

private:
  ItemPosition position;

};

#endif  // MCDEVOPS1_ITEM_H
