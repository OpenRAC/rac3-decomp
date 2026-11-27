/* func_L01_00382890: near miss (k8, 2026-11-26), 5 aligned differences with the file's flags at level 01. Ported
   from its matched sibling func_L01_0036E120 (same particle burst, same callees in the same order): the start
   vector is D_L01_001DDCE0 rotated by the object's matrix (as func_L01_00382500 does), both loops run 10 times
   (written counting up: the compiler reverses them, and the first loop's decrement only lands at its end that
   way), the second loop passes life 10 and colour 0x505070 and picks the particle's byte by the level of weapon
   row D_001425C0[0x97]. Left: in the second loop retail keeps the counter in $s2 and &D_L01_00221098 in $s4
   (ours: swapped), (the byte pick is right with its test in a local, `none = row->level == 0`). A separate counter for the
   second loop (j, or life) breaks the first loop (23); other second-loop forms (i <= 9, 1..10) give the same 5,
   counting down 29-38. */
#include "common.h"
/* localdecomp:start func_L01_00382890 */
#include "vu0.h"

extern f32 D_L01_001DDD4C;
__asm__(".extern D_L01_001DDD4C, 4");
extern f32 D_L01_001DDD50;
__asm__(".extern D_L01_001DDD50, 4");
extern s32 D_L01_001DDD54;
__asm__(".extern D_L01_001DDD54, 4");
extern u8 D_L01_001DDCE0[8];
__asm__(".extern D_L01_001DDCE0, 8");
extern u8 D_001425C0[];
extern struct WeaponRow D_L01_002C5600[];
extern f32 D_L01_001DDD60;
__asm__(".extern D_L01_001DDD60, 4");
extern f32 D_L01_001DDD64;
__asm__(".extern D_L01_001DDD64, 4");
extern f32 D_L01_001DDD68;
__asm__(".extern D_L01_001DDD68, 4");
extern f32 D_L01_001DDD6C;
__asm__(".extern D_L01_001DDD6C, 4");
extern f32 D_L01_001DDD70;
__asm__(".extern D_L01_001DDD70, 4");
extern f32 D_L01_001DDD74;
__asm__(".extern D_L01_001DDD74, 4");

extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern u8 *func_L01_004660F8(void *, void *);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
typedef struct { u8 p0[0x110]; u8 v110[0x250]; s32 f360; u8 p364[0x6C0 - 0x364]; u8 v6C0[0x10]; u8 v6D0[0x10]; } H_00382890;
extern H_00382890 D_001A4BE0_00382890;
extern u8 *D_L01_00221098_00382890[];
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L01_00382890(u8 *a0) {
    vu0_v4 q;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    u8 *p;
    u8 *r;
    s32 i;
    f32 ang;
    s32 life;
    s32 spin;
    f32 f;
    vu0_v4 *c;
    s32 col;

    *(vu0_q *)&v20 = 0;
    v20.x = 0.3f;
    v20.y = -1.0f;
    v20.w = 1.0f;
    col = 0x307F7F7F;
    func_0038D000(&v30, D_L01_001DDCE0, a0 + 0xC0);
    ang = 0.0f;
    vec_add_ab(&v30, a0 + 0x10, &v30);
    a0[0xBC] = 5;
    func_0038D890(&v20, D_001A4BE0_00382890.v6C0, D_001A4BE0_00382890.v6D0, 0.34906584f);
    v10 = v20;
    for (i = 0; i < 10; i++) {
        ang = func_0038DAB8(ang, func_003824E0(0.0f, 0.62831855f));
        func_0038CE20(&v40, &v10, func_003824E0(0.120000005f, 0.36f));
        p = func_L01_004660F8(&v30, &v40);
        if (p != 0) {
            c = (vu0_v4 *)(p + 0x30);
            func_0038CE20(&v40, &v10, 0.75f);
            vec_add_ab(p + 0x10, &v30, &v40);
            *(vu0_v4 *)(p + 0x20) = v30;
            c->w = 2.0f;
            *(f32 *)(p + 0x1C) = 0.05f;
            *(f32 *)(p + 0x2C) = 0.5f;
            *(s32 *)(p + 0x4) = col;
            *(s32 *)(p + 0xC) = col;
        }
        if (fabs_asm(ang) > 1e-5f) {
            func_003C4840(&q, D_001A4BE0_00382890.v6C0, ang);
            func_0038D850(&v10, &v20, &q);
        }
    }
    func_0038D890(&v20, D_001A4BE0_00382890.v6C0, D_001A4BE0_00382890.v6D0, D_L01_001DDD4C * 0.017453292f);
    ang = 0.0f;
    v10 = v20;
    qzero(&v60);
    if (D_001A4BE0_00382890.f360 != 0) {
        func_0038CE20(&v60, D_001A4BE0_00382890.v110, 1.7f);
    }
    for (i = 0; i < 10; i++) {
        ang = func_0038DAB8(ang, func_003824E0(0.0f, 0.62831855f));
        func_0038CE20(&v40, &v10, func_003824E0(D_L01_001DDD64 * 0.020000001f, D_L01_001DDD68 * 0.020000001f));
        vec_add_ab(&v40, &v40, &v60);
        spin = func_L01_00443A18(1.0f, 2.0f);
        v50.x = v30.x + func_L01_00443A18(0.0f, D_L01_001DDD50);
        v50.y = v30.y + func_L01_00443A18(0.0f, D_L01_001DDD50);
        v50.z = v30.z + func_L01_00443A18(0.0f, D_L01_001DDD50);
        f = func_003824E0(D_L01_001DDD6C, D_L01_001DDD70);
        vec_sub_ab(&v50, &v50, &v40);
        r = func_L01_0046A610(&v50, &v40, 10, D_L01_001DDD54, 0x505070, spin,
                          f * 210000.0f, D_L01_001DDD74, D_L01_001DDD60, 0.0f, 0.0f);
        if (r != 0) {
            { s32 none = (D_L01_002C5600 + D_001425C0[0x97])->level == 0; r[2] = none ? D_L01_00221098_00382890[0x5B][1] : D_L01_00221098_00382890[0x5B][0]; }
        }
        if (fabs_asm(ang) > 1e-5f) {
            func_003C4840(&q, D_001A4BE0_00382890.v6C0, ang);
            func_0038D850(&v10, &v20, &q);
        }
    }
}
/* localdecomp:end func_L01_00382890 */
