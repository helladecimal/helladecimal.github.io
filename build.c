#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Identifier {
    char* md; // Markdown identifier
    char* htmlStart; // Html starting element
    char* htmlEnd; // Html closing element
    bool mdSpans; // Does the identifier span the text?
};

void get_buffer_from_ident(struct Identifier* id, char* buffer);

int main(void)
{
    FILE *test;
    char buffer[256];

        struct Identifier list[] = {
        {"# ", "<h1>", "</h1>", false},
        {"## ", "<h2>", "</h2>", false},
        {"### ", "<h3>", "</h3>", false},
        {"`", "<span class=\"code\">", "</span>", true},
        //{"```", "<div class=\"code\">", "</div>", true},
        //{">", }
        //{"-"}
        //{"1."}
        //{links}
        //{images}
        {"*", "<i>", "</i>", true},
        {"**", "<b>", "</b>", true},
        {"***", "<b><i>", "</i></b>", true},
        {"---", "<hr>", "", false}
    };

    char *delims = "# ## ### ` * ** ***";

    test = fopen("blog/md/test.md", "r");

    char testbuff[10];

    while (fgets(buffer, 256, test)){
        for (int i=0; i<( sizeof(list) / sizeof(list[1]) ); i++){
            get_buffer_from_ident(&list[i], buffer);
        }
        //printf("%s", buffer);
    }
    fclose(test);
    return 0;
}

void get_buffer_from_ident(struct Identifier* id, char* buffer){
    //printf("%s\n", buffer);
    char new[256];

    int i = 0;
    int b = 0;
    while (buffer[i] != '\0'){ 
        int md_len = strlen(id->md);
        bool matches = true;

        for (int ii=0; ii<md_len; ii++){
            if (id->md[ii] != buffer[ii]) {matches = false;}
        }


        if (matches == true && i > md_len-1){
            new[b] = buffer[i];
            new[b+1] = '\0';
            b++;
        }
        i++;
    }

    printf("%s : %s\n", id->md, new);
}
