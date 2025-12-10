/*
copyright caofan3611 2025
winold.cpp
apache2.0
*/
#include <iostream>
#include <ctime>
#include <thread>
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
        cout << "winold发生错误!\nwinold:" << e.type <<"\n错误码(error code):"<<e.code<< "\n程序异常终止" << endl;

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
        if(maps_table.find(n)!=maps_table.end()) {
            err.type =
                "createMap:名称重复了,嗯嗯嗯,你这个坏孩子!搞得人家好无语呀(\"▔□▔)";
            err.code="CREATE_MAP_NAME_DEFINED";
            errf(err);
            return WINOLD_ERROR_NUMBER;
        }

    };
    string vvv;
    maps_table.insert(n);
    maps.push_back(winold_map(n, vvv));
    return maps.size() - 1;
}
ll winold::createMap(string n, string v) {
    winold_error err;
    if (maps.empty()) {

    } else {

        if(maps_table.find(n)!=maps_table.end())
        {

            err.type = "createMap:名称重复了,这样子我会分不清地图的呀!(\"▔□▔)";
            err.code="CREATE_MAP/NAME_DEFINED";
            errf(err);
            return WINOLD_ERROR_NUMBER;
        }


    };
    maps_table.insert(n);
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
        err.code="GET_MAP_NAME/NOT_ANY_MAP";
        errf(err);
        return WINOLD_ERROR_STRING;
    } else {
        if (n > maps.size() - 1) {
            if (n < 0) {
                // debug("index是负数");
                err.type = "getMapName:为什么下标是负数???你为什么背叛了我!ヽ(‘⌒´メ)ノ";
                err.code="GET_MAP_NAME/INDEX_TOO_SMALL";
                errf(err);
                return WINOLD_ERROR_STRING;
            }
            err.type = "getMapName:这该死的下标!!!为什么就是超出了正常下标的范围呢?"
                       "你为什么不改改?唉，可怜的下标居然超出了最高下标范围(ー_ー)!!";
            err.code="GET_MAP_NAME/INDEX_TOO_BIG";
            errf(err);
            return WINOLD_ERROR_STRING;

        } else if (n < 0) {

            err.type =
                "getMapName:为什么,究竟是为什么!!!不要把下标写成负数!!!...( ＿ ＿)ノ｜";
            err.code="GET_MAP_NAME/INDEX_TOO_SMALL";
            errf(err);
            return WINOLD_ERROR_STRING;
        } else {
            return maps[n].name;
        };
    };
}
bool winold::winold_one = true;
bool winold::iserr = true;

void winold::openError() {
    iserr = true;
}
void winold::closeError() {
    iserr = false;
}

void winold::setOutColor(ll c) {

    stmp = "\033[" + to_string(c) + "m";
    cout << stmp<<std::flush;
}
void winold::resetOutColor() {
    setOutColor(WINOLD_RESET);
}
ll winold::createPic(string n) {
    /*预留原本的版本，防止出错:
    winold_error err;
    if (pics.empty()) {
        ;//我也不知道干嘛，反正就把这个空语句留在这儿
    } else {

        if (pics_table.find(n)!=pics_table.end()) {

            err.type =
                "createMap:名称重复了,嗯嗯嗯,你这个坏孩子!搞得人家好无语呀(\"▔□▔)";
                err.code="CREATE_PIC/NAME_DEFINED";
            errf(err);
            return WINOLD_ERROR_NUMBER;
        }
        pics_table.insert(n);
    };
    string vvv;

    pics.push_back(winold_pic(n, vvv));
    return pics.size() - 1;
    */
    createPic(n,"");
    return 0;
}
ll winold::createPic(string n, string v) {
    winold_error err;
    if (pics.empty()) {
        ;
    } else {
        if (pics_table.find(n)!=pics_table.end()) {

            err.type =
                "createPic:名称重复了,嗯嗯嗯,你这个坏孩子!搞得人家好无语呀(\"▔□▔)";
            err.code="CREATE_PIC/NAME_DEFINED";
            errf(err);
            return WINOLD_ERROR_NUMBER;
        }
        pics_table.insert(n);
    };

    pics.push_back(winold_pic(n, v));
    return pics.size() - 1;
};

