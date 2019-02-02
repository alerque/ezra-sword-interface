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

#include <napi.h>
#include "ezra_sword_interface.hpp"

class JsEzraSwordInterface : public Napi::ObjectWrap<JsEzraSwordInterface> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    JsEzraSwordInterface(const Napi::CallbackInfo& info);

private:
    static Napi::FunctionReference constructor;

    Napi::Value refreshRepositoryConfig(const Napi::CallbackInfo& info);

    Napi::Value refreshRemoteSources(const Napi::CallbackInfo& info);
    Napi::Value repositoryConfigExisting(const Napi::CallbackInfo& info);

    Napi::Value getRepoNames(const Napi::CallbackInfo& info);
    Napi::Value getAllRepoModules(const Napi::CallbackInfo& info);
    Napi::Value getRepoModulesByLang(const Napi::CallbackInfo& info);
    Napi::Value getRepoLanguages(const Napi::CallbackInfo& info);
    Napi::Value getRepoTranslationCount(const Napi::CallbackInfo& info);
    Napi::Value getRepoLanguageTranslationCount(const Napi::CallbackInfo& info);

    Napi::Value getModuleDescription(const Napi::CallbackInfo& info);
    Napi::Value getLocalModule(const Napi::CallbackInfo& info);

    Napi::Value getBibleText(const Napi::CallbackInfo& info);

    Napi::Value installModule(const Napi::CallbackInfo& info);
    void uninstallModule(const Napi::CallbackInfo& info);

    EzraSwordInterface* _ezraSwordInterface;

    // Functions not exported to js
    void swordModuleToNapiObject(sword::SWModule* swModule, Napi::Object& object);
};

