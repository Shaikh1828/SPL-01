#include<bits/stdc++.h>
using namespace std ;

class FoodPackage ;
vector <FoodPackage> foods;

class FoodPackage
{
    public :
        string package ;
        int cost ;
        
        FoodPackage()
        {

        }

        FoodPackage( int i )
        {
            foodUpdate() ;
        }

        void foodUpdate()
        {
            foods.clear();
            ifstream my_file;
            my_file.open( "foods.txt", ios::in );
            if ( !my_file ) 
            {
                cout << "No such file of food ";
            }
            else 
            {
                string Package;
                int Price ;
                
                while ( 1 ) 
                {
                    FoodPackage addFood;
                    if (my_file.eof())
				        break;
                    my_file >> Package >> Price ;
                    
                    addFood.package = Package ;
                    addFood.cost = Price ;
                    
                    foods.push_back(addFood) ;
                }
            }

            my_file.close();
        }

        void showFoodList()
        {
            for( int i=0 ; i < foods.size() ; i++ )
            {
                cout << i+1 << ". " << foods[i].package << " : \t$ " << foods[i].cost << endl << endl ; 
            }
        }

};

// int main()
// {
//     FoodPackage f1(1);
//     f1.showFoodList() ;

// }