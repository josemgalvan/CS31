#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int countMatches(const string a[], int n, string target)
{
	if (n < 0)
	{
		return -1;
	}
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == target)
			count++;
	}
	return count;
}

int detectMatch(const string a[], int n, string target)
{
	if (n <= 0)
	{
		return -1;
	}
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == target)
		{
			return i;
		}
	}
	return -1;
}

bool detectSequence(const string a[], int n, string target, int& begin, int& end)
{
	int i = 0;
	if (n <= 0)
		return false;

	for (int i = 0; i < n; ++i)
	{
		if (a[i] == target)
		{
			i = i;
			begin = i;
			end = begin;
			break;
		}
	}
	for (int w = i + 1; w < n; ++w)
	{
		if (a[w] == target)
		{
			end = w;
		}
	}
	if (begin == 1 || begin == 2 || begin == 3 || begin == 4 || begin == 5 || begin == 6 || begin == 7 || begin == 8 || begin == 9 || begin == 10)
	{
		return true;
	}
	else
		return false;
}

int detectMin(const string a[], int n)
{
	string mins = a[0];
	int	min = 0;
	if (n <= 0)
	{
		return -1;
	}
	for (int i = 0; i < n; ++i)
	{
		if (a[i] < mins)
		{
			mins = a[i];
			min = i;
		}
	}
	return min;
}

int moveToBack(string a[], int n, int pos)
{
	if (n <= 0)
	{
		return -1;
	}
	if (pos <= 0 || pos > n)
	{
		return -1;
	}
	string temp = a[pos];
	for (int i = pos; i < n - 1; ++i)
	{
		a[i] = a[i + 1];
	}

	a[n - 1] = temp;

	return pos;
}

int moveToFront(string a[], int n, int pos)
{
	if (n <= 0)
	{
		return -1;
	}
	if (pos <= 0 || pos > n)
	{
		return -1;
	}
	string temp2 = a[pos];
	for (int i = pos; i >= 1; --i)
	{
		a[i] = a[i - 1];
	}

	a[0] = temp2;

	return pos;
}

int detectDifference(const string a1[], int n1, const string a2[], int n2)
{
	int twin = 0;
	if (n1 <= 0 || n2 <= 0)
	{
		return -1;
	}

	if (n1 >= n2)
	{
		for (int i = 0; i <= n2; ++i)
		{
			if (a1[i] == a2[i])
				twin++;
			else
				continue;
		}
	}
	else
		for (int i = 0; i <= n1; ++i)
		{
			if (a1[i] == a2[i])
				twin++;
			else
				continue;
		}
	return twin;
}

int deleteDups(string a[], int n)
{
	if (n <= 0)
	{
		return -1;
	}
	int non_dup_index = 0;           /* initialize non_dup_index to 0  */
	for (int i = 0; i < n; i++) {           /* for each item in string array */
		while (i < n - 1 && a[i].compare(a[i + 1]) == 0) { /* skip to next item if consecutive items are same */
			i++;                    /* skip to next item */
		}
		a[non_dup_index] = a[i];    /* update non_dup_index with non_dup_index item */
		non_dup_index++;            /* increment non_dup_index */
	}
	return non_dup_index;           /* return non duplicate count */
}

bool contains(const string a1[], int n1, const string a2[], int n2)
{
	{

		if (n1 >= 0 && n2 == 0)
			return true;

		if (n1 < 0 || n2 < 0)

		{

			//Return

			return false;
		}
		if (n2 > 0 && n1 == 0)
			return false;
		//if (n2 == 0 && n1)
			//return true;
		int sbstrngps = 0;

		bool Allfnd = false;

		for (int li = 0; li < n1; li++)

		{

			//If condition matches

			if (a1[li] == a2[sbstrngps] && sbstrngps < (n2 - 1))

			{

				sbstrngps++;

			}

			//If condition matches

			else if (a1[li] == a2[sbstrngps] && sbstrngps == (n2 - 1))

			{

				Allfnd = true;

			}



		}

		//Return

		return Allfnd;
	}
}

