/* Level 01. 6 diff (was 16): the do { } while (0) around the inner call raises o's allocation weight so o gets $s2 and the offset $s3 as in retail; left: flag and buf swap $s4/$s5 (global-alloc priority buf 7 refs/34 insns = 0.41, flag 6/32 = 0.375; one more weighted reference to flag would flip them, but wrapping its assignment splits the prologue block and sinks i = 0, 21 diff). Needs @ps2as (the file has it). The call to func_L01_003E34F0 passes 255 in $a2, so its definition would have to become (void *a0, f32 sc, s32 n, s32 x). */
#include "common.h"

typedef struct { char p[0x5F]; u8 cnt; } S68;
typedef struct { char p[0x68]; S68 *s; } Obj;

extern f32 D_001DF61C_sda;
__asm__(".extern D_001DF61C_sda, 4");
extern s32 D_001DF624_sda;
__asm__(".extern D_001DF624_sda, 4");
extern s32 D_001DF640_sda;
__asm__(".extern D_001DF640_sda, 4");

extern s32 func_L01_004561B8(void);
extern void func_0043A778(Obj *o, s32 i, void *out);
extern void func_L01_003E34F0(void *a0, f32 sc, s32 n, s32 x);
extern void func_L01_003E32F8(Obj *o, void *p);

void func_L01_003E36E8(Obj *o) {
    S68 *s = o->s;
    u8 buf[s->cnt * 16];
    s32 flag;
    s32 i;
    s32 j;

    flag = func_L01_004561B8() != 0;
    for (i = 0; i < s->cnt; i++) {
        func_0043A778(o, i, buf + i * 16);
        func_L01_003E34F0(buf + i * 16, D_001DF61C_sda, D_001DF624_sda, 255);
        {
            for (j = 0; flag && j < D_001DF640_sda; j++) {
                do { func_L01_003E32F8(o, buf + i * 16); } while (0);
            }
        }
    }
}
