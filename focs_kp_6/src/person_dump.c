#include "person.h"

// delimiter - ;
//Anciborko;2;2;4;1;4;0;2;1024;1;0
bool readBase (Person *person, FILE *file) {
	int res = fscanf(file, "%[^;];%u;%u;%u;%u;%u;%u;%u;%u;%u;%u\n",
                           person->surname,
                           &person->cpuCount,
                           &person->cpuType,
                           &person->memorySize,
                           &person->videoCardType,
						   &person->videoMemorySize,
                           &person->diskType,
                           &person->diskCount,
                           &person->diskSize,
                           &person->externalDevicesCount,
                           &person->operatingSystem);
	if (res == 11) {
		return true;
	}
	return false;
}

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Rus");

	if (argc != 3) {
		printf("Неверный ввод.\n");
		return 1;
	}
	Person person;
	memset(&person, '0', sizeof(Person));
	FILE *base = fopen(argv[1], "r");
	if (!base) {
		perror("Не удается открыть файл1\n");
		return 2;
	}
	FILE *bin = fopen(argv[2], "w");
	if (!bin) {
		perror("Не удается открыть файл\n");
		fclose(base);
		return 2;
	}

	while (readBase(&person, base)) {
		fwrite(&person, sizeof(Person), 1, bin);
	}
	fclose(bin);
	fclose(base);
	return 0;
}