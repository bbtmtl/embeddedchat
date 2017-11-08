#include <stdio.h>

struct AGIRL {
    int age;
    char name[20];
} fbb = 
{
    20,
    "Fan Bing Bing",
};

struct AGIRL* initFunc()
{
    struct AGIRL* beauty_addr;
    printf("[%d] beauty_addr = %p\n", __LINE__,  &beauty_addr);
    printf("[%d]*beauty_addr = %p\n", __LINE__,   beauty_addr);

    beauty_addr =(struct AGIRL*) malloc(sizeof(struct AGIRL)); 
    printf("[%d] beauty_addr = %p\n", __LINE__,  &beauty_addr);
    printf("[%d]*beauty_addr = %p\n", __LINE__,   beauty_addr);
  
//  (*beauty_addr)->age = 18;
//  (*beauty_addr)->name[0] = 'Z';
//  (*beauty_addr)->name[19] = NULL;

//  **beauty_addr = fbb; 
    return beauty_addr; 
};

void free_agirl(struct AGIRL** agirl_addr)
{
    if(*agirl_addr != NULL)
    {
        printf("[%d]*agirl_addr = %p\n", __LINE__, *agirl_addr);
        free(*agirl_addr);
    }
    printf("file = %s, line = %d\n", __FILE__, __LINE__);
    printf("[%d]*agirl_addr = %p\n", __LINE__, *agirl_addr);

    *agirl_addr = NULL;
    printf("[%d]*agirl_addr = %p\n", __LINE__, *agirl_addr);

}
void get_girl_name(char* name, struct AGIRL* girl)
{
    if(NULL != girl)
        strcpy(name, girl->name);
}
int main()
{
    char * girlName1;
    char * girlName2;
    struct AGIRL* beauty = NULL;
    struct AGIRL* normal = NULL;
                  
    printf("[%d]&beauty = %p\n", __LINE__, &beauty);
    printf("[%d] beauty = %p\n", __LINE__,  beauty);

    if (beauty == NULL)
        beauty = initFunc();

    if (normal == NULL)
        normal = initFunc();

    *beauty = fbb; 
    normal->age = 18;
    normal->name = "Zhang bingbing";

    printf("[%d]&beauty = %p\n", __LINE__, &beauty);
    printf("[%d] beauty = %p\n", __LINE__,  beauty);

    printf("[%d]&normal = %p\n", __LINE__, &normal);
    printf("[%d] normal = %p\n", __LINE__,  normal);


    printf("[%d] beauty age = %d\n", __LINE__,  beauty->age);
    printf("[%d] beauty name = %s\n", __LINE__,  beauty->name);
    get_girl_name(girlName1,beauty);
    get_girl_name(girlName2,normal);


    printf("[%d] beauty name = %s\n", __LINE__,  girlName1);
    printf("[%d] normal name = %s\n", __LINE__,  girlName2);

    free_agirl(&beauty);
    free_agirl(&normal);

    return 0;
}
