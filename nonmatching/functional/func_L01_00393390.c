/* functional: high. 191 diff = stack slot/register assignment only. Verified loop counts, constants (0.865, 0.125, 2.0, 0.25, -0.001052), each vadd/vsub operand order, cross/dot args and the culling test against asm */
#include "common.h"
#include "vu0.h"
typedef struct {
    vu0_v4 position[4];
    u32 color[4];
    f32 uv[4][2];
    unsigned long zero, texture, primitive, mode;
} Draw_00393390;
typedef struct {
    u8 pad0[0x10]; f32 scale;
    u8 pad14[8]; s32 alpha;
} P_00393390;
typedef struct {
    u8 pad0[0x10]; vu0_v4 pos;
    u8 pad20[0x48]; P_00393390 *p;
    u8 pad6C[0x54]; f32 matrix[12];
} M_00393390;
extern s32 D_L01_001DE024, D_L01_001DE028, D_L01_001DE02C, D_L01_001DE030, D_L01_001DE034;
extern s32 D_L01_001DE038, D_L01_001DE03C;
extern f32 D_L01_001DE040, D_L01_001DDFF8, D_L01_001DDFFC;
__asm__(".extern D_L01_001DE024, 4");
__asm__(".extern D_L01_001DE028, 4");
__asm__(".extern D_L01_001DE02C, 4");
__asm__(".extern D_L01_001DE030, 4");
__asm__(".extern D_L01_001DE034, 4");
__asm__(".extern D_L01_001DE038, 4");
__asm__(".extern D_L01_001DE03C, 4");
__asm__(".extern D_L01_001DE040, 4");
__asm__(".extern D_L01_001DDFF8, 4");
__asm__(".extern D_L01_001DDFFC, 4");
typedef struct { s16 vertex, uv; } Pair_00393390;
extern Pair_00393390 D_L01_002B8400[][4];
extern f32 D_L01_002B7720[][4];
extern f32 D_L01_002B9180[];
extern f32 D_L01_002B9184[];
extern vu0_v4 D_L01_001E2A40;
__asm__(".extern D_L01_001E2A40, 16");

static __inline__ void add_00393390(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 vf2, %2\n\tlqc2 vf1, %1\n\tvadd.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void sub_ab_00393390(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvsub.xyz vf2, vf2, vf1\n\tsqc2 vf2, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void sub_ba_00393390(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 vf1, %2\n\tlqc2 vf2, %1\n\tvsub.xyz vf2, vf2, vf1\n\tsqc2 vf2, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}

void func_L01_00393390(u8 *m) {
    extern unsigned long func_00389598(s32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038D000(f32 *, f32 *, f32 *);
    extern f32 func_0038D098(f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(f32 *, f32 *, f32 *);
    extern f32 func_0038CE68(f32 *, f32 *);
    extern void func_003D2DA0(void *, s32, s32);
    Draw_00393390 draw;
    vu0_v4 mat[3];
    vu0_v4 direction;
    vu0_v4 normal;
    vu0_v4 edge1;
    vu0_v4 edge2;
    M_00393390 *mob = (M_00393390 *)m;
    P_00393390 *p = mob->p;
    s32 i, j;
    f32 threshold = -0.0010519999777898192f;
    f32 *vertex;
    s32 uvindex;
    draw.texture = func_00389598(D_L01_001DE038);
    draw.primitive = 0xFF9000000260;
    draw.mode = (unsigned long)D_L01_001DE024 | ((unsigned long)D_L01_001DE028 << 2) |
        ((unsigned long)D_L01_001DE02C << 4) | ((unsigned long)D_L01_001DE030 << 6) |
        ((unsigned long)D_L01_001DE034 << 32);
    draw.zero = 0;
    draw.color[0] = draw.color[1] = draw.color[2] = draw.color[3] =
        D_L01_001DE03C + (p->alpha << 24);
    qzero(&mat[0]); qzero(&mat[1]); qzero(&mat[2]);
    mat[0].x = 1.0f;
    mat[1].y = 1.0f;
    mat[2].z = p->scale * 0.865f;
    for (i = 0; i < 215; i++) {
        for (j = 0; j < 4; j++) {
            vertex = D_L01_002B7720[D_L01_002B8400[i][j].vertex];
            uvindex = D_L01_002B8400[i][j].uv;
            func_0038CE20((f32 *)&draw.position[j], vertex, D_L01_001DE040);
            {
                f32 u = D_L01_002B9180[uvindex * 2] + D_L01_001DDFF8;
                f32 vv = D_L01_002B9184[uvindex * 2] + D_L01_001DDFFC;
                draw.uv[j][0] = u;
                draw.uv[j][1] = vv;
            }
            if (vertex[2] == threshold) {
                draw.color[j] = D_L01_001DE03C;
            } else {
                draw.color[j] = D_L01_001DE03C | (p->alpha << 24);
            }
        }
        func_0038D000((f32 *)&draw.position[0], (f32 *)&draw.position[0], (f32 *)mat);
        func_0038D000((f32 *)&draw.position[1], (f32 *)&draw.position[1], (f32 *)mat);
        func_0038D000((f32 *)&draw.position[2], (f32 *)&draw.position[2], (f32 *)mat);
        func_0038D000((f32 *)&draw.position[3], (f32 *)&draw.position[3], (f32 *)mat);
        { f32 *point, *uv2;
        qzero(&normal);
        point = (f32 *)draw.position;
        uv2 = (f32 *)draw.uv;
        j = 3;
        do {
            uv2[0] -= point[2] * 0.125f;
            point[0] *= func_0038D098(point[2]) + 2.0f;
            point[1] *= func_0038D098(point[2]) + 2.0f;
            func_0038D000(point, point, mob->matrix);
            {
                f32 px = mob->pos.x, py = mob->pos.y, pz = mob->pos.z;
                point[0] += px;
                point[1] += py;
                point[2] += pz;
            }
            add_00393390(&normal, &normal, (vu0_v4 *)point);
            point += 4;
            uv2 += 2;
        } while (--j >= 0);
        }
        func_0038CE20((f32 *)&normal, (f32 *)&normal, 0.25f);
        sub_ab_00393390(&direction, &normal, &D_L01_001E2A40);
        func_0038CF68(&direction, &direction, 1.0f);
        sub_ba_00393390(&edge1, &draw.position[2], &draw.position[0]);
        sub_ab_00393390(&edge2, &draw.position[2], &draw.position[1]);
        func_0038CE90((f32 *)&normal, (f32 *)&edge1, (f32 *)&edge2);
        func_0038CF68(&normal, &normal, 1.0f);
        if (func_0038CE68((f32 *)&direction, (f32 *)&normal) > 0.0f)
            func_003D2DA0(&draw, 0, 0);
    }
}
