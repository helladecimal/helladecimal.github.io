#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    FILE *test;
    char buffer[256];

    struct Identifier {
        char* md; // Markdown identifier
        char* htmlStart; // Html starting element
        char* htmlEnd; // Html closing element
        bool mdSpans; // Does the identifier span the text?
    };

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

    while (fgets(buffer, 256, test)){
        for (int i=0; i<( sizeof(list) / sizeof(list[1]) ); i++){
            
        }
        printf("%s", buffer);
    }
    fclose(test);
}