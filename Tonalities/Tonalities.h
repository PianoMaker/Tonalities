#pragma once
#include <iostream>
using namespace std;

//Ноти
enum NOTES1 { DO, RE, MI, FA, SOL, LA, SI };


int addpitch(int pitch1, int pitch2);
int addstep(int step1, int step2);
int key_to_step(string key, int notation);
int key_to_pitch(string key, int notation);
int keysign(int step, int alter, bool minor);
string key_to_notename(string key, int notation);
string note_to_key(int step, int pitch);
int pitch_to_alter(int step, int pitch);
string Enter(bool &mistake, string msg, int notation);
bool Trigger(string text);

//Тональність
class Tonalities
{
private:
    
    string name; // cdur, amoll etc.
    string key; // знаки біля ключа
    string mode; // лад
    string ukrname; // ім'яукраїнською
    int keysignatures; // key signatures, + sharps, - flats 
    int step; // key note, c=0, d=1 etc.
    int pitch; // key pitch, c = 0, cis = 1 etc.
    int alteration; //# = 1, b = -1,
    bool minor; // true if minor.
public:
    Tonalities(string name, int notation);
    bool relative(Tonalities destination);
    bool equal(Tonalities destination);
    void enharmonize();
    void transport(int model);
    void recount();
    void Show();
    void ShowName();
    void ShowRelatives();
    void ShowInBrackets();
};

