#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <cstdlib>

using namespace std;

struct Review
{
	string title;
	int rating;
	double price;
};

bool FillReview(Review& review)
{
	cout << "Enter book title (quit to quit): ";
	getline(cin, review.title);
	if (review.title == "quit")
		return false;
	cout << "Enter book rating: ";
	cin >> review.rating;
	if (!cin)
		return false;
	while (cin.get() != '\n')
		continue;
	cout << "Enter book price: ";
	cin >> review.price;
	if (!cin)
		return false;
	while (cin.get() != '\n')
		continue;
	return true;
}

void ShowReview(const Review& review)
{
	cout << review.rating;
	cout.precision(2);
	auto config = cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "\t" << review.price << "\t" << review.title << endl;
	cout.setf(config);
}

bool operator<(shared_ptr<Review>p1, shared_ptr<Review>p2)
{
	if (p1->title < p2->title)
		return true;
	else
		return false;
}
bool RatingSort(shared_ptr<Review>p1, shared_ptr<Review>p2)
{
	if (p1->rating < p2->rating)
		return true;
	else
		return false;
}
bool PriceSort(shared_ptr<Review>p1, shared_ptr<Review>p2)
{
	if (p1->price < p2->price)
		return true;
	else
		return false;
}

int main()
{
	vector<shared_ptr<Review>>books;
	while (1)
	{
		shared_ptr<Review>temp(new Review);
		if (FillReview(*temp))
		{
			books.push_back(temp);
			continue;
		}
		break;
	}
	if (cin) 
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
	}
	system("cls");
	cout << "Press 1-> orginal order\t2-> Alphabetical order\t3-> Rating(H->L)\n";
	cout << "Press 4-> Rating(L->H)\t5-> Price(L->H)\t6-> Price(H->L)\n";
	cout << "\tQ-> Quit\n";
	cout << "Your choice -> ";
	char choice;
	cin >> choice;
	system("cls");
	while (choice != 'Q'|| tolower(choice) != 'q')
	{
		while (cin.get() != '\n')
			continue;
		auto sorted = books;
		switch (choice)
		{
		case '1':
				break;
		case '2': 
			sort(sorted.begin(), sorted.end());
			break; 
		case '3':
			sort(sorted.rbegin(), sorted.rend(), RatingSort);
			break;
		case '4':
			sort(sorted.begin(), sorted.end(), RatingSort);
			break;
		case '5':
			sort(sorted.begin(), sorted.end(), PriceSort);
			break;
		case '6':
			sort(sorted.rbegin(), sorted.rend(), PriceSort);
			break;
		default:
			goto invalid_input;
		}
		cout << "Rating:\tPrice:\tTitle:\n";
		for (auto& x : sorted)
			ShowReview(*x);
		invalid_input:
		cout << "Press 1-> orginal order\t2-> Alphabetical order\t3-> Rating(H->L)\n";
		cout << "Press 4-> Rating(L->H)\t5-> Price(L->H)\t6-> Price(H->L)\n";
		cout << "\tQ-> Quit\nYour choice -> ";
		cin >> choice;//?
		system("cls");
	}
	cout << "Bye!\n";
}