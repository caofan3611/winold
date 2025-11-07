#include<vector>
#include <iostream>
#include <cstdlib>
using namespace std;
#include "winold_define.h"
#define ll long long

class winold {
public:
typedef vector<string> atype;
ll getMapIndex(string s);
    ll getPicIndex(string s);
       
atype nulla;
    ll replaceMap(string s,vector<string> v);
    ll replaceMap(long long l,vector<string> v);
    ll replacePic(string s,vector<string> v);
    ll replacePic(ll l,vector<string> v);
    winold() {
        debug("winold创建");
        if(winold_one==true) {
            winold_one=false;
        } else
        {
            winold_error err;
            err.type="winold:不能创建两个winold啦!（｀へ´）";
            errf(err,true);
        };


    };
    winold(const winold&)=delete;
    void setTitle(string t);
    ll newPic(string n);
    
    bool isError(ll s);
    bool isError(string s);
    ll newPic(string n,vector<string> v);
    string getPicName(ll n);
    void setOutColor(ll c);
    ~winold() {debug("winold销毁");
        winold_one=true;
        };
    void openError();
    void closeError();
    ll newMap(string n);
    ll newMap(string n,vector<string> v);
    string getMapName(ll n);
private:
    class winold_map {
    public:
        winold_map() {};
        winold_map(string n,vector<string> vs):name(n),v(vs) {};
        string name;
        vector<string> v;
    };
    vector<winold_map> maps;
    class winold_error {
    public:
        string type;
    };
    static bool winold_one;
    static bool iserr;
    static void errf(winold_error e,bool b=iserr);
    class winold_pen {
    public:
        winold_pen() {};
        ~winold_pen() {};
        long long color;
    };
    static winold_pen pen;
    string stmp;
    class winold_pic:public winold_map {
    public:
        winold_pic(string n,vector<string> vs) {
            name=n;
            v=vs;
        };
        winold_pic() {
            if(winold_one==true) {
                winold_one=false;
            } else
            {
                winold_error err;
                err.type="bnnn";
                errf(err,true);
            };


        };
        winold_pic(const winold&)=delete;

    };
    vector<winold_pic> pics;
   static void debug(string s);
    template<typename tt>
    static void debug(string s,tt t);
 
};