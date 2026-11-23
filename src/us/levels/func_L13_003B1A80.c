#include "common.h"

/* NTSC-U counterpart of func_L13_003B3938 (src/levels/shared/L13_003B3938.c): frame count 0x79 (120 frames at 30 fps) for 0x65 */
/* localdecomp:start func_L13_003B1A80 */
#include "vu0.h"

typedef struct {
    s32 w00;
    f32 f04;
    s32 w08;
    s32 w0C;
    s32 w10;
    s32 w14;
    s32 w18;
    u8 pad1C[4];
    vu0_v4 v20;
    s32 w30;
    s32 w34;
} Priv_003B1A80;
extern u8 D_001BBC40[];
extern u8 D_001A30B0[];
extern u8 D_001A4C60[];
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 4");
extern u8 *D_L13_001DF61C;
__asm__(".extern D_L13_001DF61C, 4");
extern f32 D_L13_001DE8E8;
__asm__(".extern D_L13_001DE8E8, 4");
extern f32 D_L13_001DE8EC;
__asm__(".extern D_L13_001DE8EC, 4");
extern f32 D_L13_001DE8F0;
__asm__(".extern D_L13_001DE8F0, 4");
extern s32 func_L01_00452F60(void *);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern void func_0039FB08(s32);
extern void func_L01_00452F40(u8 *, s32);
extern s32 func_L01_00442998(s32, s32, s32);
extern f32 func_L01_0040C040(void *, void *);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_003BEC60(f32 *, void *, f32, f32, f32, f32);

void func_L13_003B1A80(u8 *obj) {
    Priv_003B1A80 *p;
    u8 *ent;
    s32 id;
    s32 id2;
    s32 id3;
    s32 id4;
    f32 f;

    p = *(Priv_003B1A80 **)(obj + 0x68);
    if (obj[0x20] != 0 && p->w14 != 0) {
        if (func_L01_00452F60(obj) == 0) {
            return;
        }
    }
    if (p->w18 != 0) {
        if (D_001D545C == 0x16) {
            if ((D_001BBC40[obj[0xB0] + 0x160] & 0x80) != 0) {
                p->w30 = -1;
                p->w34 = -1;
            }
        }
    }
    if (p->w30 != -1) {
        if (func_L01_00452F60(D_L13_001DF61C + (p->w30 << 8)) == 0) {
            return;
        }
    }
    if (p->w34 != -1) {
        if (func_L01_00452F60(D_L13_001DF61C + (p->w34 << 8)) == 0) {
            return;
        }
    }
    switch (obj[0x20]) {
    case 0:
        p->f04 = p->f04 * p->f04;
        p->w0C = 0;
        p->w10 = -1;
        *(f32 *)(obj + 0x18) = func_003BE7F0(obj + 0x10, 0, 0, 0.5f);
        *(vu0_q *)&p->v20 = *(vu0_q *)(obj + 0x10);
        func_L01_00441FB8(obj, 1, -1);
        break;
    case 1:
        if (func_L01_00452EC8(obj) != 0) {
            id = p->w10;
            if (id != -1) {
                ent = D_001A30B0 + (id << 7);
                if (*(u8 **)(ent + 0xDC) == obj && ent[0xD0] != 0) {
                    func_0039FB08(id);
                }
            }
            p->w10 = -1;
            if (p->w14 == 0) {
                func_L01_00452F40(obj, 0);
            }
        }
        if (p->w00 >= 0) {
            if (func_L01_00442998(p->w00, -1, 0) == 0) {
                p->w00 = -1;
                func_L01_00441FB8(obj, 4, -1);
            }
        } else if (p->w14 != 0) {
            if (func_L01_00452F60(obj) != 0) {
                func_L01_00441FB8(obj, 4, -1);
            }
        } else if (func_L01_0040C040(obj + 0x10, D_001A4C60) < p->f04) {
            func_L01_00441FB8(obj, 4, -1);
        }
        break;
    case 3:
        if (func_L01_00452EC8(obj) != 0) {
            id3 = p->w10;
            if (id3 != -1) {
                ent = D_001A30B0 + (id3 << 7);
                if (*(u8 **)(ent + 0xDC) == obj && ent[0xD0] != 0) {
                    func_0039FB08(id3);
                }
            }
            p->w10 = -1;
            if (p->w14 == 0) {
                func_L01_00452F40(obj, 1);
            }
        }
        if (p->w08 == 0) {
            *(u16 *)(obj + 0x34) |= 2;
        } else if (*(u16 *)(obj + 0x96) >= 0x79) {
            if (p->f04 < func_L01_0040C040(obj + 0x10, D_001A4C60)) {
                func_L01_00441FB8(obj, 2, -1);
            }
        }
        break;
    case 2:
        if (func_L01_00452EC8(obj) != 0) {
            id2 = p->w10;
            if (id2 == -1 || *(u8 **)((ent = D_001A30B0 + (id2 << 7)) + 0xDC) != obj || ent[0xD0] == 0) {
                p->w10 = func_0039FE80(0, 4, obj);
            }
        }
        {
            f32 r = D_L13_001DE8EC;
            func_003BEC60((f32 *)(obj + 0x18), &p->w0C, p->v20.z, r, D_L13_001DE8EC, D_L13_001DE8F0);
        }
        if (fabs_asm(*(f32 *)(obj + 0x18) - p->v20.z) < 0.001f) {
            func_L01_00441FB8(obj, 1, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(obj) != 0) {
            id4 = p->w10;
            if (id4 == -1 || *(u8 **)((ent = D_001A30B0 + (id4 << 7)) + 0xDC) != obj || ent[0xD0] == 0) {
                p->w10 = func_0039FE80(0, 4, obj);
            }
        }
        func_003BEC60((f32 *)(obj + 0x18), &p->w0C, p->v20.z + D_L13_001DE8E8, D_L13_001DE8EC, D_L13_001DE8EC, D_L13_001DE8F0);
        f = *(f32 *)(obj + 0x18) - p->v20.z;
        if (D_L13_001DE8E8 - 0.001f < fabs_asm(f)) {
            func_L01_00441FB8(obj, 3, -1);
        }
        break;
    }
    if (*(u16 *)(obj + 0x96) < 0xFFFF) {
        *(u16 *)(obj + 0x96) += 1;
    }
}
/* localdecomp:end func_L13_003B1A80 */
