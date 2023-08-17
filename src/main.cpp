#include <iostream>
#include <sqlite3.h>
#include <Poco/Util/ServerApplication.h>
#include <Poco/Util/Option.h>
#include <Poco/Util/OptionSet.h>
#include <Poco/Util/HelpFormatter.h>

using namespace std;
using Poco::Util::HelpFormatter;
using Poco::Util::Option;
using Poco::Util::OptionCallback;
using Poco::Util::OptionSet;
using Poco::Util::ServerApplication;

class HTTPTimeServer : public ServerApplication
{
protected:
    void initialize(Application &self)
    {
        loadConfiguration();
        ServerApplication::initialize(self);
    }

    void defineOptions(OptionSet &options)
    {
        ServerApplication::defineOptions(options);

        options.addOption(
            Option("help", "h", "display argument help information")
                .required(false)
                .repeatable(false)
                .callback(OptionCallback<HTTPTimeServer>(this, &HTTPTimeServer::handleHelp)));
    }

    void handleHelp(const string &name, const string &value)
    {
        HelpFormatter helpFormatter(options());
        helpFormatter.setCommand(commandName());
        helpFormatter.setUsage("OPTIONS");
        helpFormatter.setHeader("A web server that serves the current date and time.");
        helpFormatter.format(cout);
        stopOptionsProcessing();
        _helpRequested = true;
    }

    int main(const vector<string> &args)
    {
        if (!_helpRequested)
        {
            logger().information("request processed");
        }
        return Application::EXIT_OK;
    }

private:
    bool _helpRequested = false;
};

int main(int argc, char **argv)
{
    // sqlite3 *db;
    // char *zErrMsg = 0;
    // int rc;
    // rc = sqlite3_open(".palabras.db", &db);
    // if (rc)
    // {
    //     cout << "Can't open database:" << sqlite3_errmsg(db) << endl;
    //     return 1;
    // }
    // else
    // {
    //     cout << "Opened database successfully" << endl;
    // }
    // sqlite3_close(db);
    HTTPTimeServer app;
    return app.run(argc, argv);
}
