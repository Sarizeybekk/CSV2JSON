#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	
	if(argc < 4 )
	{
		printf("Parametreler Dogru Degil");
		exit(1);
	}
	
	FILE *csv = fopen(argv[1], "r");
	if(csv == NULL){
		printf("CSV dosyasi acilamadi");
		exit(1);
	}
	
	FILE *json = fopen(argv[2], "w");
	if(json == NULL)
	{
		printf("JSON dosyasi acilamadi");
		exit(1);
	}
	
	bool header = false;
	
	char headerOn[9] = "header=ON";
	char headerOff[10] = "header=OFF";
	int i ; 
	for(i = 0 ; argv[3][i] != '\0'; i++){
		if(argv[3][i] == headerOn[i] )
			header = true;
		else if ( argv[3][i] == headerOff[i])
			header = false;
		else{
			printf("Header ON/OFF Degil");
			exit(1);
		}			
	}
	
	bool yaz = !header;
	
	
	int size = 1000000 ;
	
		
	char* satir = (char*)malloc(size*sizeof(char));
	int satirNum = -1;
	int virgulSayisi = 0 ;  
	
	
	fprintf(json,"[\n");
	char** sutunlar = (char**)malloc(size*sizeof(char));
	int index = 0 ;
	bool parantez = true; 
	while(1){
		int c = fgetc(csv);
		if(c == ',' || c == '\n' || c == EOF){
			
			if(c == ',' && header && !yaz){
				sutunlar[index++] = satir;
				satir = (char*)calloc(size,sizeof(char));
				satirNum = -1 ; 
			}else if(c== '\n' && header && !yaz){
				sutunlar[index] = satir;
				satir = (char*)calloc(size,sizeof(char));
				satirNum = -1;
				index = 0 ;
				yaz = 1 ;
			}
			else if(c == ',' && yaz) {
				if(parantez){
					fprintf(json,"   {\n");
					parantez = false;
				}				
				if(header)
					fprintf(json,"       \"%s\":\"%s\",\n",sutunlar[index],satir);
				else
					fprintf(json,"       \"%s\":\"%s\",\n","Column",satir);
				satir = (char*)calloc(size,sizeof(char));
				satirNum = -1;
				index++;
			}else if((c == '\n' || c == EOF) && yaz) {
				if(index==0)
				break;
				if(header)
					fprintf(json,"       \"%s\":\"%s\"\n",sutunlar[index++],satir);
				else{
						fprintf(json,"       \"%s\":\"%s\"\n","Column",satir);
				}
					
				fprintf(json,"   }");
				if(c == '\n'){
					fprintf(json,",\n");
					parantez = true ; 
				}
				else
					fprintf(json,"\n");
				satir = (char*)calloc(size,sizeof(char));
				satirNum = -1;
				index = 0 ; 
				if( c == EOF)
					break;
			}
		}
		else
			*(satir+((++satirNum)*sizeof(char))) = c ; 
	}
	
	fprintf(json,"]");
	fclose(json);
	return 0;
}
