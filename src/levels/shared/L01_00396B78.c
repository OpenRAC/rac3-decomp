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

/* localdecomp:start func_L01_00396B78 */
#include "vu0.h"
typedef int u128_00396B78 __attribute__((mode(TI)));
typedef struct { s32 v[2]; } Pair8_00396B78;
extern void func_003A52A0(s32, s32, void *);
extern void func_0038CF68_00396B78(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_00382538(void);
extern s32 func_0013D3E0(void);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00472238(void *, void *, s32, s32, f32);
extern s32 func_L01_00472560(void *, void *, s32, f32, s32);
extern Pair8_00396B78 D_L01_001DE0C8_00396B78[];

void func_L01_00396B78(u8 *m, s32 unused, void *pos, void *dir) {
    extern void func_0038CE20_00396B78(void *, void *, f32);
    extern void func_0038D890_00396B78(void *, void *, void *, f32);
    u8 *vars = *(u8 **)(m + 0x68);
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 v2;
    vu0_v4 v3;
    Pair8_00396B78 tbl;
    vu0_v4 v4;
    s32 i;
    f32 f;

    func_003A52A0(0, 0, m);
    func_0038CF68_00396B78(&v0, dir, 2.0f);
    vec_add_ab(&v0, &v0, pos);
    func_0038CE90(&v3, pos, &v0);
    func_0038CF68_00396B78(&v1, dir, 0.15f);
    vec_add_ba(&v1, pos, &v1);
    func_0038CF68_00396B78(&v3, &v3, 1.0f);
    func_0038CE20_00396B78(&v2, dir, 0.0009765625f);
    func_0038CF68_00396B78(&v2, &v2, 1.0f);
    tbl = D_L01_001DE0C8_00396B78[0];
    f = func_00382538();
    for (i = 23; i >= 0; i--) {
        func_0038D890_00396B78(&v4, &v3, dir, f);
        func_L01_00472238(&v1, &v4, tbl.v[func_0013D3E0() % 2], 17, 0.050000004f);
        f = func_0038DAB8(f, 0.27318197f);
    }
    for (i = 0; i < 24; i++) {
        f32 t = (f32)i / 23.0f * 1.5f;
        func_L01_00472560(pos, &v2, tbl.v[func_0013D3E0() % 2], t, func_00382498(25, 42));
    }
    *(u128_00396B78 *)vars = *(u128_00396B78 *)&v2;
}
/* localdecomp:end func_L01_00396B78 */

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
extern void func_L01_00397278_00396E08(Vec4 *, u32, s32, f32, f32, s32, s32, Vec4 *);
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
            func_L01_00397278_00396E08(&object->position, 0x103080, data->timer, scale * factor, zero, 11, 2, &data->vector40);
            func_L01_00397278_00396E08(&object->position, 0x3F3F3F, data->timer, object->scale * factor * 0.75f, zero, 11, 2, &data->vector40);
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

/* localdecomp:start func_L01_003970C8 */
typedef struct { f32 x, y, z; } V3_003970C8;
typedef struct {
    f32 verts[4][4];
    u32 color[4];
    f32 uv[8];
    unsigned long f70;
    unsigned long tex;
    unsigned long reg80;
    unsigned long prim;
} Quad_003970C8;
extern f32 D_L01_001E2880[];
extern void func_L01_00396FD8_003970C8(u8 *p);
extern void func_L01_00397060_003970C8(f32 *m, f32 s);
extern unsigned long func_00389598(int tex);
extern f32 func_0038D160(f32 a, f32 b);
extern f32 func_0038CF38(void *, void *);
extern void func_0038D328(f32 *mat, f32 *rot);
extern void func_0038CF68_003970C8(f32 *dst, f32 *src, f32 s);
extern void func_003D2DA0_003970C8(Quad_003970C8 *quad, f32 *mat, int a);
void func_L01_003970C8(V3_003970C8 *origin, u32 color, u32 alpha, int tex, int flags, f32 scale, f32 roll, f32 offset)
{
    Quad_003970C8 quad;
    f32 mat[16];
    f32 rot[4];
    vu0_v4 off;
    u32 col;
    f32 *cam;

    func_L01_00396FD8_003970C8((u8 *)&quad);
    quad.tex = func_00389598(tex);
    cam = D_L01_001E2880;
    col = color + (alpha << 24);
    quad.prim = ((long)flags << 2) | 0x8000000040;
    quad.reg80 = 0xFF9000000260;
    quad.color[3] = col;
    quad.color[2] = col;
    quad.color[1] = col;
    quad.color[0] = col;
    quad.f70 = 0;
    rot[3] = 0.0f;
    rot[2] = func_0038D160(cam[0x50] - origin->x, cam[0x51] - origin->y);
    rot[1] = -func_0038D160(func_0038CF38(origin, &cam[0x50]), cam[0x52] - origin->z);
    rot[0] = roll;
    func_0038D328(mat, rot);
    vec_sub_ba(&off, &cam[0x50], (f32 *)origin);
    func_0038CF68_003970C8((f32 *)&off, (f32 *)&off, offset);
    mat[12] = origin->x + off.x;
    mat[13] = origin->y + off.y;
    mat[14] = origin->z + off.z;
    mat[15] = 1.0f;
    func_L01_00397060_003970C8((f32 *)&quad, scale);
    func_003D2DA0_003970C8(&quad, mat, 0);
}
/* localdecomp:end func_L01_003970C8 */

/* localdecomp:start func_L01_00397278 */
typedef struct { f32 x, y, z; } V3_00397278;
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
extern unsigned long func_00389598(int tex);
extern f32 func_0038D160(f32 a, f32 b);
extern f32 func_0038CED8(f32 *v);
extern void func_0038D328(f32 *mat, f32 *rot);
extern void func_0038CF68_00397278(f32 *dst, f32 *src, f32 s);
extern void func_003D2DA0(Quad_00397278 *quad, f32 *mat, int a);
/* agent_comet_glow_draw: one added quad of the comet's glow, facing along dir */
void func_L01_00397278(V3_00397278 *origin, u32 color, u32 alpha, int tex, int flags, f32 *dir, f32 scale, f32 roll)
{
    Quad_00397278 quad;
    f32 mat[16];
    f32 rot[4];
    V3_00397278 off;
    u32 col;

    func_L01_00396FD8_00397278((u8 *)&quad);
    quad.tex = func_00389598(tex);
    col = color + (alpha << 24);
    quad.prim = ((long)flags << 2) | 0x8000000040;
    quad.color[3] = col;
    quad.color[2] = col;
    quad.color[1] = col;
    quad.color[0] = col;
    quad.reg80 = 0xFF9000000260;
    quad.f70 = 0;
    rot[3] = 0.0f;
    rot[2] = func_0038D160(dir[0], dir[1]);
    rot[1] = -func_0038D160(func_0038CED8(dir), dir[2]);
    rot[0] = roll;
    func_0038D328(mat, rot);
    /* 0.025: how far the glow sits ahead along dir */
    func_0038CF68_00397278((f32 *)&off, dir, 0.025f);
    mat[12] = origin->x + off.x;
    mat[15] = 1.0f;
    mat[13] = origin->y + off.y;
    mat[14] = origin->z + off.z;
    func_L01_00397060_00397278((f32 *)&quad, scale);
    func_003D2DA0(&quad, mat, 0);
}
/* localdecomp:end func_L01_00397278 */

/* localdecomp:start func_L01_003973F8 */
#include "vu0.h"
typedef union { vu0_q q; f32 f[4]; } V_310DB8;
typedef struct {
    V_310DB8 pos[4];
    u32 color[4];
    f32 uv[4][2];
    u8 tail[0x20];
} Poly_310DB8;
extern vu0_v4 D_L01_001E29C0;
void func_L01_003973F8(Vec4 *start_,Vec4 *points_,f32 phase,u32 color,s32 count,f32 width,f32 step)
{
    V_310DB8 *start=(V_310DB8 *)start_;
    V_310DB8 *points=(V_310DB8 *)points_;
    extern void func_003D93B0(void *,s32,s32,s32);
    extern s32 func_0013D3E0(void);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_0038CE90(void *,void *,void *);
    extern void func_0038CE20(f32 *,f32 *,f32);
    extern void func_0038D028(void *,void *,void *);
    extern void func_003D2DA0_003973F8(void *,s32,s32);
    V_310DB8 origin;
    Poly_310DB8 outer,inner;
    V_310DB8 matrix[4];
    V_310DB8 offset,offset2;
    s32 i,next;
    s32 bytes;
    f32 u,v,u2,v2;
    origin.q=start->q;
    start=&origin;
    func_003D93B0(&outer,43,1,128);
    func_003D93B0(&inner,43,1,128);
    offset2.q=offset.q=0;
    width*=0.25f;
    outer.color[0]=outer.color[1]=color;
    inner.color[0]=inner.color[1]=color;
    outer.color[2]=outer.color[3]=color;
    inner.color[2]=inner.color[3]=color;
    offset.f[3]=1.0f;
    offset2.f[3]=1.0f;
    offset.f[2]=width;
    offset2.f[2]=width+width;
    if ((func_0013D3E0()&1)==0) {
        outer.uv[0][0]=phase+0.0f;
        outer.uv[0][1]=0.0f;
        outer.uv[1][0]=phase+0.0f;
        outer.uv[1][1]=1.0f;
        outer.uv[2][0]=step+phase;
        outer.uv[2][1]=0.0f;
        outer.uv[3][0]=step+phase;
        outer.uv[3][1]=1.0f;
        inner.uv[0][0]=phase+0.0f;
        inner.uv[0][1]=0.0f;
        inner.uv[1][0]=phase+0.0f;
        inner.uv[1][1]=1.0f;
        inner.uv[2][0]=step+phase;
        inner.uv[2][1]=0.0f;
        inner.uv[3][0]=step+phase;
        inner.uv[3][1]=1.0f;
    } else {
        outer.uv[0][0]=phase+0.0f;
        outer.uv[0][1]=1.0f;
        outer.uv[1][0]=phase+0.0f;
        outer.uv[1][1]=0.0f;
        outer.uv[2][0]=step+phase;
        outer.uv[2][1]=1.0f;
        outer.uv[3][0]=step+phase;
        outer.uv[3][1]=0.0f;
        inner.uv[0][0]=phase+0.0f;
        inner.uv[0][1]=1.0f;
        inner.uv[1][0]=phase+0.0f;
        inner.uv[1][1]=0.0f;
        inner.uv[2][0]=step+phase;
        inner.uv[2][1]=1.0f;
        inner.uv[3][0]=step+phase;
        inner.uv[3][1]=0.0f;
    }
    vec_sub_ba(&matrix[0],points,start);
    func_0038CF68(&matrix[0],&matrix[0],1.0f);
    vec_sub_ba(&matrix[1],&D_L01_001E29C0,start);
    func_0038CE90(&matrix[2],&matrix[1],&matrix[0]);
    i=0;
    bytes=count<<4;
    func_0038CF68(&matrix[2],&matrix[2],1.0f);
    func_0038CE90(&matrix[1],&matrix[0],&matrix[2]);
    matrix[3].q=start->q;
    outer.pos[0].q=offset.q;
    inner.pos[0].q=offset2.q;
    func_0038CE20(outer.pos[1].f,outer.pos[0].f,-1.0f);
    func_0038CE20(inner.pos[1].f,inner.pos[0].f,-1.0f);
    func_0038D028(&outer.pos[0],&outer.pos[0],matrix);
    func_0038D028(&outer.pos[1],&outer.pos[1],matrix);
    func_0038D028(&inner.pos[0],&inner.pos[0],matrix);
    func_0038D028(&inner.pos[1],&inner.pos[1],matrix);
    while (i<count-1) {
        next=i+1;
        vec_sub_ab(&matrix[0],points+i+1,points+i);
        func_0038CF68(&matrix[0],&matrix[0],1.0f);
        vec_sub_ab(&matrix[1],&D_L01_001E29C0,points+i);
        func_0038CE90(&matrix[2],&matrix[1],&matrix[0]);
        func_0038CF68(&matrix[2],&matrix[2],1.0f);
        func_0038CE90(&matrix[1],&matrix[0],&matrix[2]);
        offset.f[2]*=0.7f;
        matrix[3].q=points[i].q;
        offset2.f[2]=offset.f[2]+offset.f[2];
        outer.pos[2].q=offset.q;
        inner.pos[2].q=offset2.q;
        func_0038CE20(outer.pos[3].f,outer.pos[2].f,-1.0f);
        func_0038CE20(inner.pos[3].f,inner.pos[2].f,-1.0f);
        func_0038D028(&outer.pos[2],&outer.pos[2],matrix);
        func_0038D028(&outer.pos[3],&outer.pos[3],matrix);
        func_0038D028(&inner.pos[2],&inner.pos[2],matrix);
        func_0038D028(&inner.pos[3],&inner.pos[3],matrix);
        u=step*(f32)next; v=u+step;
        if (u>=1.0f) {u-=1.0f;v-=1.0f;}
                outer.uv[0][0]=u+phase;outer.uv[1][0]=u+phase;
        outer.uv[2][0]=v+phase;outer.uv[3][0]=v+phase;
        inner.uv[0][0]=u+phase;inner.uv[1][0]=u+phase;
        inner.uv[2][0]=v+phase;inner.uv[3][0]=v+phase;
        func_003D2DA0_003973F8(&outer,0,0);
        func_003D2DA0_003973F8(&inner,0,0);
        if (i!=0) {
            outer.color[0]=outer.color[1]=color|0x7F000000;
            inner.color[0]=inner.color[1]=color|0x3F000000;
        }
        i=next;
        outer.pos[0].q=outer.pos[2].q;
        outer.pos[1].q=outer.pos[3].q;
        inner.pos[0].q=inner.pos[2].q;
        inner.pos[1].q=inner.pos[3].q;
        outer.color[2]=outer.color[3]=color|0x7F000000;
        inner.color[2]=inner.color[3]=color|0x3F000000;
    }
    matrix[3].q=((V_310DB8 *)(bytes+(s32)points))[-1].q;
    offset.f[2]*=0.7f;
    offset2.f[2]=offset.f[2]+offset.f[2];
    inner.pos[2].q=offset2.q;
    outer.pos[2].q=offset.q;
    func_0038CE20(outer.pos[3].f,outer.pos[2].f,-1.0f);
    func_0038CE20(inner.pos[3].f,inner.pos[2].f,-1.0f);
    func_0038D028(&outer.pos[2],&outer.pos[2],matrix);
    func_0038D028(&outer.pos[3],&outer.pos[3],matrix);
    func_0038D028(&inner.pos[2],&inner.pos[2],matrix);
    func_0038D028(&inner.pos[3],&inner.pos[3],matrix);
    u2=step*(f32)(i+1);v2=u2+step;
    outer.color[2]=outer.color[3]=color;
    inner.color[2]=inner.color[3]=color;
    if (u2>=1.0f) {u2-=1.0f;v2-=1.0f;}
    outer.uv[0][0]=u2+phase;outer.uv[1][0]=u2+phase;
    outer.uv[2][0]=v2+phase;outer.uv[3][0]=v2+phase;
    inner.uv[0][0]=u2+phase;inner.uv[1][0]=u2+phase;
    inner.uv[2][0]=v2+phase;inner.uv[3][0]=v2+phase;
    func_003D2DA0_003973F8(&outer,0,0);
    func_003D2DA0_003973F8(&inner,0,0);
}
/* localdecomp:end func_L01_003973F8 */

INCLUDE_ASM("asm/levels", func_L01_00397A28);

/* localdecomp:start func_L01_00397E98 */
typedef struct {
    f32 target[3];
    s32 owner;
    u8 *moby;
    u8 pad14[4];
    f32 speed;
    u8 pad1C[8];
    s16 timer;
    u8 armed;
    u8 frames;
    u8 pad28[4];
    s32 trail;
    vu0_v4 dir;
    u8 pad40[0x10];
    s32 sound;
} Vars_00397E98;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 state;
    u8 pad21[0x47];
    Vars_00397E98 *vars;
    u8 pad6C[0x3E];
    s16 oclass;
    u8 padAC[0xC];
    s32 bB8;
    u8 kind;
    u8 padBD[3];
    vu0_v4 mat[3];
} Moby_00397E98;
typedef struct {
    vu0_v4 vel;
    Moby_00397E98 *moby;
    u32 flags;
    u8 b18;
    u8 b19;
    u16 oclass;
    f32 f1C;
    s32 i20;
} Hit_00397E98;
typedef struct {
    u8 pad0[0x18];
    Moby_00397E98 *object;
    s32 count;
    vu0_v4 hit;
    u8 pad30[0x10];
    vu0_v4 normal;
} Coll_00397E98;
typedef struct {
    u8 b0;
    u8 level;
    u8 pad2[0x6A];
    f32 f6C;
    u8 pad70[0x80];
} Row_00397E98;
extern Coll_00397E98 D_L01_001EAA00;
extern s32 D_L01_001D673C;
extern Moby_00397E98 *D_001A71A0[];
extern s32 D_001A6290[];
extern u8 D_L01_002A19F0[];
extern u8 D_001425C0_00397E98[];
extern Ent_003985C0 D_L01_002C5600[];
extern Row_00397E98 D_L01_002C5600_00397E98[];
extern u8 D_L01_001E2A40[];
typedef struct { f32 x, y, z, w; u8 pad[0x450]; } Pl_00397E98;
extern Pl_00397E98 D_L01_001E2A40_00397E98[];
extern s32 D_001D52F0;
extern u8 *D_L01_00221098_00397E98[];
extern vu0_v4 D_L01_001E29C0;
extern u8 D_L01_001D66B0[8];
extern u8 D_L01_001E0140[8];
extern u8 D_001A4C60[];
extern void func_003C5180(void *, void *, s32);
extern void func_L01_004471A8(void *, f32);
extern s32 func_L01_004CB2D8(void);
extern void func_L01_004CAB30(void *, void *);
extern f32 *func_00382348_00397E98(void *);
extern void func_0038CE20(f32 *, f32 *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_0038CF68_00397E98(void *, void *, f32);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern f32 func_0038CF00(void *, void *);
extern s32 func_003D3CB0_00397E98(void *, void *, s32, void *, void *);
extern void func_L01_004C8688(s32, void *, s32);
extern void func_L01_00399D78(u8 *a0, u8 *a1);
extern void func_L01_00404A10_00397E98(void *, void *);
extern void func_L01_00399DE8(u8 *a0);
extern void func_L01_00399B18();
extern void func_L01_00446978(void *, void *);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);
extern u8 *func_L01_00344A88(void *, void *, u8, u8, u8, u8, u16, f32, f32, f32, f32, void *, s32, s32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_003298C8(void *, void *, s32, s32, s32, u32, s32, s32, s32, s32, f32, f32);
extern u8 *func_L01_004713C8_00397E98(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
extern s32 func_00382468(s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_003C3D30(void *, s32, s32, f32);
extern void func_L01_004C7D98(void *, void *);
extern u8 *func_L01_0046B458(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern void func_L01_00470C78(void *, s32, f32, f32, s32, s32, s32, void *, s32, s32, s32, s32);
extern void func_0038D000(void *, void *, void *);
extern u8 *func_L01_0031E788(u8 *, float *, s32, s32, s32);
extern void func_L01_00399A50();
extern void func_L01_0044BEC8(void *, void *);
extern void func_L01_004C8668(s32);
extern void func_003C2880(void *);
extern s32 func_0038CB00(void *);
extern f32 func_0038CF38(void *, void *);

void func_L01_00397E98(Moby_00397E98 *m) {
    Vars_00397E98 *vars;
    Moby_00397E98 *target;
    vu0_v4 old;
    vu0_v4 up;
    vu0_v4 aim;
    vu0_v4 vel;
    vu0_v4 to_aim;
    vu0_v4 to_me;
    vu0_v4 axis;
    vu0_v4 side;
    vu0_v4 rot;
    Hit_00397E98 hit;
    vu0_v4 v150;
    vu0_v4 v160;
    vu0_v4 mat[3];
    vu0_v4 at;
    vu0_v4 dir;
    Moby_00397E98 *owner;
    s32 found;
    s32 level;
    vu0_v4 *trail;
    f32 *info;
    f32 len_aim, len_me, a, t;
    s32 i;
    s32 j, k;
    u8 *p;
    s32 n;
    f32 heading;

    vars = m->vars;
    target = vars->moby;
    *(vu0_q *)&old = *(vu0_q *)&m->pos;
    owner = 0;
    func_003C5180(&m->pos, &up, 1);
    func_L01_004471A8(m, 0.75f);
    if (func_L01_004CB2D8() != 0) {
        func_L01_004CAB30(&m->pos, &m->pos);
    }
    if (target != 0) {
        info = func_00382348_00397E98(target);
        if (target->state == 0xFE) {
            goto lost;
        } else if (target->state == 0xFD) {
            goto lost;
        } else if (info != 0 && info[0] <= 0.0f) {
        lost:
            vars->moby = 0;
            target = 0;
        } else {
            *(vu0_q *)&aim = *(vu0_q *)&target->pos;
            if (info != 0) {
                func_0038CE20((f32 *)&vel, (f32 *)&target->mat[2], info[4]);
                vec_add_ab(&aim, &aim, &vel);
            }
        }
    }
    found = 0;
    if (target != 0 && vars->timer < 0x128 && (s8)target->state >= 0 && vars->armed != 0) {
        vel.x = vars->target[0];
        vel.y = vars->target[1];
        vel.z = vars->target[2];
        vel.w = 0.0f;
        vec_sub_ba(&to_aim, &aim, &vel);
        len_aim = func_0038CEA8(&to_aim);
        vec_sub_ba(&to_me, &m->pos, &aim);
        len_me = func_0038CEA8(&to_me);
        if (len_me != 0.0f && len_aim != 0.0f) {
            a = 1.5707964f - func_0038D0C8(func_0038CE68(&to_me, &to_aim) / (len_me * len_aim));
            func_0038CE90(&axis, &to_aim, &to_me);
            func_0038CE90(&side, &to_aim, &axis);
            if (func_0038CE68(&to_me, &side) < 0.0f) {
                a = -a;
            }
            t = a;
            a = len_aim / vars->speed;
            a *= func_0038D0B0(t);
            if (100.0f < fabs_asm(a)) {
                a = 0.0f;
            }
            while (1.0f < a) {
                a -= 1.0f;
            }
            while (a < -1.0f) {
                a += 1.0f;
            }
            a = func_0038D0C8(a);
            func_0038CE20((f32 *)&to_me, (f32 *)&to_me, -1.0f);
            func_0038CF68_00397E98(&to_me, &to_me, 1.0f);
            if (1e-05f < fabs_asm(a)) {
                func_0038CF68_00397E98(&rot, &axis, 1.0f);
                func_003C4840(&rot, &rot, a);
                func_0038D850(&m->mat[0], &to_me, &rot);
                func_0038CE90(&m->mat[1], &m->mat[0], &up);
                func_0038CF68_00397E98(&m->mat[1], &m->mat[1], 1.0f);
                func_0038CE90(&m->mat[2], &m->mat[1], &m->mat[0]);
                *(vu0_q *)&vars->dir = *(vu0_q *)&m->mat[0];
            }
            if (func_0038CF00(&aim, &m->pos) <= vars->speed
                && func_003D3CB0_00397E98(&m->pos, &aim, 0x12, D_001A71A0[0], 0) == 0) {
                *(vu0_q *)&D_L01_001EAA00.hit = *(vu0_q *)&aim;
                D_L01_001EAA00.count = -1;
                found = 1;
                D_L01_001EAA00.object = target;
            }
        }
    } else if (D_L01_001D673C == 0 || D_001A6290[0] <= 0) {
        func_L01_004C8688(vars->sound, &vars->dir, 0);
        *(vu0_q *)&m->mat[0] = *(vu0_q *)&vars->dir;
        func_0038CE90(&m->mat[1], &m->mat[0], &up);
        func_0038CF68_00397E98(&m->mat[1], &m->mat[1], 1.0f);
        func_0038CE90(&m->mat[2], &m->mat[1], &m->mat[0]);
    }
    if (target != 0) {
        vars->target[0] = aim.x;
        vars->target[1] = aim.y;
        vars->target[2] = aim.z;
    }
    m->mat[0].w = m->mat[1].w = m->mat[2].w = 0.0f;
    func_0038CE20((f32 *)&vel, (f32 *)&m->mat[0], vars->speed);
    vec_add_ab(&m->pos, &m->pos, &vel);
    if (target != 0 && target->oclass == 0xCEA) {
        vec_sub_ba(&to_aim, &aim, &m->pos);
        if (func_0038CE68(&to_aim, &m->mat[0]) < 0.0f) {
            vars->moby = 0;
            target = 0;
            found = 0;
        }
    }
    if (m->pos.x < 2.0f || 1021.0f < m->pos.x
        || m->pos.y < 2.0f || 1021.0f < m->pos.y
        || m->pos.z < 2.0f || 1021.0f < m->pos.z
        || m->kind == 3) {
        goto kill;
    }
    func_L01_00399D78((u8 *)m, (u8 *)&to_aim);
    trail = (vu0_v4 *)(D_L01_002A19F0 + vars->trail * 64);
    {
        s32 j;
        for (j = 3; j > 0; j--) {
            *(vu0_q *)&trail[j] = *(vu0_q *)&trail[j - 1];
        }
    }
    *(vu0_q *)&trail[0] = *(vu0_q *)&to_aim;
    if (++vars->frames > 3) {
        func_L01_00404A10_00397E98(func_L01_00399DE8, m);
    }
    func_L01_00399B18(m, &old);
    *(vu0_q *)&to_me = *(vu0_q *)&m->pos;
    func_0038CE20((f32 *)&axis, (f32 *)&up, -0.25f);
    vec_add_ab(&axis, &m->pos, &axis);
    if (func_003D3CB0_00397E98(&to_me, &axis, 2, 0, 0) != 0) {
        func_0038CE20((f32 *)&to_me, (f32 *)&up, 0.25f);
        vec_add_ab(&m->pos, &D_L01_001EAA00.hit, &to_me);
    }
    hit.flags = 0x1130000;
    *(vu0_q *)&hit.vel = *(vu0_q *)&vel;
    hit.moby = m;
    hit.f1C = (D_L01_002C5600_00397E98 + D_001425C0_00397E98[0x3F])->f6C;
    hit.i20 = 1;
    func_0038CF68_00397E98(&hit.vel, &hit.vel, 1.5f);
    hit.vel.w = 5627.925f;
    hit.b18 = 3;
    hit.b19 = 1;
    hit.oclass = m->oclass;
    level = (D_L01_002C5600_00397E98 + D_001425C0_00397E98[0x3F])->level;
    if (found == 0) {
        if (func_003D3CB0_00397E98(&old, &m->pos, 0, D_001A71A0[0], &hit) == 0) {
            goto no_hit;
        }
    } else if (target != 0) {
        func_L01_00446978(target, &hit);
    }
    if (D_L01_001EAA00.object != 0) {
        if (D_L01_001EAA00.object != D_001A71A0[0] && D_L01_001EAA00.object != (Moby_00397E98 *)vars->owner) {
            owner = m;
            m->kind = 2;
            *(vu0_q *)&m->pos = *(vu0_q *)&D_L01_001EAA00.hit;
        }
    } else if (D_L01_001EAA00.count > 0) {
        m->kind = 1;
        *(vu0_q *)&m->pos = *(vu0_q *)&D_L01_001EAA00.hit;
    }
    if (level >= 4) {
        func_0038CF68_00397E98(&rot, &D_L01_001EAA00.normal, 1.0f);
        vec_add_ab(&side, &D_L01_001EAA00.hit, &rot);
        func_L01_003303B8(&side, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 1.5f, 0.0f, 0.0f, 2.0f,
                          D_L01_001D673C == 0, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7,
                          0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        heading = func_0038D160((D_L01_001E2A40_00397E98 + D_001D52F0)->x - m->pos.x,
                                (D_L01_001E2A40_00397E98 + D_001D52F0)->y - m->pos.y);
        for (j = 6; j >= 0; j--) {
            f32 a, r, s, u;
            Row_00397E98 *w;
            a = func_0038DAB8(heading, func_L01_00443A18(0.0f, 1.3962634f));
            v150.x = func_0038D098(a) * func_003824E0(0.1f, 0.2f);
            v150.y = func_0038D0B0(a) * func_003824E0(0.1f, 0.2f);
            v150.z = 0.0f;
            v150.z = func_003824E0(-0.5f, 8.0f) * 0.020000001f;
            side.x += func_003824E0(-0.4f, 0.4f);
            side.y += func_003824E0(-0.4f, 0.4f);
            side.z += func_003824E0(-0.4f, 0.4f);
            r = func_003824E0(1.0f, 3.0f);
            s = func_003824E0(15.0f, 20.0f);
            u = func_003824E0(0.7f, 0.9f);
            w = D_L01_002C5600_00397E98 + D_001425C0_00397E98[0x3F];
            func_L01_00344A88(&side, &v150, 0x32, 0x64, 1, 0, 0x12C, r, s, u, w->f6C * 0.2f, m, 1, 0);
        }
        for (j = 0; j < 2; j++) {
            f32 r, s;
            r = func_003824E0(0.08726646f, 0.5235988f);
            s = func_00382538();
            func_00382760(&v150, func_003824E0(8.0f, 15.0f) * 0.020000001f, s, r);
            func_L01_003298C8(&m->pos, &v150, func_00382498(0x53, 0x6C), 2, 1, 0x80404040, 0, 1, 0x32, 0x78, 2.5f, 14.6f);
        }
        for (k = 14; k >= 0; k--) {
            f32 a, u, z;
            s32 n, life;
            n = (s32)func_L01_00443A18(2.0f, 6.0f);
            v150.x = m->pos.x + func_003824E0(-0.2f, 0.2f);
            v150.y = m->pos.y + func_003824E0(-0.2f, 0.2f);
            v150.z = m->pos.z + func_003824E0(-0.2f, 0.2f);
            z = func_003824E0(0.175f, 0.35f);
            u = func_003824E0(7.0f, 10.0f);
            a = func_0038DAB8(heading, func_L01_00443A18(0.0f, 1.3962634f));
            u *= 0.020000001f;
            v160.x = func_0038D098(a) * u;
            v160.y = func_0038D0B0(a) * u;
            v160.z = 0.0f;
            v160.z = func_003824E0(0.0f, 12.0f) * 0.020000001f;
            life = func_00382498(0x5A, 0x96);
            p = func_L01_004713C8_00397E98(&v150, &v160, (life * 5 + 2) / 6, 0x273538, n, 0x7F, 0x7F, z * 210000.0f, z * 210000.0f, 0.00584f, 1);
            if (p != 0) {
                p[2] = D_L01_00221098_00397E98[97][func_00382468(3) + 10];
                p[3] = 0x44;
            }
        }
    }
no_hit:
    if (m->kind != 0) {
        if ((D_L01_002C5600_00397E98 + D_001425C0_00397E98[0x3F])->level >= 4) {
            func_003A52A0(1, 0, m);
        } else {
            func_003A52A0(0, 0, m);
        }
        func_003C5180(&m->pos, &v150, 1);
        n = 1;
        if (D_L01_001EAA00.object != 0 && D_L01_001EAA00.count <= 0) {
            vec_sub_ab(&v160, &D_L01_001E29C0, &m->pos);
            func_0038CF68_00397E98(&v160, &v160, 1.0f);
        } else {
            func_0038CF68_00397E98(&v160, &D_L01_001EAA00.normal, 1.0f);
            if (0.1f <= fabs_asm(func_0038CE68(&v160, &v150))) {
                n = 0;
            }
        }
        if (n != 0) {
            func_003C3D30(&m->pos, 0, 0, 0.5f);
        }
        func_L01_004C7D98(&m->pos, &mat[2]);
        side.y = side.x = mat[2].z;
        side.z = -(mat[2].x + mat[2].y);
        func_0038CF68_00397E98(&mat[0], &side, 1.0f);
        func_0038CE90(&mat[1], &mat[0], &mat[2]);
        mat[0].w = mat[1].w = mat[2].w = 0.0f;
        if (level == 0) {
            func_L01_003303B8(&m->pos, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 0.6f, 0.0f, 0.0f, 2.0f,
                              0, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7,
                              0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        } else if (level == 1) {
            func_L01_003303B8(&m->pos, 1, 0x19, 0x14, 0x14, 0x14, 0x23, 2, 1.0f, 0.0f, 0.0f, 2.0f,
                              0, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7,
                              0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            vec_sub_ba(&rot, &D_L01_001E2A40, &m->pos);
            func_0038CF68_00397E98(&rot, &rot, 0.5f);
            vec_add_ab(&at, &m->pos, &rot);
            func_L01_0046B458(&at, 0x1C, 10.5f, 0.1f, 0xBFFF4020, 2, 1, D_L01_001D66B0, 0.0f, 1);
            func_L01_0046B458(&at, 0x1C, 7.5f, 0.1f, 0xBFFF8040, 2, -1, D_L01_001D66B0, 0.0f, 1);
            func_L01_0046B458(&at, 0x1C, 5.25f, 0.1f, 0xC0FF8080, 2, 1, D_L01_001D66B0, 0.0f, 1);
            func_L01_0046B458(&at, 0x1C, 3.75f, 0.1f, 0xB0FF8080, 2, -1, D_L01_001D66B0, 0.0f, 1);
            func_L01_00470C78(&at, 0x21, 3.6f, 1.4f, 0x46787878, 2, 2, D_L01_001D66B0, 0, 2, 6, 1);
            func_L01_00470C78(&at, 0x21, 6.8f, 1.4f, 0x46787878, 2, -1, D_L01_001D66B0, 1, 2, 6, 1);
            func_L01_00470C78(&at, 0x21, 8.0f, 3.0f, 0x2D787878, 2, 1, D_L01_001D66B0, 1, 2, 6, 1);
            for (i = 0; i < 4; i++) {
                f32 r, s;
                u8 *q;
                r = func_00382538();
                s = func_003824E0(0.87266463f, 1.5707964f);
                func_00382760(&dir, func_003824E0(4.0f, 9.0f) * 0.020000001f, r, s);
                dir.w = 0.0f;
                func_0038D000(&dir, &dir, mat);
                q = func_L01_0031E788((u8 *)&m->pos, (f32 *)&dir, i, 0, 1);
                if (q != 0) {
                    *(s32 *)(q + 0xB8) = m->bB8;
                }
            }
        } else if (level == 2) {
            func_L01_003303B8(&m->pos, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 1.0f, 0.0f, 0.0f, 2.0f,
                              0, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7,
                              0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            vec_sub_ba(&rot, &D_L01_001E2A40, &m->pos);
            func_0038CF68_00397E98(&rot, &rot, 0.5f);
            vec_add_ab(&at, &m->pos, &rot);
            func_L01_0046B458(&at, 0x1C, 10.5f, 0.1f, 0xBFFF4020, 2, 1, D_L01_001D66B0, 0.0f, 1);
            func_L01_0046B458(&at, 0x1C, 7.5f, 0.1f, 0xBFFF8040, 2, -1, D_L01_001D66B0, 0.0f, 1);
            func_L01_0046B458(&at, 0x1C, 5.25f, 0.1f, 0xC0FF8080, 2, 1, D_L01_001D66B0, 0.0f, 1);
            func_L01_0046B458(&at, 0x1C, 3.75f, 0.1f, 0xB0FF8080, 2, -1, D_L01_001D66B0, 0.0f, 1);
            func_L01_00470C78(&at, 0x21, 3.6f, 1.4f, 0x46787878, 2, 2, D_L01_001D66B0, 0, 2, 6, 1);
            func_L01_00470C78(&at, 0x21, 6.8f, 1.4f, 0x46787878, 2, -1, D_L01_001D66B0, 1, 2, 6, 1);
            func_L01_00470C78(&at, 0x21, 8.0f, 3.0f, 0x2D787878, 2, 1, D_L01_001D66B0, 1, 2, 6, 1);
            for (i = 0; i < 6; i++) {
                f32 r, s;
                u8 *q;
                r = func_00382538();
                s = func_003824E0(0.87266463f, 1.5707964f);
                func_00382760(&dir, func_003824E0(4.0f, 9.0f) * 0.020000001f, r, s);
                dir.w = 0.0f;
                func_0038D000(&dir, &dir, mat);
                q = func_L01_0031E788((u8 *)&m->pos, (f32 *)&dir, i, 0, 1);
                if (q != 0) {
                    *(s32 *)(q + 0xB8) = m->bB8;
                }
            }
        } else if (level == 3) {
            func_L01_003303B8(&m->pos, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 1.0f, 0.0f, 0.0f, 2.0f,
                              0, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7,
                              0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            vec_sub_ba(&rot, &D_L01_001E2A40, &m->pos);
            func_0038CF68_00397E98(&rot, &rot, 0.5f);
            vec_add_ab(&at, &m->pos, &rot);
            func_L01_0046B458(&at, 0x1C, 10.5f, 0.1f, 0xBFFF4020, 2, 1, D_L01_001D66B0, 0.0f, 1);
            func_L01_0046B458(&at, 0x1C, 7.5f, 0.1f, 0xBFFF8040, 2, -1, D_L01_001D66B0, 0.0f, 1);
            func_L01_0046B458(&at, 0x1C, 5.25f, 0.1f, 0xC0FF8080, 2, 1, D_L01_001D66B0, 0.0f, 1);
            func_L01_0046B458(&at, 0x1C, 3.75f, 0.1f, 0xB0FF8080, 2, -1, D_L01_001D66B0, 0.0f, 1);
            func_L01_00470C78(&at, 0x21, 3.6f, 1.4f, 0x46787878, 2, 2, D_L01_001D66B0, 0, 2, 6, 1);
            func_L01_00470C78(&at, 0x21, 6.8f, 1.4f, 0x46787878, 2, -1, D_L01_001D66B0, 1, 2, 6, 1);
            func_L01_00470C78(&at, 0x21, 8.0f, 3.0f, 0x2D787878, 2, 1, D_L01_001D66B0, 1, 2, 6, 1);
            for (i = 0; i < 6; i++) {
                f32 r, s;
                u8 *q;
                r = func_00382538();
                s = func_003824E0(0.6981317f, 1.3089969f);
                func_00382760(&dir, func_003824E0(4.0f, 12.0f) * 0.020000001f, r, s);
                dir.w = 0.0f;
                func_0038D000(&dir, &dir, mat);
                q = func_L01_0031E788((u8 *)&m->pos, (f32 *)&dir, i, 1, 1);
                if (q != 0) {
                    *(s32 *)(q + 0xB8) = m->bB8;
                }
            }
        }
            func_L01_00399A50(m, &v150, owner);
kill:
            func_L01_0044BEC8(m, D_L01_001E0140);
            func_L01_004C8668(vars->sound);
            func_003C2880(m);
    } else if (func_0038CB00(&vars->timer) != 0 || 75.0f < func_0038CF38(&m->pos, D_001A4C60)) {
        func_L01_0044BEC8(m, D_L01_001E0140);
        func_L01_004C8668(vars->sound);
        func_003C2880(m);
    }
}
/* localdecomp:end func_L01_00397E98 */

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

/* localdecomp:start func_L01_00399B18 */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_00399B18;
typedef struct { u8 pad[0x5C]; u8 *type; } State_00399B18;
extern State_00399B18 D_L01_00221098;
extern f32 D_001A4EC0[];
void func_L01_00399B18(u8 *obj, s128_003985C0 *position) {
    extern void func_0038CF68_00399B18(Vec4_00399B18 *, Vec4_00399B18 *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_0013D3E0(void);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, u32, s32, f32, f32, f32, f32, f32);
    vu0_v4 origin, velocity, current, step;
    s32 count, kind, i;
    s32 life, texture, mode;
    u32 color;
    f32 speed;
    f32 drift;
    u8 *particle;
    u32 blue;
    f32 length;
    origin = *(vu0_v4 *)position;
    length = *(f32 *)(*(u8 **)(obj+0x68)+0x18);
    current = origin;
    count = (s32)(length / 0.15f);
    vec_sub_ab(&step, obj+0x10, &origin);
    func_0038CF68_00399B18((Vec4_00399B18 *)&step, (Vec4_00399B18 *)&step, length / count);
    kind = D_L01_002C5600[D_001425FF[0]].pad[1];
    for (i=0; i<count; i++) {
        mode = (s32)func_L01_00443A18(1.0f,3.0f);
        drift = func_003824E0(0.2f,1.0f);
        func_0038CE20((f32 *)&velocity,D_001A4EC0,-(drift*0.020000001f));
        life = func_00382498(30,55);
        speed = func_003824E0(200.0f,1000.0f);
        if (func_0013D3E0() & 2) {
            texture=64;
            color=0;
            speed+=speed;
        } else {
            blue = 0x104080;
            texture=80;
            color=0x7F7F7F;
            if (kind) color=blue;
        }
        particle=func_L01_0046A610(&current,&velocity,(life*5+2)/6,texture,color,mode,31500.002f,speed,1.0f,0.0f,0.0f);
        vec_add_ab(&current,&current,&step);
        if (particle) {
            particle[2]=*D_L01_00221098.type;
            particle[3]=texture==80?0x48:0x44;
        }
    }
}
/* localdecomp:end func_L01_00399B18 */

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

/* localdecomp:start func_L01_0039A320 */
#include "vu0.h"
typedef struct {
    vu0_v4 push;
    u8 *owner;
    s32 flags;
    u8 active, kind;
    u16 class_id;
    f32 damage;
    s32 enabled;
} Query_0039A320;
typedef struct {
    vu0_v4 initial, starting, direction, previous, axis;
    Query_0039A320 query;
    vu0_v4 temporary;
} Scratch_0039A320;
typedef struct { u8 pad[0x25c0]; u8 *moby; } Hero_0039A320;
extern Hero_0039A320 D_001A4BE0_0039A320;
typedef struct { u8 pad[0x6c]; f32 damage; } Gun_0039A320;
extern f32 D_L01_001DE0E4;
extern s32 D_L01_001DE0E0;
__asm__(".extern D_L01_001DE0E4, 4");
__asm__(".extern D_L01_001DE0E0, 4");
extern u8 D_00142607[];
extern vu0_v4 D_L01_001EAA20_0039A320;
typedef struct { u8 pad0[0x64]; u8 *first; u8 pad68[0x1a0-0x68]; u8 *second; } Settings_0039A320;
extern Settings_0039A320 D_L01_00221098_0039A320;
extern u8 D_L01_001D66B0[8];
void func_L01_0039A320(u8 *self)
{
    extern void func_003C2F58(void *,s32,void *);
    extern void func_003C5180(void *,void *,s32);
    extern void func_0038CF68(void *,void *,f32);
    extern f32 func_0038D160(f32,f32);
    extern f32 func_003824E0(f32,f32);
    extern void func_0038D890(void *,void *,void *,f32);
    extern s32 func_003D3CB0(Vec4 *,s32 *,s32,s32,s32);
    extern void func_L01_0039AB60(void *,s32,s32);
    extern f32 func_0038CEA8(void *);
    extern s32 func_L01_00424CB0(void *,f32,f32,f32,f32,f32);
    extern s32 func_0038CAD0(void *);
    extern void func_L01_00424D88(s32);
    extern void func_003C2880(void *);
    extern u8 *func_L01_0046FB40(void *,void *,s32,s32,s32,s32,s32,f32,f32,f32,s32);
    extern void func_L01_00399E80(u8 *);
    extern void func_L01_0039A860(u8 *);
    extern void func_L01_00404A10(void *,void *);
    Scratch_0039A320 scratch;
    u8 *vars=*(u8 **)(self+0x68);
    f32 angle;
    func_003C2F58(*(void **)(self+0xb8),0,&scratch.initial);
    *(vu0_v4 *)(self+0x10)=scratch.initial;
    scratch.starting=scratch.initial;
    func_003C5180(self+0x10,&scratch.direction,1);
    scratch.previous=*(vu0_v4 *)(self+0x10);
    vec_sub_ba(&scratch.axis,vars+0x30,self+0x10);
    func_0038CF68((void *)&scratch.axis,(void *)&scratch.axis,1.0f);
    angle=func_0038D160(*(f32 *)(vars+0x30)-*(f32 *)(D_001A4BE0_0039A320.moby+0x10),
                       *(f32 *)(vars+0x34)-*(f32 *)(D_001A4BE0_0039A320.moby+0x14));
    if(angle<1.5707964f) angle=func_003824E0(0.0f,-0.7853982f);
    else angle=func_003824E0(0.0f,0.7853982f);
    *(vu0_q *)(vars+0x40)=*(vu0_q *)(self+0x10);
    *(f32 *)(vars+0x48)-=D_L01_001DE0E4;
    vec_sub_ba(vars+0x40,vars+0x40,self+0x10);
    func_0038D890((void *)(vars+0x40),(void *)(vars+0x40),(void *)&scratch.axis,angle);
    vec_add_ab(vars+0x40,self+0x10,vars+0x40);
    switch(self[0x20]) {
    case 0: {
        scratch.query.owner=self;
        scratch.query.flags=0x410000;
        scratch.query.enabled=1;
        scratch.query.damage=((Gun_0039A320 *)((s32)D_L01_002C5600+D_00142607[0]*sizeof(Ent_003985C0)))->damage*0.5f;
        vec_sub_ba(&scratch.query.push,vars+0x30,self+0x10);
        func_0038CF68((void *)&scratch.query.push,(void *)&scratch.query.push,0.7f);
        scratch.query.push.w=5627.9248046875f;
        scratch.query.class_id=*(u16 *)(self+0xaa);
        scratch.query.active=1;
        scratch.query.kind=1;
        if(func_003D3CB0((Vec4 *)(self+0x10),(s32 *)(vars+0x30),0,(s32)D_001A4BE0_0039A320.moby,(s32)&scratch.query)) {
            u8 *hit;
            scratch.temporary=D_L01_001EAA20_0039A320;
            hit=*(u8 **)((u8 *)&D_L01_001EAA20_0039A320-8);
            if(hit==0) func_L01_0039AB60(&scratch.temporary,15,0);
            else if(*(s32 *)(hit+0x98)!=0) func_L01_0039AB60(&scratch.temporary,10,0);
            self[0x20]=1;
            *(s32 *)(vars+0x10)=(D_L01_001DE0E0*5+2)/6;
        } else {
            self[0x20]=1;
            *(s32 *)(vars+0x10)=(D_L01_001DE0E0*5+2)/6;
        }
        vec_sub_ba(&scratch.temporary,vars+0x30,self+0x10);
        func_0038CF68((void *)&scratch.temporary,(void *)&scratch.temporary,func_0038CEA8(&scratch.temporary)*0.5f);
        vec_add_ba(&scratch.temporary,self+0x10,&scratch.temporary);
        *(s32 *)(vars+0x18)=func_L01_00424CB0(&scratch.temporary,10.0f,0.0f,0.1f,0.1f,1.0f);
        break;
    }
    case 1: {
        s32 i;
        if(func_0038CAD0(vars+0x10)) {
            *(s32 *)(vars+0xc)=0;
            if(*(s32 *)(vars+0x18)!=-1) func_L01_00424D88(*(s32 *)(vars+0x18));
            func_003C2880(self);
            return;
        }
        for(i=9;i>=0;i--) {
            f32 size=func_003824E0(0.15f,0.25f)*210000.0f;
            u8 *p=func_L01_0046FB40(self+0x10,D_L01_001D66B0,2,0x804020,2,127,16,size,size,0.0f,0);
            if(p) p[2]=D_L01_00221098_0039A320.first[0];
            p=func_L01_0046FB40(self+0x10,D_L01_001D66B0,2,0x804020,-1,127,16,size,size,0.0f,0);
            if(p) p[2]=D_L01_00221098_0039A320.second[0];
        }
        if(*(s32 *)(vars+0x10)>=6) func_L01_00399E80(self);
        func_L01_00404A10(func_L01_0039A860,self);
        break;
    }
    }
    if(*(f32 *)(self+0x10)<2.0f || *(f32 *)(self+0x10)>1021.0f ||
       *(f32 *)(self+0x14)<2.0f || *(f32 *)(self+0x14)>1021.0f ||
       *(f32 *)(self+0x18)<2.0f || *(f32 *)(self+0x18)>1021.0f) func_003C2880(self);
}
/* localdecomp:end func_L01_0039A320 */

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

/* localdecomp:start func_L01_0039AB60 */
extern vu0_v4 D_L01_001E29C0;
extern f32 D_001A4EC0[];
typedef struct { u8 pad[0x184]; u8 *p184; } T_0039AB60;
extern T_0039AB60 D_L01_00221098_0039AB60[1];
void func_L01_0039AB60(f32 *origin) {
    extern f32 func_0038D160(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, u32, s32, f32, f32, f32, f32, f32);
    vu0_v4 delta, velocity, position;
    f32 angle, lifetime, radius, pitch, yaw;
    s32 i, size;
    s32 alpha = 0x7F;
    s32 color;
    s32 flags = 0x44;
    u8 *p, *d;
    vec_sub_ab(&delta, &D_L01_001E29C0, origin);
    angle = func_0038D160(delta.x, delta.y);
    for (i = 0; i < 20; i++) {
        color = (alpha << 24) | 0xFF8040;
        func_0038CE20((f32 *)&velocity, D_001A4EC0, -(func_003824E0(0.2f, 3.0f) * 0.020000001415610313f));
        size = func_L01_00443A18(1.0f, 2.0f);
        lifetime = func_003824E0(0.3f, 0.75f) * 210000.0f;
        position.x = origin[0] + func_L01_00443A18(0.0f, 0.2f);
        position.y = origin[1] + func_L01_00443A18(0.0f, 0.2f);
        position.z = origin[2] + func_L01_00443A18(0.0f, 0.2f);
        p = func_L01_004669B0(&position, 0.0f, 1.0f, 1.01f, lifetime, size, &velocity, 0x7F202020, 0);
        if (p != 0) {
            *(u16 *)(p + 0xA) = 75;
            d = p + 0x20;
            p[3] = flags;
            p[9] = flags;
            *(f32 *)(d + 0x1C) = 4.0f;
            *(s32 *)(d + 4) = 3;
            d[0xA] = 0x30;
            d[0xB] = p[0xA];
        }
        radius = func_003824E0(1.0f, 2.0f);
        pitch = func_003824E0(0.0f, 1.39626336f);
        yaw = func_L01_00443A18(0.0f, 1.39626336f);
        yaw = func_0038DAB8(angle, yaw);
        func_00382760(&velocity, radius * 0.020000001415610313f, yaw, pitch);
        position.x = origin[0] + func_L01_00443A18(0.0f, 0.1f);
        position.y = origin[1] + func_L01_00443A18(0.0f, 0.1f);
        position.z = origin[2] + func_L01_00443A18(0.0f, 0.1f);
        lifetime = func_003824E0(0.1f, 0.3f) * 210000.0f;
        p = func_L01_0046A610(&position, &velocity, 25, alpha, color, size, lifetime, 500.0f, 1.0f, 0.0f, 0.0f);
        if (p != 0) p[2] = D_L01_00221098_0039AB60[0].p184[6];
    }
}
/* localdecomp:end func_L01_0039AB60 */

/* localdecomp:start func_L01_0039AEB8 */
typedef struct {
    vu0_v4 m[4];
    s32 col[4];
    f32 uv[8];
    long x70, x78, x80, x88;
} __attribute__((aligned(16))) Q_003BE190;

extern void func_0038CE20_0039AEB8(void *, void *, f32);
extern void func_003D2DA0_0039AEB8(void *, void *, s32);
extern long func_00389598_0039AEB8(s32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_003A9440(s32, unsigned long);

void func_L01_0039AEB8(u8 *pv, s32 a1, s32 a2, f32 w0, f32 w1, f32 k, s32 n, u32 c0, u32 c1) {
    Q_003BE190 q1;
    Q_003BE190 q2;
    vu0_v4 perp;
    vu0_v4 r;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 v;
    vu0_v4 w;
    vu0_v4 t;
    vu0_v4 u;
    vu0_v4 c;
    vu0_v4 s;
    vu0_v4 *p = pv;
    s32 col0;
    s32 col1;
    f32 len;
    f32 m0;
    f32 m1;
    f32 l0;
    f32 l1;
    s32 i;

    q1.x78 = func_00389598_0039AEB8(0xE);
    col0 = c0 | (a1 << 24);
    q1.x88 = 0x8000000048L;
    q1.x80 = 0xFF9000000260L;
    q1.x70 = 0;
    q1.col[0] = q1.col[1] = q1.col[2] = q1.col[3] = col0;
    q2.x78 = func_00389598_0039AEB8(0x10);
    q2.x88 = q1.x88;
    q2.x80 = q1.x80;
    q2.x70 = q1.x70;
    col1 = c1 | (a2 << 24);
    q2.col[0] = q2.col[1] = q2.col[2] = q2.col[3] = col1;
    q2.uv[0] = 0.0f;
    q2.uv[1] = 0.0f;
    q2.uv[2] = 0.0f;
    q2.uv[3] = 1.0f;
    q2.uv[4] = 1.0f;
    q2.uv[5] = 0.0f;
    q2.uv[6] = 1.0f;
    q2.uv[7] = 1.0f;
    q1.uv[0] = 0.0f;
    q1.uv[1] = 0.0f;
    q1.uv[2] = 0.0f;
    q1.uv[3] = 1.0f;
    q1.uv[4] = 1.0f;
    q1.uv[5] = 0.0f;
    q1.uv[6] = 1.0f;
    q1.uv[7] = 1.0f;

    vec_sub_ab(&a, &p[0], &D_L01_001E29C0);
    vec_sub_ab(&b, &p[1], &p[0]);
    func_0038CE90(&perp, &b, &a);
    m0 = func_0038CEA8(&perp);
    if (m0 != 0.0f) {
        m0 = 1.0f / m0;
    }
    func_0038CE20_0039AEB8(&perp, &perp, w0 * m0);
    vec_add_ba(&q1.m[0], &p[0], &perp);
    vec_sub_ab(&q1.m[1], &p[0], &perp);

    for (i = 1; i < n - 1; i++) {
        vec_sub_ab(&a, &p[i], &D_L01_001E29C0);
        vec_sub_ab(&b, &p[i + 1], &p[i]);
        func_0038CE90(&perp, &b, &a);
        m1 = func_0038CEA8(&perp);
        if (m1 != 0.0f) {
            m1 = 1.0f / m1;
        }
        func_0038CE20_0039AEB8(&perp, &perp, w0 * m1);
        vec_add_ba(&q1.m[2], &p[i], &perp);
        vec_sub_ab(&q1.m[3], &p[i], &perp);
        if (i == 1) {
            q1.col[0] = q1.col[1] = c0;
        } else if (i == n - 2) {
            q1.col[2] = q1.col[3] = c0;
        } else if (i == 2) {
            q1.col[0] = q1.col[1] = col0;
        }
        func_003D2DA0_0039AEB8(&q1, 0, 0);
        q1.m[0] = q1.m[2];
        q1.m[1] = q1.m[3];
    }

    for (i = 0; i < n - 1; i++) {
        vec_sub_ab(&t, &p[i], &D_L01_001E29C0);
        vec_sub_ab(&u, &p[i + 1], &D_L01_001E29C0);
        l0 = func_0038CEA8(&t);
        l1 = func_0038CEA8(&u);
        if (l1 < l0) {
            if (l1 == 0.0f) {
                u = t;
            } else {
                func_0038CE20_0039AEB8(&u, &u, l0 / l1);
            }
        } else {
            if (l0 == 0.0f) {
                t = u;
            } else {
                func_0038CE20_0039AEB8(&t, &t, l1 / l0);
            }
        }
        vec_add_ba(&v, &D_L01_001E29C0, &t);
        vec_add_ab(&w, &D_L01_001E29C0, &u);
        vec_sub_ba(&b, &w, &v);
        func_0038CE20_0039AEB8(&s, &b, k);
        vec_sub_ab(&v, &v, &s);
        vec_add_ab(&w, &w, &s);
        vec_sub_ab(&c, &D_L01_001E29C0, &v);
        func_0038CE90(&perp, &c, &b);
        len = func_0038CEA8(&perp);
        if (len != 0.0f) {
            len = 1.0f / len;
        }
        func_0038CE20_0039AEB8(&r, &perp, w1 * len);
        vec_add_ba(&q2.m[0], &v, &r);
        vec_sub_ab(&q2.m[1], &v, &r);
        vec_add_ba(&q2.m[2], &w, &r);
        vec_sub_ab(&q2.m[3], &w, &r);
        if (i == 0) {
            q2.col[0] = q2.col[1] = c1;
        } else if (i == n - 2) {
            q2.col[2] = q2.col[3] = c1;
        } else if (i == 1) {
            q2.col[0] = q2.col[1] = col1;
        }
        func_003D2DA0_0039AEB8(&q2, 0, 0);
    }
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L01_0039AEB8 */

/* localdecomp:start func_L01_0039B478 */
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec4_0039B478;
#include "vu0.h"
typedef struct {
    u8 pad0[16]; vu0_v4 position;
    u8 state; u8 pad21[15]; u8 alpha; u8 pad31; s16 flags;
    u8 pad34[0x34]; u8 *vars; u8 pad6C[0x54];
    vu0_v4 c0, d0, e0;
} Obj_0039B478;
extern vu0_v4 D_L01_001E29C0;
extern u8 D_00142637[];
extern Ent_003985C0 D_L01_002C5600[];
extern s32 D_L01_001E205C;
extern f32 D_L01_001E2060;
extern s32 D_L01_001DE0F4;
extern s32 D_L01_001DE0F0_0039B478;
__asm__(".extern D_L01_001DE0F0_0039B478, 4");
__asm__(".extern D_L01_001DE0F4, 4");
extern u32 D_L01_001E2058;
extern f32 D_L01_001E2064;
Obj_0039B478 *func_L01_0039B478(vu0_q *pos, s32 arg1, s32 arg2) {
    extern Obj_0039B478 *func_003C24B0_0039B478(s32, s32);
    extern void func_0038CF68_0039B478(void *, void *, f32);
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CE90(void *, void *, void *);
    extern s32 func_00382498(s32, s32);
    vu0_v4 v, q;
    Obj_0039B478 *obj = func_003C24B0_0039B478(6296, 128);
    u8 *vars;
    s32 kind;
    u8 *entry;
    f32 zero;
    if (obj) {
        vars = obj->vars;
        obj->alpha = 255;
        obj->flags = 255;
        obj->state = 0;
        *(s32 *)(vars + 4) = arg1;
        *(s32 *)(vars + 8) = arg2;
        *(vu0_q *)&obj->position = *pos;
        obj->position.w = 1.0f;
        vec_sub_ab(&v, &D_L01_001E29C0, &obj->position);
        func_0038CF68_0039B478((Vec4_0039B478 *)&v, (Vec4_0039B478 *)&v, 1.0f);
        func_003C5180(&obj->position, &q, 1);
        *(vu0_q *)&obj->c0 = *(vu0_q *)&v;
        func_0038CE90(&obj->d0, &obj->c0, &q);
        func_0038CF68_0039B478((Vec4_0039B478 *)(&obj->d0), (Vec4_0039B478 *)(&obj->d0), 1.0f);
        func_0038CE90(&obj->e0, &obj->d0, &obj->c0);
        zero = 0.0f;
        obj->e0.w = zero;
        obj->d0.w = zero;
        obj->c0.w = zero;
        *(s32 *)vars = 25;
        D_L01_001E205C = 96;
        D_L01_001E2060 = 0.005f;
        entry = (u8 *)(D_L01_002C5600 + D_00142637[0]);
        kind = entry[1];
        if (kind == 1) {
            D_L01_001DE0F0_0039B478 = 8;
            D_L01_001DE0F4 = 8;
            D_L01_001E2058 = (func_00382498(180, 255) << 16) | 0x80000000;
            D_L01_001E2064 = 3.5f;
        } else if (kind == 2) {
            D_L01_001DE0F0_0039B478 = 12;
            D_L01_001DE0F4 = 12;
            D_L01_001E2058 = func_00382498(200, 255) | 0x800A4000;
            D_L01_001E2064 = 3.75f;
        } else if (kind >= 3) {
            D_L01_001DE0F0_0039B478 = 16;
            D_L01_001DE0F4 = 16;
            D_L01_001E2058 = 0x800000FF;
            D_L01_001E2064 = 4.0f;
        }
    }
    return obj;
}
/* localdecomp:end func_L01_0039B478 */

/* localdecomp:start func_L01_0039B6B8 */
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec4_0039B6B8;
#include "vu0.h"
extern f32 D_L01_001E2064;
extern s32 D_L01_001DE0F0;
__asm__(".extern D_L01_001DE0F0, 4");
extern u8 D_00142637[];
typedef struct { u8 pad[0x25C0]; u8 *moby; } Hero_0039B6B8;
extern Hero_0039B6B8 D_001A4BE0;
typedef struct { u8 pad[0x77]; u8 weapon; } Game_0039B6B8;
extern Game_0039B6B8 D_001425C0;
typedef struct { vu0_q vec; u8 rest[0x20]; } Damage_0039B6B8;
typedef struct { u8 pad[0x6C]; f32 damage; u8 tail[0x80]; } Weapon_0039B6B8;
extern Weapon_0039B6B8 D_L01_002C5600_0039B6B8;
typedef struct { u8 pad[0x9C]; s32 owner; u8 tail[0x10]; } Effect_0039B6B8;
extern Effect_0039B6B8 D_L01_002A1E70_0039B6B8;
extern u8 D_L01_001EEA80[];
extern u8 D_L01_002A1E70[];
extern vu0_q D_L01_001EAA20;
void func_L01_0039B6B8(u8 *self)
{
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *,void *);
    extern s32 func_0038CAD0(s32 *);
    extern s32 func_003D4D00(void *,s32,void *,s32,f32);
    extern u8 *func_00382348(void *);
    extern void func_L01_004C7D98(void *,void *);
    extern void func_0038CF68(Vec4_0039B6B8 *,Vec4_0039B6B8 *,f32);
    extern void func_L01_0039BEF8(u8 *,void *,s32);
    extern void func_L01_00446760(void *,void *,s32,void *,f32);
    extern void func_L01_00446978(void *,void *);
    extern f32 func_00382538(void);
    extern void func_00382760(void *,f32,f32,f32);
    extern s32 func_003D3CB0(Vec4 *,s32 *,s32,s32,s32);
    extern void func_L01_0039C190(u8 *);
    extern void func_L01_0039B9F0(u8 *);
    extern void func_L01_00404A10(void (*)(u8 *),u8 *);
    extern void func_003C2880(void *);
    struct { vu0_q pos,offset,delta; Damage_0039B6B8 hit; } work;
    u8 *state=*(u8 **)(self+0x68);
    s32 count;
    u8 **objects;
    f32 x,y;
    s32 active;
    s32 n;
    if(func_L01_004CB2D8()) func_L01_004CAB30(self+0x10,self+0x10);
    active=func_0038CAD0((s32 *)state);
    n=D_L01_001DE0F0;
    if (!active) {
        count=func_003D4D00(self+0x10,1,self,0,D_L01_001E2064);
        if(count && (&D_L01_002C5600_0039B6B8)[D_001425C0.weapon].pad[1]>=2) {
            if(count>0) {
            s32 remaining=count;
            objects=(u8 **)D_L01_001EEA80;
            do {
                u8 *other=func_00382348(*objects);
                if(other && (*(u16 *)(*objects+0x34)&0x4000) && *objects!=D_001A4BE0.moby
                   && *objects && *(u8 **)(*objects+0x24) && (*(u8 **)(*objects+0x24))[0x46]==5) {
                    func_L01_004C7D98(self+0x10,&work.offset);
                    func_0038CF68((Vec4_0039B6B8 *)&work.offset,(Vec4_0039B6B8 *)&work.offset,*(f32 *)(other+0x10));
                    vec_add_ba(&work.pos,*objects+0x10,&work.offset);
                    func_L01_0039BEF8(self,&work.pos,4);
                    vec_sub_ba(&work.delta,*objects+0x10,self+0x10);
                    func_0038CF68((Vec4_0039B6B8 *)&work.delta,(Vec4_0039B6B8 *)&work.delta,1.5f);
                    func_0038CF68((Vec4_0039B6B8 *)((u8 *)&work.hit),(Vec4_0039B6B8 *)((u8 *)&work.hit),2.0f);
                    { Weapon_0039B6B8 *w=&(&D_L01_002C5600_0039B6B8)[D_001425C0.weapon]; func_L01_00446760(((u8 *)&work.hit),self,0x110000,&work.delta,w->damage*0.001f); }
                    *(vu0_q *)((u8 *)&work.hit)=work.delta;
                    *(s32 *)(((u8 *)&work.hit)+0x20)=1;
                    *(f32 *)(((u8 *)&work.hit)+0xC)=5627.9248046875f;
                    ((u8 *)&work.hit)[0x18]=5;
                    ((u8 *)&work.hit)[0x19]=3;
                    *(u16 *)(((u8 *)&work.hit)+0x1A)=*(u16 *)(*objects+0xAA);
                    func_L01_00446978(*objects,((u8 *)&work.hit));
                }
            } while(--remaining,objects++,remaining!=0);
            }
        }
        x=func_00382538();
        y=func_00382538();
        func_00382760(&work.pos,D_L01_001E2064,x,y);
        vec_add_ab(&work.pos,&work.pos,self+0x10);
        if(func_003D3CB0((Vec4 *)(self+0x10),(s32 *)&work.pos,0,(s32)self,0)) work.pos=D_L01_001EAA20;
        func_L01_0039BEF8(self,&work.pos,4);
        func_L01_0039C190(self);
        func_L01_00404A10(func_L01_0039B9F0,self);
    } else {
        
        s32 i;
        for(i=0;i<n;i++) (&D_L01_002A1E70_0039B6B8)[i].owner=0;
        func_003C2880(self);
    }
}
/* localdecomp:end func_L01_0039B6B8 */

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

/* localdecomp:start func_L01_0039BD08 */
#include "vu0.h"
typedef struct {
    vu0_v4 start, end, sdir, edir;
    u8 pad40[0x58];
    s32 level;
} Arc_0039BD08;
extern s32 D_L01_001DE0F4_0039BD08;
__asm__(".extern D_L01_001DE0F4_0039BD08, 4");
void func_L01_0039BD08(u8 *owner, Arc_0039BD08 *state) {
    extern void func_L01_00445208(void *, void *, void *, void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68_0039BD08(void *, void *, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_0039C560(u8 *, s32, void *, s32);
    vu0_v4 points[D_L01_001DE0F4_0039BD08 + 1];
    vu0_v4 start, end, jitter;
    s32 i;
    f32 t;
    for (i = 0; i < D_L01_001DE0F4_0039BD08; i++) {
        t = (f32)i / (D_L01_001DE0F4_0039BD08 - 1);
        start = state->start;
        end = state->end;
        vec_add_ba(&start, &start, &state->sdir);
        vec_add_ba(&end, &end, &state->edir);
        func_L01_00445208(&points[i], &state->sdir, &state->edir, &start, &end, t);
        jitter.w = 0.0f;
        jitter.x = func_003824E0(-1.0f, 1.0f);
        jitter.y = func_003824E0(-1.0f, 1.0f);
        jitter.z = func_003824E0(-1.0f, 1.0f);
        func_0038CF68_0039BD08(&jitter, &jitter, 0.075f);
        vec_add_ba(&points[i], &points[i], &jitter);
    }
    if (state->level >= 8) {
        func_L01_0039C560(owner, func_00382498(64, 128), points, D_L01_001DE0F4_0039BD08 + 1);
    } else {
        func_L01_0039C560(owner, func_00382498(0, 64), points, D_L01_001DE0F4_0039BD08 + 1);
    }
}
/* localdecomp:end func_L01_0039BD08 */

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

/* localdecomp:start func_L01_0039C560 */
#include "vu0.h"
extern u32 D_L01_001E2058;
void func_L01_0039C560(s32 unused, s32 colour, f32 (*pts)[4], s32 count) {
    extern unsigned long func_00389598_0039C560(s32);
    extern void func_L01_0039C498_0039C560(f32 (*)[4], s32);
    extern void func_L01_0039C4D8_0039C560(f32 *);
    extern void func_0038CE20_0039C560(f32 *, f32 *, f32);
    extern void func_0038CF68_0039C560(f32 *, f32 *, f32);
    extern void func_0038CE90_0039C560(f32 *, f32 *, f32 *);
    extern void func_0038D028_0039C560(f32 *, f32 *, f32 *);
    extern void func_003D2DA0_0039C560(f32 *, s32, s32);
    f32 a[36] __attribute__((aligned(16)));
    f32 b[36] __attribute__((aligned(16)));
    f32 axis[4] __attribute__((aligned(16)));
    f32 eye[4] __attribute__((aligned(16)));
    f32 side[4] __attribute__((aligned(16)));
    f32 pos[4] __attribute__((aligned(16)));
    f32 inner[4] __attribute__((aligned(16)));
    f32 outer[4] __attribute__((aligned(16)));
    s32 i;
    unsigned long texture;
    f32 u, v;
    f32 k;
    texture = func_00389598_0039C560(43);
    *(unsigned long *)(a + 28) = 0;
    *(unsigned long *)(a + 32) = 0x0000FF9000000260UL;
    *(unsigned long *)(a + 34) = ((unsigned long)(u32)colour << 32) | 104;
    *(s32 *)(a + 17) = 0x7FFFFFFF;
    *(s32 *)(a + 16) = 0x7FFFFFFF;
    *(unsigned long *)(a + 30) = texture;
    texture = func_00389598_0039C560(43);
    *(unsigned long *)(b + 30) = texture;
    *(unsigned long *)(b + 28) = 0;
    *(unsigned long *)(b + 32) = 0x0000FF9000000260UL;
    *(unsigned long *)(b + 34) = ((unsigned long)(u32)(colour / 3) << 32) | 104;
    *(vu0_q *)inner = 0;
    *(vu0_q *)outer = 0;
    inner[2] = 0.04f;
    outer[2] = 0.16f;
    *(s32 *)(a + 17) = D_L01_001E2058;
    *(s32 *)(b + 16) = D_L01_001E2058;
    inner[3] = 1.0f; outer[3] = 1.0f;
    func_L01_0039C498_0039C560(pts, count);
    func_L01_0039C4D8_0039C560(a);
    func_L01_0039C4D8_0039C560(b);
    a[20]=0.0f; a[21]=0.0f; a[22]=0.0f; a[23]=1.0f;
    a[24]=1.0f; a[25]=0.0f; a[26]=1.0f; a[27]=1.0f;
    b[20]=0.0f; b[21]=0.0f; b[22]=0.0f; b[23]=1.0f;
    b[24]=0.33f; b[25]=0.0f; b[26]=0.33f; b[27]=1.0f;
    vec_sub_ba(axis, pts[1], pts[0]);
    func_0038CF68_0039C560(axis, axis, 1.0f);
    vec_sub_ab(eye, (f32 *)&D_L01_001E29C0, pts[0]);
    func_0038CE90_0039C560(side, eye, axis);
    func_0038CF68_0039C560(side, side, 1.0f);
    func_0038CE90_0039C560(eye, axis, side);
    *(vu0_q *)pos = *(vu0_q *)pts[0];
    *(vu0_q *)a = *(vu0_q *)inner;
    func_0038CE20_0039C560(a + 4, a, -1.0f);
    func_0038D028_0039C560(a, a, axis);
    func_0038D028_0039C560(a + 4, a + 4, axis);
    *(vu0_q *)b = *(vu0_q *)outer;
    func_0038CE20_0039C560(b + 4, b, -1.0f);
    func_0038D028_0039C560(b, b, axis);
    func_0038D028_0039C560(b + 4, b + 4, axis);
    for (i = 1; i < count - 1; i++) {
        *(vu0_q *)(a + 8) = *(vu0_q *)inner;
        func_0038CE20_0039C560(a + 12, a + 8, -1.0f);
        *(vu0_q *)(b + 8) = *(vu0_q *)outer;
        func_0038CE20_0039C560(b + 12, b + 8, -1.0f);
        vec_sub_ab(axis, pts[i + 1], pts[i]);
        func_0038CF68_0039C560(axis, axis, 1.0f);
        vec_sub_ab(eye, (f32 *)&D_L01_001E29C0, pts[i]);
        func_0038CE90_0039C560(side, eye, axis);
        func_0038CF68_0039C560(side, side, 1.0f);
        func_0038CE90_0039C560(eye, axis, side);
        *(vu0_q *)pos = *(vu0_q *)pts[i];
        func_0038D028_0039C560(a + 8, a + 8, axis);
        func_0038D028_0039C560(a + 12, a + 12, axis);
        func_0038D028_0039C560(b + 8, b + 8, axis);
        k = 0.33f;
        func_0038D028_0039C560(b + 12, b + 12, axis);
        *(s32 *)(a + 19) = 0x7F7F7F7F;
        *(s32 *)(a + 18) = 0x7F7F7F7F;
        *(s32 *)(b + 19) = D_L01_001E2058;
        *(s32 *)(b + 18) = D_L01_001E2058;
        func_003D2DA0_0039C560(a, 0, 0);
        func_003D2DA0_0039C560(b, 0, 0);
        u = i * k;
        v = u + k;
        if (u >= 1.0f) { u -= 1.0f; v -= 1.0f; }
        b[20] = u; b[24] = v; b[22] = u; b[26] = v;
        *(vu0_q *)a = *(vu0_q *)(a + 8);
        *(vu0_q *)(a + 4) = *(vu0_q *)(a + 12);
        *(vu0_q *)b = *(vu0_q *)(b + 8);
        *(vu0_q *)(b + 4) = *(vu0_q *)(b + 12);
    }
}
/* localdecomp:end func_L01_0039C560 */

INCLUDE_ASM("asm/levels", func_L01_0039C9E0);

/* localdecomp:start func_L01_0039D2E0 */
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec4_0039E0C8;
#include "vu0.h"
extern u8 *D_L01_002210F4[], *D_L01_0022123C[], *D_L01_00221120[];
void func_L01_0039D2E0(u8 *self)
{
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32, s32);
    extern void func_00382580(void *, f32, f32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
    extern void func_L01_004C7D98(void *, void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(Vec4_0039E0C8 *, Vec4_0039E0C8 *, f32);
    extern void func_L01_00466F50(void *, void *, s32, f32, f32);
    vu0_v4 position;
    vu0_v4 velocity;
    vu0_v4 offset;
    s32 spin;
    u8 *p;
    vu0_v4 direction;
    if (func_00382468(3) == 0) {
        s32 life;
        func_00382580(&velocity, 0.035f, 0.05f);
        func_0038CE20((f32 *)&offset, (f32 *)&velocity, 10.0f);
        vec_add_ab(&position, &offset, self + 0x10);
        life = func_00382498(10, 30);
        life *= 5;
        life += 2;
        life /= 6;
        spin = func_00382498(-1, -3);
        p = func_L01_004713C8(&position, &velocity, life, 0x5A182, spin, 64, 0, 0, 84000.0f, 189000.0f, 0.009600000455975533f);
        if (p) {
            p[3] = func_00382468(2) ? 0x48 : 0x44;
            p[2] = *D_L01_002210F4[0];
        }
    }
    if (func_00382468(3) == 0) {
        s32 life;
        func_00382580(&velocity, 0.01f, 0.04f);
        func_0038CE20((f32 *)&offset, (f32 *)&velocity, 10.0f);
        vec_add_ab(&position, &offset, self + 0x10);
        life = func_00382498(10, 30);
        life *= 5;
        life += 2;
        life /= 6;
        spin = func_00382498(-1, -3);
        p = func_L01_004713C8(&position, &velocity, life, 0x5A182, spin, 64, 0, 0, 63000.00390625f, 42000.0f, 0.009600000455975533f);
        if (p) {
            p[3] = func_00382468(2) ? 0x48 : 0x44;
            p[2] = *D_L01_0022123C[0];
        }
    }
    if (func_00382468(3) == 0) {
        s32 life;
        func_00382580(&velocity, 0.01f, 0.03f);
        func_0038CE20((f32 *)&offset, (f32 *)&velocity, 10.0f);
        vec_add_ab(&position, &offset, self + 0x10);
        life = func_00382498(10, 30);
        life *= 5;
        life += 2;
        life /= 6;
        spin = func_00382498(-1, -3);
        p = func_L01_004713C8(&position, &velocity, life, 0x5A182, spin, 64, 0, 0, 63000.00390625f, 21000.0f, 0.009600000455975533f);
        if (p) {
            p[3] = func_00382468(2) ? 0x48 : 0x44;
            p[2] = *D_L01_00221120[0];
        }
    }
    if (func_00382468(3) == 0) {
        s32 life;
        func_00382580(&velocity, 0.01f, 0.03f);
        func_0038CE20((f32 *)&offset, (f32 *)&velocity, 20.0f);
        vec_add_ab(&position, &offset, self + 0x10);
        func_L01_004C7D98(self + 0x10, &direction);
        func_0038CF68((Vec4_0039E0C8 *)&direction, (Vec4_0039E0C8 *)&direction, -func_003824E0(0.01f, 0.05f));
        func_L01_00466F50(&position, &direction, 0x4005A182, -1.0f, -0.006000000052154064f);
    }
}
/* localdecomp:end func_L01_0039D2E0 */

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

/* localdecomp:start func_L01_0039DCB8 */
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec4_0039DCB8;
#include "vu0.h"
extern vu0_v4 D_L01_001E29C0;
extern f32 D_L01_001DE1D8[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DE1D8, 4");
extern f32 D_L01_001DE1E8[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DE1E8, 4");
extern f32 D_L01_001DE1F8[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DE1F8, 4");
extern s32 D_L01_001DE1BC, D_L01_001DE1C0;
extern s32 D_L01_001DE1C4, D_L01_001DE1C8;
extern s32 D_L01_001DE1CC, D_L01_001DE1D0;
extern s32 D_L01_001DE16C;
extern u8 *D_L01_00221098_0039DCB8[];
__asm__(".extern D_L01_001DE1BC, 4");
__asm__(".extern D_L01_001DE1C0, 4");
__asm__(".extern D_L01_001DE1C4, 4");
__asm__(".extern D_L01_001DE1C8, 4");
__asm__(".extern D_L01_001DE1CC, 4");
__asm__(".extern D_L01_001DE1D0, 4");
__asm__(".extern D_L01_001DE16C, 4");
typedef struct {
    u8 pad[0x47];
    u8 flag;
    s16 time[4];
    f32 angle[4];
} State_0039DCB8;

s32 func_L01_0039DCB8(u8 *obj) {
    extern void func_0038CF68_0039DCB8(void *, void *, f32);
    extern s32 func_0038CB00(void *);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern u8 *func_L01_0046C2E8(void *, s32, s32, s32, s32, s32, s32, s32, f32);
    Vec4_0039DCB8 va;
    Vec4_0039DCB8 vb;
    s32 found;
    State_0039DCB8 *st;
    s32 i;
    s32 x;
    s32 col;
    s32 al;
    s32 ah;
    f32 f1;
    f32 z;
    f32 d;
    f32 t;
    f32 keep;
    u8 *r;

    st = *(State_0039DCB8 **)(obj + 0x68);
    vec_sub_ab(&va, &D_L01_001E29C0, obj + 0x10);
    func_0038CF68_0039DCB8(&va, &va, -0.3f);
    found = 0;
    func_0038CF68_0039DCB8(&vb, &va, 0.1f);
    vec_add_ba(&va, &va, obj + 0x10);
    z = va.v[2];
    for (i = 0; i < 4; i++) {
        if (func_0038CB00(&st->time[i]) != 0) {
            continue;
        }
        f1 = st->angle[i] + D_L01_001DE1D8[i];
        if (st->time[i] >= 0x29) {
            found = 1;
        }
        st->angle[i] = f1;
        if (255.0f <= f1) {
            st->angle[i] = f1 - 255.0f;
        } else if (f1 <= 0.0f) {
            st->angle[i] = f1 + 255.0f;
        }
        keep = fabs_asm(0.5f - (f32)(0xD4 - st->time[i]) / 212.0f);
        if (st->flag != 0) {
            col = func_0038DBD8(D_L01_001DE1C4, D_L01_001DE1C8, keep);
        } else {
            col = func_0038DBD8(D_L01_001DE1BC, D_L01_001DE1C0, keep);
        }
        x = D_L01_001DE1D0;
        d = 1.0f - (f32)st->time[i] / (f32)((D_L01_001DE16C * 5 + 2) / 6);
        al = col >> 24;
        va.v[2] = z + D_L01_001DE1F8[i];
        t = 1.0f - d;
        al = (s32)((f32)al * t);
        ah = al << 24;
        r = func_L01_0046C2E8(&va, ah | (col & 0xFFFFFF),
                              (u8)(s32)st->angle[i], x, 0, 2, 1, 0,
                              D_L01_001DE1E8[i] * d);
        if (r != 0) {
            r[2] = *D_L01_00221098_0039DCB8[0xF8 / 4];
        }
        r = func_L01_0046C2E8(&va, ah | 0xFFFFFF,
                              (u8)(s32)st->angle[i], D_L01_001DE1D0, D_L01_001DE1CC, 2, 1, 0,
                              D_L01_001DE1E8[i] * (d * 0.7f));
        if (r != 0) {
            r[2] = *D_L01_00221098_0039DCB8[0xF8 / 4];
        }
        vec_add_ab(&va, &va, &vb);
    }
    return found;
}
/* localdecomp:end func_L01_0039DCB8 */

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
