#include <iostream>
#include "Tonalities.h"



int main()
{
	int notation = Trigger("Choose notation. 1 - classical european, 0 - scientific american");
	

	Tonalities start("Enter start tonality", notation);
	start.Show();
	Tonalities destination("Enter destination tonality", notation);
	destination.Show();

	if (start.equal(destination))
	{
		cout << "\nequal!";
		return 0;
	}

	Tonalities enharmonized = start; enharmonized.enharmonize(); enharmonized.ShowInBrackets();
	Tonalities denharmonized = destination; denharmonized.enharmonize(); denharmonized.ShowInBrackets();

	if (enharmonized.equal(destination) || start.equal(denharmonized))
	{
		cout << "\nenharmonically equal!";
		return 0;
	}

	if (start.relative(destination))
	{
		cout << "\n1st relative!";
		return 0;
	}
	else cout << "\nno 1st relative!\n";
	Tonalities transition = start;
	bool relative2 = false;

	for (int i = 1; i < 7; i++)
	{
		transition.transport(i);
		if (transition.relative(destination))
		{
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
			//cout << "\ncheck: "; transition.Show(); denharmonized.Show();
			if (transition.relative(denharmonized))
			{
				start.ShowName(); cout << " -> ";
				transition.ShowName(); cout << " -> ";
				denharmonized.ShowName(); destination.ShowInBrackets(); cout << endl;
				relative2 = true;
			}
			transition = start;
		}
	}
	

	if (!relative2) cout << "\nno 2nd relations!\n";
	else return 0;

	Tonalities transition2 = start;

	for (int i = 1; i < 7; i++)
		for (int j = 1; j < 7; j++)
		{
			transition.transport(i);
			transition2 = transition;
			transition2.transport(j);
			if (transition2.relative(destination))
			{
				start.ShowName(); cout << " -> ";
				transition.ShowName(); cout << " -> ";
				transition2.ShowName(); cout << " -> ";
				destination.ShowName(); cout << endl;
				relative2 = true;
			}
			else if(relative2 = false && transition2.relative(denharmonized))
			{
				start.ShowName(); cout << " -> ";
				transition.ShowName(); cout << " -> ";
				transition2.ShowName(); cout << " -> ";
				denharmonized.ShowName(); destination.ShowInBrackets(); cout << endl;
				relative2 = true;
			}

			transition = start;
		}



}
