/* func_L01_004BDF78 (Claude wave 14 r57, 2026-11-28). First draft kept here. */
/* PAL first draft (wave 14 r57, 2026-11-28): func_L01_004BDF78 (1852 B), written from retail with the
 * functional port's fields. Needs the existing line "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as":
 * retail loads 0.1f, 0.9f and 0.01f with Ps2EeAs's lui/ori/mtc1 (the file's GNU as line uses .lit4 lwc1,
 * so under the file's own line the count is large: 421, mostly misalignment). Cut: starts 8-aligned at
 * 0x004BDF78, ends 0x004BE6B4 + a 4-byte pad, so 0x004BDF78-0x004BE6B8 is 8-aligned at both ends (every
 * place: start 8-aligned, same size). NEEDS divs row 'func_L01_004BDF78 2 2 0 1 1'. With @ps2as and that
 * row (tools/check.py --flags @ps2as, diagnostic) 299 positional words differ but the unified diff is
 * small: (1) the two pad-counter resets D_L01_001E0F88/8C = 0 are absolute `lui $at; sw $zero` in retail
 * while their increments are $gp-relative (no plain-C form found that gives both from one name);
 * (2) the loop hoists 150.0f before 100.0f (retail: 100.0f first); (3) v0/v1 swapped for info/flag in
 * the scale computation and for the second f60 test; (4) the SN soft-double helpers fabs() expands to
 * (fptodp, dpcmp, dpsub = boot 0x00129A18/0x001294B8/0x00128F28) stay `jal 0` in the level check: the
 * level symbol tables have no address for those names. */
#include "common.h"

