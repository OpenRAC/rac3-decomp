#include "common.h"

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6F78 - 0x4958];
    u8 f6F78[1];
} S_499898;
typedef struct Obj Obj;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj *);
} ObjVt;
struct Obj {
    s32 pad;
    ObjVt *vt;
};
typedef struct { s32 w0; s32 w4; s32 w8; s32 *list; s32 state; u8 flag; u8 pad15[3]; } E_4999A0;

/* localdecomp:start func_L01_0049CF68 */
extern void func_L01_0047DAD0(s32);
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);
extern s32 func_L01_0049C630(void);
extern void func_L01_00516090_0049CF68(s32);
void func_L01_0049CF68(void) {
    func_L01_0047DAD0(8);
    func_L01_00517748(func_L01_0047EBE0());
    func_L01_00516090_0049CF68(func_L01_0049C630());
}
/* localdecomp:end func_L01_0049CF68 */

/* localdecomp:start func_L01_0049CFA8 */
__asm__(".extern D_L01_001D9474, 4");
__asm__(".extern D_L01_001D9478, 4");
extern s32 D_L01_001D9474;
extern s32 D_L01_001D9478;
extern u8 D_L01_001EA7C0_0049CFA8[];
extern E_4999A0 D_L01_002EC368[];
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C58(s32);
extern s32 func_00392B20(u8 *, s32);
void func_L01_0049CFA8(void) {
    s32 i = 0;
    s32 st;
    if (D_L01_002EC368[D_L01_001D9478].flag != 0) {
        st = D_L01_002EC368[D_L01_001D9478].state;
        if (st != 1) {
            if (st < 2) {
                if (st == 0) {
                    D_L01_001D9474 = func_003B9C58(func_003B9BD0(0));
                    func_00392B20(D_L01_001EA7C0_0049CFA8, (s32)D_L01_002EC368[D_L01_001D9478].list);
                    func_L01_0049CF68();
                }
            }
        } else {
            D_L01_001D9474 = func_003B9C58(func_003B9BD0(0));
            if (D_L01_002EC368[D_L01_001D9478].list[0] != 0) {
                do {
                    func_00392B20(D_L01_001EA7C0_0049CFA8, D_L01_002EC368[D_L01_001D9478].list[i]);
                    i++;
                } while (D_L01_002EC368[D_L01_001D9478].list[i] != 0);
            }
            func_L01_0049CF68();
        }
    }
}
/* localdecomp:end func_L01_0049CFA8 */

/* localdecomp:start func_L01_0049D0F8 */
__asm__(".extern D_L01_001D947C, 4");
__asm__(".extern D_L01_001D9480, 4");
extern S_499898 D_00160C40[];
extern void *D_L01_001D947C;
extern void *D_L01_001D9480;
extern void *func_003BB3A8(s32);
extern void *func_003B42F8(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
void func_L01_0049D0F8(void) {
    D_L01_001D947C = func_003BB3A8(0);
    D_L01_001D9480 = func_003BB3A8(0);
    func_003B4528(func_003B42F8(1), (s32)D_L01_001D947C, (s32)D_L01_001D9480, D_00160C40->f4954, (s32)D_00160C40->f6F78);
}
/* localdecomp:end func_L01_0049D0F8 */

/* localdecomp:start func_L01_0049D150 */
extern void *func_003B42F8(s32);
extern void *D_L01_001D9480;
extern void *D_L01_001D947C;

extern void func_003BB468(s32);

void func_L01_0049D150(void) {
    Obj *o = ((Obj * (*)(s32))func_003B42F8)(1);
    o->vt->fn(o);
    func_003BB468((*(s32 *)&D_L01_001D947C));
    func_003BB468((*(s32 *)&D_L01_001D9480));
}
/* localdecomp:end func_L01_0049D150 */

/* localdecomp:start func_L01_0049D190 */
typedef struct { u8 pad0[0x1C4]; u32 w1C4; } S_0049D190;
extern S_0049D190 *D_001D52FC_0049D190;
extern void func_L01_0049CFA8(void);
extern s32 func_L01_0049B550(void);
extern void func_L01_00517748(s32);
extern void func_L01_00516090_0049D190(void *);

void func_L01_0049D190(void *a) {
    if (D_001D52FC_0049D190->w1C4 & 0x40) {
        func_L01_0049CFA8();
    }
    if (D_001D52FC_0049D190->w1C4 & 0x910) {
        func_L01_00517748(func_L01_0049B550());
        func_L01_00516090_0049D190(a);
    }
}
/* localdecomp:end func_L01_0049D190 */

/* localdecomp:start func_L01_0049D200 */
__asm__(".extern D_L01_001D946C, 4");
__asm__(".extern D_L01_001D9478, 4");
__asm__(".extern D_L01_001D9468, 4");
__asm__(".extern D_L01_001D94B4, 4");
extern s32 D_L01_001D946C;
extern s32 D_L01_001D9478;
extern s32 D_L01_001D9468;
extern s32 D_L01_001D94B4;
extern s32 D_L01_002EC1D8[];
extern E_4999A0 D_L01_002EC368[];
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C58(s32);
extern s32 func_00381FF0(s32);
extern s32 func_L01_00516FD8(s32, s32);
extern void func_L01_00517190(s32, s32);
extern void func_L01_00516D60(s32, s32);
void func_L01_0049D200(void) {
    s32 *t;
    if (D_L01_001D946C != 0) {
        t = D_L01_002EC1D8;
        D_L01_001D9478 = t[func_003B9C58(func_003B9BD0(0))];
    }
    if (D_L01_001D9478 < 0) {
        return;
    }
    if (D_L01_001D9468 != D_L01_001D9478) {
        func_L01_00516FD8(0x4E0006, func_00381FF0(((E_4999A0 *)(D_L01_001D9478 * 24 + (s32)D_L01_002EC368))->w0));
        D_L01_001D94B4 = 30;
    }
    if (D_L01_001D94B4 != 0 && --D_L01_001D94B4 == 0) {
        func_L01_00517190(0x4E0003, D_L01_002EC368[D_L01_001D9478].w8 + 1);
        func_L01_00516D60(0x4E0003, 1);
    }
    D_L01_001D9468 = D_L01_001D9478;
}
/* localdecomp:end func_L01_0049D200 */

/* localdecomp:start func_L01_0049D2E8 */
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; f32 f18; f32 f1C; f32 f20; f32 a24[4]; f32 a34[4]; f32 a44[4]; } S_0049D2E8;
__asm__(".extern D_L01_001D946C, 4");
extern s32 D_L01_001D946C;
extern s32 D_L01_002EC1D8[];
extern E_4999A0 D_L01_002EC368[];
extern char D_L01_001D94B8[];
extern s32 func_L01_0047DAE0(void);
extern s32 func_003BB118(s32);
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C68();
extern void func_003BABB0(void *, f32, f32, f32, f32, f32, s32);
extern void func_003BABD0(void *, f32, f32, f32, f32);
extern void func_003BA4E0(void *, s32, f32, f32, f32);
extern s32 func_003B9E30(void *, s32, s32);
extern s32 func_00381FF0(s32);
extern void func_11B2E8();

