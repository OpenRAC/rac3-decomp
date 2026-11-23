/* functional: medium. Written from the disassembly (no draft), compiled in context, not byte-compared (618 diff words: VU0 and lq/sq written as scalar and u128 C). Update function of the 0x1DCE projectile spawned by func_L01_003DCAA0; func_L01_003DDDA8 is called with a third argument (hit moby) that the file's draft signature lacks, so it is declared locally; the scratch damage record at sp+0x80 is built as retail does but never read. */
#include "common.h"
/* localdecomp:start func_L01_003DD0F8 */
typedef struct { f32 x, y, z, w; } V4_003DD0F8 __attribute__((aligned(16)));
typedef struct {
    f32 pos[3];
    u8 *owner;         /* 0x0C */
    u128_t trail[4];   /* 0x10: previous positions, shifted every frame */
    u128_t velocity;   /* 0x50 */
    u8 *source;        /* 0x60 */
    f32 zoff;          /* 0x64 */
    f32 f68, f6C, f70;
    u16 timer74;       /* 0x74: func_0038CB00 timer */
    u8 b76, b77;       /* 0x76, 0x77: b77 counts frames */
    f32 f78;
    u8 p7C[4];
    u128_t basis;      /* 0x80 */
    u128_t dir;        /* 0x90 */
    s32 mark;          /* 0xA0 */
    s32 handle;        /* 0xA4 */
    s32 timerA8;       /* 0xA8: func_0038CAD0 timer */
    s32 lifeAC;
    u8 pB0[0x0C];
    s32 extra;         /* 0xBC */
} Fx_003DD0F8;
extern u8 D_001A4BE0[];
extern u8 D_001A30B0[];
extern u8 D_L01_001EAA00[];
extern u8 D_L01_001E0140[];
extern u8 D_L01_002C5600[];
extern u8 D_001425C0[];
extern u8 D_00142657[];
void func_L01_003DD0F8(u8 *obj) {
    extern void func_003C5180(void *, void *, s32);
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    extern s32 func_0038CAD0(void *);
    extern s32 func_0038CB00(void *);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern u8 *func_00382348(u8 *);
    extern void func_L01_004C8688(s32, void *, s32);
    extern void func_L01_004C8668(s32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CF00(void *, void *);
    extern f32 func_0038CF38(void *, void *);
    extern f32 func_0038CE68(void *, void *);
    extern void func_L01_004CB128(void *, void *, s32);
    extern void func_003C4840(void *, void *, f32);
    extern void func_0038D850(void *, void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_L01_003DEFE8(void *);
    extern void func_L01_0044BEC8(u8 *, void *);
    extern void func_L01_003DE418(u8 *, void *);
    extern void func_L01_003DE488(u8 *);
    extern void func_L01_00404A10(void (*)(u8 *), void *);
    extern void func_L01_003DE1D8(u8 *, void *);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern void func_L01_003DDDA8(u8 *, void *, u8 *);
    extern void func_003C3D30(void *, s32, s32, f32);
    extern void func_003A4F28(s32);
    extern void func_003C2880(u8 *);
    V4_003DD0F8 oldpos, gnd[2], t30, t40, t50, t60, t70, gh[2];
    u8 rec[0x30] __attribute__((aligned(16)));
    Fx_003DD0F8 *v;
    u8 *source, *h, *row, *tbl, *hit;
    f32 d;
    s32 i, a, w, mark;
    v = *(Fx_003DD0F8 **)(obj + 0x68);
    source = v->source;
    *(u128_t *)&oldpos = *(u128_t *)(obj + 0x10);
    hit = 0;
    func_003C5180(obj + 0x10, &gnd[0], 1);
    if (func_L01_004CB2D8() != 0) func_L01_004CAB30(obj + 0x10, obj + 0x10);
    if (func_0038CAD0(&v->timerA8) == 0) {
        u8 *owner = v->owner;
        *(u128_t *)(obj + 0x10) = *(u128_t *)(owner + 0x10);
        return;
    }
    for (i = 3; i > 0; i--)
        func_0038CDF8((u8 *)&v->trail[i], (u8 *)&v->trail[i], (u8 *)&v->trail[i - 1], 0.20000000298023224f);
    v->trail[0] = *(u128_t *)(obj + 0x10);
    if (source != 0) {
        h = func_00382348(source);
        if ((*(u16 *)(source + 0x34) & 2) || source[0x20] == 0xFE || source[0x20] == 0xFD || source[0x31] == 0 ||
            (h != 0 && *(f32 *)h <= 0.0f)) {
            v->source = 0;
            source = 0;
        }
    }
    func_L01_004C8688(v->handle, &v->basis, 0);
    *(u128_t *)(obj + 0xC0) = *(u128_t *)&v->basis;
    func_0038CE90(obj + 0xD0, obj + 0xC0, &gnd[0]);
    func_0038CF68(obj + 0xD0, obj + 0xD0, 1.0f);
    func_0038CE90(obj + 0xE0, obj + 0xD0, obj + 0xC0);
    if (source != 0) {
        v->pos[0] = gnd[1].x;
        v->pos[1] = gnd[1].y;
        v->pos[2] = gnd[1].z;
    }
    {
        f32 spin = v->f6C;
        if (spin < 0) spin = -spin;
        if (0.003100000089034438f < spin) {
            *(u128_t *)&t30 = *(u128_t *)(obj + 0xC0);
            func_003C4840(&t40, obj + 0xD0, v->f6C * 0.01745329238474369f);
            func_0038D850(obj + 0xC0, obj + 0xC0, &t40);
            func_0038D850(obj + 0xE0, obj + 0xE0, &t40);
            func_003C4840(&t40, &t30, v->f78);
            func_0038D850(obj + 0xC0, obj + 0xC0, &t40);
            func_0038D850(obj + 0xD0, obj + 0xD0, &t40);
            func_0038D850(obj + 0xE0, obj + 0xE0, &t40);
            func_003C4840(&t40, obj + 0xC0, v->f78);
            func_0038D850(obj + 0xD0, obj + 0xD0, &t40);
            func_0038D850(obj + 0xE0, obj + 0xE0, &t40);
            v->f78 = func_0038DAB8(v->f78, v->f70 * 0.01745329238474369f);
        }
    }
    *(f32 *)(obj + 0xCC) = 0.0f;
    *(f32 *)(obj + 0xEC) = 0.0f;
    *(f32 *)(obj + 0xDC) = 0.0f;
    if (source != 0) {
        func_0038CE20(&t30, obj + 0xC0, v->f68);
        *(f32 *)(obj + 0x10) = *(f32 *)(obj + 0x10) + t30.x;
        *(f32 *)(obj + 0x14) = *(f32 *)(obj + 0x14) + t30.y;
        *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) + t30.z;
        d = func_0038CF00(source + 0x10, obj + 0x10);
        if (d < 5.0f) {
            func_L01_004CB128(&t50, source, 0);
            t40.x = t50.x - *(f32 *)(obj + 0x10);
            t40.y = t50.y - *(f32 *)(obj + 0x14);
            t40.z = t50.z - *(f32 *)(obj + 0x18);
            t40.w = t50.w;
            func_0038CF68(&t30, &t40, v->f68);
            *(f32 *)(obj + 0x10) = *(f32 *)(obj + 0x10) + t30.x;
            *(f32 *)(obj + 0x14) = *(f32 *)(obj + 0x14) + t30.y;
            *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) + t30.z;
            func_L01_004CAB30(obj + 0x10, obj + 0x10);
        }
    } else {
        row = D_L01_002C5600 + D_00142657[0] * 0xF0;
        func_0038CE20(&t30, obj + 0xC0, v->f68);
        *(f32 *)(obj + 0x10) = *(f32 *)(obj + 0x10) + t30.x;
        *(f32 *)(obj + 0x14) = *(f32 *)(obj + 0x14) + t30.y;
        *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) + t30.z;
        if (!(row[1] < 4)) {
            t40.x = *(f32 *)&v->velocity - *(f32 *)(obj + 0x10);
            t40.y = ((f32 *)&v->velocity)[1] - *(f32 *)(obj + 0x14);
            t40.z = ((f32 *)&v->velocity)[2] - *(f32 *)(obj + 0x18);
            t40.w = ((f32 *)&v->velocity)[3];
            func_0038CF68(&t30, &t40, v->f68);
            *(f32 *)(obj + 0x10) = *(f32 *)(obj + 0x10) + t30.x;
            *(f32 *)(obj + 0x14) = *(f32 *)(obj + 0x14) + t30.y;
            *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) + t30.z;
            func_L01_004CAB30(obj + 0x10, obj + 0x10);
            if (v->extra != 0) {
                v->extra = 0;
                func_L01_003DEFE8(&v->velocity);
            }
        }
    }
    if (*(f32 *)(obj + 0x10) < 2.0f || 1021.0f < *(f32 *)(obj + 0x10) || *(f32 *)(obj + 0x14) < 2.0f ||
        1021.0f < *(f32 *)(obj + 0x14) || *(f32 *)(obj + 0x18) < 2.0f || 1021.0f < *(f32 *)(obj + 0x18)) {
        func_L01_0044BEC8(obj, D_L01_001E0140);
        func_003C2880(obj);
        return;
    }
    func_L01_003DE418(obj, &t40);
    v->b77 = v->b77 + 1;
    if (!(v->b77 < 4)) func_L01_00404A10(func_L01_003DE488, obj);
    row = D_L01_002C5600 + D_001425C0[0x97] * 0xF0;
    if (!(row[1] < 2)) func_L01_003DE1D8(obj, &oldpos);
    *(u128_t *)&t50 = *(u128_t *)(obj + 0x10);
    func_0038CE20(&t60, &gnd[0], -0.30000001192092896f);
    t60.x = *(f32 *)(obj + 0x10) + t60.x;
    t60.y = *(f32 *)(obj + 0x14) + t60.y;
    t60.z = *(f32 *)(obj + 0x18) + t60.z;
    if (func_003D3CB0(&t50, &t60, 2, 0, 0) != 0) {
        func_0038CE20(&t50, &gnd[0], 0.30000001192092896f);
        *(f32 *)(obj + 0x10) = *(f32 *)(D_L01_001EAA00 + 0x20) + t50.x;
        *(f32 *)(obj + 0x14) = *(f32 *)(D_L01_001EAA00 + 0x24) + t50.y;
        *(f32 *)(obj + 0x18) = *(f32 *)(D_L01_001EAA00 + 0x28) + t50.z;
    }
    /* scratch damage record, built by retail but never read afterwards */
    *(s32 *)(rec + 0x04) = 0x1030000;
    *(s32 *)(rec + 0x10) = 1;
    *(u8 **)(rec + 0x00) = obj;
    *(f32 *)(rec + 0x0C) = *(f32 *)(D_L01_002C5600 + D_001425C0[0x97] * 0xF0 + 0x6C);
    if (*(u16 *)(obj + 0x34) & 0x100) {
        *(u128_t *)(rec + 0x20) = *(u128_t *)&t30;
    } else {
        *(f32 *)(rec + 0x20) = func_0038D098(*(f32 *)(obj + 0xF8));
        *(f32 *)(rec + 0x24) = func_0038D0B0(*(f32 *)(obj + 0xF8));
        *(s32 *)(rec + 0x28) = 0;
    }
    *(f32 *)(rec + 0x2C) = 5627.9248046875f;
    *(f32 *)(rec + 0x28) = 1.5f;
    *(u128_t *)&t70 = *(u128_t *)(rec + 0x20);
    func_0038CF68(&t70, &t70, 1.0f);
    *(u16 *)(rec + 0x0A) = *(u16 *)(obj + 0xAA);
    t70.w = 5627.9248046875f;
    rec[8] = 3;
    rec[9] = 1;
    if (func_003D3CB0(&oldpos, obj + 0x10, 0, *(u8 **)(D_001A4BE0 + 0x25C0), 0) != 0) {
        tbl = D_L01_001EAA00;
        w = *(s32 *)(tbl + 0x18);
        a = 0;
        if (w == 0) {
            if (*(s32 *)(tbl + 0x1C) > 0) { obj[0xBC] = 1; a = 1; }
        } else if (w == *(s32 *)(D_001A4BE0 + 0x25C0)) {
        } else if (w == (s32)v->owner) {
            a = 0;
        } else {
            hit = obj;
            obj[0xBC] = 2;
            a = 1;
        }
        if (a) *(u128_t *)(obj + 0x10) = *(u128_t *)(tbl + 0x20);
    }
    if (obj[0xBC] != 0) {
        s32 want = 1;
        *(u128_t *)(obj + 0x10) = *(u128_t *)(D_L01_001EAA00 + 0x20);
        func_003C5180(obj + 0x10, &gh[0], 1);
        if (*(s32 *)(D_L01_001EAA00 + 0x18) == 0 || *(s32 *)(D_L01_001EAA00 + 0x1C) > 0) {
            func_0038CF68(&gh[1], D_L01_001EAA00 + 0x40, 1.0f);
            d = func_0038CE68(&gh[1], &gh[0]);
            if (d < 0) d = -d;
            if (0.10000000149011612f <= d) want = 0;
        } else {
            gh[1].x = ((f32 *)&D_L01_001E29C0)[0] - *(f32 *)(obj + 0x10);
            gh[1].y = ((f32 *)&D_L01_001E29C0)[1] - *(f32 *)(obj + 0x14);
            gh[1].z = ((f32 *)&D_L01_001E29C0)[2] - *(f32 *)(obj + 0x18);
            gh[1].w = ((f32 *)&D_L01_001E29C0)[3];
            func_0038CF68(&gh[1], &gh[1], 1.0f);
        }
        if (want) func_003C3D30(obj + 0x10, 0, 0, 0.5f);
        func_L01_003DDDA8(obj, &gh[0], hit);
        func_L01_0044BEC8(obj, D_L01_001E0140);
        func_L01_004C8668(v->handle);
        func_003C2880(obj);
        return;
    }
    if (func_0038CB00(&v->timer74) == 0) {
        d = func_0038CF38(obj + 0x10, D_001A4BE0 + 0x80);
        if (!(60.0f < d)) return;
    }
    mark = v->mark;
    if (mark != -1) {
        u8 *rc = D_001A30B0 + (mark << 7);
        if (*(u8 **)(rc + 0xDC) == obj && rc[0xD0] != 0) func_003A4F28(mark);
    }
    v->mark = -1;
    func_L01_0044BEC8(obj, D_L01_001E0140);
    func_L01_004C8668(v->handle);
    func_003C2880(obj);
}
/* localdecomp:end func_L01_003DD0F8 */
