#include "sword_facade.hpp"

#include <vector>
#include <iostream>
#include <swmodule.h>

using namespace std;
using namespace sword;

int main(int argc, char** argv)
{
    SwordFacade sword_facade;

    //sword_facade.refreshRemoteSources(true);

    cout << "REPOSITORIES:" << endl;
    vector<string> repoNames = sword_facade.getRepoNames();
    for (unsigned int i = 0; i < repoNames.size(); i++) {
        cout << repoNames[i] << endl;
    }
    cout << endl;

    cout << "English MODULES of CrossWire:" << endl;
    vector<SWModule*> modules = sword_facade.getRepoModulesByLang("CrossWire", "en");
    for (unsigned int i = 0; i < modules.size(); i++) {
        SWModule* currentModule = modules[i];

        cout << currentModule->getName();

        if (currentModule->getConfigEntry("Abbreviation")) {
            string moduleShortcut = currentModule->getConfigEntry("Abbreviation");
            cout << " " << moduleShortcut;
        }

        if (currentModule->getConfigEntry("InstallSize")) {
            string installSize = currentModule->getConfigEntry("InstallSize");
            cout << " " << installSize;
        }

        string moduleVersion = currentModule->getConfigEntry("Version");
        cout << " " << moduleVersion << " ";

        string moduleLocked = currentModule->getConfigEntry("CipherKey") ? "LOCKED" : "";
        cout << moduleLocked;

        cout << endl;
    }
    cout << endl;

    cout << "Text of 1 John:" << endl;
    //sword_facade.enableMarkup();
    vector<string> verses = sword_facade.getBookText("GerNeUe", "1John");
    //vector<string> verses = sword_facade.getBibleText("deu1912eb");
    cout << "Got " << verses.size() << " verses!" << endl;
    for (int i = 0; i < verses.size(); i++) {
        cout << verses[i] << endl;
    }

    return 0;
}
