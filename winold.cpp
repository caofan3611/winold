#include <iostream>
using namespace std;
#include <vector>
#include "winold.h"
#include "winold_define.h"
winold::winold_pen winold::pen;

    bool winold::isError(string s){
        debug("进入isError(string s)");
        debug("s:",s);
        debug("结果是:",s==WINOLD_ERROR_STRING);
        
       return s==WINOLD_ERROR_STRING;
    }
    bool winold::isError(ll s){
        debug("进入isError(ll s)");
        debug("s:",s);
        debug("结果是:",s==WINOLD_ERROR_NUMBER);
     
       return s==WINOLD_ERROR_NUMBER;
    }
    
void winold::errf(winold_error e,bool b) {
    debug("start:errf(winold_error e,bool b)");
if(b){
    debug("发生错误");
    cout <<"winold发生错误!\nwinold:"<<e.type<<"\n程序异常终止"<< endl;
    
    exit(1);
    }
    debug("end");
}
ll winold::newMap(string n) {
    debug("start newMap(string n)");
    debug("n:",n);
    winold_error err;
    if(maps.empty())
    {
        debug("maps空空空空空空空");
        cout << "";
    } else
    {
        for(auto i:maps) {
            if(i.name==n)
            {
       debug("名称重复!");
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
    debug("进入getMapName(ll n)");
    debug("n:",n);
    winold_error err;
    if(maps.empty()==true)
    {
        debug("空的");
        err.type="getMapName:没有添加地图,哪来的获取名字?再欺骗人家，人家要伤心了(′へ`、 )";
        errf(err);
        return WINOLD_ERROR_STRING;
    }
    else
    {
        if(n>maps.size()-1){
            if(n<0)
            {
                debug("index是负数");
                err.type="getName:为什么下标是负数???你为什么背叛了我!ヽ(‘⌒´メ)ノ";
                errf(err);
                return WINOLD_ERROR_STRING;
            }
            err.type="getName:这该死的下标!!!为什么就是超出了正常下标的范围呢?你为什么不改改?唉，可怜的下标居然超出了最高下标范围(ー_ー)!!";
            errf(err);
            return WINOLD_ERROR_STRING;
            
        }else if(n<0)
        {
            
            err.type="getName:为什么,究竟是为什么!!!不要把下标写成负数!!!...( ＿ ＿)ノ｜";
            errf(err);
            return WINOLD_ERROR_STRING;
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
        return WINOLD_ERROR_STRING;
    }
    else
    {
        if(n>pics.size()-1){
            if(n<0)
            {
                err.type="getPicName:为什么下标是负数???你为什么背叛了我!ヽ(‘⌒´メ)ノ";
                errf(err);
                return WINOLD_ERROR_STRING;
            }
            err.type="getPicName:这该死的下标!!!为什么就是超出了正常下标的范围呢?你为什么不改改?唉，可怜的下标居然超出了最高下标范围(ー_ー)!!";
            errf(err);
            return WINOLD_ERROR_STRING;
        }else if(n<0)
        {
            err.type="getPicName:为什么,究竟是为什么!!!不要把下标写成负数!!!...( ＿ ＿)ノ｜";
            errf(err);
            return WINOLD_ERROR_STRING;
        }
        else
        {
            return pics[n].name;
        };
    };
    return WINOLD_ERROR_STRING;
}
void winold::setTitle(string t){
    string s="\033]2;"+t+"\007";
    cout << s;
}
ll winold::replaceMap(string s,vector<string> v){
    winold_error err;
    if(maps.empty()){
        err.type="replaceMap:不!!!地图明明是空的!～(TロT)σ";
        errf(err);
        return WINOLD_ERROR_NUMBER;
    }else
    {
        for(ll i=0;i < maps.size();i++){
            if(maps[i].name==s)
            {
                maps[i].v=v;
                return WINOLD_ERROR_NUMBER;
            }
        }
        err.type="replaceMap:are you ok!!! 没有这个地图!";
        errf(err);
        return WINOLD_ERROR_NUMBER;
    };
}
ll winold::replacePic(string s,vector<string> v){
    winold_error err;
    if(pics.empty()){
        err.type="replacePic:不!!!pic明明是空的!～(TロT)σ";
        errf(err);
        return WINOLD_ERROR_NUMBER;
    }else
    {
        for(ll i=0;i < pics.size();i++){
            if(pics[i].name==s)
            {
                pics[i].v=v;
                return WINOLD_ERROR_NUMBER;
            }
        }
        err.type="replaceMap:are you ok⊙_⊙ 没有这个pic!";
        errf(err);
        return WINOLD_ERROR_NUMBER;
    };
}
ll winold::replaceMap(long long l,vector<string> v){
    debug("进入replaceMap(long long l,vector<string> v)");
    debug("l:",l);
    closeError();
    debug("已关闭错误");
    winold_error err;
    debug("即将调用get map name");
    auto i=getMapName(l);
    if(i==WINOLD_ERROR_STRING)
    {
        debug(" Get map name出现问题");
        openError();
        err.type="replaceMap:根本就没有这个下标嘛(* ￣︿￣)";
        errf(err);
        return WINOLD_ERROR_NUMBER;
    }
    else
    {
        debug(" Get map name没有问题");
        replaceMap(i,v);
    };
    openError();
    return WINOLD_ERROR_NUMBER;
}
ll winold::replacePic(long long l,vector<string> v){
    closeError();
    winold_error err;
    auto i=getPicName(l);
    if(isError(i))
    {
        openError();
        err.type="replacePic:根本就没有这个下标嘛(* ￣︿￣)";
        errf(err);
        return WINOLD_ERROR_NUMBER;
    }
    else
    {
        replacePic(i,v);
    };
    openError();
    return WINOLD_ERROR_NUMBER;
}
    void winold::debug(string s){
        
    }
       template<typename tt>
        void winold::debug(string s,tt t){
            
        }
        ll winold::getMapIndex(string s){
            winold_error e;
            if(maps.empty()){
                e.type="getMapIndex:地图。。。。是空的。。。";
                errf(e);
                return WINOLD_ERROR_NUMBER;
            }else
            {
                
                for(int i = 0;i < maps.size();i++) {
                    if(maps[i].name==s){
                        return i;
                    }
                }
                e.type="getMapIndex:呃,好像没有这玩意儿,你传进来的名称有误:)";
                errf(e);
                return WINOLD_ERROR_NUMBER;
            };
            e.type="getMapIndex:这...这是个未知的错误啊...";
            errf(e);
            return WINOLD_ERROR_NUMBER;
        }
                ll winold::getPicIndex(string s){
            winold_error e;
            if(pics.empty()){
                e.type="getMapIndex:地图。。。。是空的。。。";
                errf(e);
                return WINOLD_ERROR_NUMBER;
            }else
            {
                
                for(int i = 0;i < pics.size();i++) {
                    if(pics[i].name==s){
                        return i;
                    }
                }
                e.type="getMapIndex:呃,好像没有这玩意儿,你传进来的名称有误:)";
                errf(e);
                return WINOLD_ERROR_NUMBER;
            };
            e.type="getMapIndex:这...这是个未知的错误啊...";
            errf(e);
            return WINOLD_ERROR_NUMBER;
        }
        template<class type>
            ll winold::root_remove_(type ts,string s){
	    if(ts.empty()){
	    return WINOLD_ERROR_NUMBER;
	    }
	    for(auto i=ts.begin();i!=ts.end();i++){
	    if(i->name==s){
	    ts.erase(i);
	    return 0;
	    }
	    }
	    return WINOLD_ERROR_NUMBER;
	    }
            
ll winold::removeMap(string s){
if(root_remove_(maps,s)==WINOLD_ERROR_NUMBER){
winold_error e;
e.type="removeMap:可是...没有没有没有没有。。。没有这个元素...";
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

ll winold::removeMap(ll l){
  return removeMap(getMapName(l));
}

ll winold::removePic(string s){
	if(root_remove_(pics,s)==WINOLD_ERROR_NUMBER){
		winold_error e;
		e.type="removeMap:可是...没有没有没有没有。。。没有这个元素...";  errf(e);
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

ll winold::removePic(ll l){
	  return removeMap(getPicName(l));
}









