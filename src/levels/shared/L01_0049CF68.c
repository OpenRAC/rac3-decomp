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

INCLUDE_ASM("asm/levels", func_L01_0049D190);

/* localdecomp:start func_L01_0049D200 */
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

INCLUDE_ASM("asm/levels", func_L01_0049D2E8);

/* localdecomp:start func_L01_0049D590 */
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
