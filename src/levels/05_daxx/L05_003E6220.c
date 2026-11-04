#include "common.h"

typedef struct Slot_003E6220 {
    u8 pad00[0x50];
    char *ship;
    u8 pad54[0x460 - 0x54];
} Slot_003E6220;

/* localdecomp:start func_L05_003E6220 */
extern Slot_003E6220 D_L05_001E2700[];
extern f32 func_0038CF00(void *, void *);

int func_L05_003E6220(int idx)
{
    Slot_003E6220 *slot = &D_L05_001E2700[idx];
    char *ship = slot->ship;
    char *motion = *(char **)(ship + 0x70);
    int state = *(u8 *)(ship + 0x88);
    int result = 0;
    char *pad = motion + 0xE0;
    float *spin = (float *)(motion + 0x30);
    float *vel = (float *)motion;
    char *dock = motion + 0x80;
    float d;

    if ((u32)(state - 2) < 2) {
        result = *(int *)(motion + 0xE0) == 0;
    } else if ((u8)state != 1 && (u8)state != 4 && vel[0] < 0.001f && vel[1] < 0.001f && vel[2] < 0.001f
               && spin[0] < 0.0001f && spin[1] < 0.0001f && spin[2] < 0.0001f) {
        d = func_0038CF00(ship + 0x30, dock);
        if (d < 0.01f)
            result = 1;
        else if (*(int *)(pad + 0x40) != 0 && 0.1f < d)
            result = 4;
    }
    if (*(int *)(pad + 0x40) != 0 && *(u8 *)(ship + 0x89) != 0)
        result |= 2;
    return result;
}
/* localdecomp:end func_L05_003E6220 */
