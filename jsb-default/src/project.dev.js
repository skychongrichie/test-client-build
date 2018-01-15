require = function e(t, n, r) {
  function s(o, u) {
    if (!n[o]) {
      if (!t[o]) {
        var a = "function" == typeof require && require;
        if (!u && a) return a(o, !0);
        if (i) return i(o, !0);
        var f = new Error("Cannot find module '" + o + "'");
        throw f.code = "MODULE_NOT_FOUND", f;
      }
      var l = n[o] = {
        exports: {}
      };
      t[o][0].call(l.exports, function(e) {
        var n = t[o][1][e];
        return s(n || e);
      }, l, l.exports, e, t, n, r);
    }
    return n[o].exports;
  }
  var i = "function" == typeof require && require;
  for (var o = 0; o < r.length; o++) s(r[o]);
  return s;
}({
  HelloWorld: [ function(require, module, exports) {
    "use strict";
    cc._RF.push(module, "280c3rsZJJKnZ9RqbALVwtK", "HelloWorld");
    "use strict";
    var obj = {};
    obj.fight = function() {
      cc.log("delegate_fight");
    };
    cc.Class({
      extends: cc.Component,
      properties: {
        label: {
          default: null,
          type: cc.Label
        },
        text: "Hello, World!"
      },
      onLoad: function onLoad() {
        this.label.string = this.text;
      },
      start: function start() {},
      update: function update(dt) {},
      onClick: function onClick() {
        cc.log("onClick");
        this._test();
        cc.sys.garbageCollect();
        cc.log("end");
      },
      _test: function _test() {
        cc.log("mark1");
        var test = new cp.Test();
        cc.log("mark2");
        test.print();
        cc.log("mark3");
      }
    });
    cc._RF.pop();
  }, {} ],
  Utils: [ function(require, module, exports) {
    "use strict";
    cc._RF.push(module, "d5011sdGuxPWoZ5ibb7n2TX", "Utils");
    "use strict";
    cocosAnalytics.init({
      appID: "13798",
      appSecret: "959b3ac0037d0f3c2fdce94f8421a9b2",
      channel: "000000",
      version: "1.6.2"
    });
    cc._RF.pop();
  }, {} ]
}, {}, [ "HelloWorld", "Utils" ]);
//# sourceMappingURL=project.dev.js.map