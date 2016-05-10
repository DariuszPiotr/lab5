#pragma once
#include "Sample.h"

/*
- Stwórz klasę `Prediction`, dziedziczącą po klasie `Sample`, dodającą do niej zmienną `prediction`,
- Rozszerz ją o metodę statyczną `accuracy()`, przyjmującą wektor obiektów klasy `Prediction`, informującą o tym, w jakim odsetku ich zmienne `label` i `prediction` mają tę samą wartość.
*/

class Prediction : Sample
{
	private:
		int prediction;

	public:
			Prediction(int a,vector<float> b,int pred);
			Prediction(Sample & k,int pred);
			static float accuracy(vector<Prediction*> vec_pred);
			int getter_prediction() const
			{return prediction;}
};