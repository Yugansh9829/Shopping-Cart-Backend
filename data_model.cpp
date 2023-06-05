#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class item;
class cart;

class Product{

    int id;
    string name;
    int price;
    public:
    Product(){

    }
    Product(int id,string name,int price){
        this->id = id;
        this->name = name;
        this->price = price;
    }
    string display_product(void){

        return  name + "    @:" + to_string(price);

    }

    // string display_name(void){
    //     return name;
    // }
    string nick_name(void){
        return name.substr(0,1);
    }
    friend item;
    friend cart;
};

class item{
    Product Pro;
    int quantity;
    
    public:
    item(){

    }
        item(Product P , int q) : Pro(P),quantity(q){};  // constructor using initialization.
        
        int get_price(){
            return Pro.price *quantity;
        }

        string item_info(){
            return to_string(quantity) + " * " + Pro.name + " Rs " + to_string(Pro.price * quantity);
        }
        friend cart;
};


class cart{
    unordered_map<int,item> Items;
    public:
    void Add(Product product){                  //takes input the product which we wanna add in cart
        if(Items.count(product.id)==0){
            item newitem(product,1);            //it creates a new item object named as newitem and as we added for first time therefore quantity is set to 1
            Items[product.id]= newitem;
        }
        else{
            Items[product.id].quantity++;
            
        }
    }
    int items_total(){
        int total=0;
        for(auto eachitem : Items){
            total += eachitem.second.get_price();
        }
        return total;
    }

    string view_cart(){
        string itemlist;
        int total = items_total();

        for(auto itemPair : Items){
            item temp = itemPair.second;
            itemlist.append(temp.item_info() + "\n");
        }
        return itemlist + "\nTotal amount : Rs " + to_string(total);
    }

    bool isempty(){
        return Items.empty();
    }
};