#include <stdio.h>

struct AGIRL {
	int age;
	char name[20];
} fbb = 
{
	20,
	"Fan Bing Bing",
};

void initFunc(struct AGIRL** beauty_addr)
{
	printf("[%d] beauty_addr = %p\n", __LINE__,  beauty_addr);
  printf("[%d]*beauty_addr = %p\n", __LINE__, *beauty_addr);

	*beauty_addr =(struct AGIRL*) malloc(sizeof(struct AGIRL)); 
	printf("[%d] beauty_addr = %p\n", __LINE__,  beauty_addr);
  printf("[%d]*beauty_addr = %p\n", __LINE__, *beauty_addr);
  
//  (*beauty_addr)->age = 18;
//  (*beauty_addr)->name[0] = 'Z';
//  (*beauty_addr)->name[19] = NULL;
  
//	**beauty_addr = fbb; 
	return;	
};

int main(){

struct AGIRL* beauty = NULL;
struct AGIRL* normal = NULL;

printf("[%d]&beauty = %p\n", __LINE__, &beauty);
printf("[%d] beauty = %p\n", __LINE__,  beauty);

if (beauty == NULL)
  	initFunc(&beauty);

if (normal == NULL)
  	initFunc(&normal);

	*beauty = fbb; 
	*normal = fbb; 

printf("[%d]&beauty = %p\n", __LINE__, &beauty);
printf("[%d] beauty = %p\n", __LINE__,  beauty);

printf("[%d]&normal = %p\n", __LINE__, &normal);
printf("[%d] normal = %p\n", __LINE__,  normal);


printf("[%d] beauty.age = %d\n", __LINE__,  beauty->age);
printf("[%d] beauty.name = %s\n", __LINE__,  beauty->name);

return 0;
}
