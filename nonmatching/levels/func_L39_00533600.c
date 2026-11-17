/* NTSC-U draft (2026-11-14, Codex worker): C of func_L39_00532F88, the NTSC-U twin of func_L39_00533600, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 10 words differ with its file's flags.
 */
#include "common.h"

/* localdecomp:start func_L39_00532F88 */
typedef int Q_00532F88 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00532F88;
extern u8 *D_L39_0025F858 __attribute__((section(".data")));
extern V_00532F88 D_L39_0025F860;
extern f32 func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern void func_L39_005FD658(s32);
extern s32 func_003CE740(void *, void *, s32, s32, s32);
extern f32 func_003887C8(void *, void *);
extern void func_L39_005FD6D8(void);

void func_L39_00532F88(u8 *obj) {
    u8 *saved[4];
    V_00532F88 end;
    u8 *vars = *(u8 **)(obj + 0x68);
    s32 count = 0;
    s32 i;
    f32 length;
    V_00532F88 *start;
    V_00532F88 *finish;
    if (vars[0x2D] == 0) {
        length = func_00388770(vars);
        start = (V_00532F88 *)(obj + 0x10);
        func_00388830(&end, vars, length * 180.0f * 0.125f);
        finish = &end;
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(end) : "m"(end), "m"(*start) : "vf1", "vf2");
        func_L39_005FD658(*(s32 *)(*(u8 **)(vars + 0x28) + 0x2548));
retry:
        {
            u8 *hit;
            if (!func_003CE740(start, finish, 2, 0, 0)) goto done;
            if (count < 4 && (hit = D_L39_0025F858) != 0 &&
                (*(s16 *)(hit + 0xAA) == 0x107C || *(s16 *)(hit + 0xAA) == 0x107E)) {
                saved[count++] = hit;
                *(s32 *)(hit + 0x98) = 0;
                goto retry;
            } else {
                f32 ratio = func_003887C8(start, &D_L39_0025F860) / length;
                *(Q_00532F88 *)(vars + 0x30) = *(Q_00532F88 *)&D_L39_0025F860;
                vars[0x2C] = (s32)ratio;
            }
        }
done:
        func_L39_005FD6D8();
        vars[0x2D] = 8;
    } else {
        vars[0x2D]--;
    }
    for (i = 0; i < count; i++) {
        u8 *p = saved[i];
        *(s32 *)(p + 0x98) = *(s32 *)(*(u8 **)(p + 0x24) + 0x10);
    }
}
/* localdecomp:end func_L39_00532F88 */
