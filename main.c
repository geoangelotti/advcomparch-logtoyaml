#include <stdio.h>
#include <string.h>

#define BUFF_S 512

int main(int argc, char **argv) {

	FILE * infile;
	FILE * outfile;
    size_t lines = 1;
	char buffer[BUFF_S];
	char s_element[32];
	char outname[32];

	if (argc != 2) {
		printf("Usage logtoyaml <in>\n");
		return 0;
	}

	infile = fopen(argv[1], "r");
	if (infile == NULL) {
		printf("Can not open <%s> correctly\n", argv[1]);
		return 0;
	}

	strcpy(outname, argv[1]);
	outname[strlen(outname) - 4] = '\0';
	strcat(outname, ".yaml");

	outfile = fopen(outname, "w+");
	if (outfile == NULL) {
		printf("Can not create <%s> correctly\n", outname);
		return 0;
	}

	while((fgets(buffer, sizeof(buffer), infile)) != NULL) {
		switch(lines) {
			case 4:
				sscanf(buffer, "%s %s %s", s_element, s_element, s_element);
				fprintf(outfile, "Total_Instructions: %s\n", s_element);
				break;
			case 5:
				sscanf(buffer, "%s %s %s", s_element, s_element, s_element);
				fprintf(outfile, "Total_Cycles: %s\n", s_element);
				break;
			case 6:
				sscanf(buffer, "%s %s", s_element, s_element);
				fprintf(outfile, "IPC: %s\n", s_element);
				break;
			case 12:
				sscanf(buffer, "%s %s", s_element, s_element);
				fprintf(outfile, "TLBe: %s\n", s_element);
				break;
			case 13:
				sscanf(buffer, "%s %s %s", s_element, s_element, s_element);
				fprintf(outfile, "TLBp: %s\n", s_element);
				break;
			case 14:
				sscanf(buffer, "%s %s", s_element, s_element);
				fprintf(outfile, "TLBa: %s\n", s_element);
				break;
			case 38:
				sscanf(buffer, "%s %s", s_element, s_element);
				fprintf(outfile, "L1c: %s\n", s_element);
				break;
			case 39:
				sscanf(buffer, "%s %s %s", s_element, s_element, s_element);
				fprintf(outfile, "L1b: %s\n", s_element);
				break;
			case 40:
				sscanf(buffer, "%s %s", s_element, s_element);
				fprintf(outfile, "L1a: %s\n", s_element);
				break;
			case 43:
				sscanf(buffer, "%s %s", s_element, s_element);
				fprintf(outfile, "L2c: %s\n", s_element);
				break;
			case 44:
				sscanf(buffer, "%s %s %s", s_element, s_element, s_element);
				fprintf(outfile, "L2b: %s\n", s_element);
				break;
			case 45:
				sscanf(buffer, "%s %s", s_element, s_element);
				fprintf(outfile, "L2a: %s\n", s_element);
				break;
			case 52:
				sscanf(buffer, "%s %s %s %s", s_element, s_element, s_element, s_element);
				s_element[strlen(s_element) - 1] = '\0';
				if (strcmp(s_element, "N") == 0) {
					strcpy(s_element, "0");
				}
				fprintf(outfile, "L2prf: %s\n", s_element);
				break;
			case 21:
				sscanf(buffer, "%s %s %s", s_element, s_element, s_element);
				s_element[strlen(s_element) - 1] = '\0';
				fprintf(outfile, "Tlb-Load-Misses: %s\n", s_element);
				break;
			case 25:
				sscanf(buffer, "%s %s %s", s_element, s_element, s_element);
				s_element[strlen(s_element) - 1] = '\0';
				fprintf(outfile, "Tlb-Store-Misses: %s\n", s_element);
				break;
			case 29:
				sscanf(buffer, "%s %s %s", s_element, s_element, s_element);
				s_element[strlen(s_element) - 1] = '\0';
				fprintf(outfile, "Tlb-Total-Misses: %s\n", s_element);
				break;
			case 56:
				sscanf(buffer, "%s %s %s", s_element, s_element, s_element);
				s_element[strlen(s_element) - 1] = '\0';
				fprintf(outfile, "L1-Load-Misses: %s\n", s_element);
				break;
			case 60:
				sscanf(buffer, "%s %s %s", s_element, s_element, s_element);
				s_element[strlen(s_element) - 1] = '\0';
				fprintf(outfile, "L1-Store-Misses: %s\n", s_element);
				break;
			case 64:
				sscanf(buffer, "%s %s %s", s_element, s_element, s_element);
				s_element[strlen(s_element) - 1] = '\0';
				fprintf(outfile, "L1-Total-Misses: %s\n", s_element);
				break;
			case 69:
				sscanf(buffer, "%s %s %s", s_element, s_element, s_element);
				s_element[strlen(s_element) - 1] = '\0';
				fprintf(outfile, "L2-Load-Misses: %s\n", s_element);
				break;
			case 73:
				sscanf(buffer, "%s %s %s", s_element, s_element, s_element);
				s_element[strlen(s_element) - 1] = '\0';
				fprintf(outfile, "L2-Store-Misses: %s\n", s_element);
				break;
			case 77:
				sscanf(buffer, "%s %s %s", s_element, s_element, s_element);
				s_element[strlen(s_element) - 1] = '\0';
				fprintf(outfile, "L2-Total-Misses: %s\n", s_element);
				break;
			default:
				break;
		}
		lines ++;
	}
	fclose(outfile);
	fclose(infile);
	return 0;
}