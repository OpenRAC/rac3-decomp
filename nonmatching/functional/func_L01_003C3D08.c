/* functional: medium. State machine (jump table 0x2BF080 read from the level-01 ELF: states 1..12) hand-translated from the PAL asm; the compile has the same 99 calls in the same order (only block order differs, 949 diff words). Notes: (1) func_003A52A0's result is used but the file declares it void earlier, so it is called through a function-pointer cast; (2) func_L01_003C7A68's retail return value (f0) is consumed in states 9/11, yet its current C returns void: the lead should fix that definition; (3) the two quadword stores of m+0x10/m+0xF0 to the stack at entry are dead in retail and omitted. */
#include "common.h"
/* localdecomp:start func_L01_003C3D08 */
#include "vu0.h"
extern s32 D_L01_001DECD8;
extern f32 D_L01_001DECDC, D_L01_001DECE0, D_L01_001DECE4, D_L01_001DECE8;
extern s32 D_L01_001DECF8;
extern f32 D_L01_001DF950;
__asm__(".extern D_L01_001DECD8, 4");
__asm__(".extern D_L01_001DECDC, 4");
__asm__(".extern D_L01_001DECE0, 4");
__asm__(".extern D_L01_001DECE4, 4");
__asm__(".extern D_L01_001DECE8, 4");
__asm__(".extern D_L01_001DECF8, 4");
__asm__(".extern D_L01_001DF950, 4");
extern s32 D_L01_001F3F40[];
extern s16 D_001A4DC0;
extern u8 D_001A4C60[];
extern u8 D_001A4BE0[];
extern u8 D_001A30B0[];
extern u8 *D_001D52FC;
extern s32 D_001D545C;
extern u8 D_001BBC40[][16];
extern void func_L01_003C4C40(u8 *, u8 *);
extern void func_L01_003C57E0(u8 *, u8 *);
extern void func_L01_003C5888(u8 *, u8 *);
extern s32 func_L01_003C5BA8(s32, u8 *);
extern void func_L01_003C66F8(u8 *, s32, s32);
extern void func_L01_003C57B0(u8 *, u8 *, s32);
extern void func_L01_003C5290(u8 *, u8 *);
extern void func_L01_003C6F68(u8 *, u8 *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_004561B8(u8 *);
extern s32 func_L01_003C7D38(u8 *, u8 *);
extern void func_0038D308(void *, void *);
extern void func_L01_003C6E78(u8 *, s32 *);
extern s32 func_L01_003C6860(u8 *);
extern void func_L01_003C5CA8(u8 *, u8 *);
extern void func_L01_003C5C60(u8 *, u8 *);
extern void func_L01_003C6EC0(s32, u8 *);
extern void func_L01_003C7810(u8 *, u8 *, s32, s32, s32);
extern void func_L01_003C54E8(u8 *, u8 *);
extern void func_L01_003C5CE8(u8 *, u8 *);
extern s32 func_0038CAD0(void *);
extern void func_L01_003C5EC0(u8 *, u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern f32 func_L01_003C7A68(u8 *, u8 *, f32);
extern void func_L01_003C5DF0(u8 *, u8 *, s32);
extern void func_L01_004AA760(s32, s32);
extern s32 func_L01_004AA710(void *, s32);
typedef s32 (*MakeSlot_003C3D08)(s32, s32, u8 *);
extern void func_003A4F28(s32);
extern s32 func_L01_003C55B8(u8 *, u8 *);
extern void func_L01_003C5710(u8 *, void *, void *);
extern s32 func_L01_004BA800(void);
extern void func_L01_003C6D30(u8 *, u8 *, f32 *, f32 *, f32 *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern f32 func_0038DBA0(f32, f32);
extern void func_L01_003C5220(u8 *, u8 *);
extern s32 func_L01_003C7000(u8 *, u8 *);
extern s32 func_L01_003C7560(u8 *, u8 *);
extern void func_L01_003C5F10(u8 *, u8 *);
extern void func_L01_003C6128(u8 *, u8 *);
extern s32 func_L01_003C6668(u8 *);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_003C8D60(void *);
static __inline__ void slot_free_003C3D08(s32 idx, s32 own) {
    if (idx != -1) {
        u8 *e = D_001A30B0 + idx * 128;
        if (*(s32 *)(e + 0xDC) == own && e[0xD0] != 0) {
            func_003A4F28(idx);
        }
    }
}
void func_L01_003C3D08(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 s;
    s32 own;
    s32 flag;
    s32 r, i, t;
    f32 f1, d, o20, o24, o28;
    u8 *hero;
    if (m[0x20] == 0) {
        func_L01_003C4C40(m, v);
    }
    *(vu0_q *)(m + 0x10) = *(vu0_q *)(v + 0x0);
    *(vu0_q *)(m + 0xF0) = *(vu0_q *)(v + 0x10);
    func_L01_003C57E0(m, v);
    func_L01_003C5888(m, v);
    switch (m[0x20]) {
    case 1:
        s = func_L01_003C5BA8((s32)m, v);
        if (s >= 0) {
            if (s != *(s32 *)(v + 0x6BC)) {
                func_L01_003C66F8(m, s, 0);
            }
            func_L01_003C57B0(m, v, *(s32 *)(v + 0x6D0 + s * 4));
            func_L01_003C5290(m, v);
            func_L01_003C6F68(m, v);
            func_L01_004450F0(m, 4, -1);
        } else {
            t = *(s32 *)(v + 0x710 + *(s32 *)(v + 0x6BC) * 4);
            if (t != -1 && func_00382380(D_001A4C60, t, 0)) {
                func_L01_004450F0(m, 3, -1);
            }
        }
        break;
    case 2:
        s = func_L01_003C5BA8((s32)m, v);
        if (s >= 0) {
            if (s != *(s32 *)(v + 0x6BC)) {
                func_L01_003C66F8(m, s, 0);
            }
            func_L01_003C57B0(m, v, *(s32 *)(v + 0x6D0 + s * 4));
            func_L01_003C5290(m, v);
            func_L01_003C6F68(m, v);
            func_L01_004450F0(m, 4, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(m)) {
            func_L01_003C5290(m, v);
        }
        r = func_L01_003C7D38(m, v);
        func_0038D308(m + 0xC0, m + 0xF0);
        if (r == 2) {
            *(s32 *)(v + 0xC8) = 0;
            func_L01_003C6E78(m, (s32 *)v);
            func_L01_004450F0(m, 4, -1);
        }
        break;
    case 4:
        s = func_L01_003C5BA8((s32)m, v);
        if (s >= 0 && s != *(s32 *)(v + 0x6BC)) {
            func_L01_003C66F8(m, s, 0);
            func_L01_003C57B0(m, v, *(s32 *)(v + 0x6D0 + s * 4));
            func_L01_003C5290(m, v);
            func_L01_003C6F68(m, v);
            func_L01_004450F0(m, 4, -1);
        }
        break;
    case 5:
        if (func_L01_003C6860(m)) {
            func_L01_003C5CA8(m, v);
            func_L01_003C6E78(m, (s32 *)v);
            r = *(s32 *)(v + 0xB0);
        } else {
            func_L01_003C5C60(m, v);
            func_L01_003C6EC0((s32)m, v);
            r = *(s32 *)(v + 0xB0);
        }
        if (r == 0) {
            func_L01_004450F0(m, 6, -1);
        }
        break;
    case 6:
        if (func_L01_004561B8(m)) {
            func_L01_003C6EC0((s32)m, v);
            func_L01_003C7810(m, v, *(s32 *)(v + 0x700 + *(s32 *)(v + 0x6BC) * 4), -1, 0);
        }
        r = func_L01_003C7D38(m, v);
        func_0038D308(m + 0xC0, m + 0xF0);
        if (r != 0) {
            func_L01_004450F0(m, 7, -1);
        }
        break;
    case 7:
        if (func_L01_004561B8(m)) {
            func_L01_003C54E8(m, v);
        }
        break;
    case 8:
        if (func_L01_004561B8(m)) {
            *(s32 *)(v + 0xF0) = 0;
        }
        D_001A4DC0 = 2;
        func_L01_003C5CE8(m, v);
        if (*(s32 *)(v + 0xF0) != 0) {
            if (func_0038CAD0(v + 0xF0)) {
                D_L01_001DF950 = 2.0f;
                func_L01_003C5EC0(m, v);
                func_L01_004450F0(m, 0xA, -1);
            } else {
                D_L01_001DF950 = (1.0f - (f32)*(s32 *)(v + 0xF0) / (f32)D_L01_001DECF8) * 1.1f;
            }
        } else if (*(s32 *)(D_001D52FC + 0x1C4) & 0x40) {
            *(s32 *)(v + 0xF0) = D_L01_001DECF8;
        }
        *(u16 *)(m + 0x96) = *(u16 *)(m + 0x96) + 1;
        if ((D_L01_001DECD8 * 5 + 2) / 6 < (s32)*(u16 *)(m + 0x96)) {
            func_L01_003C6EC0((s32)m, v);
            func_L01_004450F0(m, 9, -1);
        } else {
            func_L01_003C5DF0(m, v, 1);
        }
        break;
    case 9:
        D_001A4DC0 = 2;
        if (*(s32 *)(v + 0xF0) != 0) {
            if (func_0038CAD0(v + 0xF0)) {
                D_L01_001DF950 = 2.0f;
                func_L01_003C5EC0(m, v);
                func_L01_004450F0(m, 0xA, -1);
            } else {
                D_L01_001DF950 = (1.0f - (f32)*(s32 *)(v + 0xF0) / (f32)D_L01_001DECF8) * 1.1f;
            }
        } else if (*(s32 *)(D_001D52FC + 0x1C4) & 0x40) {
            *(s32 *)(v + 0xF0) = D_L01_001DECF8;
        }
        r = func_L01_003C7D38(m, v);
        func_0038D308(m + 0xC0, m + 0xF0);
        func_L01_003C5CE8(m, v);
        d = func_L01_003C7A68(m, v, D_L01_001DECDC + D_L01_001DECE0 + 1.0f);
        if (d < D_L01_001DECDC + D_L01_001DECE0) {
            if (d < D_L01_001DECE0) {
                D_L01_001DF950 = 2.0f;
                d = 0.0f;
            } else {
                D_L01_001DF950 = 1.0f - (d - D_L01_001DECE0) / D_L01_001DECDC;
            }
        }
        if (d == 0.0f || r != 0) {
            D_L01_001DF950 = 2.0f;
            func_L01_003C5EC0(m, v);
            func_L01_004450F0(m, 0xA, -1);
        } else {
            func_L01_003C5DF0(m, v, 1);
        }
        break;
    case 11:
        if (func_L01_004561B8(m)) {
            *(s32 *)(v + 0xF0) = 0;
        }
        D_001A4DC0 = 2;
        if (*(s32 *)(v + 0xF0) != 0) {
            if (func_0038CAD0(v + 0xF0)) {
                D_L01_001DF950 = 2.0f;
                func_L01_003C5EC0(m, v);
                func_L01_004450F0(m, 0xC, -1);
            } else {
                D_L01_001DF950 = (1.0f - (f32)*(s32 *)(v + 0xF0) / (f32)D_L01_001DECF8) * 1.1f;
            }
        } else if (*(s32 *)(D_001D52FC + 0x1C4) & 0x40) {
            *(s32 *)(v + 0xF0) = D_L01_001DECF8;
        }
        r = func_L01_003C7D38(m, v);
        func_0038D308(m + 0xC0, m + 0xF0);
        func_L01_003C5CE8(m, v);
        d = func_L01_003C7A68(m, v, D_L01_001DECE4 + D_L01_001DECE8 + 1.0f);
        if (d < D_L01_001DECE4 + D_L01_001DECE8) {
            if (d < D_L01_001DECE8) {
                D_L01_001DF950 = 2.0f;
                d = 0.0f;
            } else {
                D_L01_001DF950 = 1.0f - (d - D_L01_001DECE8) / D_L01_001DECE4;
            }
        }
        if (d == 0.0f || r != 0) {
            D_L01_001DF950 = 2.0f;
            func_L01_003C5EC0(m, v);
            func_L01_004450F0(m, 0xC, -1);
        } else {
            func_L01_003C5DF0(m, v, 1);
        }
        break;
    case 12:
        if (func_L01_004561B8(m)) {
            *(s32 *)(v + 0xC8) = 0;
        }
        D_001A4DC0 = 2;
        D_L01_001DF950 = 2.0f;
        break;
    case 10:
        D_001A4DC0 = 2;
        D_L01_001DF950 = 2.0f;
        break;
    default:
        break;
    }
    /* tail: keep the two held slots in step with the current owner */
    if (*(s32 *)(v + 0xAC) != D_L01_001F3F40[0]) {
        func_L01_004AA760(0, *(s32 *)(v + 0x4C));
        if (*(s32 *)(v + 0xD8) != 0) {
            func_L01_004AA760(0, *(s32 *)(v + 0xD8));
        }
        *(s32 *)(v + 0xA0) = -1;
        func_L01_004AA760(1, *(s32 *)(v + 0x4C));
        if (*(s32 *)(v + 0xD8) != 0) {
            func_L01_004AA760(1, *(s32 *)(v + 0xD8));
        }
        *(s32 *)(v + 0xA8) = -1;
        *(s32 *)(v + 0xAC) = D_L01_001F3F40[0];
    }
    if (D_L01_001F3F40[0] != *(s32 *)(v + 0xE0)) {
        own = *(s32 *)(v + 0x4C);
    } else {
        own = *(s32 *)(v + 0xD8);
    }
    flag = 0;
    if (func_L01_003C55B8(m, v) == 0) {
        slot_free_003C3D08(*(s32 *)(v + 0xA0), own);
        *(s32 *)(v + 0xA0) = -1;
        slot_free_003C3D08(*(s32 *)(v + 0xA8), own);
        *(s32 *)(v + 0xA8) = -1;
    } else {
        if (func_L01_004AA710((void *)own, *(s32 *)(v + 0xA8)) == 0) {
            if (*(s32 *)(D_001A4BE0 + 0x25C4) != 0x74) {
                if (*(s32 *)(v + 0x6E0 + *(s32 *)(v + 0x6BC) * 4) != 0 ||
                    (m[0x20] >= 8 && m[0x20] <= 0xC)) {
                    *(s32 *)(v + 0xA8) = ((MakeSlot_003C3D08)func_003A52A0)(1, 4, (u8 *)own);
                    goto after_slot_a8;
                }
            }
            slot_free_003C3D08(*(s32 *)(v + 0xA8), own);
            *(s32 *)(v + 0xA8) = -1;
        } else if (*(s32 *)(D_001A4BE0 + 0x25C4) == 0x74) {
            slot_free_003C3D08(*(s32 *)(v + 0xA8), own);
            *(s32 *)(v + 0xA8) = -1;
        }
after_slot_a8:
        func_L01_003C5710(v, m + 0x10, m + 0xF0);
        f1 = *(f32 *)(v + 0xF4);
        if (func_L01_004BA800() != 0 && 0.0f < f1) {
            *(f32 *)(v + 0xF4) = f1 - 0.02f;
            if (*(f32 *)(v + 0xF4) < 0.0f) {
                *(f32 *)(v + 0xF4) = 0.0f;
            }
        } else if (f1 < 1.0f) {
            *(f32 *)(v + 0xF4) = f1 + 0.02f;
            if (1.0f < *(f32 *)(v + 0xF4)) {
                *(f32 *)(v + 0xF4) = 1.0f;
            }
        }
        if (0.0f < *(f32 *)(v + 0xF4)) {
            func_L01_003C6D30(m, v, &o20, &o24, &o28);
            *(f32 *)(m + 0x18) = *(f32 *)(m + 0x18) + o20 * *(f32 *)(v + 0xF4);
            *(f32 *)(m + 0xF0) = func_0038DAB8(*(f32 *)(m + 0xF0), o24 * *(f32 *)(v + 0xF4));
            *(f32 *)(m + 0xF4) = func_0038DAB8(*(f32 *)(m + 0xF4), o28 * *(f32 *)(v + 0xF4));
        }
        if (func_L01_0040E548(m + 0x10, v + 0x110) > 9.99999944e-11f ||
            func_0038DBA0(*(f32 *)(m + 0xF0), *(f32 *)(v + 0x120)) > 1.7453292e-06f ||
            func_0038DBA0(*(f32 *)(m + 0xF4), *(f32 *)(v + 0x124)) > 1.7453292e-06f ||
            func_0038DBA0(*(f32 *)(m + 0xF8), *(f32 *)(v + 0x128)) > 1.7453292e-06f) {
            func_L01_003C5220(m, v);
            flag = 1;
        }
        switch (*(s32 *)(v + 0xB0)) {
        case 0:
            slot_free_003C3D08(*(s32 *)(v + 0xA0), own);
            *(s32 *)(v + 0xA0) = -1;
            break;
        case 1:
            if (func_L01_003C7000(m, v)) {
                slot_free_003C3D08(*(s32 *)(v + 0xA0), own);
                *(s32 *)(v + 0xA0) = -1;
                *(s32 *)(v + 0xB0) = 2;
            } else {
                goto slot_make;
            }
            break;
        case 2:
            slot_free_003C3D08(*(s32 *)(v + 0xA0), own);
            *(s32 *)(v + 0xA0) = -1;
            func_L01_003C7000(m, v);
            break;
        case 3:
            if (func_L01_003C7560(m, v)) {
                slot_free_003C3D08(*(s32 *)(v + 0xA0), own);
                *(s32 *)(v + 0xA0) = -1;
                *(s32 *)(v + 0xB0) = 0;
            } else {
                goto slot_make;
            }
            break;
        default:
            break;
        }
        goto after_slot_a0;
slot_make:
        if (func_L01_004AA710((void *)own, *(s32 *)(v + 0xA0)) == 0 && *(s32 *)(D_001A4BE0 + 0x25C4) != 0x74) {
            *(s32 *)(v + 0xA0) = ((MakeSlot_003C3D08)func_003A52A0)(0, 4, (u8 *)own);
        }
after_slot_a0:
        if (flag == 0) {
            if (fabs_asm(*(f32 *)(v + 0x674) - *(f32 *)(m + 0xF8)) > 1.7453292e-06f ||
                fabs_asm(*(f32 *)(v + 0x6A8) - *(f32 *)(m + 0xFC)) > 9.99999975e-06f) {
                func_L01_003C5220(m, v);
            }
        }
    }
    /* pick the current entry (s) for the slot table */
    s = -1;
    if (func_L01_003C55B8(m, v) != 0) {
        u8 st = m[0x20];
        if (st < 8 || st >= 0xD) {
            s = *(s32 *)(v + 0x6C0 + *(s32 *)(v + 0x6BC) * 4);
        } else {
            i = (st < 0xB) ? *(s32 *)(v + 0x6BC) : *(s32 *)(v + 0x104);
            s = *(s32 *)(v + 0x750 + i * 4);
            if (s < 0) {
                s = *(s32 *)(v + 0x6C0 + i * 4);
            }
        }
    }
    t = *(s32 *)(v + 0x108);
    if (t != -1) {
        if (D_001D545C == 9 && D_L01_001F3F40[0] == *(s32 *)(v + 0xE0)) {
            func_L01_003C5F10(m, v);
        } else if (v[0x101] == 0 && s == D_L01_001F3F40[0]) {
            if (*(s32 *)(v + 0x10C) == -1 ||
                (D_001BBC40[D_001D545C][*(s32 *)(v + 0x10C)] & 0x80)) {
                func_L01_003C5F10(m, v);
            } else {
                func_L01_003C6128(m, v);
            }
        } else {
            func_L01_003C6128(m, v);
        }
    }
    if (func_L01_003C55B8(m, v) != 0) {
        if (s == D_L01_001F3F40[0] && func_L01_003C6668(m) == 0) {
            func_L01_00404A10(func_L01_003C8D60, m);
        }
    }
}
/* localdecomp:end func_L01_003C3D08 */
