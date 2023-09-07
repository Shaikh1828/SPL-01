#include<bits/stdc++.h>
using namespace std ;

class FoodPackage
{
    public :
        string package ;
        string cost ;
        vector <FoodPackage> foods;

        void showFoodList()
        {
            for( int i=0 ; i < foods.size() ; i++ )
            {
                cout << i+1 << ". " << foods[i].package << " : " << foods[i].cost << endl ; 
            }
        }

};