#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003C0720();


typedef int Q_3BAE98 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BAE98;
extern f32 D_001D8E60;
extern f32 D_001D8FC8;
extern s32 D_001D8F94;
extern s32 D_001D8E80;
extern s32 D_001D8F9C;
extern s32 D_001D8F98;
extern f32 D_001D8FA0;
extern f32 D_001D8FA4;
extern f32 D_001D8FA8;
extern f32 D_001D8FAC;
extern f32 D_001D8FB8;
extern f32 D_001D8FBC;
extern f32 D_001D8FC0;
extern f32 D_001D8FC4;
extern s32 D_001D8FB0;
extern s32 D_001D8FB4;
extern s32 D_001D8F90;
extern f32 D_001DA334;
extern s32 D_001D9D00;
extern void func_003A9440(s32, unsigned long);
extern void func_0038C750(void);
extern void func_0038D028();
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003D9740(void *, s32, s32, s32, s32, f32);
/* localdecomp:start func_003C03A8 */
/* from the NTSC decomp's func_003C0658 (the US draft in nonmatching/boot_elf/) */
#include "vu0.h"
__asm__(".extern D_001D8E60, 4");
__asm__(".extern D_001D8FC8, 4");
__asm__(".extern D_001D8F94, 4");
__asm__(".extern D_001D8E80, 4");
__asm__(".extern D_001D8F9C, 4");
__asm__(".extern D_001D8F98, 4");
__asm__(".extern D_001D8FA0, 4");
__asm__(".extern D_001D8FA4, 4");
__asm__(".extern D_001D8FA8, 4");
__asm__(".extern D_001D8FAC, 4");
__asm__(".extern D_001D8FB8, 4");
__asm__(".extern D_001D8FBC, 4");
__asm__(".extern D_001D8FC0, 4");
__asm__(".extern D_001D8FC4, 4");
__asm__(".extern D_001D8FB0, 4");
__asm__(".extern D_001D8FB4, 4");
__asm__(".extern D_001D8F90, 4");
extern s32 D_001DA338;
extern f32 D_001DA334;
extern s32 D_001D9D00;
extern void func_003C2EC0();
extern void func_003A9440(s32, unsigned long);
extern void func_0038C750(void);
extern void func_0038D028();
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003D9740(void *, s32, s32, s32, s32, f32);
void func_003C03A8(void *p) {
    V4_3BAE98 m0[3];
    V4_3BAE98 m30;
    V4_3BAE98 m40[3];
    V4_3BAE98 m70;
    V4_3BAE98 m80[4];
    f32 k, ph, t, s, w;
    s32 i, j, n, col, al, lo;
    u8 ob;
    k = D_001DA334 / (D_001D8E60 * 0.020000001f);
    if (D_001D8FC8 < k) {
        func_003C2EC0(p, 0, m80);
        k = 1.0f;
        ph = (f32)(D_001D9D00 % D_001D8F94) / (f32)D_001D8F94;
        func_003A9440(8, 0);
        func_003A9440(0x14, 0xFF9000000260UL);
        func_003A9440(0x47, 0x533F1);
        func_0038C750();
        for (i = 0; i < 4; i++) {
            m0[0] = m80[1];
            m0[1] = m80[2];
            m0[2] = m80[0];
            func_0038D028(&m30, (V4_3BAE98 *)&D_001D8E80 + i, m80);
            for (j = 0; j < D_001D8F9C; j++) {
                n = D_001D8F98;
                t = (f32)((D_001DA338 + n / D_001D8F9C * j) % n) / (f32)n;
                ob = i & 1;
                if (ob) {
                    t += 0.5f;
                    if (1.0f < t) t -= 1.0f;
                }
                t = t * t;
                if (i < 2) {
                    w = (D_001D8FA4 - D_001D8FA0) * t * k + D_001D8FA0;
                    s = (D_001D8FAC - D_001D8FA8) * t + D_001D8FA8;
                } else {
                    w = (D_001D8FBC - D_001D8FB8) * t * k + D_001D8FB8;
                    s = (D_001D8FC4 - D_001D8FC0) * t + D_001D8FC0;
                }
                col = func_0038DBD8(D_001D8FB0, D_001D8FB4, t);
                lo = col & 0xFFFFFF;
                al = (s32)((f32)((u32)(col & 0xFF000000) >> 24) * k);
                col = lo | (al << 24);
                func_0038CE20((f32 *)&m40[0], &m0[0], s);
                func_0038CE20((f32 *)&m40[1], &m0[1], s);
                func_0038CE20((f32 *)&m40[2], &m0[2], w);
                vec_sub_ab(&m70, &m30, &m40[2]);
                func_003D9740(m40, D_001D8F90, col, 4, 1, ph + t + (f32)(i & 1) * 0.5f);
            }
        }
        func_003A9440(0x47, 0x5360B);
    }
}
/* localdecomp:end func_003C03A8 */

/* localdecomp:start func_003C0720 */
/* from boot_elf func_003C0AD8 (twin), callees renamed through config/frontend_pairs.tsv */
#include "vu0.h"
extern f32 D_001DA340;
extern u8 D_001DA33C;
extern s32 D_001D8E40;
__asm__(".extern D_001D8E40, 4");
extern vu0_v4 D_00222400[];
extern void func_003C09E8(void *);
extern void func_00389D60(void (*)(), s32);
extern void func_003C2EC0();
extern f32 func_0038CEA8(void *);
extern f32 func_003824E0(f32, f32);
extern void func_003BF988(void *, void *, void *);
void func_003C0720(u8 *obj) {
    vu0_v4 mat[4], d, p, v;
    vu0_v4 *table;
    vu0_v4 *velocity, *position;
    f32 base, ratio;
    s32 i;
    func_00389D60(func_003C09E8,(s32)obj);
    func_003C2EC0(obj,0,(u8 *)mat);
    D_001DA33C=0;
    *(f32 *)(&D_001DA33C+4)=1.0f;
    base=func_0038CEA8(mat);
    vec_sub_ab(&d,obj+0x10,D_00222400);
    ratio=func_0038CEA8(&d)/base;
    if(ratio>20.0f) {
        D_001DA33C=1;
        *(f32 *)(&D_001DA33C+4)=1.0f-(ratio-20.0f)/40.0f;
        if(*(f32 *)(&D_001DA33C+4)<0.0f) *(f32 *)(&D_001DA33C+4)=0.0f;
    }
    velocity=&v;
    position=&p;
    table=(vu0_v4 *)&D_001D8E40;
    for(i=1;i>=0;i--) {
        func_0038D028(position,table++,mat);
        v.x=0;
        v.y=0;
        v.z=func_003824E0(0.007f,0.015f);
        func_003BF988(obj,position,velocity);
    }
}
/* localdecomp:end func_003C0720 */
