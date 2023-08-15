#include <iostream>
#include <sqlite3.h>

using namespace std;

int main()
{
    string a = "menos";
    cout << "más o " << a << "" << endl;

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open(".palabras.db", &db);

    if (rc)
    {
        cout << "Can't open database:" << sqlite3_errmsg(db) << endl;
        return 0;
    }
    else
    {
        cout << "Opened database successfully" << endl;
    }

    sqlite3_close(db);

    cout << "Terminated" << endl;
}
