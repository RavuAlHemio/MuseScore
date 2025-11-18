/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2025 MuseScore Limited and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "lv2module.h"

#include "modularity/ioc.h"
#include "audio/engine/isynthresolver.h"
#include "audio/engine/ifxresolver.h"

#include "audioplugins/iaudiopluginsscannerregister.h"
#include "audioplugins/iaudiopluginmetareaderregister.h"

#include "log.h"

using namespace muse::lv2;

static void lv2_init_qrc()
{
    Q_INIT_RESOURCE(lv2);
}

std::string LV2Module::moduleName() const
{
    return "lv2";
}

void LV2Module::registerExports()
{
    //m_configuration = std::make_shared<VstConfiguration>();

    //ioc()->registerExport<IVstConfiguration>(moduleName(), m_configuration);
}

void LV2Module::resolveImports()
{
    /*
    auto fxResolver = ioc()->resolve<IFxResolver>(moduleName());
    if (fxResolver) {
        fxResolver->registerResolver(AudioFxType::Lv2Fx, std::make_shared<Lv2FxResolver>());
    }

    auto scannerRegister = ioc()->resolve<IAudioPluginsScannerRegister>(moduleName());
    if (scannerRegister) {
        scannerRegister->registerScanner(std::make_shared<Lv2PluginsScanner>());
    }

    auto metaReaderRegister = ioc()->resolve<IAudioPluginMetaReaderRegister>(moduleName());
    if (metaReaderRegister) {
        metaReaderRegister->registerReader(std::make_shared<Lv2PluginMetaReader>());
    }
    */
}

void LV2Module::registerResources()
{
    lv2_init_qrc();
}

void LV2Module::registerUiTypes()
{
    /*
    qmlRegisterType<Lv2View>("Muse.Lv2", 1, 0, "Lv2View");

    ioc()->resolve<muse::ui::IUiEngine>(moduleName())->addSourceImportPath(muse_lv2_QML_IMPORT);
    */
}

void LV2Module::onInit(const IApplication::RunMode&)
{
    /*
    m_configuration->init();
    m_actionsController->init();
    m_pluginModulesRepo->init();
    m_actionsController->setupUsedView();
    */
}

void LV2Module::onDeinit()
{
    /*
    m_pluginModulesRepo->deInit();
    */
}
