#include "Sample.h"
#include "Dataset.h"
#include "Prediction.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cmath>
/*
- Jako argumenty wiersza poleceń programu, przekaż nazwę pliku oraz liczbę całkowitą `k`,
- dla celów testowych, w repozytorium znajduje się plik `wine.csv`,
- wczytaj plik `wine.csv` do wektora obiektów typu `Sample` tak, aby pierwsza jego kolumna określała `label`, a pozostałe znalazły się w wektorze `features`,
- stwórz dwa obiekty klasy `Dataset`. Pierwszy nazwij `train`, drugi `test`,
- do `train` wprowadź losowe 20% wczytanych z pliku obiektów, a do `test`, resztę,
- zaimplementuj funkcję `knn()`, zwracającą wektor obiektów klasy `Prediction` przyjmującą jako argumenty dwa obiekty typu `Dataset` (`train` i `test`) i zmienną całkowitą `k`:
    - utwórz w niej wektor `predictions`:
    - do utworzonego wektora wprowadź kopie wszystkich obiektów (mają typ `Sample`) znajdujących się w `test`, uzupełniając dla nich wartość `prediction`, według następującego schematu:

>   Dla każdego obiektu ze zbioru testowego znajdź `k` obiektów ze zbioru uczącego, którego cechy (`features`) znajdują się w najmniejszej od niego [odległości](https://pl.wikipedia.org/wiki/Odległość). Za `prediction` uznaj `label`, który powtarza się najczęściej wśród znalezionych.
>   

- Wyświetl użytkownikowi informacje o zbiorze (nazwa pliku, liczba próbek, liczba cech) oraz jakość klasyfikacji (`accuracy()`).
*/

using namespace std;

vector <Prediction *> knn(Dataset *train, Dataset *test, int k);

int main(int argc, char const *argv[])
{
		int k = atoi(argv[2]);
		string filename = argv[1];
		fstream file;
		file.open(filename,ios::in);
		int x=0;
		vector<Sample*> wines;
		vector<float> v;
		string line;
		if(file.good())
		{	while(getline(file,line))
			{
				stringstream lineStream(line);
				string cell;
					while(getline(lineStream,cell,','))
					{
						v.push_back(atof(cell.c_str()));
					}
				x=*(v.begin());
				
				v.erase(v.begin());
				Sample testowy(x,v);
				
				wines.push_back(&testowy);
				v.clear();

			}
		}	
		Dataset train,test;

		srand(time(NULL));
		int random;

		for (unsigned int i = 0; i < ((2*wines.size())/10); ++i)
			{
				random=rand()%wines.size();

				train.push_back_Sample(wines[random]);
				wines.erase(wines.begin()+random);

			}
		for ( unsigned int i = 0; i < wines.size(); ++i)
			{
				test.push_back_Sample(wines[i]);

			}
		wines.clear();
		vector<Prediction*> vec;
		
												
		

		cout<<"Nazwa pliku: "<<filename<<endl;
		cout<<"Liczba probek: "<<train.getter_data().size()+test.getter_data().size()<<endl;
		cout<<"Liczba cech: "<<((*((test.getter_data())[0])).getter_features()).size()<<endl;
		cout<<"Jakosc klasyfikacji: "<<Prediction::accuracy(knn(&train,&test,k))<<endl;
}
vector <Prediction *> knn(Dataset *train, Dataset *test, int k)
{
	
vector<Prediction*> predictions;
int size_2=(train->getter_data()).size();
float distance[2][size_2];	
vector<float> vec1,vec2;
	for (unsigned int i = 0; i < (test->getter_data()).size(); ++i)
	{
		float w=0;
		float x=0;
		float poww=0;
		vec1=(*(test->getter_data())[i]).getter_features();
		int size_1=((*((test->getter_data())[i])).getter_features()).size();
		for (int p = 0; p < size_2; ++p)
		{	w=0;
			int size=((*((train->getter_data())[p])).getter_features()).size();
			vec2=(*((train->getter_data())[p])).getter_features();
			for (int z = 0; (z< size)&&(z<size_1); ++z)
			{
				x=vec1[z]-vec2[z];
				poww=pow(x,2);
				w+=poww;
			}
			
			distance[0][p]=sqrt(w);
			distance[1][p]=p;

		}
		float sort,sort2;
		for (int j =0 ; j <size_2-1; ++j)
		{
			for (int l = 0; l < size_2-1; ++l)
			{
				if (distance[0][l]<distance[0][l+1])
				{
					sort=distance[0][l];
					distance[0][l]=distance[0][l+1];
					distance[0][l+1]=sort;
					
					sort2=distance[1][l];
					distance[1][l]=distance[1][l+1];
					distance[1][l+1]=sort2;

				}
			}
		}
		int index;
		int tab_of_labels[k];
		if (k<=size_2)
			for (int n = 0; n < k; ++n)
			{	
				index=distance[1][n];
				tab_of_labels[n]=(*((train->getter_data())[index])).getter_label();
			}
		int repeat[2][k];	
		for( int y = 0; y <k; ++y)
		{	repeat[1][y]=tab_of_labels[y];
			for (int r = 0; r < k; ++r)
			{
					if (tab_of_labels[y]==tab_of_labels[r])
					{
						
						repeat[0][y]+=1;
					}
			}
		}
		int sort3,sort4;
		for(int j =0 ; j < k-1; ++j)
		{
			for(int l = 0; l < k-1; ++l)
			{
				if (repeat[0][l]<repeat[0][l+1])
				{
					sort3=repeat[0][l];
					repeat[0][l]=repeat[0][l+1];
					repeat[0][l+1]=sort3;
					
					sort4=repeat[1][l];
					repeat[1][l]=repeat[1][l+1];
					repeat[1][l+1]=sort4;

				}
			}
		}



		


		Prediction* dada=new Prediction(*((test->getter_data())[i]),repeat[1][0]);

		predictions.push_back(dada);
	}
		

	

	return predictions;
}		