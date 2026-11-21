/* functional: medium. Written from the PAL assembly (no draft existed); 547 words differ with the file's flags (same frame size 0x150, same jal list, near-identical instruction mix; qzero stands for retail's por+sq). Reads sp+0x20 uninitialised on two paths exactly as retail does (func_003C5180's output scratch). func_003C4B50's argument is the moby in a0, left over in retail. */
#include "vu0.h"
typedef struct { u8 pad[0x25C0]; u8 *moby; } Hero_0039C9E0;
extern Hero_0039C9E0 D_001A4BE0;
extern s32 D_L01_001D673C;
extern f32 D_L01_001DE0F8, D_L01_001DE0FC;
extern vu0_v4 D_L01_001EAA20[];
extern u8 D_L01_001EEA80[];
__asm__(".extern D_L01_001D673C, 4");
__asm__(".extern D_L01_001DE0F8, 4");
__asm__(".extern D_L01_001DE0FC, 4");
typedef struct {
    vu0_v4 start, pos, vel;
    u8 *obj;
    s32 *local;
    s32 mode;
    f32 f3c, f40, f44;
    s32 w48, w4c;
    u8 pad50[8];
    s32 w58;
} Sweep_0039C9E0;
void func_L01_0039C9E0(u8 *self)
{
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    extern void func_L01_0039D2E0(u8 *);
    extern s32 func_00382468(s32);
    extern void func_L01_004C7D98(void *, void *);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    extern void func_L01_0039D6E0(void *);
    extern void func_003C5180(void *, void *, s32);
    extern void func_L01_004CAC40(void *, void *);
    extern void func_L01_004C8688(s32, void *, s32);
    extern void func_L01_004C7D40(void *, void *, f32);
    extern s32 func_L01_004C7E70(void *, s32);
    extern u8 *func_00382348(void *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_003A52A0(s32, s32, void *);
    extern s32 func_003D4D00(void *, s32, void *, s32, f32);
    extern s32 func_003C4B50(void *);
    extern void func_L01_00446780(void *, void *, s32, s32, s32, s32, f32, f32, f32);
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern u8 *func_L01_0046B288(void *, s32, s32, s32, f32, f32);
    extern void *func_L01_003016B0(void *, s32, f32, f32);
    extern void func_L01_0043B9E8(void *, s32, s32, s32);
    extern u8 *func_L01_00468678(void *, void *, s32, f32, f32);
    extern void func_00382580(void *, f32, f32);
    extern void func_L01_00466F50(void *, void *, s32, f32, f32);
    extern void func_L01_004C8668(s32);
    extern void func_003C2880(void *);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_L01_004471A8(void *, f32);
    u8 *vars = *(u8 **)(self + 0x68);
    u8 st;
    vu0_v4 pos0;       /* sp+0x00 */
    s32 local[2];      /* sp+0x10 */
    vu0_v4 t;          /* sp+0x20 */
    Sweep_0039C9E0 sw; /* sp+0x30 */
    vu0_v4 p90, pa0, pb0;
    u8 *hit, *other;
    s32 i, n;
    f32 a, b, c, d;

    if (func_L01_004CB2D8()) func_L01_004CAB30(self + 0x10, self + 0x10);
    st = self[0x20];
    if (st == 0) { self[0x20] = 1; st = 1; }
    if (st == 1) {
        func_L01_0039D2E0(self);
        if (D_L01_001D673C == 0) {
            if (func_00382468(3) == 0) {
                func_L01_004C7D98(self + 0x10, &t);
                func_0038CF68((f32 *)&t, (f32 *)&t, -5.0f);
                vec_add_ba(&t, self + 0x10, &t);
                if (func_003D3CB0(self + 0x10, &t, 6, (s32)D_001A4BE0.moby, 0))
                    func_L01_0039D6E0(&D_L01_001EAA20[0]);
            }
        }
        pos0 = *(vu0_v4 *)(self + 0x10);
        func_003C5180(&pos0, &t, 1);
        vec_add_ba(self + 0x10, self + 0x10, vars);
        func_L01_004CAB30(self + 0x10, self + 0x10);
        func_L01_004CAC40(vars, vars);
        func_L01_004C8688(*(s32 *)(vars + 0x34), vars, 0);
        func_L01_004C7D40(self + 0x10, vars, 0.0048f);
        local[0] = 0;
        local[1] = 0xCE3;
        sw.start = pos0;
        sw.pos = *(vu0_v4 *)(self + 0x10);
        sw.vel = *(vu0_v4 *)vars;
        sw.obj = self;
        sw.local = local;
        sw.mode = 2;
        sw.f3c = 0.25f;
        sw.f40 = D_L01_001DE0F8;
        sw.f44 = D_L01_001DE0FC;
        sw.w48 = 0;
        sw.w4c = 0;
        sw.w58 = 0;
        n = func_L01_004C7E70(&sw, -1);
        if (n == 2) self[0x20] = 2;
        *(vu0_v4 *)(self + 0x10) = sw.pos;
        *(vu0_v4 *)vars = sw.vel;
        *(vu0_v4 *)(vars + 0x20) = sw.start;
        hit = sw.obj;
        if (hit != 0) {
            u8 kind = (*(u8 **)(hit + 0x24))[0x46];
            if (kind == 5 || kind == 9 || (*(u16 *)(hit + 0x34) & 0x4000)) {
                other = func_00382348(hit);
                func_L01_004C7D98(hit + 0x10, &pa0);
                p90 = *(vu0_v4 *)(self + 0x10);
                if (other) {
                    func_0038CE20((f32 *)&pb0, (f32 *)&pa0, *(f32 *)(other + 0x10));
                    vec_add_ab(&p90, &p90, &pb0);
                }
                func_0038CE20((f32 *)&pa0, (f32 *)&pa0, -3.0f);
                self[0x20] = 2;
                vec_add_ab(&pa0, &pa0, &p90);
                *(vu0_v4 *)(self + 0x10) = D_L01_001EAA20[0];
                *(vu0_v4 *)(vars + 0x20) = D_L01_001EAA20[2];
                func_0038CF68((f32 *)(vars + 0x20), (f32 *)(vars + 0x20), 1.0f);
                if (func_003D3CB0(&p90, &pa0, 6, (s32)hit, 0)) {
                    *(vu0_v4 *)(self + 0x10) = D_L01_001EAA20[0];
                    *(vu0_v4 *)(vars + 0x20) = D_L01_001EAA20[2];
                    func_0038CF68((f32 *)(vars + 0x20), (f32 *)(vars + 0x20), 1.0f);
                }
            }
        }
    } else if (st == 2) {
        func_003A52A0(0, 0, self);
        n = func_003D4D00(self + 0x10, 0, self, 0, 3.0f);
        {
            u8 **items = (u8 **)D_L01_001EEA80;
            for (; n > 0; n--, items++) {
                u8 *o = *items;
                other = func_00382348(o);
                if (other == 0) continue;
                if (o == 0) continue;
                if (*(u8 **)(o + 0x24) == 0) continue;
                if ((*(u8 **)(o + 0x24))[0x46] != 5) continue;
                if (o == D_001A4BE0.moby) continue;
                if (*(s16 *)(o + 0xAA) == 0x188A) continue;
                if (*(s16 *)(o + 0xAA) == 0x1886) continue;
                if (func_003C4B50(o) == 0) other[0x2F] = 1;
            }
        }
        func_L01_00446780(self, self + 0x10, 0x8000000, 0, 1, 0, 1.5f, 1.0f, 1.0f);
        if (D_L01_001D673C == 0) {
            for (i = 1; i >= 0; i--) {
                a = func_00382538();
                b = func_003824E0(0.0f, 0.6f);
                c = func_003824E0(0.0f, 1.5f);
                d = func_003824E0(1.5f, 5.0f);
                n = func_00382498(100, 160);
                t.x = func_0038D098(a) * b;
                t.y = func_0038D0B0(a) * b;
                t.z = 0.0f;
                vec_add_ba(&t, &t, self + 0x10);
                func_L01_0046B288(&t, 0x30305020, 0x182810, n, c, d);
            }
        }
        {
            void *r = func_L01_003016B0(self + 0x10, 5, func_003824E0(2.0f, 2.5f), 1.04f);
            if (r) func_L01_0043B9E8(r, 0x52, 0xD1, 5);
        }
        {
            u8 *pt;
            func_L01_004C7D98(self + 0x10, &t);
            func_0038CF68((f32 *)&t, (f32 *)&t, -1.0f);
            vec_add_ba(&t, self + 0x10, &t);
            qzero(&sw.pos);
            sw.pos.x = func_003824E0(-1.0f, 1.0f);
            sw.pos.y = func_003824E0(-1.0f, 1.0f);
            sw.pos.z = func_003824E0(0.5f, 1.0f);
            *(vu0_q *)&sw.start = *(vu0_q *)&sw.pos;
            func_0038CF68((f32 *)&sw.start, (f32 *)&sw.start, func_003824E0(0.004f, 0.012f));
            pt = func_L01_00468678(&t, &sw.start, 0x8810D162, func_003824E0(0.05f, 0.15f) * 210000.0f, *(f32 *)((u8 *)&D_001A4BE0 + 0x88) + 1.0f);
            if (pt) pt[3] = 0x44;
        }
        if (func_00382468(3) == 0) {
            func_00382580(&t, 0.01f, 0.03f);
            func_0038CE20((f32 *)&t, (f32 *)&t, 4.0f);
            func_L01_00466F50(self + 0x10, &t, 0x4005A182, -1.0f, -0.012f);
        }
        if (D_L01_001D673C == 0) {
            u8 *pt;
            a = func_00382538();
            b = func_003824E0(0.0f, 2.5f);
            c = func_003824E0(0.0f, 1.5f);
            d = func_003824E0(3.0f, 5.0f);
            n = func_00382498(100, 160);
            t.x = func_0038D098(a) * b;
            t.y = func_0038D0B0(a) * b;
            t.z = 0.0f;
            vec_add_ba(&t, &t, self + 0x10);
            pt = func_L01_0046B288(&t, 0x5005D152, 0x5D152, n, c, d);
            if (pt) pt[3] = 0x44;
        }
        func_L01_004C8668(*(s32 *)(vars + 0x34));
        func_003C2880(self);
        return;
    }
    *(f32 *)(self + 0xF0) = func_0038DAB8(*(f32 *)(self + 0xF0), *(f32 *)(vars + 0x10));
    *(f32 *)(self + 0xF4) = func_0038DAB8(*(f32 *)(self + 0xF4), *(f32 *)(vars + 0x14));
    func_L01_004471A8(self, 0.2f);
    if (*(f32 *)(self + 0x10) < 2.0f || *(f32 *)(self + 0x10) > 1021.0f ||
        *(f32 *)(self + 0x14) < 2.0f || *(f32 *)(self + 0x14) > 1021.0f ||
        *(f32 *)(self + 0x18) < 2.0f || *(f32 *)(self + 0x18) > 1021.0f) {
        func_L01_004C8668(*(s32 *)(vars + 0x34));
        func_003C2880(self);
    }
}
