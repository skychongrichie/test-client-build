#include "jsb_copra_auto.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "copra.h"

se::Object* __jsb_copra_Test_proto = nullptr;
se::Class* __jsb_copra_Test_class = nullptr;

static bool js_cp_Test_fight(se::State& s)
{
    copra::Test* cobj = (copra::Test*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cp_Test_fight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->fight();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cp_Test_fight)

static bool js_cp_Test_print(se::State& s)
{
    copra::Test* cobj = (copra::Test*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cp_Test_print : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->print();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cp_Test_print)

static bool js_cp_Test_getCount(se::State& s)
{
    copra::Test* cobj = (copra::Test*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cp_Test_getCount : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getCount();
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cp_Test_getCount : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cp_Test_getCount)

static bool js_cp_Test_getArrayLength(se::State& s)
{
    copra::Test* cobj = (copra::Test*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cp_Test_getArrayLength : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::vector<int> arg0;
        ok &= seval_to_std_vector_int(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cp_Test_getArrayLength : Error processing arguments");
        int result = cobj->getArrayLength(arg0);
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cp_Test_getArrayLength : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cp_Test_getArrayLength)

static bool js_cp_Test_staticTestFunc(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        copra::Test::staticTestFunc();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cp_Test_staticTestFunc)

SE_DECLARE_FINALIZE_FUNC(js_copra_Test_finalize)

static bool js_cp_Test_constructor(se::State& s)
{
    copra::Test* cobj = new (std::nothrow) copra::Test();
    s.thisObject()->setPrivateData(cobj);
    se::NonRefNativePtrCreatedByCtorMap::emplace(cobj);
    return true;
}
SE_BIND_CTOR(js_cp_Test_constructor, __jsb_copra_Test_class, js_copra_Test_finalize)




static bool js_copra_Test_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (copra::Test)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        copra::Test* cobj = (copra::Test*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_copra_Test_finalize)

bool js_register_cp_Test(se::Object* obj)
{
    auto cls = se::Class::create("Test", obj, nullptr, _SE(js_cp_Test_constructor));

    cls->defineFunction("fight", _SE(js_cp_Test_fight));
    cls->defineFunction("print", _SE(js_cp_Test_print));
    cls->defineFunction("getCount", _SE(js_cp_Test_getCount));
    cls->defineFunction("getArrayLength", _SE(js_cp_Test_getArrayLength));
    cls->defineStaticFunction("staticTestFunc", _SE(js_cp_Test_staticTestFunc));
    cls->defineFinalizeFunction(_SE(js_copra_Test_finalize));
    cls->install();
    JSBClassType::registerClass<copra::Test>(cls);

    __jsb_copra_Test_proto = cls->getProto();
    __jsb_copra_Test_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_cp(se::Object* obj)
{
    // Get the ns
    se::Value nsVal;
    if (!obj->getProperty("cp", &nsVal))
    {
        se::HandleObject jsobj(se::Object::createPlainObject());
        nsVal.setObject(jsobj);
        obj->setProperty("cp", nsVal);
    }
    se::Object* ns = nsVal.toObject();

    js_register_cp_Test(ns);
    return true;
}

