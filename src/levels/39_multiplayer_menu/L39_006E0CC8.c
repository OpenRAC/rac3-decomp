#include "common.h"

/* declared by functions of L39_006DC228.c, which this file was cut from */
extern u8 D_001A5CD0[];
extern void *D_001E2050_sda;
extern s32 func_L39_006D6E50(s32, s32, s32, s32 *);
extern void func_L39_006D6E30(s32, s32, s32 *);
typedef struct {
    s32 ids[8];
    f32 a[8];
    f32 b[8];
    char pad[0x8C - 0x60];
    s32 count;
    char pad2[0xA4 - 0x90];
} S_006E0150_Ent;
typedef struct {
    char pad[0x100];
    s32 active[8];
    char pad2[0x2E8 - 0x120];
    S_006E0150_Ent ent[8];
} S_006E0150;
extern S_006E0150 D_001FD7E8;

/* localdecomp:start func_L39_006E0CC8 */
extern f32 D_001A6A44 __attribute__((section(".data")));

f32 func_L39_006E0CC8(void) {
    return 2.3025851f / D_001A6A44;
}
/* localdecomp:end func_L39_006E0CC8 */
