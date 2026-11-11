#include "common.h"

/* localdecomp:start func_L11_003A8FE0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) q_3A8FE0;
typedef struct { u8 pad[0x464]; u8 spent[1]; } S_3A8FE0;
extern S_3A8FE0 D_L11_00234CC0;
__asm__(".extern D_L11_00234CC0, 16");
extern u8 *D_L11_001DEE1C;
extern u8 D_001BBE90[];
extern s32 D_001D545C;
extern u8 D_001A30B0[];
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00456250(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451290(void *, void *, s32);
extern void func_003C4098(void *, void *, void *, f32);
extern void func_L01_004515D8(void *, void *, void *);
extern void func_003A4F28(s32);

void func_L11_003A8FE0(u8 *a0)
{
    s32 *v = *(s32 **)(a0 + 0x68);
    q_3A8FE0 mtx;
    q_3A8FE0 rot;
    q_3A8FE0 out;
    s32 idx;
    u8 *e;
    u16 id;
    u8 *p;
    s32 b;

    if (v == 0) {
        return;
    }
    switch (a0[0x20]) {
    case 0:
        *(u16 *)(a0 + 0x34) |= 0x100;
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (func_L01_00456250(D_L11_001DEE1C + (v[0] << 8)) == 0) {
            id = *(u16 *)(a0 + 0xB2);
            if (D_L11_00234CC0.spent[(s16)id] == 0) {
                b = D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)];
                if (id & 1) {
                    if (((b >> 4) & 7) != 0) {
                        goto spawn;
                    }
                    break;
                }
                if ((b & 7) == 0) {
                    break;
                }
            }
        }
spawn:
        func_L01_004450F0(a0, 2, -1);
        func_003A52A0(0, 0, a0);
        break;
    case 2:
        if (*(u16 *)(a0 + 0x96) < 200) {
            *(u16 *)(a0 + 0x96) += 1;
        }
        func_L01_00451290(a0, &mtx, 1);
        rot = *(q_3A8FE0 *)(a0 + 0xE0);
        func_003C4098(&out, &rot, &mtx, -0.02f);
        func_L01_004515D8(a0 + 0xC0, &out, 0);
        if (*(u16 *)(a0 + 0x96) >= 100) {
            idx = v[1];
            if (idx != -1) {
                e = D_001A30B0 + (idx << 7);
                if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
                    func_003A4F28(idx);
                }
            }
            v[1] = -1;
        }
        if (*(u16 *)(a0 + 0xB2) & 1) {
            p = &D_001BBE90[(*(s16 *)(a0 + 0xB2) >> 1) + (D_001D545C << 10)];
            if (((*p >> 4) & 7) != 7) {
                *p += 0x10;
            }
        } else {
            p = &D_001BBE90[(*(s16 *)(a0 + 0xB2) >> 1) + (D_001D545C << 10)];
            if ((*p & 7) != 7) {
                *p += 1;
            }
        }
        break;
    }
}
/* localdecomp:end func_L11_003A8FE0 */

INCLUDE_ASM("asm/levels", func_L11_003A9260);

INCLUDE_ASM("asm/levels", func_L11_003A9860);

INCLUDE_ASM("asm/levels", func_L11_003A9B30);

/* localdecomp:start func_L11_003A9CB0 */
__asm__(".extern D_L11_001D66B0, 16");
extern u8 D_L11_001D66B0;
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_004443E8(void *, s32, s32);

void func_L11_003A9CB0(u8 *a0)
{
    func_L01_00451FE0(a0, 0x3FFF, &D_L11_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
    func_003A52A0(0, 0, a0);
    func_L01_004443E8(a0, 0, 3);
}
/* localdecomp:end func_L11_003A9CB0 */

/* localdecomp:start func_L11_003A9D50 */
void func_0038CAD0(s32);
void func_0038CB00(s32);

void func_L11_003A9D50(void *arg0) {
    s32 temp_s0;
    u16 temp_v1;

    temp_s0 = *(s32 *)((u8 *)arg0 + 0x68);
    func_0038CAD0(temp_s0 + 0x2D0);
    func_0038CB00(temp_s0 + 0x2D4);
    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
}
/* localdecomp:end func_L11_003A9D50 */
