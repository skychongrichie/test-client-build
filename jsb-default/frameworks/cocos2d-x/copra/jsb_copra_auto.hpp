#pragma once
#include "base/ccConfig.h"

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_copra_Test_proto;
extern se::Class* __jsb_copra_Test_class;

bool js_register_copra_Test(se::Object* obj);
bool register_all_cp(se::Object* obj);
SE_DECLARE_FUNC(js_cp_Test_fight);
SE_DECLARE_FUNC(js_cp_Test_print);
SE_DECLARE_FUNC(js_cp_Test_getCount);
SE_DECLARE_FUNC(js_cp_Test_getArrayLength);
SE_DECLARE_FUNC(js_cp_Test_staticTestFunc);
SE_DECLARE_FUNC(js_cp_Test_Test);

