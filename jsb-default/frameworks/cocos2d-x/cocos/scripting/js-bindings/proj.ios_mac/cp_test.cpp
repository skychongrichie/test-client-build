//
//  cp_test.cpp
//  cocos2d_js_bindings
//
//  Created by cHong on 2018/1/4.
//

#include "cocos2d.h"
#include "cp_test.h"

using namespace std;

namespace copra {
    Test::Test():age_(10){}
    
    void Test::staticTestFunc(){
        CCLOG("static function");
    }
    
    int Test::getCount(){
        return 3;
    }
    
    void Test::print(){
        CCLOG("hello world");
    }
    
    void Test::fight(){
        if(delegate_)
            delegate_->Fight();
    }
    
    void Test::setDelegate(TestDelegate* delegate){
        delegate_ = delegate;
    }
    
    int Test::getArrayLength(const vector<int>& list){
        return static_cast<int>(list.size()) ;
    }
}
