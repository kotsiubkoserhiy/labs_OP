//
// Created by mac user on 09.03.2023.
//

#include "transformFiles.h"
#include "workTheFiles.h"

using namespace std;
//--------calcFile--------
void calcandAddFile(char path[]){
    FILE *inFile;
    if ((inFile = fopen(path, "r"))==NULL){
        cout<<"Cannot open file" << endl;
        exit(0);
    }

    int num = 1;
    int maxline = 0, maxpos;
    char temp[81];
    while((fgets(temp,80,inFile))!=NULL)
    {
        if (strlen(temp)>maxline){
            maxline = strlen(temp);
            maxpos = num;
        }
        num++;
    }
    fclose(inFile);
    addFile(path, maxline, maxpos);
}

void calcandAddFile(string path){
    fstream inFile(path, ios::in);
    if (!inFile){
        cout<<"Cannot open file" << endl;
        exit(0);
    }

    int num = 1;
    int maxline = 0, maxpos =0;
    char temp[81];
    string line;
    while(!inFile.eof())
    {
        getline(inFile,line);
        if (line.length()>maxline){
            maxline = line.length();
            maxpos = num;
        }
        num++;
    }
    inFile.close();
    addFile(path, maxline, maxpos);
}

//--------conversionFile--------
void conversionFile(char path[])
{
    FILE *inFile;
    if ((inFile = fopen(path, "r"))==NULL){
        cout<<"Cannot open file" << endl;
        exit(0);
    }

    char temp[81];   // рядок, який прочитуємо з файла
    char *tofile = new char();
    int num = 1;
    while((fgets(temp,81,inFile))!=NULL)
    {
        int i =0;
        char ts[161]=""; int pos = 0; //
        while (i<strlen(temp)){
            if (isalpha(temp[i])){
                char word[81]=""; int pw = 0;
                while(isalpha(temp[i])) { word[pw] = temp[i]; pw++; i++; }
                if (num%2==0){
                    if (strlen(word)>1 && toupper(word[0])==toupper(word[pw-1])) {
                        strcat(ts,word);
                        strcat(strcat(ts," "),word); pos +=strlen(word)*2+1;
                    }
                    else{
                        strcat(ts,word); pos +=strlen(word);
                    }
                }
                else{
                    if (!isupper(word[0]) || strlen(word)==1){
                        strcat(ts,word); pos +=strlen(word);
                    }
                }

            }
            else{
                ts[pos] = temp[i];
                pos++; i++;
            }
        }
        num++;
        strcat(tofile, ts);
    }
    fclose (inFile);
    writeFile(path, tofile);

}

void conversionFile(string path){
    fstream inFile(path, ios::in);

    if (!inFile){
        cout<<"Cannot open file" << endl;
        exit(0);
    }

    string line, temp, tofile;
    int num = 1;
    while (!inFile.eof()){
        getline(inFile,line);
        temp = line + " ";
        string s = " ,.!;:?-";
        if (num%2!=0){
            int pos = temp.find_first_not_of(s), endpos;
            while(!(pos == string::npos)){
                if (isupper(temp[pos])){
                    endpos = temp.find_first_of(s,pos+1);
                    temp.erase(pos,endpos-pos);
                }
                pos = temp.find_first_not_of(s,pos+1);
            }
        }
        else{
            int pos = temp.find_first_not_of(s), endpos;
            while(!(pos == string::npos)){
                if (isalpha(temp[pos])){
                    endpos = temp.find_first_of(s,pos+1);
                    if (toupper(temp[pos]) == toupper(temp[endpos-1])){
                        temp.insert(endpos," "+temp.substr(pos,endpos-pos));
                        endpos += (endpos-pos);
                    }
                }
                pos = temp.find_first_not_of(s,endpos+1);
            }
        }

        num++;
        tofile += temp+'\n';
    }
    inFile.close();
    writeFile(path, tofile);
}
