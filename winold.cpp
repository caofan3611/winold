#include <iostream>
using namespace std;
#include "winold.h"
#include "winold_define.h"
#include <vector>
// winold::winold_pen winold::pen;
winold::vidtype winold::nullvid;
bool winold::isError(string s) {
  // debug("进入isError(string s)");
  // debug("s:",s);
  // debug("结果是:",s==WINOLD_ERROR_STRING);

  return s == WINOLD_ERROR_STRING;
}
bool winold::isError(ll s) {
  // debug("进入isError(ll s)");
  // debug("s:",s);
  // debug("结果是:",s==WINOLD_ERROR_NUMBER);

  return s == WINOLD_ERROR_NUMBER;
}

void winold::errf(winold_error e, bool b) {
  // debug("start:errf(winold_error e,bool b)");
  if (b) {
    // debug("发生错误");
    cout << "winold发生错误!\nwinold:" << e.type << "\n程序异常终止" << endl;

    // winold_error error;
    throw e;
  }
  // debug("end");
}
ll winold::createMap(string n) {
  // debug("start createMap(string n)");
  // debug("n:",n);
  winold_error err;
  if (maps.empty()) {
    // debug("maps空空空空空空空");
    cout << "";
  } else {
    for (auto i : maps) {
      if (i.name == n) {
        // debug("名称重复!");
        err.type =
            "createMap:名称重复了,嗯嗯嗯,你这个坏孩子!搞得人家好无语呀(\"▔□▔)";
        errf(err);
        return WINOLD_ERROR_NUMBER;
      }
    }
  };
  string vvv;

  maps.push_back(winold_map(n, vvv));
  return maps.size() - 1;
}
ll winold::createMap(string n, string v) {
  winold_error err;
  if (maps.empty()) {
    ;
  } else {
    for (auto i : maps) {
      if (i.name == n) {

        err.type = "createMap:名称重复了,这样子我会分不清地图的呀!(\"▔□▔)";
        errf(err);
        return WINOLD_ERROR_NUMBER;
      }
    }
  };

  maps.push_back(winold_map(n, v));
  return maps.size() - 1;
}
string winold::getMapName(ll n) {
  // debug("进入getMapName(ll n)");
  // debug("n:",n);
  winold_error err;
  if (maps.empty() == true) {
    // debug("空的");
    err.type =
        "getMapName:没有添加地图,哪来的获取名字?再欺骗我，我要伤心了(′へ`、 )";
    errf(err);
    return WINOLD_ERROR_STRING;
  } else {
    if (n > maps.size() - 1) {
      if (n < 0) {
        // debug("index是负数");
        err.type = "getName:为什么下标是负数???你为什么背叛了我!ヽ(‘⌒´メ)ノ";
        errf(err);
        return WINOLD_ERROR_STRING;
      }
      err.type = "getName:这该死的下标!!!为什么就是超出了正常下标的范围呢?"
                 "你为什么不改改?唉，可怜的下标居然超出了最高下标范围(ー_ー)!!";
      errf(err);
      return WINOLD_ERROR_STRING;

    } else if (n < 0) {

      err.type =
          "getName:为什么,究竟是为什么!!!不要把下标写成负数!!!...( ＿ ＿)ノ｜";
      errf(err);
      return WINOLD_ERROR_STRING;
    } else {
      return maps[n].name;
    };
  };
}
bool winold::winold_one = true;
bool winold::iserr = true;

void winold::openError() { iserr = true; }
void winold::closeError() { iserr = false; }

