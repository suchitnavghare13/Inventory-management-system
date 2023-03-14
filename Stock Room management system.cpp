#include <string.h>
#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

class shop
{
private:
  char name[20][50];

public:
  int id[20], quantity[100];
  float price[20];
  int z;
  void add_(void);
  void delete_(void);
  void purchase_(void);
  void display_(void);
  void Pdisplay_(int x);
  void search_(void);
  void updatePrice_(void);
  void updateQuantity_(void);
  void initial(void) { z = 0; }
  void checkstock1_(void);
  void checkstock2_(void);
  
//------------ CONSTRUCTOR & DESTRUCTOR----------------//
  shop()
{
cout << "\n\n     ||********** WELCOME TO STOCK room/inventory MANAGEMENT **********||" << endl;
}

~shop()
{
      cout << "\n\t\t\t** THANK YOU ** \n";
      cout << "\n--------------------------xxxx XXX xxx--------------------------------------\n";

}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class dealer : public shop
{

public:

//-------------------FUNCTION OVERIDING-----------------//

  checkstock1_(void)
  {
    int c;
    for (c = 0; c < z; c++)
    {
      if (quantity[c] == 0)
      {
        Pdisplay_(c);
      }
    }
  }
  checkstock2_(void)
  {
    int d;
    for (d = 0; d < z; d++)
    {
      if (quantity[d] != 0)
      {
        Pdisplay_(d);
      }
    }
  }
};

//-----------------FRIEND FUNCTION---------------------//

class Info
{
private:
  int dcode;

public:
  friend void printdcode(Info b);
  void getNo(int dealercode);
};

void Info::getNo(int dealercode)
{
  dcode = dealercode;
}
void printdcode(Info b)
{
  cout << "Dealer Code: " << b.dcode << endl;
  cout << "Access Granted ";
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void shop ::add_(void)
{
  int i;
rewrite:
  cout << "\nEnter the item name: ";
  cin >> name[z];
  cout << "Enter the item code: ";
  cin >> id[z];
  
//-----------------------EXCEPTION HANDLING----------------------//
  try
  {
    if (id[z] < 0)
    {
      throw 505;
    }
  }
  catch (int myno)
  {
    cout << "Item id cannot be negative\n";
    cout << "Enter Item details again " << endl;
    goto rewrite;
  }
  cout << "Enter the item quantity: ";
  cin >> quantity[z];
   try
  {
    if (quantity[z] < 0)
    {
      throw 50.5;
    }
  }
  catch (double myno)
  {
    cout << "Item Quantity cannot be negative\n";
    cout << "Enter Item details again " << endl;
    goto rewrite;
  }
  cout << "Enter the price of the item: ";
  cin >> price[z];
  z++;
}

void shop ::delete_(void)
{
  int i, j;

  cout << "\nPlease enter the item ID:";
  cin >> i;
  for (j = 0; j < z; j++)
  {
    if (id[j] == i)
    {
      price[j] = 0;
      quantity[j] = 0;
      Pdisplay_(j);
      cout << "\nThe selected item stock is deleted from the list.";
      break;
    }
  }
}

void shop ::Pdisplay_(int x)
{
  cout << "\n\t\t\t** Item details ** \n";
  cout << "=============================================================================";
  cout << "\n"
       << setw(10) << "Name" << setw(10) << "||" << setw(10) << "ID" << setw(10) << "||" << setw(10) << "Quantity" << setw(10) << "||" << setw(10) << "Price" << endl;
  cout << "=============================================================================" << endl;
  cout << setw(10) << name[x] << setw(10) << "||" << setw(10) << id[x] << setw(10) << "||" << setw(10) << quantity[x] << setw(10) << "||" << setw(10) << price[x] << endl;
}
void shop ::purchase_(void)
{
  int i, j, reqQnty;
  float total_price = 0;

  cout << "\nEnter the item code:";
  cin >> i;
  for (j = 0; j < z; j++)
  {
    if (id[j] == i)
    {
      if (quantity[j] == 0)
      {
        cout << "\n\tSorry. The item is currently OUT OF STOCK";
      }
      else
      {

        Pdisplay_(j);
        cout << "\n***Item is Available***";
        cout << "\nHow many Quantity do you want:";
        cin >> reqQnty;
        if (reqQnty > quantity[j])
        {
          cout << "\n Required quantity not in stock, quantity available are = " << quantity[j] << endl;
        }
        else
        {
          total_price = (reqQnty * price[j]);
          cout << "\n Your requested quantity is available";
          cout << "\n Total cost of requested quantity is = " << total_price << endl;
          quantity[j] = quantity[j] - reqQnty;
          cout << " Transaction Successful";
        }

        break;
      }
    }
  }
}

void shop ::display_(void)
{
  int i, j = 1;
  cout << "\n\t\t\t** Your Item details are ** \n";
  cout << "=============================================================================";
  cout << "\n"
       << "SN" << setw(10) << "Name" << setw(10) << "||" << setw(10) << "ID" << setw(10) << "||" << setw(10) << "Quantity" << setw(10) << "||" << setw(10) << "Price" << endl;
  cout << "=============================================================================" << endl;

  for (i = 0; i < z; i++)
  {
    cout << j << " " << setw(10) << name[i] << setw(10) << "||" << setw(10) << id[i] << setw(10) << "||" << setw(10) << quantity[i] << setw(10) << "||" << setw(10) << price[i] << endl;
    j++;
  }
  cout << "=============================================================================" << endl;
  getch();
}
void shop ::search_(void)
{
  char resp;
  int i, j, reqQnty;
  float total_price = 0;

  cout << "\nEnter the item code:";
  cin >> i;
  for (j = 0; j < z; j++)
  {
    if (id[j] == i)
    {
      if (quantity[j] == 0)
      {
        Pdisplay_(j);
        cout << "\nThe Item you searched is \n *** OUT OF STOCK ***";
      }
      else
      {

        Pdisplay_(j);
        cout << "\n***Item is Available***";
        break;
      }
    }
    else
    {
      cout << "Invalid Item id ";
    }
  }
}
void shop ::checkstock1_(void)
{
  int c;
  for (c = 0; c < z; c++)
  {
    if (quantity[c] == 0)
    {
      Pdisplay_(c);
    }
  }
}
void shop ::checkstock2_(void)
{
  int d;
  for (d = 0; d < z; d++)
  {
    if (quantity[d] != 0)
    {
      Pdisplay_(d);
    }
  }
}
void shop ::updatePrice_(void)
{
  char resp;
  int i, j;
  float updatedPrice;

  cout << "\nEnter the item code:";
  cin >> i;
  for (j = 0; j < z; j++)
  {
    if (id[j] == i)
    {
      if (quantity[j] != 0) // item is available
      {
        Pdisplay_(j);
        cout << "\nEnter New price of the item: ";
        cin >> updatedPrice;
        price[j] = updatedPrice;
        Pdisplay_(j);
        cout << "\nPrice Updated Successfully";
      }
      else
      {
        Pdisplay_(j);
        cout << "The Item you searched is \n *** OUT OF STOCK ***\n Update Price is disabled for out of stock items\n";
        break;
      }
    }
    else
    {
      cout << "Invalid Item id ";
    }
  }
}
void shop ::updateQuantity_(void)
{
  char resp;
  int i, j, updatedQuantity;

  cout << "\nEnter the item code:";
  cin >> i;
  for (j = 0; j < z; j++)
  {
    if (id[j] == i)
    {
      Pdisplay_(j);
      cout << "\nEnter New Quantity of the item: ";
      cin >> updatedQuantity;
      quantity[j] = updatedQuantity;
      Pdisplay_(j);
      cout << "\nQuantity Updated Successfully";
    }
    else
    {
      cout << "Invalid Item id ";
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
  dealer d = dealer();
  Info b;

  bool flag4;
  do
  {
    flag4 = false;

    cout << "\n\t\t      STOCK room/inventory  MANAGEMENT SYSTEM\n";
    cout << "=============================================================================";
    cout << "\n\n\t\t   1. DEALER MENU\n\n\t\t   2. CUSTOMER MENU\n\n\t\t   3. EMPLOYEE MENU\n\n\t\t   4. EXIT";
    cout << "\n=============================================================================\n";
    cout << "\nEnter Your Choice: ";
    int choice, ch1, ch2, ch3, ch4, r1, r2, r3;
    cin >> choice;
    switch (choice)
    {
    case 1:
      b.getNo(001);
      printdcode(b);
      bool flag1;
      do
      {
        flag1 = false;
        cout << "\n\t\t      Welcome to DEALER menu\n";
        cout << "=============================================================================";
        cout << "\n\t\t   1. Add Items\n\t\t   2. Display Items\n\t\t   3. Delete item\n\t\t   4. Back to Main Menu";
        cout << "\n=============================================================================\n";
        cout << "\nEnter Your Choice: ";
        cin >> ch1;
        switch (ch1)
        {
          cout << "Welcome to Dealer Menu";
        case 1:
          cout << "Add Items";
          d.add_();
          break;
        case 2:
          cout << "Display Items";
          d.display_();
          break;
        case 3:
          cout << "Delete Item";
          d.delete_();
          break;
        case 4:
          flag4 = true;
          break;
        }
        if (ch1 != 4)
        {
          cout << "\nPress 1 for Dealer menu: ";
          cin >> r1;
          if (r1 == 1)
          {
            flag1 = true;
          }
        }
      } while (flag1);
      break;
    case 2:
      bool flag2;
      do
      {
        flag2 = false;
        cout << "\n\t\t      Welcome to CUSTOMER menu\n";
        cout << "=============================================================================";
        cout << "\n\t\t   1. Display Items\n\t\t   2. Purchase Items\n\t\t   3. Search Items\n\t\t   4. Back to Main Menu";
        cout << "\n=============================================================================\n";
        cout << "\nEnter Your Choice: ";
        cin >> ch2;
        switch (ch2)
        {
          cout << "Welcome to Customer Menu";
        case 1:
          cout << "Display Items";
          d.display_();
          break;
        case 2:
          cout << "Purchase Items";
          d.purchase_();
          break;
        case 3:
          cout << "Search Item";
          d.search_();
          break;
        case 4:
          flag4 = true;
          break;
        }
        if (ch2 != 4)
        {
          cout << "\nPress 1 - Customer menu: ";
          cin >> r2;
          if (r2 == 1)
          {
            flag2 = true;
          }
        }
      } while (flag2);
      break;
    case 3:
      bool flag3;

      do
      {
        flag3 = false;
        cout << "\n\t\t      Welcome to EMPLOYEE menu\n";
        cout << "=============================================================================";
        cout << "\n\t\t   1. Display Items\n\t\t   2. Update Quantity\n\t\t   3. Update Price\n\t\t   4. Check Stock\n\t\t   5. Back to Main Menu";
        cout << "\n=============================================================================\n";
        cout << "\nEnter Your Choice: ";
        cin >> ch3;
        switch (ch3)
        {
          cout << "Welcome to Employee Menu";
        case 1:
          cout << "Display Items";
          d.display_();

          break;
        case 2:
          cout << "Update Quantity";
          d.updateQuantity_();
          break;
        case 3:
          cout << "Update price";
          d.updatePrice_();
          break;
        case 4:
          cout << "Check Stock";
          cout << "\n\t1. Display All Items\n\t2. Display Deleted Items\n\t3. Display Available Items\n";
          cout << "Enter Choice: ";
          cin >> ch4;
          switch (ch4)
          {
          case 1:
            cout << "All Items";
            d.display_();
            break;
          case 2:
            cout << "Deleted Items";
            d.checkstock1_();
            break;
          case 3:
            cout << "Available Items";
            d.checkstock2_();
            break;
          }
          break;
        case 5:
          flag4 = true;
          break;
        }
        if (ch3 != 5)
        {
          cout << "\nPress 1 for Employee menu: ";
          cin >> r3;
          if (r3 == 1)
          {
            flag3 = true;
          }
        }
      } while (flag3);
      break;
    case 4:

      break;
    }
  } while (flag4);
}


