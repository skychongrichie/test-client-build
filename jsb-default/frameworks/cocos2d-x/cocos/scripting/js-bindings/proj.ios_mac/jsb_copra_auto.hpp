#pragma once
#include "base/ccConfig.h"

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_copra_Test_proto;
extern se::Class* __jsb_copra_Test_class;

bool js_register_copra_Test(se::Object* obj);
bool register_all_copra(se::Object* obj);
SE_DECLARE_FUNC(js_copra_Test_fight);
SE_DECLARE_FUNC(js_copra_Test_print);
SE_DECLARE_FUNC(js_copra_Test_getCount);
SE_DECLARE_FUNC(js_copra_Test_getArrayLength);
SE_DECLARE_FUNC(js_copra_Test_staticTestFunc);
SE_DECLARE_FUNC(js_copra_Test_Test);

