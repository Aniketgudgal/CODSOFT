#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

// Structure to represent a book
struct Book
{
  int ISBN;
  string title;
  string author;
  int quantity;
};

vector<Book> bookList;

// Function to display the main menu
void displayMenu()
{
  cout << "\n\t\t LIBRARY MANAGEMENT SYSTEM\n\n";
  cout << "1. Add Book\n";
  cout << "2. Display Books\n";
  cout << "3. Issue Book\n";
  cout << "4. Return Book\n";
  cout << "5. Exit\n";
  cout << "Enter your choice: ";
}

// Function to get user input as a string
string getStringInput()
{
  string input;
  getline(cin, input);
  return input;
}

// Function to get user input as an integer
int getIntInput()
{
  int input;
  cin >> input;
  cin.ignore(); // Clear input buffer
  return input;
}

// Function to load book data from a file
void loadBooks()
{
  ifstream file("books.dat", ios::binary); // Open binary file for reading
  if (!file.is_open())
  {
    return;
  }

  Book book;
  while (file.read(reinterpret_cast<char*>(&book), sizeof(book)))
  {
    bookList.push_back(book);
  }
  file.close();
}

// Function to save book data to a file
void saveBooks()
{
	Book book;
  ofstream file("books.dat", ios::binary); // Open binary file for writing
  if (!file.is_open())
  {
    return;
  }

std::vector<Book>::const_iterator it;
for (it = bookList.begin(); it != bookList.end(); ++it)
  {
    file.write(reinterpret_cast<char*>(&book), sizeof(book));
  }
  file.close();
}

// Function to add a new book
void addBook()
{
  Book book;
  cout << "Enter ISBN: ";
  book.ISBN = getIntInput();
  cout << "Enter book title: ";
  book.title = getStringInput();
  cout << "Enter author name: ";
  book.author = getStringInput();
  cout << "Enter quantity: ";
  book.quantity = getIntInput();

  bookList.push_back(book);
  cout << "Book added successfully!" << endl;
  saveBooks();
}

// Function to display all books
void displayBooks()
{
	Book book;
  if (bookList.empty())
  {
    cout << "There are no books in the library.\n";
    return;
  }

  cout << "\n\t\t  BOOK LIST\n\n";
  cout << " ISBN\t\t\tTitle\t\t\tAuthor\t\tQuantity\n";
  
std::vector<Book>::const_iterator it;
for (it = bookList.begin(); it != bookList.end(); ++it)
  {
    cout << book.ISBN << "\t\t\t" << book.title << "\t\t\t" << book.author << "\t\t\t" << book.quantity << endl;
  }
}

// Function to find a book by ISBN
int findBookByISBN(int isbn)
{
  for (int i = 0; i < bookList.size(); i++)
  {
    if (bookList[i].ISBN == isbn)
	{
      return i;
    }
  }
  return -1;
}

// Function to issue a book
void issueBook()
{
  int isbn, index;
  cout << "Enter ISBN of the book to issue: ";
  isbn = getIntInput();

  index = findBookByISBN(isbn);
  if (index == -1)
  {
    cout << "Book not found.\n";
    return;
  }

  if (bookList[index].quantity == 0)
  {
    cout << "Book is currently unavailable.\n";
    return;
  }

  bookList[index].quantity--;
  cout << "Book issued successfully!\n";
  saveBooks();
}

// Function to return a book
void returnBook()
{
  int isbn, index;
  cout << "Enter ISBN of the book to return: ";
  isbn = getIntInput();

  index = findBookByISBN(isbn);
  if (index == -1)
  {
    cout << "Book not found.\n";
    return;
  }

  bookList[index].quantity++;
  cout << "Book returned successfully!\n";
  saveBooks();
}

int main()
{
  loadBooks(); // Load book data from file on startup

  int choice;
  do
  {
    displayMenu();
    choice = getIntInput();

    switch (choice) {
      case 1:
        addBook();
        break;
      case 2:
        displayBooks();
        break;
      case 3:
        issueBook();
        break;
      case 4:
        returnBook();
        break;
      case 5:
        cout << "Exiting the Library Management System." << endl;
        saveBooks(); // Save book data before exiting
        break;
      default:
        cout << "Invalid choice. Please try again." << endl;
    }
  } while (choice != 5);

  return 0;
}
