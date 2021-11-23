/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef I18N_ADDON_H
#define I18N_ADDON_H

#include <string>
#include <unordered_map>
#include "napi/native_api.h"
#include "i18n_break_iterator.h"
#include "i18n_calendar.h"
#include "napi/native_node_api.h"
#include "locale_config.h"
#include "measure_data.h"
#include "number_format.h"
#include "phone_number_format.h"

namespace OHOS {
namespace Global {
namespace I18n {
void GetOptionMap(napi_env env, napi_value argv, std::map<std::string, std::string> &map);
void GetOptionValue(napi_env env, napi_value options, const std::string &optionName,
    std::string &value);

class I18nAddon {
public:
    static napi_value Init(napi_env env, napi_value exports);
    static void Destructor(napi_env env, void *nativeObject, void *finalize_hint);
    I18nAddon();
    virtual ~I18nAddon();
    static napi_value GetSystemLanguages(napi_env env, napi_callback_info info);
    static napi_value GetSystemCountries(napi_env env, napi_callback_info info);
    static napi_value IsSuggested(napi_env env, napi_callback_info info);
    static napi_value GetDisplayLanguage(napi_env env, napi_callback_info info);
    static napi_value GetDisplayCountry(napi_env env, napi_callback_info info);
    static napi_value GetSystemLanguage(napi_env env, napi_callback_info info);
    static napi_value GetSystemRegion(napi_env env, napi_callback_info info);
    static napi_value GetSystemLocale(napi_env env, napi_callback_info info);
    static napi_value SetSystemLanguage(napi_env env, napi_callback_info info);
    static napi_value SetSystemRegion(napi_env env, napi_callback_info info);
    static napi_value SetSystemLocale(napi_env env, napi_callback_info info);
    static napi_value IsRTL(napi_env env, napi_callback_info info);
    static napi_value InitPhoneNumberFormat(napi_env env, napi_value exports);
    static napi_value InitI18nCalendar(napi_env env, napi_value exports);
    static napi_value UnitConvert(napi_env env, napi_callback_info info);
    static napi_value InitBreakIterator(napi_env env, napi_value exports);

private:
    static napi_value PhoneNumberFormatConstructor(napi_env env, napi_callback_info info);
    static napi_value IsValidPhoneNumber(napi_env env, napi_callback_info info);
    static napi_value FormatPhoneNumber(napi_env env, napi_callback_info info);
    bool InitPhoneNumberFormatContext(napi_env env, napi_callback_info info, const std::string &country,
                                      const std::map<std::string, std::string> &options);

    static napi_value CalendarConstructor(napi_env env, napi_callback_info info);
    static napi_value BreakIteratorConstructor(napi_env env, napi_callback_info info);
    bool InitCalendarContext(napi_env env, napi_callback_info info, const std::string &localeTag, CalendarType type);
    static napi_value GetCalendar(napi_env env, napi_callback_info info);
    static napi_value Set(napi_env env, napi_callback_info info);
    static napi_value GetDate(napi_env env, napi_value value);
    void SetMilliseconds(napi_env env, napi_value value);
    void SetField(napi_env env, napi_value value, UCalendarDateFields field);
    static napi_value SetTime(napi_env env, napi_callback_info info);
    static std::string GetString(napi_env &env, napi_value &value, int32_t &code);
    static napi_value SetTimeZone(napi_env env, napi_callback_info info);
    static napi_value GetTimeZone(napi_env env, napi_callback_info info);
    static napi_value SetFirstDayOfWeek(napi_env env, napi_callback_info info);
    static napi_value GetFirstDayOfWeek(napi_env env, napi_callback_info info);
    static napi_value SetMinimalDaysInFirstWeek(napi_env env, napi_callback_info info);
    static napi_value GetMinimalDaysInFirstWeek(napi_env env, napi_callback_info info);
    static napi_value Get(napi_env env, napi_callback_info info);
    static napi_value GetDisplayName(napi_env env, napi_callback_info info);
    static napi_value IsWeekend(napi_env env, napi_callback_info info);
    static CalendarType GetCalendarType(napi_env env, napi_value value);
    static napi_value GetLineInstance(napi_env env, napi_callback_info info);
    static napi_value Current(napi_env env, napi_callback_info info);
    static napi_value First(napi_env env, napi_callback_info info);
    static napi_value Last(napi_env env, napi_callback_info info);
    static napi_value Previous(napi_env env, napi_callback_info info);
    static napi_value Next(napi_env env, napi_callback_info info);
    static napi_value SetText(napi_env env, napi_callback_info info);
    static napi_value GetText(napi_env env, napi_callback_info info);
    static napi_value Following(napi_env env, napi_callback_info info);
    static napi_value IsBoundary(napi_env env, napi_callback_info info);

    napi_env env_;
    napi_ref wrapper_;
    std::unique_ptr<PhoneNumberFormat> phonenumberfmt_;
    std::unique_ptr<I18nCalendar> calendar_;
    std::unique_ptr<I18nBreakIterator> brkiter_;
};
} // namespace I18n
} // namespace Global
} // namespace OHOS
#endif