#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <unordered_map>

using namespace std;

void help();

int main(int argc, char *argv[])
{
    vector<string> targetlists;   //all wordlists

    unordered_map <string,bool> targetlist;   //all wordlists combined

    char guess[256];
    unsigned long long guessc=0;
    unsigned long long correct = 0;
    int step = 1000;
    unsigned long maxGuessc = 500000000;
    int i;
        //-- parse args --//
        if (argc < 2) {
            help();
            return 0;
        }

        for(i=0;i<argc;++i)
        {
            std::string arg=argv[i];

            if(arg=="-t" || arg=="--target")
            {
                targetlists.push_back(argv[++i]);
            }
            else if(arg=="-s" || arg=="--step")
            {
                step=atoi(argv[++i]);
            }
            else if(arg=="-m" || arg=="--max")
            {
                maxGuessc=atol(argv[++i]);
            }
        }

            std::clog << "Parsing Target:\n\n";
            //--read files--//
                for (std::string wordfile : targetlists) {
                    std::clog << "Parsing " << wordfile.c_str() << "...\n";
                    //cout << wordlist;
                    std::ifstream file{wordfile};
                    std::string str;
                    if (file.is_open()) {
                        while (std::getline(file, str)) {
                            if (str != "") {
                                targetlist.insert({str,false});
                            }
                        }
                    }
                    else {
                        std::clog << "Error: Can't open" << wordfile.c_str() << "!\n";
                    }
                }

               while(scanf(" %s", &guess[0])==1)
               {
                   ++guessc;
                   unordered_map<string,bool>::const_iterator got = targetlist.find (guess);

                   if(got != targetlist.end())
                   {
                       targetlist[guess]=true;
                       ++correct;
                       if(guessc%step==0)
                       {
                           printf("%llu\t\t%llu\n", correct, guessc);
                       }
                   }
                   if(guessc>=maxGuessc)
                   {
                       printf("%llu\t\t%llu\n", correct, guessc);
                       exit(0);
                   }
               }



    return 0;
}

void help()
{

}
