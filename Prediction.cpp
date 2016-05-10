#include "Prediction.h"

using namespace std;


Prediction::Prediction(int a,vector<float> b, int pred)
 : Sample(a, b)
{

	prediction=pred;




}
Prediction::Prediction(Sample & k ,int pred): Sample(k)
{
	prediction=pred;


}
float Prediction::accuracy(vector<Prediction*> vec_pred)
{

	int k=0;
	for (unsigned int i = 0; i <vec_pred.size(); ++i)
	{
		if (vec_pred[i]->getter_label()==vec_pred[i]->getter_prediction())
		{
			k+=1;
		}

	}
 	

 	float x=k/vec_pred.size();

 	return x;



}