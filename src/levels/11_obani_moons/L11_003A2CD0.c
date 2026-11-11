#include "common.h"

typedef struct {
    char pad0[0x10];
    char pos[0x31 - 0x10];
    u8 unk31;
    char pad32[0x68 - 0x32];
    s32 vars;
    char pad6C[0x6F - 0x6C];
    u8 state;
    char pad70[0x96 - 0x70];
    u16 timer;
} Moby_003A46C8;

INCLUDE_ASM("asm/levels", func_L11_003A2CD0);

INCLUDE_ASM("asm/levels", func_L11_003A2DB0);

/* localdecomp:start func_L11_003A40B8 */
extern s32 func_L01_00451D38(void *, s32, s32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_003D9508(void *, int, int, int, float, float, float);

void func_L11_003A40B8(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 buf[0x10];
    u8 st;

    if (a0[0x95] == 0) {
        *(s32 *)(v + 0x324) = func_L01_00451D38(v + 0x328, 0x40108010, 0x40042004, 0.16755162f);
    } else if (a0[0x95] == 2) {
        st = a0[0x20];
        if (st == 6 || st == 8 || st == 7) {
            *(s32 *)(v + 0x324) = func_L01_00451D38(v + 0x328, 0x40101080, 0x40040420, 0.16755162f);
        } else {
            *(s32 *)(v + 0x324) = func_L01_00451D38(v + 0x328, 0x40108080, 0x40084040, 0.16755162f);
        }
    } else {
        *(s32 *)(v + 0x324) = func_L01_00451D38(v + 0x328, 0x40108080, 0x40084040, 0.16755162f);
    }
    *(s32 *)(a0 + 0x78) = func_0038DBD8(*(s32 *)(v + 0x324), *(s32 *)(a0 + 0x78), 0.90400004f);
    func_003C2F58(a0, 0, buf);
    func_003D9508(buf, 0xB, *(s32 *)(a0 + 0x78), 1, 0.25f, 0.08f, 0.0f);
}
/* localdecomp:end func_L11_003A40B8 */

INCLUDE_ASM("asm/levels", func_L11_003A41E0);

INCLUDE_ASM("asm/levels", func_L11_003A4410);

/* localdecomp:start func_L11_003A45D0 */
__asm__(".extern D_L11_001D66B0, 16");
extern u8 D_L11_001D66B0;
extern u8 D_001A30B0[];
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L01_004443E8(void *, s32, s32);

void func_L11_003A45D0(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    s32 idx = *(s32 *)(v + 0x2F4);
    u8 *e;

    if (idx != -1) {
        e = D_001A30B0 + (idx << 7);
        if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
            func_003A4F28(idx);
        }
    }
    *(s32 *)(v + 0x2F4) = -1;
    func_003A52A0(5, 0, a0);
    func_L01_00451FE0(a0, 0x7FFF, &D_L11_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
    func_L01_004443E8(a0, 0, 3);
}
/* localdecomp:end func_L11_003A45D0 */

/* localdecomp:start func_L11_003A46C8 */
extern u8 D_L11_001E1780[];
extern void func_0038CAD0(s32);
extern void func_0038CB00(s32);
extern void func_L11_003A40B8(u8 *);
extern void func_L01_00404808(void (*)(u8 *), void *);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);

void func_L11_003A46C8(Moby_003A46C8 *m) {
    s32 temp_s1;
    u16 temp_v1;

    temp_s1 = m->vars;
    func_0038CAD0(temp_s1 + 0x2D0);
    func_0038CB00(temp_s1 + 0x2D4);
    temp_v1 = m->timer;
    if (temp_v1 <= 0xFFFEU) {
        m->timer = (u16) (temp_v1 + 1);
    }
    func_L01_00404808(func_L11_003A40B8, m);
    func_L01_00451DF8(m, (u8 *)temp_s1 + 0x240, 2, 1, 2.5f);
    if (m->unk31 != 0 && func_L01_0040E548(D_L11_001E1780, &m->pos) < 1024.0f) {
        func_L01_004472C0(m);
        m->state = 30;
    }
}
/* localdecomp:end func_L11_003A46C8 */
