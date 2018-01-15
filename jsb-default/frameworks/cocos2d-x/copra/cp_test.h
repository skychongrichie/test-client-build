//
//  cp_test.hpp
//  cocos2d_js_bindings
//
//  Created by cHong on 2018/1/4.
//

#ifndef cp_test_hpp
#define cp_test_hpp

#include <vector>

namespace copra {
    class TestDelegate{
    public:
        virtual void Fight()=0;
    };
    
    class Test{
    public:
        static void staticTestFunc();
        Test();
        int getCount();
        void print();
        void fight();
        void setDelegate(TestDelegate* delegate);
        int getArrayLength(const std::vector<int>& list);
    private:
        TestDelegate* delegate_;
        int age_;
    };
}

#endif /* cp_test_hpp */
