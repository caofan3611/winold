// v1.3.5
/*
Copyright caofan3611 2025
本库采用apache-2.0协议
如果你使用了这个库，并把你的项目发布了出去,无论商用还是开源，
都必须写上原作者姓名caofan3611
感谢你的配合
p.s. apache2.0是有报复权的
          ——caofan3611
        2025.10.29 10:47
*/
#include <cstdlib>
#include <set>
#include <map>
#include <iostream>
#include <vector>
#include <unordered_set>
using std::cout;
using std::endl;
using std::string;
using std::unordered_set;
using std::vector;
#include "winold_define.h"
#define ll unsigned long long

class winold {
public:
  // using namespace std;
  class winold_error {
  public:
    string type;
    string code;
  };
  void clearScreen();
  ll fpsToMicrosecond(ll fpsn);
  ll playVid(string s,ll times=1);
  ll setVidFrameColor(ll index_,ll frame_,ll color_,vector<ll> range_);
  ll setVidFrameColor(string name_,ll frame_,ll color_,vector<ll> range_);
  //  ll setVidFrameColor(ll index_,ll color_,ll start_,ll end_);
  ll playVid(ll l,ll times=1);
  string getVidName(ll n);
  ll getVidIndex(string s);
   ll setVidSleep(string s,ll l);
   ll removeVid(string s);
   void clearVid();
   ll removeVid(ll l);
   typedef vector<string> vidtype;
   ll setVidSleep(ll i,ll l);
   static vidtype nullvid;
  unordered_set<string> maps_table,pics_table,vids_table;
  ll replaceVid(string name_, ll sleepn_=0, vidtype thing_ = nullvid);
  ll replaceVid(string name_, vidtype thing_);
 
  ll getMapIndex(string s);
  ll getPicIndex(string s);
  void resetOutColor();
  void clearMap();
  ll showPic(string s, bool isln = false);
  ll showPic(ll l, bool isln = false);
  void clearPic();
 
  ll createVid(string name_, ll sleepn_, vidtype thing_ = nullvid);
  ll createVid(string name_, vidtype thing_);
  ll createVid(string name_);
  ll removeMap(string s);
  ll removeMap(ll l);
  ll removePic(string s);
  ll removePic(ll l);
  ll replaceMap(string s, string v);
  ll replaceMap(long long l, string v);
  ll replacePic(string s, string v);
  ll replacePic(ll l, string v);
  winold() {
    //    debug("winold创建");
    if (winold_one == true) {
      winold_one = false;
    } else {
      winold_error err;
      err.type = "winold:不能创建两个winold啦!（｀へ´）";
      errf(err, true);
    };
  };
  winold(const winold &) = delete;
  void setTitle(string t);
  ll createPic(string n);

  bool isError(ll s);
  bool isError(string s);
  ll createPic(string n, string v);
  string getPicName(ll n);
  void setOutColor(ll c);
  ~winold() { // debug("winold销毁");
    winold_one = true;
  };
  void openError();
  void closeError();
  ll createMap(string n);
  ll createMap(string n, string v);
  string getMapName(ll n);

private:
  template <class type> ll root_remove_(type &ts, string s,string n);
  class winold_map {
  public:
    winold_map() {};
    winold_map(string n, string vs) : name(n), thing(vs) {};
    string name;
    string thing;
  };
  vector<winold_map> maps;
  static bool winold_one;
  static bool iserr;
  static void errf(winold_error e, bool b = iserr);

  string stmp;
  class winold_pic : public winold_map {
  public:
    winold_pic(string n, string vs) {
      name = n;
      thing = vs;
    };
    winold_pic() {
      /* if(winold_one==true) {
           winold_one=false;
       } else
       {
           winold_error err;
           err.type="bnnn";
           errf(err,true);
       };


   };
   winold_pic(const winold&)=delete;
*/
    }
  };
  vector<winold_pic> pics;
  static void debug(string s);
  class winold_vid{
public:
string name;
ll sleepn;
vidtype thing;
std::map<ll,std::map<ll,ll> > color;
  };
vector<winold_vid> vids;
  template <typename tt> static void debug(string s, tt t);
};
