/* This file is part of node-sword-interface.

   Copyright (C) 2019 Tobias Klein <contact@ezra-project.net>

   node-sword-interface is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   node-sword-interface is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of 
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
   See the GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with node-sword-interface. See the file COPYING.
   If not, see <http://www.gnu.org/licenses/>. */

#ifndef _NODE_SWORD_INTERFACE
#define _NODE_SWORD_INTERFACE

#include <napi.h>

class SwordFacade;
class NapiSwordHelper;

enum class ParamType {
    string,
    number,
    boolean,
    function
};

class NodeSwordInterface : public Napi::ObjectWrap<NodeSwordInterface> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    NodeSwordInterface(const Napi::CallbackInfo& info);

private:
    static Napi::FunctionReference constructor;

    Napi::Value updateRepositoryConfig(const Napi::CallbackInfo& info);
    Napi::Value repositoryConfigExisting(const Napi::CallbackInfo& info);

    Napi::Value getRepoNames(const Napi::CallbackInfo& info);
    Napi::Value getAllRepoModules(const Napi::CallbackInfo& info);
    Napi::Value getRepoModulesByLang(const Napi::CallbackInfo& info);
    Napi::Value getRepoLanguages(const Napi::CallbackInfo& info);
    Napi::Value getRepoTranslationCount(const Napi::CallbackInfo& info);
    Napi::Value getRepoModule(const Napi::CallbackInfo& info);

    Napi::Value getRepoLanguageTranslationCount(const Napi::CallbackInfo& info);
    Napi::Value getAllLocalModules(const Napi::CallbackInfo& info);
    Napi::Value isModuleInUserDir(const Napi::CallbackInfo& info);
    Napi::Value isModuleAvailableInRepo(const Napi::CallbackInfo& info);
    Napi::Value getModuleDescription(const Napi::CallbackInfo& info);
    Napi::Value getLocalModule(const Napi::CallbackInfo& info);

    Napi::Value enableMarkup(const Napi::CallbackInfo& info);
    
    Napi::Value getChapterText(const Napi::CallbackInfo& info);
    Napi::Value getBookText(const Napi::CallbackInfo& info);
    Napi::Value getBibleText(const Napi::CallbackInfo& info);
    Napi::Value getBibleChapterVerseCounts(const Napi::CallbackInfo& info);
    Napi::Value getBookIntroduction(const Napi::CallbackInfo& info);

    Napi::Value getModuleSearchResults(const Napi::CallbackInfo& info);
    Napi::Value getStrongsEntry(const Napi::CallbackInfo& info);

    Napi::Value installModule(const Napi::CallbackInfo& info);
    Napi::Value uninstallModule(const Napi::CallbackInfo& info);
    Napi::Value saveModuleUnlockKey(const Napi::CallbackInfo& info);
    Napi::Value isModuleReadable(const Napi::CallbackInfo& info);

    Napi::Value getSwordTranslation(const Napi::CallbackInfo& info);
    Napi::Value getSwordVersion(const Napi::CallbackInfo& info);

    int validateParams(const Napi::CallbackInfo& info, std::vector<ParamType> paramSpec);

    NapiSwordHelper* _napiSwordHelper;
    SwordFacade* _swordFacade;
};

#endif // _NODE_SWORD_INTERFACE

