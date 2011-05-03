/* #include <xdc/std.h>
#include <ialg.h> */



#include "LMS.h"
#include "file_read.h"

#define FAR_FILENAME "filtered_noise_10.dat"
#define NEAR_FILENAME "echo_10_128.dat"


#define SAMPLE_LEN 40000

int main (void)
{
	FILE* far_f, *near_f;

	far_f = open_file(FAR_FILENAME, "r");
	near_f = open_file(NEAR_FILENAME, "r");

//	out_file = open_file("/home/lexa/out.algo", "w");

	LMS* l = create_LMS(140);  // выделяет память ~850байт

//	float eps[SAMPLE_LEN] = {0};

	int i=0;
	int16_t far_s;
	int16_t near_s;
	float eps;
	for (i=0; i<SAMPLE_LEN; ++i)
	{
		if ((fread(&far_s, sizeof(far_s), 1, far_f) < 1) || (fread(&near_s, sizeof(near_s), 1, near_f) < 1)) // выделяет память ~250байт
		 	break;
 
		eps = make_LMS(l, far_s, near_s);
//		eps = 1;
//		fprintf(out_file, "%d %g\n", i,  eps);
		fprintf(stderr, "%d %d %d %g\n", i, far_s, near_s,  eps);
	}
	destroy_LMS(l);

	fclose(far_f);
	fclose(near_f);
//	fclose(out_file);
	return 0;
}
