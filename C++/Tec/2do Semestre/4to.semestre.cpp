#include<iostream>
#include<string>

using namespace std;

class datos
{
    private:
        string location; //origen del vuelo
        string arrival; //lugar de llegada
        int hour; //hora de salida en horas
        int minutes;// minutos del vuelo
        int date; //decha del vuelo

    public:
            string getLocation();
            string getArrival();
            int getHour();
            int getMinutes();
            int getDate();
            void printNuevosVuelos();

        datos();
};

datos::datos()
        {   
            location="";
            arrival= "";
            hour=0;
            minutes=0;
            date=0;
        }

        string datos::getLocation()
        {
            return location;
        }
        string datos::getArrival()
        {
            return arrival;
        }
        int datos::getHour()
        {
            return hour;
        }
        int datos::getMinutes()
        {
            return minutes;
        }
        int datos::getDate()
        {
            return date;
        }
        
        void datos::printNuevosVuelos()
        {
            cout << "Salida de vuelo: " << location << "Desino de vuelo : " << arrival << ", hour: " << hour << "minutes: " << minutes <<"date" <<date<<endl;
        }


int main()
{
    datos d1;
    return 0;
}