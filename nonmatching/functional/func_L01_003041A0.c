/* functional: medium. Same calls/arguments/order as retail. D_001A4BE0 (hero) and the weapon table are read through byte offsets as in retail. Retail scales the query record's position (func_0038CF68) before it is first written in the hit loop; here the record is zeroed once before the loop. */
#include "common.h"
#include "vu0.h"

typedef struct {
    vu0_v4 pos;
    u8 pad10[8];
    u8 b18;
    u8 b19;
    s16 h1A;
    u8 pad1C[4];
    s32 flags;
    u8 pad24[12];
} Q_003041A0 __attribute__((aligned(16)));

extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern u8 D_00142A60[];
extern u8 D_L01_002C5600[];
extern u8 D_001A30B0[];
extern u8 **D_001D52FC;
extern u8 *D_L01_001EEA80[];
extern s32 D_001D673C;
extern s32 D_001D6694;
extern u8 *D_L01_001DC5C4;
__asm__(".extern D_L01_001DC5C4, 4");
extern u8 *D_L01_001DC5C8;
__asm__(".extern D_L01_001DC5C8, 4");
extern u8 *D_L01_001DC5C0;
__asm__(".extern D_L01_001DC5C0, 4");

extern s32 func_0038CAD0(void *);
extern void func_L01_004C8668(s32);
extern s32 func_L01_004572B0(void *, s32, void *);
extern u8 *func_L01_00457480(s32, u8 *);
extern u8 *func_L01_00304A58(u8 *);
extern void func_003A4F28(s32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L01_005119E0(s32);
extern void func_L01_005118D0(s32, s32);
extern void func_L01_004482A0(f32 *, f32 *, f32, f32, f32, f32);
extern s32 func_L01_004AA710(void *, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_00446978(void *, void *);
extern void func_L01_005003D0(s32, s32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00457588(u8 *, u8 *, void *, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_L01_003057A0(u8 *, u8 *, void *, s32);
extern void func_L01_00304C48(u8 *);
extern void func_L01_00304AA0(u8 *);
extern void func_L01_003068B8(u8 *);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_00305AB8(u8 *);

void func_L01_003041A0(u8 *self) {
    Q_003041A0 q;
    u8 buf[0x40];
    vu0_v4 v;
    vu0_v4 v10;
    u8 *st;
    u8 *m;
    u8 *t;
    u8 *row;
    u8 *e;
    s32 alive;
    s32 count;
    s32 i;
    s32 n;
    s32 h;

    st = *(u8 **)(self + 0x68);
    func_0038CAD0(st + 0x68);
    if (D_L01_002C5600[D_001425C0[0x11] * 240 + 1] >= 2) {
        D_00142A60[0x11] |= 0x20;
    }
    if (*(s32 *)(D_001A4BE0 + 0x1224) == 3 && D_L01_001DC5C4 != 0) {
        for (i = 0; i < 35; i++) {
            e = D_L01_001DC5C4 + i * 64;
            if (*(s32 *)(e + 0x38) >= 0) {
                func_L01_004C8668(*(s32 *)(e + 0x38));
                *(s32 *)(e + 0x38) = -1;
            }
        }
    }
    if (self[0x20] == 0) {
        *(s32 *)(st + 0x34) = func_L01_004572B0(self, 0, buf);
        D_L01_001DC5C8 = func_L01_00457480(*(s16 *)(self + 0xAA), (u8 *)*(s32 *)(st + 0x34));
        D_L01_001DC5C0 = func_L01_00304A58(D_L01_001DC5C8 + 0x33E0);
        D_L01_001DC5C4 = func_L01_00304A58(D_L01_001DC5C0 + 0x1F40);
        for (i = 0; i < 125; i++) {
            *(s32 *)(D_L01_001DC5C0 + 0x30 + i * 0x40) = 1;
        }
        for (i = 0; i < 10; i++) {
            *(s32 *)(D_L01_001DC5C8 + 0x574 + i * 0x530) = 0;
        }
        for (i = 0; i < 35; i++) {
            *(s32 *)(D_L01_001DC5C4 + 0x38 + i * 0x40) = -1;
        }
        *(s32 *)(st + 0x3C) = 0;
        *(s32 *)(st + 0x48) = 0;
        *(s32 *)(st + 0x40) = 0;
        *(s32 *)(st + 0x44) = 0;
        *(s32 *)(st + 0x54) = 0;
        *(s32 *)(st + 0x50) = 0;
        *(s32 *)(st + 0x58) = 0;
        *(s32 *)(st + 0x5C) = 0;
        *(s32 *)(st + 0x60) = 0;
        *(s32 *)(st + 0x64) = 0;
        self[0x20] = 1;
        *(s32 *)(st + 0x38) = -1;
    }
    if (*(s32 *)(D_001A4BE0 + 0x1224) == 3) {
        h = *(s32 *)(st + 0x38);
        if (h != -1) {
            e = D_001A30B0 + h * 0x80;
            if (*(u8 **)(e + 0xDC) == self && e[0xD0] != 0) {
                func_003A4F28(h);
            }
        }
        *(s32 *)(st + 0x38) = -1;
        return;
    }
    func_003C2F58(self, 0, st);
    alive = 1;
    if (*(s32 *)(D_001A4BE0 + 0x25C4) == 0x1D) {
        alive = (func_0038CAD0(D_001A4BE0 + 0x28BC) != 0) ? 1 : 0;
    } else {
        *(s32 *)(D_001A4BE0 + 0x28BC) = 0x21;
    }
    if ((*(s32 *)((u8 *)*D_001D52FC + 0x1A0) & *(s32 *)(D_001A4BE0 + 0x1210)) != 0 && alive != 0 &&
        func_L01_005119E0(-1) != 0 && D_001A4BE0[0x25ED] == 0) {
        func_L01_004482A0((f32 *)(st + 0x50), (f32 *)(st + 0x54), 10.0f, 0.009f, 0.0024f, 12.0f);
        n = *(s32 *)(st + 0x60);
        if (n % 10 == 0) {
            func_L01_005118D0(-1, 1);
        }
        *(s32 *)(st + 0x60) = *(s32 *)(st + 0x60) + 1;
        if (func_L01_004AA710(self, *(s32 *)(st + 0x38)) == 0) {
            *(s32 *)(st + 0x38) = func_003A52A0(0, 4, self);
        }
        count = func_003D4D00(st, 0x10, self, 0, 0.5f);
        if (count != 0 && *(s32 *)(st + 0x68) == 0) {
            *(s32 *)(st + 0x68) = 7;
            if (D_L01_002C5600[D_001425C0[0x11] * 240 + 1] >= 4) {
                func_L01_004AAC98(1, 0, self, 0xC59);
            } else {
                func_L01_004AAC98(1, 0, self, 0x5C9);
            }
        }
        m = self + 0xC0;
        if (count > 0) {
            q.pos.x = 0.0f;
            q.pos.y = 0.0f;
            q.pos.z = 0.0f;
            q.pos.w = 0.0f;
            for (i = 0; i < count; i++) {
                t = D_L01_001EEA80[i];
                if (t == *(u8 **)(D_001A4BE0 + 0x25C0)) {
                    continue;
                }
                vec_sub_ab(&v10, t + 0x10, self + 0x10);
                func_0038CF68(&v10, &v10, 1.0f);
                func_0038CF68(&q.pos, &q.pos, 1.0f);
                row = D_L01_002C5600 + D_001425C0[0x11] * 240;
                if (row[1] >= 4) {
                    func_L01_00446760(&q.pos, self, 0x11010000, &v10, *(f32 *)(row + 0x6C));
                } else {
                    func_L01_00446760(&q.pos, self, 0x1110000, &v10, *(f32 *)(row + 0x6C));
                }
                q.pos = v10;
                q.b18 = 9;
                q.pos.w = 5627.9248f;
                q.flags = 1;
                q.b19 = 1;
                q.h1A = *(u16 *)(t + 0xAA);
                func_L01_00446978(t, &q);
                if (*(s32 *)(st + 0x68) == 0) {
                    *(s32 *)(st + 0x68) = 7;
                    if (D_L01_002C5600[D_001425C0[0x11] * 240 + 1] >= 4) {
                        func_L01_004AAC98(1, 0, self, 0xC59);
                    } else {
                        func_L01_004AAC98(1, 0, self, 0x5C9);
                    }
                }
            }
        }
    } else {
        h = *(s32 *)(st + 0x38);
        if (h != -1) {
            e = D_001A30B0 + h * 0x80;
            if (*(u8 **)(e + 0xDC) == self && e[0xD0] != 0) {
                func_003A4F28(h);
            }
        }
        *(s32 *)(st + 0x38) = -1;
        if ((*(s32 *)((u8 *)*D_001D52FC + 0x1A4) & *(s32 *)(D_001A4BE0 + 0x1210)) != 0) {
            if (func_L01_005119E0(-1) == 0 && D_001A4BE0[0x25ED] == 0) {
                func_003A52A0(2, 0, self);
            }
        }
        m = self + 0xC0;
        func_L01_004482A0((f32 *)(st + 0x50), (f32 *)(st + 0x54), 0.0f, 0.072f, 0.012f, 0.15f);
        *(s32 *)(st + 0x60) = 0;
    }
    if (*(s32 *)(D_001A4BE0 + 0x25C4) == 1) {
        func_L01_005003D0(0x1D, 1);
    }
    func_003C2F58(self, 0, st);
    qzero(&v);
    v.y = -1.0f;
    func_0038D000(&v, &v, m);
    v.z = v.z + 0.02f;
    func_0038CF68(&v, &v, *(f32 *)(st + 0x50) * 0.05f);
    if (*(s32 *)(D_001A4BE0 + 0x1430) != 0) {
        *(s32 *)(D_001A4BE0 + 0xBD8) = *(s32 *)(D_001A4BE0 + 0x1430);
        func_L01_00457588(*(u8 **)(D_001A4BE0 + 0x1430), st, &v, *(f32 *)(st + 0x50) * 0.05f);
        if (D_001D673C != 0) {
            func_0038CE20(&v10, self + 0xE0, 0.02f);
            vec_add_ab(&v, &v, &v10);
        } else {
            v.z = v.z + 0.02f;
        }
    }
    *(vu0_q *)(st + 0x10) = *(vu0_q *)st;
    if (*(s32 *)(D_001A4BE0 + 0x25C4) != 0) {
        func_0038D890(&v, &v, *(u8 **)(D_001A4BE0 + 0x25C0) + 0xD0, -0.09817477f);
    }
    if (*(f32 *)(st + 0x50) != 0.0f) {
        func_L01_003057A0(self, st, &v, 0x21);
    }
    *(f32 *)(st + 0x58) = *(f32 *)(st + 0x58) - 0.1f;
    if (*(f32 *)(st + 0x58) <= -8.0f) {
        *(f32 *)(st + 0x58) = *(f32 *)(st + 0x58) + 8.0f;
    }
    *(f32 *)(st + 0x5C) = *(f32 *)(st + 0x5C) - 0.025f;
    if (*(f32 *)(st + 0x5C) <= -8.0f) {
        *(f32 *)(st + 0x5C) = *(f32 *)(st + 0x5C) + 8.0f;
    }
    if (*(f32 *)(st + 0x50) == 0.0f) {
        *(s32 *)(st + 0x40) = 0;
        *(s32 *)(st + 0x44) = 0;
        *(s32 *)(st + 0x3C) = 0;
        *(s32 *)(st + 0x48) = 0;
    } else {
        func_L01_00304C48(self);
        func_L01_00304AA0(self);
    }
    func_L01_003068B8(self);
    if (D_001D6694 != 2 && self[0x31] != 0) {
        func_L01_00404A10((void *)func_L01_00305AB8, self);
    }
}
