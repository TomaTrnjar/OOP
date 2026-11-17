#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LogFile {
private:
    FILE* file;

public:
    LogFile(const string& name) {
        file = fopen(name.c_str(), "a");
    }

    ~LogFile() {
        if (file != nullptr) {
            fclose(file);
        }
    }

    LogFile(const LogFile& other) = delete;

    void write(const string& line) {
        if (file != nullptr) {
            fputs(line.c_str(), file);
            fputs("\n", file);
        }
    }
};

int log_songs(const vector<string>& titles) {
    LogFile log("played.log");
    int br = 0;

    for (const string& title : titles) {
        if (title == "STOP") {
            return br;
        }

        log.write(title);
        br++;
    }

    return br;
}

int main()
{
    remove("played.log");

    int n = log_songs({"Superhero", "Sports", "STOP", "Matador"});
    cout << n << '\n';

    cout << log_songs({"One Rizla"}) << '\n';

    FILE* f = fopen("played.log", "r");
    char line[100];

    while (fgets(line, sizeof line, f))
        cout << line;

    fclose(f);
    return 0;
}
