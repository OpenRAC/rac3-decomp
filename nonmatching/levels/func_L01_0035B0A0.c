/* PAL near miss, round 27 W6. Level 01, 159 raw / 165 aligned
   differences using the file flags, including @ps2as.
   Split source-packet induction, initialize its base between the two draw calls, and put the first horizontal UV store ahead of the vertical store in the zero-flag arm.
   Differences remain in saved registers for rec, i, pos and alpha, plus induction bases and spill slots around the second draw call.
   The scratch whole-file check used the func_L01_0035AB50_0035B5A0 alias
   in the later func_L01_0035B5A0 block to resolve a declaration conflict.
 */
#include "common.h"
/* localdecomp:start func_L01_0035B0A0 */
#include "vu0.h"
typedef struct { u8 b0; u8 b1; u8 p2[0xEE]; } Row_0035B0A0;
typedef struct { vu0_v4 p[4]; s32 c[4]; f32 uv[8]; long l70, l78, l80, l88; } Pk_0035B0A0;
typedef struct {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 pos[2];
    u8 pad40[0x20];
    Pk_0035B0A0 pk[8];
    s32 r[4];
    f32 vel[4];
    f32 off[4];
    f32 x510;
    s32 x514;
    s32 x518;
    s32 x51C;
    u8 pad520[0x10];
} Rec_0035B0A0;
extern u8 D_001425C0[];
extern Row_0035B0A0 D_L01_002C5600_0035B0A0[];
extern u8 D_L01_00284500_0035B0A0[];
extern u8 D_L01_001E29C0_0035B0A0[];
extern void func_L01_0035B5A0(s32, f32 *, f32 *, s32, f32);
extern long func_00389598(s32);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D2DA0();

void func_L01_0035B0A0(u8 *obj) {
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    Rec_0035B0A0 *rec;
    Pk_0035B0A0 *pk;
    s32 i;
    s32 k;
    s32 j, m;
    Pk_0035B0A0 *src;
    s32 b1;
    s32 col;
    s32 alpha;
    s32 a24;
    vu0_v4 *pos;

    b1 = D_L01_002C5600_0035B0A0[D_001425C0[0x7F]].b1;
    col = 0x103080;
    if ((u32)(b1 - 2) < 2) {
        col = 0x803010;
    } else if (b1 >= 4) {
        col = 0x803010;
    }
    for (i = 0; i < 0x19; i++) {
        rec = (Rec_0035B0A0 *)(D_L01_00284500_0035B0A0 + i * 0x530);
        if (rec->x514 != 1) {
            continue;
        }
        if (rec->x518 == 1) {
            alpha = (s32)(rec->x510 * 64.0f * 2.0f);
        } else {
            alpha = 0x40;
        }
        a24 = alpha << 24;
        pos = &rec->pos[0];
        func_L01_0035B5A0((s32)obj, (f32 *)pos, (f32 *)rec, col + a24, 0.35f);
        src = &rec->pk[0];
        func_L01_0035B5A0((s32)obj, (f32 *)pos, (f32 *)rec, a24 | 0xFFFFFF, 0.075f);
        for (k = 0, j = 4, m = 0; k < 2; k++, j++, m++) {
            Pk_0035B0A0 *source = &src[m];
            pk = &rec->pk[j];
            pk->l78 = func_00389598(0x17);
            pk->l88 = ((long)(k % 2 + 1) << 2) | 0x8000000040L;
            pk->l80 = 0xFF9000000260L;
            pk->l70 = 0;
            pk->c[0] = col + a24;
            pk->c[2] = col + a24;
            pk->c[3] = col;
            pk->c[1] = col;
            if (rec->r[m] != 0) {
                pk->uv[1] = 0.0f;
                pk->uv[0] = rec->off[k] + 0.0f;
                pk->uv[3] = 0.0f;
                pk->uv[2] = rec->off[k] + 1.0f;
                pk->uv[5] = 1.0f;
                pk->uv[4] = rec->off[k] + 0.0f;
                pk->uv[7] = 1.0f;
                pk->uv[6] = rec->off[k] + 1.0f;
            } else {
                pk->uv[0] = rec->off[k] + 0.0f;
                pk->uv[1] = 1.0f;
                pk->uv[3] = 1.0f;
                pk->uv[2] = rec->off[k] + 1.0f;
                pk->uv[5] = 0.0f;
                pk->uv[4] = rec->off[k] + 0.0f;
                pk->uv[7] = 0.0f;
                pk->uv[6] = rec->off[k] + 1.0f;
            }
            vec_sub_ba(&v40, D_L01_001E29C0_0035B0A0, &pos[k]);
            func_003C5180(&pos[k], &v50, 1);
            func_0038CF68(&v0, &v40, 1.0f);
            func_0038CE90(&v10, &v0, &v50);
            func_0038CF68(&v10, &v10, 1.0f);
            func_0038CE90(&v20, &v10, &v0);
            v30.x = pos[k].x;
            v30.y = pos[k].y;
            v30.z = pos[k].z;
            v30.w = 1.0f;
            if (rec->x518 == 1) {
                func_0038CE20((f32 *)&pk->p[0], &source->p[0], 0.5f);
                func_0038CE20((f32 *)&pk->p[1], &source->p[1], 0.5f);
                func_0038CE20((f32 *)&pk->p[2], &source->p[2], 0.5f);
                func_0038CE20((f32 *)&pk->p[3], &source->p[3], 0.5f);
            } else {
                func_0038CE20((f32 *)&pk->p[0], &source->p[0], rec->x510);
                func_0038CE20((f32 *)&pk->p[1], &source->p[1], rec->x510);
                func_0038CE20((f32 *)&pk->p[2], &source->p[2], rec->x510);
                func_0038CE20((f32 *)&pk->p[3], &source->p[3], rec->x510);
            }
            func_003D2DA0(pk, &v0, 0);
        }
    }
}
/* localdecomp:end func_L01_0035B0A0 */
