#include <iostream>

using namespace std;

const int MAX_STRING_SIZE = 255;
const int IDENTIFIER = 13;
const int LIBRARY_N_BOOKS = 1000;

class Book {
    friend std::ostream &operator<<(ostream &os, const Book& book);

    private:
        const int m_id;

        char m_title[MAX_STRING_SIZE];
        int m_isbn[IDENTIFIER];
        bool m_available;
        char m_renter[MAX_STRING_SIZE];

        static int s_idgn;

    public:
        Book();
        Book(const char* title, const int*  ISBN, const char* renter);
        Book(const Book& other);

        ~Book();

        Book& operator=(const Book& rhs);

        // Getters //
        const int getID() const;
        const char *getTitle() const;
        const int getISBN() const;
        bool getAvailable() const;
        const char *getRenter() const;

        static int getIdgn();

        // Setters //
        void setID(int ID);
        void setTitle(const char *title);
        void setISBN(const int *ISBN);
        void setAvailable(bool Available);
        void setRenter(const char *renter);

        bool valid();
        Book& operator+ (const Book &renter);
        void free();
};

class Library {
    friend std::ostream & operator<<(ostream & os, Library & lib);

    private:
        char m_name[MAX_STRING_SIZE];
        Book m_inventory[LIBRARY_N_BOOKS];

    public:
        Library(const char* name);

        const char* getName() const;
        void setName(char *name);

        Book * findOpenSlot();
        Book * operator[](const char* title);
        Book & operator[](int index);

        bool rentBook(int index, char * renter);
        bool & operator+(const Book & other);

};