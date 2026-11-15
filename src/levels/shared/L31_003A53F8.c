#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L31_003A53F8 */
typedef struct {
    char pad0[0x1C8];
    int mode;
} Vars;

typedef struct {
    char pad0[0x10];
    float x;
    float y;
    float z;
    char pad1C[0x68 - 0x1C];
    Vars *vars;
} Moby;

typedef struct {
    char pad0[0x80];
    float pos[4];
} Player;

extern Player D_001A4BE0;
extern float D_L31_001DE9F4;
extern float D_L31_001DE9F8;
extern int func_L31_003A5178(void *, float *);

int func_L31_003A53F8(Moby *m) {
    float range;

    if (m->vars->mode == 2) {
        range = D_L31_001DE9F4;
    } else {
        range = D_L31_001DE9F8;
    }
    if (fabs_asm(m->x - D_001A4BE0.pos[0]) < range &&
        fabs_asm(m->z - D_001A4BE0.pos[2]) < range &&
        func_L31_003A5178(m, D_001A4BE0.pos) != 0) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L31_003A53F8 */