/* localdecomp:start func_L01_004BDF78 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_004BDF78;
typedef struct {
    u8 pad0[0x10];
    V4_004BDF78 pos;
    u8 pad20[3];
    u8 alpha;
    u8 *info;
    u8 pad28[4];
    f32 scale;
    u8 pad30[0xAA - 0x30];
    s16 kind;
    u8 padAC[0xF0 - 0xAC];
    f32 rx;
    f32 ry;
    f32 rz;
    u8 padFC[4];
} Obj_004BDF78;
typedef struct {
    s32 type;
    s32 timer;
    s32 pending;
    u8 pad0C[0x28 - 0x0C];
    u8 *anchor;
    Obj_004BDF78 *objs;
    u8 pad30[4];
    s32 nobjs;
    u8 pad38[0x50 - 0x38];
    s32 mode;
    u8 pad54[0x60 - 0x54];
    s32 f60;
    u8 pad64[0x6C - 0x64];
    s32 scroll;
    u8 pad70[0x84 - 0x70];
    s32 active;
    u8 shown;
    u8 locked;
    u8 pad8A[2];
    s32 fade;
    s32 alpha;
    f32 spin;
    s32 f98;
    s32 choice;
    s32 idle;
    f32 goalx;
    f32 goaly;
    f32 goalz;
    f32 rotx;
    f32 roty;
    f32 rotz;
    u8 padBC[4];
    u8 matrix[0x10];
    u8 xD0[0x10];
    u8 xE0[0x10];
} UI_004BDF78;
typedef struct {
    u8 pad0[0x140];
    f32 stickx;
    f32 sticky;
    u8 pad148[0x1C0 - 0x148];
    s32 held;
    s32 pressed;
} Pad_004BDF78;
extern UI_004BDF78 D_L01_002446C0_004BDF78;
extern Pad_004BDF78 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern Pad_004BDF78 *D_001D52FC_sda;
__asm__(".extern D_001D52FC_sda, 4");
extern f32 D_L01_001DAC50;
extern f32 D_L01_001DAD5C;
extern s32 D_L01_001DABA0;
extern s32 D_L01_001DABA8;
extern s32 D_L01_001DABD8;
extern s32 D_L01_001D7BE0;
extern s32 D_L01_001E0F88;
extern s32 D_L01_001E0F8C;
extern s32 D_L01_001E0F90;
__asm__(".extern D_L01_001DAC50, 4");
__asm__(".extern D_L01_001DAD5C, 4");
__asm__(".extern D_L01_001DABA0, 4");
__asm__(".extern D_L01_001DABA8, 4");
__asm__(".extern D_L01_001DABD8, 4");
__asm__(".extern D_L01_001D7BE0, 4");
__asm__(".extern D_L01_001E0F88, 4");
__asm__(".extern D_L01_001E0F8C, 4");
__asm__(".extern D_L01_001E0F90, 4");
extern s32 D_L01_001E0F7C;
__asm__(".extern D_L01_001E0F7C, 16");
extern u8 D_00143950[];
typedef struct { s32 id; u8 pad4[16]; } Item_004BDF78;
typedef struct { u8 pad0[0x4590]; Item_004BDF78 items[64]; } Toc_004BDF78;
extern Toc_004BDF78 D_00160C40_004BDF78;
extern s16 D_0016C6A4[];

void func_L01_004BDF78(void) {
    extern void func_L01_004C1460(s32);
    extern void func_L01_004C3840(s32);
    extern void func_L01_004C42D0(s32);
    extern void func_L01_004C4D90(s32);
    extern void func_L01_004C26A8(void);
    extern void func_003A2750(s32);
    extern void func_0039AA38(s32);
    extern void func_L01_0042D110(s32);
    extern void func_003E5520(void);
    extern void func_003CD058(void);
    extern void func_L01_004AB0E0(void);
    extern void func_L01_004E20E8(void);
    extern void func_003CD350(void);
    extern void func_003A0F98(s32, s32);
    extern void func_00396568(s32);
    extern void func_L01_003EB350(s32, void *);
    extern void func_L01_003EB3C0(s32, void *);
    extern void func_003D0B20(void);
    extern void func_003E55B8(void);
    extern void func_0038D000(void *, void *, void *);
    extern f32 func_L01_0040DF68(f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_003C7C38(void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_004BF980(void);
    extern void func_L01_004BDF08(void);
    extern void func_L01_004BD4A8(void);
    extern void func_L01_004C1EA0(void);
    extern void func_003AF498(void);
    extern void func_L01_00478898(void);
    extern void func_L01_004788D0(s32);
    extern void func_003A4288(void);
    extern double fabs(double);
    V4_004BDF78 t;
    Obj_004BDF78 *o;
    s32 i;
    s32 v;
    s32 c;
    f32 sx;
    f32 sy;
    f32 s;

    if (D_L01_001DAC50 < 1.0f) D_L01_001DAC50 = 1.0f;
    switch (D_L01_002446C0_004BDF78.type) {
    case 0:
        D_L01_001DAC50 += 0.1f;
        if (1.0f <= D_L01_001DAC50) {
            D_L01_002446C0_004BDF78.type = 1;
            D_L01_001DAC50 = 1.0f;
            D_L01_002446C0_004BDF78.timer = 0;
        }
        break;
    case 2:
        if (D_L01_002446C0_004BDF78.mode == 0) func_L01_004C1460(1);
        else if (D_L01_002446C0_004BDF78.mode == 3) func_L01_004C3840(1);
        else if (D_L01_002446C0_004BDF78.mode == 2) func_L01_004C42D0(1);
        else if (D_L01_002446C0_004BDF78.mode == 5) func_L01_004C4D90(1);
        D_L01_001DAC50 += 0.1f;
        D_L01_001E0F7C++;
        if (D_L01_001E0F7C >= 12) {
            func_L01_004C26A8();
            D_L01_001DAC50 = 1.0f;
            if (D_L01_002446C0_004BDF78.pending != 0) {
                c = D_L01_002446C0_004BDF78.choice;
                D_L01_002446C0_004BDF78.pending = 0;
                if (c >= 0) {
                    v = D_00160C40_004BDF78.items[c].id;
                    func_003A2750(1);
                    func_0039AA38(v);
                    func_003A2750(1);
                    func_L01_0042D110(v);
                } else {
                    D_0016C6A4[0] = -1;
                }
            }
            D_L01_002446C0_004BDF78.timer = 0;
            if (D_L01_002446C0_004BDF78.f60 == 0) {
                func_003E5520();
                func_003CD058();
                func_L01_004AB0E0();
                func_L01_004E20E8();
                func_003CD350();
            }
            if (D_L01_001DABD8 > 0) func_003A0F98(D_L01_001DABD8, 0);
            else func_003A0F98(0, 0);
            func_00396568(1);
            if (D_L01_002446C0_004BDF78.f60 == 0) {
                func_L01_003EB350(0, D_L01_002446C0_004BDF78.xD0);
                func_L01_003EB3C0(0, D_L01_002446C0_004BDF78.xE0);
            }
            func_003D0B20();
            func_003E55B8();
            if (D_L01_002446C0_004BDF78.mode == 5) D_L01_001D7BE0 = D_L01_001DABA8;
        }
        break;
    case 1:
        if (D_001D52FC->held & 0x8000) D_L01_001E0F88++;
        else D_L01_001E0F88 = 0;
        if (D_001D52FC->held & 0x2000) D_L01_001E0F8C++;
        else D_L01_001E0F8C = 0;
        if (D_L01_002446C0_004BDF78.fade == 0) {
            D_L01_002446C0_004BDF78.alpha += 3;
            if (D_L01_002446C0_004BDF78.alpha >= 0x80) {
                D_L01_002446C0_004BDF78.alpha = 0x80;
                D_L01_002446C0_004BDF78.fade = 2;
            }
        } else if (D_L01_002446C0_004BDF78.fade == 1) {
            D_L01_002446C0_004BDF78.spin *= 0.9f;
            D_L01_002446C0_004BDF78.alpha -= 16;
            if (D_L01_002446C0_004BDF78.alpha <= 0) {
                D_L01_001DABA0--;
                if (D_L01_001DABA0 <= 0) {
                    D_L01_002446C0_004BDF78.fade = 3;
                    D_L01_001DABA0 = 4;
                }
                D_L01_002446C0_004BDF78.alpha = 0;
                D_L01_002446C0_004BDF78.spin = 0.0f;
            }
        }
        if (D_L01_002446C0_004BDF78.shown && D_L01_002446C0_004BDF78.mode != 0) {
            for (i = 0; i < D_L01_002446C0_004BDF78.nobjs; i++) {
                o = &D_L01_002446C0_004BDF78.objs[i];
                func_0038D000(&o->pos, D_L01_002446C0_004BDF78.matrix, D_L01_002446C0_004BDF78.anchor + 0xC0);
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                        : "=m"(o->pos) : "m"(o->pos), "m"(*(V4_004BDF78 *)(D_L01_002446C0_004BDF78.anchor + 0x10))
                        : "vf1", "vf2");
                s = *(f32 *)(o->info + 0x24) * D_L01_002446C0_004BDF78.spin;
                if (D_00143950[0xAD]) s = s * D_L01_001DAD5C;
                o->scale = s;
                if (o->kind == 0x10E3) o->alpha = D_L01_002446C0_004BDF78.alpha / 2;
                else o->alpha = D_L01_002446C0_004BDF78.alpha;
                if (D_L01_002446C0_004BDF78.mode != 2) {
                    o->rz = func_0038DAB8(o->rz, func_L01_0040DF68(0.01f));
                } else {
                    sy = D_001D52FC_sda->stickx / 100.0f;
                    sx = D_001D52FC_sda->sticky / 100.0f;
                    if (D_L01_002446C0_004BDF78.idle <= 0 || D_L01_002446C0_004BDF78.active != 0) {
                        D_L01_002446C0_004BDF78.rotx = func_0038DAB8(D_L01_002446C0_004BDF78.rotx,
                            (D_L01_002446C0_004BDF78.goalx - D_L01_002446C0_004BDF78.rotx) / 150.0f);
                        D_L01_002446C0_004BDF78.roty = func_0038DAB8(D_L01_002446C0_004BDF78.roty,
                            (D_L01_002446C0_004BDF78.goaly - D_L01_002446C0_004BDF78.roty) / 150.0f);
                        D_L01_002446C0_004BDF78.rotz = func_0038DAB8(D_L01_002446C0_004BDF78.rotz,
                            (D_L01_002446C0_004BDF78.goalz - D_L01_002446C0_004BDF78.rotz) / 150.0f);
                    } else {
                        D_L01_002446C0_004BDF78.rotz = func_0038DAB8(D_L01_002446C0_004BDF78.rotz, sy);
                        D_L01_002446C0_004BDF78.roty = func_0038DAB8(D_L01_002446C0_004BDF78.roty, sx);
                    }
                    o->rx = D_L01_002446C0_004BDF78.rotx;
                    o->ry = D_L01_002446C0_004BDF78.roty;
                    o->rz = D_L01_002446C0_004BDF78.rotz;
                    if (fabs(sy) > 0.0001f || fabs(sx) > 0.0001f) D_L01_002446C0_004BDF78.idle = 180;
                }
                func_003C7C38(o);
                if (D_L01_002446C0_004BDF78.mode != 2 && D_L01_002446C0_004BDF78.mode != 5
                    && D_L01_002446C0_004BDF78.mode != 3) {
                    func_0038CE20(&t, o, 0.0009765625f);
                    o->pos.x = o->pos.x + (o->pos.x - t.x);
                    o->pos.y = o->pos.y + (o->pos.y - t.y);
                    func_003C7C38(o);
                }
            }
            if (D_L01_002446C0_004BDF78.idle > 0) D_L01_002446C0_004BDF78.idle--;
        }
        if (!D_L01_002446C0_004BDF78.locked && D_L01_002446C0_004BDF78.fade == 3
            && D_L01_002446C0_004BDF78.active == 0 && D_L01_002446C0_004BDF78.scroll == 0) {
            func_L01_004BF980();
        }
        D_L01_002446C0_004BDF78.timer++;
        func_L01_004BDF08();
        func_L01_004BD4A8();
        func_L01_004C1EA0();
        D_L01_001E0F90 = D_001D52FC->pressed;
        func_00396568(1);
        func_003AF498();
        func_L01_00478898();
        func_L01_004788D0(0);
        break;
    }
    func_003A4288();
}
/* localdecomp:end func_L01_004BDF78 */
