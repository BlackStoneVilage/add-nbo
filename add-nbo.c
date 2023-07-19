#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>


uint32_t scan_number(char *title_file){
	FILE *file =fopen(title_file,"rb");
	if (file == NULL){
		printf("fail");
	}


	uint32_t num;
	size_t output = fread(&num, sizeof(num), 1, file);
	if(output!=1) {
		printf("error");
		return 0;
	}

	fclose(file);

	return ntohl(num);
}

int main(int argc, char *argv[]) {
	if(argc !=3) {
		printf("Syntax error: add-nbo <file1> <file2>\n");
		return 1;
	}


	uint32_t num1 = scan_number(argv[1]);
	uint32_t num2 = scan_number(argv[2]);
	uint32_t sum = num1 + num2;


	printf("%u(0x%x + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);
	
	
	char name[] = "김준섭";
	printf("[bob12]add-nbo[%s]", name);
	
	
	return 0;
}

