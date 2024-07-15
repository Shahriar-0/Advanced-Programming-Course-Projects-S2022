#ifndef __OBJECT_HH__
#define __OBJECT_HH__

class Object {
public:
    Object(int _id);
    virtual void add_to_box(Object* obj) = 0;
    virtual int get_evaluated() = 0;
    virtual int get_weight() = 0;
    bool operator ==(int _id) const;    
protected:
    int id;
};

#endif