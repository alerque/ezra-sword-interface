/* This file is part of ezra-sword-interface.

   Copyright (C) 2019 Tobias Klein <contact@tklein.info>

   ezra-sword-interface is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   ezra-sword-interface is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of 
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
   See the GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with ezra-sword-interface. See the file COPYING.
   If not, see <http://www.gnu.org/licenses/>. */

#ifndef _EZRA_SWORD_INTERFACE
#define _EZRA_SWORD_INTERFACE

#include <vector>
#include <string>
#include <thread>
#include <climits>

#include <remotetrans.h>

namespace sword {
    class InstallMgr;
    class InstallSource;
    class SWModule;
    class SWMgr;
    class SWConfig;
};

class SwordStatusReporter : public sword::StatusReporter
{
public:
	int last;
    virtual void update(unsigned long totalBytes, unsigned long completedBytes);
    virtual void preStatus(long totalBytes, long completedBytes, const char *message);
};

class EzraSwordInterface
{
public:
    EzraSwordInterface();
    virtual ~EzraSwordInterface();

    int refreshRepositoryConfig();
    void refreshRemoteSources(bool force=false);

    std::vector<std::string> getRepoNames();
    std::vector<sword::SWModule*> getAllRemoteModules();
    sword::SWModule* getRepoModule(std::string moduleName);
    std::vector<sword::SWModule*> getAllRepoModules(std::string repoName);
    std::vector<sword::SWModule*> getRepoModulesByLang(std::string repoName, std::string languageCode);
    unsigned int getRepoTranslationCount(std::string repoName);
    std::vector<std::string> getRepoLanguages(std::string repoName);
    unsigned int getRepoLanguageTranslationCount(std::string repoName, std::string languageCode);

    std::vector<sword::SWModule*> getAllLocalModules();
    sword::SWModule* getLocalModule(std::string moduleName);
    std::vector<std::string> getBibleText(std::string moduleName);

    int installModule(std::string moduleName);
    int installModule(std::string repoName, std::string moduleName);
    int uninstallModule(std::string moduleName);

private:
    sword::InstallSource* getRemoteSource(std::string remoteSourceName);
    std::string getModuleRepo(std::string moduleName);
    int refreshIndividualRemoteSource(std::string remoteSourceName);
    std::thread getRemoteSourceRefreshThread(std::string remoteSourceName);

    std::string getPathSeparator();
    std::string getUserDir();
    std::string getSwordDir();
    std::string getInstallMgrDir();
    std::string getModuleDir();
    std::string getSwordConfPath();

    std::string rtrim(const std::string& s);

    sword::SWMgr* _mgr = 0;
    sword::SWConfig* _swConfig = 0;
    sword::InstallMgr* _installMgr = 0;
    SwordStatusReporter* _statusReporter = 0;
};

#endif // _EZRA_SWORD_INTERFACE

