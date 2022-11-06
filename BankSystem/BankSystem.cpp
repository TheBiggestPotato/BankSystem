#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>


using namespace std;


// Client class and logic
class Client
{
private:
    char* name;
    string social_security_no;
    string email;
    string phone;
    string address;
    int client_id;

protected:
    static int next_client_id;

public:
    Client();
    Client(char* name, string social_security_no, string email, string phone, string address);
    Client(char* name, string social_security_no)
    {
        this->name = new char[100];
        strcpy_s(this->name, sizeof name, name);
        this->social_security_no = social_security_no;
        this->client_id = ++next_client_id;
    };
    Client(string social_security_no)
    {
        this->social_security_no = social_security_no;
        this->client_id = ++next_client_id;
    };
    Client(const Client& c);
    ~Client();
     
    friend ostream& operator<< (ostream& out, const Client& c)
    {
        out << "CLIENT #id: " << c.client_id << endl;
        out << "NAME: " << c.name << endl;
        out << "SOCIAL SECURITY NUMBER: " << c.social_security_no << endl;
        out << "PHONE: " << c.phone << endl;
        out << "ADDRESS: " << c.address << endl;

        return out;
    }

    // setters and getters

    char* get_name()
    {
        return this->name;
    };

    char* set_name()
    {
        if (this->name != NULL)
            delete[] name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    string get_social_sec_number()
    {
        return this->social_security_no;
    };

    string set_social_sec_number(string number)
    {
        this->social_security_no = number;
    };

    string get_email()
    {
        return this->email;
    };

    string set_email(string email)
    {
        this->email = email;
    };

    string get_phone()
    {
        return this->phone;
    };

    string set_phone(string phone)
    {
        this->phone = phone;
    };

    string get_address()
    {
        return this->address;
    };

    string set_address(string address)
    {
        this->address = address;
    };
};

int Client::next_client_id = 0;

Client::Client()
{
    this->name = new char[6];
    strcpy(this->name, "GHOST");
    this->social_security_no = "NULL";
    this->email = "NULL";
    this->phone = "NULL";
    this->address = "NULL";
    this->client_id = ++next_client_id;
    cout << "Client #" << this->client_id << " created!" << endl;
    cout << endl;
}

Client::Client(char* name, string social_security_no, string email, string phone, string address)
{
    this->name = new char[100];
    strcpy_s(this->name, sizeof name, name);
    this->social_security_no = social_security_no;
    this->email = email;
    this->phone = phone;
    this->address = address;
    this->client_id = ++next_client_id;
}

Client::~Client() {
    delete[] name;
}

// Card class and logic
class Card
{
private:
    char* card_no;
    string expiery_date;
    string cvv;
    bool is_active;
    int card_id;

protected:
    static int next_card_id;

public:
    Card();
    Card(char* card_no, string expiery_date, string cvv, bool is_active)
    {
        this->card_no = new char[17];
        strcpy(this->card_no, card_no);
        this->expiery_date = expiery_date;
        this->cvv = cvv;
        this->is_active = is_active;
        this->card_id = ++next_card_id;
    };
    Card(char* card_no, string cvv)
    {
        this->card_no = new char[17];
        strcpy(this->card_no, card_no);
        this->cvv = cvv;
        this->card_id = ++next_card_id;
    };
    Card(string cvv)
    {
        this->cvv = cvv;
        this->card_id = ++next_card_id;
    };
    Card(const Card& c)
    {

    };
    ~Card()
    {
        delete[] card_no;
    };
};

int Card::next_card_id = 0;

Card::Card()
{
    this->card_no = new char[17];
    strcpy(this->card_no, "0000000000000000");
    this->expiery_date = "01/01/2027";
    this->cvv = "000";
    this->is_active = false;
    this->card_id = ++next_card_id;
};

// Account class and logic
class Account 
{
private:
    char* acc_name;
    string iban;
    double balance;
    string currency;
    int acc_id;

protected:
    static int next_acc_id;

public:
    Account()
    {
        this->acc_name = new char[6];
        strcpy(this->acc_name, "GHOST");
        this->iban = "NULL";
        this->balance = NULL;
        string currency = "EUR";
        this->acc_id = ++next_acc_id;
    };
    Account(char* acc_name, string iban, double balance, string currency)
    {
        this->acc_name = new char[100];
        strcpy(this->acc_name, acc_name);
        this->iban = iban;
        this->balance = balance;
        this->currency = currency;
        this->acc_id = ++next_acc_id;
    };
    Account(char* acc_name, string currency) 
    {
        this->acc_name = new char[100];
        strcpy(this->acc_name, acc_name);
        this->currency = currency;
        this->acc_id = ++next_acc_id;
    };
    Account(char* acc_name)
    {
        this->acc_name = new char[100];
        strcpy(this->acc_name, acc_name);
        this->acc_id = ++next_acc_id;
    };
    Account(const Account& a);
    ~Account() 
    {
        delete[] acc_name;
    };

