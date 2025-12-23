#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// I ain't making 2 versions of that, sorry not sorry - vector supremacy

struct Vagon
{
    int Number;
    int SeatsAmount;
    int PassengerAmount;
};

class Train
{
private:
    string model;
    vector<Vagon> wagons;

public:
    Train()
    {
        model = "Hyundai";
        wagons.push_back({ 1001, 15, 13 });
        wagons.push_back({ 1002, 13, 10 });
    }

    Train(string model, int amount_of_wagons)
    {
        this->model = model;

        for (int i = 0; i < amount_of_wagons; i++)
        {
            int seats = 10 + rand() % 11;       // 10–20
            int number = 1000 + rand() % 9000;  // 1000–9999
            int passengers = rand() % (seats + 1);

            wagons.push_back({ number, seats, passengers });
        }
    }
    Train(const Train& other)
    {
        model = other.model;
        wagons = other.wagons;
    }
    void Show() const
    {
        cout << "\nTRAIN MODEL: " << model << endl;
        cout << "WAGONS:\n";

        if (wagons.empty())
        {
            cout << "No wagons.\n";
            return;
        }

        for (int i = 0; i < wagons.size(); i++)
        {
            cout << "====================\n";
            cout << "Wagon #" << (i + 1) << endl;
            cout << "Number: " << wagons[i].Number << endl;
            cout << "Seats: " << wagons[i].SeatsAmount << endl;
            cout << "Passengers: " << wagons[i].PassengerAmount << endl;
        }
        cout << "====================\n";
    }
    void AddWagon()
    {
        int Num, SA, PA;

        cout << "Enter new wagon number (1000 - 9999) >>> ";
        cin >> Num;

        cout << "Enter seats (10 - 20) >>> ";
        cin >> SA;

        cout << "Enter passengers >>> ";
        cin >> PA;

        if (SA < 10 || SA > 20)
        {
            cout << "Invalid seat amount!\n";
            return;
        }

        if (PA < 0) PA = 0;
        if (PA > SA) PA = SA;

        wagons.push_back({ Num, SA, PA });
    }
    void AddPassengerToAWagon()
    {
        if (wagons.empty())
        {
            cout << "No wagons available!\n";
            return;
        }

        int wagonIndex;
        cout << "Enter wagon index (1–" << wagons.size() << ") >>> ";
        cin >> wagonIndex;

        if (wagonIndex < 1 || wagonIndex > wagons.size())
        {
            cout << "Invalid wagon index!\n";
            return;
        }

        Vagon& w = wagons[wagonIndex - 1];

        if (w.PassengerAmount >= w.SeatsAmount)
        {
            cout << "Wagon is full (" << w.PassengerAmount
                << "/" << w.SeatsAmount << ")\n";
        }
        else
        {
            w.PassengerAmount++;
            cout << "Passenger added.\n";
        }
    }
    ~Train()
    {
        cout << "Train destroyed\n";
    }
};

int main()
{
    srand(time(NULL));

    Train t1;
    t1.Show();

    Train t2("Arctica", 5);
    t2.Show();

    t2.AddWagon();
    t2.AddPassengerToAWagon();

    Train t3 = t2;
    t3.Show();

    cout << "---------------------\n";
}