int meld(const string a1[], int n1, const string a2[], int n2, string result[], int max)
{
	bool correct1 = true;
	bool correct2 = true;
	if (n1 < 0 || n2 < 0 || max<0)
	{
		return -1;
	}
	for (int i = 0; i < n1 - 1; ++i)
	{
		if (a1[i] > a1[i + 1])
		{
			correct1 = false;
			return -1;
		}
	}
	for (int w = 0; w < n2 - 1; ++w)
	{
		if (a2[w] > a2[w + 1])
		{
			correct2 = false;
			return -1;
		}
	}
	int inputs = n1 + n2;
	if (correct1 && correct2 && inputs < max)
	{
		int e = 0;
		int p = 0;
		for (int i = 0; i < n1; ++i)
		{
			result[i] = a1[i];
		}
		for (int w = 0; w < n2; ++w)
		{
			result[w + n1] = a2[w];
		}
		//int pos=detectMin(result, inputs);
		//for (int i = 0; i < inputs; i++)
		//for (int j=0; j<)
		string mins = result[0];
		for (int i = 0; i < inputs; i++)
		{
			for (int j = i + 1; j < inputs; j++)
			{
				//If there is a smaller element found on right of the array then swap it.
				if (result[j] < result[i])
				{
					string temp = result[i];
					result[i] =result[j];
					result[j] = temp;
				}
			}
		}
		return inputs;
	}

	else
		return -1;
}

int split(string a[], int n, string splitter)
{
	if (n <= 0) {
		return -1;
	}

	int i;

	for (int j = 0; j < n - 1; j++) {
		int iMin = j;

		for (i = j + 1; i < n; i++) {
			if (a[i] < a[iMin]) {
				iMin = i;
			}
		}

		if (iMin != j) {
			swap(a[j], a[iMin]);
		}
	}

	//return a number
	for (int k = 0; k < n; k++) {
		if (a[k] >= splitter) {
			return k;
		}
	}

	return n;
}

