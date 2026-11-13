#include "common.h"

/* NTSC-U counterpart of func_L39_005A88B0 (src/levels/shared/L39_005A88B0.c) */
/* localdecomp:start func_L39_005A6A98 */
typedef struct {
    int first, second, third, fourth;
    char stamp[8];
    int invalid;
} SaveInfoEntry;
typedef struct {
    char header[0x30];
    SaveInfoEntry entries[4];
} SaveInfoSlot;
extern SaveInfoSlot D_001A4560[];
extern void *memcpy(void *, const void *, unsigned int);
int func_0039E788_005A6A98(char *a0);

/* from rac2-decomp's func_0029B0B0, renamed, constants adapted */
void func_L39_005A6A98(char *src, int slot, int entry)
{
    D_001A4560[slot].entries[entry].invalid = func_0039E788_005A6A98(src) == 0;
    src += 0x10;
    D_001A4560[slot].entries[entry].first = *(int *)src;
    src += 0xC;
    D_001A4560[slot].entries[entry].second = *(int *)src;
    D_001A4560[slot].entries[entry].third = *(unsigned char *)(src + 0x32);
    src += 0x88;
    D_001A4560[slot].entries[entry].fourth = *(int *)src;
    memcpy(D_001A4560[slot].entries[entry].stamp, src + 0xC, 8);
}
/* localdecomp:end func_L39_005A6A98 */
