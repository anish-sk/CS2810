#include<bits/stdc++.h>
using namespace std;

class Pen{
    int id;// the unique identifier for the pen.
    float width;
    string color,style;
public:
    Pen (int id, float width, string color, string style): id(id), width(width), color(color), style(style){}//constructor of the Pen class.
 ~Pen();//destructor of the Pen class.
 int getId(){
    return id;
    }
 float getWidth(){
    return width;
    }
 string getColor(){
    return color;
    }
 string getStyle(){
    return style;
    }
};

class Pencil{
    int id;// the unique identifier for the pencil.
    float width;
    string hardness_mark,point_size;
public:
    Pencil (int id, float width, string hardness_mark, string point_size): id(id), width(width), hardness_mark(hardness_mark), point_size(point_size){}//constructor of the Pencil class.
 ~Pencil();//destructor of the Pencil class.
 int getId(){
    return id;
    }
 float getWidth(){
    return width;
    }
 string getHmark(){
    return hardness_mark;
    }
string getPointsize(){
    return point_size;
    }
};

class Inventory_Item{
    int id;// the unique identifier for the item
    float price;
    string manufacturer,type;
public:
    static map <int, Inventory_Item*> items; //the static data structure containing the list of items indexed by id.
    static map <int, Pen*> pens;//the static data structure containing the list of items indexed by id.
    static map <int, Pencil*> pencils;//the static data structure containing the list of items indexed by id.
    Inventory_Item (int id, float price, string manufacturer, string type): id(id), price(price), manufacturer(manufacturer), type(type) {}//constructor of the Inventory_Item class.
 //~Inventory_Item();//destructor of the Inventory_Item class.
 int getId(){ 
    return id;
    }
 float getPrice(){
    return price;
    }
 string getManufacturer(){
    return manufacturer;
    }
 string getType() {
    return type;
    }
    
};
map <int, Inventory_Item*> Inventory_Item::items ;
map <int, Pencil*> Inventory_Item::pencils;
map <int, Pen*> Inventory_Item::pens;
Pen::~Pen(){
    Inventory_Item::pens.erase(id);
    if(Inventory_Item::items.find(id)!=Inventory_Item::items.end()){
        Inventory_Item::items.erase(id);
    }
}
Pencil::~Pencil(){

    Inventory_Item::pencils.erase(id);
    if(Inventory_Item::items.find(id)!=Inventory_Item::items.end()){
        Inventory_Item::items.erase(id);
    }
    }
void print_sorted(char ch){
        switch(ch){
            case 'p' :
            for(auto item:Inventory_Item::items){
                cout<<item.second->getId()<<" "<<item.second->getPrice()<<" "<<item.second->getManufacturer()<<" "<<item.second->getType()<<"\n";
            }
            break;
            case 'q' :
            for(auto item: Inventory_Item::pens){
                cout<<item.second->getId()<<" "<<item.second->getWidth()<<" "<<item.second->getColor()<<" "<<item.second->getStyle()<<"\n";
            }
            break;
            case 'r' :
            for(auto item: Inventory_Item::pencils){
                cout<<item.second->getId()<<" "<<item.second->getWidth()<<" "<<item.second->getHmark()<<" "<<item.second->getPointsize()<<"\n";
            }
            break;
            default:
            break;
        }
    } //Prints the list of objects of type Inventory_Item or Pen or Pencil.
int main(){
    int t;cin>>t;
    //Inventory_Item it;
    while(t--){
        char op;
        int id;float x; string c,d;
        Inventory_Item *ite;
        Pen *ite1;
        Pencil *ite2;
        cin>>op;        
        if(op=='a'){
            cin>>id>>x>>c>>d;
            ite = new Inventory_Item(id,x,c,d);
            Inventory_Item::items[id]=ite;
        }
        else if(op=='b'){
            cin>>id>>x>>c>>d;
            ite1 = new Pen(id,x,c,d);
            Inventory_Item::pens[id]=ite1;
        }
        else if (op=='c'){
            cin>>id>>x>>c>>d;
            ite2 = new Pencil(id,x,c,d);
            Inventory_Item::pencils[id]=ite2;
        }
        else if(op =='d'){
            cin>>id;
            auto i = Inventory_Item::pens.find(id);
            if(i!=Inventory_Item::pens.end()){
                delete i->second;
                //Inventory_Item::pens.erase(i);
            }
            else{
                auto j = Inventory_Item::pencils.find(id);
                if(j!=Inventory_Item::pencils.end()){
                delete j->second;
                //Inventory_Item::pencils.erase(j);
            }
            }
        }
        else
            print_sorted(op);
     
        
    }
    
    return 0;
    
}
