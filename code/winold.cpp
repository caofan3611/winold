#include <iostream>
using namespace std;
#include <vector>
#include "winold.h"
#include "winold_define.h"
winold::winold_pen winold::pen;
void winold::errf(winold_error e,bool b) {
if(b){
    cout <<"winold发生错误!\nwinold:"<<e.type<<"\n程序异常终止"<< endl;
    exit(1);
    }
}
ll winold::newMap(string n) {
    winold_error err;
    if(maps.empty())
    {
        cout << "";
    } else
    {
        for(auto i:maps) {
            if(i.name==n)
            {

                err.type="newMap:名称重复了,嗯嗯嗯,你这个坏孩子!搞得人家好无语呀(\"▔□▔)";
                         errf(err);
                return -1;
            }

        }
    };
    vector<string> vvv;

    maps.push_back(winold_map(n,vvv));
    return maps.size()-1;
}
ll winold::newMap(string n,vector<string> v){
    winold_error err;
    if(maps.empty())
    {
        cout << "";
    } else
    {
        for(auto i:maps) {
            if(i.name==n)
            {

                err.type="newMap:名称重复了,这样子我会分不清地图的呀!(\"▔□▔)";
                         errf(err);
                return -1;
            }

        }
    };
    

    maps.push_back(winold_map(n,v));
    return maps.size()-1;
}
string winold::getMapName(ll n){
    winold_error err;
    if(maps.empty()==true)
    {
        err.type="getMapName:没有添加地图,哪来的获取名字?再欺骗人家，人家要伤心了(′へ`、 )";
        errf(err);
        return " ";
    }
    else
    {
        if(n>maps.size()-1){
            if(n<0)
            {
                err.type="getName:为什么下标是负数???你为什么背叛了我!ヽ(‘⌒´メ)ノ";
                errf(err);
            }
            err.type="getName:这该死的下标!!!为什么就是超出了正常下标的范围呢?你为什么不改改?唉，可怜的下标居然超出了最高下标范围(ー_ー)!!";
            errf(err);
            
        }else if(n<0)
        {
            err.type="getName:为什么,究竟是为什么!!!不要把下标写成负数!!!...( ＿ ＿)ノ｜";
            errf(err);
        }
        else
        {
            return maps[n].name;
        };
    };
}
bool winold::winold_one=true;
bool winold::iserr=true;

void winold::openError(){
    iserr=true;
}
void winold::closeError(){
    iserr=false;
}

void winold::setOutColor(ll c){
              winold::pen.color=c;
              stmp="\033["+to_string(c)+"m";
              cout <<stmp;
          }
          ll winold::newPic(string n) {
    winold_error err;
    if(pics.empty())
    {
        cout << "";
    } else
    {
        for(auto i:pics) {
            if(i.name==n)
            {

                err.type="newMap:名称重复了,嗯嗯嗯,你这个坏孩子!搞得人家好无语呀(\"▔□▔)";
                         errf(err);
                return -1;
            }

        }
    };
    vector<string> vvv;

    pics.push_back(winold_pic(n,vvv));
    return pics.size()-1;
}
ll winold::newPic(string n,vector<string> v){
    winold_error err;
    if(pics.empty())
    {
        cout << "";
    } else
    {
        for(auto i:pics) {
            if(i.name==n)
            {

                err.type="newPic:名称重复了,这样子我会分不清地图的呀!(\"▔□▔)";
                         errf(err);
                return -1;
            }

        }
    };
    

    pics.push_back(winold_pic(n,v));
    return pics.size()-1;
}
string winold::getPicName(ll n){
    winold_error err;
    if(pics.empty()==true)
    {
        err.type="getPicName:我图呢???一个也没有!人家要伤心了(′へ`、 )";
        errf(err);
        return " ";
    }
    else
    {
        if(n>pics.size()-1){
            if(n<0)
            {
                err.type="getPicName:为什么下标是负数???你为什么背叛了我!ヽ(‘⌒´メ)ノ";
                errf(err);
            }
            err.type="getPicName:这该死的下标!!!为什么就是超出了正常下标的范围呢?你为什么不改改?唉，可怜的下标居然超出了最高下标范围(ー_ー)!!";
            errf(err);
            
        }else if(n<0)
        {
            err.type="getPicName:为什么,究竟是为什么!!!不要把下标写成负数!!!...( ＿ ＿)ノ｜";
            errf(err);
        }
        else
        {
            return pics[n].name;
        };
    };
}
void winold::setTitle(string t){
    string s="\033]2;"+t+"\007";
    cout << s;
}
bool winold::replaceMap(string s,vector<string> v){
    winold_error err;
    if(maps.empty()){
        err.type="replaceMap:不!!!地图明明是空的!～(TロT)σ";
        errf(err);
        return false;
    }else
    {
        for(ll i=0;i < maps.size()-1;i++){
            if(maps[i].name==s)
            {
                maps[i].v=v;
                return true;
            }
        }
        err.type="replaceMap:are you ok???!!! 没有这个地图!";
        errf(err);
        return false;
    };
}
bool winold::replaceMap(long long l,vector<string> v){
    closeError();
    winold_error err;
    auto i=getMapName(l);
    if(i==" ")
    {
        err.type="replaceMap:根本就没有这个下标嘛(* ￣︿￣)";
        errf(err);
        return false;
    }
    else
    {
        replaceMap(i,v);
    };
    openError();
    return true;
}
         