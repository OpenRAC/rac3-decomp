#include "common.h"

/* NTSC-U counterpart of func_L39_005FB708 (src/levels/shared/L39_005FB708.c) */
/* localdecomp:start func_L39_005F8F70 */
typedef struct { s32 sector; s32 size; } TocFile_005FB708;
typedef struct {
    s32 header;
    s32 base;
    TocFile_005FB708 files[1];
} Toc_005FB708;
extern Toc_005FB708 D_L39_001F0B80;
extern u32 D_001A4CD0[];
extern u8 D_001A5A47[];
extern s32 D_L39_0025F600[];
extern s32 D_L39_0024CBB4;
extern s32 func_003A8770_005F8F70(s32);
extern void func_L39_00599130(void *);
extern void func_L39_005F9038(s32, s32, s32, s32, s32);

/* from rac2-decomp's func_002F5D40 */
void func_L39_005F8F70(s32 n)
{
    s32 index;
    s32 flag;
    s32 i2;
    u8 v;
    s32 a0;

    if (n < 0) {
        D_L39_0024CBB4 = 0;
        return;
    }
    index = func_003A8770_005F8F70(n);
    D_001A4CD0[(u32)n >> 2] |= 1 << (n & 0x1F);
    func_L39_00599130(D_L39_0025F600);
    flag = index == 0x1F;
    a0 = D_L39_001F0B80.files[index * 2 + 1].sector + D_L39_001F0B80.base;
    v = D_001A5A47[0];
    if (D_L39_0025F600[0] != 0) {
        v = 0;
    }
    i2 = index * 2;
    func_L39_005F9038(a0, D_L39_001F0B80.files[i2 + 1].size, (s32)&D_L39_001F0B80.files[i2], v, flag);
}
/* localdecomp:end func_L39_005F8F70 */
