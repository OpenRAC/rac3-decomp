#include "common.h"

/* declared by functions of L09_00317798.c, which this file was cut from */
extern u8 *D_L09_001E009C;
extern void func_L09_00317D00(void);

/* localdecomp:start func_L09_00317D00 */
#include "vu0.h"

typedef struct { u8 _p0[0x25C0]; u8 *x25C0; s32 x25C4; } H_00317D00;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00317D00;
typedef struct { V_00317D00 r[3]; } M_00317D00;
typedef struct { s32 c[4]; f32 x, y; } S_00317D00;

extern u8 *D_L09_001DC710;
__asm__(".extern D_L09_001DC710, 4");
extern H_00317D00 D_001A4BE0;
extern V_00317D00 D_L09_001E2F10;
extern s32 D_L09_001DC71C;
__asm__(".extern D_L09_001DC71C, 16");
extern s32 D_001D4BC0;
__asm__(".extern D_001D4BC0, 16");
extern s32 D_001D4BC4;
__asm__(".extern D_001D4BC4, 16");
extern u8 *D_L09_001E009C_sda __attribute__((section(".sdata")));
extern u8 *D_L09_001E009C;
__asm__(".extern D_L09_001E009C, 16");
extern s32 D_L09_001E00D8_sda __attribute__((section(".sdata")));
extern u16 *D_L09_0021CDA0[];
extern u32 D_00142BA0[];
extern u8 D_0014271D[];
extern s32 func_00389598(s32);
extern void func_0038D308(void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D5F0(void *, void *, void *);
extern void func_L01_0040EE50(void *, void *);
extern s32 func_00396968(s32, s32);
extern void func_003972A0(s32, void *, f32, f32, f32, f32, f32);
extern void func_L09_00317890(void *, s32, void *, void *, s32);
extern void func_L09_00317B20(void *, void *, s32);

void func_L09_00317D00(void) {
    V_00317D00 pos;
    V_00317D00 rot;
    M_00317D00 mtx;
    V_00317D00 dir;
    V_00317D00 a;
    V_00317D00 b;
    S_00317D00 s;
    u8 *st = *(u8 **)(D_L09_001DC710 + 0x68);
    s32 t = func_00389598(0x3B);
    f32 fx, fy;
    f32 sx, sy;
    s32 c;
    s32 idx;
    u16 *p;
    u8 *e;

    qzero(&rot);
    rot.z = -1.57079637f;
    func_0038D308(&mtx, &rot);
    pos = *(V_00317D00 *)(D_001A4BE0.x25C0 + 0xE0);
    a = D_L09_001E2F10;
    b = pos;
    func_0038CE90(&dir, &a, &b);
    func_0038CF68(&dir, &dir, 1.0f);
    func_0038D5F0(&dir, &dir, &mtx);
    func_L01_0040EE50(&dir, &dir);
    fx = (f32)D_001D4BC0;
    fy = (f32)D_001D4BC4;
    c = D_L09_001DC71C;
    s.c[3] = c;
    s.c[2] = c;
    s.c[1] = c;
    s.c[0] = c;
    s.x = fx * 0.86650002f;
    s.y = fy * 0.838999987f;
    sx = fx * 0.0130000003f;
    sy = fy * 0.0160000008f;
    func_003972A0(func_00396968(0xE99A, 3), &s, s.x, s.y, sx, sy, 0.0f);

    if (D_001A4BE0.x25C4 != 0x31) {
        idx = *(s32 *)(st + 0x68);
        if (idx != -1) {
            e = D_L09_001E009C_sda + (idx << 8);
            if (e != 0 && e[0x20] != 0xFE && e[0x20] != 0xFD) {
                func_L09_00317890(e, 1, &pos, &dir, t);
            }
        }
    }

    for (p = D_L09_0021CDA0[*(s32 *)(st + 4)];
         (*(s32 *)(st + 4) & 0xFF) != 0xFF && *(s32 *)(st + 4) <= D_L09_001E00D8_sda && p != 0 &&
         ((s16)p[-1] >= 0 || p == D_L09_0021CDA0[*(s32 *)(st + 4)]);
         p++) {
        u8 *m = D_L09_001E009C + ((*p & 0x7FFF) << 8);
        if (m == 0) {
            break;
        }
        if (m[0x20] == 0xFE) {
            continue;
        }
        if (m[0x20] == 0xFD) {
            continue;
        }
        func_L09_00317890(m, 3, &pos, &dir, t);
    }

    if ((D_00142BA0[0x94 / 4] & 0x800000) && D_0014271D[0] == 0) {
        func_L09_00317B20(&pos, &dir, t);
    }
}
/* localdecomp:end func_L09_00317D00 */
