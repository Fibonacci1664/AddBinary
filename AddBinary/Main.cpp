#include<iostream>
#include <vector>
#include<string>

void checkVecs(std::vector<int> vecA, std::vector<int> vecB)
{
	std::cout << "Binary (a): ";

	for (int i = 0; i < vecA.size(); ++i)
	{
		std::cout << vecA[i] << ", ";
	}

	std::cout << '\n';

	std::cout << "Binary (b): ";

	for (int i = 0; i < vecB.size(); ++i)
	{
		std::cout << vecB[i] << ", ";
	}
}

std::string addBinary(std::string a, std::string b)
{
	// Check
	//std::cout << "a: " << a << " || b: " << b << '\n';

	// Check whether strings are same size
	// If not we need to pad with zeros
	if (a.size() != b.size())
	{
		// Pad (a) with zeros
		if (a.size() < b.size())
		{
			while (a.size() != b.size())
			{
				// Keep padding zeros onto front of string until the strings are the same size
				a.insert(a.begin(), '0');
			}
		}
		else		// Pad (b) with zeros
		{
			while (b.size() != a.size())
			{
				// Keep padding zeros onto front of string until the strings are the same size
				b.insert(b.begin(), '0');
			}
		}
	}

	// Check
	//std::cout << "a: " << a << " || b: " << b << '\n';

	// Once strings are the same size we can add
	std::vector<int> bin1;
	std::vector<int> bin2;

	// Now both strings are same length we only need one loop to populate both vecs
	for (int i = 0; i < a.size(); ++i)
	{
		// -48 to convert from ASCII val to int.
		int aVal = a[i] - 48;
		int bVal = b[i] - 48;

		bin1.push_back(aVal);
		bin2.push_back(bVal);
	}

	// Check vecs have populated correctly
	//checkVecs(bin1, bin2);

	std::vector<int> ans;
	int carry = 0;
	int result = 0;

	for (int i = a.size() - 1; i >= 0; --i)
	{
		int aVal = a[i] - 48;
		int bVal = b[i] - 48;

		result = carry + aVal + bVal;

		if (result == 0)
		{
			ans.push_back(0);
			carry = 0;
		}
		else if (result == 1)
		{
			ans.push_back(1);
			carry = 0;
		}
		else if (result == 2)
		{
			ans.push_back(0);
			carry = 1;
		}
		else if (result == 3)
		{
			ans.push_back(1);
			carry = 1;
		}
	}

	// If we get this far and there is still a carry it means the LSB overflowed
	// so add another 1 to the end of the vec
	if (carry == 1)
	{
		ans.push_back(1);
	}

	// The vec is is the reverse order, so reverse it to correct it
	std::reverse(ans.begin(), ans.end());

	//std::cout << "\nAns vec: ";

	std::string strAns = "";

	// Populate new string with vec indice values
	for (int i = 0; i < ans.size(); ++i)
	{
		//std::cout << ans[i] << ", ";
		strAns += std::to_string(ans[i]);
	}

	return strAns;
}

int main()
{
	// TEST CASES
	std::string test1Bin1 = "111";
	std::string test1Bin2 = "1";

	std::string finalAns = addBinary(test1Bin1, test1Bin2);

	std::cout << test1Bin1 << "(bin) + " << test1Bin2 << "(bin) = " << finalAns << "(bin)\n";

	return 0;
}