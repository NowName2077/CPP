
#include <iostream>
using namespace std;

struct PhoneNode
{
    int phone_number;
    string user_name;
    double call_time;
    PhoneNode* left;
    PhoneNode* right;

    PhoneNode() : phone_number(0), user_name(""), call_time(0), left(nullptr), right(nullptr) {}

    PhoneNode(int number, string name, double time) : 
    phone_number(number),user_name(name),call_time(time),left(nullptr), right(nullptr) {}
};

class PhoneBook 
{
    private:

    PhoneNode* root;

    void insert(PhoneNode*& node, const int& number, const string& name, double time) 
    {
        if (node == nullptr) 
        {
            node = new PhoneNode(number,name,time);
        } 
        else if (number < node->phone_number) 
        {
            insert(node->left, number,name,time);
        } 
        else 
        {
            insert(node->right, number,name,time);
        }
    }


    void print(PhoneNode* node) const 
    {
        if (node != nullptr) 
        {
            print(node->left);
            cout << "Телефон: " << node->phone_number << ", "
            << "Владелец: " << node->user_name << ", "
            << "Продолжительность разговора: " << node->call_time << " мин, " << endl;
            print(node->right);
        }
    }

    PhoneNode* search(PhoneNode* node, const int& number) const 
    {
        if (node == nullptr || node->phone_number == number) 
        {
            return node;
        }
        if (number < node->phone_number) 
        {
            return search(node->left, number);
        }
        return search(node->right, number);
    }

    double price(double time) const 
    {
        // стоимость разговора (например, 5 рубль за минуту)
        return time * 5.0;
    }

        void destroy(PhoneNode* node)
    {
        if (node != nullptr)
        {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

    public:
    PhoneBook() : root(nullptr) {}

    void insert_number(const int& number,  const string& name, double time) 
    {
        insert(root, number, name, time);
        cout << "Записано.\n";
    }

    void print_book() const 
    {
        if (root == nullptr) 
        {
            cout << "Картотека пуста!" << endl;
        } 
        else 
        {
            print(root);
        }
    }

    void receipt (const int& number) const 
    {
        PhoneNode* found = search(root, number);

        if (found != nullptr) 
        {
            double cost = price(found->call_time);
            cout << "Извещение на оплату для " << found->user_name << " (" << found->phone_number << "): "
            << cost << " руб." << endl;
        } 
        else 
        {
            cout << "Абонент с таким номером не найден!" << endl;
        }
    }

    void del()
    {
        if (root != nullptr)
        {
            destroy(root);
            root = nullptr;
            cout << "Данные удалены \n";
        }
        else
        {
            cout << "Картотека пуста!\n";
        }
    }

};




int menu ()
{
    int num;
    cout << "\nМеню:\n";
    cout << "1. Добавить нового абонента\n";
    cout << "2. Прочитать файл\n";
    cout << "3. Вывести всю картотеку\n";
    cout << "4. извещения на оплату\n";
    cout << "5. Очистить древо\n";
    cout << "0. Выход\n";
    cout << "Введите ваш выбор: ";
    cin >> num;
    return num;
}

void switchs(PhoneBook& book)
{
     int case_;
    do
    {
        case_ = menu();
        switch (case_)
        {
            case 1:
            {
                int number;
                string name;
                double time;
                cout << "Номер телефона: ";
                cin >> number;
                cout << "Имя владельца: ";
                cin >> name;
                cout << "Продолжительность разговора (в минутах): ";
                cin >> time;
                book.insert_number(number,name,time);
                break;
            }
            case 2:
            {
                cout << "Введите имя файла : ";
	            string file_name;

                break;
            }
            case 3:
            {
                cout << "Вывод: \n";
                book.print_book();
                break;
            }
            case 4:
            {
                int number;
                cout << "Введите номер телефона: \n";
                cin >> number;
                book.receipt(number);
                break;
            }
            case 5:
            {
                cout << "Удаление... \n";
                book.del();
                break;
            }
            case 0:
            {
                cout << "Выход.\n";
                break;
            }
            default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }

        cout <<"Case " << case_ ;
    } while (case_ != 0);

}
int main() 
{
    PhoneBook book;
    switchs(book);
    return 0;
}