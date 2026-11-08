/* near miss (level 3, Starship Phoenix): flags: matches only with @ps2as (the float constants 1.0e7 and -1.0 are built inline with lui/mtc1; the default assembler gives 115 diff), and L03_0032C3A8.c cannot take @ps2as because the already matched func_L03_0032C8F8 then differs; the C itself matched with --as ps2as */
#include "common.h"

/* localdecomp:start func_L03_0032D348 */
typedef struct S_0032D348 {
    char pad[0xA8];
    int idx[3];
    int cnt[16];
} S_0032D348;
extern int D_L03_0021C620[];
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern int D_L03_001DF9D8;
__asm__(".extern D_L03_001DF9D8, 16");
extern char D_L03_001A4C60[];
void *func_L03_0032F6A8();
f32 func_0038CF38();
void func_L03_0032D640();
void func_L03_0032D598();

s32 func_L03_0032D348(void *a, s32 c) {
    S_0032D348 *o = *(S_0032D348 **)((char *)a + 0x68);
    s32 flag = o->cnt[c] < 1;
    s32 r = 0;
    char *far = 0, *near = 0;
    f32 mx = -1.0f, mn = 10000000.0f;
    short *cur = (short *)D_L03_0021C620[o->idx[c]];
    while ((o->idx[c] & 0xFF) != 0xFF && D_L03_001DF9D8 >= o->idx[c] && cur != 0 &&
           (cur[-1] >= 0 || cur == (short *)D_L03_0021C620[o->idx[c]])) {
        char *buf = D_L03_001DF99C + ((*(unsigned short *)cur & 0x7FFF) << 8);
        char *q;
        f32 d;
        if (buf == 0) break;
        if ((unsigned char)buf[0x20] >= 4) {
            q = func_L03_0032F6A8(buf);
            if ((unsigned char)q[0x1D] == c) {
                r = 1;
              if ((unsigned char)q[0x1C] != 3) {
                d = func_0038CF38(buf + 0x10, D_L03_001A4C60);
                if (d < mn) { near = buf; mn = d; }
                if (flag && (unsigned char)q[0x1C] == r && mx < d) { far = buf; mx = d; }
              }
            }
        }
        cur++;
    }
    if (near != 0) {
        char *q = func_L03_0032F6A8(near);
        if ((unsigned char)q[0x1C] != 1) {
            if (far != 0) func_L03_0032D640(a, far);
            func_L03_0032D598(a, near);
        }
    }
    return r;
}
/* localdecomp:end func_L03_0032D348 */
