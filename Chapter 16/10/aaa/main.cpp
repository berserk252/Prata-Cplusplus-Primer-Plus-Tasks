// vect3.cpp -- using STL functions
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

struct Review {
    std::string title;
    int rating;
    int price;
};

bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool worseThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
bool FillReview(shared_ptr<Review> & rr);
void ShowReview(const shared_ptr<Review> & rr);
bool PworseThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2);
int main()
{


    vector<shared_ptr<Review>> books;
    shared_ptr<Review> temp(new Review);
    while (FillReview(temp))
        books.push_back(temp);

    if (books.size() > 0)
    {
        vector<shared_ptr<Review>> Sort_by_Pr(books);
        vector<shared_ptr<Review>> Sort_by_tit(books);
        vector<shared_ptr<Review>> Sort_by_Ra(books);

        cout << "Thank you. You entered the following "
             << books.size() << " ratings:\n"
              << "Rating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(Sort_by_tit.begin(), Sort_by_tit.end());
        cout << "Sorted by title:\nRating\tBook\tPrice\n";
        for_each(Sort_by_tit.begin(), Sort_by_tit.end(), ShowReview);

        cout << "(Reverse)Sorted by title:\nRating\tBook\tPrice\n";
        for_each(Sort_by_tit.rbegin(), Sort_by_tit.rend(), ShowReview);

        sort(Sort_by_Ra.begin(), Sort_by_Ra.end(), worseThan);
        cout << "Sorted by rating:\nRating\tBook\tPrice\n";
        for_each(Sort_by_Ra.begin(), Sort_by_Ra.end(), ShowReview);

         cout << "(Reverse)Sorted by rating:\nRating\tBook\tPrice\n";
        for_each(Sort_by_Ra.rbegin(), Sort_by_Ra.rend(), ShowReview);

        sort(Sort_by_Pr.begin(), Sort_by_Pr.end(), PworseThan);
        cout << "Sorted by price:\nRating\tBook\tPrice\n";
        for_each(Sort_by_Pr.begin(), Sort_by_Pr.end(), ShowReview);

        cout << "(Reverse)Sorted by price:\nRating\tBook\tPrice\n";
        for_each(Sort_by_Pr.rbegin(), Sort_by_Pr.rend(), ShowReview);

        random_shuffle(books.begin(), books.end());
        cout << "After shuffling:\nRating\tBook\tPrice\n";
        for_each(books.begin(), books.end(), ShowReview);
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
    // cin.get();
    return 0;
}

bool operator<(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
    if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool worseThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
    if (r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool PworseThan(const shared_ptr<Review> & r1, const shared_ptr<Review> & r2)
{
    if (r1->price < r2->price)
        return true;
    else
        return false;
}

bool FillReview(shared_ptr<Review> & rr)
{
    shared_ptr<Review> temp(new Review);
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, temp->title);
    if ((*temp).title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> temp->rating;

    std::cout << "Enter book price: ";
    std::cin >> temp->price;
    if (!std::cin)
        return false;
        rr = temp;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const shared_ptr<Review> & rr)
{
    std::cout << rr->rating << "\t" << rr->title << "\t" <<rr->price << std::endl << endl;
}