string winold::getPicName(ll n) {
    winold_error err;
    if (pics.empty() == true) {
        err.type = "getPicName:我图呢???一个也没有!winold要伤心了(′へ`、 )";
        err.code="GET_PIC_NAME/NOT_ANY_PIC";
        errf(err);
        return WINOLD_ERROR_STRING;
    } else {
        if (n > pics.size() - 1) {
            if (n < 0) {
                err.type = "getPicName:为什么下标是负数???你为什么背叛了我!ヽ(‘⌒´メ)ノ";
                err.code="GET_PIC_NAME/INDEX_TOO_SMALL";
                errf(err);
                return WINOLD_ERROR_STRING;
            }
            err.type = "getPicName:这该死的下标!!!为什么就是超出了正常下标的范围呢?"
                       "你为什么不改改?唉，可怜的下标居然超出了最高下标范围(ー_ー)!!";
            err.code="GET_PIC_NAME/INDEX_TOO_BIG";
            errf(err);
            return WINOLD_ERROR_STRING;
        } else if (n < 0) {
            err.type = "getPicName:为什么,究竟是为什么!!!不要把下标写成负数!!!...( "
                       "＿ ＿)ノ｜";
            err.code="GET_PIC_NAME/INDEX_TOO_SMALL";
            errf(err);
            return WINOLD_ERROR_STRING;
        } else {
            return pics[n].name;
        };
    };
    err.type = to_string(__LINE__)+"/randerr!";
    errf(err);
    return WINOLD_ERROR_STRING;
}
void winold::setTitle(string t) {
    string s = "\033]2;" + t + "\007";
    cout << s<<std::flush;
}
ll winold::replaceMap(string s, string v) {
    winold_error err;
    if (maps.empty()) {
        err.type = "replaceMap:不!!!地图明明是空的!～(TロT)σ";
        err.code="REPLACE_MAP/NOT_ANY_MAP";
        errf(err);
        return WINOLD_ERROR_NUMBER;
    } else {
        if(maps_table.find(s)!=maps_table.end()) {
            for (ll i = 0; i < maps.size(); i++) {
                if (maps[i].name == s) {
                    maps[i].thing = v;
                    return 0;
                }
            }
        }
        err.type = "replaceMap:are you ok!!! 没有这个地图!";
        err.code="REPLACE_MAP/NOT_THIS_MAP";
        errf(err);
        return WINOLD_ERROR_NUMBER;
    };
}
ll winold::replacePic(string s, string v) {
    winold_error err;
    if (pics.empty()) {
        err.type = "replacePic:不!!!pic明明是空的!～(TロT)σ";
        err.code="REPLACE_PIC/NOT_ANY_PIC";
        errf(err);
        return WINOLD_ERROR_NUMBER;
    } else {
        if(pics_table.find(s)!=pics_table.end()) {
            for (ll i = 0; i < pics.size(); i++) {
                if (pics[i].name == s) {
                    pics[i].thing = v;
                    return 0;
                }
            }
        }
        err.type = "replacePic:are you ok⊙_⊙ 没有这个pic!";
        err.code="REPLACE_PIC/NOT_THIS_PIC";
        errf(err);
        return WINOLD_ERROR_NUMBER;
    };
}
ll winold::replaceMap(long long l, string v) {
    // debug("进入replaceMap(long long l,vector<string> v)");
    // debug("l:",l);
    bool iserr_copy=winold::iserr;
    closeError();//false
    // debug("已关闭错误");
    winold_error err;
    // debug("即将调用get map name");
    string i = getMapName(l);
    if (i == WINOLD_ERROR_STRING) {
        // debug(" Get map name出现问题");
        err.type = "replaceMap:根本就没有这个下标嘛(* ￣︿￣)";
        err.code="REPLACE_MAP/NOT_THIS_INDEX";
        if(iserr_copy==true)//true
        {
            openError();//true
        } else
        {
            closeError();
        };
        errf(err);
        return WINOLD_ERROR_NUMBER;
    } else {
        // debug(" Get map name没有问题");
        if(iserr_copy==true)//true
        {
            openError();//true
        } else
        {
            closeError();
        };
        replaceMap(i, v);
        return 0;
    };
    winold_error randl;
    randl.code=to_string(__LINE__);
    errf(randl);
    return WINOLD_ERROR_NUMBER;
}
ll winold::replacePic(ll l, string v) {
    bool iserr_copy=winold::iserr;
    closeError();
    winold_error err;
    string i = getPicName(l);
    if (isError(i)) {
        if(iserr_copy==true)//true
        {
            openError();//true
        } else
        {
            closeError();
        };
        err.type = "replacePic:根本就没有这个下标嘛(* ￣︿￣)";
        err.code="REPLACE_PIC/NOT_THIS_INDEX";
        errf(err);
        return WINOLD_ERROR_NUMBER;
    } else {
        replacePic(i, v);
        return 0;
    };
    if(iserr_copy==true)//true
    {
        openError();//true
    } else
    {
        closeError();
    };
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
        e.code="GET_MAP_INDEX/NOT_ANY_MAP";
        errf(e);
        return WINOLD_ERROR_NUMBER;
    } else {
        if(maps_table.find(s)!=maps_table.end()) {
            for (int i = 0; i < maps.size(); i++) {
                if (maps[i].name == s) {
                    return i;
                }
            }
        }
        e.type = "getMapIndex:呃,好像没有这玩意儿,你传进来的名称有误:)";
        e.code="GET_MAP_INDEX/NOT_THIS_MAP";
        errf(e);
        return WINOLD_ERROR_NUMBER;
    };
    e.type = "getMapIndex:这...这是个未知的错误啊...\nranderr!";
    errf(e);
    return WINOLD_ERROR_NUMBER;
}
ll winold::getPicIndex(string s) {
    winold_error e;
    if (pics.empty()) {
        e.type = "getPicIndex:地图。。。。是空的。。。";
        e.code="GET_PIC_INDEX/NOT_ANY_PIC";
        errf(e);
        return WINOLD_ERROR_NUMBER;
    } else {
        for (int i = 0; i < pics.size(); i++) {
            if (pics[i].name == s) {
                return i;
            }
        }
        e.type = "getPicIndex:呃,好像没有这玩意儿,你传进来的名称有误:)";
        e.code="GET_PIC_INDEX/NOT_THIS_PIC";
        errf(e);
        return WINOLD_ERROR_NUMBER;
    };
    e.type = "getPicIndex:这...这是个未知的错误啊...";
    e.code=to_string(__LINE__);
    errf(e);
    return WINOLD_ERROR_NUMBER;
}
template <class type> ll winold::root_remove_(type &ts, string s,string n) {
    if (ts.empty()) {
        return WINOLD_ERROR_NUMBER;
    }
    for (auto i = ts.begin(); i != ts.end(); i++) {
        if (i->name == s) {
            ts.erase(i);
            if(n=="map")
            {
                //   cout << "map"<< endl;
                maps_table.erase(s);
            } else if(n=="pic")
            {
                //     cout << "pic"<< endl;
                pics_table.erase(s);
            }
            return 0;
        }
    }
    return WINOLD_ERROR_NUMBER;
}

