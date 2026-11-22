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

/* localdecomp:start func_L01_00396E08 */
typedef struct {
    u8 pad0[0x10];
    Vec4 vector;
    u8 pad20[0x40 - 0x20];
    Vec4 vector40;
    u8 pad50[0x5C - 0x50];
    s32 timer;
    u8 pad60[0x6C - 0x60];
    s32 disabled;
} Data_00396E08;
typedef struct {
    u8 pad0[0x10];
    Vec4 position;
    u8 state;
    u8 pad21[0x2C - 0x21];
    f32 scale;
    u8 pad30[0x68 - 0x30];
    Data_00396E08 *data;
} Object_00396E08;
extern void func_L01_003973F8(Vec4 *, Vec4 *, f32, u32, s32, f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
extern void func_L01_003970C8_00396E08(Vec4 *, u32, f32, s32, s32, s32, f32, f32);
extern void func_L01_00397278(Vec4 *, u32, s32, f32, f32, s32, s32, Vec4 *);
void func_L01_00396E08(Object_00396E08 *object) {
    Data_00396E08 *data = object->data;
    Vec4 position;
    f32 zero;
    switch (object->state) {
    case 1:
        position = object->position;
        func_L01_003973F8(&position, &data->vector, 0.0f, 0x103080, 3, 1.0f, 0.25f);
        func_L01_003970C8_00396E08(&object->position, 0x103080, object->scale * 80.0f, func_00382498(79, 111), 11, 2, func_00382538(), -1.0f);
        break;
    case 2:
        data->timer--;
        if (data->timer <= 0) data->timer = 0;
        position = object->position;
        zero = 0.0f;
        func_L01_003973F8(&position, &data->vector, zero, 0x103080, 3, 0.85f, 0.25f);
        if (data->disabled == 0) {
            f32 scale = object->scale;
            f32 factor = 45.0f;
            func_L01_00397278(&object->position, 0x103080, data->timer, scale * factor, zero, 11, 2, &data->vector40);
            func_L01_00397278(&object->position, 0x3F3F3F, data->timer, object->scale * factor * 0.75f, zero, 11, 2, &data->vector40);
        }
        break;
    }
}
/* localdecomp:end func_L01_00396E08 */

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

/* localdecomp:start func_L01_00397278 */
typedef struct {
    f32 verts[4][4];
    u32 color[4];
    f32 uv[8];
    unsigned long f70;
    unsigned long tex;
    unsigned long reg80;
    unsigned long prim;
} Quad_00397278;
extern void func_L01_00396FD8_00397278(u8 *p);
extern void func_L01_00397060_00397278(f32 *m, f32 s);
extern unsigned long func_00389598(s32 tex);
extern f32 func_0038D160(f32 a, f32 b);
extern f32 func_0038CED8(Vec4 *v);
extern void func_0038D328(f32 *mat, f32 *rot);
extern void func_0038CF68_00397278(Vec4 *dst, Vec4 *src, f32 s);
extern void func_003D2DA0(Quad_00397278 *quad, f32 *mat, s32 a);
/* agent_comet_glow_draw (open-rac-engine): one added quad of the comet's glow, facing along dir */
void func_L01_00397278(Vec4 *origin, u32 color, s32 alpha, f32 scale, f32 roll, s32 tex, s32 flags, Vec4 *dir)
{
    Quad_00397278 quad;
    f32 mat[16];
    f32 rot[4];
    Vec4 off;
    u32 col;

    func_L01_00396FD8_00397278((u8 *)&quad);
    quad.tex = func_00389598(tex);
    col = color + (alpha << 24);
    quad.prim = ((unsigned long)flags << 2) | 0x8000000040;
    quad.color[3] = col;
    quad.color[2] = col;
    quad.color[1] = col;
    quad.color[0] = col;
    quad.reg80 = 0xFF9000000260;
    quad.f70 = 0;
    rot[3] = 0.0f;
    rot[2] = func_0038D160(dir->v[0], dir->v[1]);
    rot[1] = -func_0038D160(func_0038CED8(dir), dir->v[2]);
    rot[0] = roll;
    func_0038D328(mat, rot);
    func_0038CF68_00397278(&off, dir, 0.025f);
    mat[12] = origin->v[0] + off.v[0];
    mat[15] = 1.0f;
    mat[13] = origin->v[1] + off.v[1];
    mat[14] = origin->v[2] + off.v[2];
    func_L01_00397060_00397278((f32 *)&quad, scale);
    func_003D2DA0(&quad, mat, 0);
}
/* localdecomp:end func_L01_00397278 */

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

/* localdecomp:start func_L01_0039A860 */
extern u8 D_L01_002A1BF0[];
void func_L01_0039A860(u8 *obj) {
    extern void func_L01_0039AEB8(u8 *, s32, s32, f32, f32, f32, s32, u32, u32);
    u8 *state = *(u8 **)(obj + 0x68);
    if (*(s32 *)(state + 0x1C)) {
        if (*(s32 *)(state + 0x10) < 4) {
            func_L01_0039AEB8(D_L01_002A1BF0, *(s32 *)(state + 0x10) * 7, *(s32 *)(state + 0x10) * 7, 0.06f, 0.11f, 0.2f, 10, 0x7F7F7F, 0xFF8040);
            func_L01_0039AEB8(D_L01_002A1BF0 + 0xA0, *(s32 *)(state + 0x10) * 3, *(s32 *)(state + 0x10) * 3, 0.05f, 0.095f, 0.2f, 10, 0x7F7F7F, 0xFF1010);
            func_L01_0039AEB8(D_L01_002A1BF0 + 0x140, *(s32 *)(state + 0x10) * 3, *(s32 *)(state + 0x10) * 3, 0.05f, 0.095f, 0.2f, 10, 0x7F7F7F, 0xFF1010);
        } else {
            func_L01_0039AEB8(D_L01_002A1BF0, 70, 70, 0.06f, 0.11f, 0.15f, 10, 0x7F7F7F, 0xFF8040);
            func_L01_0039AEB8(D_L01_002A1BF0 + 0xA0, 32, 32, 0.05f, 0.095f, 0.2f, 10, 0x7F7F7F, 0xFF1010);
            func_L01_0039AEB8(D_L01_002A1BF0 + 0x140, 32, 32, 0.05f, 0.095f, 0.2f, 10, 0x7F7F7F, 0xFF1010);
        }
    } else {
        func_L01_0039AEB8(D_L01_002A1BF0, 50, 50, 0.07f, 0.15f, 0.2f, 10, 0x7F7F7F, 0xFF8040);
        func_L01_0039AEB8(D_L01_002A1BF0 + 0xA0, 15, 15, 0.03f, 0.09f, 0.2f, 10, 0x7F7F7F, 0xFF1010);
        func_L01_0039AEB8(D_L01_002A1BF0 + 0x140, 15, 15, 0.03f, 0.09f, 0.2f, 10, 0x7F7F7F, 0xFF1010);
        func_L01_0039AEB8(D_L01_002A1BF0 + 0x1E0, 15, 15, 0.03f, 0.09f, 0.2f, 10, 0x7F7F7F, 0xFF1010);
    }
}
/* localdecomp:end func_L01_0039A860 */

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

/* localdecomp:start func_L01_0039BEF8 */
#include "vu0.h"
typedef int Q_0039BEF8 __attribute__((mode(TI)));
typedef struct { Q_0039BEF8 axis[2]; u8 pad[0x78]; s32 release; u8 *owner; s32 age, life, done, unused; } Effect_0039BEF8;
extern s32 D_L01_001DE0F0;
__asm__(".extern D_L01_001DE0F0, 4");
extern u8 D_L01_002A1E70[];
void func_L01_0039BEF8(u8 *owner, Q_0039BEF8 *end, s32 life) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    s32 i;
    u8 *p;
    for (i = 0; i < D_L01_001DE0F0; ++i) {
        p = D_L01_002A1E70 + i * 0xB0;
        if (*(u8 **)(p + 0x9C) == 0) {
            *(u8 **)(p + 0x9C) = owner;
            *(Q_0039BEF8 *)(p + 0x20) = *(Q_0039BEF8 *)(owner + 0x10);
            *(Q_0039BEF8 *)(p + 0x40) = *end;
            *(f32 *)(p + 0x20) += func_003824E0(-0.1f, 0.1f);
            *(f32 *)(p + 0x24) += func_003824E0(-0.1f, 0.1f);
            *(f32 *)(p + 0x28) += func_003824E0(-0.1f, 0.1f);
            *(f32 *)(p + 0x50) = func_003824E0(-3.1415927f, 3.1415927f);
            *(f32 *)(p + 0x54) = func_003824E0(-3.1415927f, 3.1415927f);
            *(f32 *)(p + 0x58) = func_003824E0(-3.1415927f, 3.1415927f);
            *(f32 *)(p + 0x74) = func_003824E0(-3.1415927f, 3.1415927f);
            *(f32 *)(p + 0x78) = func_003824E0(-3.1415927f, 3.1415927f);
            *(f32 *)(p + 0x7C) = func_003824E0(-3.1415927f, 3.1415927f);
            *(f32 *)(p + 0x5C) = func_L01_00443A18(0.001f, 0.005f);
            *(f32 *)(p + 0x60) = func_L01_00443A18(0.001f, 0.005f);
            *(f32 *)(p + 0x64) = func_L01_00443A18(0.001f, 0.005f);
            *(f32 *)(p + 0x80) = func_L01_00443A18(0.001f, 0.005f);
            *(f32 *)(p + 0x84) = func_L01_00443A18(0.001f, 0.005f);
            *(f32 *)(p + 0x88) = func_L01_00443A18(0.001f, 0.005f);
            *(f32 *)(p + 0x68) = func_003824E0(3.25f, 4.75f);
            *(f32 *)(p + 0x6C) = func_003824E0(3.25f, 4.75f);
            *(f32 *)(p + 0x70) = func_003824E0(3.25f, 4.75f);
            *(f32 *)(p + 0x8C) = func_003824E0(3.25f, 4.75f);
            *(f32 *)(p + 0x90) = func_003824E0(3.25f, 4.75f);
            *(f32 *)(p + 0x94) = func_003824E0(3.25f, 4.75f);
            { Effect_0039BEF8 *e = (Effect_0039BEF8 *)p;
            e->done = 0;
            qzero(p);
            e->age = life;
            qzero(p + 0x10);
            e->life = life;
            e->release = 17; }
            break;
        }
    }
}
/* localdecomp:end func_L01_0039BEF8 */

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