void func_L01_0049D2E8(void) {
    S_0049D2E8 s;
    s32 n = 0;
    s32 k = 0;
    s32 i;
    f32 x = 0.500369f;
    f32 w = 0.816536f;
    f32 c1 = 0.572f;
    f32 c2 = 0.06356f;

    D_L01_001D946C = 0;
    for (; D_L01_002EC368[n].w0 > 0; n++) {
        if (D_L01_002EC368[n].flag) {
            D_L01_001D946C++;
        }
    }
    if (D_L01_001D946C == 0) {
        return;
    }
    s.f0 = func_L01_0047DAE0();
    s.f4 = func_003BB118(0);
    s.f8 = 0x14;
    s.fC = D_L01_001D946C;
    s.f10 = D_L01_001D946C < 6 ? D_L01_001D946C : 5;
    s.f14 = 1;
    s.f18 = 1.0f;
    s.f1C = c1;
    s.f20 = c2;
    s.a24[0] = 0.5f;
    s.a24[1] = 1.0f;
    s.a24[2] = 1.0f;
    s.a24[3] = 1.0f;
    s.a34[0] = 0.795206f;
    s.a34[1] = 0.0f;
    s.a34[2] = 0.0f;
    s.a34[3] = 0.0f;
    s.a44[0] = 0.0f;
    s.a44[1] = 0.0f;
    s.a44[2] = 0.0f;
    s.a44[3] = 0.0f;
    func_003B9C68(func_003B9BD0(0), &s);
    func_003BABB0(func_003B9BD0(0), x, w, 0.045f, 0.0425f, 0.35f, 0);
    func_003BABD0(func_003B9BD0(0), x, 0.698703f, w, 0.314706f);
    func_003BA4E0(func_003B9BD0(0), 1, 0.033f, 0.00666f, 0.03f);
    for (i = 0; i < n; i++) {
        if (D_L01_002EC368[i].flag) {
            D_L01_002EC1D8[k] = i;
            func_11B2E8(func_003B9E30(func_003B9BD0(0), 0, k++), D_L01_001D94B8, func_00381FF0(D_L01_002EC368[i].w0));
        }
    }
}
/* localdecomp:end func_L01_0049D2E8 */

/* localdecomp:start func_L01_0049D590 */
__asm__(".extern D_L01_001E0C30, 4");
__asm__(".extern D_L01_001E0C18, 8");
extern s32 func_L01_0049D590(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0C30;
extern s32 D_L01_001E0C18[2];
extern void func_L01_0049D5E8();
extern void func_L01_0049DAB8();
extern void func_L01_0049D9E8();
extern void func_L01_0049DAF0_0049D590(void);
extern void func_L01_0049DB10_0049D590();
s32 func_L01_0049D590(void) {
    if (D_L01_001E0C30 == 0) {
        func_003E6FA0(D_L01_001E0C18, (s32)func_L01_0049D5E8, (s32)func_L01_0049DAB8, (s32)func_L01_0049D9E8, (s32)func_L01_0049DAF0_0049D590, (s32)func_L01_0049DB10_0049D590);
        D_L01_001E0C30 = 1;
    }
    return (s32)D_L01_001E0C18;
}
/* localdecomp:end func_L01_0049D590 */
