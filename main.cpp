#include <iostream>
#include <sqlite3.h>

int main()
{
    std::string a = "Olala";
    std::cout << "Hello World -> " << a << std::endl;

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open(".palabras.db", &db);

    if (rc)
    {
        std::cout << "Can't open database:" << sqlite3_errmsg(db) << std::endl;
        return 0;
    }
    else
    {
        std::cout << "Opened database successfully" << std::endl;
    }

    sqlite3_close(db);
}