void winold::setOutColor(ll c) {

  stmp = "\033[" + to_string(c) + "m";
  cout << stmp;
}
void winold::resetOutColor() { setOutColor(WINOLD_RESET); }
ll winold::createPic(string n) {
  winold_error err;
  if (pics.empty()) {
    ;
  } else {
    for (auto i : pics) {
      if (i.name == n) {

        err.type =
            "createMap:名称重复了,嗯嗯嗯,你这个坏孩子!搞得人家好无语呀(\"▔□▔)";
        errf(err);
        return WINOLD_ERROR_NUMBER;
      }
    }
  };
  string vvv;

  pics.push_back(winold_pic(n, vvv));
  return pics.size() - 1;
}
ll winold::createPic(string n, string v) {
  winold_error err;
  if (pics.empty()) {
    ;
  } else {
    for (auto i : pics) {
      if (i.name == n) {

        err.type = "createPic:名称重复了,这样子我会分不清地图的呀!(\"▔□▔)";
        errf(err);
        return WINOLD_ERROR_NUMBER;
      }
    }
  };

  pics.push_back(winold_pic(n, v));
  return pics.size() - 1;
}
string winold::getPicName(ll n) {
  winold_error err;
  if (pics.empty() == true) {
    err.type = "getPicName:我图呢???一个也没有!winold要伤心了(′へ`、 )";
    errf(err);
    return WINOLD_ERROR_STRING;
  } else {
    if (n > pics.size() - 1) {
      if (n < 0) {
        err.type = "getPicName:为什么下标是负数???你为什么背叛了我!ヽ(‘⌒´メ)ノ";
        errf(err);
        return WINOLD_ERROR_STRING;
      }
      err.type = "getPicName:这该死的下标!!!为什么就是超出了正常下标的范围呢?"
                 "你为什么不改改?唉，可怜的下标居然超出了最高下标范围(ー_ー)!!";
      errf(err);
      return WINOLD_ERROR_STRING;
    } else if (n < 0) {
      err.type = "getPicName:为什么,究竟是为什么!!!不要把下标写成负数!!!...( "
                 "＿ ＿)ノ｜";
      errf(err);
      return WINOLD_ERROR_STRING;
    } else {
      return pics[n].name;
    };
  };
  err.type = to_string(__LINE__);
  errf(err);
  return WINOLD_ERROR_STRING;
}
void winold::setTitle(string t) {
  string s = "\033]2;" + t + "\007";
  cout << s;
}
ll winold::replaceMap(string s, string v) {
  winold_error err;
  if (maps.empty()) {
    err.type = "replaceMap:不!!!地图明明是空的!～(TロT)σ";
    errf(err);
    return WINOLD_ERROR_NUMBER;
  } else {
    for (ll i = 0; i < maps.size(); i++) {
      if (maps[i].name == s) {
        maps[i].thing = v;
        return 0;
      }
    }
    err.type = "replaceMap:are you ok!!! 没有这个地图!";
    errf(err);
    return WINOLD_ERROR_NUMBER;
  };
}
ll winold::replacePic(string s, string v) {
  winold_error err;
  if (pics.empty()) {
    err.type = "replacePic:不!!!pic明明是空的!～(TロT)σ";
    errf(err);
    return WINOLD_ERROR_NUMBER;
  } else {
    for (ll i = 0; i < pics.size(); i++) {
      if (pics[i].name == s) {
        pics[i].thing = v;
        return 0;
      }
    }
    err.type = "replaceMap:are you ok⊙_⊙ 没有这个pic!";
    errf(err);
    return WINOLD_ERROR_NUMBER;
  };
}
ll winold::replaceMap(long long l, string v) {
  // debug("进入replaceMap(long long l,vector<string> v)");
  // debug("l:",l);
  closeError();
  // debug("已关闭错误");
  winold_error err;
  // debug("即将调用get map name");
  string i = getMapName(l);
  if (i == WINOLD_ERROR_STRING) {
    // debug(" Get map name出现问题");
    openError();
    err.type = "replaceMap:根本就没有这个下标嘛(* ￣︿￣)";
    errf(err);
    return WINOLD_ERROR_NUMBER;
  } else {
    // debug(" Get map name没有问题");
    replaceMap(i, v);
    return 0;
  };
  openError();
  return WINOLD_ERROR_NUMBER;
}
ll winold::replacePic(long long l, string v) {
  closeError();
  winold_error err;
  string i = getPicName(l);
  if (isError(i)) {
    openError();
    err.type = "replacePic:根本就没有这个下标嘛(* ￣︿￣)";
    errf(err);
    return WINOLD_ERROR_NUMBER;
  } else {
    replacePic(i, v);
    return 0;
  };
  openError();
  return WINOLD_ERROR_NUMBER;
}
void winold::debug(string s) {
  // 留空......
}
template <typename tt> void winold::debug(string s, tt t) {
  // 留空......
}
ll winold::getMapIndex(string s) {
  winold_error e;
  if (maps.empty()) {
    e.type = "getMapIndex:地图。。。。是空的。。。";
    errf(e);
    return WINOLD_ERROR_NUMBER;
  } else {

    for (int i = 0; i < maps.size(); i++) {
      if (maps[i].name == s) {
        return i;
      }
    }
    e.type = "getMapIndex:呃,好像没有这玩意儿,你传进来的名称有误:)";
    errf(e);
    return WINOLD_ERROR_NUMBER;
  };
  e.type = "getMapIndex:这...这是个未知的错误啊...";
  errf(e);
  return WINOLD_ERROR_NUMBER;
}
ll winold::getPicIndex(string s) {
  winold_error e;
  if (pics.empty()) {
    e.type = "getMapIndex:地图。。。。是空的。。。";
    errf(e);
    return WINOLD_ERROR_NUMBER;
  } else {

    for (int i = 0; i < pics.size(); i++) {
      if (pics[i].name == s) {
        return i;
      }
    }
    e.type = "getMapIndex:呃,好像没有这玩意儿,你传进来的名称有误:)";
    errf(e);
    return WINOLD_ERROR_NUMBER;
  };
  e.type = "getMapIndex:这...这是个未知的错误啊...";
  errf(e);
  return WINOLD_ERROR_NUMBER;
}
template <class type> ll winold::root_remove_(type &ts, string s) {
  if (ts.empty()) {
    return WINOLD_ERROR_NUMBER;
  }
  for (auto i = ts.begin(); i != ts.end(); i++) {
    if (i->name == s) {
      ts.erase(i);
      return 0;
    }
  }
  return WINOLD_ERROR_NUMBER;
}

