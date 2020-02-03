/* COMP 11 
 * Lab 1, Spring 2017
 * Starter Code *

 *Ethan Sorkin
 *Jenn Kim
 *Cory Barel
 *
 *Jan 31 2017
 ******/

#include <iostream>
using namespace std;

const int SPIDER_TICKETS = 3;
const int MINION_TICKETS = 10;

int main()
{
  int num_coupons, num_minions, num_spiders, num_leftover;
    char response;
    cout << "How many coupons do you have?" << endl;
    cin >> num_coupons;
    cout << "Do you prefer minions? Enter y/n" << endl;
    cin >> response;
    if (response == 'y')
      {
	num_minions = num_coupons / MINION_TICKETS;
	num_spiders =(num_coupons - (MINION_TICKETS * num_minions)) / SPIDER_TICKETS;
	num_leftover = num_coupons - (num_minions * MINION_TICKETS) - (num_spiders * SPIDER_TICKETS);
	cout << "You can redeem you coupons for "; 
	cout << num_minions;
	cout << " minion dolls and ";
	cout << num_spiders;
	cout << " spider rings!" << endl;
	cout << "You have ";
	cout << num_leftover;
	cout << " tickets leftover!" << endl;
	if (num_leftover == 2)
	{
	  cout << "You were so close to redeeming another spider!" << endl;
	}
	if (num_leftover == 1)
	  {
          cout << "You were two tickets away from redeeming another spider (and 9 away from a minion)" << endl;
	  }
	if (num_leftover == 0)
	  {
          cout << "Congratulations! You used all your tickets!" << endl;
           }
      }

 if (response == 'n')
      {
	num_spiders = num_coupons / SPIDER_TICKETS;
	num_leftover = num_coupons - (num_spiders * SPIDER_TICKETS);
	cout << "You can redeem you coupons for "; 
	cout << num_spiders;
	cout << " spider rings!" << endl;
	cout << "You have ";
	cout << num_leftover;
	cout << " tickets leftover!" << endl;
      }
	if (num_leftover == 2)
	{
	  cout << "You were so close to redeeming another spider!" << endl;
	}
	if (num_leftover == 1)
	  {
          cout << "You were two tickets away from redeeming another spider!" << endl;
	  }
	if (num_leftover == 0)
	  {
          cout << "Congratulations! You used all your tickets!" << endl;
           }
	return 0;
}