    friend istream& operator>>(istream& in, Account& a)
    {
        if (a.acc_name != NULL)
        {
            delete[] a.acc_name;
            a.acc_name = NULL;
        }
        cout << "ACCOUNT'S NAME: ";
        char var_name[100];
        in >> var_name;
        a.acc_name = new char[strlen(var_name) + 1];
        strcpy(a.acc_name, var_name);
        a.balance = 0.0;
        a.iban = to_string(rand());
        cout << "ACCOUNT'S CURRENCY: ";
        in >> a.currency;
        cout << endl;

        return in;
    };

    friend ostream& operator<< (ostream& out, const Account& a)
    {
        out << endl;
        out << "ACCOUNT #id: " << a.acc_id << endl;
        out << "NAME: " << a.acc_name << endl;
        out << "BALANCE: " << a.balance << endl;
        out << "IBAN: " << a.iban << endl;
        out << "CURRENCY: " << a.currency << endl;
        out << endl;

        return out;
    }
};

int Account::next_acc_id = 0;

// Transaction class and logic
class Transaction
{
private:
    float amount;
    int transaction_id;
    string currency;



protected:
    static int next_transaction_id;

public:
    Transaction()
    {
        this->amount = 0.0;

        
    };
    Transaction(float amount, Account sender, string currency);
    Transaction(float amount, Account sender);
    Transaction(float amount);
    Transaction(const Transaction& t);
    ~Transaction();

};

int Transaction::next_transaction_id = 0;

int main()
{
    

    // Register as a client

    cout << "WELCOME!" << endl;
    char* name;
    string social_security_no, email, phone, address;

    name = new char[100];
    cout << "Name: ";
    cin >> name;
    cout << "Email: ";
    cin >> email;
    cout << "Phone: ";
    cin >> phone;
    cout << "Address: ";
    cin >> address;

    Client* client{ NULL };
    client = new Client(name, social_security_no, email, phone, address);
    
    
    // Application menu

    if(client)
    {
    char option;

    cout << "BANK APP" << endl;
    cout << "1. SHOW ACCOUNTS" << endl;
    cout << "2. CREATE A NEW ACCOUNT" << endl; // override >>
    cout << "3. MAKE A DEPOSIT" << endl; // override +
    cout << "4. MAKE A WITHDRAWL" << endl; // override -
    cout << "5. SHOW TRANSACTIONS" << endl;
    cout << "6. CLOSE AN ACCOUNT" << endl;
    cout << "7. SHOW YOUR DETAILS" << endl; // override <<
    cout << "8. ORDER A NEW CARD" << endl; // override >>
    cout << "9. SHOW ACTIVE CARDS" << endl;
    cout << "10. FREEZE A CARD" << endl;
    cout << "0. EXIT" << endl;

    cout << "Please select a menu option: ";
    cin >> option;

    do
    {
        switch (option)
        {
        case '1':
       // {
           /* for (int i = 0; i <= accounts.size(); i++)
            {
                cout << accounts[i] << endl;
            }
            break; */
       // }
        case '2':
        {
        // cin >> *account;
        break;
        }
        case '3':
            break;

        case '4':
            break;

        case '5':
            break;

        case '6':
            break;

        case '7':
            break;

        case '8':
            break;

        case '9':
            break;

        case '10':
            break;
        
        case '0':
            break;

        default:
            cout << "Wrong choice! Please try again: ";
            cin >> option;
        }
    } while (option != '0');
    }
}