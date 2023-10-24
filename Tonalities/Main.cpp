#include <iostream>
#include "Tonalities.h"
#include"messages.h"
#include<conio.h>


int main()
{
	Header("Choose notation\n");
	int notation = Trigger("1 - classical european, 0 - scientific american\n");
	

	Tonalities start("Enter start tonality", notation);
	start.Show();
	Tonalities destination("Enter destination tonality", notation);
	destination.Show();

	if (start.equal(destination))
	{
		Header("\nequal!");
		return 0;
	}

	Tonalities enharmonized = start; enharmonized.enharmonize(); enharmonized.ShowInBrackets();
	Tonalities denharmonized = destination; denharmonized.enharmonize(); denharmonized.ShowInBrackets();

	if (enharmonized.equal(destination) || start.equal(denharmonized))
	{
		Header("\nenharmonically equal!");
		return 0;
	}

	if (start.relative(destination))
	{
		Header("\n1st relative!");
		return 0;
	}
	else Message(gray,"\nno 1st relative!\n");

	// 1-а тональність у ланцюгу
	Tonalities transition = start;
	//встановлює 2-у ступінь спорідненості
	bool relative2 = false; 
	//оголошення 2-ї ступені спорідненості
	bool anounced = false;

	for (int i = 1; i < 7; i++)
	{
		transition.transport(i);
		if (transition.relative(destination))
		{
			if(!anounced) Header("\n2nd relative!\n");
			anounced = true;			
			start.ShowName(); cout << " -> ";
			transition.ShowName(); cout << " -> ";
			destination.ShowName(); cout << endl;
			relative2 = true;
		}
		transition = start;
	}

	if(!relative2)
	{
		for (int i = 1; i < 7; i++)
		{
			transition.transport(i);
			
			if (transition.relative(denharmonized))
			{
				if (!anounced) Header("\n2nd relative!\n");
				anounced = true;
				start.ShowName(); cout << " -> ";
				transition.ShowName(); cout << " -> ";
				denharmonized.ShowName(); destination.ShowInBrackets(); cout << endl;
				relative2 = true;
			}
			transition = start;
		}
	}
	

	if (!relative2) Message(gray, "\nno 2nd relations!\n");
	else return 0;

	// 2-а тональність у ланцюгу
	Tonalities transition2 = start;

	for (int i = 1; i < 7; i++)
		for (int j = 1; j < 7; j++)
		{
			transition.transport(i);
			transition2 = transition;
			transition2.transport(j);
			if (transition2.relative(destination))
			{
				if (!anounced) Header("\n3rd relative!\n");
				anounced = true;
				start.ShowName(); cout << " -> ";
				transition.ShowName(); cout << " -> ";
				transition2.ShowName(); cout << " -> ";
				destination.ShowName(); cout << endl;
				relative2 = true;
			}
			else if(relative2 = false && transition2.relative(denharmonized))
			{
				if (!anounced) Header("\n3rd relative!\n");
				anounced = true;
				start.ShowName(); cout << " -> ";
				transition.ShowName(); cout << " -> ";
				transition2.ShowName(); cout << " -> ";
				denharmonized.ShowName(); destination.ShowInBrackets(); cout << endl;
				relative2 = true;
			}

			transition = start;
		}

	_getch();

}
