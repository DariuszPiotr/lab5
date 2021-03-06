#pragma once
#include "Sample.h"
#include <vector>
/*
- Stwórz klasę `Dataset`, zawierającą:
    - wektor obiektów klasy `Sample`,
    - metodę `push_back()`, dodającą nową próbkę do wektora:
        - metoda ta powinna sprawdzać, czy wektor `features` dla każdej z wprowadzanych próbek jest tej samej długości.
*/

class Dataset 
{
	private:
		std::vector<Sample*> vector_of_Sample;

	public:
		bool push_back_Sample(Sample* d);
		vector<Sample*> getter_data() const {
			return vector_of_Sample;
		}




};