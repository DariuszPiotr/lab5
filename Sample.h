#pragma once
#include <vector>
/*
- Stwórz klasę `Sample`, zawierającą:
    - zmienną całkowitą `label`,
    - wektor liczb zmiennoprzecinkowych `features`,
- w konstruktorze klasy `Sample` przyjmuj oba te parametry,
- stwórz też dla nich *gettery*.
*/
using namespace std;
class Sample
{
 	private: 
 		int label;
 		vector<float> features;
 	public: 
 		Sample(int a,vector<float> b);
 		int getter_label() const 
 		{
 			return label;
 		}
 		vector<float> getter_features() const
 		{
 			return features;
 		}


	
};