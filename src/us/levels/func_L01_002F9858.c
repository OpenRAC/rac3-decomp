#include "common.h"

/* localdecomp:start func_L01_002F9858 */
void func_L01_002F9858(char *object)
{
    extern void func_L01_002F9F48(char *);
    extern void func_L01_002F9B30(char *);
    extern float func_00389380(float, float);
    extern void func_L01_002F9A40(char *);
    extern void func_L01_004C6EC8(char *, char *);
    extern void func_L01_004C6FD8(char *, char *);
    extern void func_L01_002FB230(char *);
    char *moby = object;
    unsigned char mode = *(unsigned char *)(moby + 32);
    char *vars = *(char **)(moby + 104);
    float result;

    switch (mode) {
    case 0:
        if (*(int *)(vars + 20) != 0) {
            func_L01_002F9F48(moby);
        } else {
            func_L01_002F9B30(moby);
        }
        result = func_00389380(*(float *)(moby + 240), 0.03490658849477768f);
        *(float *)(moby + 240) = result;
        result = func_00389380(*(float *)(moby + 244), 0.13089969754219055f);
        *(float *)(moby + 244) = result;
        func_L01_002F9A40(moby);
        break;
    case 1:
        func_L01_004C6EC8((char *)(moby + 16), (char *)(moby + 16));
        func_L01_004C6FD8(vars, vars);
        func_L01_002FB230(moby);
        break;
    }
}
/* localdecomp:end func_L01_002F9858 */
