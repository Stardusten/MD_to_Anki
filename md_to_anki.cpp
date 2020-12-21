// MD_to_Anki.cpp
// by Stardust 2020.12.21

#include <cstdio>

int main(int argc, char *argv[]) {
    FILE *p_read = fopen(argv[1], "r");
    FILE *p_write = fopen(argv[2], "w");
    char ch;
    for(bool sign = false;;){
        ch = fgetc(p_read);
        if(ch == EOF) break;
        if(ch == '<'){
            ch = fgetc(p_read);
            if(ch == 'c'){
                ch = fgetc(p_read);
                if(ch == '>'){
                    fputc('"', p_write);
                    LABEL: ch = fgetc(p_read);
                    if(ch == '<'){
                        ch = fgetc(p_read);
                        if(ch == 'c'){
                            ch = fgetc(p_read);
                            if(ch == '>'){
                                fputc('"', p_write);
                                fputc(sign?'\n':',', p_write);
                                sign = sign ? false : true;
                                continue;
                            }
                        }
                    }
                    fputc(ch, p_write);
                    goto LABEL;
                }
            }
        }
    }
    return 0;
}
