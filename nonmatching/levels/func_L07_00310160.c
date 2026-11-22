/* PAL near miss (opus-w4): 85 words differ (72 aligned) with the file's flags plus -mvu0-use-vf0-vf2 (the VU0 part is j-form; without vf2 it does not compile; was 226). The loop count is copied (n = count), the hit stores put flags first. Left: global-alloc gives m ($s0 here) a higher priority than the hit-list pointer p and j, so the two swap $s0/$s1 throughout (retail: p and j in $s0, m in $s1); retail copies m + 0x10 into $s4 from $a0 after building the argument; the second VU0 add loads v3 before v1 here; and the last sqc2 into v2 sits before the jal instead of in its delay slot. */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L07_00310160 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00310160;
typedef struct { V_00310160 dir; void *source; u32 flags; u8 type,mode; u16 id; f32 damage; u32 kind; } Hit_00310160;
extern void *D_L07_001ECC80[];
extern u8 D_001A4BE0[];
extern s32 func_003D4D00(void *,s32,void *,s32,f32);
extern f32 func_0038D160(f32,f32);
extern f32 func_0038DBA0(f32,f32);
extern f32 func_L01_0040E570(void *,void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_00456230(void *,s32);
extern void func_L01_00446978(void *,void *);
extern f32 func_0038DB48(f32);
extern f32 func_0038DAB8(f32,f32);
extern void func_00382760(void *,f32,f32,f32);
extern s32 func_003D3CB0(void *,void *,s32,void *,s32);
void func_L07_00310160(void *arg0, void *arg1) {
    union { Hit_00310160 hit; struct { V_00310160 v0,v1,v2,v3; } v; } u;
    u8 *m = arg0;
    u8 *state = arg1;
    u8 *position;
    void **p;
    u8 *hero;
    s32 count, n, i, j;
    f32 radius, a, b, sign, limit;

    radius = *(f32 *)(state+0x70) * *(f32 *)(state+0x78);
    if (radius < 0.75f) radius = 0.75f;
    position = m + 0x10;
    count = func_003D4D00(position, 16, *(void **)(m+0xB8), 0, radius);
    if (count > 0) {
        p = D_L07_001ECC80;
        hero = D_001A4BE0;
        n = count;
        do {
            if (*p == *(void **)(m+0xB8)) goto next;
            if (*(f32 *)(state+0x78) > 0.0f) {
                f32 dz;
                if (func_0038DBA0(func_0038D160(*(f32 *)((u8 *)*p+0x10) - *(f32 *)(m+0x10), *(f32 *)((u8 *)*p+0x14) - *(f32 *)(m+0x14)), *(f32 *)(m+0xF8)) > 0.7417649f) goto next;
                dz = *(f32 *)((u8 *)*p+0x18) - *(f32 *)(m+0x18);
                if (dz > 0.2f) goto next;
                if (dz < -2.0f) goto next;
                limit = radius * 0.95f;
                if (func_L01_0040E570(position, (u8 *)*p+0x10) < limit * limit) goto next;
            }
            u.hit.flags = 0x430001;
            u.hit.kind = 0x430000;
            u.hit.source = *(void **)(m+0xB8);
            u.hit.damage = (f32)state[0x7C];
            u.hit.type = 2;
            u.hit.mode = 3;
            u.hit.id = *(u16 *)(m+0xAA);
            a = func_0038D160(*(f32 *)((u8 *)*p+0x10) - *(f32 *)(m+0x10), *(f32 *)((u8 *)*p+0x14) - *(f32 *)(m+0x14));
            u.hit.dir.x = func_0038D098(a);
            u.hit.dir.y = func_0038D0B0(a);
            u.hit.dir.z = 1.0f;
            u.hit.dir.w = 5627.9248046875f;
            if (*p == *(void **)(hero+0x25C0)) func_L01_00456230(*(void **)(m+0xB8), 1);
            func_L01_00446978(*p, &u.hit);
        next:
            n--;
            p++;
        } while (n);
    }
    for (i = 0; i < 2; i++) {
        sign = -1.0f;
        if (i & 1) sign = 1.0f;
        for (j = 0; j < 5; ) {
            vu0_q pos, r;
            a = func_0038DB48((f32)j * sign * 0.6981317f / 5.0f);
            j++;
            b = func_0038DB48((f32)j * sign * 0.6981317f / 5.0f);
            func_00382760(&u.v.v0, radius, func_0038DAB8(a, *(f32 *)(m+0xF8)), -*(f32 *)(m+0xF4));
            func_00382760(&u.v.v1, radius, func_0038DAB8(b, *(f32 *)(m+0xF8)), -*(f32 *)(m+0xF4));
            {
                vu0_q q0, q1, q3;
                __asm__("lqc2 %0, %1" : "=j"(pos) : "m"(*(V_00310160 *)(m+0x10)));
                __asm__("lqc2 %0, %1" : "=j"(q0) : "m"(u.v.v0));
                __asm__("sqc2 %1, %0" : "=m"(u.v.v3) : "j"(pos));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(q0), "j"(pos));
                __asm__("sqc2 %1, %0" : "=m"(u.v.v0) : "j"(r));
                __asm__("sqc2 %1, %0" : "=m"(u.v.v2) : "j"(r));
                __asm__("lqc2 %0, %1" : "=j"(q3) : "m"(u.v.v3));
                __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(u.v.v1));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(q1) : "j"(q1), "j"(q3));
                __asm__("sqc2 %1, %0" : "=m"(u.v.v1) : "j"(q1));
                __asm__("sqc2 %1, %0" : "=m"(u.v.v2) : "j"(q1));
            }
            if (func_003D3CB0(&u.v.v0, &u.v.v1, 18, *(void **)(m+0xB8), 0))
                func_00382760(&u.v.v2, 0.40000004f, *(f32 *)(m+0xF8), -*(f32 *)(m+0xF4));
        }
    }
}
/* localdecomp:end func_L07_00310160 */
