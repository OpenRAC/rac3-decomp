#include "common.h"
#include "vu0.h"

typedef int s128_003985C0 __attribute__((mode(TI)));
typedef struct {
    u8 pad[112];
    f32 f112;
    u8 pad2[124];
} Ent_003985C0;
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;

INCLUDE_ASM("asm/levels", func_L01_00396B78);

LINKER_REMNANT("asm/levels", func_L01_00396DE8);

INCLUDE_ASM("asm/levels", func_L01_00396E08);

/* localdecomp:start func_L01_00396FD8 */
void func_L01_00396FD8(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_00396FD8 */

/* localdecomp:start func_L01_00397060 */
extern void func_0038CE20(f32 *, f32 *, f32);
void func_L01_00397060(f32 *m, f32 s) {
    func_0038CE20(m, m, s);
    func_0038CE20(m + 4, m + 4, s);
    func_0038CE20(m + 8, m + 8, s);
    func_0038CE20(m + 12, m + 12, s);
}
/* localdecomp:end func_L01_00397060 */

INCLUDE_ASM("asm/levels", func_L01_003970C8);

INCLUDE_ASM("asm/levels", func_L01_00397278);

INCLUDE_ASM("asm/levels", func_L01_003973F8);

INCLUDE_ASM("asm/levels", func_L01_00397A28);

INCLUDE_ASM("asm/levels", func_L01_00397E98);

/* localdecomp:start func_L01_00399A40 */
void func_L01_00399A40(u8 *a) {
    a[0xBC] = 3;
}
/* localdecomp:end func_L01_00399A40 */

/* localdecomp:start func_L01_00399A50 */
extern void func_0038CE20(f32 *, f32 *, f32);


extern u8 D_001425FF[];
extern Ent_003985C0 D_L01_002C5600[];
extern u8 D_L01_001EEA80[];
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern void func_L01_00447718(void *, void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L01_00399A50(u8 *obj, s32 unused, s32 arg) {
    s128_003985C0 v;
    s128_003985C0 q;
    f32 scale;
    s32 r;

    ((void (*)(void *, f32))func_0038CE20)(&v, -3.0f);
    scale = (D_L01_002C5600 + D_001425FF[0])->f112;
    r = func_003D4D00(obj + 16, 16, obj, 0, 0.75f);
    q = *(s128_003985C0 *)(obj + 16);
    func_L01_00447718(obj, &q, D_L01_001EEA80, r, arg, 0x1110000, 3, 1, -1, scale, 1.0f, 1.0f);
}
/* localdecomp:end func_L01_00399A50 */

INCLUDE_ASM("asm/levels", func_L01_00399B18);

/* localdecomp:start func_L01_00399D78 */
extern void func_0038D000(void *, void *, void *);

void func_L01_00399D78(u8 *a0, u8 *a1) {
    vu0_q v = 0;
    f32 *f = (f32 *)&v;
    f[0] = -0.4f;
    f[3] = 1.0f;
    func_0038D000(&v, &v, a0 + 0xC0);
    vec_add_ba(a1, &v, a0 + 0x10);
}
/* localdecomp:end func_L01_00399D78 */

/* localdecomp:start func_L01_00399DE8 */
extern u8 D_L01_002A19F0[];
extern void func_L01_00399D78(u8 *a0, u8 *a1);
extern void func_L01_00409B08(u8 *a0, s32 a1, s32 a2);
extern void func_L01_00409E70(u8 *a0, u8 *a1, s32 a2, s32 a3, f32 f12, f32 f13);
void func_L01_00399DE8(u8 *a0) {
    u8 buf[16];
    u8 *s0;
    if (a0 != 0 && a0[32] != 254 && a0[32] != 253) {
        s0 = *(u8 **)(a0 + 104);
        if (s0 != 0) {
            func_L01_00399D78(a0, buf);
            func_L01_00409B08(buf, 0x103080, 0);
            func_L01_00409E70(buf, D_L01_002A19F0 + *(s32 *)(s0 + 44) * 64, 0x103080, 4, 0.0f, 0.25f);
        }
    }
}
/* localdecomp:end func_L01_00399DE8 */

INCLUDE_ASM("asm/levels", func_L01_00399E80);

INCLUDE_ASM("asm/levels", func_L01_0039A320);

INCLUDE_ASM("asm/levels", func_L01_0039A860);

INCLUDE_ASM("asm/levels", func_L01_0039AB60);

INCLUDE_ASM("asm/levels", func_L01_0039AEB8);

INCLUDE_ASM("asm/levels", func_L01_0039B478);

INCLUDE_ASM("asm/levels", func_L01_0039B6B8);

/* localdecomp:start func_L01_0039B9F0 */
extern u8 D_00142637[];
extern Ent_003985C0 D_L01_002C5600[];
extern s32 D_L01_001DE0F0;
extern u8 D_L01_002A1E70[];
extern s32 D_L01_001E205C;
extern f32 D_L01_001E2060;
__asm__(".extern D_L01_001DE0F0, 4");
void func_L01_0039B9F0(u8 *a0) {
    extern void func_L01_0039BD08(u8 *, u8 *);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
    s32 kind = D_L01_002C5600[D_00142637[0]].pad[1];
    u32 color = 0x3F7F0000;
    u32 inner = 0x103F0000;
    s32 i;
    u8 *entry;
    u8 *pos;
    f32 size;
    f32 rotation;
    u32 fade;
    u32 fade2;
    u32 alpha2;
    u32 alpha;
    if (kind == 2) {
        color = 0x3F204080;
        inner = 0x10102040;
    } else if (kind >= 3) {
        color = 0x3F00007F;
        inner = 0x1000003F;
    }
    for (i = 0; i < D_L01_001DE0F0; ++i) {
        entry = D_L01_002A1E70 + i * 0xB0;
        pos = entry + 0x30;
        if (*(u8 **)(pos + 0x6C) == a0) {
            func_L01_0039BD08(a0, entry);
            if (*(s32 *)(pos + 0x70) == 0) {
                size = func_003824E0(0.125f, 0.25f) * 5.0f;
                rotation = func_00382538();
                func_003D9508(pos, 0x39, color, 1, size, 1.25f, rotation);
                size = func_003824E0(0.0625f, 0.125f) * 5.0f;
                rotation = func_00382538();
                func_003D9508(pos, 0x39, 0x5F7F7F7F, 1, size, 1.24f, rotation);
                size = func_003824E0(0.15f, 0.35f) * 5.0f;
                func_003D9508(pos, 0xB, inner, 1, size, 1.23f, 0.0f);
            }
        }
    }
    alpha2 = (D_L01_001E205C + 20) << 24;
    alpha = D_L01_001E205C << 24;
    fade = alpha | 0xFF0032;
    fade2 = alpha2 | 0xFF0032;
    if (kind != 1) {
        if (kind == 2) {
            fade2 = alpha2 | 0x204080;
            fade = alpha | 0x204080;
        } else if (kind == 3) {
            fade2 = alpha2 | 0x1040FF;
            fade = alpha | 0x1040FF;
        }
    }
    func_003D9508(a0 + 0x10, 0x1A, fade2, 1, D_L01_001E2060, 0.5f, 0.0f);
    func_003D9508(a0 + 0x10, 0x3D, fade, 1, D_L01_001E2060, 0.5f, 0.0f);
    func_003D9508(a0 + 0x10, 0x3D, fade, 1, D_L01_001E2060 * 1.5f, 0.5f, 0.0f);
    D_L01_001E2060 += 0.3f;
    D_L01_001E205C -= 6;
    if (D_L01_001E205C < 0) D_L01_001E205C = 0;
}
/* localdecomp:end func_L01_0039B9F0 */

INCLUDE_ASM("asm/levels", func_L01_0039BD08);

INCLUDE_ASM("asm/levels", func_L01_0039BEF8);

/* localdecomp:start func_L01_0039C190 */
#include "vu0.h"
typedef struct {
    vu0_v4 axis1, axis2, pos, interp, end;
    f32 angle1[3], speed1[3], scale1[3];
    f32 angle2[3], speed2[3], scale2[3];
    s32 release_timer;
    u8 *owner;
    s32 age, life, done, pad;
} Effect_0039C190;
extern Effect_0039C190 D_L01_002A1E70_0039C190[];
extern s32 D_L01_001DE0F0;
__asm__(".extern D_L01_001DE0F0, 4");
void func_L01_0039C190(u8 *owner) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_0038CDF8(vu0_v4 *, vu0_v4 *, vu0_v4 *, f32);
    extern s32 func_0038CAD0(s32 *);
    vu0_v4 delta;
    s32 i;
    Effect_0039C190 *p;
    for(i=0;i<D_L01_001DE0F0;i++) {
        p=&D_L01_002A1E70_0039C190[i];
        if(p->owner==owner) {
            p->pos.x+=func_003824E0(-0.1f,0.1f);
            p->pos.y+=func_003824E0(-0.1f,0.1f);
            p->pos.z+=func_003824E0(-0.1f,0.1f);
            vec_sub_ba(&delta,&p->end,&p->pos);
            *(vu0_q *)&p->pos=*(vu0_q *)(owner+0x10);
            vec_add_ba(&p->end,&p->pos,&delta);
            if(p->age) {
                p->angle1[0]=func_0038DAB8(p->angle1[0],p->speed1[0]*100.0f);
                p->angle1[1]=func_0038DAB8(p->angle1[1],p->speed1[1]*100.0f);
                p->angle1[2]=func_0038DAB8(p->angle1[2],p->speed1[2]*100.0f);
                p->angle2[0]=func_0038DAB8(p->angle2[0],p->speed2[0]*100.0f);
                p->angle2[1]=func_0038DAB8(p->angle2[1],p->speed2[1]*100.0f);
                p->angle2[2]=func_0038DAB8(p->angle2[2],p->speed2[2]*100.0f);
            } else {
                p->angle1[0]=func_0038DAB8(p->angle1[0],p->speed1[0]*50.0f);
                p->angle1[1]=func_0038DAB8(p->angle1[1],p->speed1[1]*50.0f);
                p->angle1[2]=func_0038DAB8(p->angle1[2],p->speed1[2]*50.0f);
                p->angle2[0]=func_0038DAB8(p->angle2[0],p->speed2[0]*50.0f);
                p->angle2[1]=func_0038DAB8(p->angle2[1],p->speed2[1]*50.0f);
                p->angle2[2]=func_0038DAB8(p->angle2[2],p->speed2[2]*50.0f);
            }
            p->axis1.x=func_0038D098(p->angle1[0])*p->scale1[0];
            p->axis1.y=func_0038D0B0(p->angle1[1])*p->scale1[1];
            p->axis1.z=-func_0038D0B0(p->angle1[2])*p->scale1[2];
            p->axis2.x=func_0038D098(p->angle2[0])*p->scale2[0];
            p->axis2.y=func_0038D0B0(p->angle2[1])*p->scale2[1];
            p->axis2.z=-func_0038D0B0(p->angle2[2])*p->scale2[2];
            func_0038CDF8(&p->interp,&p->pos,&p->end,1.0f-(f32)p->age/(f32)p->life);
            if(func_0038CAD0(&p->age)) {
                if(!p->done) p->done=1;
                if(func_0038CAD0(&p->release_timer)) p->owner=0;
            }
        }
    }
}
/* localdecomp:end func_L01_0039C190 */

/* localdecomp:start func_L01_0039C498 */
void func_L01_0039C498(vu0_v4 *p, s32 i) {
    vu0_v4 d;

    vec_sub_ab(&d, &p[i - 2], &p[i - 3]);
    vec_add_ab(&p[i - 1], &p[i - 2], &d);
}
/* localdecomp:end func_L01_0039C498 */

/* localdecomp:start func_L01_0039C4D8 */
void func_L01_0039C4D8(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_0039C4D8 */

INCLUDE_ASM("asm/levels", func_L01_0039C560);

INCLUDE_ASM("asm/levels", func_L01_0039C9E0);

INCLUDE_ASM("asm/levels", func_L01_0039D2E0);

INCLUDE_ASM("asm/levels", func_L01_0039D6E0);

INCLUDE_ASM("asm/levels", func_L01_0039D818);

LINKER_REMNANT("asm/levels", func_L01_0039D930);

INCLUDE_ASM("asm/levels", func_L01_0039D938);

INCLUDE_ASM("asm/levels", func_L01_0039DB90);

INCLUDE_ASM("asm/levels", func_L01_0039DCB8);

INCLUDE_ASM("asm/levels", func_L01_0039E018);

/* localdecomp:start func_L01_0039E0C8 */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_0039E0C8;

extern void func_0038D890(Vec4_0039E0C8 *, Vec4_0039E0C8 *, Vec4_0039E0C8 *, f32);
extern void func_0038CF68(Vec4_0039E0C8 *, Vec4_0039E0C8 *, f32);
extern u8 D_L01_001E2080_0039E0C8[8] __asm__("D_L01_001E2080");
extern u8 D_L01_001E20B0_0039E0C8[8] __asm__("D_L01_001E20B0");
__asm__(".extern D_L01_001DE100, 4");
__asm__(".extern D_L01_001DE128, 4");
extern f32 D_L01_001DE100;
extern f32 D_L01_001DE128;

void func_L01_0039E0C8(u8 *obj)
{
    u8 *state = *(u8 **)(obj + 0x68);
    s32 i;
    Vec4_0039E0C8 *p = (Vec4_0039E0C8 *)D_L01_001E2080_0039E0C8;
    Vec4_0039E0C8 *q = (Vec4_0039E0C8 *)D_L01_001E20B0_0039E0C8;

    for (i = 0; i < state[0xA]; i++) {
        func_0038D890(&p[i], &p[i], &q[i], D_L01_001DE100);
        func_0038CF68(&p[i], &p[i], D_L01_001DE128);
    }
}
/* localdecomp:end func_L01_0039E0C8 */

/* localdecomp:start func_L01_0039E158 */

extern void func_003C5278(Vec4 *, Vec4 *, Vec4 *, f32);
extern s32 func_003D3CB0(Vec4 *, s32 *, s32, s32, s32);
extern s32 D_001A4CC0[];

s32 func_L01_0039E158(u8 *obj) {
    Vec4 v;
    v = *(Vec4 *)(obj + 16);
    func_003C5278((Vec4 *)(obj + 16), &v, &v, -0.5f);
    return func_003D3CB0(&v, D_001A4CC0, 18, 0, 0) == 0;
}
/* localdecomp:end func_L01_0039E158 */
