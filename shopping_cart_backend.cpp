#include<iostream>
#include"data_model.cpp"
#include<vector>
using namespace std;

//list of Products.
vector<Product> AllProduct = {
    Product(12,"apple",30),
    Product(13,"Fash-wash",100),
    Product(14,"body-lotion",210),
    Product(15,"T-shirt",300),
    Product(16,"jeans",1200),
    Product(17,"water_bottle",130),
    Product(18,"Parker-Pen",20),
};


//function to choose an product from available list.
Product* choose_product(){

    cout << " Please choose an product from below list : " << endl;
    string Product_list;                    // we will store product name only in this string

    for(auto pro : AllProduct){
    Product_list.append(pro.display_product()+"\n");
    }

    cout << Product_list << endl;
    cout << "---------------------------------------"<< endl;
    string choice;
    cin >> choice;      //choose an product from given list
    
    for ( int i=0;i<AllProduct.size();i++){         //finding location of choosen product and returning it.
        if(AllProduct[i].nick_name()==choice){
            return &AllProduct[i];
        }
    }
    cout << "product not found"<<endl;          //if product not find in product list or product not available
    return NULL;

}

bool checkout(cart & Cart){
    if(Cart.isempty())return false;

    cout << "please pay in cash"<< endl;
    int total = Cart.items_total();
    int paid;
    cin>> paid;

    if(paid>=total){
        cout << "change is :" << paid-total << endl;
        cout << "Thankyou for shopping with us"<< endl;
        return true;
    }

    else{
        cout << "Not enough cash" << endl;
        return false;
    }
}

int main(){
    char action;
    cout << "choose an action "<< endl;
    cart Cart;
    while(true){
        cout << "a to add an item \nv to view cart \nc to checkout "<< endl;
        cin>> action;
        if(action =='a'){
            Product *product = choose_product();
            if(product){
                cout << product->display_product() << " is added to cart "<< endl;
                Cart.Add(*product);
            }
        }
        else if ( action == 'v'){
            cout << "------------------------------------------\n";
            cout << Cart.view_cart();
            cout << "\n------------------------------------------\n";


        }
        else if ( action=='c'){
            Cart.view_cart();
            if(checkout(Cart)){
                break;
            }
        }
        else{
            cout << " enter an valid action" << endl;
        }
    }
}