ll winold::removeMap(string s) {
    if (root_remove_(maps, s,"map") == WINOLD_ERROR_NUMBER) {
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

ll winold::removeMap(ll l) {
    return removeMap(getMapName(l));
}

ll winold::removePic(string s) {
    if (root_remove_(pics, s,"pic") == WINOLD_ERROR_NUMBER) {
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

ll winold::removePic(ll l) {
    return removePic(getPicName(l));
}
void winold::clearMap() {
    maps.clear();
    maps_table.clear();
}
void winold::clearPic() {
    pics.clear();
    pics_table.clear();
}
void winold::clearVid() {
    vids.clear();
    vids_table.clear();
}

ll winold::showPic(string s, bool isln) {
    winold_error err;
    if (pics.empty()) {
        err.type = "showPic:不好啦不好啦!没有地图的地方不能凭空出现啦 (⊙o⊙)";
        err.code="SHOW_PIC/NOT_PIC";
        errf(err);
        return WINOLD_ERROR_NUMBER;
    }
    if(pics_table.find(s)!=pics_table.end()) {
        for (auto i : pics) {
            if (i.name == s) {
                cout << i.thing;
                if (isln) {
                    cout << endl;
                }
                return 0;
            }
        }
    }
    err.type = "showPic:没有这张图片啊(=°Д°=)";
    errf(err);
    return WINOLD_ERROR_NUMBER;
}
ll winold::showPic(ll l, bool isln) {
    string sl = getPicName(l);
    if(isError(sl))
    {
        winold_error err;
        err.type="showPic:嗯对,大概就是根本找不到这个下标吧( ^_^ )";
        err.code="SHOW_PIC/NOT_THIS_INDEX";
        errf(err);
        return WINOLD_ERROR_NUMBER;
    }
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

    if (vids_table.find(name_)!=vids_table.end()) {
        err.type =
            "createVid:不是吧?这个都能名字重复?还让动画君我怎么办啊_(´_`」 ∠)_";

        errf(err);
        return WINOLD_ERROR_NUMBER;
    }

    winold_vid v;
    v.name = name_;
    v.sleepn = sleepn_;
    v.thing = thing_;
    vids_table.insert(name_);
    vids.push_back(v);
    for(int i = 0;i < thing_.size();i++) {
    vids[vids.size()-1].color.insert({i,std::map<ll,ll>()});
   }
    return vids.size()-1;
}

ll winold::createVid(string name_, vidtype thing_) {
    createVid(name_, 0, thing_);
    return 0;
}
ll winold::createVid(string name_) {
    createVid(name_, winold::nullvid);
    return 0;
}

ll winold::replaceVid(string name_, ll sleepn_, winold::vidtype thing_) {
    winold_error err;
    if(vids_table.find(name_)==vids_table.end()) {
        err.type="replaceVid:压根就没有这个vid啊﹁_﹂";
        errf(err);
        return WINOLD_ERROR_NUMBER;
    }
    for(auto i = vids.begin(); i!=vids.end(); i++) {
        if(i->name==name_)
        {
            i->sleepn=sleepn_;
            i->thing=thing_;
            goto goto_replaceVid_nameFinded;
        }
    }
    err.type="randerr!";
    errf(err);
    return WINOLD_ERROR_NUMBER;
goto_replaceVid_nameFinded:
    return 0;
}

ll winold::replaceVid(string name_, winold::vidtype thing_) {
    replaceVid(name_,0,thing_);
    return 0;
}

ll winold::fpsToMicrosecond(ll fpsn) {
    long double x=static_cast<long double>(1)/static_cast<long double>(fpsn);
    return x*1000000;
}

ll winold::setVidSleep(string s,ll l) {
    winold_error err;
    if(vids_table.find(s)==vids_table.end()) {
        err.type="setVidSleep:不好了!vid我居然没找到这个元素!╯﹏╰";
        err.code="SET_VID_SLEEP/NOT_HAVE_THIS_VID";
        errf(err);
        return WINOLD_ERROR_NUMBER;
    } else
    {
        if(l<=0)
        {
            err.type="setVidSleep:你你你你你你你你你又是你!停顿时长为什么是负数or零?";
            err.code="SET_VID_SLEEP/TIME_IS_BAD";
            errf(err);
            return WINOLD_ERROR_NUMBER;
        }
        for(auto &i:vids) {
            if(i.name==s)
            {
                i.sleepn=l;
                return 0;
            }
        }
        err.code="setvidsleep:randerr";
        errf(err);
        return WINOLD_ERROR_NUMBER;
    };
    err.code="setvidsleep:randerr2";
    errf(err);
    return WINOLD_ERROR_NUMBER;
}

ll winold::setVidSleep(ll i,ll l) {
    bool iserr_copy=winold::iserr;
    closeError();
    string xs=getVidName(i);
    if(isError(xs))
    {
        if(iserr_copy==true)//true
        {
            openError();//true
        } else
        {
            closeError();
        };
        winold_error errx;
        errx.type="setVidSleep:这个玩意不 存 在!";
        errx.code="SET_VID_SLEEP/NOT_THIS_INDEX";
        errf(errx);
        return WINOLD_ERROR_NUMBER;
    }
    setVidSleep(xs,l);
    return 0;
}

string winold::getVidName(ll n) {
    // debug("进入getMapName(ll n)");
    // debug("n:",n);
    winold_error err;
    if (vids.empty() == true) {
        // debug("空的");
        err.type =
            "getVidName:没有添加vid,哪来的获取名字?再欺骗我，我要伤心了(′へ`、 )";
        err.code="GET_VID_NAME/NOT_ANY_VID";
        errf(err);
        return WINOLD_ERROR_STRING;
    } else {
        if (n > vids.size() - 1) {
            if (n < 0) {
                // debug("index是负数");
                err.type = "getVidName:为什么下标是负数???你为什么背叛了我!ヽ(‘⌒´メ)ノ";
                err.code="GET_VID_NAME/INDEX_TOO_SMALL";
                errf(err);
                return WINOLD_ERROR_STRING;
            }
            err.type = "getVidName:这该死的下标!!!为什么就是超出了正常下标的范围呢?"
                       "你为什么不改改?唉，可怜的下标居然超出了最高下标范围(ー_ー)!!";
            err.code="GET_VID_NAME/INDEX_TOO_BIG";
            errf(err);
            return WINOLD_ERROR_STRING;

        } else if (n < 0) {

            err.type =
                "getVidName:为什么,究竟是为什么!!!不要把下标写成负数!!!...( ＿ ＿)ノ｜";
            err.code="GET_VID_NAME/INDEX_TOO_SMALL";
            errf(err);
            return WINOLD_ERROR_STRING;
        } else {
            return vids[n].name;
        };
    };
}


ll winold::getVidIndex(string s) {
    winold_error e;
    if (vids.empty()) {
        e.type = "getVidIndex:地图。。。。是空的。。。";
        e.code="GET_VID_INDEX/NOT_ANY_VID";
        errf(e);
        return WINOLD_ERROR_NUMBER;
    } else {
        if(vids_table.find(s)!=vids_table.end()) {
            for (int i = 0; i < vids.size(); i++) {
                if (vids[i].name == s) {
                    return i;
                }
            }
        }
        e.type = "getVidIndex:呃,好像没有这玩意儿,你传进来的名称有误:)";
        e.code="GET_VID_INDEX/NOT_THIS_VID";
        errf(e);
        return WINOLD_ERROR_NUMBER;
    };
    e.type = "getVidIndex:这...这是个未知的错误啊...\nranderr!";
    errf(e);
    return WINOLD_ERROR_NUMBER;
}

ll winold::removeVid(ll l) {
    if(l>vids.size()-1 || l<0)
    {
        winold_error err;
        err.type="removeVid:这个vid压根就没有啊啊啊啊啊啊啊(´;︵;`)";
        err.code="REMOVE_VID/NOT_THIS_VID";
        errf(err);
        return WINOLD_ERROR_NUMBER;
    }
    auto iter=vids.begin();
    for(ll i=0; i<l; i++) {
        iter++;
    }
    vids.erase(iter);
    return 0;
}

ll winold::removeVid(string s) {
    bool iserr_copy=winold::iserr;
    closeError();
    ll xx=getVidIndex(s);
    if(isError(xx))
    {
        winold_error err;
        err.type="removeVid:玛卡巴卡～晚安!这个名字不存在呢!好宝宝可不要学习这种做法∩_∩";
        err.code="REMOVE_VID/NOT_THIS_NAME";
        if(iserr_copy==true)//true
        {
            openError();//true
        } else
        {
            closeError();
        };
        errf(err);
        return WINOLD_ERROR_NUMBER;
    }
    if(iserr_copy==true)//true
    {
        openError();//true
    } else
    {
        closeError();
    };
    removeVid(xx);
    return 0;
}

ll winold::playVid(ll l,ll times) {
    if(l>vids.size()-1 || l<0)
    {
        winold_error err;
        err.type="playVid:这个vid压根就没有啊啊啊啊啊啊啊(´;︵;`)";
        err.code="PLAY_VID/NOT_THIS_VID";
        errf(err);
        return WINOLD_ERROR_NUMBER;
    }
    for(int  for_times= 0; for_times< times;for_times++) {
        auto frame_iter=vids[l].color.begin();
    auto char_iter=frame_iter->second.begin();
    for(int for_frame = 0; for_frame < vids[l].thing.size(); for_frame++) {
        clearScreen();
        for(int for_char = 0; for_char < vids[l].thing[for_frame].size(); for_char++) {
            bool ison=false;
            //char_iter=frame_iter->second.begin();
            if(frame_iter!=vids[l].color.end()&&char_iter!=frame_iter->second.end()&&frame_iter->first==for_frame&&char_iter->first==for_char)
            {
                setOutColor(char_iter->second);
                ison=true;
            }else
            {
                resetOutColor();
            };
            std::wcout <<vids[l].thing[for_frame][for_char]<< std::flush;
            if(ison)
            {
                char_iter++;
            }
        }
        if(frame_iter!=vids[l].color.end())
        {
            frame_iter++;
        }
        std::this_thread::sleep_for(std::chrono::microseconds(vids[l].sleepn));
    }
    }
    return 0;
}

ll winold::playVid(string s,ll times) {
    bool iserr_copy=winold::iserr;
    closeError();
    if(isError(getVidIndex(s)))
    {
        winold_error err;
        err.type="playVid:嗯对大概就是嗯很正常很合理,根本没有这个vid啊喂!";
        err.code="PLAY_VID/NOT_THIS_VID";
        if(iserr_copy==true)//true
        {
            openError();//true
        } else
        {
            closeError();
        };
        errf(err);
        return WINOLD_ERROR_NUMBER;
    }
    if(iserr_copy==true)//true
    {
        openError();//true
    } else
    {
        closeError();
    };
    playVid(getVidIndex(s),times);
    return 0;
}

void winold::clearScreen() {
    cout << "\033[2J\033[H"<< std::flush;
}

ll winold::setVidFrameColor(ll index_,ll frame_,ll color_,vector<ll> range_) {
    if(index_>=vids.size()||index_<0)
    {
        winold_error err;
        err.type="setVidFrameColor:您好,您选择的下标暂时无法访问,也就是说,你又双叒叕写了超出范围的下标Y(^_^)Y";
        err.code="SET_VID_FRAME_COLOR/INDEX_NOT_FOUND";
        errf(err);
        return WINOLD_ERROR_NUMBER;
    } else
    {
        //auto vid=vids[index_];
        // auto colorv=vid.color;
        char what_is_this_variable='h';
        char i_do_not_know_too='a';
        auto &vid_f=vids[index_];
        //就写着占内存的,万一有用户反馈内存过大我就删掉
        if(frame_>=vid_f.thing.size()||frame_<0)
        {
            winold_error err2;
            err2.type="setVidFrameColor:泥在干神马! 帧 的 下 标 超 出 范 围 了啊喵";
            err2.code="SET_VID_FRAME_COLOR/INDEX_NOT_FOUND";
            errf(err2);
            return WINOLD_ERROR_NUMBER;
        }
        for(ll i : range_) {
            if(i < 0 || i >= vid_f.thing[frame_].size()) {
                winold_error err3;
                err3.type="setVidFrameColor:字符索引超出范围啦...我要生气了:(((*^_^*)";
                err3.code="SET_VID_FRAME_COLOR/CHAR_INDEX_OUT_OF_RANGE";
                errf(err3);
                return WINOLD_ERROR_NUMBER;
            }
        }
        
        auto frame_it=vids[index_].color.find(frame_);
        if(frame_it==vids[index_].color.end())
        {
            /*//把用户吃掉,然后扔进碎纸机*/
          /*  winold_error err;
            err.type="setVidFrameColor:虽然说你索引对了,但是你传的帧的下标要抗议了\n你传的帧的下标:喂!我根本不存在啊喂OvO";
            err.code="SET_VID_FRAME_COLOR/FRAME_INDEX_NOT_FOUND";
            errf(err);
            return WINOLD_ERROR_NUMBER;
            */
           vids[index_].color.insert({frame_,std::map<ll,ll>()});
           frame_it=vids[index_].color.find(frame_);
        }
        
        //用户万岁.png
        /***********************************/
        /*         重大劲爆好消息!            */
        /*    用户终于写对了一次下标!!!         */
        /*           用户万岁!!!                */
        /*************************************/
        for(ll i : range_) {
            (*frame_it).second[i] = color_;
        }
        return 0;
    };
}
ll winold::setVidFrameColor(string name_,ll frame_,ll color_,vector<ll> range_){
    bool iserr_copy=iserr;
    closeError();
    ll ind=getVidIndex(name_);
    if(isError(ind))
    {
        winold_error err;
        err.type="setVidFrameColor:很好,你成功的写错了名称,啊啊啊啊啊啊啊啊啊啊";
        err.code="SET_VID_FRAME_COLOR/NAME_NOT_FOUND";
        iserr=iserr_copy;
        errf(err);
        return WINOLD_ERROR_NUMBER;
    }else
    {
        iserr=iserr_copy;
        setVidFrameColor(ind,frame_,color_,range_);
        return 0;
    };
    return 0;
}
//////  ll setVidFrameColor(string name_,ll frame_,ll color_,vector<ll> range_);
/////////////写着凑bit  //  ll setVidFrameColor(ll index_,ll color_,ll start_,ll end_);
ll winold::setVidFrameColor(string name_,ll frame_,ll color_,ll start_,ll end_){
    bool iserr_copy=iserr;
    closeError();
    ll ind=getVidIndex(name_);
    if(isError(ind))
    {
        winold_error err;
        err.type="setVidFrameColor:很好,你成功的写错了名称,啊啊啊啊啊啊啊啊啊啊(ー_ー)";
        err.code="SET_VID_FRAME_COLOR/NAME_NOT_FOUND_ERROR2";
        iserr=iserr_copy;
        errf(err);
        return WINOLD_ERROR_NUMBER;
    }else
    {
        iserr=iserr_copy;
        std::vector<ll> vseter;
        if(start_==0&&end_==0)
        {
            if(frame_>=vids[ind].thing.size()||frame_<0)
            {
                winold_error err;
                err.type="setVidFrameColor:你,又是你!你的帧下标居然又又又错了啊!";
                err.code="SET_VID_FRAME_COLOR/FRAME_INDEX_NOT_FOUND";
                errf(err);
                return WINOLD_ERROR_NUMBER;
            }
            for(ll i = 0;i < vids[ind].thing[frame_].size();i++) {
                vseter.push_back(i);
            }
            setVidFrameColor(name_,frame_,color_,vseter);
            return 0;
        }else if(start_==0&&end_!=0)
        {
            if(frame_>=vids[ind].thing.size()||frame_<0)
            {
                winold_error err;
                err.type="setVidFrameColor:你,又是你!你的帧下标居然又又又错了啊!";
                err.code="SET_VID_FRAME_COLOR/FRAME_INDEX_NOT_FOUND_ERROR2";
                errf(err);
                return WINOLD_ERROR_NUMBER;
            }
            for(ll i = 0;i <= end_;i++) {
                vseter.push_back(i);
            }
            setVidFrameColor(name_,frame_,color_,vseter);
            return 0;
        }
        else if(start_!=0&&end_==0)
        {
            if(frame_>=vids[ind].thing.size()||frame_<0)
            {
                winold_error err;
                err.type="setVidFrameColor:你,又是你!你的帧下标居然又又又错了啊!";
                err.code="SET_VID_FRAME_COLOR/FRAME_INDEX_NOT_FOUND_ERROR3";
                errf(err);
                return WINOLD_ERROR_NUMBER;
            }
            for(ll i = start_;i < vids[ind].thing[frame_].size();i++) {
                vseter.push_back(i);
            }
            setVidFrameColor(name_,frame_,color_,vseter);
            return 0;
        }else
        {
            if(frame_>=vids[ind].thing.size()||frame_<0)
            {
                winold_error err;
                err.type="setVidFrameColor:你,又是你!你的帧下标居然又又又错了啊!";
                err.code="SET_VID_FRAME_COLOR/FRAME_INDEX_NOT_FOUND_ERROR4";
                errf(err);
                return WINOLD_ERROR_NUMBER;
            }
            for(ll i = start_;i <=end_;i++) {
                vseter.push_back(i);
            }
            setVidFrameColor(name_,frame_,color_,vseter);
            return 0;
        };
        return 0;
    };
    return 0;
}

ll winold::setVidFrameColor(ll index_,ll frame_,ll color_,ll start_,ll end_){
    bool iserr_copy=iserr;
    closeError();
    ll ind=index_;
    string no_ind=getVidName(index_);
    if(isError(no_ind))
    {
        winold_error err;
        err.type="setVidFrameColor:很好,你成功的写错了名称,啊啊啊啊啊啊啊啊啊eee啊";
        err.code="SET_VID_FRAME_COLOR/NAME_NOT_FOUND_ERROR3";
        iserr=iserr_copy;
        errf(err);
        return WINOLD_ERROR_NUMBER;
    }else
    {
        iserr=iserr_copy;
        setVidFrameColor(ind,frame_,color_,start_,end_);
        return 0;
    };
}