ll winold::removeMap(string s) {
  if (root_remove_(maps, s) == WINOLD_ERROR_NUMBER) {
    winold_error e;
    e.type = "removeMap:可是...没有没有没有没有。。。没有这个元素...";
    errf(e);
    return WINOLD_ERROR_NUMBER;
  }
  /*
  if(root_remove_(maps,s)==1){
          winold_error e;
  e.type="removeMap:可是...地图是空的!ᵕ᷄≀ ̠ᵕ᷅ ";
  errf(e);
  return WINOLD_ERROR_NUMBER;
  */
  return 0;
}

ll winold::removeMap(ll l) { return removeMap(getMapName(l)); }

ll winold::removePic(string s) {
  if (root_remove_(pics, s) == WINOLD_ERROR_NUMBER) {
    winold_error e;
    e.type = "removeMap:可是...没有没有没有没有。。。没有这个元素...";
    errf(e);
    return WINOLD_ERROR_NUMBER;
  }
  /*
   * if(root_remove_(maps,s)==1){
   *         winold_error e;
   *         e.type="removeMap:可是...地图是空的!ᵕ᷄≀ ̠ᵕ᷅ ";
   *         errf(e);
   *         return WINOLD_ERROR_NUMBER;
   *         */
  return 0;
}

ll winold::removePic(ll l) { return removePic(getPicName(l)); }
void winold::clearMap() { maps.clear(); }
void winold::clearPic() { pics.clear(); }

ll winold::showPic(string s, bool isln) {
  winold_error err;
  if (pics.empty()) {
    err.type = "showMap:不好啦不好啦!没有地图的地方不能凭空出现啦 (⊙o⊙)";
    errf(err);
    return WINOLD_ERROR_NUMBER;
  }
  for (auto i : pics) {
    if (i.name == s) {
      cout << i.thing;
      if (isln) {
        cout << endl;
      }
      return 0;
    }
  }
  err.type = "showPic:没有这张图片啊(=°Д°=)";
  errf(err);
  return WINOLD_ERROR_NUMBER;
}
ll winold::showPic(ll l, bool isln) {
  string sl = getPicName(l);
  showPic(sl, isln);
  return 0;
}

ll winold::createVid(string name_, ll sleepn_, vidtype thing_) {
  winold_error err;
  if (sleepn_ < 0) {
    err.type = "createVid:爆炸！大！新闻!!! "
               "居然有人把停顿秒数设置成数负数!\ncaofan3611→▄█▀█● 🤔←你";
    errf(err);
    return WINOLD_ERROR_NUMBER;
  }
  for (winold_vid tmp : vids) {
    if (tmp.name == name_) {
      err.type =
          "createVid:不是吧?这个都能名字重复?还让动画君我怎么办啊_(´_`」 ∠)_";

      errf(err);
      return WINOLD_ERROR_NUMBER;
    }
  }
  winold_vid v;
  v.name = name_;
  v.sleepn = sleepn_;
  v.thing = thing_;
  vids.push_back(v);
  return 0;
}

ll winold::createVid(string name_, vidtype thing_) {
  createVid(name_, 0, thing_);
  return 0;
}
  ll winold::createVid(string name_) {
    createVid(name_, winold::nullvid);
    return 0;
  }
