#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L13_003B8010 */
typedef struct {
    s32 w0;
    s32 w4;
    f32 f8;
    f32 fC;
    s32 w10;
    s32 w14;
    s32 w18;
    f32 f1C;
    f32 f20;
    s32 w24;
    s32 w28;
} V_3B8010;

__asm__(".extern D_L13_001DF59C, 4");
extern u8 (*D_L13_001DF59C)[0x100];
extern s32 D_L13_001DF0C0;
extern vu0_v4 (*D_L13_001DF680)[8];
extern u8 D_00142CA0[];
extern u8 D_001A4C60[];
extern void func_003C2880(void *);
extern s32 func_00382380(void *, s32, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0043B510(s32);
extern f32 func_003C4088(f32, f32, f32);
extern void *func_L13_0034C658(s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L13_0034C730(void *, void *, void *);

void func_L13_003B8010(u8 *self) {
    V_3B8010 *v = *(V_3B8010 **)(self + 0x68);
    vu0_v4 out;
    vu0_v4 pos;
    vu0_v4 dir;

    if (self[0x20] == 0) {
        if (v->w24 != 0 && D_00142CA0[0x1D] != 0) {
            func_003C2880(self);
            return;
        }
        if (func_00382380(D_001A4C60, v->w0, 0) != 0) {
            func_L01_004450F0(self, 1, -1);
        }
        if (v->w28 >= 0) {
            if (v->w10 == -1 || D_L13_001DF59C[v->w10][0x20] == 0xFE ||
                D_L13_001DF59C[v->w10][0x20] == 0xFD) {
                func_L01_0043B510(v->w28);
            }
        }
    }
    if (self[0x20] == 1) {
        void *m;
        f32 f;
        f32 a;
        if (func_00382380(D_001A4C60, v->w0, &out) == 0) {
            func_L01_004450F0(self, 0, -1);
            return;
        }
        f = func_003C4088(v->f8, v->fC, (out.z + 1.0f) * 0.5f);
        if (v->w14 + (s32)(50.0f / f) < D_L13_001DF0C0) {
            m = func_L13_0034C658(v->w4);
            if (m != 0) {
                f32 dirAng = func_0038D160(out.x, out.y);
                a = func_0038DAB8(dirAng, func_L01_00443A18(0.0f, v->f20 * 0.017453292f));
                pos = D_L13_001DF680[v->w18][3];
                dir.x = func_0038D098(a) * v->f1C;
                dir.y = func_0038D0B0(a) * v->f1C;
                dir.z = 0.0f;
                vec_add_ab(&dir, &pos, &dir);
                func_L13_0034C730(m, &pos, &dir);
                v->w14 = D_L13_001DF0C0;
            }
        }
    }
}
/* localdecomp:end func_L13_003B8010 */