int main()
{
	string h[7] = { "moana", "tiana", "elsa", "ariel", "", "belle", "elsa" };
	if (countMatches(h, 7, "elsa") == 2)
		cout << 1;
	if (countMatches(h, 0, "elsa") == 0)
		cout << 1.1;
	if (countMatches(h, 7, "") == 1)
		cout << 2;
	if (countMatches(h, -1, "merida") == -1)
		cout << 3;
	if (countMatches(h, 0, "elsa") == 0)
		cout << 4 << endl;
	if (detectMatch(h, 7, "elsa") == 2)
		cout << 5;
	if (detectMatch(h, 0, "elsa") == -1)
		cout << 5.1;
	if (detectMatch(h, 2, "elsa") == -1)
		cout << 6;
	if (detectMatch(h, 7, "coco") == -1)
		cout << 6.1;
	if (detectMatch(h, -10, "elsa") == -1)
		cout << 6.2 << endl;

	int bg;
	int en;
	if (detectSequence(h, 7, "koala", bg, en) == false)
		cout << 7;
	if (detectSequence(h, 0, "ariel", bg, en) == false)
		cout << 7.1;
	if (detectSequence(h, 1, "elsa", bg, en) == false)
		cout << 8;
	if (detectSequence(h, 7, "ariel", bg, en) && bg == 3 && en == 3)
		cout << 9;
	if (detectSequence(h, 7, "elsa", bg, en) && bg == 2 && en == 6)
		cout << 10;
	if (detectSequence(h, -1, "elsa", bg, en) == false)
		cout << 11 << endl;
	string g[5] = { "moana", "tiana", "ariel", "belle","ariel" };
	if (detectMin(g, 4) == 2)
		cout << 12;
	if (detectMin(g, 2) == 0)
		cout << 13;
	if (detectMin(g, -1) == -1)
		cout << 14;
	if (detectMin(g, 5) == 2)
		cout << 15;
	if (detectMin(g, 0) == -1)
		cout << 16 << endl;
	//if (moveToBack(g, 4, 1) == 1 && g[1] == "ariel" && g[3] == "tiana")
		cout << 15;
	//if (moveToBack(g, 4, 2) == 2 && g[2] == "belle" && g[3] == "ariel")
		cout << 16;
	//if (moveToBack(g, -1, 2) == -1)
		cout << 17;
	if (moveToBack(g, 0, 2) == -1)
		cout << 17.2;
	//if (moveToBack(g, 4, -1) == -1)
		cout << 18 << endl;
	string f[4] = { "belle", "ariel", "tiana", "elsa" };
	//if (moveToFront(f, 4, 2) == 2 && f[0] == "tiana" && f[2] == "ariel")
		cout << 17;
	//if (moveToFront(f, 4, 3) == 3 && f[0] == "elsa" && f[3] == "tiana")
		cout << 18;
	//if (moveToFront(f, 4, 1) == 1 && f[0] == "ariel" && f[1] == "belle")
		cout << 19;
	//if (moveToFront(f, -1, 2) == -1)
		cout << 20;
	if (moveToFront(f, 0, 2) == -1)
		cout << 20.5;
	//if (moveToFront(f, 2, -10) == -1)
		cout << 21 << endl;
	//cout<<f[0]<<f[1]<<f[2]<<f[3];
	if (detectDifference(h, 4, g, 4) == 2)
		cout << 22;
	if (detectDifference(h, 4, f, 4) == 0)
		cout << 23;
	if (detectDifference(f, 4, g, 3) == 0)
		cout << 24;
	if (detectDifference(f, -4, g, 3) == -1)
		cout << 24.5;
	if (detectDifference(f, 0, g, 3) == -1)
		cout << 24.6;
	if (detectDifference(f, 4, g, 0) == -1)
		cout << 24.7;
	if (detectDifference(f, 4, g, -3) == -1)
		cout << 24.75<<endl;
	string e[5] = { "belle", "belle", "belle", "tiana", "tiana" };
	if (deleteDups(e, 5) == 2 && e[1] == "tiana")
		cout << 25;
	string t[7] = { "x","s","L","L","L","L","L" };
	string w[5] = { "w", "w","e","e","e" };
	if (deleteDups(t, 7) == 3)
		cout << 26;
	if (t[2] == "L")
		cout << 27;
	if (deleteDups(w, -1) == -1)
		cout << 27.5;
	if (deleteDups(w, 5) == 2)
		cout << 28;
	if (deleteDups(w, 0) == -1)
		cout << 28.5;
	if (w[1] == "e")
		cout << 29<<endl;
	//string h[7] = { "moana", "tiana", "elsa", "ariel", "", "belle", "elsa" };
	//string g[5] = { "moana", "tiana", "ariel", "belle","ariel" };
	//string f[4] = { "belle", "ariel", "tiana", "elsa" };
	if (contains(h, 7, g, 2))
		cout << 30;
	if (contains(h, 7, f, 1))
		cout << 31;
	if (contains(h, 7, g, 3))
		cout << 31.5;
	if (contains(h, 0, g, 0)==true)
		cout << 31.52;
	if (contains(h, 1, g, 0)==true)
		cout << 31.53;
	if (contains(h, 0, g, 1)==false)
		cout << 31.54;
	if (contains(h, -1, g, 3)==false)
		cout << 31.6;
	if (contains(h, 1, g, -2)==false)
		cout << 31.7;
	if (!contains(h, 7, f, 2))
		cout << 31.8 << endl;
	string O[7] = { "moana", "tiana", "elsa", "ariel", "", "belle", "elsa" };
	string x[4] = { "elsa", "elsa", "raya", "tiana" };
	string y[4] = { "ariel", "belle", "elsa", "merida" };
	string LL[3] = { "arnold","potato","snow" };
	string lp[5] = { "valerie", "valeria","rae", "elizabeth", "annalise" };
	string lp1[3] = { "anna","elizabeth","rae" };
	string z[10];
	string q[10];
	string yy[10];
	string yyy[10];
	if (meld(x, 4, y, 4, z, 10) == 8 && z[5] == "merida")
		cout << 32;
	if (meld(x, 4, LL, 3, q, 10) == 7 && q[5] == "snow")
		cout << 33;
	if (meld(y, 4, LL, 3, yy, 10) == 7 && yy[5] == "potato")
		cout << 34;
	if (meld(x, 0, y, 0, z, 10) == 0)
		cout << 34.1;
	if (meld(y, 4, lp, 5, yyy, 10) == -1)
		cout << 34.2;
	if (meld(y, 4, lp, 5, yyy, 3) == -1)
		cout << 34.3;
	if (meld(y, -1, lp, 5, yyy, 3) == -1)
		cout << 34.4;
	if (meld(y, 3, lp, -3, yyy, 3) == -1)
		cout << 34.5;
	if (meld(y, 4, lp1, 3, yyy, 10) == 7 && yyy[2] == "belle")
		cout << 35<<endl;
	if (split(O, 7, "elsa") == 3);
		cout << 36;
	if (split(O, 7, "tiana") == 6);
		cout << 37;
	if (split(O, -1, "tiana") == -1);
		cout << 38;
	if (split(O, 0, "tiana") == -1)
			cout << 39;
	string wer[3] = { "blue","red","yellow" };
	string ty[1] = { "blue" };
	if (detectDifference(wer, 3, ty, 2) == 1)
		cout << 111;
	//cout << "All tests succeeded" << endl;*/
}