/* localdecomp:start func_L01_0039D6E0 */
#include "vu0.h"
void func_L01_0039D6E0(vu0_v4 *position) {
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern u8 *func_L01_0046B288(void *, u32, u32, f32, f32, s32);
    vu0_v4 offset;
    f32 angle, radius, size, life;
    s32 alpha;
    u8 *effect;
    s32 i=0;
    do {
        i--;
        angle=func_00382538();
        radius=func_003824E0(0.0f,0.6f);
        size=func_003824E0(0.0f,1.5f);
        life=func_003824E0(1.0f,5.0f);
        alpha=func_00382498(100,160);
        offset.x=func_0038D098(angle)*radius;
        offset.y=func_0038D0B0(angle)*radius;
        offset.z=0.0f;
        vec_add_ba(&offset,&offset,position);
        effect=func_L01_0046B288(&offset,0x5005C162,0x0005C162,size,life,alpha);
        if(effect) effect[3]=0x44;
    } while(i>=0);
}
/* localdecomp:end func_L01_0039D6E0 */

/* localdecomp:start func_L01_0039D818 */
u8 *func_L01_0039D818(void *owner, void *position, void *direction) {
    extern u8 *func_003C24B0(s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_L01_004C85C8(void *, s32, f32, f32, f32);
    extern void func_003C7C38(void *);
    u8 *object = func_003C24B0(0x1899, 0x80);
    u8 *state;
    if (object) {
        object[0x20] = 0;
        object[0x30] = *(u16 *)(object + 0x32) = 255;
        state = *(u8 **)(object + 0x68);
        *(s128_003985C0 *)(object + 0x10) = *(s128_003985C0 *)position;
        *(s128_003985C0 *)state = *(s128_003985C0 *)direction;
        object[0x23] = 40;
        *(f32 *)(object + 0x2c) = 0.0125f;
        *(f32 *)(state + 0x10) = func_003824E0(0.062831856f, 0.12566371f);
        *(f32 *)(state + 0x14) = func_003824E0(0.062831856f, 0.12566371f);
        *(void **)(state + 0x30) = owner;
        *(s32 *)(state + 0x18) = 0;
        *(s32 *)(state + 0x34) = func_L01_004C85C8(object, 0, 1.0f, 1.0f, 1.0f);
        func_003C7C38(object);
    }
    return object;
}
/* localdecomp:end func_L01_0039D818 */

LINKER_REMNANT("asm/levels", func_L01_0039D930);

/* localdecomp:start func_L01_0039D938 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x18];
    u8 *object;
    u8 pad1c[0xc];
    f32 height;
} Collision_0039D938;
extern Collision_0039D938 D_L01_001EAA00_0039D938;
extern f32 D_L01_001EAA28_0039D938[];
void func_L01_0039D938(u8 *object)
{
    extern s32 func_L01_0044C108(void *);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_L01_0044C998(void *, void *, void *, void *, void *, void *);
    extern void func_003C5278(Vec4 *, Vec4 *, Vec4 *, f32);
    extern s32 func_003D3CB0(Vec4 *, s32 *, s32, s32, s32);
    extern s32 func_003C4B50(void *);
    extern s32 func_003C4D58(void *);
    extern void func_L01_0044CB18(void *, void *, void *, void *, void *, void *);
    Vec4 bottom, top, zero;
    u8 *state = *(u8 **)(object + 0x68);
    Vec4 *position = (Vec4 *)(object + 0x10);
    s32 collided = 0;
    f32 ground;
    if (!func_L01_0044C108(position)) {
        func_L01_004450F0(object, 5, -1);
        return;
    }
    if (*(void **)(state + 0xc)) {
        qzero(&zero);
        func_L01_0044C998(object, *(void **)(state + 0xc), state + 0x60, &zero, position, &zero);
    }
    bottom = *position;
    func_003C5278(position, &bottom, &bottom, -0.5f);
    top = bottom;
    func_003C5278(position, &top, &top, 1.5f);
    if (func_003D3CB0(&bottom, (s32 *)&top, 2, (s32)object, 0)) {
        collided = 1;
        ground = D_L01_001EAA28_0039D938[0];
    } else {
        ground = top.v[2];
    }
    if (collided && D_L01_001EAA00_0039D938.object) {
        if (func_003C4B50(D_L01_001EAA00_0039D938.object)) {
            *(f32 *)(state + 0x10) = *(f32 *)(D_L01_001EAA00_0039D938.object + 0x10);
            *(f32 *)(object + 0x10) = *(f32 *)(state + 0x10);
            *(f32 *)(state + 0x14) = *(f32 *)(D_L01_001EAA00_0039D938.object + 0x14);
            *(f32 *)(object + 0x14) = *(f32 *)(state + 0x14);
            *(f32 *)(object + 0x18) = D_L01_001EAA00_0039D938.height;
            *(Vec4 *)(state + 0x10) = *(Vec4 *)(object + 0x10);
            func_003C5278((Vec4 *)(object + 0x10), (Vec4 *)(state + 0x10), (Vec4 *)(state + 0x10), -0.5f);
        } else if (!*(void **)(state + 0xc) && func_003C4D58(D_L01_001EAA00_0039D938.object)) {
            void *hit = D_L01_001EAA00_0039D938.object;
            *(void **)(state + 0xc) = hit;
            func_L01_0044CB18(object, hit, object + 0x10, object + 0xf0, state + 0x60, &zero);
        }
    }
    if (*(f32 *)(object + 0x18) <= ground) {
        *(f32 *)(object + 0x18) = ground;
        object[0xbc] = 0;
        *(s32 *)(state + 0x40) = 0;
    } else {
        object[0xbc] = 1;
        if (*(void **)(state + 0xc)) *(f32 *)(state + 0x68) -= *(f32 *)(state + 0x40);
        else *(f32 *)(object + 0x18) -= *(f32 *)(state + 0x40);
        *(f32 *)(state + 0x40) += 0.00392f;
        *(f32 *)(state + 0x40) = *(f32 *)(state + 0x40) > 0.3f ? 0.3f : *(f32 *)(state + 0x40);
    }
}
/* localdecomp:end func_L01_0039D938 */

/* localdecomp:start func_L01_0039DB90 */
extern vu0_v4 D_L01_001E29C0;
extern f32 D_001A4EC0[];
extern f32 D_L01_001DE19C, D_L01_001DE1A0, D_L01_001DE1B4, D_L01_001DE1B8;
extern s32 D_L01_001DE1A4, D_L01_001DE1A8, D_L01_001DE1AC, D_L01_001DE1B0;
__asm__(".extern D_L01_001DE19C, 4");
__asm__(".extern D_L01_001DE1A0, 4");
__asm__(".extern D_L01_001DE1B4, 4");
__asm__(".extern D_L01_001DE1B8, 4");
__asm__(".extern D_L01_001DE1A4, 4");
__asm__(".extern D_L01_001DE1A8, 4");
__asm__(".extern D_L01_001DE1AC, 4");
__asm__(".extern D_L01_001DE1B0, 4");
void func_L01_0039DB90(u8 *obj) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern s32 func_00382468(s32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038D890_0039DB90(vu0_v4 *, vu0_v4 *, vu0_v4 *, f32);
    extern void func_L01_0046C470(void *, void *, s32, f32, s32, s32, s32, s32, s32);
    vu0_v4 delta, axis, direction;
    u8 *state;
    s32 color;
    vec_sub_ab(&delta, &D_L01_001E29C0, obj + 0x10);
    state=*(u8 **)(obj+0x68);
    func_0038CE20((f32 *)&axis, D_001A4EC0, func_003824E0(D_L01_001DE19C * 0.020000001f, D_L01_001DE1A0 * 0.020000001f));
    func_0038D890_0039DB90((vu0_v4 *)&direction, (vu0_v4 *)&axis, (vu0_v4 *)&delta, func_00382538());
    if (state[0x47]) color = D_L01_001DE1B0;
    else color = D_L01_001DE1A8;
    func_L01_0046C470(obj+0x10, &direction, color, D_L01_001DE1B4, D_L01_001DE1A4, func_00382468(255)&255, 1, 64, 0);
    func_L01_0046C470(obj+0x10, &direction, D_L01_001DE1AC, D_L01_001DE1B8, D_L01_001DE1A4, func_00382468(255)&255, 1, 64, 0);
}
/* localdecomp:end func_L01_0039DB90 */

INCLUDE_ASM("asm/levels", func_L01_0039DCB8);

/* localdecomp:start func_L01_0039E018 */
extern void func_0038D890_0039E018(void *, void *, void *, f32);
extern void func_0038CF68_0039E018(void *, void *, f32);
extern u8 D_L01_001E2080_0039E018[8];

void func_L01_0039E018(u8 *obj, f32 *out, s32 idx) {
    vu0_v4 v;
    u8 *d = *(u8 **)(obj + 0x68);
    u8 *p;

    func_0038D890_0039E018(&v, D_L01_001E2080_0039E018 + idx * 16, d + 0x20, *(f32 *)(d + 0x2C));
    p = *(u8 **)(d + (idx << 2) + 0x30);
    if (p != 0 && obj[0x20] == 2) {
        func_0038CF68_0039E018(&v, &v, *(f32 *)(p + 0x28));
    }
    vec_add_ab(out, d + 0x10, &v);
    out[2] += *(f32 *)d;
}
/* localdecomp:end func_L01_0039E018 */

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
