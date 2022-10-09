#include "MyText.h"
#include <iostream>

int strlen(const char *data) {
    if (data == NULL)
        return 0;

    int i = 0;
    for (; *(data + i) != '\0'; i++)
        ;
    return i;
}

void copyStrTo(int count, const char *source, int from, char *target) { 
    for (int i = 0; i < count; i++)
        *(target + from + i) = *(source + i);
}

char *copyStr(const char* source) {
    int len = strlen(source);
    char *result = new char[len + 1]();

    if (source != NULL)
        copyStrTo(len + 1, source, 0, result);

    return result;
}

int up2low_low2up(int src) { 
    return src >= 'a' ? std::toupper(src) : std::tolower(src);
}

MyText *initMyText(const char *name, MyText *sourceTxt) { 
    MyText *createdTxt = new MyText;

    if (sourceTxt == NULL) { 
        createdTxt->data = copyStr(NULL);
    }   
    else {
        createdTxt->data = copyStr(sourceTxt->data);
    }

    createdTxt->name = copyStr(name);

    return createdTxt;
}

bool empty(MyText *txt) {
    return strlen(txt->data) == 0;
}

char *getStr(MyText *txt) { 
    if (txt == NULL)
        return NULL;

    return txt->data;
}

MyText *append(MyText *txt, const char *data) { 
    if (txt == NULL)
        return NULL;

    int len1 = strlen(txt->data);
    int len2 = strlen(data);
    int len = len1 + len2;

    char *result = new char[len + 1]();

    copyStrTo(len1, txt->data, 0, result);
    copyStrTo(len2 + 1, data, len1, result);

    delete []txt->data;
    txt->data = result;

    return txt;
}

void print(MyText *txt) { 
    std::cout << txt->name << " = \"" << txt->data << "\"" <<std::endl;
}

int size(MyText *txt) { 
    return strlen(txt->data);
}

void setChar(MyText *txt, int pos, char value) { 
    if (txt == NULL)
        return;

    *(txt->data + pos) = value;
}

void erase(MyText *txt, int from, int to) { 
    if (txt == NULL)
        return;

    int sourceLen = strlen(txt->data);

    char *result = new char[sourceLen - (to - from) + 1];
    
    copyStrTo(from, txt->data, 0, result);
    copyStrTo(sourceLen - to + 1, txt->data + to, from, result);

    delete []txt->data;
    txt->data = result;
}

void insert(MyText *txt, int from, const char *data) { 
    if (txt == NULL)
        return;

    int oldLen = strlen(txt->data);
    int dataLen = strlen(data);

    char *result = new char[oldLen + dataLen + 1]();

    copyStrTo(from, txt->data, 0, result);
    copyStrTo(dataLen, data, from, result);
    copyStrTo(oldLen - from + 1, txt->data + from, from + dataLen, result);

    delete []txt->data;
    txt->data = result;
}

void modify(MyText *txt, int fun(int source)) { 
    if (txt == NULL)
        return;

    int len = strlen(txt->data);

    for(int i = 0; i < len; i++)
        *(txt->data + i) = fun(*(txt->data + i));
}

void clear(MyText *txt) { 
    if (txt == NULL)
        return;

    if (txt->data != NULL) { 
        delete []txt->data;
        txt->data = NULL;
    }

    if (txt->name != NULL) { 
        delete []txt->name;
        txt->name = NULL;
    }
}