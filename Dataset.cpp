#include "Dataset.h"
#include "Sample.h"
#include <iostream>



bool Dataset::push_back_Sample(Sample *d)
{
	/*	static unsigned int rozmiar;
	if(!(vector_of_Sample.size()))
		{
			 rozmiar=(d->getter_features()).size();
		}

	if(rozmiar==(d->getter_features()).size())

	{
		vector_of_Sample.push_back(d);

	}
	else
	{
		std::cout<<"zly rozmiar";
	}*/
		if (!(vector_of_Sample.size()))
		{
			vector_of_Sample.push_back(d);
			return true;
		}
		else if((vector_of_Sample[0]->getter_features()).size()==((d->getter_features()).size()))
		{
			vector_of_Sample.push_back(d); 
			return true;
		}
		else
		{
			return false;
		}




}